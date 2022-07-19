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
.PHONY: clean test all

PATH_SRC = src/
PATH_UNITY = unity/src/
PATH_TEST = test/

PATH_BUILD = build/
PATH_DEP = $(PATH_BUILD)depends/
PATH_OBJ = $(PATH_BUILD)objs/
PATH_RESULT = $(PATH_BUILD)results/

BUILD_PATH_SRC = $(PATH_BUILD) $(PATH_DEP) $(PATH_OBJ) $(PATH_RESULT)

SRCS := $(wildcard $(PATH_SRC)*.cpp)
HEADERS := $(wildcard $(PATH_SRC)*.h)
DEPENDS := $(patsubst $(PATH_SRC)%.cpp, $(PATH_OBJ)%.o, $(SRCS))

SRCT = $(wildcard $(PATH_TEST)*.cpp)

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATH_UNITY) -I$(PATH_SRC) -DTEST

RESULTS = $(patsubst $(PATH_TEST)test_%.cpp, $(PATH_RESULT)test_%.txt, $(SRCT))

PASSED = `grep -s PASS $(PATH_RESULT)*.txt`
FAIL = `grep -s FAIL $(PATH_RESULT)*.txt`
IGNORE = `grep -s IGNORE $(PATH_RESULT)*.txt`


##
## Targets
##
all:
	@echo $(SRCT)
	@echo $(SRCS)
	@echo $(HEADERS)
	@echo $(DEPENDS)
	@echo $(RESULTS)


test: $(BUILD_PATH_SRC) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

$(PATH_RESULT)%.txt: $(PATH_BUILD)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATH_BUILD)test_%.$(TARGET_EXTENSION): $(PATH_OBJ)test_%.o $(PATH_OBJ)%.o $(PATH_OBJ)unity.o $(PATH_DEP)test_%.d
	$(LINK) -o $@ $^

$(PATH_OBJ)%.o:: $(PATH_TEST)%.cpp
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATH_OBJ)%.o:: $(PATH_SRC)%.cpp
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATH_OBJ)%.o:: $(PATH_UNITY)%.c $(PATH_UNITY)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATH_DEP)%.d:: $(PATH_TEST)%.cpp
	$(DEPEND) $@ $<


$(PATH_BUILD):
	$(MKDIR) $(PATH_BUILD)

$(PATH_DEP):
	$(MKDIR) $(PATH_DEP)

$(PATH_OBJ):
	$(MKDIR) $(PATH_OBJ)

$(PATH_RESULT):
	$(MKDIR) $(PATH_RESULT)


clean:
	$(CLEANUP) $(PATH_OBJ)*.o
	$(CLEANUP) $(PATH_BUILD)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATH_RESULT)*.txt

## .PRECIOUS: Preserving Libraries Against Removal due to Interrupts
## https://docs.oracle.com/cd/E19504-01/802-5880/make-49/index.html
.PRECIOUS: $(PATH_BUILD)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATH_DEP)%.d
.PRECIOUS: $(PATH_OBJ)%.o
.PRECIOUS: $(PATH_RESULT)%.txt
