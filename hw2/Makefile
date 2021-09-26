MYDEFS = -g -Wall -std=c++11 -DLOCALHOST=\"127.0.0.1\"

all: Interpreter

Interpreter: Interpreter.cpp LetStatement.o ProgramState.o PrintStatement.o PrintALL.o MULT.o DIV.o ADD.o SUB.o GOTO.o IFThen.o RETURN.o GOSUB.o END.o
	g++ -g -Wall Interpreter.cpp LetStatement.o ProgramState.o PrintStatement.o PrintALL.o MULT.o DIV.o ADD.o SUB.o GOTO.o IFThen.o RETURN.o GOSUB.o END.o -o Interpreter 

LetStatement.o: LetStatement.cpp LetStatement.h
	g++ -g -c -Wall LetStatement.cpp -o LetStatement.o

ProgramState.o: ProgramState.cpp ProgramState.h
	g++ -g -c -Wall ProgramState.cpp -o ProgramState.o

PrintStatement.o: PrintStatement.cpp PrintStatement.h
	g++ -g -c -Wall PrintStatement.cpp -o PrintStatement.o

PrintALL.o: PrintALL.cpp PrintALL.h 
	g++ -g -c -Wall PrintALL.cpp -o PrintALL.o

MULT.o: MULT.cpp MULT.h
	g++ -g -c -Wall MULT.cpp -o MULT.o

DIV.o: DIV.cpp DIV.h
	g++ -g -c -Wall DIV.cpp -o DIV.o

ADD.o: ADD.cpp ADD.h
	g++ -g -c -Wall ADD.cpp -o ADD.o

SUB.o: SUB.cpp SUB.h
	g++ -g -c -Wall SUB.cpp -o SUB.o

GOTO.o: GOTO.cpp GOTO.h
	g++ -g -c -Wall GOTO.cpp -o GOTO.o

IFThen.o: IFThen.cpp IFThen.h
	g++ -g -c -Wall IFThen.cpp -o IFThen.o

RETURN.o: RETURN.cpp RETURN.h
	g++ -g -c -Wall RETURN.cpp -o RETURN.o

GOSUB.o: GOSUB.cpp GOSUB.h
	g++ -g -c -Wall GOSUB.cpp  -o GOSUB.o

END.o: END.cpp END.h
	g++ -g -c -Wall END.cpp  -o END.o


clean:
	rm -f  *.o 

