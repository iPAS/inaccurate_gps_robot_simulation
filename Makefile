## Original from http://www.throwtheswitch.org/build/make

## Please beware of calling "C" from "C++"
# https://stackoverflow.com/questions/2744181/how-to-call-c-function-from-c

## https://stackoverflow.com/questions/3477292/what-do-and-do-as-prefixes-to-recipe-lines-in-make
# @ suppresses the normal 'echo' of the command that is executed.
# - means ignore the exit status of the command that is executed (normally, a non-zero exit status would stop that part of the build).
# + means 'execute this command under make -n' (or 'make -t' or 'make -q') when commands are not normally executed. 


##
## Host specific commands
##
ifeq ($(OS),Windows_NT)
	ifeq ($(shell uname -s),)  # Not in a bash-like shell
		CLEANUP = del /F /Q
		MKDIR = mkdir
	else  # In a bash-like shell, like msys
		CLEANUP = rm -f
		MKDIR = mkdir -p
	endif
	TARGET_EXTENSION=exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=out
endif


##
## Variables setup
##

# the compiler: gcc for C program, define as g++ for C++
CC = clang++
# CC = gcc
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS = -g -Wall -I. -I$(PATH_UNITY) -I$(PATH_SRC)

PATH_SRC = src/
PATH_UNITY = unity/src/
PATH_TEST = test/

PATH_BUILD = build/
PATH_DEP = $(PATH_BUILD)depends/
PATH_OBJ = $(PATH_BUILD)objs/
PATH_RESULT = $(PATH_BUILD)results/

BUILD_PATH_SRC = $(PATH_BUILD) $(PATH_DEP) $(PATH_OBJ) $(PATH_RESULT)

APP_NAME := simulation
TARGET := $(PATH_BUILD)$(APP_NAME).$(TARGET_EXTENSION)

SRCS := $(wildcard $(PATH_SRC)*.cpp)
HEADERS := $(wildcard $(PATH_SRC)*.h)
DEPENDS := $(patsubst $(PATH_SRC)%.cpp, $(PATH_OBJ)%.o, $(SRCS))

SRCT = $(wildcard $(PATH_TEST)*.cpp)
RESULTS = $(patsubst $(PATH_TEST)test_%.cpp, $(PATH_RESULT)test_%.txt, $(SRCT))

PASSED = `grep -s PASS $(PATH_RESULT)*.txt`
FAIL = `grep -s FAIL $(PATH_RESULT)*.txt`
IGNORE = `grep -s IGNORE $(PATH_RESULT)*.txt`


##
## Targets
##

# https://stackoverflow.com/questions/2057689/how-does-make-app-know-default-target-to-build-if-no-target-is-specified
.DEFAULT_GOAL := all
.PHONY: all run clean test show_var


## The double colon tells Make that this rule is terminating. 
## Therefore, if it can't find a C file associated with one of these rules, 
##	it should consider that to be a problem.
$(PATH_OBJ)%.o:: $(PATH_TEST)%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(PATH_OBJ)%.o:: $(PATH_SRC)%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(PATH_OBJ)%.o:: $(PATH_UNITY)%.c $(PATH_UNITY)%.h
	$(CC) -c $(CFLAGS) $< -o $@

$(PATH_DEP)%.d:: $(PATH_TEST)%.cpp
	$(CC) -MM -MG -MF $@ $<


$(PATH_BUILD):
	$(MKDIR) $(PATH_BUILD)

$(PATH_DEP):
	$(MKDIR) $(PATH_DEP)

$(PATH_OBJ):
	$(MKDIR) $(PATH_OBJ)

$(PATH_RESULT):
	$(MKDIR) $(PATH_RESULT)


$(PATH_RESULT)test_%.txt: $(PATH_BUILD)test_%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATH_BUILD)test_%.$(TARGET_EXTENSION): $(PATH_OBJ)test_%.o $(PATH_OBJ)%.o $(PATH_OBJ)unity.o #$(PATH_DEP)test_%.d
	$(CC) -o $@ $^


$(TARGET): $(DEPENDS)
	$(CC) -o $@ $^

all: Makefile $(BUILD_PATH_SRC) $(TARGET)

run:
	@make all
	@echo '--- Start the Simulation ---'
	-$(TARGET)

test: $(BUILD_PATH_SRC) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

clean:
	$(CLEANUP) -r $(PATH_BUILD)
# $(CLEANUP) $(PATH_OBJ)*.o
# $(CLEANUP) $(PATH_BUILD)*.$(TARGET_EXTENSION)
# $(CLEANUP) $(PATH_RESULT)*.txt

show_var:
	@echo $(SRCS)
	@echo $(HEADERS)
	@echo $(DEPENDS)
	@echo $(SRCT)
	@echo $(RESULTS)

## .PRECIOUS: Preserving Libraries Against Removal due to Interrupts
## https://docs.oracle.com/cd/E19504-01/802-5880/make-49/index.html
.PRECIOUS: $(PATH_BUILD)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATH_DEP)%.d
.PRECIOUS: $(PATH_OBJ)%.o
.PRECIOUS: $(PATH_RESULT)test_%.txt