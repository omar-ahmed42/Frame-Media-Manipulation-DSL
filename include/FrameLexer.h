
// Generated from Frame.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FrameLexer : public antlr4::Lexer {
public:
    enum {
        T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7,
        T__7 = 8, T__8 = 9, VIDEO_FORMAT = 10, VIDEO_CODEC = 11, IMAGE_FORMAT = 12,
        AUDIO_FORMAT = 13, DEBUG = 14, CODEC = 15, BITRATE = 16, SAMPLE_RATE = 17,
        PITCH = 18, TEMPO = 19, RESOLUTION = 20, SAVE_TO = 21, NUMBER = 22,
        SUBTITLES = 23, SUBTITLE = 24, FLIP_VH = 25, PIXEL = 26, ART = 27, FORMAT = 28,
        COMMENT = 29, NEWLINE = 30, OPTIONS = 31, AUDIO = 32, FRAME = 33, VIDEO = 34,
        PATH = 35, TRIM = 36, CROP = 37, FRAME_RATE = 38, EXTRACT = 39, RESIZE = 40,
        RATIO = 41, OVERLAY = 42, MERGE = 43, POSITION = 44, SATURATION = 45,
        GAMMA = 46, CONTRAST = 47, ROTATE = 48, FLIP = 49, BRIGHTNESS = 50,
        CONCATENATE = 51, SCALE = 52, SET = 53, VOLUME = 54, HEIGHT = 55, WIDTH = 56,
        SHARPEN = 57, BLUR = 58, CONVERT = 59, ADD = 60, FROM = 61, TO = 62,
        AS = 63, WITH = 64, FOR = 65, ON = 66, AT = 67, INTENSITY = 68, REDUCE = 69,
        NOISE = 70, MIX = 71, NORMALIZE = 72, LOUDNESS = 73, RANGE = 74, PEAK = 75,
        TREBLE = 76, BASS = 77, GAIN = 78, FREQUENCY = 79, SHOW = 80, BITSCOPE = 81,
        HISTOGRAM = 82, DISPLAY = 83, MODE = 84, PHASEMETER = 85, VECTORSCOPE = 86,
        DRAWING = 87, CQT = 88, FREQUENCIES = 89, SPATIAL = 90, SPECTRUM = 91,
        COLORS = 92, CHANNEL = 93, SOBEL = 94, EMBED = 95, IN = 96, TIME = 97,
        INT = 98, FLOAT = 99, DIGIT = 100, ALPHA = 101, COLON = 102, MINUS = 103,
        COMMA = 104, STRING = 105, LBRACE = 106, RBRACE = 107, REENCODE = 108,
        OVERWRITE = 109, YES = 110, NO = 111, OUTPUT = 112, COLOR = 113, NAME = 114,
        WS = 115
    };

    explicit FrameLexer(antlr4::CharStream* input);
    ~FrameLexer();

    virtual std::string getGrammarFileName() const override;
    virtual const std::vector<std::string>& getRuleNames() const override;

    virtual const std::vector<std::string>& getChannelNames() const override;
    virtual const std::vector<std::string>& getModeNames() const override;
    virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
    virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

    virtual const std::vector<uint16_t> getSerializedATN() const override;
    virtual const antlr4::atn::ATN& getATN() const override;

private:
    static std::vector<antlr4::dfa::DFA> _decisionToDFA;
    static antlr4::atn::PredictionContextCache _sharedContextCache;
    static std::vector<std::string> _ruleNames;
    static std::vector<std::string> _tokenNames;
    static std::vector<std::string> _channelNames;
    static std::vector<std::string> _modeNames;

    static std::vector<std::string> _literalNames;
    static std::vector<std::string> _symbolicNames;
    static antlr4::dfa::Vocabulary _vocabulary;
    static antlr4::atn::ATN _atn;
    static std::vector<uint16_t> _serializedATN;


    // Individual action functions triggered by action() above.

    // Individual semantic predicate functions triggered by sempred() above.

    struct Initializer {
        Initializer();
    };
    static Initializer _init;
};

