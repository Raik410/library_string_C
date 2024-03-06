CC = gcc
C_FLAGS = -Wall -Wextra -Werror -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lcheck -lm -lsubunit
TEST_DIR = tests
AR = ar rcs
TARGET = s21_string.a
SRC_FILES = $(wildcard ./*.c)
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
TEST_SRC_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ_FILES = $(patsubst %.c, %.o, $(TEST_SRC_FILES))
TEST_EXEC = $(patsubst %.c, %, $(TEST_SRC_FILES))
HTML_VAR = ./*.html ./*.css ./*.gcov ./*.gcda ./*.gcno ./tests/*.gcov ./tests/*.gcda ./tests/*.gcno ./tests/*.gcda ./tests/*.Identifier

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

$(TEST_DIR)/%: $(TEST_DIR)/%.o $(TARGET)
	$(CC) $(C_FLAGS) $^ $(TEST_FLAGS) -o $@

test: $(TEST_EXEC)
	for exe in $^; do \
		./$$exe; \
	done

val: test
	valgrind --tool=memcheck --leak-check=yes ./tests/test_memchr
	valgrind --tool=memcheck --leak-check=yes ./tests/test_memcmp
	valgrind --tool=memcheck --leak-check=yes ./tests/test_memcpy
	valgrind --tool=memcheck --leak-check=yes ./tests/test_memset
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strchr
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strcspn
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strerror
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strlen
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strncat
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strncpy
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strpbrk
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strrchr
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strspn
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strtok
	valgrind --tool=memcheck --leak-check=yes ./tests/test_to_lower
	valgrind --tool=memcheck --leak-check=yes ./tests/test_to_upper
	valgrind --tool=memcheck --leak-check=yes ./tests/test_insert
	valgrind --tool=memcheck --leak-check=yes ./tests/test_trim
	valgrind --tool=memcheck --leak-check=yes ./tests/test_strstr

val_sprintf: test
	valgrind --tool=memcheck --leak-check=yes ./tests/test_sprintf

gcov_report: test
	gcov $(SRC_FILES)
	~/.local/bin/gcovr -r . --html --html-details -o s21_string.html

open:
	@echo "OPEN REPORT..."
	xdg-open s21_string.html

clean: 
	rm -f $(OBJ_FILES) $(TARGET) $(TEST_OBJ_FILES) $(TEST_EXEC) $(HTML_VAR)

clang-check: 
	clang-format -n ./*.c ./*.h ./tests/*.c

clang:
	clang-format -i ./*.c ./*.h ./tests/*.c

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 *.c *.h ./tests/*.c