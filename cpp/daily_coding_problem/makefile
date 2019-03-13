CC = g++
STD_FLAG = -std=c++14
WARNING_FLAGS = -pedantic -Wall -Weffc++ -Wextra
CFLAGS = $(STD_FLAG) $(WARNING_FLAGS)
GTEST_FLAGS = -lgtest -lgtest_main -pthread

.PHONY : clean create

create %:
	 cp test/template.cpp $(filter-out $@,$(MAKECMDGOALS)).cpp

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.out" -type f -delete


%:
	$(CC) $(CFLAGS) -c test/structures.cpp -o structures.o
	$(CC) $(CFLAGS) -c $@.cpp -o $@.o
	$(CC) $(CFLAGS) -o $@.out $(GTEST_FLAGS) structures.o $@.o
	./$@.out
	rm $@.out
