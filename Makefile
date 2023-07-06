CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -Wno-empty-body -c
OBJECT_DIR:=./object
BUILD_DIR:=./build
INCLUDE_DIR:=./include
SOURCE:=./source
TEST:=./test
C_INCLUDE_FLAGS:=-I$(INCLUDE_DIR)
C_GNU_SOURCE_FLAG:=-D_GNU_SOURCE
MAIN_EXECUTABLE:=$(BUILD_DIR)/snake-tui