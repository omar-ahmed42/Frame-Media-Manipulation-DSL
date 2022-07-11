
// Generated from Frame.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "FrameParser.h"

/**
 * This class defines an abstract visitor for a parse tree
 * produced by FrameParser.
 */
class  FrameVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FrameParser.
   */
     antlrcpp::Any visitFile(FrameParser::FileContext *context);

     antlrcpp::Any visitProgram(FrameParser::ProgramContext *context);

     antlrcpp::Any visitGlobal_options(FrameParser::Global_optionsContext *context);

     antlrcpp::Any visitReencode_option(FrameParser::Reencode_optionContext *context);

     antlrcpp::Any visitOutput_option(FrameParser::Output_optionContext *context);

     antlrcpp::Any visitOverwrite_option(FrameParser::Overwrite_optionContext* context);

     antlrcpp::Any visitDebug_option(FrameParser::Debug_optionContext* context);

     antlrcpp::Any visitConstruct(FrameParser::ConstructContext *context);

     antlrcpp::Any visitPath(FrameParser::PathContext *context);

     antlrcpp::Any visitProperty(FrameParser::PropertyContext *context);

     antlrcpp::Any visitFormat(FrameParser::FormatContext *context);

     antlrcpp::Any visitCodec(FrameParser::CodecContext* context);

     antlrcpp::Any visitBitrate(FrameParser::BitrateContext* context);

     antlrcpp::Any visitSample_rate(FrameParser::Sample_rateContext* context);

     antlrcpp::Any visitPitch(FrameParser::PitchContext* context);

     antlrcpp::Any visitTempo(FrameParser::TempoContext* context);

     antlrcpp::Any visitResolution(FrameParser::ResolutionContext* context);

     antlrcpp::Any visitFramerate(FrameParser::FramerateContext *context);

     antlrcpp::Any visitAction(FrameParser::ActionContext *context);

     antlrcpp::Any visitTrimming(FrameParser::TrimmingContext *context);

     antlrcpp::Any visitCropping(FrameParser::CroppingContext *context);

     antlrcpp::Any visitOverlaying(FrameParser::OverlayingContext *context);

     antlrcpp::Any visitExtractingAudioFromVideo(FrameParser::ExtractingAudioFromVideoContext *context);

     antlrcpp::Any visitExtractingFramesFromVideo(FrameParser::ExtractingFramesFromVideoContext *context);

     antlrcpp::Any visitMergingAudioWithVideo(FrameParser::MergingAudioWithVideoContext *context);

     antlrcpp::Any visitConcatentating(FrameParser::ConcatentatingContext *context);

     antlrcpp::Any visitRotating(FrameParser::RotatingContext *context);

     antlrcpp::Any visitFlipping(FrameParser::FlippingContext *context);

     antlrcpp::Any visitSettingSaturation(FrameParser::SettingSaturationContext *context);

     antlrcpp::Any visitSettingGamma(FrameParser::SettingGammaContext *context);

     antlrcpp::Any visitSettingBrightness(FrameParser::SettingBrightnessContext *context);

     antlrcpp::Any visitSettingContrast(FrameParser::SettingContrastContext *context);

     antlrcpp::Any visitSettingFramerate(FrameParser::SettingFramerateContext *context);

     antlrcpp::Any visitSettingVolume(FrameParser::SettingVolumeContext *context);

     antlrcpp::Any visitScaling(FrameParser::ScalingContext *context);

     antlrcpp::Any visitExtractingNSubtitlesFromVideo(FrameParser::ExtractingNSubtitlesFromVideoContext *context);

     antlrcpp::Any visitExtractingKthSubtitleFromVideo(FrameParser::ExtractingKthSubtitleFromVideoContext *context);

     antlrcpp::Any visitAddingSubtitlesToVideo(FrameParser::AddingSubtitlesToVideoContext *context);

     antlrcpp::Any visitSharpening(FrameParser::SharpeningContext *context);

     antlrcpp::Any visitBlurring(FrameParser::BlurringContext *context);

     antlrcpp::Any visitConverting(FrameParser::ConvertingContext *context);

     antlrcpp::Any visitNoiseReduction(FrameParser::NoiseReductionContext *context);

     antlrcpp::Any visitNormalization(FrameParser::NormalizationContext *context);

     antlrcpp::Any visitSettingBass(FrameParser::SettingBassContext *context);

     antlrcpp::Any visitSettingTreble(FrameParser::SettingTrebleContext *context);

     antlrcpp::Any visitShowingBitscope(FrameParser::ShowingBitscopeContext *context);

     antlrcpp::Any visitShowingAHistogram(FrameParser::ShowingAHistogramContext *context);

     antlrcpp::Any visitShowingPhasemeter(FrameParser::ShowingPhasemeterContext *context);

     antlrcpp::Any visitShowingVectorscope(FrameParser::ShowingVectorscopeContext *context);

     antlrcpp::Any visitShowingCQT(FrameParser::ShowingCQTContext *context);

     antlrcpp::Any visitShowingFreqs(FrameParser::ShowingFreqsContext *context);

     antlrcpp::Any visitShowingSpatial(FrameParser::ShowingSpatialContext *context);

     antlrcpp::Any visitShowingSpectrum(FrameParser::ShowingSpectrumContext *context);

     antlrcpp::Any visitShowingVolume(FrameParser::ShowingVolumeContext *context);

     antlrcpp::Any visitScalingPixelArt(FrameParser::ScalingPixelArtContext *context);

     antlrcpp::Any visitSobel(FrameParser::SobelContext *context);

     antlrcpp::Any visitMixing(FrameParser::MixingContext *context);

     antlrcpp::Any visitEmbeddingSubtitles(FrameParser::EmbeddingSubtitlesContext *context);

};

