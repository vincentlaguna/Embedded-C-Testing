ifeq ($(OSTYPE), cygwin)
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.exe
else ifeq ($(OS), Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

PATHU = ../unity/
PATHS = src/
PATHT = test/
PATHI = inc/
PATHB = build/

SRCU