NO2PATH  = ./Josephus/
NO8PATH  = ./MST/
NO10PATH = ./Sort/

WINCC    = /usr/local/i386-mingw32-4.3.0/bin/i386-mingw32-g++

default : 
	make No.2.exe
	make No.8.exe
	make No.10.exe

No.2.exe : main.cpp $(NO2PATH)Cli.cpp $(NO2PATH)CircleList.cpp
	$(WINCC) main.cpp $(NO2PATH)Cli.cpp $(NO2PATH)CircleList.cpp -finput-charset=UTF-8 -fexec-charset=gbk -D__NO_2__ -o No.2.exe

No.8.exe : main.cpp $(NO8PATH)Cli.cpp $(NO8PATH)MST.cpp
	$(WINCC) main.cpp $(NO8PATH)Cli.cpp $(NO8PATH)MST.cpp -finput-charset=UTF-8 -fexec-charset=gbk -D__NO_8__ -o No.8.exe

No.10.exe : main.cpp $(NO10PATH)Cli.cpp $(NO10PATH)Sort.cpp
	$(WINCC) main.cpp $(NO10PATH)Cli.cpp $(NO10PATH)Sort.cpp -finput-charset=UTF-8 -fexec-charset=gbk -D__NO_10__ -o No.10.exe