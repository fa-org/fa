// Generated from e:\GitHub\_\fa\fa\fa\tools\Fa.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FaLexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"AImport", "ALib", "Break", "CC__Cdecl", "CC__FastCall", "CC__StdCall", 
			"Continue", "Class", "Const", "Else", "Enum", "FaMain", "For", "If", 
			"Interface", "Internal", "New", "Public", "Protected", "Private", "Return", 
			"Signed", "Static", "Step", "Struct", "Unsigned", "Use", "While", "Assign", 
			"ReverseOp", "AddAddOp", "SubSubOp", "PointPoint", "PointOp", "AddOp", 
			"SubOp", "StarOp", "DivOp", "ModOp", "OrOp", "AndOp", "XorOp", "Qus", 
			"Comma", "ColonColon", "Colon", "Semi", "Exclam", "QuotFangL", "QuotFangR", 
			"QuotJianL", "QuotJianR", "QuotHuaL", "QuotHuaR", "QuotYuanL", "QuotYuanR", 
			"SimpleEscape", "HexEscape", "UniEscape", "Schar", "BoolLiteral", "IntLiteral", 
			"FloatLiteral", "String1Literal", "NUM", "HEX", "ID_BEGIN", "ID_AFTER", 
			"Id", "Comment1", "Comment2", "WS"
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


	public FaLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Fa.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2B\u0222\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6"+
		"\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3"+
		"\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\n"+
		"\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r"+
		"\3\r\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20"+
		"\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\22"+
		"\3\22\3\22\3\22\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3\24"+
		"\3\24\3\24\3\24\3\24\3\24\3\24\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25"+
		"\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\27\3\27\3\27\3\27\3\27\3\27\3\27"+
		"\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31\3\31\3\32\3\32"+
		"\3\32\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33"+
		"\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\36\3\36\3\37\3\37"+
		"\3 \3 \3 \3!\3!\3!\3\"\3\"\3\"\3#\3#\3$\3$\3%\3%\3&\3&\3\'\3\'\3(\3(\3"+
		")\3)\3*\3*\3+\3+\3,\3,\3-\3-\3.\3.\3.\3/\3/\3\60\3\60\3\61\3\61\3\62\3"+
		"\62\3\63\3\63\3\64\3\64\3\65\3\65\3\66\3\66\3\67\3\67\38\38\39\39\3:\3"+
		":\3:\3:\3:\3:\3:\3:\3:\3:\3:\3:\3:\5:\u019e\n:\3:\5:\u01a1\n:\3:\3:\5"+
		":\u01a5\n:\3;\3;\3;\3;\3;\3;\3<\3<\3<\3<\3<\3<\3<\3<\3=\3=\3=\3=\5=\u01b9"+
		"\n=\3>\3>\3>\3>\3>\3>\3>\3>\3>\5>\u01c4\n>\3?\6?\u01c7\n?\r?\16?\u01c8"+
		"\3@\6@\u01cc\n@\r@\16@\u01cd\3@\3@\6@\u01d2\n@\r@\16@\u01d3\3A\3A\7A\u01d8"+
		"\nA\fA\16A\u01db\13A\3A\3A\3B\3B\3C\3C\5C\u01e3\nC\3D\3D\3D\3D\3D\3D\3"+
		"D\3D\3D\5D\u01ee\nD\3E\3E\3E\3E\3E\3E\3E\3E\3E\3E\5E\u01fa\nE\3F\3F\7"+
		"F\u01fe\nF\fF\16F\u0201\13F\3G\3G\3G\3G\7G\u0207\nG\fG\16G\u020a\13G\3"+
		"G\3G\3G\3G\3G\3H\3H\3H\3H\7H\u0215\nH\fH\16H\u0218\13H\3H\3H\3I\6I\u021d"+
		"\nI\rI\16I\u021e\3I\3I\3\u0208\2J\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23"+
		"\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31"+
		"\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W-Y.[/]\60"+
		"_\61a\62c\63e\64g\65i\66k\67m8o9q:s\2u\2w\2y\2{;}<\177=\u0081>\u0083\2"+
		"\u0085\2\u0087\2\u0089\2\u008b?\u008d@\u008fA\u0091B\3\2\b\6\2\f\f\17"+
		"\17$$^^\3\2\62;\4\2CHch\5\2C\\aac|\4\2\f\f\17\17\5\2\13\f\17\17\"\"\2"+
		"\u0231\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2"+
		"\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3"+
		"\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2"+
		"\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2"+
		"/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2"+
		"\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2"+
		"G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3"+
		"\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2"+
		"\2\2a\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\2g\3\2\2\2\2i\3\2\2\2\2k\3\2\2\2\2"+
		"m\3\2\2\2\2o\3\2\2\2\2q\3\2\2\2\2{\3\2\2\2\2}\3\2\2\2\2\177\3\2\2\2\2"+
		"\u0081\3\2\2\2\2\u008b\3\2\2\2\2\u008d\3\2\2\2\2\u008f\3\2\2\2\2\u0091"+
		"\3\2\2\2\3\u0093\3\2\2\2\5\u009b\3\2\2\2\7\u00a0\3\2\2\2\t\u00a6\3\2\2"+
		"\2\13\u00ae\3\2\2\2\r\u00b9\3\2\2\2\17\u00c3\3\2\2\2\21\u00cc\3\2\2\2"+
		"\23\u00d2\3\2\2\2\25\u00d8\3\2\2\2\27\u00dd\3\2\2\2\31\u00e2\3\2\2\2\33"+
		"\u00e9\3\2\2\2\35\u00ed\3\2\2\2\37\u00f0\3\2\2\2!\u00fa\3\2\2\2#\u0103"+
		"\3\2\2\2%\u0107\3\2\2\2\'\u010e\3\2\2\2)\u0118\3\2\2\2+\u0120\3\2\2\2"+
		"-\u0127\3\2\2\2/\u012e\3\2\2\2\61\u0135\3\2\2\2\63\u013a\3\2\2\2\65\u0141"+
		"\3\2\2\2\67\u014a\3\2\2\29\u014e\3\2\2\2;\u0154\3\2\2\2=\u0156\3\2\2\2"+
		"?\u0158\3\2\2\2A\u015b\3\2\2\2C\u015e\3\2\2\2E\u0161\3\2\2\2G\u0163\3"+
		"\2\2\2I\u0165\3\2\2\2K\u0167\3\2\2\2M\u0169\3\2\2\2O\u016b\3\2\2\2Q\u016d"+
		"\3\2\2\2S\u016f\3\2\2\2U\u0171\3\2\2\2W\u0173\3\2\2\2Y\u0175\3\2\2\2["+
		"\u0177\3\2\2\2]\u017a\3\2\2\2_\u017c\3\2\2\2a\u017e\3\2\2\2c\u0180\3\2"+
		"\2\2e\u0182\3\2\2\2g\u0184\3\2\2\2i\u0186\3\2\2\2k\u0188\3\2\2\2m\u018a"+
		"\3\2\2\2o\u018c\3\2\2\2q\u018e\3\2\2\2s\u01a4\3\2\2\2u\u01a6\3\2\2\2w"+
		"\u01ac\3\2\2\2y\u01b8\3\2\2\2{\u01c3\3\2\2\2}\u01c6\3\2\2\2\177\u01cb"+
		"\3\2\2\2\u0081\u01d5\3\2\2\2\u0083\u01de\3\2\2\2\u0085\u01e2\3\2\2\2\u0087"+
		"\u01ed\3\2\2\2\u0089\u01f9\3\2\2\2\u008b\u01fb\3\2\2\2\u008d\u0202\3\2"+
		"\2\2\u008f\u0210\3\2\2\2\u0091\u021c\3\2\2\2\u0093\u0094\7B\2\2\u0094"+
		"\u0095\7k\2\2\u0095\u0096\7o\2\2\u0096\u0097\7r\2\2\u0097\u0098\7q\2\2"+
		"\u0098\u0099\7t\2\2\u0099\u009a\7v\2\2\u009a\4\3\2\2\2\u009b\u009c\7B"+
		"\2\2\u009c\u009d\7n\2\2\u009d\u009e\7k\2\2\u009e\u009f\7d\2\2\u009f\6"+
		"\3\2\2\2\u00a0\u00a1\7d\2\2\u00a1\u00a2\7t\2\2\u00a2\u00a3\7g\2\2\u00a3"+
		"\u00a4\7c\2\2\u00a4\u00a5\7m\2\2\u00a5\b\3\2\2\2\u00a6\u00a7\7a\2\2\u00a7"+
		"\u00a8\7a\2\2\u00a8\u00a9\7e\2\2\u00a9\u00aa\7f\2\2\u00aa\u00ab\7g\2\2"+
		"\u00ab\u00ac\7e\2\2\u00ac\u00ad\7n\2\2\u00ad\n\3\2\2\2\u00ae\u00af\7a"+
		"\2\2\u00af\u00b0\7a\2\2\u00b0\u00b1\7h\2\2\u00b1\u00b2\7c\2\2\u00b2\u00b3"+
		"\7u\2\2\u00b3\u00b4\7v\2\2\u00b4\u00b5\7e\2\2\u00b5\u00b6\7c\2\2\u00b6"+
		"\u00b7\7n\2\2\u00b7\u00b8\7n\2\2\u00b8\f\3\2\2\2\u00b9\u00ba\7a\2\2\u00ba"+
		"\u00bb\7a\2\2\u00bb\u00bc\7u\2\2\u00bc\u00bd\7v\2\2\u00bd\u00be\7f\2\2"+
		"\u00be\u00bf\7e\2\2\u00bf\u00c0\7c\2\2\u00c0\u00c1\7n\2\2\u00c1\u00c2"+
		"\7n\2\2\u00c2\16\3\2\2\2\u00c3\u00c4\7e\2\2\u00c4\u00c5\7q\2\2\u00c5\u00c6"+
		"\7p\2\2\u00c6\u00c7\7v\2\2\u00c7\u00c8\7k\2\2\u00c8\u00c9\7p\2\2\u00c9"+
		"\u00ca\7w\2\2\u00ca\u00cb\7g\2\2\u00cb\20\3\2\2\2\u00cc\u00cd\7e\2\2\u00cd"+
		"\u00ce\7n\2\2\u00ce\u00cf\7c\2\2\u00cf\u00d0\7u\2\2\u00d0\u00d1\7u\2\2"+
		"\u00d1\22\3\2\2\2\u00d2\u00d3\7e\2\2\u00d3\u00d4\7q\2\2\u00d4\u00d5\7"+
		"p\2\2\u00d5\u00d6\7u\2\2\u00d6\u00d7\7v\2\2\u00d7\24\3\2\2\2\u00d8\u00d9"+
		"\7g\2\2\u00d9\u00da\7n\2\2\u00da\u00db\7u\2\2\u00db\u00dc\7g\2\2\u00dc"+
		"\26\3\2\2\2\u00dd\u00de\7g\2\2\u00de\u00df\7p\2\2\u00df\u00e0\7w\2\2\u00e0"+
		"\u00e1\7o\2\2\u00e1\30\3\2\2\2\u00e2\u00e3\7H\2\2\u00e3\u00e4\7c\2\2\u00e4"+
		"\u00e5\7O\2\2\u00e5\u00e6\7c\2\2\u00e6\u00e7\7k\2\2\u00e7\u00e8\7p\2\2"+
		"\u00e8\32\3\2\2\2\u00e9\u00ea\7h\2\2\u00ea\u00eb\7q\2\2\u00eb\u00ec\7"+
		"t\2\2\u00ec\34\3\2\2\2\u00ed\u00ee\7k\2\2\u00ee\u00ef\7h\2\2\u00ef\36"+
		"\3\2\2\2\u00f0\u00f1\7k\2\2\u00f1\u00f2\7p\2\2\u00f2\u00f3\7v\2\2\u00f3"+
		"\u00f4\7g\2\2\u00f4\u00f5\7t\2\2\u00f5\u00f6\7h\2\2\u00f6\u00f7\7c\2\2"+
		"\u00f7\u00f8\7e\2\2\u00f8\u00f9\7g\2\2\u00f9 \3\2\2\2\u00fa\u00fb\7k\2"+
		"\2\u00fb\u00fc\7p\2\2\u00fc\u00fd\7v\2\2\u00fd\u00fe\7g\2\2\u00fe\u00ff"+
		"\7t\2\2\u00ff\u0100\7p\2\2\u0100\u0101\7c\2\2\u0101\u0102\7n\2\2\u0102"+
		"\"\3\2\2\2\u0103\u0104\7p\2\2\u0104\u0105\7g\2\2\u0105\u0106\7y\2\2\u0106"+
		"$\3\2\2\2\u0107\u0108\7r\2\2\u0108\u0109\7w\2\2\u0109\u010a\7d\2\2\u010a"+
		"\u010b\7n\2\2\u010b\u010c\7k\2\2\u010c\u010d\7e\2\2\u010d&\3\2\2\2\u010e"+
		"\u010f\7r\2\2\u010f\u0110\7t\2\2\u0110\u0111\7q\2\2\u0111\u0112\7v\2\2"+
		"\u0112\u0113\7g\2\2\u0113\u0114\7e\2\2\u0114\u0115\7v\2\2\u0115\u0116"+
		"\7g\2\2\u0116\u0117\7f\2\2\u0117(\3\2\2\2\u0118\u0119\7r\2\2\u0119\u011a"+
		"\7t\2\2\u011a\u011b\7k\2\2\u011b\u011c\7x\2\2\u011c\u011d\7c\2\2\u011d"+
		"\u011e\7v\2\2\u011e\u011f\7g\2\2\u011f*\3\2\2\2\u0120\u0121\7t\2\2\u0121"+
		"\u0122\7g\2\2\u0122\u0123\7v\2\2\u0123\u0124\7w\2\2\u0124\u0125\7t\2\2"+
		"\u0125\u0126\7p\2\2\u0126,\3\2\2\2\u0127\u0128\7u\2\2\u0128\u0129\7k\2"+
		"\2\u0129\u012a\7i\2\2\u012a\u012b\7p\2\2\u012b\u012c\7g\2\2\u012c\u012d"+
		"\7f\2\2\u012d.\3\2\2\2\u012e\u012f\7u\2\2\u012f\u0130\7v\2\2\u0130\u0131"+
		"\7c\2\2\u0131\u0132\7v\2\2\u0132\u0133\7k\2\2\u0133\u0134\7e\2\2\u0134"+
		"\60\3\2\2\2\u0135\u0136\7u\2\2\u0136\u0137\7v\2\2\u0137\u0138\7g\2\2\u0138"+
		"\u0139\7r\2\2\u0139\62\3\2\2\2\u013a\u013b\7u\2\2\u013b\u013c\7v\2\2\u013c"+
		"\u013d\7t\2\2\u013d\u013e\7w\2\2\u013e\u013f\7e\2\2\u013f\u0140\7v\2\2"+
		"\u0140\64\3\2\2\2\u0141\u0142\7w\2\2\u0142\u0143\7p\2\2\u0143\u0144\7"+
		"u\2\2\u0144\u0145\7k\2\2\u0145\u0146\7i\2\2\u0146\u0147\7p\2\2\u0147\u0148"+
		"\7g\2\2\u0148\u0149\7f\2\2\u0149\66\3\2\2\2\u014a\u014b\7w\2\2\u014b\u014c"+
		"\7u\2\2\u014c\u014d\7g\2\2\u014d8\3\2\2\2\u014e\u014f\7y\2\2\u014f\u0150"+
		"\7j\2\2\u0150\u0151\7k\2\2\u0151\u0152\7n\2\2\u0152\u0153\7g\2\2\u0153"+
		":\3\2\2\2\u0154\u0155\7?\2\2\u0155<\3\2\2\2\u0156\u0157\7\u0080\2\2\u0157"+
		">\3\2\2\2\u0158\u0159\7-\2\2\u0159\u015a\7-\2\2\u015a@\3\2\2\2\u015b\u015c"+
		"\7/\2\2\u015c\u015d\7/\2\2\u015dB\3\2\2\2\u015e\u015f\7\60\2\2\u015f\u0160"+
		"\7\60\2\2\u0160D\3\2\2\2\u0161\u0162\7\60\2\2\u0162F\3\2\2\2\u0163\u0164"+
		"\7-\2\2\u0164H\3\2\2\2\u0165\u0166\7/\2\2\u0166J\3\2\2\2\u0167\u0168\7"+
		",\2\2\u0168L\3\2\2\2\u0169\u016a\7\61\2\2\u016aN\3\2\2\2\u016b\u016c\7"+
		"\'\2\2\u016cP\3\2\2\2\u016d\u016e\7~\2\2\u016eR\3\2\2\2\u016f\u0170\7"+
		"(\2\2\u0170T\3\2\2\2\u0171\u0172\7`\2\2\u0172V\3\2\2\2\u0173\u0174\7A"+
		"\2\2\u0174X\3\2\2\2\u0175\u0176\7.\2\2\u0176Z\3\2\2\2\u0177\u0178\7<\2"+
		"\2\u0178\u0179\7<\2\2\u0179\\\3\2\2\2\u017a\u017b\7<\2\2\u017b^\3\2\2"+
		"\2\u017c\u017d\7=\2\2\u017d`\3\2\2\2\u017e\u017f\7#\2\2\u017fb\3\2\2\2"+
		"\u0180\u0181\7]\2\2\u0181d\3\2\2\2\u0182\u0183\7_\2\2\u0183f\3\2\2\2\u0184"+
		"\u0185\7>\2\2\u0185h\3\2\2\2\u0186\u0187\7@\2\2\u0187j\3\2\2\2\u0188\u0189"+
		"\7}\2\2\u0189l\3\2\2\2\u018a\u018b\7\177\2\2\u018bn\3\2\2\2\u018c\u018d"+
		"\7*\2\2\u018dp\3\2\2\2\u018e\u018f\7+\2\2\u018fr\3\2\2\2\u0190\u0191\7"+
		"^\2\2\u0191\u01a5\7)\2\2\u0192\u0193\7^\2\2\u0193\u01a5\7$\2\2\u0194\u0195"+
		"\7^\2\2\u0195\u01a5\7^\2\2\u0196\u0197\7^\2\2\u0197\u01a5\7p\2\2\u0198"+
		"\u0199\7^\2\2\u0199\u01a5\7t\2\2\u019a\u01a0\7^\2\2\u019b\u019d\7\17\2"+
		"\2\u019c\u019e\7\f\2\2\u019d\u019c\3\2\2\2\u019d\u019e\3\2\2\2\u019e\u01a1"+
		"\3\2\2\2\u019f\u01a1\7\f\2\2\u01a0\u019b\3\2\2\2\u01a0\u019f\3\2\2\2\u01a1"+
		"\u01a5\3\2\2\2\u01a2\u01a3\7^\2\2\u01a3\u01a5\7v\2\2\u01a4\u0190\3\2\2"+
		"\2\u01a4\u0192\3\2\2\2\u01a4\u0194\3\2\2\2\u01a4\u0196\3\2\2\2\u01a4\u0198"+
		"\3\2\2\2\u01a4\u019a\3\2\2\2\u01a4\u01a2\3\2\2\2\u01a5t\3\2\2\2\u01a6"+
		"\u01a7\7^\2\2\u01a7\u01a8\7z\2\2\u01a8\u01a9\3\2\2\2\u01a9\u01aa\5\u0085"+
		"C\2\u01aa\u01ab\5\u0085C\2\u01abv\3\2\2\2\u01ac\u01ad\7^\2\2\u01ad\u01ae"+
		"\7w\2\2\u01ae\u01af\3\2\2\2\u01af\u01b0\5\u0085C\2\u01b0\u01b1\5\u0085"+
		"C\2\u01b1\u01b2\5\u0085C\2\u01b2\u01b3\5\u0085C\2\u01b3x\3\2\2\2\u01b4"+
		"\u01b9\5s:\2\u01b5\u01b9\5u;\2\u01b6\u01b9\5w<\2\u01b7\u01b9\n\2\2\2\u01b8"+
		"\u01b4\3\2\2\2\u01b8\u01b5\3\2\2\2\u01b8\u01b6\3\2\2\2\u01b8\u01b7\3\2"+
		"\2\2\u01b9z\3\2\2\2\u01ba\u01bb\7v\2\2\u01bb\u01bc\7t\2\2\u01bc\u01bd"+
		"\7w\2\2\u01bd\u01c4\7g\2\2\u01be\u01bf\7h\2\2\u01bf\u01c0\7c\2\2\u01c0"+
		"\u01c1\7n\2\2\u01c1\u01c2\7u\2\2\u01c2\u01c4\7g\2\2\u01c3\u01ba\3\2\2"+
		"\2\u01c3\u01be\3\2\2\2\u01c4|\3\2\2\2\u01c5\u01c7\5\u0083B\2\u01c6\u01c5"+
		"\3\2\2\2\u01c7\u01c8\3\2\2\2\u01c8\u01c6\3\2\2\2\u01c8\u01c9\3\2\2\2\u01c9"+
		"~\3\2\2\2\u01ca\u01cc\5\u0083B\2\u01cb\u01ca\3\2\2\2\u01cc\u01cd\3\2\2"+
		"\2\u01cd\u01cb\3\2\2\2\u01cd\u01ce\3\2\2\2\u01ce\u01cf\3\2\2\2\u01cf\u01d1"+
		"\5E#\2\u01d0\u01d2\5\u0083B\2\u01d1\u01d0\3\2\2\2\u01d2\u01d3\3\2\2\2"+
		"\u01d3\u01d1\3\2\2\2\u01d3\u01d4\3\2\2\2\u01d4\u0080\3\2\2\2\u01d5\u01d9"+
		"\7$\2\2\u01d6\u01d8\5y=\2\u01d7\u01d6\3\2\2\2\u01d8\u01db\3\2\2\2\u01d9"+
		"\u01d7\3\2\2\2\u01d9\u01da\3\2\2\2\u01da\u01dc\3\2\2\2\u01db\u01d9\3\2"+
		"\2\2\u01dc\u01dd\7$\2\2\u01dd\u0082\3\2\2\2\u01de\u01df\t\3\2\2\u01df"+
		"\u0084\3\2\2\2\u01e0\u01e3\5\u0083B\2\u01e1\u01e3\t\4\2\2\u01e2\u01e0"+
		"\3\2\2\2\u01e2\u01e1\3\2\2\2\u01e3\u0086\3\2\2\2\u01e4\u01ee\t\5\2\2\u01e5"+
		"\u01e6\7^\2\2\u01e6\u01e7\7w\2\2\u01e7\u01e8\3\2\2\2\u01e8\u01e9\5\u0085"+
		"C\2\u01e9\u01ea\5\u0085C\2\u01ea\u01eb\5\u0085C\2\u01eb\u01ec\5\u0085"+
		"C\2\u01ec\u01ee\3\2\2\2\u01ed\u01e4\3\2\2\2\u01ed\u01e5\3\2\2\2\u01ee"+
		"\u0088\3\2\2\2\u01ef\u01fa\5\u0083B\2\u01f0\u01fa\t\5\2\2\u01f1\u01f2"+
		"\7^\2\2\u01f2\u01f3\7w\2\2\u01f3\u01f4\3\2\2\2\u01f4\u01f5\5\u0085C\2"+
		"\u01f5\u01f6\5\u0085C\2\u01f6\u01f7\5\u0085C\2\u01f7\u01f8\5\u0085C\2"+
		"\u01f8\u01fa\3\2\2\2\u01f9\u01ef\3\2\2\2\u01f9\u01f0\3\2\2\2\u01f9\u01f1"+
		"\3\2\2\2\u01fa\u008a\3\2\2\2\u01fb\u01ff\5\u0087D\2\u01fc\u01fe\5\u0089"+
		"E\2\u01fd\u01fc\3\2\2\2\u01fe\u0201\3\2\2\2\u01ff\u01fd\3\2\2\2\u01ff"+
		"\u0200\3\2\2\2\u0200\u008c\3\2\2\2\u0201\u01ff\3\2\2\2\u0202\u0203\7\61"+
		"\2\2\u0203\u0204\7,\2\2\u0204\u0208\3\2\2\2\u0205\u0207\13\2\2\2\u0206"+
		"\u0205\3\2\2\2\u0207\u020a\3\2\2\2\u0208\u0209\3\2\2\2\u0208\u0206\3\2"+
		"\2\2\u0209\u020b\3\2\2\2\u020a\u0208\3\2\2\2\u020b\u020c\7,\2\2\u020c"+
		"\u020d\7\61\2\2\u020d\u020e\3\2\2\2\u020e\u020f\bG\2\2\u020f\u008e\3\2"+
		"\2\2\u0210\u0211\7\61\2\2\u0211\u0212\7\61\2\2\u0212\u0216\3\2\2\2\u0213"+
		"\u0215\n\6\2\2\u0214\u0213\3\2\2\2\u0215\u0218\3\2\2\2\u0216\u0214\3\2"+
		"\2\2\u0216\u0217\3\2\2\2\u0217\u0219\3\2\2\2\u0218\u0216\3\2\2\2\u0219"+
		"\u021a\bH\2\2\u021a\u0090\3\2\2\2\u021b\u021d\t\7\2\2\u021c\u021b\3\2"+
		"\2\2\u021d\u021e\3\2\2\2\u021e\u021c\3\2\2\2\u021e\u021f\3\2\2\2\u021f"+
		"\u0220\3\2\2\2\u0220\u0221\bI\2\2\u0221\u0092\3\2\2\2\23\2\u019d\u01a0"+
		"\u01a4\u01b8\u01c3\u01c8\u01cd\u01d3\u01d9\u01e2\u01ed\u01f9\u01ff\u0208"+
		"\u0216\u021e\3\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}