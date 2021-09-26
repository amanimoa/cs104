// LetStatement.cpp:
#include "RETURN.h"
using namespace std;

RETURN::RETURN()
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void RETURN::execute(ProgramState * state, ostream &outf)
{

	/*access the stack and see where is the most recent gosub and
	from there we return and also we pop from the stack so that the next time 
	we hit return we continue in the stack */
	
	//this returns where should the program counter be set at and deletes 
	int line_num = state->delete_stack();
	state->set_PC(line_num);
	
}
