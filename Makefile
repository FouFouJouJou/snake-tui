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
COMPILE:=$(CC) $(CFLAGS) $(C_GNU_SOURCE_FLAG) $(C_INCLUDE_FLAGS) -c

snake_test: $(BUILD_DIR)/snake_test
	 @echo running snake test
	 @$(BUILD_DIR)/snake_test
	 @echo exit code: $$?

list_test: $(BUILD_DIR)/list_test
	 @echo running list test
	 @$(BUILD_DIR)/list_test
	 @echo exit code: $$?

$(BUILD_DIR)/snake_test: $(OBJECT_DIR)/snake.o $(OBJECT_DIR)/list.o $(OBJECT_DIR)/position.o $(OBJECT_DIR)/snake_test.o
	 $(CC) $(OBJECT_DIR)/snake_test.o $(OBJECT_DIR)/snake.o $(OBJECT_DIR)/list.o $(OBJECT_DIR)/position.o -o $(BUILD_DIR)/snake_test
	 @echo [100%] linking snake test

$(OBJECT_DIR)/snake_test.o: $(TEST)/snake_test.c
	 @ $(COMPILE) -c $(TEST)/snake_test.c -o $(OBJECT_DIR)/snake_test.o
	 @echo [100%] compiling snake test

$(OBJECT_DIR)/position.o: $(SOURCE)/position.c
	 @$(COMPILE) -c $(SOURCE)/position.c -o $(OBJECT_DIR)/position.o
	 @echo [100%] compiling position


$(OBJECT_DIR)/snake.o: $(SOURCE)/snake.c
	 @$(COMPILE) -c $(SOURCE)/snake.c -o $(OBJECT_DIR)/snake.o
	 @echo [100%] compiling snake


$(BUILD_DIR)/list_test: $(OBJECT_DIR)/list_test.o $(OBJECT_DIR)/list.o
	 @$(CC) $(OBJECT_DIR)/list_test.o $(OBJECT_DIR)/list.o -o $(BUILD_DIR)/list_test 
	 @echo [100%] linking list test

$(OBJECT_DIR)/list_test.o: $(TEST)/list_test.c
	 @$(COMPILE) -c $(TEST)/list_test.c -o $(OBJECT_DIR)/list_test.o
	 @echo [100%] compiling list test

$(OBJECT_DIR)/list.o: $(SOURCE)/list.c
	 @$(COMPILE) -c $(SOURCE)/list.c -o $(OBJECT_DIR)/list.o
	 @echo [100%] compiling list


clean:
	 @echo cleaning
	 @rm object/* build/*
