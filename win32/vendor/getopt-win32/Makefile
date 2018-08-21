CFLAGS = /nologo /W4 /LD /DEXPORTS_GETOPT

all: getopt.dll

getopt.dll: getopt.c getopt.h
	$(CC) $(CFLAGS) $(LDFLAGS) getopt.c $(LDLIBS)

clean: .phony
	if exist getopt.exp del getopt.exp
	if exist getopt.lib del getopt.lib
	if exist getopt.obj del getopt.obj
	if exist getopt.dll del getopt.dll

.phony:
