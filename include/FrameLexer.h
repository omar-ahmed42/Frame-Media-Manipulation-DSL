
// Generated from Frame.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FrameLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, VIDEO_FORMAT = 10, VIDEO_CODEC = 11, IMAGE_FORMAT = 12, 
    AUDIO_FORMAT = 13, DEBUG = 14, CODEC = 15, BITRATE = 16, SAMPLE_RATE = 17, 
    PITCH = 18, TEMPO = 19, RESOLUTION = 20, HFLIP = 21, VFLIP = 22, SAVE_TO = 23, 
    NUMBER = 24, SUBTITLES = 25, SUBTITLE = 26, FLIP_VH = 27, PIXEL = 28, 
    ART = 29, FORMAT = 30, COMMENT = 31, NEWLINE = 32, OPTIONS = 33, AUDIO = 34, 
    FRAME = 35, VIDEO = 36, PATH = 37, TRIM = 38, CROP = 39, FRAME_RATE = 40, 
    EXTRACT = 41, RESIZE = 42, RATIO = 43, OVERLAY = 44, MERGE = 45, POSITION = 46, 
    SATURATION = 47, GAMMA = 48, CONTRAST = 49, ROTATE = 50, FLIP = 51, 
    BRIGHTNESS = 52, CONCATENATE = 53, SCALE = 54, SET = 55, VOLUME = 56, 
    HEIGHT = 57, WIDTH = 58, SHARPEN = 59, BLUR = 60, CONVERT = 61, ADD = 62, 
    FROM = 63, TO = 64, AS = 65, WITH = 66, FOR = 67, ON = 68, AT = 69, 
    INTENSITY = 70, REDUCE = 71, NOISE = 72, MIX = 73, NORMALIZE = 74, LOUDNESS = 75, 
    RANGE = 76, PEAK = 77, TREBLE = 78, BASS = 79, GAIN = 80, FREQUENCY = 81, 
    SHOW = 82, BITSCOPE = 83, HISTOGRAM = 84, DISPLAY = 85, MODE = 86, PHASEMETER = 87, 
    VECTORSCOPE = 88, DRAWING = 89, CQT = 90, FREQUENCIES = 91, SPATIAL = 92, 
    SPECTRUM = 93, COLORS = 94, CHANNEL = 95, SOBEL = 96, EMBED = 97, IN = 98, 
    TIME = 99, INT = 100, FLOAT = 101, DIGIT = 102, ALPHA = 103, COLON = 104, 
    MINUS = 105, COMMA = 106, STRING = 107, LBRACE = 108, RBRACE = 109, 
    REENCODE = 110, OVERWRITE = 111, YES = 112, NO = 113, OUTPUT = 114, 
    COLOR = 115, NAME = 116, WS = 117
  };

  explicit FrameLexer(antlr4::CharStream *input);
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

