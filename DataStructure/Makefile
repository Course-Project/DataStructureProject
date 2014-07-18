NO2PATH           = ./Josephus/
NO8PATH           = ./MST/
NO10PATH          = ./Sort/

NO2FILES          = main.cpp $(NO2PATH)Cli.cpp $(NO2PATH)CircleList.cpp
NO8FILES          = main.cpp $(NO8PATH)Cli.cpp $(NO8PATH)MST.cpp
NO10FILES         = main.cpp $(NO10PATH)Cli.cpp $(NO10PATH)Sort.cpp

win-char-encoding = -finput-charset=UTF-8 -fexec-charset=gbk

WINCOMPILER       = /usr/local/i386-mingw32-4.3.0/bin/i386-mingw32-g++
COMPILER          = g++

default :
	make No.2
	make No.8
	make No.10
	make No.2.exe
	make No.8.exe
	make No.10.exe

win :
	make No.2.exe
	make No.8.exe
	make No.10.exe

mac :
	make No.2
	make No.8
	make No.10

clean :
	rm No.2 No.8 No.10 No.2.exe No.8.exe No.10.exe

No.2.exe : $(NO2FILES)
	$(WINCOMPILER) $(NO2FILES) $(win-char-encoding) -D__NO_2__ -o No.2.exe

No.8.exe : $(NO8FILES)
	$(WINCOMPILER) $(NO8FILES) $(win-char-encoding) -D__NO_8__ -o No.8.exe

No.10.exe : $(NO10FILES)
	$(WINCOMPILER) $(NO10FILES) $(win-char-encoding) -D__NO_10__ -o No.10.exe

No.2 : $(NO2FILES)
	$(COMPILER) $(NO2FILES) -D__NO_2__ -o No.2

No.8 : $(NO8FILES)
	$(COMPILER) $(NO8FILES) -D__NO_8__ -o No.8

No.10 : $(NO10FILES)
	$(COMPILER) $(NO10FILES) -D__NO_10__ -o No.10
