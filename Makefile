# The build target 
TARGET = simulation
SRCS := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
DEPENDS := $(SRCS:.cpp=.o)

# the compiler: gcc for C program, define as g++ for C++
CC = clang++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS = -g -Wall


.PHONY: all run clean

# Make an object
%.o: %.cpp %.h
	${CC} $(CFLAGS) -c $<

# Make the target
$(TARGET): $(DEPENDS)
	$(CC) $(CFLAGS) -o $(TARGET) $(DEPENDS)

# ----------------
all: $(TARGET)

run: all
	@echo '--- Start the Simulation ---'
	@./$(TARGET)

clean:
	rm -rf $(TARGET) *.s *.o *.dSYM
