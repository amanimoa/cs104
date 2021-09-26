// LetStatement.cpp:
#include "LetStatement.h"

#include <iostream>
#include <map>
#include <string>

using namespace std;

LetStatement::LetStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{
	//cout << "Letstatement constructor has been called" << endl;
}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, ostream &outf)
{
	//increment Program counter
	//state->PC = state->PC + 1;  
	int increase = state->get_PC() + 1; 
	state->set_PC(increase);
	
	//add to the map 
	
	//state->MAP.insert(pair<std::string, int> (m_variableName, m_value)); 
	state->set_map(m_variableName, m_value);
	
	
	
}
