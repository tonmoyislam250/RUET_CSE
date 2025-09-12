all: 
	gcc -o hello hello.c
	gcc -E hello.c > hello.i
	gcc -S -masm=intel hello.i
	as -o hello.o hello.s 
	objdump -M intel -d hello.o > hello.dump
