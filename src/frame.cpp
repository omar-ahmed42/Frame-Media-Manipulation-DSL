#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "../include/FrameLexer.h"
#include "../include//FrameParser.h"
#include "../include/FrameVisitor.h"

int main(int argc, const char* argv[])
{
    //std::ifstream infile("scripts/setting_contrast.frame");
    //std::ifstream infile("scripts/scale.frame");
    //std::ifstream infile("scripts/sharpen.frame");
    //std::ifstream infile("scripts/blur.frame");
    ////std::ifstream infile("scripts/normalize.frame");
    //std::ifstream infile("scripts/noise_reduction.frame");
    //std::ifstream infile("scripts/embed_subtitles.frame");
    //std::ifstream infile("scripts/adding_subtitles.frame");
    //std::ifstream infile("scripts/extract_N_subtitles_from_video.frame");
    //std::ifstream infile("scripts/extract_Kth_subtitles_from_video.frame");
    //std::ifstream infile("scripts/setting_framerate.frame");
    //std::ifstream infile("scripts/normalize.frame");
    //std::ifstream infile("scripts/bass.frame");
    //std::ifstream infile("scripts/treble.frame");
    //std::ifstream infile("scripts/abitscope.frame");
    //std::ifstream infile("scripts/ahistogram.frame");
    //std::ifstream infile("scripts/aphasemeter.frame");
    //std::ifstream infile("scripts/showcqt.frame");
    //std::ifstream infile("scripts/showvolume.frame");
    //std::ifstream infile("scripts/showvectorscope.frame");
    //std::ifstream infile("scripts/showfreqs.frame"); //done
    //std::ifstream infile("scripts/showspectrum.frame"); // done
    //std::ifstream infile("scripts/showspatial.frame"); //done
    //std::ifstream infile("scripts/mixing.frame");
    //std::ifstream infile("scripts/sobel.frame"); //done
    //std::ifstream infile("scripts/pixel_art_scaling.frame");
    //std::ifstream infile("scripts/setting_volume.frame");
    //std::ifstream infile("scripts/setting_saturation.frame");
    //std::ifstream infile("scripts/setting_contrast.frame");
    //std::ifstream infile("scripts/overlay.frame");
    std::ifstream infile("scripts/rotate.frame");
    //std::ifstream infile("scripts/flip.frame");
    antlr4::ANTLRInputStream input(infile);
    FrameLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    FrameParser parser(&tokens);
    FrameParser::FileContext* tree = parser.file();
    FrameVisitor visitor;
    visitor.visitFile(tree);
    return 0;
}