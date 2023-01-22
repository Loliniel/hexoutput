# hexoutput


hexoutput is a simple function in C to accept a file and output it's contents as in a readable hexadecimal format.  For example a .png file will show as the following.  These are only the first 256 bytes from the .png file.  The file can be compiled with the supplied Makefile.

## Installation
Just a simple Makefile
```bash
make
```

## Usage
To view information on usage.
```bash
hex -h
```

To show the hex output of the example file, lita.png
```bash
hex -f lita.png
```

## Sample output of the first 256 bytes from the example file.

```bash
00000000 89 50 4E 47 0D 0A 1A 0A 00 00 00 0D 49 48 44 52 ‰PNG........IHDR
00000010 00 00 02 BC 00 00 02 BC 08 02 00 00 00 82 D8 FB ...¼...¼.....‚Øû
00000020 14 00 00 00 01 73 52 47 42 00 AE CE 1C E9 00 00 .....sRGB.®Î.é..
00000030 00 04 67 41 4D 41 00 00 B1 8F 0B FC 61 05 00 00 ..gAMA..±.üa...
00000040 00 09 70 48 59 73 00 00 0E C3 00 00 0E C3 01 C7 ..pHYs...Ã...Ã.Ç
00000050 6F A8 64 00 00 FF A5 49 44 41 54 78 5E EC DD 69 o¨d..ÿ¥IDATx^ìÝi
00000060 D3 AD DB 55 D7 FF EC D3 A7 25 3D 5D 20 21 24 04 Ó­ÛU×ÿìÓ§%=] !$.
00000070 08 20 02 1A B1 A9 BF 0D 3E F2 81 6F 49 51 90 D0 . ..±©¿.>òoIQÐ
00000080 6B 41 61 89 8A 55 96 3C D0 17 40 69 69 95 5A 0A kAa‰ŠU–<Ð.@ii•Z.
00000090 11 23 92 D0 93 90 3E 90 8E 34 27 A7 D9 A7 CB F9 .#’Ð“>Ž4'§Ù§Ëù
000000A0 CF 6B 7D AE BD F6 77 EF B9 D7 DA EB CE C9 C1 84 Ïk}®½öwï¹×ÚëÎÉÁ„
000000B0 CC 5F D5 19 7B DE 63 8E 39 BA 39 AF 75 C6 98 6B Ì_Õ.{ÞcŽ9º9¯uÆ˜k
000000C0 DD EB BE F6 63 3F F6 63 2F 78 C1 0B 9E 7D F6 D9 Ýë¾öc?öc/xÁ.ž}öÙ
000000D0 41 EF BD F7 DE 41 EF BB EF BE 41 1F 7B EC B1 41 Aï½÷ÞAï»ï¾A{ì±A
000000E0 EF B9 E7 9E 23 BD 76 ED DA 91 E2 90 47 9F 79 E6 ï¹çž#½víÚ‘âGŸyæ
000000F0 99 41 1F 78 E0 81 E3 F8 E9 A7 9F 1E 94 B6 2F 7C ™Axàãøé§Ÿ.”¶/|
00000100 E1 0B 47 FA E0 83 0F 0E 0A D5 6C D5 53 4F 3D 35 á.Gúàƒ...ÕlÕSO=5
```
