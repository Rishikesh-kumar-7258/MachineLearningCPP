define newline

endef

all: compile run

compile:
	@g++ main.cpp -o main 

run:
	@./main