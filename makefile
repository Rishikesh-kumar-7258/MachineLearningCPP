define newline

endef

all: compile run

compile:
	@g++ main.cpp pandascpp.cpp DataFrame.cpp -o main 

run:
	@./main