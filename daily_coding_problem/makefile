CC = g++
STD_FLAG = -std=c++14
WARNING_FLAGS = -pedantic -Wall -Weffc++ -Wextra
CFLAGS = $(STD_FLAG) $(WARNING_FLAGS)
GTEST_FLAGS = -lgtest -lgtest_main -pthread

.PHONY : clean *.cpp

*.cpp:
	$(CC) $(CFLAGS) $@ -o $@.out $(GTEST_FLAGS)

clean:
	rm *.out
