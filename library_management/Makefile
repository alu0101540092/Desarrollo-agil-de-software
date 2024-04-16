CXX := g++ -fmax-errors=1
SRC_DIR := src
BUILD_DIR := build

# Find all .cc source files in the src directory
SRCS := $(wildcard $(SRC_DIR)/*.cc)

# Define the object files by replacing .cc with .o
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

# Name of the executable (same as the directory name)
EXECUTABLE := $(notdir $(shell pwd))

# Compiler flags
CXXFLAGS :=

# Linker flags
LDFLAGS :=

# Build the executable
all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

.PHONY: all clean