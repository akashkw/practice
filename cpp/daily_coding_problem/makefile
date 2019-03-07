CC = g++
STD_FLAG = -std=c++14
WARNING_FLAGS = -pedantic -Wall -Weffc++ -Wextra
CFLAGS = $(STD_FLAG) $(WARNING_FLAGS)
GTEST_FLAGS = -lgtest -lgtest_main -pthread

.PHONY : clean create

create %:
	 cp template $(filter-out $@,$(MAKECMDGOALS)).cpp

clean:
	rm *.out

%:
	$(CC) $(STD_FLAG) $@.cpp -o $@.out $(GTEST_FLAGS)
	./$@.out
	rm $@.out
