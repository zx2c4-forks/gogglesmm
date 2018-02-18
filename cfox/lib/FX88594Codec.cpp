#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "FXArray.h"
#include "FXHash.h"
#include "FXStream.h"
#include "FXTextCodec.h"
#include "FX88594Codec.h"

namespace FX {

FXIMPLEMENT(FX88594Codec,FXTextCodec,NULL,0)


//// Created by codec tool on 03/25/2005 from: 8859-4.TXT ////
static const unsigned short forward_data[256]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,
   144,  145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
   160,  260,  312,  342,  164,  296,  315,  167,  168,  352,  274,  290,  358,  173,  381,  175,
   176,  261,  731,  343,  180,  297,  316,  711,  184,  353,  275,  291,  359,  330,  382,  331,
   256,  193,  194,  195,  196,  197,  198,  302,  268,  201,  280,  203,  278,  205,  206,  298,
   272,  325,  332,  310,  212,  213,  214,  215,  216,  370,  218,  219,  220,  360,  362,  223,
   257,  225,  226,  227,  228,  229,  230,  303,  269,  233,  281,  235,  279,  237,  238,  299,
   273,  326,  333,  311,  244,  245,  246,  247,  248,  371,  250,  251,  252,  361,  363,  729,
  };


static const unsigned char reverse_plane[17]={
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  };

static const unsigned char reverse_pages[65]={
  0,  46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,
  46,
  };

static const unsigned short reverse_block[110]={
  0,   16,  32,  48,  64,  80,  96,  112, 128, 144, 160, 176, 191, 206, 222, 237,
  253, 269, 283, 299, 312, 326, 342, 356, 371, 371, 371, 371, 371, 371, 371, 371,
  371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 380, 388, 371, 371,
  371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371,
  371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371,
  371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371,
  371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371, 371,
  };

static const unsigned char reverse_data[404]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,
   144,  145,  146,  147,  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
   160,  26,   26,   26,   164,  26,   26,   167,  168,  26,   26,   26,   26,   173,  26,   175,
   176,  26,   26,   26,   180,  26,   26,   26,   184,  26,   26,   26,   26,   26,   26,   26,
   193,  194,  195,  196,  197,  198,  26,   26,   201,  26,   203,  26,   205,  206,  26,   26,
   26,   26,   212,  213,  214,  215,  216,  26,   218,  219,  220,  26,   26,   223,  26,   225,
   226,  227,  228,  229,  230,  26,   26,   233,  26,   235,  26,   237,  238,  26,   26,   26,
   26,   244,  245,  246,  247,  248,  26,   250,  251,  252,  26,   26,   26,   192,  224,  26,
   26,   161,  177,  26,   26,   26,   26,   26,   26,   200,  232,  26,   26,   208,  240,  170,
   186,  26,   26,   204,  236,  202,  234,  26,   26,   26,   26,   26,   26,   171,  187,  26,
   26,   26,   26,   165,  181,  207,  239,  26,   26,   199,  231,  26,   26,   26,   26,   26,
   26,   211,  243,  162,  26,   26,   166,  182,  26,   26,   26,   26,   26,   209,  241,  26,
   26,   26,   189,  191,  210,  242,  26,   26,   26,   26,   26,   26,   163,  179,  26,   26,
   26,   26,   26,   26,   26,   26,   169,  185,  26,   26,   26,   26,   172,  188,  221,  253,
   222,  254,  26,   26,   26,   26,   217,  249,  26,   26,   26,   26,   26,   26,   26,   26,
   26,   174,  190,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   183,  26,   26,   26,   26,   26,   26,   26,   26,   26,   255,  26,   178,
   26,   26,   26,   26,
  };


FXint FX88594Codec::mb2wc(FXwchar& wc,const FXchar* src,FXint nsrc) const {
  if(nsrc<1) return -1;
  wc=forward_data[(FXuchar)src[0]];
  return 1;
  }


FXint FX88594Codec::wc2mb(FXchar* dst,FXint ndst,FXwchar wc) const {
  if(ndst<1) return -1;
  dst[0]=reverse_data[reverse_block[reverse_pages[reverse_plane[wc>>16]+((wc>>10)&63)]+((wc>>4)&63)]+(wc&15)];
  return 1;
  }

FXint FX88594Codec::mibEnum() const {
  return 7;
  }


const FXchar* FX88594Codec::name() const {
  return "ISO-8859-4";
  }


const FXchar* FX88594Codec::mimeName() const {
  return "ISO-8859-4";
  }


const FXchar* const* FX88594Codec::aliases() const {
  static const FXchar *const list[]={"iso8859-4","ISO-8859-4","ISO_8859-4","latin4","iso-ir-110","l4","csISOLatin4",NULL};
  return list;
  }

}

