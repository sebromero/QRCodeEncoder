// QR_Encode.h : CQR_Encode クラス宣言およびインターフェイス定義
// Date 2006/05/17	Ver. 1.22	Psytec Inc.

/////////////////////////////////////////////////////////////////////////////
// 定数

// 誤り訂正レベル
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

// データモード
#define QR_MODE_NUMERAL		0
#define QR_MODE_ALPHABET	1
#define QR_MODE_8BIT		2
#define QR_MODE_KANJI		3

// バージョン(型番)グループ
#define QR_VRESION_S	0 // 1 ～ 9
#define QR_VRESION_M	1 // 10 ～ 26
#define QR_VRESION_L	2 // 27 ～ 40

#define MAX_ALLCODEWORD	 3706 // 総コードワード数最大値
#define MAX_DATACODEWORD 2956 // データコードワード最大値(バージョン40-L)
#define MAX_CODEBLOCK	  153 // ブロックデータコードワード数最大値(ＲＳコードワードを含む)
#define MAX_MODULESIZE	  177 // 一辺モジュール数最大値

// ビットマップ描画時マージン
#define QR_MARGIN	4


/////////////////////////////////////////////////////////////////////////////
typedef struct tagRS_BLOCKINFO
{
	NSInteger ncRSBlock;		// ＲＳブロック数
	NSInteger ncAllCodeWord;	// ブロック内コードワード数
	NSInteger ncDataCodeWord;	// データコードワード数(コードワード数 - ＲＳコードワード数)

} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/////////////////////////////////////////////////////////////////////////////
// QRコードバージョン(型番)関連情報

typedef struct tagQR_VERSIONINFO
{
	NSInteger nVersionNo;	   // バージョン(型番)番号(1～40)
	NSInteger ncAllCodeWord; // 総コードワード数

	// 以下配列添字は誤り訂正率(0 = L, 1 = M, 2 = Q, 3 = H) 
	NSInteger ncDataCodeWord[4];	// データコードワード数(総コードワード数 - ＲＳコードワード数)

	NSInteger ncAlignPoint;	// アライメントパターン座標数
	NSInteger nAlignPoint[6];	// アライメントパターン中心座標

	RS_BLOCKINFO RS_BlockInfo1[4]; // ＲＳブロック情報(1)
	RS_BLOCKINFO RS_BlockInfo2[4]; // ＲＳブロック情報(2)

} QR_VERSIONINFO, *LPQR_VERSIONINFO;

typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef BYTE* LPBYTE;
typedef const char* LPCSTR;

#define ZeroMemory(Destination,Length) memset((Destination),0,(Length))


@interface CQR_Encode : NSObject
{
    @public
    NSInteger m_nLevel;		// 誤り訂正レベル
    NSInteger m_nVersion;		// バージョン(型番)
    BOOL m_bAutoExtent;	// バージョン(型番)自動拡張指定フラグ
    NSInteger m_nMaskingNo;	// マスキングパターン番号
    NSInteger m_nSymbleSize;
    BYTE m_byModuleData[MAX_MODULESIZE][MAX_MODULESIZE]; // [x][y]
    
    @private
    NSInteger m_ncDataCodeWordBit; // データコードワードビット長
    BYTE m_byDataCodeWord[MAX_DATACODEWORD]; // 入力データエンコードエリア
    NSInteger m_ncDataBlock;
    BYTE m_byBlockMode[MAX_DATACODEWORD];
    NSInteger m_nBlockLength[MAX_DATACODEWORD];
    NSInteger m_ncAllCodeWord; // 総コードワード数(ＲＳ誤り訂正データを含む)
    BYTE m_byAllCodeWord[MAX_ALLCODEWORD]; // 総コードワード算出エリア
    BYTE m_byRSWork[MAX_CODEBLOCK]; // ＲＳコードワード算出ワーク
}

    -(BOOL) EncodeData:(NSInteger) nLevel nVersion:(NSInteger) nVersion bAutoExtent:(BOOL) bAutoExtent nMaskingNo:(NSInteger)nMaskingNo lpsSource:(LPCSTR) lpsSource ncSource: (NSInteger) ncSource;
    -(NSInteger) GetEncodeVersion:(NSInteger) nVersion lpsSource:(LPCSTR) lpsSource ncLength:(NSInteger) ncLength;
    -(BOOL) EncodeSourceData:(LPCSTR) lpsSource ncLength:(NSInteger) ncLength nVerGroup:(NSInteger) nVerGroup;

    -(NSInteger) GetBitLength:(BYTE) nMode ncData:(NSInteger) ncData nVerGroup:(NSInteger) nVerGroup;
    -(NSInteger)SetBitStream:(NSInteger) nIndex wData:(WORD) wData ncData:(NSInteger) ncData;

    -(BOOL) IsNumeralData:(unsigned char) c;
    -(BOOL) IsAlphabetData:(unsigned char) c;
    -(BOOL) IsKanjiData:(unsigned char) c1 c2:(unsigned char) c2;

    -(BYTE) AlphabetToBinaly:(unsigned char) c;
    -(WORD) KanjiToBinaly:(WORD) wc;

    -(void) GetRSCodeWord:(LPBYTE)lpbyRSWork ncDataCodeWord:(NSInteger)ncDataCodeWord ncRSCodeWord:(NSInteger) ncRSCodeWord;
	-(void) FormatModule;
	-(void) SetFunctionModule;
    -(void) SetFinderPattern:(NSInteger)x y:(NSInteger)y;
    -(void) SetAlignmentPattern:(NSInteger)x y:(NSInteger)y;
	-(void) SetVersionPattern;
	-(void) SetCodeWordPattern;
    -(void) SetMaskingPattern:(NSInteger) nPatternNo;
    -(void) SetFormatInfoPattern:(NSInteger) nPatternNo;
	-(NSInteger) CountPenalty;
@end
