# generates .o files using Makefile implicit rules
OFILES= assign.o read.o write.o gen_infix.o finish.o declare.o mk_temp.o convert.o symbol_table.o if.o loop.o
pascal: SPparser.tab.c lex.yy.c pascal.tab.h $(OFILES)
	g++ $(OFILES) SPparser.tab.c lex.yy.c -lfl -o pascal
declare.o: symbol_table.o
convert.o gen_infix.o: mk_temp.o 
lex.yy.c: SPscanner.l
	flex SPscanner.l
pascal.tab.h SPparser.tab.c:  SPparser.y
	bison --defines=pascal.tab.h SPparser.y 
clean:
	rm -f *.o lex.yy.c SPparser.tab.c pascal.tab.h pascal *.asm
