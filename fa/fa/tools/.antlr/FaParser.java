// Generated from e:\GitHub\_\fa\fa\fa\tools\Fa.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FaParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		AImport=1, ALib=2, Break=3, CC__Cdecl=4, CC__FastCall=5, CC__StdCall=6, 
		Continue=7, Class=8, Const=9, Else=10, Enum=11, FaMain=12, For=13, If=14, 
		Interface=15, Internal=16, New=17, Public=18, Protected=19, Private=20, 
		Return=21, Signed=22, Static=23, Step=24, Struct=25, Unsigned=26, Use=27, 
		While=28, Assign=29, ReverseOp=30, AddAddOp=31, SubSubOp=32, PointPoint=33, 
		PointOp=34, AddOp=35, SubOp=36, StarOp=37, DivOp=38, ModOp=39, OrOp=40, 
		AndOp=41, XorOp=42, Qus=43, Comma=44, ColonColon=45, Colon=46, Semi=47, 
		Exclam=48, QuotFangL=49, QuotFangR=50, QuotJianL=51, QuotJianR=52, QuotHuaL=53, 
		QuotHuaR=54, QuotYuanL=55, QuotYuanR=56, BoolLiteral=57, IntLiteral=58, 
		FloatLiteral=59, String1Literal=60, Id=61, Comment1=62, Comment2=63, WS=64;
	public static final int
		RULE_addAssign = 0, RULE_subAssign = 1, RULE_starAssign = 2, RULE_divAssign = 3, 
		RULE_modAssign = 4, RULE_orAssign = 5, RULE_andAssign = 6, RULE_xorAssign = 7, 
		RULE_qusQusAssign = 8, RULE_starStarAssign = 9, RULE_andAndAssign = 10, 
		RULE_orOrAssign = 11, RULE_shiftLAssign = 12, RULE_shiftRAssign = 13, 
		RULE_allAssign = 14, RULE_qusQusOp = 15, RULE_starStarOp = 16, RULE_andAndOp = 17, 
		RULE_orOrOp = 18, RULE_shiftLOp = 19, RULE_shiftROp = 20, RULE_ltOp = 21, 
		RULE_ltEqualOp = 22, RULE_gtOp = 23, RULE_gtEqualOp = 24, RULE_equalOp = 25, 
		RULE_notEqualOp = 26, RULE_exprFuncDef = 27, RULE_selfOp2 = 28, RULE_compareOp2 = 29, 
		RULE_changeOp2 = 30, RULE_allOp2 = 31, RULE_intNum = 32, RULE_floatNum = 33, 
		RULE_literal = 34, RULE_ids = 35, RULE_typeAfter = 36, RULE_type = 37, 
		RULE_typeNewable = 38, RULE_typeVar = 39, RULE_typeVarList = 40, RULE_quotStmtPart = 41, 
		RULE_quotStmtExpr = 42, RULE_ifStmt = 43, RULE_ifExpr = 44, RULE_whileStmt = 45, 
		RULE_numIterStmt = 46, RULE_quotExpr = 47, RULE_exprOpt = 48, RULE_newExprItem = 49, 
		RULE_newExpr = 50, RULE_arrayExpr1 = 51, RULE_arrayExpr2 = 52, RULE_strongExprBase = 53, 
		RULE_strongExprPrefix = 54, RULE_strongExprSuffix = 55, RULE_strongExpr = 56, 
		RULE_middleExpr = 57, RULE_expr = 58, RULE_tmpAssignExpr = 59, RULE_defVarStmt = 60, 
		RULE_useStmt = 61, RULE_normalStmt = 62, RULE_stmt = 63, RULE_publicLevel = 64, 
		RULE_classParent = 65, RULE_classType = 66, RULE_classStmt = 67, RULE_classVarExtFunc = 68, 
		RULE_classVarExt = 69, RULE_classVar = 70, RULE_classFuncName = 71, RULE_classFuncBody = 72, 
		RULE_classFunc = 73, RULE_enumAtom = 74, RULE_callConvention = 75, RULE_importStmt = 76, 
		RULE_libStmt = 77, RULE_importBlock = 78, RULE_faMainFuncBlock = 79, RULE_program = 80;
	private static String[] makeRuleNames() {
		return new String[] {
			"addAssign", "subAssign", "starAssign", "divAssign", "modAssign", "orAssign", 
			"andAssign", "xorAssign", "qusQusAssign", "starStarAssign", "andAndAssign", 
			"orOrAssign", "shiftLAssign", "shiftRAssign", "allAssign", "qusQusOp", 
			"starStarOp", "andAndOp", "orOrOp", "shiftLOp", "shiftROp", "ltOp", "ltEqualOp", 
			"gtOp", "gtEqualOp", "equalOp", "notEqualOp", "exprFuncDef", "selfOp2", 
			"compareOp2", "changeOp2", "allOp2", "intNum", "floatNum", "literal", 
			"ids", "typeAfter", "type", "typeNewable", "typeVar", "typeVarList", 
			"quotStmtPart", "quotStmtExpr", "ifStmt", "ifExpr", "whileStmt", "numIterStmt", 
			"quotExpr", "exprOpt", "newExprItem", "newExpr", "arrayExpr1", "arrayExpr2", 
			"strongExprBase", "strongExprPrefix", "strongExprSuffix", "strongExpr", 
			"middleExpr", "expr", "tmpAssignExpr", "defVarStmt", "useStmt", "normalStmt", 
			"stmt", "publicLevel", "classParent", "classType", "classStmt", "classVarExtFunc", 
			"classVarExt", "classVar", "classFuncName", "classFuncBody", "classFunc", 
			"enumAtom", "callConvention", "importStmt", "libStmt", "importBlock", 
			"faMainFuncBlock", "program"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'@import'", "'@lib'", "'break'", "'__cdecl'", "'__fastcall'", 
			"'__stdcall'", "'continue'", "'class'", "'const'", "'else'", "'enum'", 
			"'FaMain'", "'for'", "'if'", "'interface'", "'internal'", "'new'", "'public'", 
			"'protected'", "'private'", "'return'", "'signed'", "'static'", "'step'", 
			"'struct'", "'unsigned'", "'use'", "'while'", "'='", "'~'", "'++'", "'--'", 
			"'..'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "'^'", 
			"'?'", "','", "'::'", "':'", "';'", "'!'", "'['", "']'", "'<'", "'>'", 
			"'{'", "'}'", "'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "AImport", "ALib", "Break", "CC__Cdecl", "CC__FastCall", "CC__StdCall", 
			"Continue", "Class", "Const", "Else", "Enum", "FaMain", "For", "If", 
			"Interface", "Internal", "New", "Public", "Protected", "Private", "Return", 
			"Signed", "Static", "Step", "Struct", "Unsigned", "Use", "While", "Assign", 
			"ReverseOp", "AddAddOp", "SubSubOp", "PointPoint", "PointOp", "AddOp", 
			"SubOp", "StarOp", "DivOp", "ModOp", "OrOp", "AndOp", "XorOp", "Qus", 
			"Comma", "ColonColon", "Colon", "Semi", "Exclam", "QuotFangL", "QuotFangR", 
			"QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", "QuotYuanR", 
			"BoolLiteral", "IntLiteral", "FloatLiteral", "String1Literal", "Id", 
			"Comment1", "Comment2", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Fa.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public FaParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class AddAssignContext extends ParserRuleContext {
		public TerminalNode AddOp() { return getToken(FaParser.AddOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public AddAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_addAssign; }
	}

	public final AddAssignContext addAssign() throws RecognitionException {
		AddAssignContext _localctx = new AddAssignContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_addAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(162);
			match(AddOp);
			setState(163);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SubAssignContext extends ParserRuleContext {
		public TerminalNode SubOp() { return getToken(FaParser.SubOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public SubAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_subAssign; }
	}

	public final SubAssignContext subAssign() throws RecognitionException {
		SubAssignContext _localctx = new SubAssignContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_subAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(165);
			match(SubOp);
			setState(166);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StarAssignContext extends ParserRuleContext {
		public TerminalNode StarOp() { return getToken(FaParser.StarOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public StarAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_starAssign; }
	}

	public final StarAssignContext starAssign() throws RecognitionException {
		StarAssignContext _localctx = new StarAssignContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_starAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(168);
			match(StarOp);
			setState(169);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DivAssignContext extends ParserRuleContext {
		public TerminalNode DivOp() { return getToken(FaParser.DivOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public DivAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_divAssign; }
	}

	public final DivAssignContext divAssign() throws RecognitionException {
		DivAssignContext _localctx = new DivAssignContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_divAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(171);
			match(DivOp);
			setState(172);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ModAssignContext extends ParserRuleContext {
		public TerminalNode ModOp() { return getToken(FaParser.ModOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public ModAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_modAssign; }
	}

	public final ModAssignContext modAssign() throws RecognitionException {
		ModAssignContext _localctx = new ModAssignContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_modAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(174);
			match(ModOp);
			setState(175);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OrAssignContext extends ParserRuleContext {
		public TerminalNode OrOp() { return getToken(FaParser.OrOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public OrAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_orAssign; }
	}

	public final OrAssignContext orAssign() throws RecognitionException {
		OrAssignContext _localctx = new OrAssignContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_orAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(177);
			match(OrOp);
			setState(178);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AndAssignContext extends ParserRuleContext {
		public TerminalNode AndOp() { return getToken(FaParser.AndOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public AndAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_andAssign; }
	}

	public final AndAssignContext andAssign() throws RecognitionException {
		AndAssignContext _localctx = new AndAssignContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_andAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(180);
			match(AndOp);
			setState(181);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class XorAssignContext extends ParserRuleContext {
		public TerminalNode XorOp() { return getToken(FaParser.XorOp, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public XorAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_xorAssign; }
	}

	public final XorAssignContext xorAssign() throws RecognitionException {
		XorAssignContext _localctx = new XorAssignContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_xorAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(183);
			match(XorOp);
			setState(184);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class QusQusAssignContext extends ParserRuleContext {
		public QusQusOpContext qusQusOp() {
			return getRuleContext(QusQusOpContext.class,0);
		}
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public QusQusAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qusQusAssign; }
	}

	public final QusQusAssignContext qusQusAssign() throws RecognitionException {
		QusQusAssignContext _localctx = new QusQusAssignContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_qusQusAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(186);
			qusQusOp();
			setState(187);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StarStarAssignContext extends ParserRuleContext {
		public StarStarOpContext starStarOp() {
			return getRuleContext(StarStarOpContext.class,0);
		}
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public StarStarAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_starStarAssign; }
	}

	public final StarStarAssignContext starStarAssign() throws RecognitionException {
		StarStarAssignContext _localctx = new StarStarAssignContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_starStarAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(189);
			starStarOp();
			setState(190);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AndAndAssignContext extends ParserRuleContext {
		public AndAndOpContext andAndOp() {
			return getRuleContext(AndAndOpContext.class,0);
		}
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public AndAndAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_andAndAssign; }
	}

	public final AndAndAssignContext andAndAssign() throws RecognitionException {
		AndAndAssignContext _localctx = new AndAndAssignContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_andAndAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(192);
			andAndOp();
			setState(193);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OrOrAssignContext extends ParserRuleContext {
		public OrOrOpContext orOrOp() {
			return getRuleContext(OrOrOpContext.class,0);
		}
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public OrOrAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_orOrAssign; }
	}

	public final OrOrAssignContext orOrAssign() throws RecognitionException {
		OrOrAssignContext _localctx = new OrOrAssignContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_orOrAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(195);
			orOrOp();
			setState(196);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ShiftLAssignContext extends ParserRuleContext {
		public ShiftLOpContext shiftLOp() {
			return getRuleContext(ShiftLOpContext.class,0);
		}
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public ShiftLAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shiftLAssign; }
	}

	public final ShiftLAssignContext shiftLAssign() throws RecognitionException {
		ShiftLAssignContext _localctx = new ShiftLAssignContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_shiftLAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(198);
			shiftLOp();
			setState(199);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ShiftRAssignContext extends ParserRuleContext {
		public ShiftROpContext shiftROp() {
			return getRuleContext(ShiftROpContext.class,0);
		}
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public ShiftRAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shiftRAssign; }
	}

	public final ShiftRAssignContext shiftRAssign() throws RecognitionException {
		ShiftRAssignContext _localctx = new ShiftRAssignContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_shiftRAssign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(201);
			shiftROp();
			setState(202);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AllAssignContext extends ParserRuleContext {
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public QusQusAssignContext qusQusAssign() {
			return getRuleContext(QusQusAssignContext.class,0);
		}
		public AddAssignContext addAssign() {
			return getRuleContext(AddAssignContext.class,0);
		}
		public SubAssignContext subAssign() {
			return getRuleContext(SubAssignContext.class,0);
		}
		public StarAssignContext starAssign() {
			return getRuleContext(StarAssignContext.class,0);
		}
		public StarStarAssignContext starStarAssign() {
			return getRuleContext(StarStarAssignContext.class,0);
		}
		public DivAssignContext divAssign() {
			return getRuleContext(DivAssignContext.class,0);
		}
		public ModAssignContext modAssign() {
			return getRuleContext(ModAssignContext.class,0);
		}
		public AndAssignContext andAssign() {
			return getRuleContext(AndAssignContext.class,0);
		}
		public OrAssignContext orAssign() {
			return getRuleContext(OrAssignContext.class,0);
		}
		public XorAssignContext xorAssign() {
			return getRuleContext(XorAssignContext.class,0);
		}
		public AndAndAssignContext andAndAssign() {
			return getRuleContext(AndAndAssignContext.class,0);
		}
		public OrOrAssignContext orOrAssign() {
			return getRuleContext(OrOrAssignContext.class,0);
		}
		public ShiftLAssignContext shiftLAssign() {
			return getRuleContext(ShiftLAssignContext.class,0);
		}
		public ShiftRAssignContext shiftRAssign() {
			return getRuleContext(ShiftRAssignContext.class,0);
		}
		public AllAssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_allAssign; }
	}

	public final AllAssignContext allAssign() throws RecognitionException {
		AllAssignContext _localctx = new AllAssignContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_allAssign);
		try {
			setState(219);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(204);
				match(Assign);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(205);
				qusQusAssign();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(206);
				addAssign();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(207);
				subAssign();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(208);
				starAssign();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(209);
				starStarAssign();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(210);
				divAssign();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(211);
				modAssign();
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(212);
				andAssign();
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(213);
				orAssign();
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(214);
				xorAssign();
				}
				break;
			case 12:
				enterOuterAlt(_localctx, 12);
				{
				setState(215);
				andAndAssign();
				}
				break;
			case 13:
				enterOuterAlt(_localctx, 13);
				{
				setState(216);
				orOrAssign();
				}
				break;
			case 14:
				enterOuterAlt(_localctx, 14);
				{
				setState(217);
				shiftLAssign();
				}
				break;
			case 15:
				enterOuterAlt(_localctx, 15);
				{
				setState(218);
				shiftRAssign();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class QusQusOpContext extends ParserRuleContext {
		public List<TerminalNode> Qus() { return getTokens(FaParser.Qus); }
		public TerminalNode Qus(int i) {
			return getToken(FaParser.Qus, i);
		}
		public QusQusOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qusQusOp; }
	}

	public final QusQusOpContext qusQusOp() throws RecognitionException {
		QusQusOpContext _localctx = new QusQusOpContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_qusQusOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(221);
			match(Qus);
			setState(222);
			match(Qus);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StarStarOpContext extends ParserRuleContext {
		public List<TerminalNode> StarOp() { return getTokens(FaParser.StarOp); }
		public TerminalNode StarOp(int i) {
			return getToken(FaParser.StarOp, i);
		}
		public StarStarOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_starStarOp; }
	}

	public final StarStarOpContext starStarOp() throws RecognitionException {
		StarStarOpContext _localctx = new StarStarOpContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_starStarOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(224);
			match(StarOp);
			setState(225);
			match(StarOp);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AndAndOpContext extends ParserRuleContext {
		public List<TerminalNode> AndOp() { return getTokens(FaParser.AndOp); }
		public TerminalNode AndOp(int i) {
			return getToken(FaParser.AndOp, i);
		}
		public AndAndOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_andAndOp; }
	}

	public final AndAndOpContext andAndOp() throws RecognitionException {
		AndAndOpContext _localctx = new AndAndOpContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_andAndOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(227);
			match(AndOp);
			setState(228);
			match(AndOp);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OrOrOpContext extends ParserRuleContext {
		public List<TerminalNode> OrOp() { return getTokens(FaParser.OrOp); }
		public TerminalNode OrOp(int i) {
			return getToken(FaParser.OrOp, i);
		}
		public OrOrOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_orOrOp; }
	}

	public final OrOrOpContext orOrOp() throws RecognitionException {
		OrOrOpContext _localctx = new OrOrOpContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_orOrOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(230);
			match(OrOp);
			setState(231);
			match(OrOp);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ShiftLOpContext extends ParserRuleContext {
		public List<TerminalNode> QuotJianL() { return getTokens(FaParser.QuotJianL); }
		public TerminalNode QuotJianL(int i) {
			return getToken(FaParser.QuotJianL, i);
		}
		public ShiftLOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shiftLOp; }
	}

	public final ShiftLOpContext shiftLOp() throws RecognitionException {
		ShiftLOpContext _localctx = new ShiftLOpContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_shiftLOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(233);
			match(QuotJianL);
			setState(234);
			match(QuotJianL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ShiftROpContext extends ParserRuleContext {
		public List<TerminalNode> QuotJianR() { return getTokens(FaParser.QuotJianR); }
		public TerminalNode QuotJianR(int i) {
			return getToken(FaParser.QuotJianR, i);
		}
		public ShiftROpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shiftROp; }
	}

	public final ShiftROpContext shiftROp() throws RecognitionException {
		ShiftROpContext _localctx = new ShiftROpContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_shiftROp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(236);
			match(QuotJianR);
			setState(237);
			match(QuotJianR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LtOpContext extends ParserRuleContext {
		public TerminalNode QuotJianL() { return getToken(FaParser.QuotJianL, 0); }
		public LtOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ltOp; }
	}

	public final LtOpContext ltOp() throws RecognitionException {
		LtOpContext _localctx = new LtOpContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_ltOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(239);
			match(QuotJianL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LtEqualOpContext extends ParserRuleContext {
		public TerminalNode QuotJianL() { return getToken(FaParser.QuotJianL, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public LtEqualOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ltEqualOp; }
	}

	public final LtEqualOpContext ltEqualOp() throws RecognitionException {
		LtEqualOpContext _localctx = new LtEqualOpContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_ltEqualOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(241);
			match(QuotJianL);
			setState(242);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class GtOpContext extends ParserRuleContext {
		public TerminalNode QuotJianR() { return getToken(FaParser.QuotJianR, 0); }
		public GtOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_gtOp; }
	}

	public final GtOpContext gtOp() throws RecognitionException {
		GtOpContext _localctx = new GtOpContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_gtOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(244);
			match(QuotJianR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class GtEqualOpContext extends ParserRuleContext {
		public TerminalNode QuotJianR() { return getToken(FaParser.QuotJianR, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public GtEqualOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_gtEqualOp; }
	}

	public final GtEqualOpContext gtEqualOp() throws RecognitionException {
		GtEqualOpContext _localctx = new GtEqualOpContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_gtEqualOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(246);
			match(QuotJianR);
			setState(247);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EqualOpContext extends ParserRuleContext {
		public List<TerminalNode> Assign() { return getTokens(FaParser.Assign); }
		public TerminalNode Assign(int i) {
			return getToken(FaParser.Assign, i);
		}
		public EqualOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_equalOp; }
	}

	public final EqualOpContext equalOp() throws RecognitionException {
		EqualOpContext _localctx = new EqualOpContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_equalOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(249);
			match(Assign);
			setState(250);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NotEqualOpContext extends ParserRuleContext {
		public TerminalNode Exclam() { return getToken(FaParser.Exclam, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public NotEqualOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_notEqualOp; }
	}

	public final NotEqualOpContext notEqualOp() throws RecognitionException {
		NotEqualOpContext _localctx = new NotEqualOpContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_notEqualOp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(252);
			match(Exclam);
			setState(253);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprFuncDefContext extends ParserRuleContext {
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public TerminalNode QuotJianR() { return getToken(FaParser.QuotJianR, 0); }
		public ExprFuncDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exprFuncDef; }
	}

	public final ExprFuncDefContext exprFuncDef() throws RecognitionException {
		ExprFuncDefContext _localctx = new ExprFuncDefContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_exprFuncDef);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(255);
			match(Assign);
			setState(256);
			match(QuotJianR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SelfOp2Context extends ParserRuleContext {
		public TerminalNode AddOp() { return getToken(FaParser.AddOp, 0); }
		public TerminalNode SubOp() { return getToken(FaParser.SubOp, 0); }
		public TerminalNode StarOp() { return getToken(FaParser.StarOp, 0); }
		public TerminalNode DivOp() { return getToken(FaParser.DivOp, 0); }
		public StarStarOpContext starStarOp() {
			return getRuleContext(StarStarOpContext.class,0);
		}
		public TerminalNode ModOp() { return getToken(FaParser.ModOp, 0); }
		public TerminalNode AndOp() { return getToken(FaParser.AndOp, 0); }
		public TerminalNode OrOp() { return getToken(FaParser.OrOp, 0); }
		public TerminalNode XorOp() { return getToken(FaParser.XorOp, 0); }
		public AndAndOpContext andAndOp() {
			return getRuleContext(AndAndOpContext.class,0);
		}
		public OrOrOpContext orOrOp() {
			return getRuleContext(OrOrOpContext.class,0);
		}
		public ShiftLOpContext shiftLOp() {
			return getRuleContext(ShiftLOpContext.class,0);
		}
		public ShiftROpContext shiftROp() {
			return getRuleContext(ShiftROpContext.class,0);
		}
		public SelfOp2Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_selfOp2; }
	}

	public final SelfOp2Context selfOp2() throws RecognitionException {
		SelfOp2Context _localctx = new SelfOp2Context(_ctx, getState());
		enterRule(_localctx, 56, RULE_selfOp2);
		try {
			setState(271);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(258);
				match(AddOp);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(259);
				match(SubOp);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(260);
				match(StarOp);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(261);
				match(DivOp);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(262);
				starStarOp();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(263);
				match(ModOp);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(264);
				match(AndOp);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(265);
				match(OrOp);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(266);
				match(XorOp);
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(267);
				andAndOp();
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(268);
				orOrOp();
				}
				break;
			case 12:
				enterOuterAlt(_localctx, 12);
				{
				setState(269);
				shiftLOp();
				}
				break;
			case 13:
				enterOuterAlt(_localctx, 13);
				{
				setState(270);
				shiftROp();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CompareOp2Context extends ParserRuleContext {
		public LtOpContext ltOp() {
			return getRuleContext(LtOpContext.class,0);
		}
		public LtEqualOpContext ltEqualOp() {
			return getRuleContext(LtEqualOpContext.class,0);
		}
		public GtOpContext gtOp() {
			return getRuleContext(GtOpContext.class,0);
		}
		public GtEqualOpContext gtEqualOp() {
			return getRuleContext(GtEqualOpContext.class,0);
		}
		public EqualOpContext equalOp() {
			return getRuleContext(EqualOpContext.class,0);
		}
		public NotEqualOpContext notEqualOp() {
			return getRuleContext(NotEqualOpContext.class,0);
		}
		public CompareOp2Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compareOp2; }
	}

	public final CompareOp2Context compareOp2() throws RecognitionException {
		CompareOp2Context _localctx = new CompareOp2Context(_ctx, getState());
		enterRule(_localctx, 58, RULE_compareOp2);
		try {
			setState(279);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(273);
				ltOp();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(274);
				ltEqualOp();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(275);
				gtOp();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(276);
				gtEqualOp();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(277);
				equalOp();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(278);
				notEqualOp();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ChangeOp2Context extends ParserRuleContext {
		public QusQusOpContext qusQusOp() {
			return getRuleContext(QusQusOpContext.class,0);
		}
		public CompareOp2Context compareOp2() {
			return getRuleContext(CompareOp2Context.class,0);
		}
		public ChangeOp2Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_changeOp2; }
	}

	public final ChangeOp2Context changeOp2() throws RecognitionException {
		ChangeOp2Context _localctx = new ChangeOp2Context(_ctx, getState());
		enterRule(_localctx, 60, RULE_changeOp2);
		try {
			setState(283);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Qus:
				enterOuterAlt(_localctx, 1);
				{
				setState(281);
				qusQusOp();
				}
				break;
			case Assign:
			case Exclam:
			case QuotJianL:
			case QuotJianR:
				enterOuterAlt(_localctx, 2);
				{
				setState(282);
				compareOp2();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AllOp2Context extends ParserRuleContext {
		public SelfOp2Context selfOp2() {
			return getRuleContext(SelfOp2Context.class,0);
		}
		public ChangeOp2Context changeOp2() {
			return getRuleContext(ChangeOp2Context.class,0);
		}
		public AllOp2Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_allOp2; }
	}

	public final AllOp2Context allOp2() throws RecognitionException {
		AllOp2Context _localctx = new AllOp2Context(_ctx, getState());
		enterRule(_localctx, 62, RULE_allOp2);
		try {
			setState(287);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(285);
				selfOp2();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(286);
				changeOp2();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IntNumContext extends ParserRuleContext {
		public TerminalNode IntLiteral() { return getToken(FaParser.IntLiteral, 0); }
		public TerminalNode SubOp() { return getToken(FaParser.SubOp, 0); }
		public IntNumContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_intNum; }
	}

	public final IntNumContext intNum() throws RecognitionException {
		IntNumContext _localctx = new IntNumContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_intNum);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(290);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SubOp) {
				{
				setState(289);
				match(SubOp);
				}
			}

			setState(292);
			match(IntLiteral);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FloatNumContext extends ParserRuleContext {
		public TerminalNode FloatLiteral() { return getToken(FaParser.FloatLiteral, 0); }
		public TerminalNode SubOp() { return getToken(FaParser.SubOp, 0); }
		public FloatNumContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_floatNum; }
	}

	public final FloatNumContext floatNum() throws RecognitionException {
		FloatNumContext _localctx = new FloatNumContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_floatNum);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(295);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SubOp) {
				{
				setState(294);
				match(SubOp);
				}
			}

			setState(297);
			match(FloatLiteral);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode BoolLiteral() { return getToken(FaParser.BoolLiteral, 0); }
		public IntNumContext intNum() {
			return getRuleContext(IntNumContext.class,0);
		}
		public FloatNumContext floatNum() {
			return getRuleContext(FloatNumContext.class,0);
		}
		public TerminalNode String1Literal() { return getToken(FaParser.String1Literal, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_literal);
		try {
			setState(303);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(299);
				match(BoolLiteral);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(300);
				intNum();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(301);
				floatNum();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(302);
				match(String1Literal);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdsContext extends ParserRuleContext {
		public List<TerminalNode> Id() { return getTokens(FaParser.Id); }
		public TerminalNode Id(int i) {
			return getToken(FaParser.Id, i);
		}
		public List<TerminalNode> PointOp() { return getTokens(FaParser.PointOp); }
		public TerminalNode PointOp(int i) {
			return getToken(FaParser.PointOp, i);
		}
		public IdsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ids; }
	}

	public final IdsContext ids() throws RecognitionException {
		IdsContext _localctx = new IdsContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_ids);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(305);
			match(Id);
			setState(310);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(306);
					match(PointOp);
					setState(307);
					match(Id);
					}
					} 
				}
				setState(312);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeAfterContext extends ParserRuleContext {
		public TerminalNode QuotFangL() { return getToken(FaParser.QuotFangL, 0); }
		public TerminalNode QuotFangR() { return getToken(FaParser.QuotFangR, 0); }
		public TerminalNode AndOp() { return getToken(FaParser.AndOp, 0); }
		public TerminalNode Qus() { return getToken(FaParser.Qus, 0); }
		public TerminalNode QuotJianL() { return getToken(FaParser.QuotJianL, 0); }
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public TerminalNode QuotJianR() { return getToken(FaParser.QuotJianR, 0); }
		public List<TerminalNode> Comma() { return getTokens(FaParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FaParser.Comma, i);
		}
		public TerminalNode StarOp() { return getToken(FaParser.StarOp, 0); }
		public TypeAfterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeAfter; }
	}

	public final TypeAfterContext typeAfter() throws RecognitionException {
		TypeAfterContext _localctx = new TypeAfterContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_typeAfter);
		int _la;
		try {
			setState(329);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case QuotFangL:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(313);
				match(QuotFangL);
				setState(314);
				match(QuotFangR);
				}
				}
				break;
			case AndOp:
				enterOuterAlt(_localctx, 2);
				{
				setState(315);
				match(AndOp);
				}
				break;
			case Qus:
				enterOuterAlt(_localctx, 3);
				{
				setState(316);
				match(Qus);
				}
				break;
			case QuotJianL:
				enterOuterAlt(_localctx, 4);
				{
				{
				setState(317);
				match(QuotJianL);
				setState(318);
				type();
				setState(323);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(319);
					match(Comma);
					setState(320);
					type();
					}
					}
					setState(325);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(326);
				match(QuotJianR);
				}
				}
				break;
			case StarOp:
				enterOuterAlt(_localctx, 5);
				{
				setState(328);
				match(StarOp);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public List<TypeAfterContext> typeAfter() {
			return getRuleContexts(TypeAfterContext.class);
		}
		public TypeAfterContext typeAfter(int i) {
			return getRuleContext(TypeAfterContext.class,i);
		}
		public TerminalNode QuotYuanL() { return getToken(FaParser.QuotYuanL, 0); }
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public TerminalNode QuotYuanR() { return getToken(FaParser.QuotYuanR, 0); }
		public List<TerminalNode> Comma() { return getTokens(FaParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FaParser.Comma, i);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_type);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(342);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Id:
				{
				setState(331);
				match(Id);
				}
				break;
			case QuotYuanL:
				{
				{
				setState(332);
				match(QuotYuanL);
				setState(333);
				type();
				setState(336); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(334);
					match(Comma);
					setState(335);
					type();
					}
					}
					setState(338); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==Comma );
				setState(340);
				match(QuotYuanR);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(347);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(344);
					typeAfter();
					}
					} 
				}
				setState(349);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeNewableContext extends ParserRuleContext {
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public List<TypeAfterContext> typeAfter() {
			return getRuleContexts(TypeAfterContext.class);
		}
		public TypeAfterContext typeAfter(int i) {
			return getRuleContext(TypeAfterContext.class,i);
		}
		public TypeNewableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeNewable; }
	}

	public final TypeNewableContext typeNewable() throws RecognitionException {
		TypeNewableContext _localctx = new TypeNewableContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_typeNewable);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(350);
			match(Id);
			setState(354);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << StarOp) | (1L << AndOp) | (1L << Qus) | (1L << QuotFangL) | (1L << QuotJianL))) != 0)) {
				{
				{
				setState(351);
				typeAfter();
				}
				}
				setState(356);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeVarContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TypeVarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeVar; }
	}

	public final TypeVarContext typeVar() throws RecognitionException {
		TypeVarContext _localctx = new TypeVarContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_typeVar);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(357);
			type();
			setState(359);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Id) {
				{
				setState(358);
				match(Id);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeVarListContext extends ParserRuleContext {
		public List<TypeVarContext> typeVar() {
			return getRuleContexts(TypeVarContext.class);
		}
		public TypeVarContext typeVar(int i) {
			return getRuleContext(TypeVarContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(FaParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FaParser.Comma, i);
		}
		public TypeVarListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeVarList; }
	}

	public final TypeVarListContext typeVarList() throws RecognitionException {
		TypeVarListContext _localctx = new TypeVarListContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_typeVarList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(361);
			typeVar();
			setState(366);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(362);
				match(Comma);
				setState(363);
				typeVar();
				}
				}
				setState(368);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class QuotStmtPartContext extends ParserRuleContext {
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public QuotStmtPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_quotStmtPart; }
	}

	public final QuotStmtPartContext quotStmtPart() throws RecognitionException {
		QuotStmtPartContext _localctx = new QuotStmtPartContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_quotStmtPart);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(369);
			match(QuotHuaL);
			setState(373);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Break) | (1L << Continue) | (1L << For) | (1L << If) | (1L << New) | (1L << Return) | (1L << While) | (1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp) | (1L << ColonColon) | (1L << Semi) | (1L << QuotFangL) | (1L << QuotYuanL) | (1L << BoolLiteral) | (1L << IntLiteral) | (1L << FloatLiteral) | (1L << String1Literal) | (1L << Id))) != 0)) {
				{
				{
				setState(370);
				stmt();
				}
				}
				setState(375);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(376);
			match(QuotHuaR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class QuotStmtExprContext extends ParserRuleContext {
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public QuotStmtExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_quotStmtExpr; }
	}

	public final QuotStmtExprContext quotStmtExpr() throws RecognitionException {
		QuotStmtExprContext _localctx = new QuotStmtExprContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_quotStmtExpr);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(378);
			match(QuotHuaL);
			setState(382);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(379);
					stmt();
					}
					} 
				}
				setState(384);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			setState(385);
			expr();
			setState(386);
			match(QuotHuaR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfStmtContext extends ParserRuleContext {
		public List<TerminalNode> If() { return getTokens(FaParser.If); }
		public TerminalNode If(int i) {
			return getToken(FaParser.If, i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<QuotStmtPartContext> quotStmtPart() {
			return getRuleContexts(QuotStmtPartContext.class);
		}
		public QuotStmtPartContext quotStmtPart(int i) {
			return getRuleContext(QuotStmtPartContext.class,i);
		}
		public List<TerminalNode> Else() { return getTokens(FaParser.Else); }
		public TerminalNode Else(int i) {
			return getToken(FaParser.Else, i);
		}
		public IfStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStmt; }
	}

	public final IfStmtContext ifStmt() throws RecognitionException {
		IfStmtContext _localctx = new IfStmtContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_ifStmt);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(388);
			match(If);
			setState(389);
			expr();
			setState(390);
			quotStmtPart();
			setState(398);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(391);
					match(Else);
					setState(392);
					match(If);
					setState(393);
					expr();
					setState(394);
					quotStmtPart();
					}
					} 
				}
				setState(400);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			setState(403);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Else) {
				{
				setState(401);
				match(Else);
				setState(402);
				quotStmtPart();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfExprContext extends ParserRuleContext {
		public List<TerminalNode> If() { return getTokens(FaParser.If); }
		public TerminalNode If(int i) {
			return getToken(FaParser.If, i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<QuotStmtExprContext> quotStmtExpr() {
			return getRuleContexts(QuotStmtExprContext.class);
		}
		public QuotStmtExprContext quotStmtExpr(int i) {
			return getRuleContext(QuotStmtExprContext.class,i);
		}
		public List<TerminalNode> Else() { return getTokens(FaParser.Else); }
		public TerminalNode Else(int i) {
			return getToken(FaParser.Else, i);
		}
		public IfExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifExpr; }
	}

	public final IfExprContext ifExpr() throws RecognitionException {
		IfExprContext _localctx = new IfExprContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_ifExpr);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(405);
			match(If);
			setState(406);
			expr();
			setState(407);
			quotStmtExpr();
			setState(415);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(408);
					match(Else);
					setState(409);
					match(If);
					setState(410);
					expr();
					setState(411);
					quotStmtExpr();
					}
					} 
				}
				setState(417);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			setState(418);
			match(Else);
			setState(419);
			quotStmtExpr();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileStmtContext extends ParserRuleContext {
		public TerminalNode While() { return getToken(FaParser.While, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public WhileStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStmt; }
	}

	public final WhileStmtContext whileStmt() throws RecognitionException {
		WhileStmtContext _localctx = new WhileStmtContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_whileStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(421);
			match(While);
			setState(422);
			expr();
			setState(423);
			match(QuotHuaL);
			setState(427);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Break) | (1L << Continue) | (1L << For) | (1L << If) | (1L << New) | (1L << Return) | (1L << While) | (1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp) | (1L << ColonColon) | (1L << Semi) | (1L << QuotFangL) | (1L << QuotYuanL) | (1L << BoolLiteral) | (1L << IntLiteral) | (1L << FloatLiteral) | (1L << String1Literal) | (1L << Id))) != 0)) {
				{
				{
				setState(424);
				stmt();
				}
				}
				setState(429);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(430);
			match(QuotHuaR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NumIterStmtContext extends ParserRuleContext {
		public TerminalNode For() { return getToken(FaParser.For, 0); }
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public List<TerminalNode> Colon() { return getTokens(FaParser.Colon); }
		public TerminalNode Colon(int i) {
			return getToken(FaParser.Colon, i);
		}
		public List<ExprOptContext> exprOpt() {
			return getRuleContexts(ExprOptContext.class);
		}
		public ExprOptContext exprOpt(int i) {
			return getRuleContext(ExprOptContext.class,i);
		}
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public NumIterStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numIterStmt; }
	}

	public final NumIterStmtContext numIterStmt() throws RecognitionException {
		NumIterStmtContext _localctx = new NumIterStmtContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_numIterStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(432);
			match(For);
			setState(433);
			match(Id);
			setState(434);
			match(Colon);
			setState(435);
			exprOpt();
			setState(438); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(436);
				match(Colon);
				setState(437);
				exprOpt();
				}
				}
				setState(440); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==Colon );
			setState(442);
			match(QuotHuaL);
			setState(446);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Break) | (1L << Continue) | (1L << For) | (1L << If) | (1L << New) | (1L << Return) | (1L << While) | (1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp) | (1L << ColonColon) | (1L << Semi) | (1L << QuotFangL) | (1L << QuotYuanL) | (1L << BoolLiteral) | (1L << IntLiteral) | (1L << FloatLiteral) | (1L << String1Literal) | (1L << Id))) != 0)) {
				{
				{
				setState(443);
				stmt();
				}
				}
				setState(448);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(449);
			match(QuotHuaR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class QuotExprContext extends ParserRuleContext {
		public TerminalNode QuotYuanL() { return getToken(FaParser.QuotYuanL, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode QuotYuanR() { return getToken(FaParser.QuotYuanR, 0); }
		public QuotExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_quotExpr; }
	}

	public final QuotExprContext quotExpr() throws RecognitionException {
		QuotExprContext _localctx = new QuotExprContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_quotExpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(451);
			match(QuotYuanL);
			setState(452);
			expr();
			setState(453);
			match(QuotYuanR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprOptContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExprOptContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exprOpt; }
	}

	public final ExprOptContext exprOpt() throws RecognitionException {
		ExprOptContext _localctx = new ExprOptContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_exprOpt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(456);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << If) | (1L << New) | (1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp) | (1L << ColonColon) | (1L << QuotFangL) | (1L << QuotYuanL) | (1L << BoolLiteral) | (1L << IntLiteral) | (1L << FloatLiteral) | (1L << String1Literal) | (1L << Id))) != 0)) {
				{
				setState(455);
				expr();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NewExprItemContext extends ParserRuleContext {
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public MiddleExprContext middleExpr() {
			return getRuleContext(MiddleExprContext.class,0);
		}
		public NewExprItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_newExprItem; }
	}

	public final NewExprItemContext newExprItem() throws RecognitionException {
		NewExprItemContext _localctx = new NewExprItemContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_newExprItem);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(458);
			match(Id);
			setState(461);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Assign) {
				{
				setState(459);
				match(Assign);
				setState(460);
				middleExpr();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NewExprContext extends ParserRuleContext {
		public TerminalNode New() { return getToken(FaParser.New, 0); }
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public IdsContext ids() {
			return getRuleContext(IdsContext.class,0);
		}
		public List<NewExprItemContext> newExprItem() {
			return getRuleContexts(NewExprItemContext.class);
		}
		public NewExprItemContext newExprItem(int i) {
			return getRuleContext(NewExprItemContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(FaParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FaParser.Comma, i);
		}
		public NewExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_newExpr; }
	}

	public final NewExprContext newExpr() throws RecognitionException {
		NewExprContext _localctx = new NewExprContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_newExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(463);
			match(New);
			setState(465);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Id) {
				{
				setState(464);
				ids();
				}
			}

			setState(467);
			match(QuotHuaL);
			setState(476);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Id) {
				{
				setState(468);
				newExprItem();
				setState(473);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(469);
					match(Comma);
					setState(470);
					newExprItem();
					}
					}
					setState(475);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(478);
			match(QuotHuaR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayExpr1Context extends ParserRuleContext {
		public TerminalNode QuotFangL() { return getToken(FaParser.QuotFangL, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode PointPoint() { return getToken(FaParser.PointPoint, 0); }
		public TerminalNode QuotFangR() { return getToken(FaParser.QuotFangR, 0); }
		public TerminalNode Step() { return getToken(FaParser.Step, 0); }
		public ArrayExpr1Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayExpr1; }
	}

	public final ArrayExpr1Context arrayExpr1() throws RecognitionException {
		ArrayExpr1Context _localctx = new ArrayExpr1Context(_ctx, getState());
		enterRule(_localctx, 102, RULE_arrayExpr1);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(480);
			match(QuotFangL);
			setState(481);
			expr();
			setState(482);
			match(PointPoint);
			setState(483);
			expr();
			setState(486);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Step) {
				{
				setState(484);
				match(Step);
				setState(485);
				expr();
				}
			}

			setState(488);
			match(QuotFangR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayExpr2Context extends ParserRuleContext {
		public TerminalNode QuotFangL() { return getToken(FaParser.QuotFangL, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode QuotFangR() { return getToken(FaParser.QuotFangR, 0); }
		public List<TerminalNode> Comma() { return getTokens(FaParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FaParser.Comma, i);
		}
		public ArrayExpr2Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayExpr2; }
	}

	public final ArrayExpr2Context arrayExpr2() throws RecognitionException {
		ArrayExpr2Context _localctx = new ArrayExpr2Context(_ctx, getState());
		enterRule(_localctx, 104, RULE_arrayExpr2);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(490);
			match(QuotFangL);
			setState(491);
			expr();
			setState(496);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(492);
				match(Comma);
				setState(493);
				expr();
				}
				}
				setState(498);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(499);
			match(QuotFangR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StrongExprBaseContext extends ParserRuleContext {
		public IdsContext ids() {
			return getRuleContext(IdsContext.class,0);
		}
		public TerminalNode ColonColon() { return getToken(FaParser.ColonColon, 0); }
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public IfExprContext ifExpr() {
			return getRuleContext(IfExprContext.class,0);
		}
		public QuotExprContext quotExpr() {
			return getRuleContext(QuotExprContext.class,0);
		}
		public NewExprContext newExpr() {
			return getRuleContext(NewExprContext.class,0);
		}
		public ArrayExpr1Context arrayExpr1() {
			return getRuleContext(ArrayExpr1Context.class,0);
		}
		public ArrayExpr2Context arrayExpr2() {
			return getRuleContext(ArrayExpr2Context.class,0);
		}
		public StrongExprBaseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_strongExprBase; }
	}

	public final StrongExprBaseContext strongExprBase() throws RecognitionException {
		StrongExprBaseContext _localctx = new StrongExprBaseContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_strongExprBase);
		try {
			setState(510);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(501);
				ids();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(502);
				match(ColonColon);
				setState(503);
				match(Id);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(504);
				literal();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(505);
				ifExpr();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(506);
				quotExpr();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(507);
				newExpr();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(508);
				arrayExpr1();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(509);
				arrayExpr2();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StrongExprPrefixContext extends ParserRuleContext {
		public TerminalNode SubOp() { return getToken(FaParser.SubOp, 0); }
		public TerminalNode AddAddOp() { return getToken(FaParser.AddAddOp, 0); }
		public TerminalNode SubSubOp() { return getToken(FaParser.SubSubOp, 0); }
		public TerminalNode ReverseOp() { return getToken(FaParser.ReverseOp, 0); }
		public StrongExprPrefixContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_strongExprPrefix; }
	}

	public final StrongExprPrefixContext strongExprPrefix() throws RecognitionException {
		StrongExprPrefixContext _localctx = new StrongExprPrefixContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_strongExprPrefix);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(512);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StrongExprSuffixContext extends ParserRuleContext {
		public TerminalNode AddAddOp() { return getToken(FaParser.AddAddOp, 0); }
		public TerminalNode SubSubOp() { return getToken(FaParser.SubSubOp, 0); }
		public TerminalNode QuotYuanL() { return getToken(FaParser.QuotYuanL, 0); }
		public TerminalNode QuotYuanR() { return getToken(FaParser.QuotYuanR, 0); }
		public List<ExprOptContext> exprOpt() {
			return getRuleContexts(ExprOptContext.class);
		}
		public ExprOptContext exprOpt(int i) {
			return getRuleContext(ExprOptContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(FaParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FaParser.Comma, i);
		}
		public TerminalNode QuotFangL() { return getToken(FaParser.QuotFangL, 0); }
		public TerminalNode QuotFangR() { return getToken(FaParser.QuotFangR, 0); }
		public List<TerminalNode> Colon() { return getTokens(FaParser.Colon); }
		public TerminalNode Colon(int i) {
			return getToken(FaParser.Colon, i);
		}
		public TerminalNode PointOp() { return getToken(FaParser.PointOp, 0); }
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public StrongExprSuffixContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_strongExprSuffix; }
	}

	public final StrongExprSuffixContext strongExprSuffix() throws RecognitionException {
		StrongExprSuffixContext _localctx = new StrongExprSuffixContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_strongExprSuffix);
		int _la;
		try {
			setState(540);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case AddAddOp:
				enterOuterAlt(_localctx, 1);
				{
				setState(514);
				match(AddAddOp);
				}
				break;
			case SubSubOp:
				enterOuterAlt(_localctx, 2);
				{
				setState(515);
				match(SubSubOp);
				}
				break;
			case QuotYuanL:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(516);
				match(QuotYuanL);
				{
				setState(517);
				exprOpt();
				setState(522);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(518);
					match(Comma);
					setState(519);
					exprOpt();
					}
					}
					setState(524);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				setState(525);
				match(QuotYuanR);
				}
				}
				break;
			case QuotFangL:
				enterOuterAlt(_localctx, 4);
				{
				{
				setState(527);
				match(QuotFangL);
				{
				setState(528);
				exprOpt();
				setState(533);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Colon) {
					{
					{
					setState(529);
					match(Colon);
					setState(530);
					exprOpt();
					}
					}
					setState(535);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				setState(536);
				match(QuotFangR);
				}
				}
				break;
			case PointOp:
				enterOuterAlt(_localctx, 5);
				{
				{
				setState(538);
				match(PointOp);
				setState(539);
				match(Id);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StrongExprContext extends ParserRuleContext {
		public StrongExprBaseContext strongExprBase() {
			return getRuleContext(StrongExprBaseContext.class,0);
		}
		public List<StrongExprPrefixContext> strongExprPrefix() {
			return getRuleContexts(StrongExprPrefixContext.class);
		}
		public StrongExprPrefixContext strongExprPrefix(int i) {
			return getRuleContext(StrongExprPrefixContext.class,i);
		}
		public List<StrongExprSuffixContext> strongExprSuffix() {
			return getRuleContexts(StrongExprSuffixContext.class);
		}
		public StrongExprSuffixContext strongExprSuffix(int i) {
			return getRuleContext(StrongExprSuffixContext.class,i);
		}
		public StrongExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_strongExpr; }
	}

	public final StrongExprContext strongExpr() throws RecognitionException {
		StrongExprContext _localctx = new StrongExprContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_strongExpr);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(545);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(542);
					strongExprPrefix();
					}
					} 
				}
				setState(547);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
			}
			setState(548);
			strongExprBase();
			setState(552);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << AddAddOp) | (1L << SubSubOp) | (1L << PointOp) | (1L << QuotFangL) | (1L << QuotYuanL))) != 0)) {
				{
				{
				setState(549);
				strongExprSuffix();
				}
				}
				setState(554);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MiddleExprContext extends ParserRuleContext {
		public List<StrongExprContext> strongExpr() {
			return getRuleContexts(StrongExprContext.class);
		}
		public StrongExprContext strongExpr(int i) {
			return getRuleContext(StrongExprContext.class,i);
		}
		public List<AllOp2Context> allOp2() {
			return getRuleContexts(AllOp2Context.class);
		}
		public AllOp2Context allOp2(int i) {
			return getRuleContext(AllOp2Context.class,i);
		}
		public MiddleExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_middleExpr; }
	}

	public final MiddleExprContext middleExpr() throws RecognitionException {
		MiddleExprContext _localctx = new MiddleExprContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_middleExpr);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(555);
			strongExpr();
			setState(561);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(556);
					allOp2();
					setState(557);
					strongExpr();
					}
					} 
				}
				setState(563);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public List<MiddleExprContext> middleExpr() {
			return getRuleContexts(MiddleExprContext.class);
		}
		public MiddleExprContext middleExpr(int i) {
			return getRuleContext(MiddleExprContext.class,i);
		}
		public List<AllAssignContext> allAssign() {
			return getRuleContexts(AllAssignContext.class);
		}
		public AllAssignContext allAssign(int i) {
			return getRuleContext(AllAssignContext.class,i);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 116, RULE_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(564);
			middleExpr();
			setState(570);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Assign) | (1L << AddOp) | (1L << SubOp) | (1L << StarOp) | (1L << DivOp) | (1L << ModOp) | (1L << OrOp) | (1L << AndOp) | (1L << XorOp) | (1L << Qus) | (1L << QuotJianL) | (1L << QuotJianR))) != 0)) {
				{
				{
				setState(565);
				allAssign();
				setState(566);
				middleExpr();
				}
				}
				setState(572);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TmpAssignExprContext extends ParserRuleContext {
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public TmpAssignExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_tmpAssignExpr; }
	}

	public final TmpAssignExprContext tmpAssignExpr() throws RecognitionException {
		TmpAssignExprContext _localctx = new TmpAssignExprContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_tmpAssignExpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(573);
			match(Assign);
			setState(574);
			expr();
			setState(575);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DefVarStmtContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode Assign() { return getToken(FaParser.Assign, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public DefVarStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_defVarStmt; }
	}

	public final DefVarStmtContext defVarStmt() throws RecognitionException {
		DefVarStmtContext _localctx = new DefVarStmtContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_defVarStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(577);
			type();
			setState(578);
			match(Id);
			setState(579);
			match(Assign);
			setState(580);
			expr();
			setState(581);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UseStmtContext extends ParserRuleContext {
		public TerminalNode Use() { return getToken(FaParser.Use, 0); }
		public IdsContext ids() {
			return getRuleContext(IdsContext.class,0);
		}
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public UseStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_useStmt; }
	}

	public final UseStmtContext useStmt() throws RecognitionException {
		UseStmtContext _localctx = new UseStmtContext(_ctx, getState());
		enterRule(_localctx, 122, RULE_useStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(583);
			match(Use);
			setState(584);
			ids();
			setState(585);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NormalStmtContext extends ParserRuleContext {
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public TerminalNode Break() { return getToken(FaParser.Break, 0); }
		public TerminalNode Continue() { return getToken(FaParser.Continue, 0); }
		public TerminalNode Return() { return getToken(FaParser.Return, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public NormalStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_normalStmt; }
	}

	public final NormalStmtContext normalStmt() throws RecognitionException {
		NormalStmtContext _localctx = new NormalStmtContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_normalStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(595);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case If:
			case New:
			case Return:
			case ReverseOp:
			case AddAddOp:
			case SubSubOp:
			case SubOp:
			case ColonColon:
			case Semi:
			case QuotFangL:
			case QuotYuanL:
			case BoolLiteral:
			case IntLiteral:
			case FloatLiteral:
			case String1Literal:
			case Id:
				{
				{
				setState(588);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Return) {
					{
					setState(587);
					match(Return);
					}
				}

				setState(591);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << If) | (1L << New) | (1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp) | (1L << ColonColon) | (1L << QuotFangL) | (1L << QuotYuanL) | (1L << BoolLiteral) | (1L << IntLiteral) | (1L << FloatLiteral) | (1L << String1Literal) | (1L << Id))) != 0)) {
					{
					setState(590);
					expr();
					}
				}

				}
				}
				break;
			case Break:
				{
				setState(593);
				match(Break);
				}
				break;
			case Continue:
				{
				setState(594);
				match(Continue);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(597);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public NormalStmtContext normalStmt() {
			return getRuleContext(NormalStmtContext.class,0);
		}
		public IfStmtContext ifStmt() {
			return getRuleContext(IfStmtContext.class,0);
		}
		public DefVarStmtContext defVarStmt() {
			return getRuleContext(DefVarStmtContext.class,0);
		}
		public WhileStmtContext whileStmt() {
			return getRuleContext(WhileStmtContext.class,0);
		}
		public NumIterStmtContext numIterStmt() {
			return getRuleContext(NumIterStmtContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_stmt);
		try {
			setState(604);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,43,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(599);
				normalStmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(600);
				ifStmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(601);
				defVarStmt();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(602);
				whileStmt();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(603);
				numIterStmt();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PublicLevelContext extends ParserRuleContext {
		public TerminalNode Public() { return getToken(FaParser.Public, 0); }
		public TerminalNode Internal() { return getToken(FaParser.Internal, 0); }
		public TerminalNode Protected() { return getToken(FaParser.Protected, 0); }
		public TerminalNode Private() { return getToken(FaParser.Private, 0); }
		public PublicLevelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_publicLevel; }
	}

	public final PublicLevelContext publicLevel() throws RecognitionException {
		PublicLevelContext _localctx = new PublicLevelContext(_ctx, getState());
		enterRule(_localctx, 128, RULE_publicLevel);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(606);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassParentContext extends ParserRuleContext {
		public TerminalNode Colon() { return getToken(FaParser.Colon, 0); }
		public List<IdsContext> ids() {
			return getRuleContexts(IdsContext.class);
		}
		public IdsContext ids(int i) {
			return getRuleContext(IdsContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(FaParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(FaParser.Comma, i);
		}
		public ClassParentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classParent; }
	}

	public final ClassParentContext classParent() throws RecognitionException {
		ClassParentContext _localctx = new ClassParentContext(_ctx, getState());
		enterRule(_localctx, 130, RULE_classParent);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(608);
			match(Colon);
			setState(609);
			ids();
			setState(614);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(610);
				match(Comma);
				setState(611);
				ids();
				}
				}
				setState(616);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassTypeContext extends ParserRuleContext {
		public TerminalNode Class() { return getToken(FaParser.Class, 0); }
		public TerminalNode Struct() { return getToken(FaParser.Struct, 0); }
		public TerminalNode Interface() { return getToken(FaParser.Interface, 0); }
		public TerminalNode Enum() { return getToken(FaParser.Enum, 0); }
		public ClassTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classType; }
	}

	public final ClassTypeContext classType() throws RecognitionException {
		ClassTypeContext _localctx = new ClassTypeContext(_ctx, getState());
		enterRule(_localctx, 132, RULE_classType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(617);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Class) | (1L << Enum) | (1L << Interface) | (1L << Struct))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassStmtContext extends ParserRuleContext {
		public ClassTypeContext classType() {
			return getRuleContext(ClassTypeContext.class,0);
		}
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public PublicLevelContext publicLevel() {
			return getRuleContext(PublicLevelContext.class,0);
		}
		public ClassParentContext classParent() {
			return getRuleContext(ClassParentContext.class,0);
		}
		public List<EnumAtomContext> enumAtom() {
			return getRuleContexts(EnumAtomContext.class);
		}
		public EnumAtomContext enumAtom(int i) {
			return getRuleContext(EnumAtomContext.class,i);
		}
		public List<ClassVarContext> classVar() {
			return getRuleContexts(ClassVarContext.class);
		}
		public ClassVarContext classVar(int i) {
			return getRuleContext(ClassVarContext.class,i);
		}
		public List<ClassFuncContext> classFunc() {
			return getRuleContexts(ClassFuncContext.class);
		}
		public ClassFuncContext classFunc(int i) {
			return getRuleContext(ClassFuncContext.class,i);
		}
		public ClassStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classStmt; }
	}

	public final ClassStmtContext classStmt() throws RecognitionException {
		ClassStmtContext _localctx = new ClassStmtContext(_ctx, getState());
		enterRule(_localctx, 134, RULE_classStmt);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(620);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private))) != 0)) {
				{
				setState(619);
				publicLevel();
				}
			}

			setState(622);
			classType();
			setState(623);
			match(Id);
			setState(625);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Colon) {
				{
				setState(624);
				classParent();
				}
			}

			setState(627);
			match(QuotHuaL);
			setState(631);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(628);
					enumAtom();
					}
					} 
				}
				setState(633);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
			}
			setState(638);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private) | (1L << Static) | (1L << QuotYuanL) | (1L << Id))) != 0)) {
				{
				setState(636);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,48,_ctx) ) {
				case 1:
					{
					setState(634);
					classVar();
					}
					break;
				case 2:
					{
					setState(635);
					classFunc();
					}
					break;
				}
				}
				setState(640);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(641);
			match(QuotHuaR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassVarExtFuncContext extends ParserRuleContext {
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public ClassFuncBodyContext classFuncBody() {
			return getRuleContext(ClassFuncBodyContext.class,0);
		}
		public PublicLevelContext publicLevel() {
			return getRuleContext(PublicLevelContext.class,0);
		}
		public ClassVarExtFuncContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classVarExtFunc; }
	}

	public final ClassVarExtFuncContext classVarExtFunc() throws RecognitionException {
		ClassVarExtFuncContext _localctx = new ClassVarExtFuncContext(_ctx, getState());
		enterRule(_localctx, 136, RULE_classVarExtFunc);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(644);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private))) != 0)) {
				{
				setState(643);
				publicLevel();
				}
			}

			setState(646);
			match(Id);
			setState(649);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Semi:
				{
				setState(647);
				match(Semi);
				}
				break;
			case Assign:
			case QuotHuaL:
				{
				setState(648);
				classFuncBody();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassVarExtContext extends ParserRuleContext {
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public List<ClassVarExtFuncContext> classVarExtFunc() {
			return getRuleContexts(ClassVarExtFuncContext.class);
		}
		public ClassVarExtFuncContext classVarExtFunc(int i) {
			return getRuleContext(ClassVarExtFuncContext.class,i);
		}
		public TmpAssignExprContext tmpAssignExpr() {
			return getRuleContext(TmpAssignExprContext.class,0);
		}
		public ClassVarExtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classVarExt; }
	}

	public final ClassVarExtContext classVarExt() throws RecognitionException {
		ClassVarExtContext _localctx = new ClassVarExtContext(_ctx, getState());
		enterRule(_localctx, 138, RULE_classVarExt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(651);
			match(QuotHuaL);
			setState(653); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(652);
				classVarExtFunc();
				}
				}
				setState(655); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private) | (1L << Id))) != 0) );
			setState(657);
			match(QuotHuaR);
			setState(659);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Assign) {
				{
				setState(658);
				tmpAssignExpr();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassVarContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public TmpAssignExprContext tmpAssignExpr() {
			return getRuleContext(TmpAssignExprContext.class,0);
		}
		public ClassVarExtContext classVarExt() {
			return getRuleContext(ClassVarExtContext.class,0);
		}
		public PublicLevelContext publicLevel() {
			return getRuleContext(PublicLevelContext.class,0);
		}
		public TerminalNode Static() { return getToken(FaParser.Static, 0); }
		public ClassVarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classVar; }
	}

	public final ClassVarContext classVar() throws RecognitionException {
		ClassVarContext _localctx = new ClassVarContext(_ctx, getState());
		enterRule(_localctx, 140, RULE_classVar);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(662);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private))) != 0)) {
				{
				setState(661);
				publicLevel();
				}
			}

			setState(665);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Static) {
				{
				setState(664);
				match(Static);
				}
			}

			setState(667);
			type();
			setState(668);
			match(Id);
			setState(672);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Semi:
				{
				setState(669);
				match(Semi);
				}
				break;
			case Assign:
				{
				setState(670);
				tmpAssignExpr();
				}
				break;
			case QuotHuaL:
				{
				setState(671);
				classVarExt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassFuncNameContext extends ParserRuleContext {
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode QuotFangL() { return getToken(FaParser.QuotFangL, 0); }
		public TerminalNode QuotFangR() { return getToken(FaParser.QuotFangR, 0); }
		public AllOp2Context allOp2() {
			return getRuleContext(AllOp2Context.class,0);
		}
		public AllAssignContext allAssign() {
			return getRuleContext(AllAssignContext.class,0);
		}
		public ClassFuncNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classFuncName; }
	}

	public final ClassFuncNameContext classFuncName() throws RecognitionException {
		ClassFuncNameContext _localctx = new ClassFuncNameContext(_ctx, getState());
		enterRule(_localctx, 142, RULE_classFuncName);
		try {
			setState(679);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,57,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(674);
				match(Id);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(675);
				match(QuotFangL);
				setState(676);
				match(QuotFangR);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(677);
				allOp2();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(678);
				allAssign();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassFuncBodyContext extends ParserRuleContext {
		public ExprFuncDefContext exprFuncDef() {
			return getRuleContext(ExprFuncDefContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public ClassFuncBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classFuncBody; }
	}

	public final ClassFuncBodyContext classFuncBody() throws RecognitionException {
		ClassFuncBodyContext _localctx = new ClassFuncBodyContext(_ctx, getState());
		enterRule(_localctx, 144, RULE_classFuncBody);
		int _la;
		try {
			setState(693);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Assign:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(681);
				exprFuncDef();
				setState(682);
				expr();
				setState(683);
				match(Semi);
				}
				}
				break;
			case QuotHuaL:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(685);
				match(QuotHuaL);
				setState(689);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Break) | (1L << Continue) | (1L << For) | (1L << If) | (1L << New) | (1L << Return) | (1L << While) | (1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp) | (1L << ColonColon) | (1L << Semi) | (1L << QuotFangL) | (1L << QuotYuanL) | (1L << BoolLiteral) | (1L << IntLiteral) | (1L << FloatLiteral) | (1L << String1Literal) | (1L << Id))) != 0)) {
					{
					{
					setState(686);
					stmt();
					}
					}
					setState(691);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(692);
				match(QuotHuaR);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassFuncContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ClassFuncNameContext classFuncName() {
			return getRuleContext(ClassFuncNameContext.class,0);
		}
		public TerminalNode QuotYuanL() { return getToken(FaParser.QuotYuanL, 0); }
		public TerminalNode QuotYuanR() { return getToken(FaParser.QuotYuanR, 0); }
		public ClassFuncBodyContext classFuncBody() {
			return getRuleContext(ClassFuncBodyContext.class,0);
		}
		public PublicLevelContext publicLevel() {
			return getRuleContext(PublicLevelContext.class,0);
		}
		public TerminalNode Static() { return getToken(FaParser.Static, 0); }
		public TypeVarListContext typeVarList() {
			return getRuleContext(TypeVarListContext.class,0);
		}
		public ClassFuncContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classFunc; }
	}

	public final ClassFuncContext classFunc() throws RecognitionException {
		ClassFuncContext _localctx = new ClassFuncContext(_ctx, getState());
		enterRule(_localctx, 146, RULE_classFunc);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(696);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private))) != 0)) {
				{
				setState(695);
				publicLevel();
				}
			}

			setState(699);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Static) {
				{
				setState(698);
				match(Static);
				}
			}

			setState(701);
			type();
			setState(702);
			classFuncName();
			setState(703);
			match(QuotYuanL);
			setState(705);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==QuotYuanL || _la==Id) {
				{
				setState(704);
				typeVarList();
				}
			}

			setState(707);
			match(QuotYuanR);
			setState(708);
			classFuncBody();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EnumAtomContext extends ParserRuleContext {
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode Comma() { return getToken(FaParser.Comma, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public EnumAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumAtom; }
	}

	public final EnumAtomContext enumAtom() throws RecognitionException {
		EnumAtomContext _localctx = new EnumAtomContext(_ctx, getState());
		enterRule(_localctx, 148, RULE_enumAtom);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(711);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,63,_ctx) ) {
			case 1:
				{
				setState(710);
				type();
				}
				break;
			}
			setState(713);
			match(Id);
			setState(714);
			match(Comma);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CallConventionContext extends ParserRuleContext {
		public TerminalNode CC__Cdecl() { return getToken(FaParser.CC__Cdecl, 0); }
		public TerminalNode CC__FastCall() { return getToken(FaParser.CC__FastCall, 0); }
		public TerminalNode CC__StdCall() { return getToken(FaParser.CC__StdCall, 0); }
		public CallConventionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_callConvention; }
	}

	public final CallConventionContext callConvention() throws RecognitionException {
		CallConventionContext _localctx = new CallConventionContext(_ctx, getState());
		enterRule(_localctx, 150, RULE_callConvention);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(716);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << CC__Cdecl) | (1L << CC__FastCall) | (1L << CC__StdCall))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ImportStmtContext extends ParserRuleContext {
		public TerminalNode AImport() { return getToken(FaParser.AImport, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public CallConventionContext callConvention() {
			return getRuleContext(CallConventionContext.class,0);
		}
		public TerminalNode Id() { return getToken(FaParser.Id, 0); }
		public TerminalNode QuotYuanL() { return getToken(FaParser.QuotYuanL, 0); }
		public TypeVarListContext typeVarList() {
			return getRuleContext(TypeVarListContext.class,0);
		}
		public TerminalNode QuotYuanR() { return getToken(FaParser.QuotYuanR, 0); }
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public ImportStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_importStmt; }
	}

	public final ImportStmtContext importStmt() throws RecognitionException {
		ImportStmtContext _localctx = new ImportStmtContext(_ctx, getState());
		enterRule(_localctx, 152, RULE_importStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(718);
			match(AImport);
			setState(719);
			type();
			setState(720);
			callConvention();
			setState(721);
			match(Id);
			setState(722);
			match(QuotYuanL);
			setState(723);
			typeVarList();
			setState(724);
			match(QuotYuanR);
			setState(725);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LibStmtContext extends ParserRuleContext {
		public TerminalNode ALib() { return getToken(FaParser.ALib, 0); }
		public TerminalNode String1Literal() { return getToken(FaParser.String1Literal, 0); }
		public TerminalNode Semi() { return getToken(FaParser.Semi, 0); }
		public LibStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_libStmt; }
	}

	public final LibStmtContext libStmt() throws RecognitionException {
		LibStmtContext _localctx = new LibStmtContext(_ctx, getState());
		enterRule(_localctx, 154, RULE_libStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(727);
			match(ALib);
			setState(728);
			match(String1Literal);
			setState(729);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ImportBlockContext extends ParserRuleContext {
		public List<ImportStmtContext> importStmt() {
			return getRuleContexts(ImportStmtContext.class);
		}
		public ImportStmtContext importStmt(int i) {
			return getRuleContext(ImportStmtContext.class,i);
		}
		public List<LibStmtContext> libStmt() {
			return getRuleContexts(LibStmtContext.class);
		}
		public LibStmtContext libStmt(int i) {
			return getRuleContext(LibStmtContext.class,i);
		}
		public ImportBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_importBlock; }
	}

	public final ImportBlockContext importBlock() throws RecognitionException {
		ImportBlockContext _localctx = new ImportBlockContext(_ctx, getState());
		enterRule(_localctx, 156, RULE_importBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(733); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(733);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case AImport:
					{
					setState(731);
					importStmt();
					}
					break;
				case ALib:
					{
					setState(732);
					libStmt();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(735); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==AImport || _la==ALib );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FaMainFuncBlockContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode FaMain() { return getToken(FaParser.FaMain, 0); }
		public TerminalNode QuotYuanL() { return getToken(FaParser.QuotYuanL, 0); }
		public TerminalNode QuotYuanR() { return getToken(FaParser.QuotYuanR, 0); }
		public TerminalNode QuotHuaL() { return getToken(FaParser.QuotHuaL, 0); }
		public TerminalNode QuotHuaR() { return getToken(FaParser.QuotHuaR, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public FaMainFuncBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_faMainFuncBlock; }
	}

	public final FaMainFuncBlockContext faMainFuncBlock() throws RecognitionException {
		FaMainFuncBlockContext _localctx = new FaMainFuncBlockContext(_ctx, getState());
		enterRule(_localctx, 158, RULE_faMainFuncBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(737);
			type();
			setState(738);
			match(FaMain);
			setState(739);
			match(QuotYuanL);
			setState(740);
			match(QuotYuanR);
			setState(741);
			match(QuotHuaL);
			setState(745);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Break) | (1L << Continue) | (1L << For) | (1L << If) | (1L << New) | (1L << Return) | (1L << While) | (1L << ReverseOp) | (1L << AddAddOp) | (1L << SubSubOp) | (1L << SubOp) | (1L << ColonColon) | (1L << Semi) | (1L << QuotFangL) | (1L << QuotYuanL) | (1L << BoolLiteral) | (1L << IntLiteral) | (1L << FloatLiteral) | (1L << String1Literal) | (1L << Id))) != 0)) {
				{
				{
				setState(742);
				stmt();
				}
				}
				setState(747);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(748);
			match(QuotHuaR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProgramContext extends ParserRuleContext {
		public List<UseStmtContext> useStmt() {
			return getRuleContexts(UseStmtContext.class);
		}
		public UseStmtContext useStmt(int i) {
			return getRuleContext(UseStmtContext.class,i);
		}
		public ImportBlockContext importBlock() {
			return getRuleContext(ImportBlockContext.class,0);
		}
		public List<ClassStmtContext> classStmt() {
			return getRuleContexts(ClassStmtContext.class);
		}
		public ClassStmtContext classStmt(int i) {
			return getRuleContext(ClassStmtContext.class,i);
		}
		public FaMainFuncBlockContext faMainFuncBlock() {
			return getRuleContext(FaMainFuncBlockContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 160, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(753);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Use) {
				{
				{
				setState(750);
				useStmt();
				}
				}
				setState(755);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(757);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==AImport || _la==ALib) {
				{
				setState(756);
				importBlock();
				}
			}

			setState(762);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Class) | (1L << Enum) | (1L << Interface) | (1L << Internal) | (1L << Public) | (1L << Protected) | (1L << Private) | (1L << Struct))) != 0)) {
				{
				{
				setState(759);
				classStmt();
				}
				}
				setState(764);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(766);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==QuotYuanL || _la==Id) {
				{
				setState(765);
				faMainFuncBlock();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3B\u0303\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\4R\tR\3\2\3\2\3\2"+
		"\3\3\3\3\3\3\3\4\3\4\3\4\3\5\3\5\3\5\3\6\3\6\3\6\3\7\3\7\3\7\3\b\3\b\3"+
		"\b\3\t\3\t\3\t\3\n\3\n\3\n\3\13\3\13\3\13\3\f\3\f\3\f\3\r\3\r\3\r\3\16"+
		"\3\16\3\16\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20"+
		"\3\20\3\20\3\20\3\20\3\20\3\20\5\20\u00de\n\20\3\21\3\21\3\21\3\22\3\22"+
		"\3\22\3\23\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\25\3\26\3\26\3\26\3\27"+
		"\3\27\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\32\3\33\3\33\3\33\3\34\3\34"+
		"\3\34\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36"+
		"\3\36\3\36\3\36\5\36\u0112\n\36\3\37\3\37\3\37\3\37\3\37\3\37\5\37\u011a"+
		"\n\37\3 \3 \5 \u011e\n \3!\3!\5!\u0122\n!\3\"\5\"\u0125\n\"\3\"\3\"\3"+
		"#\5#\u012a\n#\3#\3#\3$\3$\3$\3$\5$\u0132\n$\3%\3%\3%\7%\u0137\n%\f%\16"+
		"%\u013a\13%\3&\3&\3&\3&\3&\3&\3&\3&\7&\u0144\n&\f&\16&\u0147\13&\3&\3"+
		"&\3&\5&\u014c\n&\3\'\3\'\3\'\3\'\3\'\6\'\u0153\n\'\r\'\16\'\u0154\3\'"+
		"\3\'\5\'\u0159\n\'\3\'\7\'\u015c\n\'\f\'\16\'\u015f\13\'\3(\3(\7(\u0163"+
		"\n(\f(\16(\u0166\13(\3)\3)\5)\u016a\n)\3*\3*\3*\7*\u016f\n*\f*\16*\u0172"+
		"\13*\3+\3+\7+\u0176\n+\f+\16+\u0179\13+\3+\3+\3,\3,\7,\u017f\n,\f,\16"+
		",\u0182\13,\3,\3,\3,\3-\3-\3-\3-\3-\3-\3-\3-\7-\u018f\n-\f-\16-\u0192"+
		"\13-\3-\3-\5-\u0196\n-\3.\3.\3.\3.\3.\3.\3.\3.\7.\u01a0\n.\f.\16.\u01a3"+
		"\13.\3.\3.\3.\3/\3/\3/\3/\7/\u01ac\n/\f/\16/\u01af\13/\3/\3/\3\60\3\60"+
		"\3\60\3\60\3\60\3\60\6\60\u01b9\n\60\r\60\16\60\u01ba\3\60\3\60\7\60\u01bf"+
		"\n\60\f\60\16\60\u01c2\13\60\3\60\3\60\3\61\3\61\3\61\3\61\3\62\5\62\u01cb"+
		"\n\62\3\63\3\63\3\63\5\63\u01d0\n\63\3\64\3\64\5\64\u01d4\n\64\3\64\3"+
		"\64\3\64\3\64\7\64\u01da\n\64\f\64\16\64\u01dd\13\64\5\64\u01df\n\64\3"+
		"\64\3\64\3\65\3\65\3\65\3\65\3\65\3\65\5\65\u01e9\n\65\3\65\3\65\3\66"+
		"\3\66\3\66\3\66\7\66\u01f1\n\66\f\66\16\66\u01f4\13\66\3\66\3\66\3\67"+
		"\3\67\3\67\3\67\3\67\3\67\3\67\3\67\3\67\5\67\u0201\n\67\38\38\39\39\3"+
		"9\39\39\39\79\u020b\n9\f9\169\u020e\139\39\39\39\39\39\39\79\u0216\n9"+
		"\f9\169\u0219\139\39\39\39\39\59\u021f\n9\3:\7:\u0222\n:\f:\16:\u0225"+
		"\13:\3:\3:\7:\u0229\n:\f:\16:\u022c\13:\3;\3;\3;\3;\7;\u0232\n;\f;\16"+
		";\u0235\13;\3<\3<\3<\3<\7<\u023b\n<\f<\16<\u023e\13<\3=\3=\3=\3=\3>\3"+
		">\3>\3>\3>\3>\3?\3?\3?\3?\3@\5@\u024f\n@\3@\5@\u0252\n@\3@\3@\5@\u0256"+
		"\n@\3@\3@\3A\3A\3A\3A\3A\5A\u025f\nA\3B\3B\3C\3C\3C\3C\7C\u0267\nC\fC"+
		"\16C\u026a\13C\3D\3D\3E\5E\u026f\nE\3E\3E\3E\5E\u0274\nE\3E\3E\7E\u0278"+
		"\nE\fE\16E\u027b\13E\3E\3E\7E\u027f\nE\fE\16E\u0282\13E\3E\3E\3F\5F\u0287"+
		"\nF\3F\3F\3F\5F\u028c\nF\3G\3G\6G\u0290\nG\rG\16G\u0291\3G\3G\5G\u0296"+
		"\nG\3H\5H\u0299\nH\3H\5H\u029c\nH\3H\3H\3H\3H\3H\5H\u02a3\nH\3I\3I\3I"+
		"\3I\3I\5I\u02aa\nI\3J\3J\3J\3J\3J\3J\7J\u02b2\nJ\fJ\16J\u02b5\13J\3J\5"+
		"J\u02b8\nJ\3K\5K\u02bb\nK\3K\5K\u02be\nK\3K\3K\3K\3K\5K\u02c4\nK\3K\3"+
		"K\3K\3L\5L\u02ca\nL\3L\3L\3L\3M\3M\3N\3N\3N\3N\3N\3N\3N\3N\3N\3O\3O\3"+
		"O\3O\3P\3P\6P\u02e0\nP\rP\16P\u02e1\3Q\3Q\3Q\3Q\3Q\3Q\7Q\u02ea\nQ\fQ\16"+
		"Q\u02ed\13Q\3Q\3Q\3R\7R\u02f2\nR\fR\16R\u02f5\13R\3R\5R\u02f8\nR\3R\7"+
		"R\u02fb\nR\fR\16R\u02fe\13R\3R\5R\u0301\nR\3R\2\2S\2\4\6\b\n\f\16\20\22"+
		"\24\26\30\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`bdfhjlnp"+
		"rtvxz|~\u0080\u0082\u0084\u0086\u0088\u008a\u008c\u008e\u0090\u0092\u0094"+
		"\u0096\u0098\u009a\u009c\u009e\u00a0\u00a2\2\6\4\2 \"&&\4\2\22\22\24\26"+
		"\6\2\n\n\r\r\21\21\33\33\3\2\6\b\2\u0329\2\u00a4\3\2\2\2\4\u00a7\3\2\2"+
		"\2\6\u00aa\3\2\2\2\b\u00ad\3\2\2\2\n\u00b0\3\2\2\2\f\u00b3\3\2\2\2\16"+
		"\u00b6\3\2\2\2\20\u00b9\3\2\2\2\22\u00bc\3\2\2\2\24\u00bf\3\2\2\2\26\u00c2"+
		"\3\2\2\2\30\u00c5\3\2\2\2\32\u00c8\3\2\2\2\34\u00cb\3\2\2\2\36\u00dd\3"+
		"\2\2\2 \u00df\3\2\2\2\"\u00e2\3\2\2\2$\u00e5\3\2\2\2&\u00e8\3\2\2\2(\u00eb"+
		"\3\2\2\2*\u00ee\3\2\2\2,\u00f1\3\2\2\2.\u00f3\3\2\2\2\60\u00f6\3\2\2\2"+
		"\62\u00f8\3\2\2\2\64\u00fb\3\2\2\2\66\u00fe\3\2\2\28\u0101\3\2\2\2:\u0111"+
		"\3\2\2\2<\u0119\3\2\2\2>\u011d\3\2\2\2@\u0121\3\2\2\2B\u0124\3\2\2\2D"+
		"\u0129\3\2\2\2F\u0131\3\2\2\2H\u0133\3\2\2\2J\u014b\3\2\2\2L\u0158\3\2"+
		"\2\2N\u0160\3\2\2\2P\u0167\3\2\2\2R\u016b\3\2\2\2T\u0173\3\2\2\2V\u017c"+
		"\3\2\2\2X\u0186\3\2\2\2Z\u0197\3\2\2\2\\\u01a7\3\2\2\2^\u01b2\3\2\2\2"+
		"`\u01c5\3\2\2\2b\u01ca\3\2\2\2d\u01cc\3\2\2\2f\u01d1\3\2\2\2h\u01e2\3"+
		"\2\2\2j\u01ec\3\2\2\2l\u0200\3\2\2\2n\u0202\3\2\2\2p\u021e\3\2\2\2r\u0223"+
		"\3\2\2\2t\u022d\3\2\2\2v\u0236\3\2\2\2x\u023f\3\2\2\2z\u0243\3\2\2\2|"+
		"\u0249\3\2\2\2~\u0255\3\2\2\2\u0080\u025e\3\2\2\2\u0082\u0260\3\2\2\2"+
		"\u0084\u0262\3\2\2\2\u0086\u026b\3\2\2\2\u0088\u026e\3\2\2\2\u008a\u0286"+
		"\3\2\2\2\u008c\u028d\3\2\2\2\u008e\u0298\3\2\2\2\u0090\u02a9\3\2\2\2\u0092"+
		"\u02b7\3\2\2\2\u0094\u02ba\3\2\2\2\u0096\u02c9\3\2\2\2\u0098\u02ce\3\2"+
		"\2\2\u009a\u02d0\3\2\2\2\u009c\u02d9\3\2\2\2\u009e\u02df\3\2\2\2\u00a0"+
		"\u02e3\3\2\2\2\u00a2\u02f3\3\2\2\2\u00a4\u00a5\7%\2\2\u00a5\u00a6\7\37"+
		"\2\2\u00a6\3\3\2\2\2\u00a7\u00a8\7&\2\2\u00a8\u00a9\7\37\2\2\u00a9\5\3"+
		"\2\2\2\u00aa\u00ab\7\'\2\2\u00ab\u00ac\7\37\2\2\u00ac\7\3\2\2\2\u00ad"+
		"\u00ae\7(\2\2\u00ae\u00af\7\37\2\2\u00af\t\3\2\2\2\u00b0\u00b1\7)\2\2"+
		"\u00b1\u00b2\7\37\2\2\u00b2\13\3\2\2\2\u00b3\u00b4\7*\2\2\u00b4\u00b5"+
		"\7\37\2\2\u00b5\r\3\2\2\2\u00b6\u00b7\7+\2\2\u00b7\u00b8\7\37\2\2\u00b8"+
		"\17\3\2\2\2\u00b9\u00ba\7,\2\2\u00ba\u00bb\7\37\2\2\u00bb\21\3\2\2\2\u00bc"+
		"\u00bd\5 \21\2\u00bd\u00be\7\37\2\2\u00be\23\3\2\2\2\u00bf\u00c0\5\"\22"+
		"\2\u00c0\u00c1\7\37\2\2\u00c1\25\3\2\2\2\u00c2\u00c3\5$\23\2\u00c3\u00c4"+
		"\7\37\2\2\u00c4\27\3\2\2\2\u00c5\u00c6\5&\24\2\u00c6\u00c7\7\37\2\2\u00c7"+
		"\31\3\2\2\2\u00c8\u00c9\5(\25\2\u00c9\u00ca\7\37\2\2\u00ca\33\3\2\2\2"+
		"\u00cb\u00cc\5*\26\2\u00cc\u00cd\7\37\2\2\u00cd\35\3\2\2\2\u00ce\u00de"+
		"\7\37\2\2\u00cf\u00de\5\22\n\2\u00d0\u00de\5\2\2\2\u00d1\u00de\5\4\3\2"+
		"\u00d2\u00de\5\6\4\2\u00d3\u00de\5\24\13\2\u00d4\u00de\5\b\5\2\u00d5\u00de"+
		"\5\n\6\2\u00d6\u00de\5\16\b\2\u00d7\u00de\5\f\7\2\u00d8\u00de\5\20\t\2"+
		"\u00d9\u00de\5\26\f\2\u00da\u00de\5\30\r\2\u00db\u00de\5\32\16\2\u00dc"+
		"\u00de\5\34\17\2\u00dd\u00ce\3\2\2\2\u00dd\u00cf\3\2\2\2\u00dd\u00d0\3"+
		"\2\2\2\u00dd\u00d1\3\2\2\2\u00dd\u00d2\3\2\2\2\u00dd\u00d3\3\2\2\2\u00dd"+
		"\u00d4\3\2\2\2\u00dd\u00d5\3\2\2\2\u00dd\u00d6\3\2\2\2\u00dd\u00d7\3\2"+
		"\2\2\u00dd\u00d8\3\2\2\2\u00dd\u00d9\3\2\2\2\u00dd\u00da\3\2\2\2\u00dd"+
		"\u00db\3\2\2\2\u00dd\u00dc\3\2\2\2\u00de\37\3\2\2\2\u00df\u00e0\7-\2\2"+
		"\u00e0\u00e1\7-\2\2\u00e1!\3\2\2\2\u00e2\u00e3\7\'\2\2\u00e3\u00e4\7\'"+
		"\2\2\u00e4#\3\2\2\2\u00e5\u00e6\7+\2\2\u00e6\u00e7\7+\2\2\u00e7%\3\2\2"+
		"\2\u00e8\u00e9\7*\2\2\u00e9\u00ea\7*\2\2\u00ea\'\3\2\2\2\u00eb\u00ec\7"+
		"\65\2\2\u00ec\u00ed\7\65\2\2\u00ed)\3\2\2\2\u00ee\u00ef\7\66\2\2\u00ef"+
		"\u00f0\7\66\2\2\u00f0+\3\2\2\2\u00f1\u00f2\7\65\2\2\u00f2-\3\2\2\2\u00f3"+
		"\u00f4\7\65\2\2\u00f4\u00f5\7\37\2\2\u00f5/\3\2\2\2\u00f6\u00f7\7\66\2"+
		"\2\u00f7\61\3\2\2\2\u00f8\u00f9\7\66\2\2\u00f9\u00fa\7\37\2\2\u00fa\63"+
		"\3\2\2\2\u00fb\u00fc\7\37\2\2\u00fc\u00fd\7\37\2\2\u00fd\65\3\2\2\2\u00fe"+
		"\u00ff\7\62\2\2\u00ff\u0100\7\37\2\2\u0100\67\3\2\2\2\u0101\u0102\7\37"+
		"\2\2\u0102\u0103\7\66\2\2\u01039\3\2\2\2\u0104\u0112\7%\2\2\u0105\u0112"+
		"\7&\2\2\u0106\u0112\7\'\2\2\u0107\u0112\7(\2\2\u0108\u0112\5\"\22\2\u0109"+
		"\u0112\7)\2\2\u010a\u0112\7+\2\2\u010b\u0112\7*\2\2\u010c\u0112\7,\2\2"+
		"\u010d\u0112\5$\23\2\u010e\u0112\5&\24\2\u010f\u0112\5(\25\2\u0110\u0112"+
		"\5*\26\2\u0111\u0104\3\2\2\2\u0111\u0105\3\2\2\2\u0111\u0106\3\2\2\2\u0111"+
		"\u0107\3\2\2\2\u0111\u0108\3\2\2\2\u0111\u0109\3\2\2\2\u0111\u010a\3\2"+
		"\2\2\u0111\u010b\3\2\2\2\u0111\u010c\3\2\2\2\u0111\u010d\3\2\2\2\u0111"+
		"\u010e\3\2\2\2\u0111\u010f\3\2\2\2\u0111\u0110\3\2\2\2\u0112;\3\2\2\2"+
		"\u0113\u011a\5,\27\2\u0114\u011a\5.\30\2\u0115\u011a\5\60\31\2\u0116\u011a"+
		"\5\62\32\2\u0117\u011a\5\64\33\2\u0118\u011a\5\66\34\2\u0119\u0113\3\2"+
		"\2\2\u0119\u0114\3\2\2\2\u0119\u0115\3\2\2\2\u0119\u0116\3\2\2\2\u0119"+
		"\u0117\3\2\2\2\u0119\u0118\3\2\2\2\u011a=\3\2\2\2\u011b\u011e\5 \21\2"+
		"\u011c\u011e\5<\37\2\u011d\u011b\3\2\2\2\u011d\u011c\3\2\2\2\u011e?\3"+
		"\2\2\2\u011f\u0122\5:\36\2\u0120\u0122\5> \2\u0121\u011f\3\2\2\2\u0121"+
		"\u0120\3\2\2\2\u0122A\3\2\2\2\u0123\u0125\7&\2\2\u0124\u0123\3\2\2\2\u0124"+
		"\u0125\3\2\2\2\u0125\u0126\3\2\2\2\u0126\u0127\7<\2\2\u0127C\3\2\2\2\u0128"+
		"\u012a\7&\2\2\u0129\u0128\3\2\2\2\u0129\u012a\3\2\2\2\u012a\u012b\3\2"+
		"\2\2\u012b\u012c\7=\2\2\u012cE\3\2\2\2\u012d\u0132\7;\2\2\u012e\u0132"+
		"\5B\"\2\u012f\u0132\5D#\2\u0130\u0132\7>\2\2\u0131\u012d\3\2\2\2\u0131"+
		"\u012e\3\2\2\2\u0131\u012f\3\2\2\2\u0131\u0130\3\2\2\2\u0132G\3\2\2\2"+
		"\u0133\u0138\7?\2\2\u0134\u0135\7$\2\2\u0135\u0137\7?\2\2\u0136\u0134"+
		"\3\2\2\2\u0137\u013a\3\2\2\2\u0138\u0136\3\2\2\2\u0138\u0139\3\2\2\2\u0139"+
		"I\3\2\2\2\u013a\u0138\3\2\2\2\u013b\u013c\7\63\2\2\u013c\u014c\7\64\2"+
		"\2\u013d\u014c\7+\2\2\u013e\u014c\7-\2\2\u013f\u0140\7\65\2\2\u0140\u0145"+
		"\5L\'\2\u0141\u0142\7.\2\2\u0142\u0144\5L\'\2\u0143\u0141\3\2\2\2\u0144"+
		"\u0147\3\2\2\2\u0145\u0143\3\2\2\2\u0145\u0146\3\2\2\2\u0146\u0148\3\2"+
		"\2\2\u0147\u0145\3\2\2\2\u0148\u0149\7\66\2\2\u0149\u014c\3\2\2\2\u014a"+
		"\u014c\7\'\2\2\u014b\u013b\3\2\2\2\u014b\u013d\3\2\2\2\u014b\u013e\3\2"+
		"\2\2\u014b\u013f\3\2\2\2\u014b\u014a\3\2\2\2\u014cK\3\2\2\2\u014d\u0159"+
		"\7?\2\2\u014e\u014f\79\2\2\u014f\u0152\5L\'\2\u0150\u0151\7.\2\2\u0151"+
		"\u0153\5L\'\2\u0152\u0150\3\2\2\2\u0153\u0154\3\2\2\2\u0154\u0152\3\2"+
		"\2\2\u0154\u0155\3\2\2\2\u0155\u0156\3\2\2\2\u0156\u0157\7:\2\2\u0157"+
		"\u0159\3\2\2\2\u0158\u014d\3\2\2\2\u0158\u014e\3\2\2\2\u0159\u015d\3\2"+
		"\2\2\u015a\u015c\5J&\2\u015b\u015a\3\2\2\2\u015c\u015f\3\2\2\2\u015d\u015b"+
		"\3\2\2\2\u015d\u015e\3\2\2\2\u015eM\3\2\2\2\u015f\u015d\3\2\2\2\u0160"+
		"\u0164\7?\2\2\u0161\u0163\5J&\2\u0162\u0161\3\2\2\2\u0163\u0166\3\2\2"+
		"\2\u0164\u0162\3\2\2\2\u0164\u0165\3\2\2\2\u0165O\3\2\2\2\u0166\u0164"+
		"\3\2\2\2\u0167\u0169\5L\'\2\u0168\u016a\7?\2\2\u0169\u0168\3\2\2\2\u0169"+
		"\u016a\3\2\2\2\u016aQ\3\2\2\2\u016b\u0170\5P)\2\u016c\u016d\7.\2\2\u016d"+
		"\u016f\5P)\2\u016e\u016c\3\2\2\2\u016f\u0172\3\2\2\2\u0170\u016e\3\2\2"+
		"\2\u0170\u0171\3\2\2\2\u0171S\3\2\2\2\u0172\u0170\3\2\2\2\u0173\u0177"+
		"\7\67\2\2\u0174\u0176\5\u0080A\2\u0175\u0174\3\2\2\2\u0176\u0179\3\2\2"+
		"\2\u0177\u0175\3\2\2\2\u0177\u0178\3\2\2\2\u0178\u017a\3\2\2\2\u0179\u0177"+
		"\3\2\2\2\u017a\u017b\78\2\2\u017bU\3\2\2\2\u017c\u0180\7\67\2\2\u017d"+
		"\u017f\5\u0080A\2\u017e\u017d\3\2\2\2\u017f\u0182\3\2\2\2\u0180\u017e"+
		"\3\2\2\2\u0180\u0181\3\2\2\2\u0181\u0183\3\2\2\2\u0182\u0180\3\2\2\2\u0183"+
		"\u0184\5v<\2\u0184\u0185\78\2\2\u0185W\3\2\2\2\u0186\u0187\7\20\2\2\u0187"+
		"\u0188\5v<\2\u0188\u0190\5T+\2\u0189\u018a\7\f\2\2\u018a\u018b\7\20\2"+
		"\2\u018b\u018c\5v<\2\u018c\u018d\5T+\2\u018d\u018f\3\2\2\2\u018e\u0189"+
		"\3\2\2\2\u018f\u0192\3\2\2\2\u0190\u018e\3\2\2\2\u0190\u0191\3\2\2\2\u0191"+
		"\u0195\3\2\2\2\u0192\u0190\3\2\2\2\u0193\u0194\7\f\2\2\u0194\u0196\5T"+
		"+\2\u0195\u0193\3\2\2\2\u0195\u0196\3\2\2\2\u0196Y\3\2\2\2\u0197\u0198"+
		"\7\20\2\2\u0198\u0199\5v<\2\u0199\u01a1\5V,\2\u019a\u019b\7\f\2\2\u019b"+
		"\u019c\7\20\2\2\u019c\u019d\5v<\2\u019d\u019e\5V,\2\u019e\u01a0\3\2\2"+
		"\2\u019f\u019a\3\2\2\2\u01a0\u01a3\3\2\2\2\u01a1\u019f\3\2\2\2\u01a1\u01a2"+
		"\3\2\2\2\u01a2\u01a4\3\2\2\2\u01a3\u01a1\3\2\2\2\u01a4\u01a5\7\f\2\2\u01a5"+
		"\u01a6\5V,\2\u01a6[\3\2\2\2\u01a7\u01a8\7\36\2\2\u01a8\u01a9\5v<\2\u01a9"+
		"\u01ad\7\67\2\2\u01aa\u01ac\5\u0080A\2\u01ab\u01aa\3\2\2\2\u01ac\u01af"+
		"\3\2\2\2\u01ad\u01ab\3\2\2\2\u01ad\u01ae\3\2\2\2\u01ae\u01b0\3\2\2\2\u01af"+
		"\u01ad\3\2\2\2\u01b0\u01b1\78\2\2\u01b1]\3\2\2\2\u01b2\u01b3\7\17\2\2"+
		"\u01b3\u01b4\7?\2\2\u01b4\u01b5\7\60\2\2\u01b5\u01b8\5b\62\2\u01b6\u01b7"+
		"\7\60\2\2\u01b7\u01b9\5b\62\2\u01b8\u01b6\3\2\2\2\u01b9\u01ba\3\2\2\2"+
		"\u01ba\u01b8\3\2\2\2\u01ba\u01bb\3\2\2\2\u01bb\u01bc\3\2\2\2\u01bc\u01c0"+
		"\7\67\2\2\u01bd\u01bf\5\u0080A\2\u01be\u01bd\3\2\2\2\u01bf\u01c2\3\2\2"+
		"\2\u01c0\u01be\3\2\2\2\u01c0\u01c1\3\2\2\2\u01c1\u01c3\3\2\2\2\u01c2\u01c0"+
		"\3\2\2\2\u01c3\u01c4\78\2\2\u01c4_\3\2\2\2\u01c5\u01c6\79\2\2\u01c6\u01c7"+
		"\5v<\2\u01c7\u01c8\7:\2\2\u01c8a\3\2\2\2\u01c9\u01cb\5v<\2\u01ca\u01c9"+
		"\3\2\2\2\u01ca\u01cb\3\2\2\2\u01cbc\3\2\2\2\u01cc\u01cf\7?\2\2\u01cd\u01ce"+
		"\7\37\2\2\u01ce\u01d0\5t;\2\u01cf\u01cd\3\2\2\2\u01cf\u01d0\3\2\2\2\u01d0"+
		"e\3\2\2\2\u01d1\u01d3\7\23\2\2\u01d2\u01d4\5H%\2\u01d3\u01d2\3\2\2\2\u01d3"+
		"\u01d4\3\2\2\2\u01d4\u01d5\3\2\2\2\u01d5\u01de\7\67\2\2\u01d6\u01db\5"+
		"d\63\2\u01d7\u01d8\7.\2\2\u01d8\u01da\5d\63\2\u01d9\u01d7\3\2\2\2\u01da"+
		"\u01dd\3\2\2\2\u01db\u01d9\3\2\2\2\u01db\u01dc\3\2\2\2\u01dc\u01df\3\2"+
		"\2\2\u01dd\u01db\3\2\2\2\u01de\u01d6\3\2\2\2\u01de\u01df\3\2\2\2\u01df"+
		"\u01e0\3\2\2\2\u01e0\u01e1\78\2\2\u01e1g\3\2\2\2\u01e2\u01e3\7\63\2\2"+
		"\u01e3\u01e4\5v<\2\u01e4\u01e5\7#\2\2\u01e5\u01e8\5v<\2\u01e6\u01e7\7"+
		"\32\2\2\u01e7\u01e9\5v<\2\u01e8\u01e6\3\2\2\2\u01e8\u01e9\3\2\2\2\u01e9"+
		"\u01ea\3\2\2\2\u01ea\u01eb\7\64\2\2\u01ebi\3\2\2\2\u01ec\u01ed\7\63\2"+
		"\2\u01ed\u01f2\5v<\2\u01ee\u01ef\7.\2\2\u01ef\u01f1\5v<\2\u01f0\u01ee"+
		"\3\2\2\2\u01f1\u01f4\3\2\2\2\u01f2\u01f0\3\2\2\2\u01f2\u01f3\3\2\2\2\u01f3"+
		"\u01f5\3\2\2\2\u01f4\u01f2\3\2\2\2\u01f5\u01f6\7\64\2\2\u01f6k\3\2\2\2"+
		"\u01f7\u0201\5H%\2\u01f8\u01f9\7/\2\2\u01f9\u0201\7?\2\2\u01fa\u0201\5"+
		"F$\2\u01fb\u0201\5Z.\2\u01fc\u0201\5`\61\2\u01fd\u0201\5f\64\2\u01fe\u0201"+
		"\5h\65\2\u01ff\u0201\5j\66\2\u0200\u01f7\3\2\2\2\u0200\u01f8\3\2\2\2\u0200"+
		"\u01fa\3\2\2\2\u0200\u01fb\3\2\2\2\u0200\u01fc\3\2\2\2\u0200\u01fd\3\2"+
		"\2\2\u0200\u01fe\3\2\2\2\u0200\u01ff\3\2\2\2\u0201m\3\2\2\2\u0202\u0203"+
		"\t\2\2\2\u0203o\3\2\2\2\u0204\u021f\7!\2\2\u0205\u021f\7\"\2\2\u0206\u0207"+
		"\79\2\2\u0207\u020c\5b\62\2\u0208\u0209\7.\2\2\u0209\u020b\5b\62\2\u020a"+
		"\u0208\3\2\2\2\u020b\u020e\3\2\2\2\u020c\u020a\3\2\2\2\u020c\u020d\3\2"+
		"\2\2\u020d\u020f\3\2\2\2\u020e\u020c\3\2\2\2\u020f\u0210\7:\2\2\u0210"+
		"\u021f\3\2\2\2\u0211\u0212\7\63\2\2\u0212\u0217\5b\62\2\u0213\u0214\7"+
		"\60\2\2\u0214\u0216\5b\62\2\u0215\u0213\3\2\2\2\u0216\u0219\3\2\2\2\u0217"+
		"\u0215\3\2\2\2\u0217\u0218\3\2\2\2\u0218\u021a\3\2\2\2\u0219\u0217\3\2"+
		"\2\2\u021a\u021b\7\64\2\2\u021b\u021f\3\2\2\2\u021c\u021d\7$\2\2\u021d"+
		"\u021f\7?\2\2\u021e\u0204\3\2\2\2\u021e\u0205\3\2\2\2\u021e\u0206\3\2"+
		"\2\2\u021e\u0211\3\2\2\2\u021e\u021c\3\2\2\2\u021fq\3\2\2\2\u0220\u0222"+
		"\5n8\2\u0221\u0220\3\2\2\2\u0222\u0225\3\2\2\2\u0223\u0221\3\2\2\2\u0223"+
		"\u0224\3\2\2\2\u0224\u0226\3\2\2\2\u0225\u0223\3\2\2\2\u0226\u022a\5l"+
		"\67\2\u0227\u0229\5p9\2\u0228\u0227\3\2\2\2\u0229\u022c\3\2\2\2\u022a"+
		"\u0228\3\2\2\2\u022a\u022b\3\2\2\2\u022bs\3\2\2\2\u022c\u022a\3\2\2\2"+
		"\u022d\u0233\5r:\2\u022e\u022f\5@!\2\u022f\u0230\5r:\2\u0230\u0232\3\2"+
		"\2\2\u0231\u022e\3\2\2\2\u0232\u0235\3\2\2\2\u0233\u0231\3\2\2\2\u0233"+
		"\u0234\3\2\2\2\u0234u\3\2\2\2\u0235\u0233\3\2\2\2\u0236\u023c\5t;\2\u0237"+
		"\u0238\5\36\20\2\u0238\u0239\5t;\2\u0239\u023b\3\2\2\2\u023a\u0237\3\2"+
		"\2\2\u023b\u023e\3\2\2\2\u023c\u023a\3\2\2\2\u023c\u023d\3\2\2\2\u023d"+
		"w\3\2\2\2\u023e\u023c\3\2\2\2\u023f\u0240\7\37\2\2\u0240\u0241\5v<\2\u0241"+
		"\u0242\7\61\2\2\u0242y\3\2\2\2\u0243\u0244\5L\'\2\u0244\u0245\7?\2\2\u0245"+
		"\u0246\7\37\2\2\u0246\u0247\5v<\2\u0247\u0248\7\61\2\2\u0248{\3\2\2\2"+
		"\u0249\u024a\7\35\2\2\u024a\u024b\5H%\2\u024b\u024c\7\61\2\2\u024c}\3"+
		"\2\2\2\u024d\u024f\7\27\2\2\u024e\u024d\3\2\2\2\u024e\u024f\3\2\2\2\u024f"+
		"\u0251\3\2\2\2\u0250\u0252\5v<\2\u0251\u0250\3\2\2\2\u0251\u0252\3\2\2"+
		"\2\u0252\u0256\3\2\2\2\u0253\u0256\7\5\2\2\u0254\u0256\7\t\2\2\u0255\u024e"+
		"\3\2\2\2\u0255\u0253\3\2\2\2\u0255\u0254\3\2\2\2\u0256\u0257\3\2\2\2\u0257"+
		"\u0258\7\61\2\2\u0258\177\3\2\2\2\u0259\u025f\5~@\2\u025a\u025f\5X-\2"+
		"\u025b\u025f\5z>\2\u025c\u025f\5\\/\2\u025d\u025f\5^\60\2\u025e\u0259"+
		"\3\2\2\2\u025e\u025a\3\2\2\2\u025e\u025b\3\2\2\2\u025e\u025c\3\2\2\2\u025e"+
		"\u025d\3\2\2\2\u025f\u0081\3\2\2\2\u0260\u0261\t\3\2\2\u0261\u0083\3\2"+
		"\2\2\u0262\u0263\7\60\2\2\u0263\u0268\5H%\2\u0264\u0265\7.\2\2\u0265\u0267"+
		"\5H%\2\u0266\u0264\3\2\2\2\u0267\u026a\3\2\2\2\u0268\u0266\3\2\2\2\u0268"+
		"\u0269\3\2\2\2\u0269\u0085\3\2\2\2\u026a\u0268\3\2\2\2\u026b\u026c\t\4"+
		"\2\2\u026c\u0087\3\2\2\2\u026d\u026f\5\u0082B\2\u026e\u026d\3\2\2\2\u026e"+
		"\u026f\3\2\2\2\u026f\u0270\3\2\2\2\u0270\u0271\5\u0086D\2\u0271\u0273"+
		"\7?\2\2\u0272\u0274\5\u0084C\2\u0273\u0272\3\2\2\2\u0273\u0274\3\2\2\2"+
		"\u0274\u0275\3\2\2\2\u0275\u0279\7\67\2\2\u0276\u0278\5\u0096L\2\u0277"+
		"\u0276\3\2\2\2\u0278\u027b\3\2\2\2\u0279\u0277\3\2\2\2\u0279\u027a\3\2"+
		"\2\2\u027a\u0280\3\2\2\2\u027b\u0279\3\2\2\2\u027c\u027f\5\u008eH\2\u027d"+
		"\u027f\5\u0094K\2\u027e\u027c\3\2\2\2\u027e\u027d\3\2\2\2\u027f\u0282"+
		"\3\2\2\2\u0280\u027e\3\2\2\2\u0280\u0281\3\2\2\2\u0281\u0283\3\2\2\2\u0282"+
		"\u0280\3\2\2\2\u0283\u0284\78\2\2\u0284\u0089\3\2\2\2\u0285\u0287\5\u0082"+
		"B\2\u0286\u0285\3\2\2\2\u0286\u0287\3\2\2\2\u0287\u0288\3\2\2\2\u0288"+
		"\u028b\7?\2\2\u0289\u028c\7\61\2\2\u028a\u028c\5\u0092J\2\u028b\u0289"+
		"\3\2\2\2\u028b\u028a\3\2\2\2\u028c\u008b\3\2\2\2\u028d\u028f\7\67\2\2"+
		"\u028e\u0290\5\u008aF\2\u028f\u028e\3\2\2\2\u0290\u0291\3\2\2\2\u0291"+
		"\u028f\3\2\2\2\u0291\u0292\3\2\2\2\u0292\u0293\3\2\2\2\u0293\u0295\78"+
		"\2\2\u0294\u0296\5x=\2\u0295\u0294\3\2\2\2\u0295\u0296\3\2\2\2\u0296\u008d"+
		"\3\2\2\2\u0297\u0299\5\u0082B\2\u0298\u0297\3\2\2\2\u0298\u0299\3\2\2"+
		"\2\u0299\u029b\3\2\2\2\u029a\u029c\7\31\2\2\u029b\u029a\3\2\2\2\u029b"+
		"\u029c\3\2\2\2\u029c\u029d\3\2\2\2\u029d\u029e\5L\'\2\u029e\u02a2\7?\2"+
		"\2\u029f\u02a3\7\61\2\2\u02a0\u02a3\5x=\2\u02a1\u02a3\5\u008cG\2\u02a2"+
		"\u029f\3\2\2\2\u02a2\u02a0\3\2\2\2\u02a2\u02a1\3\2\2\2\u02a3\u008f\3\2"+
		"\2\2\u02a4\u02aa\7?\2\2\u02a5\u02a6\7\63\2\2\u02a6\u02aa\7\64\2\2\u02a7"+
		"\u02aa\5@!\2\u02a8\u02aa\5\36\20\2\u02a9\u02a4\3\2\2\2\u02a9\u02a5\3\2"+
		"\2\2\u02a9\u02a7\3\2\2\2\u02a9\u02a8\3\2\2\2\u02aa\u0091\3\2\2\2\u02ab"+
		"\u02ac\58\35\2\u02ac\u02ad\5v<\2\u02ad\u02ae\7\61\2\2\u02ae\u02b8\3\2"+
		"\2\2\u02af\u02b3\7\67\2\2\u02b0\u02b2\5\u0080A\2\u02b1\u02b0\3\2\2\2\u02b2"+
		"\u02b5\3\2\2\2\u02b3\u02b1\3\2\2\2\u02b3\u02b4\3\2\2\2\u02b4\u02b6\3\2"+
		"\2\2\u02b5\u02b3\3\2\2\2\u02b6\u02b8\78\2\2\u02b7\u02ab\3\2\2\2\u02b7"+
		"\u02af\3\2\2\2\u02b8\u0093\3\2\2\2\u02b9\u02bb\5\u0082B\2\u02ba\u02b9"+
		"\3\2\2\2\u02ba\u02bb\3\2\2\2\u02bb\u02bd\3\2\2\2\u02bc\u02be\7\31\2\2"+
		"\u02bd\u02bc\3\2\2\2\u02bd\u02be\3\2\2\2\u02be\u02bf\3\2\2\2\u02bf\u02c0"+
		"\5L\'\2\u02c0\u02c1\5\u0090I\2\u02c1\u02c3\79\2\2\u02c2\u02c4\5R*\2\u02c3"+
		"\u02c2\3\2\2\2\u02c3\u02c4\3\2\2\2\u02c4\u02c5\3\2\2\2\u02c5\u02c6\7:"+
		"\2\2\u02c6\u02c7\5\u0092J\2\u02c7\u0095\3\2\2\2\u02c8\u02ca\5L\'\2\u02c9"+
		"\u02c8\3\2\2\2\u02c9\u02ca\3\2\2\2\u02ca\u02cb\3\2\2\2\u02cb\u02cc\7?"+
		"\2\2\u02cc\u02cd\7.\2\2\u02cd\u0097\3\2\2\2\u02ce\u02cf\t\5\2\2\u02cf"+
		"\u0099\3\2\2\2\u02d0\u02d1\7\3\2\2\u02d1\u02d2\5L\'\2\u02d2\u02d3\5\u0098"+
		"M\2\u02d3\u02d4\7?\2\2\u02d4\u02d5\79\2\2\u02d5\u02d6\5R*\2\u02d6\u02d7"+
		"\7:\2\2\u02d7\u02d8\7\61\2\2\u02d8\u009b\3\2\2\2\u02d9\u02da\7\4\2\2\u02da"+
		"\u02db\7>\2\2\u02db\u02dc\7\61\2\2\u02dc\u009d\3\2\2\2\u02dd\u02e0\5\u009a"+
		"N\2\u02de\u02e0\5\u009cO\2\u02df\u02dd\3\2\2\2\u02df\u02de\3\2\2\2\u02e0"+
		"\u02e1\3\2\2\2\u02e1\u02df\3\2\2\2\u02e1\u02e2\3\2\2\2\u02e2\u009f\3\2"+
		"\2\2\u02e3\u02e4\5L\'\2\u02e4\u02e5\7\16\2\2\u02e5\u02e6\79\2\2\u02e6"+
		"\u02e7\7:\2\2\u02e7\u02eb\7\67\2\2\u02e8\u02ea\5\u0080A\2\u02e9\u02e8"+
		"\3\2\2\2\u02ea\u02ed\3\2\2\2\u02eb\u02e9\3\2\2\2\u02eb\u02ec\3\2\2\2\u02ec"+
		"\u02ee\3\2\2\2\u02ed\u02eb\3\2\2\2\u02ee\u02ef\78\2\2\u02ef\u00a1\3\2"+
		"\2\2\u02f0\u02f2\5|?\2\u02f1\u02f0\3\2\2\2\u02f2\u02f5\3\2\2\2\u02f3\u02f1"+
		"\3\2\2\2\u02f3\u02f4\3\2\2\2\u02f4\u02f7\3\2\2\2\u02f5\u02f3\3\2\2\2\u02f6"+
		"\u02f8\5\u009eP\2\u02f7\u02f6\3\2\2\2\u02f7\u02f8\3\2\2\2\u02f8\u02fc"+
		"\3\2\2\2\u02f9\u02fb\5\u0088E\2\u02fa\u02f9\3\2\2\2\u02fb\u02fe\3\2\2"+
		"\2\u02fc\u02fa\3\2\2\2\u02fc\u02fd\3\2\2\2\u02fd\u0300\3\2\2\2\u02fe\u02fc"+
		"\3\2\2\2\u02ff\u0301\5\u00a0Q\2\u0300\u02ff\3\2\2\2\u0300\u0301\3\2\2"+
		"\2\u0301\u00a3\3\2\2\2I\u00dd\u0111\u0119\u011d\u0121\u0124\u0129\u0131"+
		"\u0138\u0145\u014b\u0154\u0158\u015d\u0164\u0169\u0170\u0177\u0180\u0190"+
		"\u0195\u01a1\u01ad\u01ba\u01c0\u01ca\u01cf\u01d3\u01db\u01de\u01e8\u01f2"+
		"\u0200\u020c\u0217\u021e\u0223\u022a\u0233\u023c\u024e\u0251\u0255\u025e"+
		"\u0268\u026e\u0273\u0279\u027e\u0280\u0286\u028b\u0291\u0295\u0298\u029b"+
		"\u02a2\u02a9\u02b3\u02b7\u02ba\u02bd\u02c3\u02c9\u02df\u02e1\u02eb\u02f3"+
		"\u02f7\u02fc\u0300";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}