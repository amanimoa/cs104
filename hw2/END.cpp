// END.cpp:
#include "END.h"
using namespace std;

/*END::END(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{} */

END::END(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void END::execute(ProgramState * state, ostream &outf)
{	
	//state->set_PC(-1);

	state->set_PC(0); //SET TO 0 TO STOP
}
