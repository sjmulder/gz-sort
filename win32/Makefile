ZLIB     = win32\vendor\zlib-1.2.11
PTHREADS = win32\vendor\pthreads-w32-2.9.1
GETOPT   = win32\vendor\getopt-win32

CFLAGS = /nologo /O2 /W3 /D _CRT_SECURE_NO_WARNINGS \
         /I $(ZLIB) /I $(PTHREADS) /I $(GETOPT)

LDLIBS = $(ZLIB)\zdll.lib \
         $(PTHREADS)\pthreadVC2.lib \
         $(GETOPT)\getopt.lib

all: gz-sort.exe

deps: .phony
	cd $(ZLIB)     && $(MAKE) /nologo /f win32\Makefile.msc
	cd $(PTHREADS) && $(MAKE) /nologo VC
	cd $(GETOPT)   && $(MAKE) /nologo
	copy $(ZLIB)\zlib1.dll
	copy $(PTHREADS)\pthreadVC2.dll
	copy $(GETOPT)\getopt.dll

dist: all .phony
	if exist win32\dist rmdir /s/q win32\dist
	md win32\dist
	copy README.md      win32\dist
	copy LICENSE        win32\dist\LICENSE.txt
	copy gz-sort.exe    win32\dist
	copy zlib1.dll      win32\dist
	copy pthreadVC2.dll win32\dist
	copy getopt.dll     win32\dist
	copy $(GETOPT)\LICENSE   win32\dist\LICENSE.getopt.txt
	copy $(PTHREADS)\COPYING win32\dist\LICENSE.pthreads-w32.txt

clean: .phony
	cd $(ZLIB)     && $(MAKE) /nologo /f win32\makefile.msc clean
	cd $(PTHREADS) && $(MAKE) /nologo clean
	cd $(GETOPT)   && $(MAKE) /nologo clean
	if exist $(PTHREADS)\pthreadVC2.dll del $(PTHREADS)\pthreadVC2.dll 
	if exist zlib1.dll      del zlib1.dll
	if exist pthreadVC2.dll del pthreadVC2.dll
	if exist getopt.dll     del getopt.dll
	if exist gz-sort.exe    del gz-sort.exe
	if exist gz-sort.obj    del gz-sort.obj
	if exist win32\dist     rmdir /s/q win32\dist

gz-sort.exe: gz-sort.c deps
	$(CC) $(CFLAGS) $(LDFLAGS) gz-sort.c $(LDLIBS)

.phony:
