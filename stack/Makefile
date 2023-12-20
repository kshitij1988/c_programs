#Makefile

#Compiler
CC = gcc

#Compiler flags
CFLAGS_COMMON = -Wall -Wextra
CFLAGS_DBG = -g
CFLAGS_PERF = -pg

#Source Directory
SRC_DIR = src

#Build Directory
BUILD_DIR = build

#include directories
INCLUDE_DIR = include

#documentation directory
DOC_DIR = Documentation

#performance directory
PERF_DIR = Performance

#performance directory
MEM_DIR = Memory

# Doxygen Configuration File
DOXYFILE = Doxyfile

# Performance metric input File
GMON = gmon.out

# Performance metric output File
PERF_METRIC = stacks_perf.txt

# Memory analysis output File
MEM_METRIC = stacks_mem.txt

#Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

#Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

#Executable Name
TARGET = $(BUILD_DIR)/stacks

#Default target
all: $(TARGET)

#Rule to create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#Rule to create documentation directory
$(DOC_DIR):
	mkdir -p $(DOC_DIR)

#Rule to create performance directory
$(PERF_DIR):
	mkdir -p $(PERF_DIR)

#Rule to create memory directory
$(MEM_DIR):
	mkdir -p $(MEM_DIR)

#Rule to build the executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS_COMMON) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@

#Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS_COMMON) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

#Rule to generate documentation
documentation: $(DOXYFILE) | $(DOC_DIR)
	doxygen $(DOXYFILE)

#Rule to generate performance analysis
performance: CFLAGS += $(CFLAGS_PERF)
performance: clean $(PERF_DIR) | $(TARGET)
	@if [ ! -f $(GMON) ]; then \
		$(TARGET); \
	fi
	gprof $(TARGET) $(GMON) > $(PERF_DIR)/$(PERF_METRIC)

#Rule to generate memory analysis
memory: CFLAGS += $(CFLAGS_DBG)
memory: clean $(MEM_DIR) | $(TARGET)
	valgrind --leak-check=full --log-file=$(MEM_DIR)/$(MEM_METRIC) $(TARGET)

#Clean up intermediate files
clean:
	rm -f $(GMON)
	rm -f $(OBJS)
	rm -rf $(TARGET)

#Clean up all generated files
distclean: clean
	rm -rf $(DOC_DIR)
	rm -rf $(MEM_DIR)
	rm -rf $(PERF_DIR)
	rm -rf $(BUILD_DIR)
