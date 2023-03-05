..\out\msvc\Win32\Debug\2c -v
..\out\msvc\Win32\Debug\2c --bin    -IFELSsM=comp-lang/c-cxx   --lf _2cver.h
..\out\msvc\Win32\Debug\2c          -IFELSaCRM=comp-lang/c-cxx  --lf _2cver.h _2cver1
..\out\msvc\Win32\Debug\2c  --base64-len=76 -IFELSsRM=comp-lang/c-cxx   --lf _2cver.h _2cver2
..\out\msvc\Win32\Debug\2c  -IFELSaCRM=comp-lang/c-cxx  --lf _2cver.h _2cver3
..\out\msvc\Win32\Debug\2c --help > help.txt
..\out\msvc\Win32\Debug\2c --wiki --help > wiki.txt
..\out\msvc\Win32\Debug\2c --bash --help > bash-complete.txt
..\out\msvc\Win32\Debug\2c --clink --help > clink-complete.txt
..\out\msvc\Win32\Debug\2c --console-colors=none
..\out\msvc\Win32\Debug\2c --console-colors=abr

..\out\msvc\Win32\Debug\2c --autocomplete-install

rem --wiki
rem --bash-complete
rem --static -S
rem --mime -M
rem --last-modified -I
rem --filename -F
rem --output-string -s
rem --output-array -a
rem --non-const -C
rem --compress-ws
rem --output-string
g++ test.cpp 
a > _2cver_2.h
del a.exe