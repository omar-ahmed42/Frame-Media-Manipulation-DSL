
// Generated from Frame.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  FrameParser : public antlr4::Parser {
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

  enum {
    RuleFile = 0, RuleProgram = 1, RuleGlobal_options = 2, RuleReencode_option = 3, 
    RuleOutput_option = 4, RuleOverwrite_option = 5, RuleDebug_option = 6, 
    RuleConstruct = 7, RulePath = 8, RuleProperty = 9, RuleFormat = 10, 
    RuleCodec = 11, RuleBitrate = 12, RuleSample_rate = 13, RulePitch = 14, 
    RuleTempo = 15, RuleResolution = 16, RuleFramerate = 17, RuleAction = 18, 
    RuleTrim_action = 19, RuleCrop_action = 20, RuleOverlay_action = 21, 
    RuleExtract_audio_from_video_action = 22, RuleExtract_frames_from_video_action = 23, 
    RuleMerge_audio_with_video_action = 24, RuleConcatentation_action = 25, 
    RuleRotate_action = 26, RuleFlip_action = 27, RuleSaturation_action = 28, 
    RuleGamma_action = 29, RuleBrightness_action = 30, RuleContrast_action = 31, 
    RuleFrame_rate_action = 32, RuleVolume_action = 33, RuleScale_action = 34, 
    RuleExtract_N_subtitles_from_video = 35, RuleExtract_Kth_subtitle_from_video = 36, 
    RuleAdd_subtitles_to_video = 37, RuleSharpen_action = 38, RuleBlur_action = 39, 
    RuleConvert_action = 40, RuleNoise_reduction_action = 41, RuleNormalize_action = 42, 
    RuleBass_action = 43, RuleTreble_action = 44, RuleAbitscope_action = 45, 
    RuleAhistogram_action = 46, RuleAphasemeter_action = 47, RuleAvectorscope_action = 48, 
    RuleShowcqt_action = 49, RuleShowfreqs_action = 50, RuleShowspatial_action = 51, 
    RuleShowspectrum_action = 52, RuleShowvolume_action = 53, RuleSuper2xsai_action = 54, 
    RuleSobel_action = 55, RuleTmix_action = 56, RuleEmbedding_subtitles_action = 57
  };

  explicit FrameParser(antlr4::TokenStream *input);
  ~FrameParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class ProgramContext;
  class Global_optionsContext;
  class Reencode_optionContext;
  class Output_optionContext;
  class Overwrite_optionContext;
  class Debug_optionContext;
  class ConstructContext;
  class PathContext;
  class PropertyContext;
  class FormatContext;
  class CodecContext;
  class BitrateContext;
  class Sample_rateContext;
  class PitchContext;
  class TempoContext;
  class ResolutionContext;
  class FramerateContext;
  class ActionContext;
  class Trim_actionContext;
  class Crop_actionContext;
  class Overlay_actionContext;
  class Extract_audio_from_video_actionContext;
  class Extract_frames_from_video_actionContext;
  class Merge_audio_with_video_actionContext;
  class Concatentation_actionContext;
  class Rotate_actionContext;
  class Flip_actionContext;
  class Saturation_actionContext;
  class Gamma_actionContext;
  class Brightness_actionContext;
  class Contrast_actionContext;
  class Frame_rate_actionContext;
  class Volume_actionContext;
  class Scale_actionContext;
  class Extract_N_subtitles_from_videoContext;
  class Extract_Kth_subtitle_from_videoContext;
  class Add_subtitles_to_videoContext;
  class Sharpen_actionContext;
  class Blur_actionContext;
  class Convert_actionContext;
  class Noise_reduction_actionContext;
  class Normalize_actionContext;
  class Bass_actionContext;
  class Treble_actionContext;
  class Abitscope_actionContext;
  class Ahistogram_actionContext;
  class Aphasemeter_actionContext;
  class Avectorscope_actionContext;
  class Showcqt_actionContext;
  class Showfreqs_actionContext;
  class Showspatial_actionContext;
  class Showspectrum_actionContext;
  class Showvolume_actionContext;
  class Super2xsai_actionContext;
  class Sobel_actionContext;
  class Tmix_actionContext;
  class Embedding_subtitles_actionContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();
    antlr4::tree::TerminalNode *EOF();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstructContext *> construct();
    ConstructContext* construct(size_t i);
    Global_optionsContext *global_options();
    std::vector<antlr4::tree::TerminalNode *> COMMENT();
    antlr4::tree::TerminalNode* COMMENT(size_t i);
    std::vector<ActionContext *> action();
    ActionContext* action(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Global_optionsContext : public antlr4::ParserRuleContext {
  public:
    Global_optionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPTIONS();
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<Reencode_optionContext *> reencode_option();
    Reencode_optionContext* reencode_option(size_t i);
    std::vector<Output_optionContext *> output_option();
    Output_optionContext* output_option(size_t i);
    std::vector<Overwrite_optionContext *> overwrite_option();
    Overwrite_optionContext* overwrite_option(size_t i);
    std::vector<Debug_optionContext *> debug_option();
    Debug_optionContext* debug_option(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_optionsContext* global_options();

  class  Reencode_optionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *decision = nullptr;
    Reencode_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REENCODE();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *YES();
    antlr4::tree::TerminalNode *NO();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Reencode_optionContext* reencode_option();

  class  Output_optionContext : public antlr4::ParserRuleContext {
  public:
    Output_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OUTPUT();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Output_optionContext* output_option();

  class  Overwrite_optionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *decision = nullptr;
    Overwrite_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OVERWRITE();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *YES();
    antlr4::tree::TerminalNode *NO();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Overwrite_optionContext* overwrite_option();

  class  Debug_optionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *decision = nullptr;
    Debug_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEBUG();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *YES();
    antlr4::tree::TerminalNode *NO();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Debug_optionContext* debug_option();

  class  ConstructContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *type = nullptr;
    ConstructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    PathContext *path();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *AUDIO();
    antlr4::tree::TerminalNode *FRAME();
    antlr4::tree::TerminalNode *VIDEO();
    std::vector<PropertyContext *> property();
    PropertyContext* property(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructContext* construct();

  class  PathContext : public antlr4::ParserRuleContext {
  public:
    PathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATH();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathContext* path();

  class  PropertyContext : public antlr4::ParserRuleContext {
  public:
    PropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FormatContext *format();
    CodecContext *codec();
    FramerateContext *framerate();
    BitrateContext *bitrate();
    Sample_rateContext *sample_rate();
    PitchContext *pitch();
    TempoContext *tempo();
    ResolutionContext *resolution();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyContext* property();

  class  FormatContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *type = nullptr;
    FormatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORMAT();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *AUDIO_FORMAT();
    antlr4::tree::TerminalNode *IMAGE_FORMAT();
    antlr4::tree::TerminalNode *VIDEO_FORMAT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormatContext* format();

  class  CodecContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *type = nullptr;
    CodecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CODEC();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *AUDIO_FORMAT();
    antlr4::tree::TerminalNode *IMAGE_FORMAT();
    antlr4::tree::TerminalNode *VIDEO_CODEC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodecContext* codec();

  class  BitrateContext : public antlr4::ParserRuleContext {
  public:
    BitrateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BITRATE();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *INT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitrateContext* bitrate();

  class  Sample_rateContext : public antlr4::ParserRuleContext {
  public:
    Sample_rateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SAMPLE_RATE();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *INT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sample_rateContext* sample_rate();

  class  PitchContext : public antlr4::ParserRuleContext {
  public:
    PitchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PITCH();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *INT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PitchContext* pitch();

  class  TempoContext : public antlr4::ParserRuleContext {
  public:
    TempoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEMPO();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *FLOAT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TempoContext* tempo();

  class  ResolutionContext : public antlr4::ParserRuleContext {
  public:
    ResolutionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESOLUTION();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResolutionContext* resolution();

  class  FramerateContext : public antlr4::ParserRuleContext {
  public:
    FramerateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FRAME_RATE();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *INT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FramerateContext* framerate();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Trim_actionContext *trim_action();
    Crop_actionContext *crop_action();
    Overlay_actionContext *overlay_action();
    Extract_audio_from_video_actionContext *extract_audio_from_video_action();
    Extract_frames_from_video_actionContext *extract_frames_from_video_action();
    Merge_audio_with_video_actionContext *merge_audio_with_video_action();
    Concatentation_actionContext *concatentation_action();
    Rotate_actionContext *rotate_action();
    Flip_actionContext *flip_action();
    Saturation_actionContext *saturation_action();
    Frame_rate_actionContext *frame_rate_action();
    Gamma_actionContext *gamma_action();
    Brightness_actionContext *brightness_action();
    Contrast_actionContext *contrast_action();
    Volume_actionContext *volume_action();
    Scale_actionContext *scale_action();
    Extract_N_subtitles_from_videoContext *extract_N_subtitles_from_video();
    Extract_Kth_subtitle_from_videoContext *extract_Kth_subtitle_from_video();
    Add_subtitles_to_videoContext *add_subtitles_to_video();
    Sharpen_actionContext *sharpen_action();
    Blur_actionContext *blur_action();
    Convert_actionContext *convert_action();
    Noise_reduction_actionContext *noise_reduction_action();
    Normalize_actionContext *normalize_action();
    Bass_actionContext *bass_action();
    Treble_actionContext *treble_action();
    Abitscope_actionContext *abitscope_action();
    Ahistogram_actionContext *ahistogram_action();
    Aphasemeter_actionContext *aphasemeter_action();
    Avectorscope_actionContext *avectorscope_action();
    Showcqt_actionContext *showcqt_action();
    Showfreqs_actionContext *showfreqs_action();
    Showspatial_actionContext *showspatial_action();
    Showspectrum_actionContext *showspectrum_action();
    Showvolume_actionContext *showvolume_action();
    Super2xsai_actionContext *super2xsai_action();
    Sobel_actionContext *sobel_action();
    Tmix_actionContext *tmix_action();
    Embedding_subtitles_actionContext *embedding_subtitles_action();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();

  class  Trim_actionContext : public antlr4::ParserRuleContext {
  public:
    Trim_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Trim_actionContext() = default;
    void copyFrom(Trim_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TrimmingContext : public Trim_actionContext {
  public:
    TrimmingContext(Trim_actionContext *ctx);

    antlr4::tree::TerminalNode *TRIM();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FROM();
    std::vector<antlr4::tree::TerminalNode *> TIME();
    antlr4::tree::TerminalNode* TIME(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Trim_actionContext* trim_action();

  class  Crop_actionContext : public antlr4::ParserRuleContext {
  public:
    Crop_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Crop_actionContext() = default;
    void copyFrom(Crop_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CroppingContext : public Crop_actionContext {
  public:
    CroppingContext(Crop_actionContext *ctx);

    antlr4::tree::TerminalNode *CROP();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *WIDTH();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *HEIGHT();
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *POSITION();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Crop_actionContext* crop_action();

  class  Overlay_actionContext : public antlr4::ParserRuleContext {
  public:
    Overlay_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Overlay_actionContext() = default;
    void copyFrom(Overlay_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OverlayingContext : public Overlay_actionContext {
  public:
    OverlayingContext(Overlay_actionContext *ctx);

    antlr4::tree::TerminalNode *OVERLAY();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *ON();
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *POSITION();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Overlay_actionContext* overlay_action();

  class  Extract_audio_from_video_actionContext : public antlr4::ParserRuleContext {
  public:
    Extract_audio_from_video_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Extract_audio_from_video_actionContext() = default;
    void copyFrom(Extract_audio_from_video_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExtractingAudioFromVideoContext : public Extract_audio_from_video_actionContext {
  public:
    ExtractingAudioFromVideoContext(Extract_audio_from_video_actionContext *ctx);

    antlr4::tree::TerminalNode *EXTRACT();
    antlr4::tree::TerminalNode *FROM();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FORMAT();
    antlr4::tree::TerminalNode *AUDIO_FORMAT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Extract_audio_from_video_actionContext* extract_audio_from_video_action();

  class  Extract_frames_from_video_actionContext : public antlr4::ParserRuleContext {
  public:
    Extract_frames_from_video_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Extract_frames_from_video_actionContext() = default;
    void copyFrom(Extract_frames_from_video_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExtractingFramesFromVideoContext : public Extract_frames_from_video_actionContext {
  public:
    ExtractingFramesFromVideoContext(Extract_frames_from_video_actionContext *ctx);

    antlr4::tree::TerminalNode *EXTRACT();
    antlr4::tree::TerminalNode *FROM();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FORMAT();
    antlr4::tree::TerminalNode *IMAGE_FORMAT();
    antlr4::tree::TerminalNode *RATIO();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Extract_frames_from_video_actionContext* extract_frames_from_video_action();

  class  Merge_audio_with_video_actionContext : public antlr4::ParserRuleContext {
  public:
    Merge_audio_with_video_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Merge_audio_with_video_actionContext() = default;
    void copyFrom(Merge_audio_with_video_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MergingAudioWithVideoContext : public Merge_audio_with_video_actionContext {
  public:
    MergingAudioWithVideoContext(Merge_audio_with_video_actionContext *ctx);

    antlr4::tree::TerminalNode *MERGE();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Merge_audio_with_video_actionContext* merge_audio_with_video_action();

  class  Concatentation_actionContext : public antlr4::ParserRuleContext {
  public:
    Concatentation_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Concatentation_actionContext() = default;
    void copyFrom(Concatentation_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConcatentatingContext : public Concatentation_actionContext {
  public:
    ConcatentatingContext(Concatentation_actionContext *ctx);

    antlr4::tree::TerminalNode *CONCATENATE();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Concatentation_actionContext* concatentation_action();

  class  Rotate_actionContext : public antlr4::ParserRuleContext {
  public:
    Rotate_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Rotate_actionContext() = default;
    void copyFrom(Rotate_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RotatingContext : public Rotate_actionContext {
  public:
    RotatingContext(Rotate_actionContext *ctx);

    antlr4::tree::TerminalNode *ROTATE();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Rotate_actionContext* rotate_action();

  class  Flip_actionContext : public antlr4::ParserRuleContext {
  public:
    Flip_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Flip_actionContext() = default;
    void copyFrom(Flip_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FlippingContext : public Flip_actionContext {
  public:
    FlippingContext(Flip_actionContext *ctx);

    antlr4::tree::TerminalNode *FLIP();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FLIP_VH();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Flip_actionContext* flip_action();

  class  Saturation_actionContext : public antlr4::ParserRuleContext {
  public:
    Saturation_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Saturation_actionContext() = default;
    void copyFrom(Saturation_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingSaturationContext : public Saturation_actionContext {
  public:
    SettingSaturationContext(Saturation_actionContext *ctx);

    antlr4::Token *saturationValue = nullptr;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *SATURATION();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Saturation_actionContext* saturation_action();

  class  Gamma_actionContext : public antlr4::ParserRuleContext {
  public:
    Gamma_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Gamma_actionContext() = default;
    void copyFrom(Gamma_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingGammaContext : public Gamma_actionContext {
  public:
    SettingGammaContext(Gamma_actionContext *ctx);

    antlr4::Token *gammaValue = nullptr;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *GAMMA();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Gamma_actionContext* gamma_action();

  class  Brightness_actionContext : public antlr4::ParserRuleContext {
  public:
    Brightness_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Brightness_actionContext() = default;
    void copyFrom(Brightness_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingBrightnessContext : public Brightness_actionContext {
  public:
    SettingBrightnessContext(Brightness_actionContext *ctx);

    antlr4::Token *brightnessValue = nullptr;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *BRIGHTNESS();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Brightness_actionContext* brightness_action();

  class  Contrast_actionContext : public antlr4::ParserRuleContext {
  public:
    Contrast_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Contrast_actionContext() = default;
    void copyFrom(Contrast_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingContrastContext : public Contrast_actionContext {
  public:
    SettingContrastContext(Contrast_actionContext *ctx);

    antlr4::Token *contrastValue = nullptr;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *CONTRAST();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Contrast_actionContext* contrast_action();

  class  Frame_rate_actionContext : public antlr4::ParserRuleContext {
  public:
    Frame_rate_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Frame_rate_actionContext() = default;
    void copyFrom(Frame_rate_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingFramerateContext : public Frame_rate_actionContext {
  public:
    SettingFramerateContext(Frame_rate_actionContext *ctx);

    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *FRAME_RATE();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Frame_rate_actionContext* frame_rate_action();

  class  Volume_actionContext : public antlr4::ParserRuleContext {
  public:
    Volume_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Volume_actionContext() = default;
    void copyFrom(Volume_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingVolumeContext : public Volume_actionContext {
  public:
    SettingVolumeContext(Volume_actionContext *ctx);

    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *VOLUME();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Volume_actionContext* volume_action();

  class  Scale_actionContext : public antlr4::ParserRuleContext {
  public:
    Scale_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Scale_actionContext() = default;
    void copyFrom(Scale_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ScalingContext : public Scale_actionContext {
  public:
    ScalingContext(Scale_actionContext *ctx);

    antlr4::tree::TerminalNode *SCALE();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *WIDTH();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *HEIGHT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Scale_actionContext* scale_action();

  class  Extract_N_subtitles_from_videoContext : public antlr4::ParserRuleContext {
  public:
    Extract_N_subtitles_from_videoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Extract_N_subtitles_from_videoContext() = default;
    void copyFrom(Extract_N_subtitles_from_videoContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExtractingNSubtitlesFromVideoContext : public Extract_N_subtitles_from_videoContext {
  public:
    ExtractingNSubtitlesFromVideoContext(Extract_N_subtitles_from_videoContext *ctx);

    antlr4::tree::TerminalNode *EXTRACT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *SUBTITLES();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Extract_N_subtitles_from_videoContext* extract_N_subtitles_from_video();

  class  Extract_Kth_subtitle_from_videoContext : public antlr4::ParserRuleContext {
  public:
    Extract_Kth_subtitle_from_videoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Extract_Kth_subtitle_from_videoContext() = default;
    void copyFrom(Extract_Kth_subtitle_from_videoContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExtractingKthSubtitleFromVideoContext : public Extract_Kth_subtitle_from_videoContext {
  public:
    ExtractingKthSubtitleFromVideoContext(Extract_Kth_subtitle_from_videoContext *ctx);

    antlr4::tree::TerminalNode *EXTRACT();
    antlr4::tree::TerminalNode *SUBTITLE();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Extract_Kth_subtitle_from_videoContext* extract_Kth_subtitle_from_video();

  class  Add_subtitles_to_videoContext : public antlr4::ParserRuleContext {
  public:
    Add_subtitles_to_videoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Add_subtitles_to_videoContext() = default;
    void copyFrom(Add_subtitles_to_videoContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddingSubtitlesToVideoContext : public Add_subtitles_to_videoContext {
  public:
    AddingSubtitlesToVideoContext(Add_subtitles_to_videoContext *ctx);

    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUBTITLES();
    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Add_subtitles_to_videoContext* add_subtitles_to_video();

  class  Sharpen_actionContext : public antlr4::ParserRuleContext {
  public:
    Sharpen_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Sharpen_actionContext() = default;
    void copyFrom(Sharpen_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SharpeningContext : public Sharpen_actionContext {
  public:
    SharpeningContext(Sharpen_actionContext *ctx);

    antlr4::Token *effectAmount = nullptr;
    antlr4::tree::TerminalNode *SHARPEN();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *WIDTH();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *HEIGHT();
    antlr4::tree::TerminalNode *INTENSITY();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *FLOAT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Sharpen_actionContext* sharpen_action();

  class  Blur_actionContext : public antlr4::ParserRuleContext {
  public:
    Blur_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Blur_actionContext() = default;
    void copyFrom(Blur_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BlurringContext : public Blur_actionContext {
  public:
    BlurringContext(Blur_actionContext *ctx);

    antlr4::Token *effectAmount = nullptr;
    antlr4::tree::TerminalNode *BLUR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *WIDTH();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *HEIGHT();
    antlr4::tree::TerminalNode *INTENSITY();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *FLOAT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Blur_actionContext* blur_action();

  class  Convert_actionContext : public antlr4::ParserRuleContext {
  public:
    Convert_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Convert_actionContext() = default;
    void copyFrom(Convert_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConvertingContext : public Convert_actionContext {
  public:
    ConvertingContext(Convert_actionContext *ctx);

    antlr4::tree::TerminalNode *CONVERT();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Convert_actionContext* convert_action();

  class  Noise_reduction_actionContext : public antlr4::ParserRuleContext {
  public:
    Noise_reduction_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Noise_reduction_actionContext() = default;
    void copyFrom(Noise_reduction_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NoiseReductionContext : public Noise_reduction_actionContext {
  public:
    NoiseReductionContext(Noise_reduction_actionContext *ctx);

    antlr4::Token *mixValue = nullptr;
    antlr4::tree::TerminalNode *REDUCE();
    antlr4::tree::TerminalNode *NOISE();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *MIX();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Noise_reduction_actionContext* noise_reduction_action();

  class  Normalize_actionContext : public antlr4::ParserRuleContext {
  public:
    Normalize_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Normalize_actionContext() = default;
    void copyFrom(Normalize_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NormalizationContext : public Normalize_actionContext {
  public:
    NormalizationContext(Normalize_actionContext *ctx);

    antlr4::Token *loudnessValue = nullptr;
    antlr4::Token *rangeValue = nullptr;
    antlr4::Token *peakValue = nullptr;
    antlr4::tree::TerminalNode *NORMALIZE();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *LOUDNESS();
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *PEAK();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();
    std::vector<antlr4::tree::TerminalNode *> FLOAT();
    antlr4::tree::TerminalNode* FLOAT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Normalize_actionContext* normalize_action();

  class  Bass_actionContext : public antlr4::ParserRuleContext {
  public:
    Bass_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Bass_actionContext() = default;
    void copyFrom(Bass_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingBassContext : public Bass_actionContext {
  public:
    SettingBassContext(Bass_actionContext *ctx);

    antlr4::Token *gainValue = nullptr;
    antlr4::Token *frequencyValue = nullptr;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *BASS();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *GAIN();
    antlr4::tree::TerminalNode *FREQUENCY();
    antlr4::tree::TerminalNode *AS();
    std::vector<antlr4::tree::TerminalNode *> FLOAT();
    antlr4::tree::TerminalNode* FLOAT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Bass_actionContext* bass_action();

  class  Treble_actionContext : public antlr4::ParserRuleContext {
  public:
    Treble_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Treble_actionContext() = default;
    void copyFrom(Treble_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SettingTrebleContext : public Treble_actionContext {
  public:
    SettingTrebleContext(Treble_actionContext *ctx);

    antlr4::Token *gainValue = nullptr;
    antlr4::Token *frequencyValue = nullptr;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *TREBLE();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *GAIN();
    antlr4::tree::TerminalNode *FREQUENCY();
    antlr4::tree::TerminalNode *AS();
    std::vector<antlr4::tree::TerminalNode *> FLOAT();
    antlr4::tree::TerminalNode* FLOAT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Treble_actionContext* treble_action();

  class  Abitscope_actionContext : public antlr4::ParserRuleContext {
  public:
    Abitscope_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Abitscope_actionContext() = default;
    void copyFrom(Abitscope_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingBitscopeContext : public Abitscope_actionContext {
  public:
    ShowingBitscopeContext(Abitscope_actionContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *BITSCOPE();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *COLORS();
    std::vector<antlr4::tree::TerminalNode *> COLOR();
    antlr4::tree::TerminalNode* COLOR(size_t i);
    antlr4::tree::TerminalNode *WIDTH();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *HEIGHT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Abitscope_actionContext* abitscope_action();

  class  Ahistogram_actionContext : public antlr4::ParserRuleContext {
  public:
    Ahistogram_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Ahistogram_actionContext() = default;
    void copyFrom(Ahistogram_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingAHistogramContext : public Ahistogram_actionContext {
  public:
    ShowingAHistogramContext(Ahistogram_actionContext *ctx);

    antlr4::Token *dmode = nullptr;
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *HISTOGRAM();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *DISPLAY();
    antlr4::tree::TerminalNode *MODE();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Ahistogram_actionContext* ahistogram_action();

  class  Aphasemeter_actionContext : public antlr4::ParserRuleContext {
  public:
    Aphasemeter_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Aphasemeter_actionContext() = default;
    void copyFrom(Aphasemeter_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingPhasemeterContext : public Aphasemeter_actionContext {
  public:
    ShowingPhasemeterContext(Aphasemeter_actionContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *PHASEMETER();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Aphasemeter_actionContext* aphasemeter_action();

  class  Avectorscope_actionContext : public antlr4::ParserRuleContext {
  public:
    Avectorscope_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Avectorscope_actionContext() = default;
    void copyFrom(Avectorscope_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingVectorscopeContext : public Avectorscope_actionContext {
  public:
    ShowingVectorscopeContext(Avectorscope_actionContext *ctx);

    antlr4::Token *drawingMode = nullptr;
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *VECTORSCOPE();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *DRAWING();
    antlr4::tree::TerminalNode *MODE();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Avectorscope_actionContext* avectorscope_action();

  class  Showcqt_actionContext : public antlr4::ParserRuleContext {
  public:
    Showcqt_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Showcqt_actionContext() = default;
    void copyFrom(Showcqt_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingCQTContext : public Showcqt_actionContext {
  public:
    ShowingCQTContext(Showcqt_actionContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *CQT();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Showcqt_actionContext* showcqt_action();

  class  Showfreqs_actionContext : public antlr4::ParserRuleContext {
  public:
    Showfreqs_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Showfreqs_actionContext() = default;
    void copyFrom(Showfreqs_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingFreqsContext : public Showfreqs_actionContext {
  public:
    ShowingFreqsContext(Showfreqs_actionContext *ctx);

    antlr4::Token *freqsDModes = nullptr;
    antlr4::Token *freqsCMode = nullptr;
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *FREQUENCIES();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *DISPLAY();
    std::vector<antlr4::tree::TerminalNode *> MODE();
    antlr4::tree::TerminalNode* MODE(size_t i);
    antlr4::tree::TerminalNode *COLORS();
    std::vector<antlr4::tree::TerminalNode *> COLOR();
    antlr4::tree::TerminalNode* COLOR(size_t i);
    antlr4::tree::TerminalNode *CHANNEL();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Showfreqs_actionContext* showfreqs_action();

  class  Showspatial_actionContext : public antlr4::ParserRuleContext {
  public:
    Showspatial_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Showspatial_actionContext() = default;
    void copyFrom(Showspatial_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingSpatialContext : public Showspatial_actionContext {
  public:
    ShowingSpatialContext(Showspatial_actionContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *SPATIAL();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Showspatial_actionContext* showspatial_action();

  class  Showspectrum_actionContext : public antlr4::ParserRuleContext {
  public:
    Showspectrum_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Showspectrum_actionContext() = default;
    void copyFrom(Showspectrum_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingSpectrumContext : public Showspectrum_actionContext {
  public:
    ShowingSpectrumContext(Showspectrum_actionContext *ctx);

    antlr4::Token *spectrumDMode = nullptr;
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *SPECTRUM();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *DISPLAY();
    antlr4::tree::TerminalNode *MODE();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Showspectrum_actionContext* showspectrum_action();

  class  Showvolume_actionContext : public antlr4::ParserRuleContext {
  public:
    Showvolume_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Showvolume_actionContext() = default;
    void copyFrom(Showvolume_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShowingVolumeContext : public Showvolume_actionContext {
  public:
    ShowingVolumeContext(Showvolume_actionContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *VOLUME();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Showvolume_actionContext* showvolume_action();

  class  Super2xsai_actionContext : public antlr4::ParserRuleContext {
  public:
    Super2xsai_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Super2xsai_actionContext() = default;
    void copyFrom(Super2xsai_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ScalingPixelArtContext : public Super2xsai_actionContext {
  public:
    ScalingPixelArtContext(Super2xsai_actionContext *ctx);

    antlr4::tree::TerminalNode *SCALE();
    antlr4::tree::TerminalNode *PIXEL();
    antlr4::tree::TerminalNode *ART();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Super2xsai_actionContext* super2xsai_action();

  class  Sobel_actionContext : public antlr4::ParserRuleContext {
  public:
    Sobel_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Sobel_actionContext() = default;
    void copyFrom(Sobel_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SobelContext : public Sobel_actionContext {
  public:
    SobelContext(Sobel_actionContext *ctx);

    antlr4::Token *intensityAmount = nullptr;
    antlr4::tree::TerminalNode *SOBEL();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *INTENSITY();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Sobel_actionContext* sobel_action();

  class  Tmix_actionContext : public antlr4::ParserRuleContext {
  public:
    Tmix_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Tmix_actionContext() = default;
    void copyFrom(Tmix_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MixingContext : public Tmix_actionContext {
  public:
    MixingContext(Tmix_actionContext *ctx);

    antlr4::tree::TerminalNode *MIX();
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Tmix_actionContext* tmix_action();

  class  Embedding_subtitles_actionContext : public antlr4::ParserRuleContext {
  public:
    Embedding_subtitles_actionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Embedding_subtitles_actionContext() = default;
    void copyFrom(Embedding_subtitles_actionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EmbeddingSubtitlesContext : public Embedding_subtitles_actionContext {
  public:
    EmbeddingSubtitlesContext(Embedding_subtitles_actionContext *ctx);

    antlr4::tree::TerminalNode *EMBED();
    antlr4::tree::TerminalNode *SUBTITLES();
    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);
    antlr4::tree::TerminalNode *IN();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SAVE_TO();
    antlr4::tree::TerminalNode *AS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Embedding_subtitles_actionContext* embedding_subtitles_action();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

