#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "../include/FrameLexer.h"
#include "../include/FrameParser.h"
#include "../include/FrameVisitor.h"

int main(int argc, const char* argv[])
{
    if (argc > 1)
    {
        std::string scriptPath = argv[1];
        std::ifstream infile(scriptPath);
        antlr4::ANTLRInputStream input(infile);
        FrameLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        FrameParser parser(&tokens);
        FrameParser::FileContext* tree = parser.file();
        FrameVisitor visitor;
        visitor.visitFile(tree);
    }
    else
    {
        std::cout << "Please specify a script for the interpreter!";
    }
    return 0;
}