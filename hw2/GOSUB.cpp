// GOSUB.cpp:
#include "GOSUB.h"
using namespace std;

GOSUB::GOSUB( int line_number)
	: m_value( line_number )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void GOSUB::execute(ProgramState * state, ostream &outf)
{
	//every time we add the most recent GOSUB to the stack
	//so that the first time we hit return it goes to the line (after) the most recent GOSUB
	
	/* first of all we need to check whether the give line is valid and within the range
	of the number of lines or not  so we need to access how many lines there is in this 
	text file*/
	int lines_there = state->get_numLines(); 
		if(lines_there > m_value){ //within the range 
	
	 		state->add_stack(state->get_PC()+1); //add where to return later 
	 
	 		state->set_PC(m_value); //now go here  
	 	}
	
}
