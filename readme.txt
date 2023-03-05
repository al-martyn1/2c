Возможно, что у арма в рантайме есть процедура декомпрессии.
Вохоже, что применен алгоритм LZ
https://en.wikipedia.org/wiki/LZ77_and_LZ78
https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Storer%E2%80%93Szymanski

https://community.arm.com/developer/tools-software/tools/f/keil-forum/32144/hard-fault-caused-by-scatter-loader-decompress-routine

Application startup - http://www.keil.com/support/man/docs/armclang_intro/armclang_intro_asa1505906246660.htm
Considerations when working with RW data compression - http://www.keil.com/support/man/docs/armlink/armlink_pge1362065933683.htm
Optimization with RW data compression - http://www.keil.com/support/man/docs/armlink/armlink_pge1362065930871.htm
How the linker chooses a compressor - http://www.keil.com/support/man/docs/armlink/armlink_pge1362065931542.htm
Options available to override the compression algorithm used by the linker - http://www.keil.com/support/man/docs/armlink/armlink_pge1362065932292.htm
armlink --datacompressor list
…
Num     Compression algorithm
========================================================
0       Run-length encoding
1       Run-length encoding, with LZ77 on small-repeats
2       Complex LZ77 compression

http://users.ece.utexas.edu/~valvano/Volume1/uvision/DUI0377C_using_the_linker.pdf

Заодно нашел про scatter file - http://www.keil.com/support/man/docs/armlink/armlink_pge1362075650322.htm
Прикопаю тут

10.3.4 Intrinsic Functions
https://www.sciencedirect.com/topics/computer-science/compiler-intrinsics

CHAPTER 10 - Cortex-M3 Programming - https://www.sciencedirect.com/science/article/pii/B9781856179638000132

Compiler intrinsics - http://www.keil.com/support/man/docs/armcc/armcc_chr1359124210895.htm
ARM assembler instruction intrinsics - http://www.keil.com/support/man/docs/armcc/armcc_chr1359124211394.htm
Generic intrinsics - http://www.keil.com/support/man/docs/armcc/armcc_chr1359124211659.htm

GNU built-in functions - http://www.keil.com/support/man/docs/armcc/armcc_chr1359125006834.htm
__pure - http://www.keil.com/support/man/docs/armcc/armcc_chr1359124969049.htm
__attribute__((const)) - http://www.keil.com/support/man/docs/armcc/armcc_chr1359124974244.htm

Compiler intrinsics for inserting native instructions - http://www.keil.com/support/man/docs/armcc/armcc_chr1359124212424.htm
__rbit intrinsic - http://www.keil.com/support/man/docs/armcc/armcc_chr1359125000344.htm
__rev intrinsic - 32-bit big-endian data value into a little-endian data value - http://www.keil.com/support/man/docs/armcc/armcc_chr1359125000562.htm