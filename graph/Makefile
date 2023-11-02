COMPILER = g++ 

COMPILER_FLAGS = -c -g -Wall -std=c++17

PROGRAM_NAME = main.exe

CPP_FILES = main.cpp

build:
	@$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES)
	@$(COMPILER) -o $(PROGRAM_NAME) *.o
	@echo "successfully compiled!"

run:
	@./$(PROGRAM_NAME)

clean:
	rm -f $(PROGRAM_NAME) *.o

unittest:
	@./$(PROGRAM_NAME) test

kattistest:
	@cat input/1.in | ./$(PROGRAM_NAME) | diff - output/1.ans
	@cat input/2.in | ./$(PROGRAM_NAME) | diff - output/2.ans
	@cat input/3.in | ./$(PROGRAM_NAME) | diff - output/3.ans
	@cat input/4.in | ./$(PROGRAM_NAME) | diff - output/4.ans
	@cat input/5.in | ./$(PROGRAM_NAME) | diff - output/5.ans


	@echo "All test cases passed!"