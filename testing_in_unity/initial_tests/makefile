ifeq ($(OSTYPE), cygwin)
	CLEANUP = rm -f
	MKDIR = -p
	TARGET_EXTENSION = .out
else ifeq ($(OS), Windows_NT
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION = .exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION = .out
endif

CC = gcc
CFLAGS = -I. -I$(PATHU) -DTEST

PATHU = ../unity/
PATHS = 
PATHT = 
PATHB = build/

# Working files
SRC = Test.c src.c unity.c
OBJ = $(patsubst %.c, $(PATHB)%.o, $(SRC))
DEP = $(PATHU)unity.h $(PATHU)unity_internals.h
TGT = $(PATHB)test$(TARGET_EXTENSION)

test: $(PATHB) $(TGT)
	  ./$(TGT)

$(PATHB)%.o:: $(PATHS)%.c $(DEP)
			  $(CC) -c $(CFLAGS) $< -o $@
	
$(PATHB)%.o:: $(PATHU)%.c $(DEP)
			  $(CC) -c $(CFLAGS) $< $(DEP)

$(TGT): $(OBJ)
		gcc -o $@ $^
		
clean:
		$(CLEANUP) $(PATHB)*.o
		$(CLEANUP) $(TGT)

$(PATHB):
			$(MKDIR) $(PATHB)

all: clean test

.PHONY: all
.PHONY: clean
.PHONY: test
	
	