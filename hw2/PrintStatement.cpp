// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{

	//we need to increment the program counter 
	//state->PC = state->PC + 1; 
	//set_PC(get_PC() + 1);
	state->set_PC(state->get_PC() + 1);
	
	/*to print a specific statement  for example if a 
	variable name was given we want to print it with its
	value from the map */
	std::map<std::string, int> map_copy = state->get_map();
	std::map<std::string, int>::iterator it = map_copy.find(m_variableName); 
	
	if(it != map_copy.end()){ //means we found it
		outf << it->first << " " << it->second << endl;
		
	} else {
		//state->.insert(pair<std::string, int> (m_variableName, 0));
		state->set_map(m_variableName, 0);
		
		//it = state->map_copy.find(m_variableName); 

		outf << m_variableName << " " << 0 << endl;  //assign zero for it
	
	}
	
	
	

}
