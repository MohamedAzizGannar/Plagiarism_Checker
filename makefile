
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
LIB_DIR = lib
BUILD_DIR = build
BIN = program

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIB_DIR)/*.c)
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC)))

# Default target
.PHONY: all
all: $(BIN)

# Link object files into executable
$(BIN): $(OBJ)
	@echo "🔗 Linking..."
	$(CC) $(OBJ) -o $@

# Compile source files from src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "🛠️  Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Compile source files from lib/
$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	@echo "🛠️  Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN)

# Run the program
.PHONY: run
run: all
	@echo "🚀 Running..."
	./$(BIN)

# Placeholder test target (required by some setups)
.PHONY: test
test: all
	@echo "🧪 Running tests..."
	@echo "(No tests defined yet)"
