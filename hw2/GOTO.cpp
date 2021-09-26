// GOTO.cpp:
#include "GOTO.h"
using namespace std;

GOTO::GOTO(int line_number)
	: line_N( line_number )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void GOTO::execute(ProgramState * state, ostream &outf)
{
	//  program counter to line_number
	
	int lines_there = state->get_numLines(); 
	
		if(lines_there > line_N){ //within the range 
		
			state->set_PC(line_N); //okay go there 
		}
	
	
	
}
