#include "qimage.h"
#include "qpixmap.h"


/* XPM */
static char * pen_xpm[] = {
"32 32 188 2",
"  	c None",
". 	c #656569",
"+ 	c #B2B0B4",
"@ 	c #D9DAE0",
"# 	c #868586",
"$ 	c #BFBEBF",
"% 	c #D2D0D2",
"& 	c #CCCCC9",
"* 	c #464442",
"= 	c #B1AFB3",
"- 	c #C3C1C1",
"; 	c #AFAEAA",
"> 	c #B2B0A5",
", 	c #686865",
"' 	c #555554",
") 	c #D7D4D8",
"! 	c #BEBDBD",
"~ 	c #A7A59F",
"{ 	c #9C9A91",
"] 	c #5B5A56",
"^ 	c #8E8D85",
"/ 	c #717170",
"( 	c #D1CFD2",
"_ 	c #B6B5B5",
": 	c #A5A39C",
"< 	c #8E8E82",
"[ 	c #3C3C38",
"} 	c #615D53",
"| 	c #484843",
"1 	c #B8B7B3",
"2 	c #D3D1D3",
"3 	c #B6B4B1",
"4 	c #9E9D92",
"5 	c #858376",
"6 	c #353531",
"7 	c #2C2B27",
"8 	c #3F3E39",
"9 	c #D9D6D2",
"0 	c #E1DEDE",
"a 	c #CCC9C7",
"b 	c #989688",
"c 	c #7C7A6C",
"d 	c #202221",
"e 	c #23221E",
"f 	c #3E3D38",
"g 	c #E5E2DF",
"h 	c #E2DFDD",
"i 	c #CDCBC7",
"j 	c #A8A6A0",
"k 	c #6A685E",
"l 	c #1A1C1B",
"m 	c #2F2D29",
"n 	c #56554F",
"o 	c #D6D3CE",
"p 	c #E1DEDA",
"q 	c #D3D0CE",
"r 	c #BBB8B4",
"s 	c #91908A",
"t 	c #727067",
"u 	c #2C2C27",
"v 	c #43423B",
"w 	c #CDCAC7",
"x 	c #DEDAD7",
"y 	c #CECBCA",
"z 	c #B2AEA9",
"A 	c #99978E",
"B 	c #68685D",
"C 	c #23231D",
"D 	c #55524B",
"E 	c #D9D7D3",
"F 	c #DFDCDA",
"G 	c #CCCAC7",
"H 	c #B0ACA6",
"I 	c #8E8D84",
"J 	c #4F4D45",
"K 	c #69645C",
"L 	c #77706D",
"M 	c #B9B6B2",
"N 	c #D6D3CF",
"O 	c #D7D3D0",
"P 	c #BFBBB6",
"Q 	c #97948E",
"R 	c #74726A",
"S 	c #3B3B34",
"T 	c #23201B",
"U 	c #CBC8C5",
"V 	c #E0DCDA",
"W 	c #D4D1D0",
"X 	c #B6B2AE",
"Y 	c #79786D",
"Z 	c #2F2F28",
"` 	c #0A0B08",
" .	c #D1CECC",
"..	c #E5E2E0",
"+.	c #D2CFCE",
"@.	c #B4B0AB",
"#.	c #96938B",
"$.	c #5A5950",
"%.	c #161715",
"&.	c #040504",
"*.	c #A7A3A3",
"=.	c #D7D4D1",
"-.	c #DBD8D6",
";.	c #C2BFBB",
">.	c #A3A09A",
",.	c #817E76",
"'.	c #4A4942",
").	c #151613",
"!.	c #040403",
"~.	c #C5C2C1",
"{.	c #E1DDDD",
"].	c #DAD7D8",
"^.	c #CBC6C4",
"/.	c #A7A29B",
"(.	c #848178",
"_.	c #3E3E38",
":.	c #10100D",
"<.	c #95919C",
"[.	c #CDC8C7",
"}.	c #D9D5D2",
"|.	c #BEBBB4",
"1.	c #959288",
"2.	c #625F56",
"3.	c #232420",
"4.	c #070706",
"5.	c #6D6B71",
"6.	c #ACA8AF",
"7.	c #CBC8C9",
"8.	c #B0ABA7",
"9.	c #A19C93",
"0.	c #928E85",
"a.	c #5B5950",
"b.	c #272723",
"c.	c #080908",
"d.	c #828283",
"e.	c #B5B2B3",
"f.	c #BFBEBD",
"g.	c #9E998F",
"h.	c #868174",
"i.	c #68665F",
"j.	c #4D4C44",
"k.	c #191915",
"l.	c #7F7C7A",
"m.	c #CBC3C8",
"n.	c #CDCAD2",
"o.	c #959182",
"p.	c #827F73",
"q.	c #50514C",
"r.	c #1D1C1A",
"s.	c #121310",
"t.	c #8F8B89",
"u.	c #E2DCE1",
"v.	c #CDC8CE",
"w.	c #908C7C",
"x.	c #747469",
"y.	c #424645",
"z.	c #131412",
"A.	c #060606",
"B.	c #A49DA4",
"C.	c #E4DCE7",
"D.	c #C7C2C5",
"E.	c #868171",
"F.	c #716D5C",
"G.	c #333432",
"H.	c #0F0F0E",
"I.	c #9E969F",
"J.	c #E4DAED",
"K.	c #C7C3C6",
"L.	c #6D6B5D",
"M.	c #525247",
"N.	c #232423",
"O.	c #0C0C0B",
"P.	c #8C848E",
"Q.	c #E3D7ED",
"R.	c #ACA7AD",
"S.	c #484A42",
"T.	c #32332E",
"U.	c #070A08",
"V.	c #C2BCC4",
"W.	c #797479",
"X.	c #404039",
"Y.	c #22221F",
"Z.	c #A19993",
"`.	c #55524A",
" +	c #2A2A25",
".+	c #161614",
"++	c #3F3B34",
"@+	c #1D1D1B",
"                                                                ",
"                                                                ",
"                                                                ",
"                                                          . + @ ",
"                                                        # $ % & ",
"                                                    * = - ; > , ",
"                                                  ' ) ! ~ { ] ^ ",
"                                                / ( _ : < [ } | ",
"                                              1 2 3 4 5 6 7 8   ",
"                                            9 0 a b c d e f     ",
"                                          g h i j k l m n       ",
"                                      o p q r s t u v           ",
"                                    w x y z A B C D             ",
"                                  E F G H I J K L               ",
"                              M N O P Q R S T                   ",
"                            U V W X A Y Z `                     ",
"                           ...+.@.#.$.%.&.                      ",
"                      *.=.-.;.>.,.'.).!.                        ",
"                    ~.{.].^./.(._.:.                            ",
"                  <.[.}.|.1.2.3.4.                              ",
"              5.6.7.8.9.0.a.b.c.                                ",
"            d.e.f.g.h.i.j.k.                                    ",
"          l.m.n.o.p.q.r.s.                                      ",
"        t.u.v.w.x.y.z.A.                                        ",
"      B.C.D.E.F.G.H.                                            ",
"    I.J.K.L.M.N.O.                                              ",
"  P.Q.R.S.T.l U.                                                ",
"  V.W.X.Y.z.                                                    ",
"Z.`. +.+                                                        ",
"++@+                                                            ",
"                                                                ",
"                                                                "};
