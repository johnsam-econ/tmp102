CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2

BUILD_DIR := build
TEST_BIN := $(BUILD_DIR)/test_tmp102

.PHONY: all build test clean

all: build

build: $(TEST_BIN)

$(TEST_BIN): tmp102.c tmp102.h test_tmp102.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -I. tmp102.c test_tmp102.c -o $@ $(LDFLAGS) $(LDLIBS)

test: build
	./$(TEST_BIN)

clean:
	rm -rf $(BUILD_DIR)
