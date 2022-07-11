grammar Frame;

file: program EOF
;

program: (COMMENT | NEWLINE)* global_options? (COMMENT | NEWLINE)* construct (COMMENT | construct | action | NEWLINE)*
;

global_options: OPTIONS (NEWLINE)? LBRACE NEWLINE (reencode_option
| output_option
| overwrite_option
| debug_option
| NEWLINE)* RBRACE NEWLINE
;

reencode_option: REENCODE COLON decision=(YES | NO)
;

output_option: OUTPUT COLON STRING
;

overwrite_option: OVERWRITE COLON decision=(YES | NO)
;

debug_option: DEBUG COLON decision=(YES | NO)
;

construct: type=(AUDIO | FRAME | VIDEO) NAME (NEWLINE)? LBRACE NEWLINE path NEWLINE (property NEWLINE)* RBRACE NEWLINE
;

path: PATH COLON STRING
;

// fill in with available properties
property: format
| codec
| framerate
| bitrate
| sample_rate
| pitch
| tempo
| resolution
;

format: FORMAT COLON type=(AUDIO_FORMAT | IMAGE_FORMAT | VIDEO_FORMAT)
;

codec: CODEC COLON type=(AUDIO_FORMAT | IMAGE_FORMAT | VIDEO_CODEC)
;

bitrate: BITRATE COLON INT
;

sample_rate: SAMPLE_RATE COLON INT
;

pitch: PITCH COLON INT
;

tempo: TEMPO COLON FLOAT
;

resolution: RESOLUTION COLON INT 'x' INT
;

framerate: FRAME_RATE COLON INT
;

// fill in with other available actions
action : trim_action
| crop_action
| overlay_action
| extract_audio_from_video_action
| extract_frames_from_video_action
| merge_audio_with_video_action
| concatentation_action
| rotate_action
| flip_action
| saturation_action
| frame_rate_action
| gamma_action
| brightness_action
| contrast_action
| volume_action
| scale_action
| extract_N_subtitles_from_video
| extract_Kth_subtitle_from_video
| add_subtitles_to_video
| sharpen_action
| blur_action
| convert_action
| noise_reduction_action
| normalize_action
| bass_action
| treble_action
| abitscope_action
| ahistogram_action
| aphasemeter_action
| avectorscope_action
| showcqt_action
| showfreqs_action
| showspatial_action
| showspectrum_action
| showvolume_action
| super2xsai_action
| sobel_action
| tmix_action
| embedding_subtitles_action
;

trim_action : TRIM NAME FROM TIME TO TIME (AS NAME)? (SAVE_TO STRING)? #trimming
;

crop_action: CROP NAME (WIDTH INT HEIGHT INT) (AT POSITION INT INT)? (AS NAME)? (SAVE_TO STRING)? #cropping
;

overlay_action: OVERLAY NAME ON NAME AT POSITION MINUS? INT MINUS? INT (AS NAME)? (SAVE_TO STRING)? #overlaying
;

extract_audio_from_video_action : EXTRACT 'audio' FROM NAME FORMAT AUDIO_FORMAT (AS NAME)? (SAVE_TO STRING)? #extractingAudioFromVideo
;

extract_frames_from_video_action: EXTRACT 'frames' FROM NAME FORMAT IMAGE_FORMAT (RATIO INT INT)? (AS NAME)? (SAVE_TO STRING)? #extractingFramesFromVideo
;

merge_audio_with_video_action: MERGE NAME WITH NAME (AS NAME)? (SAVE_TO STRING)? #mergingAudioWithVideo
;

concatentation_action: CONCATENATE NAME+ (AS NAME)? (SAVE_TO STRING)? #concatentating
;

rotate_action: ROTATE NAME INT (AS NAME)? (SAVE_TO STRING)? #rotating
;

flip_action: FLIP NAME FLIP_VH (AS NAME)? (SAVE_TO STRING)? #flipping
;

saturation_action: SET SATURATION FOR NAME saturationValue=(FLOAT | INT) (AS NAME)? (SAVE_TO STRING)? #settingSaturation
;

gamma_action: SET GAMMA FOR NAME gammaValue=(FLOAT | INT) (AS NAME)? (SAVE_TO STRING)? #settingGamma
;

brightness_action: SET BRIGHTNESS FOR NAME MINUS? brightnessValue=(FLOAT | INT) (AS NAME)? (SAVE_TO STRING)? #settingBrightness
;

contrast_action: SET CONTRAST FOR NAME MINUS? contrastValue=(FLOAT | INT) (AS NAME)? (SAVE_TO STRING)? #settingContrast
;

frame_rate_action: SET FRAME_RATE FOR NAME INT (AS NAME)? (SAVE_TO STRING)? #settingFramerate
;

volume_action: SET VOLUME FOR NAME (INT) (AS NAME)? (SAVE_TO STRING)? #settingVolume
;

scale_action: SCALE NAME (WIDTH INT HEIGHT INT) (AS NAME)? (SAVE_TO STRING)? #scaling
;

extract_N_subtitles_from_video: EXTRACT INT SUBTITLES FROM NAME SAVE_TO STRING #extractingNSubtitlesFromVideo
;

extract_Kth_subtitle_from_video: EXTRACT SUBTITLE NUMBER INT FROM NAME SAVE_TO STRING #extractingKthSubtitleFromVideo
;

add_subtitles_to_video: ADD SUBTITLES STRING FOR NAME (AS NAME)? (SAVE_TO STRING)? #addingSubtitlesToVideo
;

sharpen_action: SHARPEN NAME (WIDTH INT HEIGHT INT)? (INTENSITY effectAmount=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING)? #sharpening
;

blur_action: BLUR NAME (WIDTH INT HEIGHT INT)? (INTENSITY effectAmount=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING)? #blurring
;

convert_action: CONVERT NAME FORMAT type=(AUDIO_FORMAT | IMAGE_FORMAT | VIDEO_FORMAT) (AS NAME)? (SAVE_TO STRING)? #converting
;

noise_reduction_action: REDUCE NOISE FOR NAME (MIX MINUS? mixValue=(FLOAT|INT)) (AS NAME)? (SAVE_TO STRING) #noiseReduction
;

normalize_action: NORMALIZE NAME (LOUDNESS loudnessValue=(FLOAT|INT))? (RANGE rangeValue=(FLOAT|INT))? (PEAK peakValue=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING)? #normalization
;

bass_action: SET BASS FOR NAME (GAIN MINUS? gainValue=(FLOAT|INT))? (FREQUENCY frequencyValue=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING) #settingBass
;

treble_action: SET TREBLE FOR NAME (GAIN MINUS? gainValue=(FLOAT|INT))? (FREQUENCY frequencyValue=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING) #settingTreble
;

abitscope_action: SHOW BITSCOPE FOR NAME (COLORS COLOR COLOR)? (WIDTH INT HEIGHT INT)? (AS NAME)? (SAVE_TO STRING)? #showingBitscope
;

ahistogram_action: SHOW 'audio' HISTOGRAM FOR NAME (DISPLAY MODE dmode=('single' | 'separate')) (AS NAME)? (SAVE_TO STRING)? #showingAHistogram
;

aphasemeter_action: SHOW PHASEMETER FOR NAME (AS NAME)? (SAVE_TO STRING)? #showingPhasemeter
;

avectorscope_action: SHOW 'audio' VECTORSCOPE FOR NAME (DRAWING MODE drawingMode=('dot' | 'line'))? (AS NAME)? (SAVE_TO STRING)? #showingVectorscope
;

showcqt_action: SHOW CQT FOR NAME (AS NAME)? (SAVE_TO STRING)? #showingCQT
;

showfreqs_action: SHOW FREQUENCIES FOR NAME (DISPLAY MODE freqsDModes=('line' | 'bar' | 'dot'))? (COLORS COLOR COLOR)? (CHANNEL MODE freqsCMode=('combined' | 'separate') )? (AS NAME)? (SAVE_TO STRING)? #showingFreqs
;

showspatial_action: SHOW SPATIAL FOR NAME (AS NAME)? (SAVE_TO STRING)? #showingSpatial
;

showspectrum_action: SHOW SPECTRUM FOR NAME (DISPLAY MODE spectrumDMode=('combined'|'separate')) (AS NAME)? (SAVE_TO STRING)? #showingSpectrum
;

showvolume_action: SHOW VOLUME FOR NAME (AS NAME)? (SAVE_TO STRING)? #showingVolume
;

super2xsai_action: SCALE PIXEL ART NAME (AS NAME)? (SAVE_TO STRING)? #scalingPixelArt
;

sobel_action: SOBEL NAME (INTENSITY intensityAmount=(FLOAT|INT))? (AS NAME)? (SAVE_TO STRING)? #sobel
;

tmix_action: MIX 'frames' INT? FOR NAME (AS NAME)? (SAVE_TO STRING)? #mixing
;

embedding_subtitles_action: EMBED SUBTITLES STRING IN NAME (AS NAME)? (SAVE_TO STRING) #embeddingSubtitles
;

VIDEO_FORMAT: ('mp4' | 'wmv' | 'webm' | 'avi' | 'mkv' | 'ogg' | 'gif')
;

VIDEO_CODEC: ('mpeg4' | 'vp8' | 'vp9' | 'h264' | 'h265' | 'libvpx')
;

IMAGE_FORMAT: ('jpeg' | 'jpg' | 'bmp' | 'png')
;

AUDIO_FORMAT: ('mp3' | 'aac' | 'wav' | 'flac' | 'opus')
;

DEBUG: 'debug' | 'debug mode'
;

CODEC: 'codec'
;

BITRATE: 'bitrate'
;

SAMPLE_RATE: 'sample rate'
;

PITCH: 'pitch'
;

TEMPO: 'tempo'
;

RESOLUTION: 'resolution'
;

SAVE_TO: 'save to'
;

NUMBER: 'number'
;

SUBTITLES: 'subtitles'
;

SUBTITLE: 'subtitle'
;

FLIP_VH: 'hflip' | 'vflip'
;

PIXEL: 'pixel'
;

ART: 'art'
;

FORMAT: 'format'
;

COMMENT: ( '//' ~[\r\n]* '\r'? NEWLINE
           | '/*' .*? '*/'
           ) -> skip
;

NEWLINE: '\r'? '\n'
;

OPTIONS: 'Options'
;

AUDIO: 'Audio'
;

FRAME: 'Frame'
;

VIDEO: 'Video'
;

PATH: 'path'
;

TRIM: 'trim'
;

CROP: 'crop'
;

FRAME_RATE: 'framerate'
;

EXTRACT: 'extract'
;

RESIZE: 'resize'
;

RATIO: 'ratio'
;

OVERLAY: 'overlay'
;

MERGE: 'merge'
;

POSITION: 'position'
;

SATURATION: 'saturation'
;

GAMMA: 'gamma'
;

CONTRAST: 'contrast'
;

ROTATE: 'rotate'
;

FLIP: 'flip'
;

BRIGHTNESS: 'brightness'
;

CONCATENATE: 'concatenate'
;

SCALE: 'scale'
;

SET: 'set'
;

VOLUME: 'volume'
;

HEIGHT: 'height'
;

WIDTH: 'width'
;

SHARPEN: 'sharpen'
;

BLUR: 'blur'
;

CONVERT: 'convert'
;

ADD: 'add'
;

FROM: 'from'
;

TO: 'to'
;

AS: 'as'
;

WITH: 'with'
;

FOR: 'for'
;

ON: 'on'
;

AT: 'at'
;

INTENSITY: 'intensity'
;

REDUCE: 'reduce'
;

NOISE: 'noise'
;

MIX: 'mix'
;

NORMALIZE: 'normalize'
;

LOUDNESS: 'loudness'
;

RANGE: 'range'
;

PEAK: 'peak'
;

TREBLE: 'treble'
;

BASS: 'bass'
;

GAIN: 'gain'
;

FREQUENCY: 'frequency'
;

SHOW: 'show'
;

BITSCOPE: 'bitscope'
;

HISTOGRAM: 'histogram'
;

DISPLAY: 'display'
;

MODE: 'mode'
;

PHASEMETER: 'phasemeter'
;

VECTORSCOPE: 'vectorscope'
;

DRAWING: 'drawing'
;

CQT: 'cqt'
;

FREQUENCIES: 'frequencies'
;

SPATIAL: 'spatial'
;

SPECTRUM: 'spectrum'
;

COLORS: 'colors'
;

CHANNEL: 'channel'
;

SOBEL: 'sobel'
;

EMBED: 'embed'
;

IN: 'in'
;

TIME: '"' DIGIT DIGIT COLON DIGIT DIGIT COLON DIGIT DIGIT '"'
;

INT: (SPACE | SPACE+) DIGIT+
;

FLOAT: (SPACE | SPACE+) DIGIT+ '.' (DIGIT+)
| (SPACE | SPACE+) DIGIT+
;

DIGIT: [0-9]
;

ALPHA: [a-zA-Z_]
;

COLON : ':'
;

MINUS: '-'
;

COMMA: ','
;

STRING : '"' .*? '"'
;

LBRACE: '{'
;

RBRACE: '}'
;

REENCODE: 'reencode'
;

OVERWRITE: 'overwrite'
;

YES: 'yes'
;

NO: 'no'
;

OUTPUT: 'output'
;

COLOR:  ('aliceblue'|'0xf0f8ff'|'antiquewhite'
               |'0xfaebd7'|'aqua'
               |'0x00ffff'|'aquamarine'
               |'0x7fffd4'|'azure'
               |'0xf0ffff'|'beige'
               |'0xf5f5dc'|'bisque'
               |'0xffe4c4'|'black'
               |'0x000000'|'blanchedalmond'
               |'0xffebcd'|'blue'
               |'0x0000ff'|'blueviolet'
               |'0x8a2be2'|'brown'
               |'0xa52a2a'|'burlywood'
               |'0xdeb887'|'cadetblue'
               |'0x5f9ea0'|'chartreuse'
               |'0x7fff00'|'chocolate'
               |'0xd2691e'|'coral'
               |'0xff7f50'|'cornflowerblue'
               |'0x6495ed'|'cornsilk'
               |'0xfff8dc'|'crimson'
               |'0xdc143c'|'cyan'
               |'0x00ffff'|'darkblue'
               |'0x00008b'|'darkcyan'
               |'0x008b8b'|'darkgoldenrod'
               |'0xb8860b'|'darkgray'
               |'0xa9a9a9'|'darkgreen'
               |'0x006400'|'darkkhaki'
               |'0xbdb76b'|'darkmagenta'
               |'0x8b008b'|'darkolivegreen'
               |'0x556b2f'|'darkorange'
               |'0xff8c00'|'darkorchid'
               |'0x9932cc'|'darkred'
               |'0x8b0000'|'darksalmon'
               |'0xe9967a'|'darkseagreen'
               |'0x8fbc8f'|'darkslateblue'
               |'0x483d8b'|'darkslategray'
               |'0x2f4f4f'|'darkturquoise'
               |'0x00ced1'|'darkviolet'
               |'0x9400d3'|'deeppink'
               |'0xff1493'|'deepskyblue'
               |'0x00bfff'|'dimgray'
               |'0x696969'|'dodgerblue'
               |'0x1e90ff'|'firebrick'
               |'0xb22222'|'floralwhite'
               |'0xfffaf0'|'forestgreen'
               |'0x228b22'|'fuchsia'
               |'0xff00ff'|'gainsboro'
               |'0xdcdcdc'|'ghostwhite'
               |'0xf8f8ff'|'gold'
               |'0xffd700'|'goldenrod'
               |'0xdaa520'|'gray'
               |'0x808080'|'green'
               |'0x008000'|'greenyellow'
               |'0xadff2f'|'honeydew'
               |'0xf0fff0'|'hotpink'
               |'0xff69b4'|'indianred'
               |'0xcd5c5c'|'indigo'
               |'0x4b0082'|'ivory'
               |'0xfffff0'|'khaki'
               |'0xf0e68c'|'lavender'
               |'0xe6e6fa'|'lavenderblush'
               |'0xfff0f5'|'lawngreen'
               |'0x7cfc00'|'lemonchiffon'
               |'0xfffacd'|'lightblue'
               |'0xadd8e6'|'lightcoral'
               |'0xf08080'|'lightcyan'
               |'0xe0ffff'|'lightgoldenrodyellow'
               |'0xfafad2'|'lightgreen'
               |'0x90ee90'|'lightgrey'
               |'0xd3d3d3'|'lightpink'
               |'0xffb6c1'|'lightsalmon'
               |'0xffa07a'|'lightseagreen'
               |'0x20b2aa'|'lightskyblue'
               |'0x87cefa'|'lightslategray'
               |'0x778899'|'lightsteelblue'
               |'0xb0c4de'|'lightyellow'
               |'0xffffe0'|'lime'
               |'0x00ff00'|'limegreen'
               |'0x32cd32'|'linen'
               |'0xfaf0e6'|'magenta'
               |'0xff00ff'|'maroon'
               |'0x800000'|'mediumaquamarine'
               |'0x66cdaa'|'mediumblue'
               |'0x0000cd'|'mediumorchid'
               |'0xba55d3'|'mediumpurple'
               |'0x9370d8'|'mediumseagreen'
               |'0x3cb371'|'mediumslateblue'
               |'0x7b68ee'|'mediumspringgreen'
               |'0x00fa9a'|'mediumturquoise'
               |'0x48d1cc'|'mediumvioletred'
               |'0xc71585'|'midnightblue'
               |'0x191970'|'mintcream'
               |'0xf5fffa'|'mistyrose'
               |'0xffe4e1'|'moccasin'
               |'0xffe4b5'|'navajowhite'
               |'0xffdead'|'navy'
               |'0x000080'|'oldlace'
               |'0xfdf5e6'|'olive'
               |'0x808000'|'olivedrab'
               |'0x6b8e23'|'orange'
               |'0xffa500'|'orangered'
               |'0xff4500'|'orchid'
               |'0xda70d6'|'palegoldenrod'
               |'0xeee8aa'|'palegreen'
               |'0x98fb98'|'paleturquoise'
               |'0xafeeee'|'palevioletred'
               |'0xd87093'|'papayawhip'
               |'0xffefd5'|'peachpuff'
               |'0xffdab9'|'peru'
               |'0xcd853f'|'pink'
               |'0xffc0cb'|'plum'
               |'0xdda0dd'|'powderblue'
               |'0xb0e0e6'|'purple'
               |'0x800080'|'red'
               |'0xff0000'|'rosybrown'
               |'0xbc8f8f'|'royalblue'
               |'0x4169e1'|'saddlebrown'
               |'0x8b4513'|'salmon'
               |'0xfa8072'|'sandybrown'
               |'0xf4a460'|'seagreen'
               |'0x2e8b57'|'seashell'
               |'0xfff5ee'|'sienna'
               |'0xa0522d'|'silver'
               |'0xc0c0c0'|'skyblue'
               |'0x87ceeb'|'slateblue'
               |'0x6a5acd'|'slategray'
               |'0x708090'|'snow'
               |'0xfffafa'|'springgreen'
               |'0x00ff7f'|'steelblue'
               |'0x4682b4'|'tan'
               |'0xd2b48c'|'teal'
               |'0x008080'|'thistle'
               |'0xd8bfd8'|'tomato'
               |'0xff6347'|'turquoise'
               |'0x40e0d0'|'violet'
               |'0xee82ee'|'wheat'
               |'0xf5deb3'|'white'
               |'0xffffff'|'whitesmoke'
               |'0xf5f5f5'|'yellow'
               |'0xffff00'|'yellowgreen'
               |'0x9acd32')
;

NAME: ALPHA ( ALPHA | DIGIT )*
;

fragment SPACE: ' '
;

WS: [ \t]+ -> skip
;