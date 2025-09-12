main: cal.l cal.y
	mkdir -p build
	bison -d cal.y -o build/cal.tab.c
	flex -o build/lex.yy.c cal.l
	gcc build/cal.tab.c build/lex.yy.c -o build/calculator
	./build/calculator < input.txt > output.txt

clean:
	rm -f build/cal.tab.c build/cal.tab.h build/lex.yy.c build/calculator