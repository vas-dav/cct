CC=gcc
CFLAGS=-c -Wall -std=c99
SRCS = $(shell find . -maxdepth 1 -type f -name "*.c")
BUILD_DIR = $(shell git rev-parse --show-toplevel)/build
OBJS = $(patsubst ./%, $(BUILD_DIR)/%, $(SRCS:.c=.o))
AR=ar
ARFLAGS=rcs
INSTALL_DIR=/usr
LIB_DIR=$(INSTALL_DIR)/lib
INCLUDE_DIR=$(INSTALL_DIR)/include/cct

all: $(BUILD_DIR)/libcct.a

$(BUILD_DIR)/libcct.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $@

$(OBJS): | $(BUILD_DIR)

install: $(BUILD_DIR)/libcct.a
	sudo mkdir -p $(INCLUDE_DIR)
	sudo cp *.h $(INCLUDE_DIR)
	sudo cp $(BUILD_DIR)/libcct.a $(LIB_DIR)

clean:
	rm -rf $(BUILD_DIR)

uninstall:
	sudo rm -f $(LIB_DIR)/libcct.a
	sudo rm -f $(INCLUDE_DIR)/*.h
	sudo rmdir $(INCLUDE_DIR)
	rm -f $(BUILD_DIR)/libcct.a
