main: condition.l condition.y
	mkdir -p build
	bison -d condition.y -o build/condition.tab.c
	flex -o build/lex.yy.c condition.l
	gcc build/condition.tab.c build/lex.yy.c -o build/condition
	./build/condition < build/input.txt > build/output.txt

clean:
	rm -f build/condition.tab.c build/condition.tab.h build/lex.yy.c build/condition