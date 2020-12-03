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
#Determine the source files
SRCU = $(PATHU)unity.c
SRCS = $(wildcard) $(PATHS)*.c)
SRCT = $(wildcard) $(PATHT)*.c)
SRC = $(SRCU) $(SRCS) $(SRCT)
#Files we are to work with
OBJU = $(patsubst $(PATHU)%.c,$(PATHB)%.o,$(SRCU))
OBJS = $(patsubst $(PATHS)%.c,$(PATHB)%.o,$(SRCS))
OBJT = $(patsubst $(PATHT)%.c,$(PATHT)%.o,$(SRCT))
OBJ = $(OBJU) $(OBJS) $(OBJT)
#Other relevant files
DEP = $(PATHU)unity.h $(PATHU)unity_internals.h
TGT = $(PATHB)test $(TARGET_EXTENSION)
#Tool definitions
CC=gcc
CFLAGS=-I. -I$(PATHU) -I$(PATHI) -I$(PATHS) -DTEST
