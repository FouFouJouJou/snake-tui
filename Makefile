CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -Wno-empty-body 
OBJECT_DIR:=./object
BUILD_DIR:=./build
INCLUDE_DIR:=./include
SOURCE:=./source
TEST:=./test
C_INCLUDE_FLAGS:=-I$(INCLUDE_DIR)
C_GNU_SOURCE_FLAG:=-D_GNU_SOURCE
MAIN_EXECUTABLE:=$(BUILD_DIR)/snake-tui

list_test: $(BUILD_DIR)/list_test
	 @echo running list test
	 @$(BUILD_DIR)/list_test
	 @echo exit code: $$?

$(BUILD_DIR)/list_test: $(OBJECT_DIR)/list_test.o $(OBJECT_DIR)/list.o
	 @$(CC) $(OBJECT_DIR)/list_test.o $(OBJECT_DIR)/list.o -o $(BUILD_DIR)/list_test 
	 @echo [100%] linking list test

$(OBJECT_DIR)/list_test.o: $(TEST)/list_test.c
	 @$(CC) $(CFLAGS) $(C_INCLUDE_FLAGS) $(C_GNU_SOURCE_FLAG) -c $(TEST)/list_test.c -o $(OBJECT_DIR)/list_test.o
	 @echo [100%] compiling list test

$(OBJECT_DIR)/list.o: $(SOURCE)/list.c
	 @$(CC) $(CFLAGS) $(C_INCLUDE_FLAGS) $(C_GNU_SOURCE_FLAG) -c $(SOURCE)/list.c -o $(OBJECT_DIR)/list.o
	 @echo [100%] compiling list


clean:
	 @echo cleaning
	 @rm object/* build/*
