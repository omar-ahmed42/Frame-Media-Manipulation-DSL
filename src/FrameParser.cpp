
// Generated from Frame.g4 by ANTLR 4.9.3


#include "../include/FrameVisitor.h"

#include "../include/FrameParser.h"


using namespace antlrcpp;
using namespace antlr4;

FrameParser::FrameParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FrameParser::~FrameParser() {
  delete _interpreter;
}

std::string FrameParser::getGrammarFileName() const {
  return "Frame.g4";
}

const std::vector<std::string>& FrameParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FrameParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

FrameParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FrameParser::ProgramContext* FrameParser::FileContext::program() {
  return getRuleContext<FrameParser::ProgramContext>(0);
}

tree::TerminalNode* FrameParser::FileContext::EOF() {
  return getToken(FrameParser::EOF, 0);
}


size_t FrameParser::FileContext::getRuleIndex() const {
  return FrameParser::RuleFile;
}


antlrcpp::Any FrameParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::FileContext* FrameParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, FrameParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    program();
    setState(117);
    match(FrameParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

FrameParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FrameParser::ConstructContext *> FrameParser::ProgramContext::construct() {
  return getRuleContexts<FrameParser::ConstructContext>();
}

FrameParser::ConstructContext* FrameParser::ProgramContext::construct(size_t i) {
  return getRuleContext<FrameParser::ConstructContext>(i);
}

FrameParser::Global_optionsContext* FrameParser::ProgramContext::global_options() {
  return getRuleContext<FrameParser::Global_optionsContext>(0);
}

std::vector<tree::TerminalNode *> FrameParser::ProgramContext::COMMENT() {
  return getTokens(FrameParser::COMMENT);
}

tree::TerminalNode* FrameParser::ProgramContext::COMMENT(size_t i) {
  return getToken(FrameParser::COMMENT, i);
}

std::vector<FrameParser::ActionContext *> FrameParser::ProgramContext::action() {
  return getRuleContexts<FrameParser::ActionContext>();
}

FrameParser::ActionContext* FrameParser::ProgramContext::action(size_t i) {
  return getRuleContext<FrameParser::ActionContext>(i);
}

std::vector<tree::TerminalNode *> FrameParser::ProgramContext::NEWLINE() {
  return getTokens(FrameParser::NEWLINE);
}

tree::TerminalNode* FrameParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(FrameParser::NEWLINE, i);
}


size_t FrameParser::ProgramContext::getRuleIndex() const {
  return FrameParser::RuleProgram;
}


antlrcpp::Any FrameParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::ProgramContext* FrameParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, FrameParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(122);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(119);
        _la = _input->LA(1);
        if (!(_la == FrameParser::COMMENT

        || _la == FrameParser::NEWLINE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        } 
      }
      setState(124);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(126);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::OPTIONS) {
      setState(125);
      global_options();
    }
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FrameParser::COMMENT

    || _la == FrameParser::NEWLINE) {
      setState(128);
      _la = _input->LA(1);
      if (!(_la == FrameParser::COMMENT

      || _la == FrameParser::NEWLINE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(134);
    construct();
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FrameParser::COMMENT)
      | (1ULL << FrameParser::NEWLINE)
      | (1ULL << FrameParser::AUDIO)
      | (1ULL << FrameParser::FRAME)
      | (1ULL << FrameParser::VIDEO)
      | (1ULL << FrameParser::TRIM)
      | (1ULL << FrameParser::CROP)
      | (1ULL << FrameParser::EXTRACT)
      | (1ULL << FrameParser::OVERLAY)
      | (1ULL << FrameParser::MERGE)
      | (1ULL << FrameParser::ROTATE)
      | (1ULL << FrameParser::FLIP)
      | (1ULL << FrameParser::CONCATENATE)
      | (1ULL << FrameParser::SCALE)
      | (1ULL << FrameParser::SET)
      | (1ULL << FrameParser::SHARPEN)
      | (1ULL << FrameParser::BLUR)
      | (1ULL << FrameParser::CONVERT)
      | (1ULL << FrameParser::ADD))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (FrameParser::REDUCE - 71))
      | (1ULL << (FrameParser::MIX - 71))
      | (1ULL << (FrameParser::NORMALIZE - 71))
      | (1ULL << (FrameParser::SHOW - 71))
      | (1ULL << (FrameParser::SOBEL - 71))
      | (1ULL << (FrameParser::EMBED - 71)))) != 0)) {
      setState(139);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FrameParser::COMMENT: {
          setState(135);
          match(FrameParser::COMMENT);
          break;
        }

        case FrameParser::AUDIO:
        case FrameParser::FRAME:
        case FrameParser::VIDEO: {
          setState(136);
          construct();
          break;
        }

        case FrameParser::TRIM:
        case FrameParser::CROP:
        case FrameParser::EXTRACT:
        case FrameParser::OVERLAY:
        case FrameParser::MERGE:
        case FrameParser::ROTATE:
        case FrameParser::FLIP:
        case FrameParser::CONCATENATE:
        case FrameParser::SCALE:
        case FrameParser::SET:
        case FrameParser::SHARPEN:
        case FrameParser::BLUR:
        case FrameParser::CONVERT:
        case FrameParser::ADD:
        case FrameParser::REDUCE:
        case FrameParser::MIX:
        case FrameParser::NORMALIZE:
        case FrameParser::SHOW:
        case FrameParser::SOBEL:
        case FrameParser::EMBED: {
          setState(137);
          action();
          break;
        }

        case FrameParser::NEWLINE: {
          setState(138);
          match(FrameParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(143);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Global_optionsContext ------------------------------------------------------------------

FrameParser::Global_optionsContext::Global_optionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::Global_optionsContext::OPTIONS() {
  return getToken(FrameParser::OPTIONS, 0);
}

tree::TerminalNode* FrameParser::Global_optionsContext::LBRACE() {
  return getToken(FrameParser::LBRACE, 0);
}

std::vector<tree::TerminalNode *> FrameParser::Global_optionsContext::NEWLINE() {
  return getTokens(FrameParser::NEWLINE);
}

tree::TerminalNode* FrameParser::Global_optionsContext::NEWLINE(size_t i) {
  return getToken(FrameParser::NEWLINE, i);
}

tree::TerminalNode* FrameParser::Global_optionsContext::RBRACE() {
  return getToken(FrameParser::RBRACE, 0);
}

std::vector<FrameParser::Reencode_optionContext *> FrameParser::Global_optionsContext::reencode_option() {
  return getRuleContexts<FrameParser::Reencode_optionContext>();
}

FrameParser::Reencode_optionContext* FrameParser::Global_optionsContext::reencode_option(size_t i) {
  return getRuleContext<FrameParser::Reencode_optionContext>(i);
}

std::vector<FrameParser::Output_optionContext *> FrameParser::Global_optionsContext::output_option() {
  return getRuleContexts<FrameParser::Output_optionContext>();
}

FrameParser::Output_optionContext* FrameParser::Global_optionsContext::output_option(size_t i) {
  return getRuleContext<FrameParser::Output_optionContext>(i);
}

std::vector<FrameParser::Overwrite_optionContext *> FrameParser::Global_optionsContext::overwrite_option() {
  return getRuleContexts<FrameParser::Overwrite_optionContext>();
}

FrameParser::Overwrite_optionContext* FrameParser::Global_optionsContext::overwrite_option(size_t i) {
  return getRuleContext<FrameParser::Overwrite_optionContext>(i);
}

std::vector<FrameParser::Debug_optionContext *> FrameParser::Global_optionsContext::debug_option() {
  return getRuleContexts<FrameParser::Debug_optionContext>();
}

FrameParser::Debug_optionContext* FrameParser::Global_optionsContext::debug_option(size_t i) {
  return getRuleContext<FrameParser::Debug_optionContext>(i);
}


size_t FrameParser::Global_optionsContext::getRuleIndex() const {
  return FrameParser::RuleGlobal_options;
}


antlrcpp::Any FrameParser::Global_optionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitGlobal_options(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::Global_optionsContext* FrameParser::global_options() {
  Global_optionsContext *_localctx = _tracker.createInstance<Global_optionsContext>(_ctx, getState());
  enterRule(_localctx, 4, FrameParser::RuleGlobal_options);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(FrameParser::OPTIONS);
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::NEWLINE) {
      setState(145);
      match(FrameParser::NEWLINE);
    }
    setState(148);
    match(FrameParser::LBRACE);
    setState(149);
    match(FrameParser::NEWLINE);
    setState(157);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FrameParser::DEBUG

    || _la == FrameParser::NEWLINE || ((((_la - 110) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 110)) & ((1ULL << (FrameParser::REENCODE - 110))
      | (1ULL << (FrameParser::OVERWRITE - 110))
      | (1ULL << (FrameParser::OUTPUT - 110)))) != 0)) {
      setState(155);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FrameParser::REENCODE: {
          setState(150);
          reencode_option();
          break;
        }

        case FrameParser::OUTPUT: {
          setState(151);
          output_option();
          break;
        }

        case FrameParser::OVERWRITE: {
          setState(152);
          overwrite_option();
          break;
        }

        case FrameParser::DEBUG: {
          setState(153);
          debug_option();
          break;
        }

        case FrameParser::NEWLINE: {
          setState(154);
          match(FrameParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(159);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(160);
    match(FrameParser::RBRACE);
    setState(161);
    match(FrameParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Reencode_optionContext ------------------------------------------------------------------

FrameParser::Reencode_optionContext::Reencode_optionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::Reencode_optionContext::REENCODE() {
  return getToken(FrameParser::REENCODE, 0);
}

tree::TerminalNode* FrameParser::Reencode_optionContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::Reencode_optionContext::YES() {
  return getToken(FrameParser::YES, 0);
}

tree::TerminalNode* FrameParser::Reencode_optionContext::NO() {
  return getToken(FrameParser::NO, 0);
}


size_t FrameParser::Reencode_optionContext::getRuleIndex() const {
  return FrameParser::RuleReencode_option;
}


antlrcpp::Any FrameParser::Reencode_optionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitReencode_option(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::Reencode_optionContext* FrameParser::reencode_option() {
  Reencode_optionContext *_localctx = _tracker.createInstance<Reencode_optionContext>(_ctx, getState());
  enterRule(_localctx, 6, FrameParser::RuleReencode_option);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(FrameParser::REENCODE);
    setState(164);
    match(FrameParser::COLON);
    setState(165);
    antlrcpp::downCast<Reencode_optionContext *>(_localctx)->decision = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::YES

    || _la == FrameParser::NO)) {
      antlrcpp::downCast<Reencode_optionContext *>(_localctx)->decision = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Output_optionContext ------------------------------------------------------------------

FrameParser::Output_optionContext::Output_optionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::Output_optionContext::OUTPUT() {
  return getToken(FrameParser::OUTPUT, 0);
}

tree::TerminalNode* FrameParser::Output_optionContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::Output_optionContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}


size_t FrameParser::Output_optionContext::getRuleIndex() const {
  return FrameParser::RuleOutput_option;
}


antlrcpp::Any FrameParser::Output_optionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitOutput_option(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::Output_optionContext* FrameParser::output_option() {
  Output_optionContext *_localctx = _tracker.createInstance<Output_optionContext>(_ctx, getState());
  enterRule(_localctx, 8, FrameParser::RuleOutput_option);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(FrameParser::OUTPUT);
    setState(168);
    match(FrameParser::COLON);
    setState(169);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Overwrite_optionContext ------------------------------------------------------------------

FrameParser::Overwrite_optionContext::Overwrite_optionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::Overwrite_optionContext::OVERWRITE() {
  return getToken(FrameParser::OVERWRITE, 0);
}

tree::TerminalNode* FrameParser::Overwrite_optionContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::Overwrite_optionContext::YES() {
  return getToken(FrameParser::YES, 0);
}

tree::TerminalNode* FrameParser::Overwrite_optionContext::NO() {
  return getToken(FrameParser::NO, 0);
}


size_t FrameParser::Overwrite_optionContext::getRuleIndex() const {
  return FrameParser::RuleOverwrite_option;
}


antlrcpp::Any FrameParser::Overwrite_optionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitOverwrite_option(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::Overwrite_optionContext* FrameParser::overwrite_option() {
  Overwrite_optionContext *_localctx = _tracker.createInstance<Overwrite_optionContext>(_ctx, getState());
  enterRule(_localctx, 10, FrameParser::RuleOverwrite_option);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(FrameParser::OVERWRITE);
    setState(172);
    match(FrameParser::COLON);
    setState(173);
    antlrcpp::downCast<Overwrite_optionContext *>(_localctx)->decision = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::YES

    || _la == FrameParser::NO)) {
      antlrcpp::downCast<Overwrite_optionContext *>(_localctx)->decision = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Debug_optionContext ------------------------------------------------------------------

FrameParser::Debug_optionContext::Debug_optionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::Debug_optionContext::DEBUG() {
  return getToken(FrameParser::DEBUG, 0);
}

tree::TerminalNode* FrameParser::Debug_optionContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::Debug_optionContext::YES() {
  return getToken(FrameParser::YES, 0);
}

tree::TerminalNode* FrameParser::Debug_optionContext::NO() {
  return getToken(FrameParser::NO, 0);
}


size_t FrameParser::Debug_optionContext::getRuleIndex() const {
  return FrameParser::RuleDebug_option;
}


antlrcpp::Any FrameParser::Debug_optionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitDebug_option(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::Debug_optionContext* FrameParser::debug_option() {
  Debug_optionContext *_localctx = _tracker.createInstance<Debug_optionContext>(_ctx, getState());
  enterRule(_localctx, 12, FrameParser::RuleDebug_option);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(FrameParser::DEBUG);
    setState(176);
    match(FrameParser::COLON);
    setState(177);
    antlrcpp::downCast<Debug_optionContext *>(_localctx)->decision = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::YES

    || _la == FrameParser::NO)) {
      antlrcpp::downCast<Debug_optionContext *>(_localctx)->decision = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructContext ------------------------------------------------------------------

FrameParser::ConstructContext::ConstructContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::ConstructContext::NAME() {
  return getToken(FrameParser::NAME, 0);
}

tree::TerminalNode* FrameParser::ConstructContext::LBRACE() {
  return getToken(FrameParser::LBRACE, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ConstructContext::NEWLINE() {
  return getTokens(FrameParser::NEWLINE);
}

tree::TerminalNode* FrameParser::ConstructContext::NEWLINE(size_t i) {
  return getToken(FrameParser::NEWLINE, i);
}

FrameParser::PathContext* FrameParser::ConstructContext::path() {
  return getRuleContext<FrameParser::PathContext>(0);
}

tree::TerminalNode* FrameParser::ConstructContext::RBRACE() {
  return getToken(FrameParser::RBRACE, 0);
}

tree::TerminalNode* FrameParser::ConstructContext::AUDIO() {
  return getToken(FrameParser::AUDIO, 0);
}

tree::TerminalNode* FrameParser::ConstructContext::FRAME() {
  return getToken(FrameParser::FRAME, 0);
}

tree::TerminalNode* FrameParser::ConstructContext::VIDEO() {
  return getToken(FrameParser::VIDEO, 0);
}

std::vector<FrameParser::PropertyContext *> FrameParser::ConstructContext::property() {
  return getRuleContexts<FrameParser::PropertyContext>();
}

FrameParser::PropertyContext* FrameParser::ConstructContext::property(size_t i) {
  return getRuleContext<FrameParser::PropertyContext>(i);
}


size_t FrameParser::ConstructContext::getRuleIndex() const {
  return FrameParser::RuleConstruct;
}


antlrcpp::Any FrameParser::ConstructContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitConstruct(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::ConstructContext* FrameParser::construct() {
  ConstructContext *_localctx = _tracker.createInstance<ConstructContext>(_ctx, getState());
  enterRule(_localctx, 14, FrameParser::RuleConstruct);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    antlrcpp::downCast<ConstructContext *>(_localctx)->type = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FrameParser::AUDIO)
      | (1ULL << FrameParser::FRAME)
      | (1ULL << FrameParser::VIDEO))) != 0))) {
      antlrcpp::downCast<ConstructContext *>(_localctx)->type = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(180);
    match(FrameParser::NAME);
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::NEWLINE) {
      setState(181);
      match(FrameParser::NEWLINE);
    }
    setState(184);
    match(FrameParser::LBRACE);
    setState(185);
    match(FrameParser::NEWLINE);
    setState(186);
    path();
    setState(187);
    match(FrameParser::NEWLINE);
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FrameParser::CODEC)
      | (1ULL << FrameParser::BITRATE)
      | (1ULL << FrameParser::SAMPLE_RATE)
      | (1ULL << FrameParser::PITCH)
      | (1ULL << FrameParser::TEMPO)
      | (1ULL << FrameParser::RESOLUTION)
      | (1ULL << FrameParser::FORMAT)
      | (1ULL << FrameParser::FRAME_RATE))) != 0)) {
      setState(188);
      property();
      setState(189);
      match(FrameParser::NEWLINE);
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(196);
    match(FrameParser::RBRACE);
    setState(197);
    match(FrameParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathContext ------------------------------------------------------------------

FrameParser::PathContext::PathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::PathContext::PATH() {
  return getToken(FrameParser::PATH, 0);
}

tree::TerminalNode* FrameParser::PathContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::PathContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}


size_t FrameParser::PathContext::getRuleIndex() const {
  return FrameParser::RulePath;
}


antlrcpp::Any FrameParser::PathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitPath(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::PathContext* FrameParser::path() {
  PathContext *_localctx = _tracker.createInstance<PathContext>(_ctx, getState());
  enterRule(_localctx, 16, FrameParser::RulePath);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(FrameParser::PATH);
    setState(200);
    match(FrameParser::COLON);
    setState(201);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

FrameParser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FrameParser::FormatContext* FrameParser::PropertyContext::format() {
  return getRuleContext<FrameParser::FormatContext>(0);
}

FrameParser::CodecContext* FrameParser::PropertyContext::codec() {
  return getRuleContext<FrameParser::CodecContext>(0);
}

FrameParser::FramerateContext* FrameParser::PropertyContext::framerate() {
  return getRuleContext<FrameParser::FramerateContext>(0);
}

FrameParser::BitrateContext* FrameParser::PropertyContext::bitrate() {
  return getRuleContext<FrameParser::BitrateContext>(0);
}

FrameParser::Sample_rateContext* FrameParser::PropertyContext::sample_rate() {
  return getRuleContext<FrameParser::Sample_rateContext>(0);
}

FrameParser::PitchContext* FrameParser::PropertyContext::pitch() {
  return getRuleContext<FrameParser::PitchContext>(0);
}

FrameParser::TempoContext* FrameParser::PropertyContext::tempo() {
  return getRuleContext<FrameParser::TempoContext>(0);
}

FrameParser::ResolutionContext* FrameParser::PropertyContext::resolution() {
  return getRuleContext<FrameParser::ResolutionContext>(0);
}


size_t FrameParser::PropertyContext::getRuleIndex() const {
  return FrameParser::RuleProperty;
}


antlrcpp::Any FrameParser::PropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitProperty(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::PropertyContext* FrameParser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 18, FrameParser::RuleProperty);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FrameParser::FORMAT: {
        enterOuterAlt(_localctx, 1);
        setState(203);
        format();
        break;
      }

      case FrameParser::CODEC: {
        enterOuterAlt(_localctx, 2);
        setState(204);
        codec();
        break;
      }

      case FrameParser::FRAME_RATE: {
        enterOuterAlt(_localctx, 3);
        setState(205);
        framerate();
        break;
      }

      case FrameParser::BITRATE: {
        enterOuterAlt(_localctx, 4);
        setState(206);
        bitrate();
        break;
      }

      case FrameParser::SAMPLE_RATE: {
        enterOuterAlt(_localctx, 5);
        setState(207);
        sample_rate();
        break;
      }

      case FrameParser::PITCH: {
        enterOuterAlt(_localctx, 6);
        setState(208);
        pitch();
        break;
      }

      case FrameParser::TEMPO: {
        enterOuterAlt(_localctx, 7);
        setState(209);
        tempo();
        break;
      }

      case FrameParser::RESOLUTION: {
        enterOuterAlt(_localctx, 8);
        setState(210);
        resolution();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormatContext ------------------------------------------------------------------

FrameParser::FormatContext::FormatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::FormatContext::FORMAT() {
  return getToken(FrameParser::FORMAT, 0);
}

tree::TerminalNode* FrameParser::FormatContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::FormatContext::AUDIO_FORMAT() {
  return getToken(FrameParser::AUDIO_FORMAT, 0);
}

tree::TerminalNode* FrameParser::FormatContext::IMAGE_FORMAT() {
  return getToken(FrameParser::IMAGE_FORMAT, 0);
}

tree::TerminalNode* FrameParser::FormatContext::VIDEO_FORMAT() {
  return getToken(FrameParser::VIDEO_FORMAT, 0);
}


size_t FrameParser::FormatContext::getRuleIndex() const {
  return FrameParser::RuleFormat;
}


antlrcpp::Any FrameParser::FormatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitFormat(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::FormatContext* FrameParser::format() {
  FormatContext *_localctx = _tracker.createInstance<FormatContext>(_ctx, getState());
  enterRule(_localctx, 20, FrameParser::RuleFormat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(FrameParser::FORMAT);
    setState(214);
    match(FrameParser::COLON);
    setState(215);
    antlrcpp::downCast<FormatContext *>(_localctx)->type = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FrameParser::VIDEO_FORMAT)
      | (1ULL << FrameParser::IMAGE_FORMAT)
      | (1ULL << FrameParser::AUDIO_FORMAT))) != 0))) {
      antlrcpp::downCast<FormatContext *>(_localctx)->type = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodecContext ------------------------------------------------------------------

FrameParser::CodecContext::CodecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::CodecContext::CODEC() {
  return getToken(FrameParser::CODEC, 0);
}

tree::TerminalNode* FrameParser::CodecContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::CodecContext::AUDIO_FORMAT() {
  return getToken(FrameParser::AUDIO_FORMAT, 0);
}

tree::TerminalNode* FrameParser::CodecContext::IMAGE_FORMAT() {
  return getToken(FrameParser::IMAGE_FORMAT, 0);
}

tree::TerminalNode* FrameParser::CodecContext::VIDEO_CODEC() {
  return getToken(FrameParser::VIDEO_CODEC, 0);
}


size_t FrameParser::CodecContext::getRuleIndex() const {
  return FrameParser::RuleCodec;
}


antlrcpp::Any FrameParser::CodecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitCodec(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::CodecContext* FrameParser::codec() {
  CodecContext *_localctx = _tracker.createInstance<CodecContext>(_ctx, getState());
  enterRule(_localctx, 22, FrameParser::RuleCodec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(FrameParser::CODEC);
    setState(218);
    match(FrameParser::COLON);
    setState(219);
    antlrcpp::downCast<CodecContext *>(_localctx)->type = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FrameParser::VIDEO_CODEC)
      | (1ULL << FrameParser::IMAGE_FORMAT)
      | (1ULL << FrameParser::AUDIO_FORMAT))) != 0))) {
      antlrcpp::downCast<CodecContext *>(_localctx)->type = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitrateContext ------------------------------------------------------------------

FrameParser::BitrateContext::BitrateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::BitrateContext::BITRATE() {
  return getToken(FrameParser::BITRATE, 0);
}

tree::TerminalNode* FrameParser::BitrateContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::BitrateContext::INT() {
  return getToken(FrameParser::INT, 0);
}


size_t FrameParser::BitrateContext::getRuleIndex() const {
  return FrameParser::RuleBitrate;
}


antlrcpp::Any FrameParser::BitrateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitBitrate(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::BitrateContext* FrameParser::bitrate() {
  BitrateContext *_localctx = _tracker.createInstance<BitrateContext>(_ctx, getState());
  enterRule(_localctx, 24, FrameParser::RuleBitrate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(FrameParser::BITRATE);
    setState(222);
    match(FrameParser::COLON);
    setState(223);
    match(FrameParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sample_rateContext ------------------------------------------------------------------

FrameParser::Sample_rateContext::Sample_rateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::Sample_rateContext::SAMPLE_RATE() {
  return getToken(FrameParser::SAMPLE_RATE, 0);
}

tree::TerminalNode* FrameParser::Sample_rateContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::Sample_rateContext::INT() {
  return getToken(FrameParser::INT, 0);
}


size_t FrameParser::Sample_rateContext::getRuleIndex() const {
  return FrameParser::RuleSample_rate;
}


antlrcpp::Any FrameParser::Sample_rateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSample_rate(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::Sample_rateContext* FrameParser::sample_rate() {
  Sample_rateContext *_localctx = _tracker.createInstance<Sample_rateContext>(_ctx, getState());
  enterRule(_localctx, 26, FrameParser::RuleSample_rate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(FrameParser::SAMPLE_RATE);
    setState(226);
    match(FrameParser::COLON);
    setState(227);
    match(FrameParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PitchContext ------------------------------------------------------------------

FrameParser::PitchContext::PitchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::PitchContext::PITCH() {
  return getToken(FrameParser::PITCH, 0);
}

tree::TerminalNode* FrameParser::PitchContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::PitchContext::INT() {
  return getToken(FrameParser::INT, 0);
}


size_t FrameParser::PitchContext::getRuleIndex() const {
  return FrameParser::RulePitch;
}


antlrcpp::Any FrameParser::PitchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitPitch(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::PitchContext* FrameParser::pitch() {
  PitchContext *_localctx = _tracker.createInstance<PitchContext>(_ctx, getState());
  enterRule(_localctx, 28, FrameParser::RulePitch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(FrameParser::PITCH);
    setState(230);
    match(FrameParser::COLON);
    setState(231);
    match(FrameParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TempoContext ------------------------------------------------------------------

FrameParser::TempoContext::TempoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::TempoContext::TEMPO() {
  return getToken(FrameParser::TEMPO, 0);
}

tree::TerminalNode* FrameParser::TempoContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::TempoContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}


size_t FrameParser::TempoContext::getRuleIndex() const {
  return FrameParser::RuleTempo;
}


antlrcpp::Any FrameParser::TempoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitTempo(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::TempoContext* FrameParser::tempo() {
  TempoContext *_localctx = _tracker.createInstance<TempoContext>(_ctx, getState());
  enterRule(_localctx, 30, FrameParser::RuleTempo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(FrameParser::TEMPO);
    setState(234);
    match(FrameParser::COLON);
    setState(235);
    match(FrameParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResolutionContext ------------------------------------------------------------------

FrameParser::ResolutionContext::ResolutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::ResolutionContext::RESOLUTION() {
  return getToken(FrameParser::RESOLUTION, 0);
}

tree::TerminalNode* FrameParser::ResolutionContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ResolutionContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::ResolutionContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}


size_t FrameParser::ResolutionContext::getRuleIndex() const {
  return FrameParser::RuleResolution;
}


antlrcpp::Any FrameParser::ResolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitResolution(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::ResolutionContext* FrameParser::resolution() {
  ResolutionContext *_localctx = _tracker.createInstance<ResolutionContext>(_ctx, getState());
  enterRule(_localctx, 32, FrameParser::RuleResolution);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(FrameParser::RESOLUTION);
    setState(238);
    match(FrameParser::COLON);
    setState(239);
    match(FrameParser::INT);
    setState(240);
    match(FrameParser::T__0);
    setState(241);
    match(FrameParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FramerateContext ------------------------------------------------------------------

FrameParser::FramerateContext::FramerateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FrameParser::FramerateContext::FRAME_RATE() {
  return getToken(FrameParser::FRAME_RATE, 0);
}

tree::TerminalNode* FrameParser::FramerateContext::COLON() {
  return getToken(FrameParser::COLON, 0);
}

tree::TerminalNode* FrameParser::FramerateContext::INT() {
  return getToken(FrameParser::INT, 0);
}


size_t FrameParser::FramerateContext::getRuleIndex() const {
  return FrameParser::RuleFramerate;
}


antlrcpp::Any FrameParser::FramerateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitFramerate(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::FramerateContext* FrameParser::framerate() {
  FramerateContext *_localctx = _tracker.createInstance<FramerateContext>(_ctx, getState());
  enterRule(_localctx, 34, FrameParser::RuleFramerate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(FrameParser::FRAME_RATE);
    setState(244);
    match(FrameParser::COLON);
    setState(245);
    match(FrameParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionContext ------------------------------------------------------------------

FrameParser::ActionContext::ActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FrameParser::Trim_actionContext* FrameParser::ActionContext::trim_action() {
  return getRuleContext<FrameParser::Trim_actionContext>(0);
}

FrameParser::Crop_actionContext* FrameParser::ActionContext::crop_action() {
  return getRuleContext<FrameParser::Crop_actionContext>(0);
}

FrameParser::Overlay_actionContext* FrameParser::ActionContext::overlay_action() {
  return getRuleContext<FrameParser::Overlay_actionContext>(0);
}

FrameParser::Extract_audio_from_video_actionContext* FrameParser::ActionContext::extract_audio_from_video_action() {
  return getRuleContext<FrameParser::Extract_audio_from_video_actionContext>(0);
}

FrameParser::Extract_frames_from_video_actionContext* FrameParser::ActionContext::extract_frames_from_video_action() {
  return getRuleContext<FrameParser::Extract_frames_from_video_actionContext>(0);
}

FrameParser::Merge_audio_with_video_actionContext* FrameParser::ActionContext::merge_audio_with_video_action() {
  return getRuleContext<FrameParser::Merge_audio_with_video_actionContext>(0);
}

FrameParser::Concatentation_actionContext* FrameParser::ActionContext::concatentation_action() {
  return getRuleContext<FrameParser::Concatentation_actionContext>(0);
}

FrameParser::Rotate_actionContext* FrameParser::ActionContext::rotate_action() {
  return getRuleContext<FrameParser::Rotate_actionContext>(0);
}

FrameParser::Flip_actionContext* FrameParser::ActionContext::flip_action() {
  return getRuleContext<FrameParser::Flip_actionContext>(0);
}

FrameParser::Saturation_actionContext* FrameParser::ActionContext::saturation_action() {
  return getRuleContext<FrameParser::Saturation_actionContext>(0);
}

FrameParser::Frame_rate_actionContext* FrameParser::ActionContext::frame_rate_action() {
  return getRuleContext<FrameParser::Frame_rate_actionContext>(0);
}

FrameParser::Gamma_actionContext* FrameParser::ActionContext::gamma_action() {
  return getRuleContext<FrameParser::Gamma_actionContext>(0);
}

FrameParser::Brightness_actionContext* FrameParser::ActionContext::brightness_action() {
  return getRuleContext<FrameParser::Brightness_actionContext>(0);
}

FrameParser::Contrast_actionContext* FrameParser::ActionContext::contrast_action() {
  return getRuleContext<FrameParser::Contrast_actionContext>(0);
}

FrameParser::Volume_actionContext* FrameParser::ActionContext::volume_action() {
  return getRuleContext<FrameParser::Volume_actionContext>(0);
}

FrameParser::Scale_actionContext* FrameParser::ActionContext::scale_action() {
  return getRuleContext<FrameParser::Scale_actionContext>(0);
}

FrameParser::Extract_N_subtitles_from_videoContext* FrameParser::ActionContext::extract_N_subtitles_from_video() {
  return getRuleContext<FrameParser::Extract_N_subtitles_from_videoContext>(0);
}

FrameParser::Extract_Kth_subtitle_from_videoContext* FrameParser::ActionContext::extract_Kth_subtitle_from_video() {
  return getRuleContext<FrameParser::Extract_Kth_subtitle_from_videoContext>(0);
}

FrameParser::Add_subtitles_to_videoContext* FrameParser::ActionContext::add_subtitles_to_video() {
  return getRuleContext<FrameParser::Add_subtitles_to_videoContext>(0);
}

FrameParser::Sharpen_actionContext* FrameParser::ActionContext::sharpen_action() {
  return getRuleContext<FrameParser::Sharpen_actionContext>(0);
}

FrameParser::Blur_actionContext* FrameParser::ActionContext::blur_action() {
  return getRuleContext<FrameParser::Blur_actionContext>(0);
}

FrameParser::Convert_actionContext* FrameParser::ActionContext::convert_action() {
  return getRuleContext<FrameParser::Convert_actionContext>(0);
}

FrameParser::Noise_reduction_actionContext* FrameParser::ActionContext::noise_reduction_action() {
  return getRuleContext<FrameParser::Noise_reduction_actionContext>(0);
}

FrameParser::Normalize_actionContext* FrameParser::ActionContext::normalize_action() {
  return getRuleContext<FrameParser::Normalize_actionContext>(0);
}

FrameParser::Bass_actionContext* FrameParser::ActionContext::bass_action() {
  return getRuleContext<FrameParser::Bass_actionContext>(0);
}

FrameParser::Treble_actionContext* FrameParser::ActionContext::treble_action() {
  return getRuleContext<FrameParser::Treble_actionContext>(0);
}

FrameParser::Abitscope_actionContext* FrameParser::ActionContext::abitscope_action() {
  return getRuleContext<FrameParser::Abitscope_actionContext>(0);
}

FrameParser::Ahistogram_actionContext* FrameParser::ActionContext::ahistogram_action() {
  return getRuleContext<FrameParser::Ahistogram_actionContext>(0);
}

FrameParser::Aphasemeter_actionContext* FrameParser::ActionContext::aphasemeter_action() {
  return getRuleContext<FrameParser::Aphasemeter_actionContext>(0);
}

FrameParser::Avectorscope_actionContext* FrameParser::ActionContext::avectorscope_action() {
  return getRuleContext<FrameParser::Avectorscope_actionContext>(0);
}

FrameParser::Showcqt_actionContext* FrameParser::ActionContext::showcqt_action() {
  return getRuleContext<FrameParser::Showcqt_actionContext>(0);
}

FrameParser::Showfreqs_actionContext* FrameParser::ActionContext::showfreqs_action() {
  return getRuleContext<FrameParser::Showfreqs_actionContext>(0);
}

FrameParser::Showspatial_actionContext* FrameParser::ActionContext::showspatial_action() {
  return getRuleContext<FrameParser::Showspatial_actionContext>(0);
}

FrameParser::Showspectrum_actionContext* FrameParser::ActionContext::showspectrum_action() {
  return getRuleContext<FrameParser::Showspectrum_actionContext>(0);
}

FrameParser::Showvolume_actionContext* FrameParser::ActionContext::showvolume_action() {
  return getRuleContext<FrameParser::Showvolume_actionContext>(0);
}

FrameParser::Super2xsai_actionContext* FrameParser::ActionContext::super2xsai_action() {
  return getRuleContext<FrameParser::Super2xsai_actionContext>(0);
}

FrameParser::Sobel_actionContext* FrameParser::ActionContext::sobel_action() {
  return getRuleContext<FrameParser::Sobel_actionContext>(0);
}

FrameParser::Tmix_actionContext* FrameParser::ActionContext::tmix_action() {
  return getRuleContext<FrameParser::Tmix_actionContext>(0);
}

FrameParser::Embedding_subtitles_actionContext* FrameParser::ActionContext::embedding_subtitles_action() {
  return getRuleContext<FrameParser::Embedding_subtitles_actionContext>(0);
}


size_t FrameParser::ActionContext::getRuleIndex() const {
  return FrameParser::RuleAction;
}


antlrcpp::Any FrameParser::ActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitAction(this);
  else
    return visitor->visitChildren(this);
}

FrameParser::ActionContext* FrameParser::action() {
  ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, getState());
  enterRule(_localctx, 36, FrameParser::RuleAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(247);
      trim_action();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(248);
      crop_action();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(249);
      overlay_action();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(250);
      extract_audio_from_video_action();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(251);
      extract_frames_from_video_action();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(252);
      merge_audio_with_video_action();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(253);
      concatentation_action();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(254);
      rotate_action();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(255);
      flip_action();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(256);
      saturation_action();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(257);
      frame_rate_action();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(258);
      gamma_action();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(259);
      brightness_action();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(260);
      contrast_action();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(261);
      volume_action();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(262);
      scale_action();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(263);
      extract_N_subtitles_from_video();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(264);
      extract_Kth_subtitle_from_video();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(265);
      add_subtitles_to_video();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(266);
      sharpen_action();
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(267);
      blur_action();
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(268);
      convert_action();
      break;
    }

    case 23: {
      enterOuterAlt(_localctx, 23);
      setState(269);
      noise_reduction_action();
      break;
    }

    case 24: {
      enterOuterAlt(_localctx, 24);
      setState(270);
      normalize_action();
      break;
    }

    case 25: {
      enterOuterAlt(_localctx, 25);
      setState(271);
      bass_action();
      break;
    }

    case 26: {
      enterOuterAlt(_localctx, 26);
      setState(272);
      treble_action();
      break;
    }

    case 27: {
      enterOuterAlt(_localctx, 27);
      setState(273);
      abitscope_action();
      break;
    }

    case 28: {
      enterOuterAlt(_localctx, 28);
      setState(274);
      ahistogram_action();
      break;
    }

    case 29: {
      enterOuterAlt(_localctx, 29);
      setState(275);
      aphasemeter_action();
      break;
    }

    case 30: {
      enterOuterAlt(_localctx, 30);
      setState(276);
      avectorscope_action();
      break;
    }

    case 31: {
      enterOuterAlt(_localctx, 31);
      setState(277);
      showcqt_action();
      break;
    }

    case 32: {
      enterOuterAlt(_localctx, 32);
      setState(278);
      showfreqs_action();
      break;
    }

    case 33: {
      enterOuterAlt(_localctx, 33);
      setState(279);
      showspatial_action();
      break;
    }

    case 34: {
      enterOuterAlt(_localctx, 34);
      setState(280);
      showspectrum_action();
      break;
    }

    case 35: {
      enterOuterAlt(_localctx, 35);
      setState(281);
      showvolume_action();
      break;
    }

    case 36: {
      enterOuterAlt(_localctx, 36);
      setState(282);
      super2xsai_action();
      break;
    }

    case 37: {
      enterOuterAlt(_localctx, 37);
      setState(283);
      sobel_action();
      break;
    }

    case 38: {
      enterOuterAlt(_localctx, 38);
      setState(284);
      tmix_action();
      break;
    }

    case 39: {
      enterOuterAlt(_localctx, 39);
      setState(285);
      embedding_subtitles_action();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Trim_actionContext ------------------------------------------------------------------

FrameParser::Trim_actionContext::Trim_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Trim_actionContext::getRuleIndex() const {
  return FrameParser::RuleTrim_action;
}

void FrameParser::Trim_actionContext::copyFrom(Trim_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TrimmingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::TrimmingContext::TRIM() {
  return getToken(FrameParser::TRIM, 0);
}

std::vector<tree::TerminalNode *> FrameParser::TrimmingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::TrimmingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::TrimmingContext::FROM() {
  return getToken(FrameParser::FROM, 0);
}

std::vector<tree::TerminalNode *> FrameParser::TrimmingContext::TIME() {
  return getTokens(FrameParser::TIME);
}

tree::TerminalNode* FrameParser::TrimmingContext::TIME(size_t i) {
  return getToken(FrameParser::TIME, i);
}

tree::TerminalNode* FrameParser::TrimmingContext::TO() {
  return getToken(FrameParser::TO, 0);
}

tree::TerminalNode* FrameParser::TrimmingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::TrimmingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::TrimmingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::TrimmingContext::TrimmingContext(Trim_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::TrimmingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitTrimming(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Trim_actionContext* FrameParser::trim_action() {
  Trim_actionContext *_localctx = _tracker.createInstance<Trim_actionContext>(_ctx, getState());
  enterRule(_localctx, 38, FrameParser::RuleTrim_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::TrimmingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(FrameParser::TRIM);
    setState(289);
    match(FrameParser::NAME);
    setState(290);
    match(FrameParser::FROM);
    setState(291);
    match(FrameParser::TIME);
    setState(292);
    match(FrameParser::TO);
    setState(293);
    match(FrameParser::TIME);
    setState(296);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(294);
      match(FrameParser::AS);
      setState(295);
      match(FrameParser::NAME);
    }
    setState(300);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(298);
      match(FrameParser::SAVE_TO);
      setState(299);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Crop_actionContext ------------------------------------------------------------------

FrameParser::Crop_actionContext::Crop_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Crop_actionContext::getRuleIndex() const {
  return FrameParser::RuleCrop_action;
}

void FrameParser::Crop_actionContext::copyFrom(Crop_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CroppingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::CroppingContext::CROP() {
  return getToken(FrameParser::CROP, 0);
}

std::vector<tree::TerminalNode *> FrameParser::CroppingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::CroppingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::CroppingContext::WIDTH() {
  return getToken(FrameParser::WIDTH, 0);
}

std::vector<tree::TerminalNode *> FrameParser::CroppingContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::CroppingContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::CroppingContext::HEIGHT() {
  return getToken(FrameParser::HEIGHT, 0);
}

tree::TerminalNode* FrameParser::CroppingContext::AT() {
  return getToken(FrameParser::AT, 0);
}

tree::TerminalNode* FrameParser::CroppingContext::POSITION() {
  return getToken(FrameParser::POSITION, 0);
}

tree::TerminalNode* FrameParser::CroppingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::CroppingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::CroppingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::CroppingContext::CroppingContext(Crop_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::CroppingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitCropping(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Crop_actionContext* FrameParser::crop_action() {
  Crop_actionContext *_localctx = _tracker.createInstance<Crop_actionContext>(_ctx, getState());
  enterRule(_localctx, 40, FrameParser::RuleCrop_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::CroppingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(FrameParser::CROP);
    setState(303);
    match(FrameParser::NAME);

    setState(304);
    match(FrameParser::WIDTH);
    setState(305);
    match(FrameParser::INT);
    setState(306);
    match(FrameParser::HEIGHT);
    setState(307);
    match(FrameParser::INT);
    setState(313);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AT) {
      setState(309);
      match(FrameParser::AT);
      setState(310);
      match(FrameParser::POSITION);
      setState(311);
      match(FrameParser::INT);
      setState(312);
      match(FrameParser::INT);
    }
    setState(317);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(315);
      match(FrameParser::AS);
      setState(316);
      match(FrameParser::NAME);
    }
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(319);
      match(FrameParser::SAVE_TO);
      setState(320);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Overlay_actionContext ------------------------------------------------------------------

FrameParser::Overlay_actionContext::Overlay_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Overlay_actionContext::getRuleIndex() const {
  return FrameParser::RuleOverlay_action;
}

void FrameParser::Overlay_actionContext::copyFrom(Overlay_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OverlayingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::OverlayingContext::OVERLAY() {
  return getToken(FrameParser::OVERLAY, 0);
}

std::vector<tree::TerminalNode *> FrameParser::OverlayingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::OverlayingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::OverlayingContext::ON() {
  return getToken(FrameParser::ON, 0);
}

tree::TerminalNode* FrameParser::OverlayingContext::AT() {
  return getToken(FrameParser::AT, 0);
}

tree::TerminalNode* FrameParser::OverlayingContext::POSITION() {
  return getToken(FrameParser::POSITION, 0);
}

std::vector<tree::TerminalNode *> FrameParser::OverlayingContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::OverlayingContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

std::vector<tree::TerminalNode *> FrameParser::OverlayingContext::MINUS() {
  return getTokens(FrameParser::MINUS);
}

tree::TerminalNode* FrameParser::OverlayingContext::MINUS(size_t i) {
  return getToken(FrameParser::MINUS, i);
}

tree::TerminalNode* FrameParser::OverlayingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::OverlayingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::OverlayingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::OverlayingContext::OverlayingContext(Overlay_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::OverlayingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitOverlaying(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Overlay_actionContext* FrameParser::overlay_action() {
  Overlay_actionContext *_localctx = _tracker.createInstance<Overlay_actionContext>(_ctx, getState());
  enterRule(_localctx, 42, FrameParser::RuleOverlay_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::OverlayingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(323);
    match(FrameParser::OVERLAY);
    setState(324);
    match(FrameParser::NAME);
    setState(325);
    match(FrameParser::ON);
    setState(326);
    match(FrameParser::NAME);
    setState(327);
    match(FrameParser::AT);
    setState(328);
    match(FrameParser::POSITION);
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::MINUS) {
      setState(329);
      match(FrameParser::MINUS);
    }
    setState(332);
    match(FrameParser::INT);
    setState(334);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::MINUS) {
      setState(333);
      match(FrameParser::MINUS);
    }
    setState(336);
    match(FrameParser::INT);
    setState(339);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(337);
      match(FrameParser::AS);
      setState(338);
      match(FrameParser::NAME);
    }
    setState(343);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(341);
      match(FrameParser::SAVE_TO);
      setState(342);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extract_audio_from_video_actionContext ------------------------------------------------------------------

FrameParser::Extract_audio_from_video_actionContext::Extract_audio_from_video_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Extract_audio_from_video_actionContext::getRuleIndex() const {
  return FrameParser::RuleExtract_audio_from_video_action;
}

void FrameParser::Extract_audio_from_video_actionContext::copyFrom(Extract_audio_from_video_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExtractingAudioFromVideoContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::EXTRACT() {
  return getToken(FrameParser::EXTRACT, 0);
}

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::FROM() {
  return getToken(FrameParser::FROM, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ExtractingAudioFromVideoContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::FORMAT() {
  return getToken(FrameParser::FORMAT, 0);
}

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::AUDIO_FORMAT() {
  return getToken(FrameParser::AUDIO_FORMAT, 0);
}

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ExtractingAudioFromVideoContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ExtractingAudioFromVideoContext::ExtractingAudioFromVideoContext(Extract_audio_from_video_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ExtractingAudioFromVideoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitExtractingAudioFromVideo(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Extract_audio_from_video_actionContext* FrameParser::extract_audio_from_video_action() {
  Extract_audio_from_video_actionContext *_localctx = _tracker.createInstance<Extract_audio_from_video_actionContext>(_ctx, getState());
  enterRule(_localctx, 44, FrameParser::RuleExtract_audio_from_video_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ExtractingAudioFromVideoContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(345);
    match(FrameParser::EXTRACT);
    setState(346);
    match(FrameParser::T__1);
    setState(347);
    match(FrameParser::FROM);
    setState(348);
    match(FrameParser::NAME);
    setState(349);
    match(FrameParser::FORMAT);
    setState(350);
    match(FrameParser::AUDIO_FORMAT);
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(351);
      match(FrameParser::AS);
      setState(352);
      match(FrameParser::NAME);
    }
    setState(357);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(355);
      match(FrameParser::SAVE_TO);
      setState(356);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extract_frames_from_video_actionContext ------------------------------------------------------------------

FrameParser::Extract_frames_from_video_actionContext::Extract_frames_from_video_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Extract_frames_from_video_actionContext::getRuleIndex() const {
  return FrameParser::RuleExtract_frames_from_video_action;
}

void FrameParser::Extract_frames_from_video_actionContext::copyFrom(Extract_frames_from_video_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExtractingFramesFromVideoContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::EXTRACT() {
  return getToken(FrameParser::EXTRACT, 0);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::FROM() {
  return getToken(FrameParser::FROM, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ExtractingFramesFromVideoContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::FORMAT() {
  return getToken(FrameParser::FORMAT, 0);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::IMAGE_FORMAT() {
  return getToken(FrameParser::IMAGE_FORMAT, 0);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::RATIO() {
  return getToken(FrameParser::RATIO, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ExtractingFramesFromVideoContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ExtractingFramesFromVideoContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ExtractingFramesFromVideoContext::ExtractingFramesFromVideoContext(Extract_frames_from_video_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ExtractingFramesFromVideoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitExtractingFramesFromVideo(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Extract_frames_from_video_actionContext* FrameParser::extract_frames_from_video_action() {
  Extract_frames_from_video_actionContext *_localctx = _tracker.createInstance<Extract_frames_from_video_actionContext>(_ctx, getState());
  enterRule(_localctx, 46, FrameParser::RuleExtract_frames_from_video_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ExtractingFramesFromVideoContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(FrameParser::EXTRACT);
    setState(360);
    match(FrameParser::T__2);
    setState(361);
    match(FrameParser::FROM);
    setState(362);
    match(FrameParser::NAME);
    setState(363);
    match(FrameParser::FORMAT);
    setState(364);
    match(FrameParser::IMAGE_FORMAT);
    setState(368);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::RATIO) {
      setState(365);
      match(FrameParser::RATIO);
      setState(366);
      match(FrameParser::INT);
      setState(367);
      match(FrameParser::INT);
    }
    setState(372);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(370);
      match(FrameParser::AS);
      setState(371);
      match(FrameParser::NAME);
    }
    setState(376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(374);
      match(FrameParser::SAVE_TO);
      setState(375);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Merge_audio_with_video_actionContext ------------------------------------------------------------------

FrameParser::Merge_audio_with_video_actionContext::Merge_audio_with_video_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Merge_audio_with_video_actionContext::getRuleIndex() const {
  return FrameParser::RuleMerge_audio_with_video_action;
}

void FrameParser::Merge_audio_with_video_actionContext::copyFrom(Merge_audio_with_video_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MergingAudioWithVideoContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::MergingAudioWithVideoContext::MERGE() {
  return getToken(FrameParser::MERGE, 0);
}

std::vector<tree::TerminalNode *> FrameParser::MergingAudioWithVideoContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::MergingAudioWithVideoContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::MergingAudioWithVideoContext::WITH() {
  return getToken(FrameParser::WITH, 0);
}

tree::TerminalNode* FrameParser::MergingAudioWithVideoContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::MergingAudioWithVideoContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::MergingAudioWithVideoContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::MergingAudioWithVideoContext::MergingAudioWithVideoContext(Merge_audio_with_video_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::MergingAudioWithVideoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitMergingAudioWithVideo(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Merge_audio_with_video_actionContext* FrameParser::merge_audio_with_video_action() {
  Merge_audio_with_video_actionContext *_localctx = _tracker.createInstance<Merge_audio_with_video_actionContext>(_ctx, getState());
  enterRule(_localctx, 48, FrameParser::RuleMerge_audio_with_video_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::MergingAudioWithVideoContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(378);
    match(FrameParser::MERGE);
    setState(379);
    match(FrameParser::NAME);
    setState(380);
    match(FrameParser::WITH);
    setState(381);
    match(FrameParser::NAME);
    setState(384);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(382);
      match(FrameParser::AS);
      setState(383);
      match(FrameParser::NAME);
    }
    setState(388);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(386);
      match(FrameParser::SAVE_TO);
      setState(387);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concatentation_actionContext ------------------------------------------------------------------

FrameParser::Concatentation_actionContext::Concatentation_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Concatentation_actionContext::getRuleIndex() const {
  return FrameParser::RuleConcatentation_action;
}

void FrameParser::Concatentation_actionContext::copyFrom(Concatentation_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConcatentatingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ConcatentatingContext::CONCATENATE() {
  return getToken(FrameParser::CONCATENATE, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ConcatentatingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ConcatentatingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ConcatentatingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ConcatentatingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ConcatentatingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ConcatentatingContext::ConcatentatingContext(Concatentation_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ConcatentatingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitConcatentating(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Concatentation_actionContext* FrameParser::concatentation_action() {
  Concatentation_actionContext *_localctx = _tracker.createInstance<Concatentation_actionContext>(_ctx, getState());
  enterRule(_localctx, 50, FrameParser::RuleConcatentation_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ConcatentatingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(FrameParser::CONCATENATE);
    setState(392); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(391);
      match(FrameParser::NAME);
      setState(394); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FrameParser::NAME);
    setState(398);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(396);
      match(FrameParser::AS);
      setState(397);
      match(FrameParser::NAME);
    }
    setState(402);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(400);
      match(FrameParser::SAVE_TO);
      setState(401);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rotate_actionContext ------------------------------------------------------------------

FrameParser::Rotate_actionContext::Rotate_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Rotate_actionContext::getRuleIndex() const {
  return FrameParser::RuleRotate_action;
}

void FrameParser::Rotate_actionContext::copyFrom(Rotate_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RotatingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::RotatingContext::ROTATE() {
  return getToken(FrameParser::ROTATE, 0);
}

std::vector<tree::TerminalNode *> FrameParser::RotatingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::RotatingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::RotatingContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::RotatingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::RotatingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::RotatingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::RotatingContext::RotatingContext(Rotate_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::RotatingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitRotating(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Rotate_actionContext* FrameParser::rotate_action() {
  Rotate_actionContext *_localctx = _tracker.createInstance<Rotate_actionContext>(_ctx, getState());
  enterRule(_localctx, 52, FrameParser::RuleRotate_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::RotatingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(404);
    match(FrameParser::ROTATE);
    setState(405);
    match(FrameParser::NAME);
    setState(406);
    match(FrameParser::INT);
    setState(409);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(407);
      match(FrameParser::AS);
      setState(408);
      match(FrameParser::NAME);
    }
    setState(413);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(411);
      match(FrameParser::SAVE_TO);
      setState(412);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Flip_actionContext ------------------------------------------------------------------

FrameParser::Flip_actionContext::Flip_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Flip_actionContext::getRuleIndex() const {
  return FrameParser::RuleFlip_action;
}

void FrameParser::Flip_actionContext::copyFrom(Flip_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FlippingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::FlippingContext::FLIP() {
  return getToken(FrameParser::FLIP, 0);
}

std::vector<tree::TerminalNode *> FrameParser::FlippingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::FlippingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::FlippingContext::FLIP_VH() {
  return getToken(FrameParser::FLIP_VH, 0);
}

tree::TerminalNode* FrameParser::FlippingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::FlippingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::FlippingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::FlippingContext::FlippingContext(Flip_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::FlippingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitFlipping(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Flip_actionContext* FrameParser::flip_action() {
  Flip_actionContext *_localctx = _tracker.createInstance<Flip_actionContext>(_ctx, getState());
  enterRule(_localctx, 54, FrameParser::RuleFlip_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::FlippingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(415);
    match(FrameParser::FLIP);
    setState(416);
    match(FrameParser::NAME);
    setState(417);
    match(FrameParser::FLIP_VH);
    setState(420);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(418);
      match(FrameParser::AS);
      setState(419);
      match(FrameParser::NAME);
    }
    setState(424);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(422);
      match(FrameParser::SAVE_TO);
      setState(423);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Saturation_actionContext ------------------------------------------------------------------

FrameParser::Saturation_actionContext::Saturation_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Saturation_actionContext::getRuleIndex() const {
  return FrameParser::RuleSaturation_action;
}

void FrameParser::Saturation_actionContext::copyFrom(Saturation_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingSaturationContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingSaturationContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::SATURATION() {
  return getToken(FrameParser::SATURATION, 0);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingSaturationContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingSaturationContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::SettingSaturationContext::SettingSaturationContext(Saturation_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingSaturationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingSaturation(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Saturation_actionContext* FrameParser::saturation_action() {
  Saturation_actionContext *_localctx = _tracker.createInstance<Saturation_actionContext>(_ctx, getState());
  enterRule(_localctx, 56, FrameParser::RuleSaturation_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingSaturationContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(FrameParser::SET);
    setState(427);
    match(FrameParser::SATURATION);
    setState(428);
    match(FrameParser::FOR);
    setState(429);
    match(FrameParser::NAME);
    setState(430);
    antlrcpp::downCast<SettingSaturationContext *>(_localctx)->saturationValue = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::INT

    || _la == FrameParser::FLOAT)) {
      antlrcpp::downCast<SettingSaturationContext *>(_localctx)->saturationValue = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(433);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(431);
      match(FrameParser::AS);
      setState(432);
      match(FrameParser::NAME);
    }
    setState(437);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(435);
      match(FrameParser::SAVE_TO);
      setState(436);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Gamma_actionContext ------------------------------------------------------------------

FrameParser::Gamma_actionContext::Gamma_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Gamma_actionContext::getRuleIndex() const {
  return FrameParser::RuleGamma_action;
}

void FrameParser::Gamma_actionContext::copyFrom(Gamma_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingGammaContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingGammaContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingGammaContext::GAMMA() {
  return getToken(FrameParser::GAMMA, 0);
}

tree::TerminalNode* FrameParser::SettingGammaContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingGammaContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingGammaContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingGammaContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

tree::TerminalNode* FrameParser::SettingGammaContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::SettingGammaContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SettingGammaContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingGammaContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::SettingGammaContext::SettingGammaContext(Gamma_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingGammaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingGamma(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Gamma_actionContext* FrameParser::gamma_action() {
  Gamma_actionContext *_localctx = _tracker.createInstance<Gamma_actionContext>(_ctx, getState());
  enterRule(_localctx, 58, FrameParser::RuleGamma_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingGammaContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(439);
    match(FrameParser::SET);
    setState(440);
    match(FrameParser::GAMMA);
    setState(441);
    match(FrameParser::FOR);
    setState(442);
    match(FrameParser::NAME);
    setState(443);
    antlrcpp::downCast<SettingGammaContext *>(_localctx)->gammaValue = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::INT

    || _la == FrameParser::FLOAT)) {
      antlrcpp::downCast<SettingGammaContext *>(_localctx)->gammaValue = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(444);
      match(FrameParser::AS);
      setState(445);
      match(FrameParser::NAME);
    }
    setState(450);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(448);
      match(FrameParser::SAVE_TO);
      setState(449);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Brightness_actionContext ------------------------------------------------------------------

FrameParser::Brightness_actionContext::Brightness_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Brightness_actionContext::getRuleIndex() const {
  return FrameParser::RuleBrightness_action;
}

void FrameParser::Brightness_actionContext::copyFrom(Brightness_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingBrightnessContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingBrightnessContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::BRIGHTNESS() {
  return getToken(FrameParser::BRIGHTNESS, 0);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingBrightnessContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::MINUS() {
  return getToken(FrameParser::MINUS, 0);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingBrightnessContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::SettingBrightnessContext::SettingBrightnessContext(Brightness_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingBrightnessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingBrightness(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Brightness_actionContext* FrameParser::brightness_action() {
  Brightness_actionContext *_localctx = _tracker.createInstance<Brightness_actionContext>(_ctx, getState());
  enterRule(_localctx, 60, FrameParser::RuleBrightness_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingBrightnessContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(452);
    match(FrameParser::SET);
    setState(453);
    match(FrameParser::BRIGHTNESS);
    setState(454);
    match(FrameParser::FOR);
    setState(455);
    match(FrameParser::NAME);
    setState(457);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::MINUS) {
      setState(456);
      match(FrameParser::MINUS);
    }
    setState(459);
    antlrcpp::downCast<SettingBrightnessContext *>(_localctx)->brightnessValue = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::INT

    || _la == FrameParser::FLOAT)) {
      antlrcpp::downCast<SettingBrightnessContext *>(_localctx)->brightnessValue = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(462);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(460);
      match(FrameParser::AS);
      setState(461);
      match(FrameParser::NAME);
    }
    setState(466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(464);
      match(FrameParser::SAVE_TO);
      setState(465);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Contrast_actionContext ------------------------------------------------------------------

FrameParser::Contrast_actionContext::Contrast_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Contrast_actionContext::getRuleIndex() const {
  return FrameParser::RuleContrast_action;
}

void FrameParser::Contrast_actionContext::copyFrom(Contrast_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingContrastContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingContrastContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingContrastContext::CONTRAST() {
  return getToken(FrameParser::CONTRAST, 0);
}

tree::TerminalNode* FrameParser::SettingContrastContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingContrastContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingContrastContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingContrastContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

tree::TerminalNode* FrameParser::SettingContrastContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::SettingContrastContext::MINUS() {
  return getToken(FrameParser::MINUS, 0);
}

tree::TerminalNode* FrameParser::SettingContrastContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SettingContrastContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingContrastContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::SettingContrastContext::SettingContrastContext(Contrast_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingContrastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingContrast(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Contrast_actionContext* FrameParser::contrast_action() {
  Contrast_actionContext *_localctx = _tracker.createInstance<Contrast_actionContext>(_ctx, getState());
  enterRule(_localctx, 62, FrameParser::RuleContrast_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingContrastContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(468);
    match(FrameParser::SET);
    setState(469);
    match(FrameParser::CONTRAST);
    setState(470);
    match(FrameParser::FOR);
    setState(471);
    match(FrameParser::NAME);
    setState(473);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::MINUS) {
      setState(472);
      match(FrameParser::MINUS);
    }
    setState(475);
    antlrcpp::downCast<SettingContrastContext *>(_localctx)->contrastValue = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::INT

    || _la == FrameParser::FLOAT)) {
      antlrcpp::downCast<SettingContrastContext *>(_localctx)->contrastValue = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(478);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(476);
      match(FrameParser::AS);
      setState(477);
      match(FrameParser::NAME);
    }
    setState(482);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(480);
      match(FrameParser::SAVE_TO);
      setState(481);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Frame_rate_actionContext ------------------------------------------------------------------

FrameParser::Frame_rate_actionContext::Frame_rate_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Frame_rate_actionContext::getRuleIndex() const {
  return FrameParser::RuleFrame_rate_action;
}

void FrameParser::Frame_rate_actionContext::copyFrom(Frame_rate_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingFramerateContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingFramerateContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingFramerateContext::FRAME_RATE() {
  return getToken(FrameParser::FRAME_RATE, 0);
}

tree::TerminalNode* FrameParser::SettingFramerateContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingFramerateContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingFramerateContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingFramerateContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::SettingFramerateContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SettingFramerateContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingFramerateContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::SettingFramerateContext::SettingFramerateContext(Frame_rate_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingFramerateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingFramerate(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Frame_rate_actionContext* FrameParser::frame_rate_action() {
  Frame_rate_actionContext *_localctx = _tracker.createInstance<Frame_rate_actionContext>(_ctx, getState());
  enterRule(_localctx, 64, FrameParser::RuleFrame_rate_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingFramerateContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(FrameParser::SET);
    setState(485);
    match(FrameParser::FRAME_RATE);
    setState(486);
    match(FrameParser::FOR);
    setState(487);
    match(FrameParser::NAME);
    setState(488);
    match(FrameParser::INT);
    setState(491);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(489);
      match(FrameParser::AS);
      setState(490);
      match(FrameParser::NAME);
    }
    setState(495);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(493);
      match(FrameParser::SAVE_TO);
      setState(494);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Volume_actionContext ------------------------------------------------------------------

FrameParser::Volume_actionContext::Volume_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Volume_actionContext::getRuleIndex() const {
  return FrameParser::RuleVolume_action;
}

void FrameParser::Volume_actionContext::copyFrom(Volume_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingVolumeContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingVolumeContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingVolumeContext::VOLUME() {
  return getToken(FrameParser::VOLUME, 0);
}

tree::TerminalNode* FrameParser::SettingVolumeContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingVolumeContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingVolumeContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingVolumeContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::SettingVolumeContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SettingVolumeContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingVolumeContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::SettingVolumeContext::SettingVolumeContext(Volume_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingVolumeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingVolume(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Volume_actionContext* FrameParser::volume_action() {
  Volume_actionContext *_localctx = _tracker.createInstance<Volume_actionContext>(_ctx, getState());
  enterRule(_localctx, 66, FrameParser::RuleVolume_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingVolumeContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(497);
    match(FrameParser::SET);
    setState(498);
    match(FrameParser::VOLUME);
    setState(499);
    match(FrameParser::FOR);
    setState(500);
    match(FrameParser::NAME);

    setState(501);
    match(FrameParser::INT);
    setState(504);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(502);
      match(FrameParser::AS);
      setState(503);
      match(FrameParser::NAME);
    }
    setState(508);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(506);
      match(FrameParser::SAVE_TO);
      setState(507);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scale_actionContext ------------------------------------------------------------------

FrameParser::Scale_actionContext::Scale_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Scale_actionContext::getRuleIndex() const {
  return FrameParser::RuleScale_action;
}

void FrameParser::Scale_actionContext::copyFrom(Scale_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ScalingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ScalingContext::SCALE() {
  return getToken(FrameParser::SCALE, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ScalingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ScalingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ScalingContext::WIDTH() {
  return getToken(FrameParser::WIDTH, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ScalingContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::ScalingContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::ScalingContext::HEIGHT() {
  return getToken(FrameParser::HEIGHT, 0);
}

tree::TerminalNode* FrameParser::ScalingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ScalingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ScalingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ScalingContext::ScalingContext(Scale_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ScalingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitScaling(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Scale_actionContext* FrameParser::scale_action() {
  Scale_actionContext *_localctx = _tracker.createInstance<Scale_actionContext>(_ctx, getState());
  enterRule(_localctx, 68, FrameParser::RuleScale_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ScalingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(510);
    match(FrameParser::SCALE);
    setState(511);
    match(FrameParser::NAME);

    setState(512);
    match(FrameParser::WIDTH);
    setState(513);
    match(FrameParser::INT);
    setState(514);
    match(FrameParser::HEIGHT);
    setState(515);
    match(FrameParser::INT);
    setState(519);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(517);
      match(FrameParser::AS);
      setState(518);
      match(FrameParser::NAME);
    }
    setState(523);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(521);
      match(FrameParser::SAVE_TO);
      setState(522);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extract_N_subtitles_from_videoContext ------------------------------------------------------------------

FrameParser::Extract_N_subtitles_from_videoContext::Extract_N_subtitles_from_videoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Extract_N_subtitles_from_videoContext::getRuleIndex() const {
  return FrameParser::RuleExtract_N_subtitles_from_video;
}

void FrameParser::Extract_N_subtitles_from_videoContext::copyFrom(Extract_N_subtitles_from_videoContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExtractingNSubtitlesFromVideoContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ExtractingNSubtitlesFromVideoContext::EXTRACT() {
  return getToken(FrameParser::EXTRACT, 0);
}

tree::TerminalNode* FrameParser::ExtractingNSubtitlesFromVideoContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::ExtractingNSubtitlesFromVideoContext::SUBTITLES() {
  return getToken(FrameParser::SUBTITLES, 0);
}

tree::TerminalNode* FrameParser::ExtractingNSubtitlesFromVideoContext::FROM() {
  return getToken(FrameParser::FROM, 0);
}

tree::TerminalNode* FrameParser::ExtractingNSubtitlesFromVideoContext::NAME() {
  return getToken(FrameParser::NAME, 0);
}

tree::TerminalNode* FrameParser::ExtractingNSubtitlesFromVideoContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ExtractingNSubtitlesFromVideoContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ExtractingNSubtitlesFromVideoContext::ExtractingNSubtitlesFromVideoContext(Extract_N_subtitles_from_videoContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ExtractingNSubtitlesFromVideoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitExtractingNSubtitlesFromVideo(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Extract_N_subtitles_from_videoContext* FrameParser::extract_N_subtitles_from_video() {
  Extract_N_subtitles_from_videoContext *_localctx = _tracker.createInstance<Extract_N_subtitles_from_videoContext>(_ctx, getState());
  enterRule(_localctx, 70, FrameParser::RuleExtract_N_subtitles_from_video);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ExtractingNSubtitlesFromVideoContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(525);
    match(FrameParser::EXTRACT);
    setState(526);
    match(FrameParser::INT);
    setState(527);
    match(FrameParser::SUBTITLES);
    setState(528);
    match(FrameParser::FROM);
    setState(529);
    match(FrameParser::NAME);
    setState(530);
    match(FrameParser::SAVE_TO);
    setState(531);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extract_Kth_subtitle_from_videoContext ------------------------------------------------------------------

FrameParser::Extract_Kth_subtitle_from_videoContext::Extract_Kth_subtitle_from_videoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Extract_Kth_subtitle_from_videoContext::getRuleIndex() const {
  return FrameParser::RuleExtract_Kth_subtitle_from_video;
}

void FrameParser::Extract_Kth_subtitle_from_videoContext::copyFrom(Extract_Kth_subtitle_from_videoContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExtractingKthSubtitleFromVideoContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::EXTRACT() {
  return getToken(FrameParser::EXTRACT, 0);
}

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::SUBTITLE() {
  return getToken(FrameParser::SUBTITLE, 0);
}

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::NUMBER() {
  return getToken(FrameParser::NUMBER, 0);
}

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::FROM() {
  return getToken(FrameParser::FROM, 0);
}

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::NAME() {
  return getToken(FrameParser::NAME, 0);
}

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ExtractingKthSubtitleFromVideoContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ExtractingKthSubtitleFromVideoContext::ExtractingKthSubtitleFromVideoContext(Extract_Kth_subtitle_from_videoContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ExtractingKthSubtitleFromVideoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitExtractingKthSubtitleFromVideo(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Extract_Kth_subtitle_from_videoContext* FrameParser::extract_Kth_subtitle_from_video() {
  Extract_Kth_subtitle_from_videoContext *_localctx = _tracker.createInstance<Extract_Kth_subtitle_from_videoContext>(_ctx, getState());
  enterRule(_localctx, 72, FrameParser::RuleExtract_Kth_subtitle_from_video);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ExtractingKthSubtitleFromVideoContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(533);
    match(FrameParser::EXTRACT);
    setState(534);
    match(FrameParser::SUBTITLE);
    setState(535);
    match(FrameParser::NUMBER);
    setState(536);
    match(FrameParser::INT);
    setState(537);
    match(FrameParser::FROM);
    setState(538);
    match(FrameParser::NAME);
    setState(539);
    match(FrameParser::SAVE_TO);
    setState(540);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Add_subtitles_to_videoContext ------------------------------------------------------------------

FrameParser::Add_subtitles_to_videoContext::Add_subtitles_to_videoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Add_subtitles_to_videoContext::getRuleIndex() const {
  return FrameParser::RuleAdd_subtitles_to_video;
}

void FrameParser::Add_subtitles_to_videoContext::copyFrom(Add_subtitles_to_videoContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AddingSubtitlesToVideoContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::AddingSubtitlesToVideoContext::ADD() {
  return getToken(FrameParser::ADD, 0);
}

tree::TerminalNode* FrameParser::AddingSubtitlesToVideoContext::SUBTITLES() {
  return getToken(FrameParser::SUBTITLES, 0);
}

std::vector<tree::TerminalNode *> FrameParser::AddingSubtitlesToVideoContext::STRING() {
  return getTokens(FrameParser::STRING);
}

tree::TerminalNode* FrameParser::AddingSubtitlesToVideoContext::STRING(size_t i) {
  return getToken(FrameParser::STRING, i);
}

tree::TerminalNode* FrameParser::AddingSubtitlesToVideoContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::AddingSubtitlesToVideoContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::AddingSubtitlesToVideoContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::AddingSubtitlesToVideoContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::AddingSubtitlesToVideoContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

FrameParser::AddingSubtitlesToVideoContext::AddingSubtitlesToVideoContext(Add_subtitles_to_videoContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::AddingSubtitlesToVideoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitAddingSubtitlesToVideo(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Add_subtitles_to_videoContext* FrameParser::add_subtitles_to_video() {
  Add_subtitles_to_videoContext *_localctx = _tracker.createInstance<Add_subtitles_to_videoContext>(_ctx, getState());
  enterRule(_localctx, 74, FrameParser::RuleAdd_subtitles_to_video);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::AddingSubtitlesToVideoContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(542);
    match(FrameParser::ADD);
    setState(543);
    match(FrameParser::SUBTITLES);
    setState(544);
    match(FrameParser::STRING);
    setState(545);
    match(FrameParser::FOR);
    setState(546);
    match(FrameParser::NAME);
    setState(549);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(547);
      match(FrameParser::AS);
      setState(548);
      match(FrameParser::NAME);
    }
    setState(553);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(551);
      match(FrameParser::SAVE_TO);
      setState(552);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sharpen_actionContext ------------------------------------------------------------------

FrameParser::Sharpen_actionContext::Sharpen_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Sharpen_actionContext::getRuleIndex() const {
  return FrameParser::RuleSharpen_action;
}

void FrameParser::Sharpen_actionContext::copyFrom(Sharpen_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SharpeningContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SharpeningContext::SHARPEN() {
  return getToken(FrameParser::SHARPEN, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SharpeningContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SharpeningContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SharpeningContext::WIDTH() {
  return getToken(FrameParser::WIDTH, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SharpeningContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::SharpeningContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::SharpeningContext::HEIGHT() {
  return getToken(FrameParser::HEIGHT, 0);
}

tree::TerminalNode* FrameParser::SharpeningContext::INTENSITY() {
  return getToken(FrameParser::INTENSITY, 0);
}

tree::TerminalNode* FrameParser::SharpeningContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SharpeningContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SharpeningContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

tree::TerminalNode* FrameParser::SharpeningContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

FrameParser::SharpeningContext::SharpeningContext(Sharpen_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SharpeningContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSharpening(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Sharpen_actionContext* FrameParser::sharpen_action() {
  Sharpen_actionContext *_localctx = _tracker.createInstance<Sharpen_actionContext>(_ctx, getState());
  enterRule(_localctx, 76, FrameParser::RuleSharpen_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SharpeningContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(555);
    match(FrameParser::SHARPEN);
    setState(556);
    match(FrameParser::NAME);
    setState(561);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::WIDTH) {
      setState(557);
      match(FrameParser::WIDTH);
      setState(558);
      match(FrameParser::INT);
      setState(559);
      match(FrameParser::HEIGHT);
      setState(560);
      match(FrameParser::INT);
    }
    setState(565);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::INTENSITY) {
      setState(563);
      match(FrameParser::INTENSITY);
      setState(564);
      antlrcpp::downCast<SharpeningContext *>(_localctx)->effectAmount = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<SharpeningContext *>(_localctx)->effectAmount = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(569);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(567);
      match(FrameParser::AS);
      setState(568);
      match(FrameParser::NAME);
    }
    setState(573);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(571);
      match(FrameParser::SAVE_TO);
      setState(572);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Blur_actionContext ------------------------------------------------------------------

FrameParser::Blur_actionContext::Blur_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Blur_actionContext::getRuleIndex() const {
  return FrameParser::RuleBlur_action;
}

void FrameParser::Blur_actionContext::copyFrom(Blur_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlurringContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::BlurringContext::BLUR() {
  return getToken(FrameParser::BLUR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::BlurringContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::BlurringContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::BlurringContext::WIDTH() {
  return getToken(FrameParser::WIDTH, 0);
}

std::vector<tree::TerminalNode *> FrameParser::BlurringContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::BlurringContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::BlurringContext::HEIGHT() {
  return getToken(FrameParser::HEIGHT, 0);
}

tree::TerminalNode* FrameParser::BlurringContext::INTENSITY() {
  return getToken(FrameParser::INTENSITY, 0);
}

tree::TerminalNode* FrameParser::BlurringContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::BlurringContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::BlurringContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

tree::TerminalNode* FrameParser::BlurringContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

FrameParser::BlurringContext::BlurringContext(Blur_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::BlurringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitBlurring(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Blur_actionContext* FrameParser::blur_action() {
  Blur_actionContext *_localctx = _tracker.createInstance<Blur_actionContext>(_ctx, getState());
  enterRule(_localctx, 78, FrameParser::RuleBlur_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::BlurringContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(575);
    match(FrameParser::BLUR);
    setState(576);
    match(FrameParser::NAME);
    setState(581);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::WIDTH) {
      setState(577);
      match(FrameParser::WIDTH);
      setState(578);
      match(FrameParser::INT);
      setState(579);
      match(FrameParser::HEIGHT);
      setState(580);
      match(FrameParser::INT);
    }
    setState(585);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::INTENSITY) {
      setState(583);
      match(FrameParser::INTENSITY);
      setState(584);
      antlrcpp::downCast<BlurringContext *>(_localctx)->effectAmount = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<BlurringContext *>(_localctx)->effectAmount = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(589);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(587);
      match(FrameParser::AS);
      setState(588);
      match(FrameParser::NAME);
    }
    setState(593);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(591);
      match(FrameParser::SAVE_TO);
      setState(592);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Convert_actionContext ------------------------------------------------------------------

FrameParser::Convert_actionContext::Convert_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Convert_actionContext::getRuleIndex() const {
  return FrameParser::RuleConvert_action;
}

void FrameParser::Convert_actionContext::copyFrom(Convert_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConvertingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ConvertingContext::CONVERT() {
  return getToken(FrameParser::CONVERT, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ConvertingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ConvertingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ConvertingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ConvertingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ConvertingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ConvertingContext::ConvertingContext(Convert_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ConvertingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitConverting(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Convert_actionContext* FrameParser::convert_action() {
  Convert_actionContext *_localctx = _tracker.createInstance<Convert_actionContext>(_ctx, getState());
  enterRule(_localctx, 80, FrameParser::RuleConvert_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ConvertingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(595);
    match(FrameParser::CONVERT);
    setState(596);
    match(FrameParser::NAME);
    setState(599);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(597);
      match(FrameParser::AS);
      setState(598);
      match(FrameParser::NAME);
    }
    setState(603);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(601);
      match(FrameParser::SAVE_TO);
      setState(602);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Noise_reduction_actionContext ------------------------------------------------------------------

FrameParser::Noise_reduction_actionContext::Noise_reduction_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Noise_reduction_actionContext::getRuleIndex() const {
  return FrameParser::RuleNoise_reduction_action;
}

void FrameParser::Noise_reduction_actionContext::copyFrom(Noise_reduction_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NoiseReductionContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::NoiseReductionContext::REDUCE() {
  return getToken(FrameParser::REDUCE, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::NOISE() {
  return getToken(FrameParser::NOISE, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::NoiseReductionContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::MIX() {
  return getToken(FrameParser::MIX, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::NoiseReductionContext::MINUS() {
  return getToken(FrameParser::MINUS, 0);
}

FrameParser::NoiseReductionContext::NoiseReductionContext(Noise_reduction_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::NoiseReductionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitNoiseReduction(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Noise_reduction_actionContext* FrameParser::noise_reduction_action() {
  Noise_reduction_actionContext *_localctx = _tracker.createInstance<Noise_reduction_actionContext>(_ctx, getState());
  enterRule(_localctx, 82, FrameParser::RuleNoise_reduction_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::NoiseReductionContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(605);
    match(FrameParser::REDUCE);
    setState(606);
    match(FrameParser::NOISE);
    setState(607);
    match(FrameParser::FOR);
    setState(608);
    match(FrameParser::NAME);

    setState(609);
    match(FrameParser::MIX);
    setState(611);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::MINUS) {
      setState(610);
      match(FrameParser::MINUS);
    }
    setState(613);
    antlrcpp::downCast<NoiseReductionContext *>(_localctx)->mixValue = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::INT

    || _la == FrameParser::FLOAT)) {
      antlrcpp::downCast<NoiseReductionContext *>(_localctx)->mixValue = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(617);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(615);
      match(FrameParser::AS);
      setState(616);
      match(FrameParser::NAME);
    }

    setState(619);
    match(FrameParser::SAVE_TO);
    setState(620);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Normalize_actionContext ------------------------------------------------------------------

FrameParser::Normalize_actionContext::Normalize_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Normalize_actionContext::getRuleIndex() const {
  return FrameParser::RuleNormalize_action;
}

void FrameParser::Normalize_actionContext::copyFrom(Normalize_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NormalizationContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::NormalizationContext::NORMALIZE() {
  return getToken(FrameParser::NORMALIZE, 0);
}

std::vector<tree::TerminalNode *> FrameParser::NormalizationContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::NormalizationContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::NormalizationContext::LOUDNESS() {
  return getToken(FrameParser::LOUDNESS, 0);
}

tree::TerminalNode* FrameParser::NormalizationContext::RANGE() {
  return getToken(FrameParser::RANGE, 0);
}

tree::TerminalNode* FrameParser::NormalizationContext::PEAK() {
  return getToken(FrameParser::PEAK, 0);
}

tree::TerminalNode* FrameParser::NormalizationContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::NormalizationContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::NormalizationContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

std::vector<tree::TerminalNode *> FrameParser::NormalizationContext::FLOAT() {
  return getTokens(FrameParser::FLOAT);
}

tree::TerminalNode* FrameParser::NormalizationContext::FLOAT(size_t i) {
  return getToken(FrameParser::FLOAT, i);
}

std::vector<tree::TerminalNode *> FrameParser::NormalizationContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::NormalizationContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

FrameParser::NormalizationContext::NormalizationContext(Normalize_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::NormalizationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitNormalization(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Normalize_actionContext* FrameParser::normalize_action() {
  Normalize_actionContext *_localctx = _tracker.createInstance<Normalize_actionContext>(_ctx, getState());
  enterRule(_localctx, 84, FrameParser::RuleNormalize_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::NormalizationContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(622);
    match(FrameParser::NORMALIZE);
    setState(623);
    match(FrameParser::NAME);
    setState(626);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::LOUDNESS) {
      setState(624);
      match(FrameParser::LOUDNESS);
      setState(625);
      antlrcpp::downCast<NormalizationContext *>(_localctx)->loudnessValue = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<NormalizationContext *>(_localctx)->loudnessValue = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(630);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::RANGE) {
      setState(628);
      match(FrameParser::RANGE);
      setState(629);
      antlrcpp::downCast<NormalizationContext *>(_localctx)->rangeValue = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<NormalizationContext *>(_localctx)->rangeValue = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(634);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::PEAK) {
      setState(632);
      match(FrameParser::PEAK);
      setState(633);
      antlrcpp::downCast<NormalizationContext *>(_localctx)->peakValue = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<NormalizationContext *>(_localctx)->peakValue = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(638);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(636);
      match(FrameParser::AS);
      setState(637);
      match(FrameParser::NAME);
    }
    setState(642);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(640);
      match(FrameParser::SAVE_TO);
      setState(641);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bass_actionContext ------------------------------------------------------------------

FrameParser::Bass_actionContext::Bass_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Bass_actionContext::getRuleIndex() const {
  return FrameParser::RuleBass_action;
}

void FrameParser::Bass_actionContext::copyFrom(Bass_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingBassContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingBassContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingBassContext::BASS() {
  return getToken(FrameParser::BASS, 0);
}

tree::TerminalNode* FrameParser::SettingBassContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingBassContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingBassContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingBassContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingBassContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

tree::TerminalNode* FrameParser::SettingBassContext::GAIN() {
  return getToken(FrameParser::GAIN, 0);
}

tree::TerminalNode* FrameParser::SettingBassContext::FREQUENCY() {
  return getToken(FrameParser::FREQUENCY, 0);
}

tree::TerminalNode* FrameParser::SettingBassContext::AS() {
  return getToken(FrameParser::AS, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingBassContext::FLOAT() {
  return getTokens(FrameParser::FLOAT);
}

tree::TerminalNode* FrameParser::SettingBassContext::FLOAT(size_t i) {
  return getToken(FrameParser::FLOAT, i);
}

std::vector<tree::TerminalNode *> FrameParser::SettingBassContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::SettingBassContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::SettingBassContext::MINUS() {
  return getToken(FrameParser::MINUS, 0);
}

FrameParser::SettingBassContext::SettingBassContext(Bass_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingBassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingBass(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Bass_actionContext* FrameParser::bass_action() {
  Bass_actionContext *_localctx = _tracker.createInstance<Bass_actionContext>(_ctx, getState());
  enterRule(_localctx, 86, FrameParser::RuleBass_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingBassContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(644);
    match(FrameParser::SET);
    setState(645);
    match(FrameParser::BASS);
    setState(646);
    match(FrameParser::FOR);
    setState(647);
    match(FrameParser::NAME);
    setState(653);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::GAIN) {
      setState(648);
      match(FrameParser::GAIN);
      setState(650);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FrameParser::MINUS) {
        setState(649);
        match(FrameParser::MINUS);
      }
      setState(652);
      antlrcpp::downCast<SettingBassContext *>(_localctx)->gainValue = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<SettingBassContext *>(_localctx)->gainValue = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(657);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::FREQUENCY) {
      setState(655);
      match(FrameParser::FREQUENCY);
      setState(656);
      antlrcpp::downCast<SettingBassContext *>(_localctx)->frequencyValue = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<SettingBassContext *>(_localctx)->frequencyValue = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(661);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(659);
      match(FrameParser::AS);
      setState(660);
      match(FrameParser::NAME);
    }

    setState(663);
    match(FrameParser::SAVE_TO);
    setState(664);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Treble_actionContext ------------------------------------------------------------------

FrameParser::Treble_actionContext::Treble_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Treble_actionContext::getRuleIndex() const {
  return FrameParser::RuleTreble_action;
}

void FrameParser::Treble_actionContext::copyFrom(Treble_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SettingTrebleContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SettingTrebleContext::SET() {
  return getToken(FrameParser::SET, 0);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::TREBLE() {
  return getToken(FrameParser::TREBLE, 0);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingTrebleContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::GAIN() {
  return getToken(FrameParser::GAIN, 0);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::FREQUENCY() {
  return getToken(FrameParser::FREQUENCY, 0);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::AS() {
  return getToken(FrameParser::AS, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SettingTrebleContext::FLOAT() {
  return getTokens(FrameParser::FLOAT);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::FLOAT(size_t i) {
  return getToken(FrameParser::FLOAT, i);
}

std::vector<tree::TerminalNode *> FrameParser::SettingTrebleContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::SettingTrebleContext::MINUS() {
  return getToken(FrameParser::MINUS, 0);
}

FrameParser::SettingTrebleContext::SettingTrebleContext(Treble_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SettingTrebleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSettingTreble(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Treble_actionContext* FrameParser::treble_action() {
  Treble_actionContext *_localctx = _tracker.createInstance<Treble_actionContext>(_ctx, getState());
  enterRule(_localctx, 88, FrameParser::RuleTreble_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SettingTrebleContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(666);
    match(FrameParser::SET);
    setState(667);
    match(FrameParser::TREBLE);
    setState(668);
    match(FrameParser::FOR);
    setState(669);
    match(FrameParser::NAME);
    setState(675);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::GAIN) {
      setState(670);
      match(FrameParser::GAIN);
      setState(672);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FrameParser::MINUS) {
        setState(671);
        match(FrameParser::MINUS);
      }
      setState(674);
      antlrcpp::downCast<SettingTrebleContext *>(_localctx)->gainValue = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<SettingTrebleContext *>(_localctx)->gainValue = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(679);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::FREQUENCY) {
      setState(677);
      match(FrameParser::FREQUENCY);
      setState(678);
      antlrcpp::downCast<SettingTrebleContext *>(_localctx)->frequencyValue = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<SettingTrebleContext *>(_localctx)->frequencyValue = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(683);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(681);
      match(FrameParser::AS);
      setState(682);
      match(FrameParser::NAME);
    }

    setState(685);
    match(FrameParser::SAVE_TO);
    setState(686);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Abitscope_actionContext ------------------------------------------------------------------

FrameParser::Abitscope_actionContext::Abitscope_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Abitscope_actionContext::getRuleIndex() const {
  return FrameParser::RuleAbitscope_action;
}

void FrameParser::Abitscope_actionContext::copyFrom(Abitscope_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingBitscopeContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingBitscopeContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::BITSCOPE() {
  return getToken(FrameParser::BITSCOPE, 0);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingBitscopeContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::COLORS() {
  return getToken(FrameParser::COLORS, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingBitscopeContext::COLOR() {
  return getTokens(FrameParser::COLOR);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::COLOR(size_t i) {
  return getToken(FrameParser::COLOR, i);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::WIDTH() {
  return getToken(FrameParser::WIDTH, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingBitscopeContext::INT() {
  return getTokens(FrameParser::INT);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::INT(size_t i) {
  return getToken(FrameParser::INT, i);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::HEIGHT() {
  return getToken(FrameParser::HEIGHT, 0);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingBitscopeContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingBitscopeContext::ShowingBitscopeContext(Abitscope_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingBitscopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingBitscope(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Abitscope_actionContext* FrameParser::abitscope_action() {
  Abitscope_actionContext *_localctx = _tracker.createInstance<Abitscope_actionContext>(_ctx, getState());
  enterRule(_localctx, 90, FrameParser::RuleAbitscope_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingBitscopeContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(688);
    match(FrameParser::SHOW);
    setState(689);
    match(FrameParser::BITSCOPE);
    setState(690);
    match(FrameParser::FOR);
    setState(691);
    match(FrameParser::NAME);
    setState(695);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::COLORS) {
      setState(692);
      match(FrameParser::COLORS);
      setState(693);
      match(FrameParser::COLOR);
      setState(694);
      match(FrameParser::COLOR);
    }
    setState(701);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::WIDTH) {
      setState(697);
      match(FrameParser::WIDTH);
      setState(698);
      match(FrameParser::INT);
      setState(699);
      match(FrameParser::HEIGHT);
      setState(700);
      match(FrameParser::INT);
    }
    setState(705);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(703);
      match(FrameParser::AS);
      setState(704);
      match(FrameParser::NAME);
    }
    setState(709);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(707);
      match(FrameParser::SAVE_TO);
      setState(708);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ahistogram_actionContext ------------------------------------------------------------------

FrameParser::Ahistogram_actionContext::Ahistogram_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Ahistogram_actionContext::getRuleIndex() const {
  return FrameParser::RuleAhistogram_action;
}

void FrameParser::Ahistogram_actionContext::copyFrom(Ahistogram_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingAHistogramContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingAHistogramContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::HISTOGRAM() {
  return getToken(FrameParser::HISTOGRAM, 0);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingAHistogramContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::DISPLAY() {
  return getToken(FrameParser::DISPLAY, 0);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::MODE() {
  return getToken(FrameParser::MODE, 0);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingAHistogramContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingAHistogramContext::ShowingAHistogramContext(Ahistogram_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingAHistogramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingAHistogram(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Ahistogram_actionContext* FrameParser::ahistogram_action() {
  Ahistogram_actionContext *_localctx = _tracker.createInstance<Ahistogram_actionContext>(_ctx, getState());
  enterRule(_localctx, 92, FrameParser::RuleAhistogram_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingAHistogramContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(711);
    match(FrameParser::SHOW);
    setState(712);
    match(FrameParser::T__1);
    setState(713);
    match(FrameParser::HISTOGRAM);
    setState(714);
    match(FrameParser::FOR);
    setState(715);
    match(FrameParser::NAME);

    setState(716);
    match(FrameParser::DISPLAY);
    setState(717);
    match(FrameParser::MODE);
    setState(718);
    antlrcpp::downCast<ShowingAHistogramContext *>(_localctx)->dmode = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::T__3

    || _la == FrameParser::T__4)) {
      antlrcpp::downCast<ShowingAHistogramContext *>(_localctx)->dmode = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(722);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(720);
      match(FrameParser::AS);
      setState(721);
      match(FrameParser::NAME);
    }
    setState(726);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(724);
      match(FrameParser::SAVE_TO);
      setState(725);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aphasemeter_actionContext ------------------------------------------------------------------

FrameParser::Aphasemeter_actionContext::Aphasemeter_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Aphasemeter_actionContext::getRuleIndex() const {
  return FrameParser::RuleAphasemeter_action;
}

void FrameParser::Aphasemeter_actionContext::copyFrom(Aphasemeter_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingPhasemeterContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingPhasemeterContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingPhasemeterContext::PHASEMETER() {
  return getToken(FrameParser::PHASEMETER, 0);
}

tree::TerminalNode* FrameParser::ShowingPhasemeterContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingPhasemeterContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingPhasemeterContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingPhasemeterContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingPhasemeterContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingPhasemeterContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingPhasemeterContext::ShowingPhasemeterContext(Aphasemeter_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingPhasemeterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingPhasemeter(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Aphasemeter_actionContext* FrameParser::aphasemeter_action() {
  Aphasemeter_actionContext *_localctx = _tracker.createInstance<Aphasemeter_actionContext>(_ctx, getState());
  enterRule(_localctx, 94, FrameParser::RuleAphasemeter_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingPhasemeterContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(728);
    match(FrameParser::SHOW);
    setState(729);
    match(FrameParser::PHASEMETER);
    setState(730);
    match(FrameParser::FOR);
    setState(731);
    match(FrameParser::NAME);
    setState(734);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(732);
      match(FrameParser::AS);
      setState(733);
      match(FrameParser::NAME);
    }
    setState(738);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(736);
      match(FrameParser::SAVE_TO);
      setState(737);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Avectorscope_actionContext ------------------------------------------------------------------

FrameParser::Avectorscope_actionContext::Avectorscope_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Avectorscope_actionContext::getRuleIndex() const {
  return FrameParser::RuleAvectorscope_action;
}

void FrameParser::Avectorscope_actionContext::copyFrom(Avectorscope_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingVectorscopeContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::VECTORSCOPE() {
  return getToken(FrameParser::VECTORSCOPE, 0);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingVectorscopeContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::DRAWING() {
  return getToken(FrameParser::DRAWING, 0);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::MODE() {
  return getToken(FrameParser::MODE, 0);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingVectorscopeContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingVectorscopeContext::ShowingVectorscopeContext(Avectorscope_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingVectorscopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingVectorscope(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Avectorscope_actionContext* FrameParser::avectorscope_action() {
  Avectorscope_actionContext *_localctx = _tracker.createInstance<Avectorscope_actionContext>(_ctx, getState());
  enterRule(_localctx, 96, FrameParser::RuleAvectorscope_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingVectorscopeContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(740);
    match(FrameParser::SHOW);
    setState(741);
    match(FrameParser::T__1);
    setState(742);
    match(FrameParser::VECTORSCOPE);
    setState(743);
    match(FrameParser::FOR);
    setState(744);
    match(FrameParser::NAME);
    setState(748);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::DRAWING) {
      setState(745);
      match(FrameParser::DRAWING);
      setState(746);
      match(FrameParser::MODE);
      setState(747);
      antlrcpp::downCast<ShowingVectorscopeContext *>(_localctx)->drawingMode = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::T__5

      || _la == FrameParser::T__6)) {
        antlrcpp::downCast<ShowingVectorscopeContext *>(_localctx)->drawingMode = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(752);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(750);
      match(FrameParser::AS);
      setState(751);
      match(FrameParser::NAME);
    }
    setState(756);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(754);
      match(FrameParser::SAVE_TO);
      setState(755);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Showcqt_actionContext ------------------------------------------------------------------

FrameParser::Showcqt_actionContext::Showcqt_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Showcqt_actionContext::getRuleIndex() const {
  return FrameParser::RuleShowcqt_action;
}

void FrameParser::Showcqt_actionContext::copyFrom(Showcqt_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingCQTContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingCQTContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingCQTContext::CQT() {
  return getToken(FrameParser::CQT, 0);
}

tree::TerminalNode* FrameParser::ShowingCQTContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingCQTContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingCQTContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingCQTContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingCQTContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingCQTContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingCQTContext::ShowingCQTContext(Showcqt_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingCQTContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingCQT(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Showcqt_actionContext* FrameParser::showcqt_action() {
  Showcqt_actionContext *_localctx = _tracker.createInstance<Showcqt_actionContext>(_ctx, getState());
  enterRule(_localctx, 98, FrameParser::RuleShowcqt_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingCQTContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(758);
    match(FrameParser::SHOW);
    setState(759);
    match(FrameParser::CQT);
    setState(760);
    match(FrameParser::FOR);
    setState(761);
    match(FrameParser::NAME);
    setState(764);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(762);
      match(FrameParser::AS);
      setState(763);
      match(FrameParser::NAME);
    }
    setState(768);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(766);
      match(FrameParser::SAVE_TO);
      setState(767);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Showfreqs_actionContext ------------------------------------------------------------------

FrameParser::Showfreqs_actionContext::Showfreqs_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Showfreqs_actionContext::getRuleIndex() const {
  return FrameParser::RuleShowfreqs_action;
}

void FrameParser::Showfreqs_actionContext::copyFrom(Showfreqs_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingFreqsContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingFreqsContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::FREQUENCIES() {
  return getToken(FrameParser::FREQUENCIES, 0);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingFreqsContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::DISPLAY() {
  return getToken(FrameParser::DISPLAY, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingFreqsContext::MODE() {
  return getTokens(FrameParser::MODE);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::MODE(size_t i) {
  return getToken(FrameParser::MODE, i);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::COLORS() {
  return getToken(FrameParser::COLORS, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingFreqsContext::COLOR() {
  return getTokens(FrameParser::COLOR);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::COLOR(size_t i) {
  return getToken(FrameParser::COLOR, i);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::CHANNEL() {
  return getToken(FrameParser::CHANNEL, 0);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingFreqsContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingFreqsContext::ShowingFreqsContext(Showfreqs_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingFreqsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingFreqs(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Showfreqs_actionContext* FrameParser::showfreqs_action() {
  Showfreqs_actionContext *_localctx = _tracker.createInstance<Showfreqs_actionContext>(_ctx, getState());
  enterRule(_localctx, 100, FrameParser::RuleShowfreqs_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingFreqsContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(770);
    match(FrameParser::SHOW);
    setState(771);
    match(FrameParser::FREQUENCIES);
    setState(772);
    match(FrameParser::FOR);
    setState(773);
    match(FrameParser::NAME);
    setState(777);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::DISPLAY) {
      setState(774);
      match(FrameParser::DISPLAY);
      setState(775);
      match(FrameParser::MODE);
      setState(776);
      antlrcpp::downCast<ShowingFreqsContext *>(_localctx)->freqsDModes = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FrameParser::T__5)
        | (1ULL << FrameParser::T__6)
        | (1ULL << FrameParser::T__7))) != 0))) {
        antlrcpp::downCast<ShowingFreqsContext *>(_localctx)->freqsDModes = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(782);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::COLORS) {
      setState(779);
      match(FrameParser::COLORS);
      setState(780);
      match(FrameParser::COLOR);
      setState(781);
      match(FrameParser::COLOR);
    }
    setState(787);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::CHANNEL) {
      setState(784);
      match(FrameParser::CHANNEL);
      setState(785);
      match(FrameParser::MODE);
      setState(786);
      antlrcpp::downCast<ShowingFreqsContext *>(_localctx)->freqsCMode = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::T__4

      || _la == FrameParser::T__8)) {
        antlrcpp::downCast<ShowingFreqsContext *>(_localctx)->freqsCMode = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(791);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(789);
      match(FrameParser::AS);
      setState(790);
      match(FrameParser::NAME);
    }
    setState(795);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(793);
      match(FrameParser::SAVE_TO);
      setState(794);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Showspatial_actionContext ------------------------------------------------------------------

FrameParser::Showspatial_actionContext::Showspatial_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Showspatial_actionContext::getRuleIndex() const {
  return FrameParser::RuleShowspatial_action;
}

void FrameParser::Showspatial_actionContext::copyFrom(Showspatial_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingSpatialContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingSpatialContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingSpatialContext::SPATIAL() {
  return getToken(FrameParser::SPATIAL, 0);
}

tree::TerminalNode* FrameParser::ShowingSpatialContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingSpatialContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingSpatialContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingSpatialContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingSpatialContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingSpatialContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingSpatialContext::ShowingSpatialContext(Showspatial_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingSpatialContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingSpatial(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Showspatial_actionContext* FrameParser::showspatial_action() {
  Showspatial_actionContext *_localctx = _tracker.createInstance<Showspatial_actionContext>(_ctx, getState());
  enterRule(_localctx, 102, FrameParser::RuleShowspatial_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingSpatialContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(797);
    match(FrameParser::SHOW);
    setState(798);
    match(FrameParser::SPATIAL);
    setState(799);
    match(FrameParser::FOR);
    setState(800);
    match(FrameParser::NAME);
    setState(803);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(801);
      match(FrameParser::AS);
      setState(802);
      match(FrameParser::NAME);
    }
    setState(807);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(805);
      match(FrameParser::SAVE_TO);
      setState(806);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Showspectrum_actionContext ------------------------------------------------------------------

FrameParser::Showspectrum_actionContext::Showspectrum_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Showspectrum_actionContext::getRuleIndex() const {
  return FrameParser::RuleShowspectrum_action;
}

void FrameParser::Showspectrum_actionContext::copyFrom(Showspectrum_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingSpectrumContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingSpectrumContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::SPECTRUM() {
  return getToken(FrameParser::SPECTRUM, 0);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingSpectrumContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::DISPLAY() {
  return getToken(FrameParser::DISPLAY, 0);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::MODE() {
  return getToken(FrameParser::MODE, 0);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingSpectrumContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingSpectrumContext::ShowingSpectrumContext(Showspectrum_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingSpectrumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingSpectrum(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Showspectrum_actionContext* FrameParser::showspectrum_action() {
  Showspectrum_actionContext *_localctx = _tracker.createInstance<Showspectrum_actionContext>(_ctx, getState());
  enterRule(_localctx, 104, FrameParser::RuleShowspectrum_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingSpectrumContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(809);
    match(FrameParser::SHOW);
    setState(810);
    match(FrameParser::SPECTRUM);
    setState(811);
    match(FrameParser::FOR);
    setState(812);
    match(FrameParser::NAME);

    setState(813);
    match(FrameParser::DISPLAY);
    setState(814);
    match(FrameParser::MODE);
    setState(815);
    antlrcpp::downCast<ShowingSpectrumContext *>(_localctx)->spectrumDMode = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FrameParser::T__4

    || _la == FrameParser::T__8)) {
      antlrcpp::downCast<ShowingSpectrumContext *>(_localctx)->spectrumDMode = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(819);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(817);
      match(FrameParser::AS);
      setState(818);
      match(FrameParser::NAME);
    }
    setState(823);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(821);
      match(FrameParser::SAVE_TO);
      setState(822);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Showvolume_actionContext ------------------------------------------------------------------

FrameParser::Showvolume_actionContext::Showvolume_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Showvolume_actionContext::getRuleIndex() const {
  return FrameParser::RuleShowvolume_action;
}

void FrameParser::Showvolume_actionContext::copyFrom(Showvolume_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShowingVolumeContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ShowingVolumeContext::SHOW() {
  return getToken(FrameParser::SHOW, 0);
}

tree::TerminalNode* FrameParser::ShowingVolumeContext::VOLUME() {
  return getToken(FrameParser::VOLUME, 0);
}

tree::TerminalNode* FrameParser::ShowingVolumeContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ShowingVolumeContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ShowingVolumeContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ShowingVolumeContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ShowingVolumeContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ShowingVolumeContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ShowingVolumeContext::ShowingVolumeContext(Showvolume_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ShowingVolumeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitShowingVolume(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Showvolume_actionContext* FrameParser::showvolume_action() {
  Showvolume_actionContext *_localctx = _tracker.createInstance<Showvolume_actionContext>(_ctx, getState());
  enterRule(_localctx, 106, FrameParser::RuleShowvolume_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ShowingVolumeContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(825);
    match(FrameParser::SHOW);
    setState(826);
    match(FrameParser::VOLUME);
    setState(827);
    match(FrameParser::FOR);
    setState(828);
    match(FrameParser::NAME);
    setState(831);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(829);
      match(FrameParser::AS);
      setState(830);
      match(FrameParser::NAME);
    }
    setState(835);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(833);
      match(FrameParser::SAVE_TO);
      setState(834);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Super2xsai_actionContext ------------------------------------------------------------------

FrameParser::Super2xsai_actionContext::Super2xsai_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Super2xsai_actionContext::getRuleIndex() const {
  return FrameParser::RuleSuper2xsai_action;
}

void FrameParser::Super2xsai_actionContext::copyFrom(Super2xsai_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ScalingPixelArtContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::ScalingPixelArtContext::SCALE() {
  return getToken(FrameParser::SCALE, 0);
}

tree::TerminalNode* FrameParser::ScalingPixelArtContext::PIXEL() {
  return getToken(FrameParser::PIXEL, 0);
}

tree::TerminalNode* FrameParser::ScalingPixelArtContext::ART() {
  return getToken(FrameParser::ART, 0);
}

std::vector<tree::TerminalNode *> FrameParser::ScalingPixelArtContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::ScalingPixelArtContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::ScalingPixelArtContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::ScalingPixelArtContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::ScalingPixelArtContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::ScalingPixelArtContext::ScalingPixelArtContext(Super2xsai_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::ScalingPixelArtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitScalingPixelArt(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Super2xsai_actionContext* FrameParser::super2xsai_action() {
  Super2xsai_actionContext *_localctx = _tracker.createInstance<Super2xsai_actionContext>(_ctx, getState());
  enterRule(_localctx, 108, FrameParser::RuleSuper2xsai_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::ScalingPixelArtContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(837);
    match(FrameParser::SCALE);
    setState(838);
    match(FrameParser::PIXEL);
    setState(839);
    match(FrameParser::ART);
    setState(840);
    match(FrameParser::NAME);
    setState(843);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(841);
      match(FrameParser::AS);
      setState(842);
      match(FrameParser::NAME);
    }
    setState(847);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(845);
      match(FrameParser::SAVE_TO);
      setState(846);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sobel_actionContext ------------------------------------------------------------------

FrameParser::Sobel_actionContext::Sobel_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Sobel_actionContext::getRuleIndex() const {
  return FrameParser::RuleSobel_action;
}

void FrameParser::Sobel_actionContext::copyFrom(Sobel_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SobelContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::SobelContext::SOBEL() {
  return getToken(FrameParser::SOBEL, 0);
}

std::vector<tree::TerminalNode *> FrameParser::SobelContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::SobelContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::SobelContext::INTENSITY() {
  return getToken(FrameParser::INTENSITY, 0);
}

tree::TerminalNode* FrameParser::SobelContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::SobelContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::SobelContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

tree::TerminalNode* FrameParser::SobelContext::FLOAT() {
  return getToken(FrameParser::FLOAT, 0);
}

tree::TerminalNode* FrameParser::SobelContext::INT() {
  return getToken(FrameParser::INT, 0);
}

FrameParser::SobelContext::SobelContext(Sobel_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::SobelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitSobel(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Sobel_actionContext* FrameParser::sobel_action() {
  Sobel_actionContext *_localctx = _tracker.createInstance<Sobel_actionContext>(_ctx, getState());
  enterRule(_localctx, 110, FrameParser::RuleSobel_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::SobelContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(849);
    match(FrameParser::SOBEL);
    setState(850);
    match(FrameParser::NAME);
    setState(853);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::INTENSITY) {
      setState(851);
      match(FrameParser::INTENSITY);
      setState(852);
      antlrcpp::downCast<SobelContext *>(_localctx)->intensityAmount = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == FrameParser::INT

      || _la == FrameParser::FLOAT)) {
        antlrcpp::downCast<SobelContext *>(_localctx)->intensityAmount = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(857);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(855);
      match(FrameParser::AS);
      setState(856);
      match(FrameParser::NAME);
    }
    setState(861);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(859);
      match(FrameParser::SAVE_TO);
      setState(860);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tmix_actionContext ------------------------------------------------------------------

FrameParser::Tmix_actionContext::Tmix_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Tmix_actionContext::getRuleIndex() const {
  return FrameParser::RuleTmix_action;
}

void FrameParser::Tmix_actionContext::copyFrom(Tmix_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MixingContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::MixingContext::MIX() {
  return getToken(FrameParser::MIX, 0);
}

tree::TerminalNode* FrameParser::MixingContext::FOR() {
  return getToken(FrameParser::FOR, 0);
}

std::vector<tree::TerminalNode *> FrameParser::MixingContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::MixingContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::MixingContext::INT() {
  return getToken(FrameParser::INT, 0);
}

tree::TerminalNode* FrameParser::MixingContext::AS() {
  return getToken(FrameParser::AS, 0);
}

tree::TerminalNode* FrameParser::MixingContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::MixingContext::STRING() {
  return getToken(FrameParser::STRING, 0);
}

FrameParser::MixingContext::MixingContext(Tmix_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::MixingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitMixing(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Tmix_actionContext* FrameParser::tmix_action() {
  Tmix_actionContext *_localctx = _tracker.createInstance<Tmix_actionContext>(_ctx, getState());
  enterRule(_localctx, 112, FrameParser::RuleTmix_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::MixingContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(863);
    match(FrameParser::MIX);
    setState(864);
    match(FrameParser::T__2);
    setState(866);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::INT) {
      setState(865);
      match(FrameParser::INT);
    }
    setState(868);
    match(FrameParser::FOR);
    setState(869);
    match(FrameParser::NAME);
    setState(872);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(870);
      match(FrameParser::AS);
      setState(871);
      match(FrameParser::NAME);
    }
    setState(876);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::SAVE_TO) {
      setState(874);
      match(FrameParser::SAVE_TO);
      setState(875);
      match(FrameParser::STRING);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Embedding_subtitles_actionContext ------------------------------------------------------------------

FrameParser::Embedding_subtitles_actionContext::Embedding_subtitles_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FrameParser::Embedding_subtitles_actionContext::getRuleIndex() const {
  return FrameParser::RuleEmbedding_subtitles_action;
}

void FrameParser::Embedding_subtitles_actionContext::copyFrom(Embedding_subtitles_actionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EmbeddingSubtitlesContext ------------------------------------------------------------------

tree::TerminalNode* FrameParser::EmbeddingSubtitlesContext::EMBED() {
  return getToken(FrameParser::EMBED, 0);
}

tree::TerminalNode* FrameParser::EmbeddingSubtitlesContext::SUBTITLES() {
  return getToken(FrameParser::SUBTITLES, 0);
}

std::vector<tree::TerminalNode *> FrameParser::EmbeddingSubtitlesContext::STRING() {
  return getTokens(FrameParser::STRING);
}

tree::TerminalNode* FrameParser::EmbeddingSubtitlesContext::STRING(size_t i) {
  return getToken(FrameParser::STRING, i);
}

tree::TerminalNode* FrameParser::EmbeddingSubtitlesContext::IN() {
  return getToken(FrameParser::IN, 0);
}

std::vector<tree::TerminalNode *> FrameParser::EmbeddingSubtitlesContext::NAME() {
  return getTokens(FrameParser::NAME);
}

tree::TerminalNode* FrameParser::EmbeddingSubtitlesContext::NAME(size_t i) {
  return getToken(FrameParser::NAME, i);
}

tree::TerminalNode* FrameParser::EmbeddingSubtitlesContext::SAVE_TO() {
  return getToken(FrameParser::SAVE_TO, 0);
}

tree::TerminalNode* FrameParser::EmbeddingSubtitlesContext::AS() {
  return getToken(FrameParser::AS, 0);
}

FrameParser::EmbeddingSubtitlesContext::EmbeddingSubtitlesContext(Embedding_subtitles_actionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FrameParser::EmbeddingSubtitlesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FrameVisitor*>(visitor))
    return parserVisitor->visitEmbeddingSubtitles(this);
  else
    return visitor->visitChildren(this);
}
FrameParser::Embedding_subtitles_actionContext* FrameParser::embedding_subtitles_action() {
  Embedding_subtitles_actionContext *_localctx = _tracker.createInstance<Embedding_subtitles_actionContext>(_ctx, getState());
  enterRule(_localctx, 114, FrameParser::RuleEmbedding_subtitles_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<FrameParser::EmbeddingSubtitlesContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(878);
    match(FrameParser::EMBED);
    setState(879);
    match(FrameParser::SUBTITLES);
    setState(880);
    match(FrameParser::STRING);
    setState(881);
    match(FrameParser::IN);
    setState(882);
    match(FrameParser::NAME);
    setState(885);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FrameParser::AS) {
      setState(883);
      match(FrameParser::AS);
      setState(884);
      match(FrameParser::NAME);
    }

    setState(887);
    match(FrameParser::SAVE_TO);
    setState(888);
    match(FrameParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> FrameParser::_decisionToDFA;
atn::PredictionContextCache FrameParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FrameParser::_atn;
std::vector<uint16_t> FrameParser::_serializedATN;

std::vector<std::string> FrameParser::_ruleNames = {
  "file", "program", "global_options", "reencode_option", "output_option", 
  "overwrite_option", "debug_option", "construct", "path", "property", "format", 
  "codec", "bitrate", "sample_rate", "pitch", "tempo", "resolution", "framerate", 
  "action", "trim_action", "crop_action", "overlay_action", "extract_audio_from_video_action", 
  "extract_frames_from_video_action", "merge_audio_with_video_action", "concatentation_action", 
  "rotate_action", "flip_action", "saturation_action", "gamma_action", "brightness_action", 
  "contrast_action", "frame_rate_action", "volume_action", "scale_action", 
  "extract_N_subtitles_from_video", "extract_Kth_subtitle_from_video", "add_subtitles_to_video", 
  "sharpen_action", "blur_action", "convert_action", "noise_reduction_action", 
  "normalize_action", "bass_action", "treble_action", "abitscope_action", 
  "ahistogram_action", "aphasemeter_action", "avectorscope_action", "showcqt_action", 
  "showfreqs_action", "showspatial_action", "showspectrum_action", "showvolume_action", 
  "super2xsai_action", "sobel_action", "tmix_action", "embedding_subtitles_action"
};

std::vector<std::string> FrameParser::_literalNames = {
  "", "'x'", "'audio'", "'frames'", "'single'", "'separate'", "'dot'", "'line'", 
  "'bar'", "'combined'", "", "", "", "", "", "'codec'", "'bitrate'", "'sample rate'", 
  "'pitch'", "'tempo'", "'resolution'", "'hflip'", "'vflip'", "'save to'", 
  "'number'", "'subtitles'", "'subtitle'", "", "'pixel'", "'art'", "'format'", 
  "", "", "'Options'", "'Audio'", "'Frame'", "'Video'", "'path'", "'trim'", 
  "'crop'", "'framerate'", "'extract'", "'resize'", "'ratio'", "'overlay'", 
  "'merge'", "'position'", "'saturation'", "'gamma'", "'contrast'", "'rotate'", 
  "'flip'", "'brightness'", "'concatenate'", "'scale'", "'set'", "'volume'", 
  "'height'", "'width'", "'sharpen'", "'blur'", "'convert'", "'add'", "'from'", 
  "'to'", "'as'", "'with'", "'for'", "'on'", "'at'", "'intensity'", "'reduce'", 
  "'noise'", "'mix'", "'normalize'", "'loudness'", "'range'", "'peak'", 
  "'treble'", "'bass'", "'gain'", "'frequency'", "'show'", "'bitscope'", 
  "'histogram'", "'display'", "'mode'", "'phasemeter'", "'vectorscope'", 
  "'drawing'", "'cqt'", "'frequencies'", "'spatial'", "'spectrum'", "'colors'", 
  "'channel'", "'sobel'", "'embed'", "'in'", "", "", "", "", "", "':'", 
  "'-'", "','", "", "'{'", "'}'", "'reencode'", "'overwrite'", "'yes'", 
  "'no'", "'output'"
};

std::vector<std::string> FrameParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "VIDEO_FORMAT", "VIDEO_CODEC", 
  "IMAGE_FORMAT", "AUDIO_FORMAT", "DEBUG", "CODEC", "BITRATE", "SAMPLE_RATE", 
  "PITCH", "TEMPO", "RESOLUTION", "HFLIP", "VFLIP", "SAVE_TO", "NUMBER", 
  "SUBTITLES", "SUBTITLE", "FLIP_VH", "PIXEL", "ART", "FORMAT", "COMMENT", 
  "NEWLINE", "OPTIONS", "AUDIO", "FRAME", "VIDEO", "PATH", "TRIM", "CROP", 
  "FRAME_RATE", "EXTRACT", "RESIZE", "RATIO", "OVERLAY", "MERGE", "POSITION", 
  "SATURATION", "GAMMA", "CONTRAST", "ROTATE", "FLIP", "BRIGHTNESS", "CONCATENATE", 
  "SCALE", "SET", "VOLUME", "HEIGHT", "WIDTH", "SHARPEN", "BLUR", "CONVERT", 
  "ADD", "FROM", "TO", "AS", "WITH", "FOR", "ON", "AT", "INTENSITY", "REDUCE", 
  "NOISE", "MIX", "NORMALIZE", "LOUDNESS", "RANGE", "PEAK", "TREBLE", "BASS", 
  "GAIN", "FREQUENCY", "SHOW", "BITSCOPE", "HISTOGRAM", "DISPLAY", "MODE", 
  "PHASEMETER", "VECTORSCOPE", "DRAWING", "CQT", "FREQUENCIES", "SPATIAL", 
  "SPECTRUM", "COLORS", "CHANNEL", "SOBEL", "EMBED", "IN", "TIME", "INT", 
  "FLOAT", "DIGIT", "ALPHA", "COLON", "MINUS", "COMMA", "STRING", "LBRACE", 
  "RBRACE", "REENCODE", "OVERWRITE", "YES", "NO", "OUTPUT", "COLOR", "NAME", 
  "WS"
};

dfa::Vocabulary FrameParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FrameParser::_tokenNames;

FrameParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x77, 0x37d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x7b, 
       0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x7e, 0xb, 0x3, 0x3, 0x3, 0x5, 0x3, 
       0x81, 0xa, 0x3, 0x3, 0x3, 0x7, 0x3, 0x84, 0xa, 0x3, 0xc, 0x3, 0xe, 
       0x3, 0x87, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x7, 0x3, 0x8e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x91, 0xb, 0x3, 
       0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x95, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x9e, 
       0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xa1, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x5, 0x9, 0xb9, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xc2, 0xa, 0x9, 0xc, 
       0x9, 0xe, 0x9, 0xc5, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xd6, 
       0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x5, 0x14, 0x121, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
       0x12b, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x12f, 0xa, 0x15, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
       0x13c, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x140, 0xa, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x144, 0xa, 0x16, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 
       0x17, 0x14d, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x151, 0xa, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x156, 0xa, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x15a, 0xa, 0x17, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x5, 0x18, 0x164, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
       0x168, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x173, 
       0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x177, 0xa, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x5, 0x19, 0x17b, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x183, 0xa, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x187, 0xa, 0x1a, 0x3, 0x1b, 
       0x3, 0x1b, 0x6, 0x1b, 0x18b, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 0x18c, 
       0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x191, 0xa, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x195, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x19c, 0xa, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x5, 0x1c, 0x1a0, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1a7, 0xa, 0x1d, 0x3, 0x1d, 0x3, 
       0x1d, 0x5, 0x1d, 0x1ab, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1b4, 0xa, 
       0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1b8, 0xa, 0x1e, 0x3, 0x1f, 
       0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x5, 0x1f, 0x1c1, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1c5, 
       0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x5, 0x20, 0x1cc, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 
       0x20, 0x1d1, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1d5, 0xa, 
       0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 
       0x21, 0x1dc, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
       0x1e1, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x1e5, 0xa, 0x21, 
       0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
       0x3, 0x22, 0x5, 0x22, 0x1ee, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
       0x22, 0x1f2, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1fb, 0xa, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x5, 0x23, 0x1ff, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
       0x3, 0x24, 0x5, 0x24, 0x20a, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 
       0x24, 0x20e, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x228, 0xa, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x5, 0x27, 0x22c, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x234, 0xa, 0x28, 0x3, 
       0x28, 0x3, 0x28, 0x5, 0x28, 0x238, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 
       0x5, 0x28, 0x23c, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x240, 
       0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x5, 0x29, 0x248, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 
       0x29, 0x24c, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x250, 0xa, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x254, 0xa, 0x29, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x25a, 0xa, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x25e, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x266, 0xa, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x26c, 
       0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
       0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x275, 0xa, 0x2c, 0x3, 0x2c, 0x3, 
       0x2c, 0x5, 0x2c, 0x279, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
       0x27d, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x281, 0xa, 0x2c, 
       0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x285, 0xa, 0x2c, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x28d, 
       0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x290, 0xa, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x5, 0x2d, 0x294, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
       0x298, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x2a3, 
       0xa, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x2a6, 0xa, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x5, 0x2e, 0x2aa, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
       0x2ae, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 
       0x2f, 0x2ba, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
       0x5, 0x2f, 0x2c0, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x2c4, 
       0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x2c8, 0xa, 0x2f, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2d5, 
       0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2d9, 0xa, 0x30, 0x3, 
       0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 
       0x31, 0x2e1, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x2e5, 0xa, 
       0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
       0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x2ef, 0xa, 0x32, 0x3, 0x32, 
       0x3, 0x32, 0x5, 0x32, 0x2f3, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 
       0x32, 0x2f7, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
       0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x2ff, 0xa, 0x33, 0x3, 0x33, 0x3, 
       0x33, 0x5, 0x33, 0x303, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x30c, 0xa, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x311, 0xa, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x316, 0xa, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x5, 0x34, 0x31a, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x5, 0x34, 0x31e, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x326, 0xa, 0x35, 0x3, 0x35, 
       0x3, 0x35, 0x5, 0x35, 0x32a, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 
       0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
       0x36, 0x3, 0x36, 0x5, 0x36, 0x336, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x5, 0x36, 0x33a, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
       0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x342, 0xa, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x5, 0x37, 0x346, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 
       0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x34e, 0xa, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x352, 0xa, 0x38, 0x3, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x358, 0xa, 0x39, 0x3, 0x39, 
       0x3, 0x39, 0x5, 0x39, 0x35c, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 
       0x39, 0x360, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 
       0x365, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 
       0x3a, 0x36b, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x36f, 0xa, 
       0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x378, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
       0x3, 0x3b, 0x3, 0x3b, 0x2, 0x2, 0x3c, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 
       0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x2, 0xc, 0x3, 0x2, 
       0x21, 0x22, 0x3, 0x2, 0x72, 0x73, 0x3, 0x2, 0x24, 0x26, 0x4, 0x2, 
       0xc, 0xc, 0xe, 0xf, 0x3, 0x2, 0xd, 0xf, 0x3, 0x2, 0x66, 0x67, 0x3, 
       0x2, 0x6, 0x7, 0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0x8, 0xa, 0x4, 0x2, 
       0x7, 0x7, 0xb, 0xb, 0x2, 0x3e1, 0x2, 0x76, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0x7c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x92, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa5, 
       0x3, 0x2, 0x2, 0x2, 0xa, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xc, 0xad, 0x3, 
       0x2, 0x2, 0x2, 0xe, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x10, 0xb5, 0x3, 0x2, 
       0x2, 0x2, 0x12, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x14, 0xd5, 0x3, 0x2, 0x2, 
       0x2, 0x16, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xdb, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0xe7, 0x3, 0x2, 0x2, 0x2, 0x20, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x22, 0xef, 
       0x3, 0x2, 0x2, 0x2, 0x24, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x26, 0x120, 
       0x3, 0x2, 0x2, 0x2, 0x28, 0x122, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x2c, 0x145, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x15b, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x169, 0x3, 0x2, 0x2, 0x2, 0x32, 0x17c, 
       0x3, 0x2, 0x2, 0x2, 0x34, 0x188, 0x3, 0x2, 0x2, 0x2, 0x36, 0x196, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1ac, 
       0x3, 0x2, 0x2, 0x2, 0x3c, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1c6, 
       0x3, 0x2, 0x2, 0x2, 0x40, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1e6, 
       0x3, 0x2, 0x2, 0x2, 0x44, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x200, 
       0x3, 0x2, 0x2, 0x2, 0x48, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x217, 
       0x3, 0x2, 0x2, 0x2, 0x4c, 0x220, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x22d, 
       0x3, 0x2, 0x2, 0x2, 0x50, 0x241, 0x3, 0x2, 0x2, 0x2, 0x52, 0x255, 
       0x3, 0x2, 0x2, 0x2, 0x54, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x56, 0x270, 
       0x3, 0x2, 0x2, 0x2, 0x58, 0x286, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x29c, 
       0x3, 0x2, 0x2, 0x2, 0x5c, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x2c9, 
       0x3, 0x2, 0x2, 0x2, 0x60, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x62, 0x2e6, 
       0x3, 0x2, 0x2, 0x2, 0x64, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x66, 0x304, 
       0x3, 0x2, 0x2, 0x2, 0x68, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x32b, 
       0x3, 0x2, 0x2, 0x2, 0x6c, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x347, 
       0x3, 0x2, 0x2, 0x2, 0x70, 0x353, 0x3, 0x2, 0x2, 0x2, 0x72, 0x361, 
       0x3, 0x2, 0x2, 0x2, 0x74, 0x370, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 
       0x5, 0x4, 0x3, 0x2, 0x77, 0x78, 0x7, 0x2, 0x2, 0x3, 0x78, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x79, 0x7b, 0x9, 0x2, 0x2, 0x2, 0x7a, 0x79, 0x3, 0x2, 
       0x2, 0x2, 0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 
       0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 0x2, 
       0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x81, 0x5, 0x6, 0x4, 0x2, 0x80, 
       0x7f, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x85, 
       0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 0x9, 0x2, 0x2, 0x2, 0x83, 0x82, 0x3, 
       0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 
       0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 
       0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8f, 0x5, 0x10, 0x9, 
       0x2, 0x89, 0x8e, 0x7, 0x21, 0x2, 0x2, 0x8a, 0x8e, 0x5, 0x10, 0x9, 
       0x2, 0x8b, 0x8e, 0x5, 0x26, 0x14, 0x2, 0x8c, 0x8e, 0x7, 0x22, 0x2, 
       0x2, 0x8d, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8a, 0x3, 0x2, 0x2, 0x2, 
       0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 
       0x91, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 
       0x3, 0x2, 0x2, 0x2, 0x90, 0x5, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 
       0x2, 0x2, 0x2, 0x92, 0x94, 0x7, 0x23, 0x2, 0x2, 0x93, 0x95, 0x7, 
       0x22, 0x2, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 
       0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x6e, 
       0x2, 0x2, 0x97, 0x9f, 0x7, 0x22, 0x2, 0x2, 0x98, 0x9e, 0x5, 0x8, 
       0x5, 0x2, 0x99, 0x9e, 0x5, 0xa, 0x6, 0x2, 0x9a, 0x9e, 0x5, 0xc, 0x7, 
       0x2, 0x9b, 0x9e, 0x5, 0xe, 0x8, 0x2, 0x9c, 0x9e, 0x7, 0x22, 0x2, 
       0x2, 0x9d, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x99, 0x3, 0x2, 0x2, 0x2, 
       0x9d, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 
       0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 
       0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa2, 0x3, 
       0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x6f, 
       0x2, 0x2, 0xa3, 0xa4, 0x7, 0x22, 0x2, 0x2, 0xa4, 0x7, 0x3, 0x2, 0x2, 
       0x2, 0xa5, 0xa6, 0x7, 0x70, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x6a, 0x2, 
       0x2, 0xa7, 0xa8, 0x9, 0x3, 0x2, 0x2, 0xa8, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0xa9, 0xaa, 0x7, 0x74, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x6a, 0x2, 0x2, 
       0xab, 0xac, 0x7, 0x6d, 0x2, 0x2, 0xac, 0xb, 0x3, 0x2, 0x2, 0x2, 0xad, 
       0xae, 0x7, 0x71, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x6a, 0x2, 0x2, 0xaf, 
       0xb0, 0x9, 0x3, 0x2, 0x2, 0xb0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 
       0x7, 0x10, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x6a, 0x2, 0x2, 0xb3, 0xb4, 
       0x9, 0x3, 0x2, 0x2, 0xb4, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x9, 
       0x4, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x76, 0x2, 0x2, 0xb7, 0xb9, 0x7, 
       0x22, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 
       0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x6e, 
       0x2, 0x2, 0xbb, 0xbc, 0x7, 0x22, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x12, 
       0xa, 0x2, 0xbd, 0xc3, 0x7, 0x22, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x14, 
       0xb, 0x2, 0xbf, 0xc0, 0x7, 0x22, 0x2, 0x2, 0xc0, 0xc2, 0x3, 0x2, 
       0x2, 0x2, 0xc1, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 
       0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 
       0xc4, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 
       0xc7, 0x7, 0x6f, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x22, 0x2, 0x2, 0xc8, 
       0x11, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x27, 0x2, 0x2, 0xca, 
       0xcb, 0x7, 0x6a, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x6d, 0x2, 0x2, 0xcc, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd6, 0x5, 0x16, 0xc, 0x2, 0xce, 
       0xd6, 0x5, 0x18, 0xd, 0x2, 0xcf, 0xd6, 0x5, 0x24, 0x13, 0x2, 0xd0, 
       0xd6, 0x5, 0x1a, 0xe, 0x2, 0xd1, 0xd6, 0x5, 0x1c, 0xf, 0x2, 0xd2, 
       0xd6, 0x5, 0x1e, 0x10, 0x2, 0xd3, 0xd6, 0x5, 0x20, 0x11, 0x2, 0xd4, 
       0xd6, 0x5, 0x22, 0x12, 0x2, 0xd5, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd5, 
       0xce, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd0, 
       0x3, 0x2, 0x2, 0x2, 0xd5, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd2, 0x3, 
       0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd4, 0x3, 0x2, 
       0x2, 0x2, 0xd6, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x20, 
       0x2, 0x2, 0xd8, 0xd9, 0x7, 0x6a, 0x2, 0x2, 0xd9, 0xda, 0x9, 0x5, 
       0x2, 0x2, 0xda, 0x17, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x11, 
       0x2, 0x2, 0xdc, 0xdd, 0x7, 0x6a, 0x2, 0x2, 0xdd, 0xde, 0x9, 0x6, 
       0x2, 0x2, 0xde, 0x19, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x12, 
       0x2, 0x2, 0xe0, 0xe1, 0x7, 0x6a, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x66, 
       0x2, 0x2, 0xe2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x13, 
       0x2, 0x2, 0xe4, 0xe5, 0x7, 0x6a, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x66, 
       0x2, 0x2, 0xe6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x14, 
       0x2, 0x2, 0xe8, 0xe9, 0x7, 0x6a, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x66, 
       0x2, 0x2, 0xea, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x15, 
       0x2, 0x2, 0xec, 0xed, 0x7, 0x6a, 0x2, 0x2, 0xed, 0xee, 0x7, 0x67, 
       0x2, 0x2, 0xee, 0x21, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x16, 
       0x2, 0x2, 0xf0, 0xf1, 0x7, 0x6a, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x66, 
       0x2, 0x2, 0xf2, 0xf3, 0x7, 0x3, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x66, 
       0x2, 0x2, 0xf4, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x2a, 
       0x2, 0x2, 0xf6, 0xf7, 0x7, 0x6a, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x66, 
       0x2, 0x2, 0xf8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xf9, 0x121, 0x5, 0x28, 
       0x15, 0x2, 0xfa, 0x121, 0x5, 0x2a, 0x16, 0x2, 0xfb, 0x121, 0x5, 0x2c, 
       0x17, 0x2, 0xfc, 0x121, 0x5, 0x2e, 0x18, 0x2, 0xfd, 0x121, 0x5, 0x30, 
       0x19, 0x2, 0xfe, 0x121, 0x5, 0x32, 0x1a, 0x2, 0xff, 0x121, 0x5, 0x34, 
       0x1b, 0x2, 0x100, 0x121, 0x5, 0x36, 0x1c, 0x2, 0x101, 0x121, 0x5, 
       0x38, 0x1d, 0x2, 0x102, 0x121, 0x5, 0x3a, 0x1e, 0x2, 0x103, 0x121, 
       0x5, 0x42, 0x22, 0x2, 0x104, 0x121, 0x5, 0x3c, 0x1f, 0x2, 0x105, 
       0x121, 0x5, 0x3e, 0x20, 0x2, 0x106, 0x121, 0x5, 0x40, 0x21, 0x2, 
       0x107, 0x121, 0x5, 0x44, 0x23, 0x2, 0x108, 0x121, 0x5, 0x46, 0x24, 
       0x2, 0x109, 0x121, 0x5, 0x48, 0x25, 0x2, 0x10a, 0x121, 0x5, 0x4a, 
       0x26, 0x2, 0x10b, 0x121, 0x5, 0x4c, 0x27, 0x2, 0x10c, 0x121, 0x5, 
       0x4e, 0x28, 0x2, 0x10d, 0x121, 0x5, 0x50, 0x29, 0x2, 0x10e, 0x121, 
       0x5, 0x52, 0x2a, 0x2, 0x10f, 0x121, 0x5, 0x54, 0x2b, 0x2, 0x110, 
       0x121, 0x5, 0x56, 0x2c, 0x2, 0x111, 0x121, 0x5, 0x58, 0x2d, 0x2, 
       0x112, 0x121, 0x5, 0x5a, 0x2e, 0x2, 0x113, 0x121, 0x5, 0x5c, 0x2f, 
       0x2, 0x114, 0x121, 0x5, 0x5e, 0x30, 0x2, 0x115, 0x121, 0x5, 0x60, 
       0x31, 0x2, 0x116, 0x121, 0x5, 0x62, 0x32, 0x2, 0x117, 0x121, 0x5, 
       0x64, 0x33, 0x2, 0x118, 0x121, 0x5, 0x66, 0x34, 0x2, 0x119, 0x121, 
       0x5, 0x68, 0x35, 0x2, 0x11a, 0x121, 0x5, 0x6a, 0x36, 0x2, 0x11b, 
       0x121, 0x5, 0x6c, 0x37, 0x2, 0x11c, 0x121, 0x5, 0x6e, 0x38, 0x2, 
       0x11d, 0x121, 0x5, 0x70, 0x39, 0x2, 0x11e, 0x121, 0x5, 0x72, 0x3a, 
       0x2, 0x11f, 0x121, 0x5, 0x74, 0x3b, 0x2, 0x120, 0xf9, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x120, 0xfb, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x120, 0xfd, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x120, 0xff, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x100, 0x3, 0x2, 0x2, 0x2, 0x120, 0x101, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x102, 0x3, 0x2, 0x2, 0x2, 0x120, 0x103, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x104, 0x3, 0x2, 0x2, 0x2, 0x120, 0x105, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x106, 0x3, 0x2, 0x2, 0x2, 0x120, 0x107, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x108, 0x3, 0x2, 0x2, 0x2, 0x120, 0x109, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x120, 0x10b, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x120, 0x10d, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x10f, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x110, 0x3, 0x2, 0x2, 0x2, 0x120, 0x111, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x112, 0x3, 0x2, 0x2, 0x2, 0x120, 0x113, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x114, 0x3, 0x2, 0x2, 0x2, 0x120, 0x115, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x116, 0x3, 0x2, 0x2, 0x2, 0x120, 0x117, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x118, 0x3, 0x2, 0x2, 0x2, 0x120, 0x119, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11b, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11d, 0x3, 0x2, 0x2, 
       0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 
       0x2, 0x121, 0x27, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x7, 0x28, 0x2, 
       0x2, 0x123, 0x124, 0x7, 0x76, 0x2, 0x2, 0x124, 0x125, 0x7, 0x41, 
       0x2, 0x2, 0x125, 0x126, 0x7, 0x65, 0x2, 0x2, 0x126, 0x127, 0x7, 0x42, 
       0x2, 0x2, 0x127, 0x12a, 0x7, 0x65, 0x2, 0x2, 0x128, 0x129, 0x7, 0x43, 
       0x2, 0x2, 0x129, 0x12b, 0x7, 0x76, 0x2, 0x2, 0x12a, 0x128, 0x3, 0x2, 
       0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 
       0x2, 0x2, 0x12c, 0x12d, 0x7, 0x19, 0x2, 0x2, 0x12d, 0x12f, 0x7, 0x6d, 
       0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 
       0x2, 0x2, 0x12f, 0x29, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x29, 
       0x2, 0x2, 0x131, 0x132, 0x7, 0x76, 0x2, 0x2, 0x132, 0x133, 0x7, 0x3c, 
       0x2, 0x2, 0x133, 0x134, 0x7, 0x66, 0x2, 0x2, 0x134, 0x135, 0x7, 0x3b, 
       0x2, 0x2, 0x135, 0x136, 0x7, 0x66, 0x2, 0x2, 0x136, 0x13b, 0x3, 0x2, 
       0x2, 0x2, 0x137, 0x138, 0x7, 0x47, 0x2, 0x2, 0x138, 0x139, 0x7, 0x30, 
       0x2, 0x2, 0x139, 0x13a, 0x7, 0x66, 0x2, 0x2, 0x13a, 0x13c, 0x7, 0x66, 
       0x2, 0x2, 0x13b, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 
       0x2, 0x2, 0x13c, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x43, 
       0x2, 0x2, 0x13e, 0x140, 0x7, 0x76, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 
       0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 
       0x2, 0x2, 0x141, 0x142, 0x7, 0x19, 0x2, 0x2, 0x142, 0x144, 0x7, 0x6d, 
       0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 
       0x2, 0x2, 0x144, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x7, 0x2e, 
       0x2, 0x2, 0x146, 0x147, 0x7, 0x76, 0x2, 0x2, 0x147, 0x148, 0x7, 0x46, 
       0x2, 0x2, 0x148, 0x149, 0x7, 0x76, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x47, 
       0x2, 0x2, 0x14a, 0x14c, 0x7, 0x30, 0x2, 0x2, 0x14b, 0x14d, 0x7, 0x6b, 
       0x2, 0x2, 0x14c, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 
       0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x150, 0x7, 0x66, 
       0x2, 0x2, 0x14f, 0x151, 0x7, 0x6b, 0x2, 0x2, 0x150, 0x14f, 0x3, 0x2, 
       0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x3, 0x2, 
       0x2, 0x2, 0x152, 0x155, 0x7, 0x66, 0x2, 0x2, 0x153, 0x154, 0x7, 0x43, 
       0x2, 0x2, 0x154, 0x156, 0x7, 0x76, 0x2, 0x2, 0x155, 0x153, 0x3, 0x2, 
       0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x159, 0x3, 0x2, 
       0x2, 0x2, 0x157, 0x158, 0x7, 0x19, 0x2, 0x2, 0x158, 0x15a, 0x7, 0x6d, 
       0x2, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 
       0x2, 0x2, 0x15a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x2b, 
       0x2, 0x2, 0x15c, 0x15d, 0x7, 0x4, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x41, 
       0x2, 0x2, 0x15e, 0x15f, 0x7, 0x76, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x20, 
       0x2, 0x2, 0x160, 0x163, 0x7, 0xf, 0x2, 0x2, 0x161, 0x162, 0x7, 0x43, 
       0x2, 0x2, 0x162, 0x164, 0x7, 0x76, 0x2, 0x2, 0x163, 0x161, 0x3, 0x2, 
       0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x167, 0x3, 0x2, 
       0x2, 0x2, 0x165, 0x166, 0x7, 0x19, 0x2, 0x2, 0x166, 0x168, 0x7, 0x6d, 
       0x2, 0x2, 0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 0x2, 
       0x2, 0x2, 0x168, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x7, 0x2b, 
       0x2, 0x2, 0x16a, 0x16b, 0x7, 0x5, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x41, 
       0x2, 0x2, 0x16c, 0x16d, 0x7, 0x76, 0x2, 0x2, 0x16d, 0x16e, 0x7, 0x20, 
       0x2, 0x2, 0x16e, 0x172, 0x7, 0xe, 0x2, 0x2, 0x16f, 0x170, 0x7, 0x2d, 
       0x2, 0x2, 0x170, 0x171, 0x7, 0x66, 0x2, 0x2, 0x171, 0x173, 0x7, 0x66, 
       0x2, 0x2, 0x172, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x3, 0x2, 
       0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x7, 0x43, 
       0x2, 0x2, 0x175, 0x177, 0x7, 0x76, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 
       0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x3, 0x2, 
       0x2, 0x2, 0x178, 0x179, 0x7, 0x19, 0x2, 0x2, 0x179, 0x17b, 0x7, 0x6d, 
       0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 
       0x2, 0x2, 0x17b, 0x31, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x2f, 
       0x2, 0x2, 0x17d, 0x17e, 0x7, 0x76, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x44, 
       0x2, 0x2, 0x17f, 0x182, 0x7, 0x76, 0x2, 0x2, 0x180, 0x181, 0x7, 0x43, 
       0x2, 0x2, 0x181, 0x183, 0x7, 0x76, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 
       0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x186, 0x3, 0x2, 
       0x2, 0x2, 0x184, 0x185, 0x7, 0x19, 0x2, 0x2, 0x185, 0x187, 0x7, 0x6d, 
       0x2, 0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 
       0x2, 0x2, 0x187, 0x33, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 0x7, 0x37, 
       0x2, 0x2, 0x189, 0x18b, 0x7, 0x76, 0x2, 0x2, 0x18a, 0x189, 0x3, 0x2, 
       0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 0x2, 
       0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x190, 0x3, 0x2, 
       0x2, 0x2, 0x18e, 0x18f, 0x7, 0x43, 0x2, 0x2, 0x18f, 0x191, 0x7, 0x76, 
       0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 
       0x2, 0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x193, 0x7, 0x19, 
       0x2, 0x2, 0x193, 0x195, 0x7, 0x6d, 0x2, 0x2, 0x194, 0x192, 0x3, 0x2, 
       0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x35, 0x3, 0x2, 
       0x2, 0x2, 0x196, 0x197, 0x7, 0x34, 0x2, 0x2, 0x197, 0x198, 0x7, 0x76, 
       0x2, 0x2, 0x198, 0x19b, 0x7, 0x66, 0x2, 0x2, 0x199, 0x19a, 0x7, 0x43, 
       0x2, 0x2, 0x19a, 0x19c, 0x7, 0x76, 0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 
       0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19f, 0x3, 0x2, 
       0x2, 0x2, 0x19d, 0x19e, 0x7, 0x19, 0x2, 0x2, 0x19e, 0x1a0, 0x7, 0x6d, 
       0x2, 0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 
       0x2, 0x2, 0x1a0, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x7, 0x35, 
       0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x76, 0x2, 0x2, 0x1a3, 0x1a6, 0x7, 0x1d, 
       0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x43, 0x2, 0x2, 0x1a5, 0x1a7, 0x7, 0x76, 
       0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 
       0x2, 0x2, 0x1a7, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x19, 
       0x2, 0x2, 0x1a9, 0x1ab, 0x7, 0x6d, 0x2, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 
       0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x39, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x31, 
       0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x45, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x76, 
       0x2, 0x2, 0x1b0, 0x1b3, 0x9, 0x7, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x43, 
       0x2, 0x2, 0x1b2, 0x1b4, 0x7, 0x76, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 
       0x2, 0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b7, 0x3, 0x2, 
       0x2, 0x2, 0x1b5, 0x1b6, 0x7, 0x19, 0x2, 0x2, 0x1b6, 0x1b8, 0x7, 0x6d, 
       0x2, 0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 0x2, 
       0x2, 0x2, 0x1b8, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x39, 
       0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0x32, 0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x45, 
       0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x76, 0x2, 0x2, 0x1bd, 0x1c0, 0x9, 0x7, 
       0x2, 0x2, 0x1be, 0x1bf, 0x7, 0x43, 0x2, 0x2, 0x1bf, 0x1c1, 0x7, 0x76, 
       0x2, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x3, 0x2, 
       0x2, 0x2, 0x1c1, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x7, 0x19, 
       0x2, 0x2, 0x1c3, 0x1c5, 0x7, 0x6d, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 
       0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x3d, 0x3, 0x2, 
       0x2, 0x2, 0x1c6, 0x1c7, 0x7, 0x39, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x36, 
       0x2, 0x2, 0x1c8, 0x1c9, 0x7, 0x45, 0x2, 0x2, 0x1c9, 0x1cb, 0x7, 0x76, 
       0x2, 0x2, 0x1ca, 0x1cc, 0x7, 0x6b, 0x2, 0x2, 0x1cb, 0x1ca, 0x3, 0x2, 
       0x2, 0x2, 0x1cb, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 
       0x2, 0x2, 0x1cd, 0x1d0, 0x9, 0x7, 0x2, 0x2, 0x1ce, 0x1cf, 0x7, 0x43, 
       0x2, 0x2, 0x1cf, 0x1d1, 0x7, 0x76, 0x2, 0x2, 0x1d0, 0x1ce, 0x3, 0x2, 
       0x2, 0x2, 0x1d0, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d4, 0x3, 0x2, 
       0x2, 0x2, 0x1d2, 0x1d3, 0x7, 0x19, 0x2, 0x2, 0x1d3, 0x1d5, 0x7, 0x6d, 
       0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x3, 0x2, 
       0x2, 0x2, 0x1d5, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 0x7, 0x39, 
       0x2, 0x2, 0x1d7, 0x1d8, 0x7, 0x33, 0x2, 0x2, 0x1d8, 0x1d9, 0x7, 0x45, 
       0x2, 0x2, 0x1d9, 0x1db, 0x7, 0x76, 0x2, 0x2, 0x1da, 0x1dc, 0x7, 0x6b, 
       0x2, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x3, 0x2, 
       0x2, 0x2, 0x1dc, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1e0, 0x9, 0x7, 
       0x2, 0x2, 0x1de, 0x1df, 0x7, 0x43, 0x2, 0x2, 0x1df, 0x1e1, 0x7, 0x76, 
       0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3, 0x2, 
       0x2, 0x2, 0x1e1, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x7, 0x19, 
       0x2, 0x2, 0x1e3, 0x1e5, 0x7, 0x6d, 0x2, 0x2, 0x1e4, 0x1e2, 0x3, 0x2, 
       0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x41, 0x3, 0x2, 
       0x2, 0x2, 0x1e6, 0x1e7, 0x7, 0x39, 0x2, 0x2, 0x1e7, 0x1e8, 0x7, 0x2a, 
       0x2, 0x2, 0x1e8, 0x1e9, 0x7, 0x45, 0x2, 0x2, 0x1e9, 0x1ea, 0x7, 0x76, 
       0x2, 0x2, 0x1ea, 0x1ed, 0x7, 0x66, 0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x43, 
       0x2, 0x2, 0x1ec, 0x1ee, 0x7, 0x76, 0x2, 0x2, 0x1ed, 0x1eb, 0x3, 0x2, 
       0x2, 0x2, 0x1ed, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1f1, 0x3, 0x2, 
       0x2, 0x2, 0x1ef, 0x1f0, 0x7, 0x19, 0x2, 0x2, 0x1f0, 0x1f2, 0x7, 0x6d, 
       0x2, 0x2, 0x1f1, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f2, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x7, 0x39, 
       0x2, 0x2, 0x1f4, 0x1f5, 0x7, 0x3a, 0x2, 0x2, 0x1f5, 0x1f6, 0x7, 0x45, 
       0x2, 0x2, 0x1f6, 0x1f7, 0x7, 0x76, 0x2, 0x2, 0x1f7, 0x1fa, 0x7, 0x66, 
       0x2, 0x2, 0x1f8, 0x1f9, 0x7, 0x43, 0x2, 0x2, 0x1f9, 0x1fb, 0x7, 0x76, 
       0x2, 0x2, 0x1fa, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 0x2, 
       0x2, 0x2, 0x1fb, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x7, 0x19, 
       0x2, 0x2, 0x1fd, 0x1ff, 0x7, 0x6d, 0x2, 0x2, 0x1fe, 0x1fc, 0x3, 0x2, 
       0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x45, 0x3, 0x2, 
       0x2, 0x2, 0x200, 0x201, 0x7, 0x38, 0x2, 0x2, 0x201, 0x202, 0x7, 0x76, 
       0x2, 0x2, 0x202, 0x203, 0x7, 0x3c, 0x2, 0x2, 0x203, 0x204, 0x7, 0x66, 
       0x2, 0x2, 0x204, 0x205, 0x7, 0x3b, 0x2, 0x2, 0x205, 0x206, 0x7, 0x66, 
       0x2, 0x2, 0x206, 0x209, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x7, 0x43, 
       0x2, 0x2, 0x208, 0x20a, 0x7, 0x76, 0x2, 0x2, 0x209, 0x207, 0x3, 0x2, 
       0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20d, 0x3, 0x2, 
       0x2, 0x2, 0x20b, 0x20c, 0x7, 0x19, 0x2, 0x2, 0x20c, 0x20e, 0x7, 0x6d, 
       0x2, 0x2, 0x20d, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x3, 0x2, 
       0x2, 0x2, 0x20e, 0x47, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x210, 0x7, 0x2b, 
       0x2, 0x2, 0x210, 0x211, 0x7, 0x66, 0x2, 0x2, 0x211, 0x212, 0x7, 0x1b, 
       0x2, 0x2, 0x212, 0x213, 0x7, 0x41, 0x2, 0x2, 0x213, 0x214, 0x7, 0x76, 
       0x2, 0x2, 0x214, 0x215, 0x7, 0x19, 0x2, 0x2, 0x215, 0x216, 0x7, 0x6d, 
       0x2, 0x2, 0x216, 0x49, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x7, 0x2b, 
       0x2, 0x2, 0x218, 0x219, 0x7, 0x1c, 0x2, 0x2, 0x219, 0x21a, 0x7, 0x1a, 
       0x2, 0x2, 0x21a, 0x21b, 0x7, 0x66, 0x2, 0x2, 0x21b, 0x21c, 0x7, 0x41, 
       0x2, 0x2, 0x21c, 0x21d, 0x7, 0x76, 0x2, 0x2, 0x21d, 0x21e, 0x7, 0x19, 
       0x2, 0x2, 0x21e, 0x21f, 0x7, 0x6d, 0x2, 0x2, 0x21f, 0x4b, 0x3, 0x2, 
       0x2, 0x2, 0x220, 0x221, 0x7, 0x40, 0x2, 0x2, 0x221, 0x222, 0x7, 0x1b, 
       0x2, 0x2, 0x222, 0x223, 0x7, 0x6d, 0x2, 0x2, 0x223, 0x224, 0x7, 0x45, 
       0x2, 0x2, 0x224, 0x227, 0x7, 0x76, 0x2, 0x2, 0x225, 0x226, 0x7, 0x43, 
       0x2, 0x2, 0x226, 0x228, 0x7, 0x76, 0x2, 0x2, 0x227, 0x225, 0x3, 0x2, 
       0x2, 0x2, 0x227, 0x228, 0x3, 0x2, 0x2, 0x2, 0x228, 0x22b, 0x3, 0x2, 
       0x2, 0x2, 0x229, 0x22a, 0x7, 0x19, 0x2, 0x2, 0x22a, 0x22c, 0x7, 0x6d, 
       0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x3, 0x2, 
       0x2, 0x2, 0x22c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x7, 0x3d, 
       0x2, 0x2, 0x22e, 0x233, 0x7, 0x76, 0x2, 0x2, 0x22f, 0x230, 0x7, 0x3c, 
       0x2, 0x2, 0x230, 0x231, 0x7, 0x66, 0x2, 0x2, 0x231, 0x232, 0x7, 0x3b, 
       0x2, 0x2, 0x232, 0x234, 0x7, 0x66, 0x2, 0x2, 0x233, 0x22f, 0x3, 0x2, 
       0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 0x2, 0x234, 0x237, 0x3, 0x2, 
       0x2, 0x2, 0x235, 0x236, 0x7, 0x48, 0x2, 0x2, 0x236, 0x238, 0x9, 0x7, 
       0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 
       0x2, 0x2, 0x238, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x7, 0x43, 
       0x2, 0x2, 0x23a, 0x23c, 0x7, 0x76, 0x2, 0x2, 0x23b, 0x239, 0x3, 0x2, 
       0x2, 0x2, 0x23b, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23f, 0x3, 0x2, 
       0x2, 0x2, 0x23d, 0x23e, 0x7, 0x19, 0x2, 0x2, 0x23e, 0x240, 0x7, 0x6d, 
       0x2, 0x2, 0x23f, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x3, 0x2, 
       0x2, 0x2, 0x240, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 0x7, 0x3e, 
       0x2, 0x2, 0x242, 0x247, 0x7, 0x76, 0x2, 0x2, 0x243, 0x244, 0x7, 0x3c, 
       0x2, 0x2, 0x244, 0x245, 0x7, 0x66, 0x2, 0x2, 0x245, 0x246, 0x7, 0x3b, 
       0x2, 0x2, 0x246, 0x248, 0x7, 0x66, 0x2, 0x2, 0x247, 0x243, 0x3, 0x2, 
       0x2, 0x2, 0x247, 0x248, 0x3, 0x2, 0x2, 0x2, 0x248, 0x24b, 0x3, 0x2, 
       0x2, 0x2, 0x249, 0x24a, 0x7, 0x48, 0x2, 0x2, 0x24a, 0x24c, 0x9, 0x7, 
       0x2, 0x2, 0x24b, 0x249, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x3, 0x2, 
       0x2, 0x2, 0x24c, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x7, 0x43, 
       0x2, 0x2, 0x24e, 0x250, 0x7, 0x76, 0x2, 0x2, 0x24f, 0x24d, 0x3, 0x2, 
       0x2, 0x2, 0x24f, 0x250, 0x3, 0x2, 0x2, 0x2, 0x250, 0x253, 0x3, 0x2, 
       0x2, 0x2, 0x251, 0x252, 0x7, 0x19, 0x2, 0x2, 0x252, 0x254, 0x7, 0x6d, 
       0x2, 0x2, 0x253, 0x251, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x3, 0x2, 
       0x2, 0x2, 0x254, 0x51, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x7, 0x3f, 
       0x2, 0x2, 0x256, 0x259, 0x7, 0x76, 0x2, 0x2, 0x257, 0x258, 0x7, 0x43, 
       0x2, 0x2, 0x258, 0x25a, 0x7, 0x76, 0x2, 0x2, 0x259, 0x257, 0x3, 0x2, 
       0x2, 0x2, 0x259, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25d, 0x3, 0x2, 
       0x2, 0x2, 0x25b, 0x25c, 0x7, 0x19, 0x2, 0x2, 0x25c, 0x25e, 0x7, 0x6d, 
       0x2, 0x2, 0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 
       0x2, 0x2, 0x25e, 0x53, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x7, 0x49, 
       0x2, 0x2, 0x260, 0x261, 0x7, 0x4a, 0x2, 0x2, 0x261, 0x262, 0x7, 0x45, 
       0x2, 0x2, 0x262, 0x263, 0x7, 0x76, 0x2, 0x2, 0x263, 0x265, 0x7, 0x4b, 
       0x2, 0x2, 0x264, 0x266, 0x7, 0x6b, 0x2, 0x2, 0x265, 0x264, 0x3, 0x2, 
       0x2, 0x2, 0x265, 0x266, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 0x3, 0x2, 
       0x2, 0x2, 0x267, 0x268, 0x9, 0x7, 0x2, 0x2, 0x268, 0x26b, 0x3, 0x2, 
       0x2, 0x2, 0x269, 0x26a, 0x7, 0x43, 0x2, 0x2, 0x26a, 0x26c, 0x7, 0x76, 
       0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x3, 0x2, 
       0x2, 0x2, 0x26c, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x7, 0x19, 
       0x2, 0x2, 0x26e, 0x26f, 0x7, 0x6d, 0x2, 0x2, 0x26f, 0x55, 0x3, 0x2, 
       0x2, 0x2, 0x270, 0x271, 0x7, 0x4c, 0x2, 0x2, 0x271, 0x274, 0x7, 0x76, 
       0x2, 0x2, 0x272, 0x273, 0x7, 0x4d, 0x2, 0x2, 0x273, 0x275, 0x9, 0x7, 
       0x2, 0x2, 0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 
       0x2, 0x2, 0x275, 0x278, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x7, 0x4e, 
       0x2, 0x2, 0x277, 0x279, 0x9, 0x7, 0x2, 0x2, 0x278, 0x276, 0x3, 0x2, 
       0x2, 0x2, 0x278, 0x279, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27c, 0x3, 0x2, 
       0x2, 0x2, 0x27a, 0x27b, 0x7, 0x4f, 0x2, 0x2, 0x27b, 0x27d, 0x9, 0x7, 
       0x2, 0x2, 0x27c, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x3, 0x2, 
       0x2, 0x2, 0x27d, 0x280, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x7, 0x43, 
       0x2, 0x2, 0x27f, 0x281, 0x7, 0x76, 0x2, 0x2, 0x280, 0x27e, 0x3, 0x2, 
       0x2, 0x2, 0x280, 0x281, 0x3, 0x2, 0x2, 0x2, 0x281, 0x284, 0x3, 0x2, 
       0x2, 0x2, 0x282, 0x283, 0x7, 0x19, 0x2, 0x2, 0x283, 0x285, 0x7, 0x6d, 
       0x2, 0x2, 0x284, 0x282, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x3, 0x2, 
       0x2, 0x2, 0x285, 0x57, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x7, 0x39, 
       0x2, 0x2, 0x287, 0x288, 0x7, 0x51, 0x2, 0x2, 0x288, 0x289, 0x7, 0x45, 
       0x2, 0x2, 0x289, 0x28f, 0x7, 0x76, 0x2, 0x2, 0x28a, 0x28c, 0x7, 0x52, 
       0x2, 0x2, 0x28b, 0x28d, 0x7, 0x6b, 0x2, 0x2, 0x28c, 0x28b, 0x3, 0x2, 
       0x2, 0x2, 0x28c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 
       0x2, 0x2, 0x28e, 0x290, 0x9, 0x7, 0x2, 0x2, 0x28f, 0x28a, 0x3, 0x2, 
       0x2, 0x2, 0x28f, 0x290, 0x3, 0x2, 0x2, 0x2, 0x290, 0x293, 0x3, 0x2, 
       0x2, 0x2, 0x291, 0x292, 0x7, 0x53, 0x2, 0x2, 0x292, 0x294, 0x9, 0x7, 
       0x2, 0x2, 0x293, 0x291, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 
       0x2, 0x2, 0x294, 0x297, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 0x7, 0x43, 
       0x2, 0x2, 0x296, 0x298, 0x7, 0x76, 0x2, 0x2, 0x297, 0x295, 0x3, 0x2, 
       0x2, 0x2, 0x297, 0x298, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x3, 0x2, 
       0x2, 0x2, 0x299, 0x29a, 0x7, 0x19, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x6d, 
       0x2, 0x2, 0x29b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x39, 
       0x2, 0x2, 0x29d, 0x29e, 0x7, 0x50, 0x2, 0x2, 0x29e, 0x29f, 0x7, 0x45, 
       0x2, 0x2, 0x29f, 0x2a5, 0x7, 0x76, 0x2, 0x2, 0x2a0, 0x2a2, 0x7, 0x52, 
       0x2, 0x2, 0x2a1, 0x2a3, 0x7, 0x6b, 0x2, 0x2, 0x2a2, 0x2a1, 0x3, 0x2, 
       0x2, 0x2, 0x2a2, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 0x3, 0x2, 
       0x2, 0x2, 0x2a4, 0x2a6, 0x9, 0x7, 0x2, 0x2, 0x2a5, 0x2a0, 0x3, 0x2, 
       0x2, 0x2, 0x2a5, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a9, 0x3, 0x2, 
       0x2, 0x2, 0x2a7, 0x2a8, 0x7, 0x53, 0x2, 0x2, 0x2a8, 0x2aa, 0x9, 0x7, 
       0x2, 0x2, 0x2a9, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0x3, 0x2, 
       0x2, 0x2, 0x2aa, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ac, 0x7, 0x43, 
       0x2, 0x2, 0x2ac, 0x2ae, 0x7, 0x76, 0x2, 0x2, 0x2ad, 0x2ab, 0x3, 0x2, 
       0x2, 0x2, 0x2ad, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 0x3, 0x2, 
       0x2, 0x2, 0x2af, 0x2b0, 0x7, 0x19, 0x2, 0x2, 0x2b0, 0x2b1, 0x7, 0x6d, 
       0x2, 0x2, 0x2b1, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x7, 0x54, 
       0x2, 0x2, 0x2b3, 0x2b4, 0x7, 0x55, 0x2, 0x2, 0x2b4, 0x2b5, 0x7, 0x45, 
       0x2, 0x2, 0x2b5, 0x2b9, 0x7, 0x76, 0x2, 0x2, 0x2b6, 0x2b7, 0x7, 0x60, 
       0x2, 0x2, 0x2b7, 0x2b8, 0x7, 0x75, 0x2, 0x2, 0x2b8, 0x2ba, 0x7, 0x75, 
       0x2, 0x2, 0x2b9, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x3, 0x2, 
       0x2, 0x2, 0x2ba, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x3c, 
       0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x66, 0x2, 0x2, 0x2bd, 0x2be, 0x7, 0x3b, 
       0x2, 0x2, 0x2be, 0x2c0, 0x7, 0x66, 0x2, 0x2, 0x2bf, 0x2bb, 0x3, 0x2, 
       0x2, 0x2, 0x2bf, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c3, 0x3, 0x2, 
       0x2, 0x2, 0x2c1, 0x2c2, 0x7, 0x43, 0x2, 0x2, 0x2c2, 0x2c4, 0x7, 0x76, 
       0x2, 0x2, 0x2c3, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x3, 0x2, 
       0x2, 0x2, 0x2c4, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x19, 
       0x2, 0x2, 0x2c6, 0x2c8, 0x7, 0x6d, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 0x2, 
       0x2, 0x2, 0x2c7, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x5d, 0x3, 0x2, 
       0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0x54, 0x2, 0x2, 0x2ca, 0x2cb, 0x7, 0x4, 
       0x2, 0x2, 0x2cb, 0x2cc, 0x7, 0x56, 0x2, 0x2, 0x2cc, 0x2cd, 0x7, 0x45, 
       0x2, 0x2, 0x2cd, 0x2ce, 0x7, 0x76, 0x2, 0x2, 0x2ce, 0x2cf, 0x7, 0x57, 
       0x2, 0x2, 0x2cf, 0x2d0, 0x7, 0x58, 0x2, 0x2, 0x2d0, 0x2d1, 0x9, 0x8, 
       0x2, 0x2, 0x2d1, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d3, 0x7, 0x43, 
       0x2, 0x2, 0x2d3, 0x2d5, 0x7, 0x76, 0x2, 0x2, 0x2d4, 0x2d2, 0x3, 0x2, 
       0x2, 0x2, 0x2d4, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d8, 0x3, 0x2, 
       0x2, 0x2, 0x2d6, 0x2d7, 0x7, 0x19, 0x2, 0x2, 0x2d7, 0x2d9, 0x7, 0x6d, 
       0x2, 0x2, 0x2d8, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d9, 0x3, 0x2, 
       0x2, 0x2, 0x2d9, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x7, 0x54, 
       0x2, 0x2, 0x2db, 0x2dc, 0x7, 0x59, 0x2, 0x2, 0x2dc, 0x2dd, 0x7, 0x45, 
       0x2, 0x2, 0x2dd, 0x2e0, 0x7, 0x76, 0x2, 0x2, 0x2de, 0x2df, 0x7, 0x43, 
       0x2, 0x2, 0x2df, 0x2e1, 0x7, 0x76, 0x2, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 
       0x2, 0x2, 0x2e0, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e4, 0x3, 0x2, 
       0x2, 0x2, 0x2e2, 0x2e3, 0x7, 0x19, 0x2, 0x2, 0x2e3, 0x2e5, 0x7, 0x6d, 
       0x2, 0x2, 0x2e4, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0x3, 0x2, 
       0x2, 0x2, 0x2e5, 0x61, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 0x7, 0x54, 
       0x2, 0x2, 0x2e7, 0x2e8, 0x7, 0x4, 0x2, 0x2, 0x2e8, 0x2e9, 0x7, 0x5a, 
       0x2, 0x2, 0x2e9, 0x2ea, 0x7, 0x45, 0x2, 0x2, 0x2ea, 0x2ee, 0x7, 0x76, 
       0x2, 0x2, 0x2eb, 0x2ec, 0x7, 0x5b, 0x2, 0x2, 0x2ec, 0x2ed, 0x7, 0x58, 
       0x2, 0x2, 0x2ed, 0x2ef, 0x9, 0x9, 0x2, 0x2, 0x2ee, 0x2eb, 0x3, 0x2, 
       0x2, 0x2, 0x2ee, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f2, 0x3, 0x2, 
       0x2, 0x2, 0x2f0, 0x2f1, 0x7, 0x43, 0x2, 0x2, 0x2f1, 0x2f3, 0x7, 0x76, 
       0x2, 0x2, 0x2f2, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x3, 0x2, 
       0x2, 0x2, 0x2f3, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f5, 0x7, 0x19, 
       0x2, 0x2, 0x2f5, 0x2f7, 0x7, 0x6d, 0x2, 0x2, 0x2f6, 0x2f4, 0x3, 0x2, 
       0x2, 0x2, 0x2f6, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x63, 0x3, 0x2, 
       0x2, 0x2, 0x2f8, 0x2f9, 0x7, 0x54, 0x2, 0x2, 0x2f9, 0x2fa, 0x7, 0x5c, 
       0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0x45, 0x2, 0x2, 0x2fb, 0x2fe, 0x7, 0x76, 
       0x2, 0x2, 0x2fc, 0x2fd, 0x7, 0x43, 0x2, 0x2, 0x2fd, 0x2ff, 0x7, 0x76, 
       0x2, 0x2, 0x2fe, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2ff, 0x3, 0x2, 
       0x2, 0x2, 0x2ff, 0x302, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x7, 0x19, 
       0x2, 0x2, 0x301, 0x303, 0x7, 0x6d, 0x2, 0x2, 0x302, 0x300, 0x3, 0x2, 
       0x2, 0x2, 0x302, 0x303, 0x3, 0x2, 0x2, 0x2, 0x303, 0x65, 0x3, 0x2, 
       0x2, 0x2, 0x304, 0x305, 0x7, 0x54, 0x2, 0x2, 0x305, 0x306, 0x7, 0x5d, 
       0x2, 0x2, 0x306, 0x307, 0x7, 0x45, 0x2, 0x2, 0x307, 0x30b, 0x7, 0x76, 
       0x2, 0x2, 0x308, 0x309, 0x7, 0x57, 0x2, 0x2, 0x309, 0x30a, 0x7, 0x58, 
       0x2, 0x2, 0x30a, 0x30c, 0x9, 0xa, 0x2, 0x2, 0x30b, 0x308, 0x3, 0x2, 
       0x2, 0x2, 0x30b, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x310, 0x3, 0x2, 
       0x2, 0x2, 0x30d, 0x30e, 0x7, 0x60, 0x2, 0x2, 0x30e, 0x30f, 0x7, 0x75, 
       0x2, 0x2, 0x30f, 0x311, 0x7, 0x75, 0x2, 0x2, 0x310, 0x30d, 0x3, 0x2, 
       0x2, 0x2, 0x310, 0x311, 0x3, 0x2, 0x2, 0x2, 0x311, 0x315, 0x3, 0x2, 
       0x2, 0x2, 0x312, 0x313, 0x7, 0x61, 0x2, 0x2, 0x313, 0x314, 0x7, 0x58, 
       0x2, 0x2, 0x314, 0x316, 0x9, 0xb, 0x2, 0x2, 0x315, 0x312, 0x3, 0x2, 
       0x2, 0x2, 0x315, 0x316, 0x3, 0x2, 0x2, 0x2, 0x316, 0x319, 0x3, 0x2, 
       0x2, 0x2, 0x317, 0x318, 0x7, 0x43, 0x2, 0x2, 0x318, 0x31a, 0x7, 0x76, 
       0x2, 0x2, 0x319, 0x317, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31a, 0x3, 0x2, 
       0x2, 0x2, 0x31a, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x7, 0x19, 
       0x2, 0x2, 0x31c, 0x31e, 0x7, 0x6d, 0x2, 0x2, 0x31d, 0x31b, 0x3, 0x2, 
       0x2, 0x2, 0x31d, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x67, 0x3, 0x2, 
       0x2, 0x2, 0x31f, 0x320, 0x7, 0x54, 0x2, 0x2, 0x320, 0x321, 0x7, 0x5e, 
       0x2, 0x2, 0x321, 0x322, 0x7, 0x45, 0x2, 0x2, 0x322, 0x325, 0x7, 0x76, 
       0x2, 0x2, 0x323, 0x324, 0x7, 0x43, 0x2, 0x2, 0x324, 0x326, 0x7, 0x76, 
       0x2, 0x2, 0x325, 0x323, 0x3, 0x2, 0x2, 0x2, 0x325, 0x326, 0x3, 0x2, 
       0x2, 0x2, 0x326, 0x329, 0x3, 0x2, 0x2, 0x2, 0x327, 0x328, 0x7, 0x19, 
       0x2, 0x2, 0x328, 0x32a, 0x7, 0x6d, 0x2, 0x2, 0x329, 0x327, 0x3, 0x2, 
       0x2, 0x2, 0x329, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x69, 0x3, 0x2, 
       0x2, 0x2, 0x32b, 0x32c, 0x7, 0x54, 0x2, 0x2, 0x32c, 0x32d, 0x7, 0x5f, 
       0x2, 0x2, 0x32d, 0x32e, 0x7, 0x45, 0x2, 0x2, 0x32e, 0x32f, 0x7, 0x76, 
       0x2, 0x2, 0x32f, 0x330, 0x7, 0x57, 0x2, 0x2, 0x330, 0x331, 0x7, 0x58, 
       0x2, 0x2, 0x331, 0x332, 0x9, 0xb, 0x2, 0x2, 0x332, 0x335, 0x3, 0x2, 
       0x2, 0x2, 0x333, 0x334, 0x7, 0x43, 0x2, 0x2, 0x334, 0x336, 0x7, 0x76, 
       0x2, 0x2, 0x335, 0x333, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x3, 0x2, 
       0x2, 0x2, 0x336, 0x339, 0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 0x7, 0x19, 
       0x2, 0x2, 0x338, 0x33a, 0x7, 0x6d, 0x2, 0x2, 0x339, 0x337, 0x3, 0x2, 
       0x2, 0x2, 0x339, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x6b, 0x3, 0x2, 
       0x2, 0x2, 0x33b, 0x33c, 0x7, 0x54, 0x2, 0x2, 0x33c, 0x33d, 0x7, 0x3a, 
       0x2, 0x2, 0x33d, 0x33e, 0x7, 0x45, 0x2, 0x2, 0x33e, 0x341, 0x7, 0x76, 
       0x2, 0x2, 0x33f, 0x340, 0x7, 0x43, 0x2, 0x2, 0x340, 0x342, 0x7, 0x76, 
       0x2, 0x2, 0x341, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x341, 0x342, 0x3, 0x2, 
       0x2, 0x2, 0x342, 0x345, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0x7, 0x19, 
       0x2, 0x2, 0x344, 0x346, 0x7, 0x6d, 0x2, 0x2, 0x345, 0x343, 0x3, 0x2, 
       0x2, 0x2, 0x345, 0x346, 0x3, 0x2, 0x2, 0x2, 0x346, 0x6d, 0x3, 0x2, 
       0x2, 0x2, 0x347, 0x348, 0x7, 0x38, 0x2, 0x2, 0x348, 0x349, 0x7, 0x1e, 
       0x2, 0x2, 0x349, 0x34a, 0x7, 0x1f, 0x2, 0x2, 0x34a, 0x34d, 0x7, 0x76, 
       0x2, 0x2, 0x34b, 0x34c, 0x7, 0x43, 0x2, 0x2, 0x34c, 0x34e, 0x7, 0x76, 
       0x2, 0x2, 0x34d, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34e, 0x3, 0x2, 
       0x2, 0x2, 0x34e, 0x351, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x7, 0x19, 
       0x2, 0x2, 0x350, 0x352, 0x7, 0x6d, 0x2, 0x2, 0x351, 0x34f, 0x3, 0x2, 
       0x2, 0x2, 0x351, 0x352, 0x3, 0x2, 0x2, 0x2, 0x352, 0x6f, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x354, 0x7, 0x62, 0x2, 0x2, 0x354, 0x357, 0x7, 0x76, 
       0x2, 0x2, 0x355, 0x356, 0x7, 0x48, 0x2, 0x2, 0x356, 0x358, 0x9, 0x7, 
       0x2, 0x2, 0x357, 0x355, 0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 0x3, 0x2, 
       0x2, 0x2, 0x358, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 0x7, 0x43, 
       0x2, 0x2, 0x35a, 0x35c, 0x7, 0x76, 0x2, 0x2, 0x35b, 0x359, 0x3, 0x2, 
       0x2, 0x2, 0x35b, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35f, 0x3, 0x2, 
       0x2, 0x2, 0x35d, 0x35e, 0x7, 0x19, 0x2, 0x2, 0x35e, 0x360, 0x7, 0x6d, 
       0x2, 0x2, 0x35f, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x360, 0x3, 0x2, 
       0x2, 0x2, 0x360, 0x71, 0x3, 0x2, 0x2, 0x2, 0x361, 0x362, 0x7, 0x4b, 
       0x2, 0x2, 0x362, 0x364, 0x7, 0x5, 0x2, 0x2, 0x363, 0x365, 0x7, 0x66, 
       0x2, 0x2, 0x364, 0x363, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x3, 0x2, 
       0x2, 0x2, 0x365, 0x366, 0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x7, 0x45, 
       0x2, 0x2, 0x367, 0x36a, 0x7, 0x76, 0x2, 0x2, 0x368, 0x369, 0x7, 0x43, 
       0x2, 0x2, 0x369, 0x36b, 0x7, 0x76, 0x2, 0x2, 0x36a, 0x368, 0x3, 0x2, 
       0x2, 0x2, 0x36a, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36e, 0x3, 0x2, 
       0x2, 0x2, 0x36c, 0x36d, 0x7, 0x19, 0x2, 0x2, 0x36d, 0x36f, 0x7, 0x6d, 
       0x2, 0x2, 0x36e, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36f, 0x3, 0x2, 
       0x2, 0x2, 0x36f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x7, 0x63, 
       0x2, 0x2, 0x371, 0x372, 0x7, 0x1b, 0x2, 0x2, 0x372, 0x373, 0x7, 0x6d, 
       0x2, 0x2, 0x373, 0x374, 0x7, 0x64, 0x2, 0x2, 0x374, 0x377, 0x7, 0x76, 
       0x2, 0x2, 0x375, 0x376, 0x7, 0x43, 0x2, 0x2, 0x376, 0x378, 0x7, 0x76, 
       0x2, 0x2, 0x377, 0x375, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 0x3, 0x2, 
       0x2, 0x2, 0x378, 0x379, 0x3, 0x2, 0x2, 0x2, 0x379, 0x37a, 0x7, 0x19, 
       0x2, 0x2, 0x37a, 0x37b, 0x7, 0x6d, 0x2, 0x2, 0x37b, 0x75, 0x3, 0x2, 
       0x2, 0x2, 0x71, 0x7c, 0x80, 0x85, 0x8d, 0x8f, 0x94, 0x9d, 0x9f, 0xb8, 
       0xc3, 0xd5, 0x120, 0x12a, 0x12e, 0x13b, 0x13f, 0x143, 0x14c, 0x150, 
       0x155, 0x159, 0x163, 0x167, 0x172, 0x176, 0x17a, 0x182, 0x186, 0x18c, 
       0x190, 0x194, 0x19b, 0x19f, 0x1a6, 0x1aa, 0x1b3, 0x1b7, 0x1c0, 0x1c4, 
       0x1cb, 0x1d0, 0x1d4, 0x1db, 0x1e0, 0x1e4, 0x1ed, 0x1f1, 0x1fa, 0x1fe, 
       0x209, 0x20d, 0x227, 0x22b, 0x233, 0x237, 0x23b, 0x23f, 0x247, 0x24b, 
       0x24f, 0x253, 0x259, 0x25d, 0x265, 0x26b, 0x274, 0x278, 0x27c, 0x280, 
       0x284, 0x28c, 0x28f, 0x293, 0x297, 0x2a2, 0x2a5, 0x2a9, 0x2ad, 0x2b9, 
       0x2bf, 0x2c3, 0x2c7, 0x2d4, 0x2d8, 0x2e0, 0x2e4, 0x2ee, 0x2f2, 0x2f6, 
       0x2fe, 0x302, 0x30b, 0x310, 0x315, 0x319, 0x31d, 0x325, 0x329, 0x335, 
       0x339, 0x341, 0x345, 0x34d, 0x351, 0x357, 0x35b, 0x35f, 0x364, 0x36a, 
       0x36e, 0x377, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FrameParser::Initializer FrameParser::_init;
