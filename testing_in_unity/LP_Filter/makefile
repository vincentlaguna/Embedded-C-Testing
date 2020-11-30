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
# Path Definitions
PATHU = ../unity/
PATHS = src/
PATHT = test/
PATHI = inc/
PATHB = build/
#Files we are to work with
SRCU = $(PATHU)unity.c
SRCS = $(wildcard) $(PATHS)*.c)
SRCT = $(wildcard) $(PATHT)*.c)
SRC = $(SRCU) $(SRCS) $(SRCT)
#Other relevant files
OBJU = $(patsubst $(PATHU)%.c,$(PATHB)%.o,$(SRCU))
OBJS = $(patsubst $(PATHS)%.c,$(PATHB)%.o,$(SRCS))
