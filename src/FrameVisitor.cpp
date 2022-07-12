#include "../include/FrameVisitor.h"
#include "../include/frm.h"
#define eraseSpace(X) X.erase(std::remove(X.begin(), X.end(), ' '), X.end())
#pragma warning(disable: 4996)

antlrcpp::Any FrameVisitor::visitFile(FrameParser::FileContext* ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitProgram(FrameParser::ProgramContext* ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitGlobal_options(FrameParser::Global_optionsContext* ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitReencode_option(FrameParser::Reencode_optionContext* ctx) {
    if (ctx->decision->getText() == "yes")
    {
        frm::options.reencode = true;
    }
    else if (ctx->decision->getText() == "no")
    {
        frm::options.reencode = false;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitOverwrite_option(FrameParser::Overwrite_optionContext* ctx) {
    if (ctx->decision->getText() == "yes")
    {
        frm::options.overwrite = true;
    }
    else if (ctx->decision->getText() == "no")
    {
        frm::options.overwrite = false;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitOutput_option(FrameParser::Output_optionContext* ctx) {
    std::string dir = ctx->STRING()->getText();
    dir = dir.substr(1, dir.length() - 2);
    if (!std::filesystem::is_directory(dir))
    {
        std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
        exit(0);
    }
    else
    {
        frm::options.global_output = true;
        if (dir[dir.length() - 1] != '\\') dir.push_back('\\');
        frm::options.global_output_path = dir;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitDebug_option(FrameParser::Debug_optionContext* ctx)
{
    if (ctx->decision->getText() == "yes")
    {
        frm::options.debug = true;
    }
    else if (ctx->decision->getText() == "no")
    {
        frm::options.debug = false;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitConstruct(FrameParser::ConstructContext* ctx) {

    std::string name = ctx->NAME()->getText();
    std::string path = ctx->path()->STRING()->getText();
    std::string type = ctx->type->getText();

    if (frm::findByName(name))
    {
        std::cout << "Line " << ctx->start->getLine() << ": Name in use for another construct";
        exit(0);
    }
    else if (frm::findByPath(path.substr(1, path.length() - 2)) || !std::filesystem::exists(path.substr(1, path.length() - 2)))
    {
        std::cout << "Construct at line " << ctx->start->getLine() << ": Path does not exist or in use for another construct";
        exit(0);
    }

    if (type == "Video")
    {
        Media med(name, path, VIDEO);
        frm::medias.push_back(med);
    }
    else if (type == "Audio")
    {
        Media med(name, path, AUDIO);
        frm::medias.push_back(med);
    }
    else
    {
        Media med(name, path, FRAME);
        frm::medias.push_back(med);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitPath(FrameParser::PathContext* ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitProperty(FrameParser::PropertyContext* ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitFormat(FrameParser::FormatContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::string format;
    if (ctx->AUDIO_FORMAT() != NULL)
    {
        std::cout << constructName << ":" << " Converting audio format, this may take a while...\n";
        format = ctx->AUDIO_FORMAT()->getText();
        if (format == "opus") format = "libopus";
    }
    else if (ctx->VIDEO_FORMAT() != NULL)
    {
        std::cout << constructName << ":" << " Converting video format, this may take a while...\n";
        format = ctx->VIDEO_FORMAT()->getText();
    }
    else
    {
        std::cout << constructName << ":" << " Converting frame format, this may take a while...\n";
        format = ctx->IMAGE_FORMAT()->getText();
    }
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;

    if (exists)
    {
        std::string newFilePath = directory + constructName + "." + (format != "libopus" ? format : "opus");
        if (media.propertyApplied)
        {
            std::string TempFilePath = directory + constructName + "Temp." + (format != "libopus" ? format : "opus");
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
        }
        else
        {
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            frm::medias[idx].propertyApplied = true;
        }
        frm::medias[idx].path = newFilePath;
        frm::medias[idx].format = format;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitCodec(FrameParser::CodecContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::string codec;
    bool audio_codec = false;
    std::cout << constructName << ":" << " Converting codec, this may take a while...\n";
    if (ctx->AUDIO_FORMAT() != NULL)
    {
        codec = ctx->AUDIO_FORMAT()->getText();
        if (codec == "opus") codec = "libopus";
        audio_codec = true;
    }
    else if (ctx->VIDEO_CODEC() != NULL)
    {
        codec = ctx->VIDEO_CODEC()->getText();
    }
    else
    {
        codec = ctx->IMAGE_FORMAT()->getText();
    }
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;
    if (exists)
    {
        if (media.type == AUDIO || media.type == FRAME)
        {
            std::string newFilePath = directory + constructName + "." + (codec != "libopus" ? codec : "opus");
            if (media.propertyApplied)
            {
                std::string TempFilePath = directory + constructName + "Temp." + (codec != "libopus" ? codec : "opus");
                std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                    + " -i \"" + media.path + "\" \"" + TempFilePath + "\"";
                if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                else
                {
                    // Suppress the system call
                    cmd += " >nul 2>nul";
                }
                system(cmd.c_str());
                std::filesystem::remove(newFilePath);
                std::filesystem::rename(TempFilePath, newFilePath);
            }
            else
            {
                std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                    + " -i \"" + media.path + "\" \"" + newFilePath + "\"";
                if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                else
                {
                    // Suppress the system call
                    cmd += " >nul 2>nul";
                }
                system(cmd.c_str());
                frm::medias[idx].propertyApplied = true;
            }
            frm::medias[idx].path = newFilePath;
            frm::medias[idx].format = (codec != "libopus" ? codec : "opus");
        }
        else
        {
            if (codec == "vp8") codec = "libvpx";
            else if (codec == "vp9") codec = "libvpx-vp9";
            else if (codec == "h264") codec = "libx264";
            else if (codec == "h265") codec = "libx265";

            std::string newFilePath = directory + constructName + "." + media.format;
            if (media.propertyApplied)
            {
                std::string TempFilePath = directory + constructName + "Temp." + media.format;
                std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                    + " -i \"" + media.path + "\""
                    + (audio_codec ? std::string(" -c:a ") : std::string(" -c:v ")) + codec + " \"" + TempFilePath + "\"";
                if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                else
                {
                    // Suppress the system call
                    cmd += " >nul 2>nul";
                }
                system(cmd.c_str());
                std::filesystem::remove(newFilePath);
                std::filesystem::rename(TempFilePath, newFilePath);
            }
            else
            {
                std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                    + " -i \"" + media.path + "\""
                    + (audio_codec ? std::string(" -c:a ") : std::string(" -c:v ")) + codec + " \"" + newFilePath + "\"";
                if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                else
                {
                    // Suppress the system call
                    cmd += " >nul 2>nul";
                }
                system(cmd.c_str());
                frm::medias[idx].propertyApplied = true;
            }
            frm::medias[idx].path = newFilePath;
        }
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitBitrate(FrameParser::BitrateContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::cout << constructName << ":" << " Changing bitrate\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == FRAME)
    {
        std::cout << "Construct at line " << ctx->start->getLine() << ": Can't change bitrate of a frame type";
        exit(0);
    }
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;

    if (exists)
    {
        std::string newFilePath = directory + constructName + "." + media.format;
        if (media.propertyApplied)
        {
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -b:a " + ctx->INT()->getText() + "k \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
        }
        else
        {
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -b:a " + ctx->INT()->getText() + "k \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            frm::medias[idx].propertyApplied = true;
        }
        frm::medias[idx].path = newFilePath;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitSample_rate(FrameParser::Sample_rateContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::cout << constructName << ":" << " Changing sample rate\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == FRAME)
    {
        std::cout << "Construct at line " << ctx->start->getLine() << ": Can't change sample rate of a frame type";
        exit(0);
    }
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;

    if (exists)
    {
        std::string newFilePath = directory + constructName + "." + media.format;
        if (media.propertyApplied)
        {
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -af" + " \"asetrate=" + ctx->INT()->getText() + "\" \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
        }
        else
        {
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -af" + " \"asetrate=" + ctx->INT()->getText() + "\" \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            frm::medias[idx].propertyApplied = true;
        }
        frm::medias[idx].path = newFilePath;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitPitch(FrameParser::PitchContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::cout << constructName << ":" << " Changing pitch\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == FRAME)
    {
        std::cout << "Construct at line " << ctx->start->getLine() << ": Can't change pitch of a frame type";
        exit(0);
    }
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;

    if (exists)
    {
        std::string newFilePath = directory + constructName + "." + media.format;
        if (media.propertyApplied)
        {
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -af" + " \"aresample=" + ctx->INT()->getText() + "\" \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
        }
        else
        {
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -af" + " \"aresample=" + ctx->INT()->getText() + "\" \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            frm::medias[idx].propertyApplied = true;
        }
        frm::medias[idx].path = newFilePath;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitTempo(FrameParser::TempoContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::cout << constructName << ":" << " Changing tempo\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == FRAME)
    {
        std::cout << "Construct at line " << ctx->start->getLine() << ": Can't change tempo of a frame type";
        exit(0);
    }
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;

    if (exists)
    {
        std::string newFilePath = directory + constructName + "." + media.format;
        if (media.propertyApplied)
        {
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -af" + " \"atempo=" + ctx->FLOAT()->getText() + "\" \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
        }
        else
        {
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -af" + " \"atempo=" + ctx->FLOAT()->getText() + "\" \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            frm::medias[idx].propertyApplied = true;
        }
        frm::medias[idx].path = newFilePath;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitResolution(FrameParser::ResolutionContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::cout << constructName << ":" << " Changing resolution\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Construct at line " << ctx->start->getLine() << ": Can't change resolution of an audio type";
        exit(0);
    }
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;

    if (exists)
    {
        std::string newFilePath = directory + constructName + "." + media.format;
        std::string width = ctx->INT()[0]->getText();
        std::string height = ctx->INT()[1]->getText();
        eraseSpace(width);
        eraseSpace(height);
        if (media.propertyApplied)
        {
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -vf" + " scale=" + width
                + ":" + height + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
        }
        else
        {
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -vf" + " scale=" + width
                + ":" + height + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            frm::medias[idx].propertyApplied = true;
        }
        frm::medias[idx].path = newFilePath;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitFramerate(FrameParser::FramerateContext* ctx) {
    std::string constructName = ctx->parent->parent->getText();
    constructName = constructName.substr(5, constructName.find_first_of("{\n") - 5);
    std::cout << constructName << ":" << " Changing frame rate\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type != VIDEO)
    {
        std::cout << "Construct at line " << ctx->start->getLine() << ": Can't change frame rate of a non video type";
        exit(0);
    }
    std::string directory = frm::options.global_output ? frm::options.global_output_path
        : media.directory;

    if (exists)
    {
        std::string newFilePath = directory + constructName + "." + media.format;
        std::string framerate = ctx->INT()->getText();
        eraseSpace(framerate);
        if (media.propertyApplied)
        {
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -filter:v" + " fps=" + framerate + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
        }
        else
        {
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -filter:v" + " fps=" + framerate + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            frm::medias[idx].propertyApplied = true;
        }
        frm::medias[idx].path = newFilePath;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitAction(FrameParser::ActionContext* ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitTrimming(FrameParser::TrimmingContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Trimming " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == FRAME)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't trim a frame type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c copy"))
                + " -ss " + ctx->TIME()[0]->getText() + " -to "
                + ctx->TIME()[1]->getText() + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c copy"))
                + " -ss " + ctx->TIME()[0]->getText() + " -to "
                + ctx->TIME()[1]->getText() + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitCropping(FrameParser::CroppingContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Cropping " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't crop an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf \"crop=" + ctx->INT()[0]->getText() + ":"
                + ctx->INT()[1]->getText() + (ctx->AS() != NULL ? ctx->INT()[2]->getText() + ":" + ctx->INT()[3]->getText() : "")
                + "\" \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf \"crop=" + ctx->INT()[0]->getText() + ":"
                + ctx->INT()[1]->getText() + (ctx->AS() != NULL ? ctx->INT()[2]->getText() + ":" + ctx->INT()[3]->getText() : "")
                + "\" \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitOverlaying(FrameParser::OverlayingContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::string constructTwoName = ctx->NAME()[1]->getText();
    std::cout << "Overlaying " << constructName + " on " + constructTwoName + "\n";
    bool exists = false;
    bool existsTwo = false;
    int idx;
    int idxTwo;
    Media media = frm::findByName(constructName, exists, idx);
    Media mediaTwo = frm::findByName(constructTwoName, existsTwo, idxTwo);
    if (media.type == AUDIO || mediaTwo.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't overlay an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        bool minusFirst = false;
        bool minusSecond = false;
        if (ctx->MINUS().size() == 1)
        {
            if (ctx->children[6] != ctx->MINUS()[0])
            {
                minusSecond = true;
            }
            else
            {
                minusFirst = true;
            }
        }
        else if (ctx->MINUS().size() == 2)
        {
            minusFirst = true;
            minusSecond = true;
        }

        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[2]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -i \"" + mediaTwo.path + "\"" + " -filter_complex \"[0:v][1:v] overlay="
                + (minusFirst ? "-" : "") + ctx->INT()[0]->getText() + ":"
                + (minusSecond ? "-" : "") + ctx->INT()[1]->getText() + "\""
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[2]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -i \"" + mediaTwo.path + "\"" + " -filter_complex \"[0:v][1:v] overlay="
                + (minusFirst ? "-" : "") + ctx->INT()[0]->getText() + ":"
                + (minusSecond ? "-" : "") + ctx->INT()[1]->getText() + "\""
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitExtractingAudioFromVideo(FrameParser::ExtractingAudioFromVideoContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Extracting audio from " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type != VIDEO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't extract audio from a non-video type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + ctx->AUDIO_FORMAT()->getText();
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -vn" + (frm::options.reencode ? std::string("") : std::string(" -c copy"))
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + ctx->AUDIO_FORMAT()->getText();
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\"" + " -vn" + (frm::options.reencode ? std::string("") : std::string(" -c copy"))
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitExtractingFramesFromVideo(FrameParser::ExtractingFramesFromVideoContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Extracting frames from " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type != VIDEO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't extract frames from a non-video type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        bool ints = false;
        std::string firstInt;
        std::string secondInt;
        if (ctx->RATIO() != NULL)
        {
            ints = true;
            firstInt = ctx->INT()[0]->getText();
            eraseSpace(firstInt);
            secondInt = ctx->INT()[1]->getText();
            eraseSpace(secondInt);
        }
        std::string newFilePath = directory
            + (ctx->AS() != NULL ? ctx->NAME()[1]->getText() : constructName) + "%05d." + ctx->IMAGE_FORMAT()->getText();
        std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
            + " -i \"" + media.path + "\"" + " -vf fps" + (ints ? ("=" + firstInt + "/" + secondInt) : "")
            + " \"" + newFilePath + "\"";
        if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
        else
        {
            // Suppress the system call
            cmd += " >nul 2>nul";
        }
        system(cmd.c_str());
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitMergingAudioWithVideo(FrameParser::MergingAudioWithVideoContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::string constructTwoName = ctx->NAME()[1]->getText();
    std::cout << "Merging " << constructName + " with " + constructTwoName + "\n";
    bool exists = false;
    int idx;
    bool existsTwo = false;
    int idxTwo;
    Media media = frm::findByName(constructName, exists, idx);
    Media mediaTwo = frm::findByName(constructTwoName, existsTwo, idxTwo);
    if (media.type == FRAME || mediaTwo.type == FRAME || media.type == mediaTwo.type)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't merge used types";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        bool audioFirst = false;
        std::string mformat = media.format;
        if (media.type == AUDIO)
        {
            audioFirst = true;
            mformat = mediaTwo.format;
        }
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[2]->getText() + "." + mformat;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + (audioFirst ? media.path : mediaTwo.path) + "\""
                + " -i \"" + (audioFirst ? mediaTwo.path : media.path) + "\""
                + (frm::options.reencode ? std::string("") : std::string(" -c copy"))
                + " -shortest \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[2]->getText(), newFilePath, VIDEO);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + mformat;
            std::string TempFilePath = directory + constructName + "Temp." + mformat;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + (audioFirst ? media.path : mediaTwo.path) + "\""
                + " -i \"" + (audioFirst ? mediaTwo.path : media.path) + "\""
                + (frm::options.reencode ? std::string("") : std::string(" -c copy"))
                + " -shortest \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitConcatentating(FrameParser::ConcatentatingContext* ctx) {
    std::vector<antlr4::tree::TerminalNode*> nodes = ctx->NAME();
    int constCount = (ctx->AS() != NULL ? ctx->NAME().size() - 1 : ctx->NAME().size());
    std::vector<Media> constructs;
    std::string constructName = nodes[0]->getText();
    std::cout << "Concatenating to " << constructName + ". Note that all constructs must have same the resolution in case of video or frame\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    medtype usedType = media.type;
    for (int i = 0; i < constCount; i++)
    {
        Media conMed = frm::findByName(nodes[i]->getText(), exists, idx);
        if (!exists)
        {
            std::cout << "Line " << ctx->start->getLine() << ": One or more of the constructs do not exist";
            exit(0);
        }
        if (conMed.type != usedType)
        {
            std::cout << "Action at line " << ctx->start->getLine() << ": Can't concatenate unequal construct types";
            exit(0);
        }
        constructs.push_back(conMed);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (ctx->AS() != NULL)
    {
        std::string newFilePath = directory + ctx->NAME()[constCount]->getText() + "." + media.format;
        std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"));
        for (int i = 0; i < constCount; i++)
        {
            cmd += +" -i \"" + constructs[i].path + "\"";
        }
        cmd += " -filter_complex \"";
        if (usedType == VIDEO)
        {
            for (int i = 0; i < constCount; i++)
            {
                cmd += "[" + std::to_string(i) + ":v:0]" + "[" + std::to_string(i) + ":a:0]";
            }
            cmd += "concat=n=" + std::to_string(constCount) + ":v=1:a=1[outv][outa]\" -vsync 2 -map \"[outv]\" -map \"[outa]\" " + newFilePath;
        }
        else if (usedType == AUDIO)
        {
            for (int i = 0; i < constCount; i++)
            {
                cmd += "[" + std::to_string(i) + ":a]";
            }
            cmd += "concat=n=" + std::to_string(constCount) + ":v=0:a=1[outa]\" -map \"[outa]\" " + newFilePath;
        }
        else
        {
            for (int i = 0; i < constCount; i++)
            {
                cmd += "[" + std::to_string(i) + "]";
            }
            cmd += "hstack=inputs=" + std::to_string(constCount) + "\" -vframes 1 " + newFilePath;
        }
        if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
        else
        {
            // Suppress the system call
            cmd += " >nul 2>nul";
        }
        system(cmd.c_str());
        newFilePath = "\"" + newFilePath + "\"";
        Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
        frm::medias.push_back(newMedia);
    }
    else
    {
        std::string newFilePath = directory + constructName + "." + media.format;
        std::string TempFilePath = directory + constructName + "Temp." + media.format;
        std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"));
        for (int i = 0; i < constCount; i++)
        {
            cmd += +" -i \"" + constructs[i].path + "\"";
        }
        cmd += " -filter_complex \"";
        if (usedType == VIDEO)
        {
            for (int i = 0; i < constCount; i++)
            {
                cmd += "[" + std::to_string(i) + ":v:0]" + "[" + std::to_string(i) + ":a:0]";
            }
            cmd += "concat=n=" + std::to_string(constCount) + ":v=1:a=1[outv][outa]\" -vsync 2 -map \"[outv]\" -map \"[outa]\" " + TempFilePath;
        }
        else if (usedType == AUDIO)
        {
            for (int i = 0; i < constCount; i++)
            {
                cmd += "[" + std::to_string(i) + ":a:0]";
            }
            cmd += "concat=n=" + std::to_string(constCount) + ":v=0:a=1[outa]\" -map \"[outa]\" " + TempFilePath;
        }
        else
        {
            for (int i = 0; i < constCount; i++)
            {
                cmd += "[" + std::to_string(i) + "]";
            }
            cmd += "hstack=inputs=" + std::to_string(constCount) + "\" -vframes 1 " + TempFilePath;
        }
        if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
        else
        {
            // Suppress the system call
            cmd += " >nul 2>nul";
        }
        system(cmd.c_str());
        std::cout << "git";
        std::filesystem::remove(newFilePath);
        std::filesystem::rename(TempFilePath, newFilePath);
        frm::medias[idx].path = newFilePath;
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitRotating(FrameParser::RotatingContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Rotating " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't rotate an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        std::string deg = ctx->INT()->getText();
        eraseSpace(deg);
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf \"rotate=" + deg + "*PI/180\""
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf \"rotate=" + deg + "*PI/180\""
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitFlipping(FrameParser::FlippingContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Flipping " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't flip an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        bool vflip = ctx->FLIP_VH()->getText() == "vflip" ? true : false;
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf \"" + (vflip ? "vflip" : "hflip") + "\""
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf \"" + (vflip ? "vflip" : "hflip") + "\""
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitSettingSaturation(FrameParser::SettingSaturationContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Changing saturation of " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't change saturation of an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        std::string value = ctx->saturationValue->getText();
        eraseSpace(value);
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=saturation=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=saturation=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitSettingGamma(FrameParser::SettingGammaContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Changing gamma of " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't change gamma of an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        std::string value = ctx->gammaValue->getText();
        eraseSpace(value);
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=gamma=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=gamma=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitSettingBrightness(FrameParser::SettingBrightnessContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Changing brightness of " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't change brightness of an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        std::string value = ctx->brightnessValue->getText();
        eraseSpace(value);
        if (ctx->MINUS() != NULL) value = "-" + value;
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=brightness=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=brightness=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

antlrcpp::Any FrameVisitor::visitSettingContrast(FrameParser::SettingContrastContext* ctx) {
    std::string constructName = ctx->NAME()[0]->getText();
    std::cout << "Changing contrast of " << constructName + "\n";
    bool exists = false;
    int idx;
    Media media = frm::findByName(constructName, exists, idx);
    if (media.type == AUDIO)
    {
        std::cout << "Action at line " << ctx->start->getLine() << ": Can't change contrast of an audio type";
        exit(0);
    }

    std::string directory;

    if (ctx->STRING() != NULL)
    {
        directory = ctx->STRING()->getText();
        directory = directory.substr(1, directory.length() - 2);
        if (!std::filesystem::is_directory(directory))
        {
            std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
            exit(0);
        }
        if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
    }
    else
    {
        directory = frm::options.global_output ? frm::options.global_output_path
            : media.directory;
    }

    if (exists)
    {
        std::string value = ctx->contrastValue->getText();
        eraseSpace(value);
        if (ctx->MINUS() != NULL) value = "-" + value;
        if (ctx->AS() != NULL)
        {
            std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=contrast=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + newFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            newFilePath = "\"" + newFilePath + "\"";
            Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
            frm::medias.push_back(newMedia);
        }
        else
        {
            std::string newFilePath = directory + constructName + "." + media.format;
            std::string TempFilePath = directory + constructName + "Temp." + media.format;
            std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                + " -i \"" + media.path + "\" -vf eq=contrast=" + value
                + (frm::options.reencode ? std::string("") : std::string(" -c:a copy"))
                + " \"" + TempFilePath + "\"";
            if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
            else
            {
                // Suppress the system call
                cmd += " >nul 2>nul";
            }
            system(cmd.c_str());
            std::filesystem::remove(newFilePath);
            std::filesystem::rename(TempFilePath, newFilePath);
            frm::medias[idx].path = newFilePath;
        }
    }
    else
    {
        std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
        exit(0);
    }
    return visitChildren(ctx);
}

 antlrcpp::Any FrameVisitor:: visitSettingFramerate(FrameParser::SettingFramerateContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Changing framerate for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't change framerate for audio type";
         exit(0);
     }

     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't change framerate for frame type";
         exit(0);
     }

     std::string directory;

     std::string framerateValue = ctx->INT()->getText();
     eraseSpace(framerateValue); //2000000000

     if (std::stod(framerateValue) > 2000000000.0 || std::stod(framerateValue) < 0) {
         std::cout << "Action at line " << ctx->start->getLine() << ": framerate value has to be between 0 and 2000000000";
         exit(0);
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter:v \"fps=" + framerateValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter:v \"fps=" + framerateValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 //volume_action: SET VOLUME FOR NAME (INT) (AS NAME)? (SAVE_TO STRING)? #settingVolume
 antlrcpp::Any FrameVisitor:: visitSettingVolume(FrameParser::SettingVolumeContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Changing volume for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't change volume for frame type";
         exit(0);
     }

     std::string directory;

     std::string volumeValue = ctx->INT()->getText();
     eraseSpace(volumeValue);
     volumeValue = std::to_string(std::stod(volumeValue) / 100.0);

     if (std::stod(volumeValue) > 9999999.0) {
         std::cout << "Action at line " << ctx->start->getLine() << ": volume value has to be between -9999999.0 and 9999999.0";
         exit(0);
     }

     volumeValue = std::stod(volumeValue) < 100 ? '-' + volumeValue : volumeValue; // 100 = no change in audio, less than 100 means decreasing volume, more than 100 means increasing volume

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -af \"volume=" + volumeValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -af \"volume=" + volumeValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor:: visitScaling(FrameParser::ScalingContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Scaling " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't scale audio type";
         exit(0);
     }

     std::string directory;

     std::string widthValue = ctx->INT()[0]->getText();
     std::string heightValue = ctx->INT()[1]->getText();
     eraseSpace(widthValue);
     eraseSpace(heightValue);

     if (std::stoi(widthValue) > 16000.0 || std::stoi(widthValue) < 1) {
         std::cout << "Action at line " << ctx->start->getLine() << ": width value has to be between 1 and 16000";
         exit(0);
     }

     if (std::stoi(heightValue) > 16000.0 || std::stoi(heightValue) < 1) {
         std::cout << "Action at line " << ctx->start->getLine() << ": height value has to be between 1 and 16000";
         exit(0);
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf \"scale=" + widthValue + ':' + heightValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf \"scale=" + widthValue + ':' + heightValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
}

 //extract_N_subtitles_from_video:
// EXTRACT INT SUBTITLES FROM NAME SAVE_TO STRING #extractingNSubtitlesFromVideo
 antlrcpp::Any FrameVisitor:: visitExtractingNSubtitlesFromVideo(FrameParser::ExtractingNSubtitlesFromVideoContext* ctx)  {
     std::string constructName = ctx->NAME()->getText();
     //Enter action name     
     std::cout << "Extracting subtitles from " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't extract subtitles from audio type";
         exit(0);
     }
     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't extract subtitles from frame type";
         exit(0);
     }

     std::string directory;

     std::string numberOfSubtitles = ctx->INT()->getText();
     eraseSpace(numberOfSubtitles);

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     
     if (exists)
     {
             // generateSubtitlesStreamMapping
             std::string subtitlesStream = "";
             std::string newFilesPaths = "";
             // mapping each required subtitle stream
             // making each stream optional (in case N > the actual number of subtitles) to avoid errors "0:s:0?" the '?' makes it optional
             for (int i = 0; i < std::stoi(numberOfSubtitles); i++) { 
                 subtitlesStream += " -map \"0:s:" + std::to_string(i) + "?\" " + " \"" + directory + constructName + std::to_string(i) + ".srt" + "\" ";
             }
            
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + subtitlesStream;
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());        
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor:: visitExtractingKthSubtitleFromVideo(FrameParser::ExtractingKthSubtitleFromVideoContext* ctx)  {
     std::string constructName = ctx->NAME()->getText();
     //Enter action name     
     std::cout << "Extracting subtitles from " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't extract subtitles from audio type";
         exit(0);
     }

     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't extract subtitles from frame type";
         exit(0);
     }

     std::string directory;

     std::string kthSubtitleValue = ctx->INT()->getText();
     eraseSpace(kthSubtitleValue);

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         std::string newFilePath = directory + constructName + kthSubtitleValue + ".srt";
         //FFMPEG COMMAND
         std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
             + " -i \"" + media.path + "\"" + " -map \"0:s:" + std::to_string(std::stoi(kthSubtitleValue) - 1) + "?\"" +
             +" \"" + newFilePath + "\"";
         if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
         else
         {
             // Suppress the system call
             cmd += " >nul 2>nul";
         }
         system(cmd.c_str());
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 //add_subtitles_to_video: ADD SUBTITLES STRING FOR NAME (AS NAME)? (SAVE_TO STRING)? #addingSubtitlesToVideo
//ffmpeg -y -i boo_empty_previously_subtitles.mp4 -i marvel.srt -i shockzart.srt -map "0:v?" -map "0:a?" -map "0:s?" -map 1 -map 2 -c copy -c:s mov_text boo_append_subtitles.mp4
 antlrcpp::Any FrameVisitor:: visitAddingSubtitlesToVideo(FrameParser::AddingSubtitlesToVideoContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Adding subtitles to " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't add subtitles to audio type";
         exit(0);
     }

     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't add subtitles to frame type";
         exit(0);
     }

     std::string directory;

     std::string subtitlePath = ctx->STRING()[0]->getText();

     if (ctx->STRING()[0] != NULL) 
     { //handle it
         std::string subtitleDirectory = subtitlePath;
         subtitleDirectory = subtitleDirectory.substr(1, subtitleDirectory.length() - 2);

         if (!std::filesystem::exists(subtitleDirectory) || !std::filesystem::is_regular_file(subtitleDirectory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid subtitle path";
             exit(0);
         }

         std::string subtitleFormat = subtitleDirectory; // save subtitle directory to check its format later in an if condition
         subtitleFormat = subtitleFormat.substr(subtitleFormat.rfind('.') + 1);
         if (subtitleFormat != "srt") 
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid subtitle file format";
             exit(0);
        }
     }

     if (ctx->STRING()[1] != NULL)
     {
         directory = ctx->STRING()[1]->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {
             //ffmpeg -y -i boo_empty_previously_subtitles.mp4 -i marvel.srt -i shockzart.srt -map "0:v?" -map "0:a?" -map "0:s?" -map 1 -map 2 -c copy -c:s mov_text boo_append_subtitles.mp4
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -i " + subtitlePath + " -map \"0:v?\" -map \"0:a?\" -map \"0:s?\" -map 1 "
                 + std::string(" -c copy -c:s mov_text")
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -i " + subtitlePath + " -map \"0:v?\" -map \"0:a?\" -map \"0:s?\" -map 1 "
                 + std::string(" -c:s move_text")
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
}


 //sharpen_action: SHARPEN NAME (WIDTH INT HEIGHT INT)? (INTENSITY effectAmount=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING)? #sharpening
 //ffmpeg -i bateekha.mp4 -filter unsharp output_sharpen.mp4
 //ffmpeg -i bateekha.mp4 -filter "unsharp=lx=3:ly=3:la=1.0" output_sharpen_or.mp4
 antlrcpp::Any FrameVisitor:: visitSharpening(FrameParser::SharpeningContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Sharpening " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't sharpen audio type";
         exit(0);
     }

     std::string directory;
     std::string widthValue = "5";
     std::string heightValue = "5";
     std::string effectIntensity = "1.0";

     if (ctx->WIDTH() != NULL && ctx->HEIGHT() != NULL) {
         widthValue = ctx->INT()[0]->getText();
         heightValue = ctx->INT()[1]->getText();
         eraseSpace(widthValue);
         eraseSpace(heightValue);

         if (std::stoi(widthValue) > 6 || std::stoi(widthValue) < 0) { std::cout << "Action at line " << ctx->start->getLine() << ": sharpen width value has to be between 0 and 6"; exit(0); }
         if (std::stoi(heightValue) > 6 || std::stoi(heightValue) < 0) { std::cout << "Action at line " << ctx->start->getLine() << ": sharpen height value has to be between 0 and 6"; exit(0); }
         widthValue = std::to_string(std::stoi(widthValue) * 2 + 1);
         heightValue = std::to_string(std::stoi(heightValue)* 2 + 1);
     }

     if (ctx->INTENSITY() != NULL) {
         effectIntensity = ctx->effectAmount->getText();
         eraseSpace(effectIntensity);
         if (std::stod(effectIntensity) > 5.0 || std::stod(effectIntensity) < 0.0) { std::cout << "Action at line " << ctx->start->getLine() << ": sharpen effect intensity value has to be between 0.0 and 5.0"; exit(0); }
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter \"unsharp=lx=" + widthValue + ":ly=" + heightValue + ":la=" + effectIntensity + "\"" 
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter \"unsharp=lx=" + widthValue + ":ly=" + heightValue + ":la=" + effectIntensity + "\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor:: visitBlurring(FrameParser::BlurringContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Blurring " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't blur audio type";
         exit(0);
     }

     std::string directory;
     std::string widthValue = "5";
     std::string heightValue = "5";
     std::string effectIntensity = "1.0";

     if (ctx->WIDTH() != NULL && ctx->HEIGHT() != NULL) {
         widthValue = ctx->INT()[0]->getText();
         heightValue = ctx->INT()[1]->getText();
         eraseSpace(widthValue);
         eraseSpace(heightValue);

         if (std::stoi(widthValue) > 6 || std::stoi(widthValue) < 0) { std::cout << "Action at line " << ctx->start->getLine() << ": blur value has to be between 0 and 6"; exit(0); }
         if (std::stoi(heightValue) > 6 || std::stoi(heightValue) < 0) { std::cout << "Action at line " << ctx->start->getLine() << ": blur value has to be between 0 and 6"; exit(0); }
         widthValue = std::to_string(std::stoi(widthValue) * 2 + 1);
         heightValue = std::to_string(std::stoi(heightValue) * 2 + 1);
     }

     if (ctx->INTENSITY() != NULL) {
         effectIntensity = ctx->effectAmount->getText();
         eraseSpace(effectIntensity);
         if (std::stod(effectIntensity) > 2.0 || std::stod(effectIntensity) < 0.0) { std::cout << "Action at line " << ctx->start->getLine() << ": blur effect intensity value has to be between 0.0 and 2.0"; exit(0); }
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter \"unsharp=lx=" + widthValue + ":ly=" + heightValue + ":la=-" + effectIntensity + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter \"unsharp=lx=" + widthValue + ":ly=" + heightValue + ":la=" + effectIntensity + "\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor:: visitConverting(FrameParser::ConvertingContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     std::cout << "Converting format of " << constructName + "\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     if (media.type == AUDIO && ctx->AUDIO_FORMAT() == NULL)
     {
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't convert different types";
         exit(0);
     }
     else if (media.type == VIDEO && ctx->VIDEO_FORMAT() == NULL)
     {
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't convert different types";
         exit(0);
     }
     if (media.type == FRAME && ctx->IMAGE_FORMAT() == NULL)
     {
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't convert different types";
         exit(0);
     }

     std::string directory;

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + ctx->type->getText();
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + ctx->type->getText();
             std::string TempFilePath = directory + constructName + "Temp." + ctx->type->getText();
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct does not exist";
         exit(0);
     }
    return visitChildren(ctx);
}

 antlrcpp::Any FrameVisitor:: visitNoiseReduction(FrameParser::NoiseReductionContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Applying noise reduction on " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't apply noise reduction on frame type";
         exit(0);
     }

     std::string directory;

     std::string mixValue = "0";

     if (ctx->MIX() != NULL) {
         mixValue = ctx->mixValue->getText();
         eraseSpace(mixValue); // Check applicable boundaries
         if (std::stod(mixValue) < -1.0 || std::stod(mixValue) > 1.0) { std::cout << "Action at line " << ctx->start->getLine() << ": Noise reduction mix value has to be between -1.0 and 1.0"; exit(0); }
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string ffmpegENV = std::getenv("ffmpeg");
         std::string arnndnModelPath = (ffmpegENV.back() == '\\')
             ?
             ffmpegENV + "model.rnnn" : ffmpegENV + '\\' + "model.rnnn";
         std::string temp = arnndnModelPath;

         for (int i = arnndnModelPath.length() - 1; i >= 0; i--) { // escape every ':' and '\' as ffmpeg rejects unescaped absolute paths
             if (arnndnModelPath[i] == '\\') {
                 temp.insert(i, "\\\\\\");
             }
             if (arnndnModelPath[i] == ':') {
                 temp.insert(i, "\\\\");
             }
         }

         std::string escapedArnndnModelPath = temp; // Path to be used in the cmd command
         if (!std::filesystem::exists(arnndnModelPath) || !std::filesystem::is_regular_file(arnndnModelPath)) {
             std::cout << "Line " << ctx->start->getLine() << ": Download arnndn model from our website"; exit(0);
         }

             if (ctx->AS() != NULL)
             {

                 std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
                 //FFMPEG command
                 std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                     + " -i \"" + media.path + "\"" + " -af \"arnndn=model=" + escapedArnndnModelPath + ":mix=" + mixValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                     + " \"" + newFilePath + "\"";
                 if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                 else
                 {
                     // Suppress the system call
                     cmd += " >nul 2>nul";
                 }
                 system(cmd.c_str());
                 newFilePath = "\"" + newFilePath + "\"";
                 Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
                 frm::medias.push_back(newMedia);
             }
             else
             {
                 std::string newFilePath = directory + constructName + "." + media.format;
                 std::string TempFilePath = directory + constructName + "Temp." + media.format;
                 //FFMPEG COMMAND
                 std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                     + " -i \"" + media.path + "\"" + " -af \"arnndn=model=" + escapedArnndnModelPath + ":mix=" + mixValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                     + " \"" + TempFilePath + "\"";
                 if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                 else
                 {
                     // Suppress the system call
                     cmd += " >nul 2>nul";
                 }
                 system(cmd.c_str());
                 std::filesystem::remove(newFilePath);
                 std::filesystem::rename(TempFilePath, newFilePath);
                 frm::medias[idx].path = newFilePath;
             }
         }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor:: visitNormalization(FrameParser::NormalizationContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Normalizing " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't normalize frame type";
         exit(0);
     }

     std::string directory;

     std::string loudValue = "19"; // default values
     std::string rangeValue = "7";
     std::string peakValue = "7";

     if (ctx->LOUDNESS() != NULL) {
         loudValue = ctx->loudnessValue->getText();
         eraseSpace(loudValue);
         if (std::stod(loudValue) < 0.0 || std::stod(loudValue) > 65.0) { std::cout << "Action at line " << ctx->start->getLine() << ": Normalization's loudness value has to be between 0.0 and 65.0"; exit(0); }
     }

     if (ctx->RANGE() != NULL) {
         rangeValue = ctx->rangeValue->getText();
         eraseSpace(rangeValue);
         if (std::stod(rangeValue) < 1.0 || std::stod(rangeValue) > 50.0) { std::cout << "Action at line " << ctx->start->getLine() << ": Normalization's range value has to be between 0.0 and 9.0"; exit(0); }
     }

     if (ctx->PEAK() != NULL) {
         peakValue = ctx->peakValue->getText();
         eraseSpace(peakValue);
         if (std::stod(peakValue) < 0.0 || std::stod(peakValue) > 9.0) { std::cout << "Action at line " << ctx->start->getLine() << ": Normalization's peak value has to be between 0.0 and 9.0"; exit(0); }
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     loudValue = std::to_string((std::stod(loudValue) + 5) * -1);
     peakValue = std::to_string(std::stod(peakValue) - 9);
     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -af \"loudnorm=I=" + loudValue + ":LRA=" + rangeValue + ":TP=" + peakValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -af \"loudnorm=I=" + loudValue + ":LRA=" + rangeValue + ":TP=" + peakValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor::visitSettingBass(FrameParser::SettingBassContext* ctx) {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Changing bass for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't change bass for frame type";
         exit(0);
     }

     std::string directory;

     std::string gainValue = "0";
     std::string frequencyValue = "100";
     if (ctx->GAIN() != NULL) {
         gainValue = ctx->gainValue->getText();
         eraseSpace(gainValue);
         gainValue = ctx->MINUS() != NULL ? '-' + gainValue : gainValue;
         if (std::stod(gainValue) < -900.0 || std::stod(gainValue) > 900.0) { std::cout << "Action at line " << ctx->start->getLine() << ": bass's gain value has to be between -900.0 and 900.0"; exit(0); }
     }

     if (ctx->FREQUENCY() != NULL) {
         frequencyValue = ctx->frequencyValue->getText();
         eraseSpace(frequencyValue);
         if (std::stod(frequencyValue) < 0.0 || std::stod(frequencyValue) > 999999.0) { std::cout << "Action at line " << ctx->start->getLine() << ": bass's frequency value has to be between 0.0 and 999999.0"; exit(0); }
     }

         if (ctx->STRING() != NULL)
         {
             directory = ctx->STRING()->getText();
             directory = directory.substr(1, directory.length() - 2);
             if (!std::filesystem::is_directory(directory))
             {
                 std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
                 exit(0);
             }
             if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
         }
         else
         {
             directory = frm::options.global_output ? frm::options.global_output_path
                 : media.directory;
         }


         if (exists)
         {
             if (ctx->AS() != NULL)
             {

                 std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
                 //FFMPEG command
                 std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                     + " -i \"" + media.path + "\"" + " -af \"bass=g=" + gainValue + ":f=" + frequencyValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                     + " \"" + newFilePath + "\"";
                 if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                 else
                 {
                     // Suppress the system call
                     cmd += " >nul 2>nul";
                 }
                 system(cmd.c_str());
                 newFilePath = "\"" + newFilePath + "\"";
                 Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
                 frm::medias.push_back(newMedia);
             }
             else
             {
                 std::string newFilePath = directory + constructName + "." + media.format;
                 std::string TempFilePath = directory + constructName + "Temp." + media.format;
                 //FFMPEG COMMAND
                 std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                     + " -i \"" + media.path + "\"" + " -af \"bass=g=" + gainValue + ":f=" + frequencyValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                     + " \"" + TempFilePath + "\"";
                 if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
                 else
                 {
                     // Suppress the system call
                     cmd += " >nul 2>nul";
                 }
                 system(cmd.c_str());
                 std::filesystem::remove(newFilePath);
                 std::filesystem::rename(TempFilePath, newFilePath);
                 frm::medias[idx].path = newFilePath;
             }
         }
         else
         {
             std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
             exit(0);
         }
         return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor:: visitSettingTreble(FrameParser::SettingTrebleContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Changing bass for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't change bass for frame type";
         exit(0);
     }

     std::string directory;

     std::string gainValue = "0";
     std::string frequencyValue = "3000";
     if (ctx->GAIN() != NULL) {
         gainValue = ctx->gainValue->getText();
         eraseSpace(gainValue);
         gainValue = ctx->MINUS() != NULL ? '-' + gainValue : gainValue;
         if (std::stod(gainValue) < -900.0 || std::stod(gainValue) > 900.0) { std::cout << "Action at line " << ctx->start->getLine() << ": treble's gain value has to be between -900.0 and 900.0"; exit(0); }
     }

     if (ctx->FREQUENCY() != NULL) {
         frequencyValue = ctx->frequencyValue->getText();
         eraseSpace(frequencyValue);
         if (std::stod(frequencyValue) < 0.0 || std::stod(frequencyValue) > 999999.0) { std::cout << "Action at line " << ctx->start->getLine() << ": treble's frequency value has to be between 0.0 and 999999.0"; exit(0); }
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -af \"treble=g=" + gainValue + ":f=" + frequencyValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -af \"treble=g=" + gainValue + ":f=" + frequencyValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 antlrcpp::Any FrameVisitor:: visitShowingBitscope(FrameParser::ShowingBitscopeContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Displaying bitscope for " << constructName + "\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't display bitscope for a frame type";
         exit(0);
     }

     std::string directory;

     std::string colors = ctx->COLORS() != NULL ? "colors=" + ctx->COLOR()[0]->getText() + '|' + ctx->COLOR()[1]->getText() + ":" : "";
     std::string widthValue = "1024";
     std::string heightValue = "256";

     if (ctx->WIDTH() != NULL && ctx->HEIGHT() != NULL) {
         widthValue = ctx->INT()[0]->getText();
         heightValue = ctx->INT()[1]->getText();
         eraseSpace(widthValue);
         eraseSpace(heightValue);
         if (std::stoi(widthValue) > 16000.0 || std::stoi(widthValue) < 1) {std::cout << "Action at line " << ctx->start->getLine() << ": width value has to be between 1 and 16000";exit(0);}
         if (std::stoi(heightValue) > 16000.0 || std::stoi(heightValue) < 1) {std::cout << "Action at line " << ctx->start->getLine() << ": height value has to be between 1 and 16000";exit(0);}
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"abitscope=" +
                 colors +
                 "size=" + widthValue + 'x' + heightValue
                 + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"abitscope=" +
                 colors +
                 "size=" + widthValue + 'x' + heightValue
                 + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy"))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }

     return visitChildren(ctx);
 }

 //ahistogram_action: SHOW 'audio' HISTOGRAM FOR NAME (DISPLAY MODE dmode=('single' | 'separate')) (AS NAME)? (SAVE_TO STRING)? #showingAHistogram
//ffmpeg -y -i omar.mp3 -filter_complex "ahistogram=dmode=separate" ahistogram.mp4
 antlrcpp::Any FrameVisitor:: visitShowingAHistogram(FrameParser::ShowingAHistogramContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Displaying histogram for " << constructName + "\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't display histogram for a frame type";
         exit(0);
     }

     std::string directory;
     std::string displayModeValue = ctx->dmode->getText();
     if (ctx->DISPLAY() == NULL || ctx->MODE() == NULL || ctx->dmode == NULL) {
         std::cout << "Action at line " << ctx->start->getLine() << ": Incorrect syntax, display mode is missing";
         exit(0);
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string mediaFormat = (media.type == VIDEO) ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"ahistogram=" + displayModeValue + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, VIDEO);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"ahistogram=" + displayModeValue + "\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 //aphasemeter_action: SHOW PHASEMETER FOR NAME (AS NAME)? (SAVE_TO STRING)? #showingPhasemeter
 antlrcpp::Any FrameVisitor:: visitShowingPhasemeter(FrameParser::ShowingPhasemeterContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Displaying phasemeter for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't display phasemeter for a frame type";
         exit(0);
     }

     std::string directory;

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"aphasemeter\"" +
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, VIDEO);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"aphasemeter\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }

 //ffmpeg -y -i omar.mp4 -filter_complex "avectorscope=m=lissajous_xy:draw=line" avectorspace.mp4
//avectorscope_action: SHOW 'audio' VECTORSCOPE FOR NAME (DRAWING MODE drawingMode=('dot' | 'line'))? (AS NAME)? (SAVE_TO STRING)? #showingVectorscope
 antlrcpp::Any FrameVisitor:: visitShowingVectorscope(FrameParser::ShowingVectorscopeContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Displaying vectorscope for " << constructName + "\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't display vectorscope for frame type";
         exit(0);
     }

     std::string directory;

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     std::string drawingMode = "";
     if (ctx->DRAWING() != NULL && ctx->MODE() != NULL && ctx->drawingMode != NULL) {
         drawingMode = ":draw= " + ctx->drawingMode->getText();
     } 
     else if (ctx->DRAWING() != NULL &&
         (ctx->MODE() == NULL)) //handle ctx->drawingMode no value provided: (ctx->MODE() == NULL || ctx->drawingMode)
     {
         std::cout << "Line " << ctx->start->getLine() << ": Incorrect syntax";
         exit(0);
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"avectorscope=m=lissajous_xy"
                 + drawingMode + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, VIDEO);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"avectorscope=m=lissajous_xy:draw="
                 + drawingMode + "\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
    return visitChildren(ctx);
}


 //showcqt_action: SHOW CQT FOR NAME (AS NAME)? (SAVE_TO STRING)? #showingCQT
 //ffmpeg -y -i omar.mp3 -filter_complex "showcqt" omar_showcqt.mp4
 antlrcpp::Any FrameVisitor:: visitShowingCQT(FrameParser::ShowingCQTContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Displaying Constant-Q form (CQT) for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't display Constant-Q form (CQT) for a frame type";
         exit(0);
     }

     std::string directory;

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showcqt" 
                 + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showcqt"
                 + "\"" 
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }

     return visitChildren(ctx);
}

 //showfreqs_action: SHOW FREQUENCIES FOR NAME (DISPLAY MODE freqsDModes=('line' | 'bar' | 'dot'))? (COLORS COLOR COLOR)? (CHANNEL MODE freqsCMode=('combined' | 'separate') )? (AS NAME)? (SAVE_TO STRING)? #showingFreqs
 //ffmpeg -y -i omar.mp3 -filter_complex "showfreqs=mode=bar:colors=magenta|yellow:cmode=separate" 
 antlrcpp::Any FrameVisitor:: visitShowingFreqs(FrameParser::ShowingFreqsContext* ctx)  
 {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Displaying frequencies for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't display frequencies for a frame type";
         exit(0);
     }

     std::string directory;

     std::string colors = "";
     if (ctx->COLORS() != NULL && ctx->COLOR().size() == 2) {
         colors = ctx->COLOR()[0]->getText() + '|' + ctx->COLOR()[1]->getText();
     }
     else if (ctx->COLORS() != NULL && ctx->COLOR().size() < 2) {
         std::cout << "Action at line " << ctx->start->getLine() << ": Incorrect syntax";
         exit(0);
     }
     
     std::string freqsDMode = "bar"; //default value
     if (ctx->DISPLAY() != NULL) {
         freqsDMode = ctx->freqsDModes->getText();
     }

     std::string freqsCMode = "combined"; // default value
     if (ctx->CHANNEL() != NULL) {
         freqsCMode = ctx->freqsCMode->getText();
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showfreqs=mode=" + freqsDMode + ":colors=" + colors + ":cmode=" + freqsCMode
                 + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showfreqs=mode=" + freqsDMode + ":colors=" + colors + ":cmode=" + freqsCMode
                 + "\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }

     return visitChildren(ctx);
}

 //showspatial_action: SHOW SPATIAL FOR NAME (AS NAME)? (SAVE_TO STRING)? #showingCQT
 antlrcpp::Any FrameVisitor:: visitShowingSpatial(FrameParser::ShowingSpatialContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Displaying spatial for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't display spatial for a frame type";
         exit(0);
     }

     std::string directory;

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showspatial"
                 + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showspatial"
                 + "\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }

     return visitChildren(ctx);
 }

//ffmpeg -y -i omar.mp3 -filter_complex "showspectrum=mode=separate" showspectrum.mp4
//showspectrum_action: SHOW SPECTRUM FOR NAME (DISPLAY MODE spectrumDMode=('combined'|'separate')) (AS NAME)? (SAVE_TO STRING)? #showingSpectrum
 antlrcpp::Any FrameVisitor:: visitShowingSpectrum(FrameParser::ShowingSpectrumContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Showing spectrum for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't show spectrum for frame type";
         exit(0);
     }

     std::string directory;
     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     std::string spectrumMode = "";
     if (ctx->DISPLAY() != NULL && ctx->MODE() != NULL && ctx->spectrumDMode != NULL) {
         spectrumMode = ctx->spectrumDMode->getText();
     }
     else {
         std::cout << "Line " << ctx->start->getLine() << ": Incorrect syntax ";
         exit(0);
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex " + "\"showspectrum=mode="
                 + spectrumMode
                 + "\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, VIDEO);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex " + "\"showspectrum=mode="
                 + spectrumMode
                 + "\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
    return visitChildren(ctx);
}

 antlrcpp::Any FrameVisitor:: visitShowingVolume(FrameParser::ShowingVolumeContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Showing volume for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't show volume for frame type";
         exit(0);
     }

     std::string directory;

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         std::string mediaFormat = media.type == VIDEO ? media.format : "mp4";
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + mediaFormat;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showvolume\""
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, VIDEO);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + mediaFormat;
             std::string TempFilePath = directory + constructName + "Temp." + mediaFormat;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -filter_complex \"showvolume\""
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
    return visitChildren(ctx);
}

 //ffmpeg - y - i fighter.png - vf super2xsai fighter_super2xsai.png
//SCALE PIXEL ART NAME(AS NAME) ? (SAVE_TO STRING) ? #scalingPixelArt
 antlrcpp::Any FrameVisitor:: visitScalingPixelArt(FrameParser::ScalingPixelArtContext* ctx)  {

     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Pixel art scaling for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't pixel art scale audio type";
         exit(0);
     }

     std::string directory;
     
     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         if (ctx->AS() != NULL)
         {
             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf super2xsai " + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf super2xsai " + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
}

 //sobel_action: SOBEL NAME (INTENSITY intensityAmount=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING)? #sobel
 ////ffmpeg -y -i fight.mp4 -vf sobel=scale=1 sobel_fight.mp4
 antlrcpp::Any FrameVisitor:: visitSobel(FrameParser::SobelContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Sobelling " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't sobel audio type";
         exit(0);
     }

     std::string directory;
     std::string intensityValue = "1";
     if (ctx->INTENSITY() != NULL) {
         intensityValue = ctx->intensityAmount->getText();
         eraseSpace(intensityValue);
     }
     
     if (std::stod(intensityValue) < 0 || std::stod(intensityValue) > 65535.0) {
         std::cout << "Action at line " << ctx->start->getLine() << ": sobel's intensity value has to be between 0.0 and 65535.0";
         exit(0);
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf \"sobel=scale=" + intensityValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf \"sobel=scale=" + intensityValue + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
 }


 //tmix_action: MIX 'frames' INT? FOR NAME (AS NAME)? (SAVE_TO STRING)? #mixing
 antlrcpp::Any FrameVisitor:: visitMixing(FrameParser::MixingContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Mixing successive frames for " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't mix frames for audio type";
         exit(0);
     } 
     
     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Can't mix frames for frame type";
         exit(0);
     }

     std::string directory;

     std::string numberOfSuccessiveFrames = "3"; //default value

     if (ctx->INT() != NULL) {
         numberOfSuccessiveFrames = ctx->INT()->getText();
         eraseSpace(numberOfSuccessiveFrames);
     }

     if (std::stod(numberOfSuccessiveFrames) < 1 || std::stod(numberOfSuccessiveFrames) > 1024) {
         std::cout << "Action at line " << ctx->start->getLine() << ": Number of successive frames has to be between 1 and 1024";
         exit(0);
     }

     if (ctx->STRING() != NULL)
     {
         directory = ctx->STRING()->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }

     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf \"tmix=frames=" + numberOfSuccessiveFrames + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf \"tmix=frames=" + numberOfSuccessiveFrames + "\"" + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
}

 //embedding_subtitles_action: EMBED SUBTITLES STRING IN NAME (AS NAME)? (SAVE_TO STRING) #embeddingSubtitles
 antlrcpp::Any FrameVisitor:: visitEmbeddingSubtitles(FrameParser::EmbeddingSubtitlesContext* ctx)  {
     std::string constructName = ctx->NAME()[0]->getText();
     //Enter action name     
     std::cout << "Embedding subtitles in " << constructName + "...\n";
     bool exists = false;
     int idx;
     Media media = frm::findByName(constructName, exists, idx);
     //Incompatible types     
     if (media.type == AUDIO)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Cannot embed subtitles in audio type";
         exit(0);
     }

     if (media.type == FRAME)
     {
         //Error message
         std::cout << "Action at line " << ctx->start->getLine() << ": Cannot embed subtitles in frame type";
         exit(0);
     }

     std::string directory;

     std::string subtitlePath = ctx->STRING()[0]->getText();

     if (ctx->STRING()[0] != NULL)
     { //handle it
         std::string subtitleDirectory = subtitlePath;
         subtitleDirectory = subtitleDirectory.substr(1, subtitleDirectory.length() - 2);
         if (!std::filesystem::exists(subtitleDirectory) || !std::filesystem::is_regular_file(subtitleDirectory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid subtitle path";
             exit(0);
         }

         std::string subtitleFormat = subtitleDirectory; // save subtitle directory to check its format later in an if condition
         subtitleFormat = subtitleFormat.substr(subtitleFormat.rfind('.') + 1);
         if (subtitleFormat != "srt")
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid subtitle file format";
             exit(0);
         }

         std::string temp = subtitlePath;

         for (int i = subtitlePath.length() - 1; i >= 0; i--) { // escape every ':' and '\' as ffmpeg rejects unescaped absolute paths
             if (subtitlePath[i] == '\\') {
                 temp.insert(i, "\\\\\\");
             }
             if (subtitlePath[i] == ':') {
                 temp.insert(i, "\\\\");
             }
         }

         subtitlePath = temp; // Path to be used in the cmd command
     }

     if (ctx->STRING()[1] != NULL)
     {
         directory = ctx->STRING()[1]->getText();
         directory = directory.substr(1, directory.length() - 2);
         if (!std::filesystem::is_directory(directory))
         {
             std::cout << "Line " << ctx->start->getLine() << ": Invalid directory";
             exit(0);
         }
         if (directory[directory.length() - 1] != '\\') directory.push_back('\\');
     }
     else
     {
         directory = frm::options.global_output ? frm::options.global_output_path
             : media.directory;
     }


     if (exists)
     {
         if (ctx->AS() != NULL)
         {

             std::string newFilePath = directory + ctx->NAME()[1]->getText() + "." + media.format;
             //FFMPEG command
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf " + "subtitles=" + subtitlePath + " " + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + newFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             newFilePath = "\"" + newFilePath + "\"";
             Media newMedia(ctx->NAME()[1]->getText(), newFilePath, media.type);
             frm::medias.push_back(newMedia);
         }
         else
         {
             std::string newFilePath = directory + constructName + "." + media.format;
             std::string TempFilePath = directory + constructName + "Temp." + media.format;
             //FFMPEG COMMAND
             std::string cmd = "ffmpeg" + (frm::options.overwrite ? std::string(" -y") : std::string(" -n"))
                 + " -i \"" + media.path + "\"" + " -vf " + "subtitles=" + subtitlePath + " " + (frm::options.reencode ? std::string("") : std::string(" -c:v:a copy "))
                 + " \"" + TempFilePath + "\"";
             if (frm::options.debug) std::cout << "\n\n\n" << cmd << "\n";
             else
             {
                 // Suppress the system call
                 cmd += " >nul 2>nul";
             }
             system(cmd.c_str());
             std::filesystem::remove(newFilePath);
             std::filesystem::rename(TempFilePath, newFilePath);
             frm::medias[idx].path = newFilePath;
         }
     }
     else
     {
         std::cout << "Line " << ctx->start->getLine() << ": Construct " + ctx->NAME()[0]->getText() + " does not exist";
         exit(0);
     }
     return visitChildren(ctx);
}