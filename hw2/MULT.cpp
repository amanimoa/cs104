// MULT.cpp:
#include "MULT.h"
using namespace std;

MULT::MULT(std::string variableName, int value)
	: m_variableName1( variableName ), m_value( value )
{
	 flag_con1 = true; 

}

MULT::MULT(std::string variableName1, std::string variableName2)
	: m_variableName1( variableName1 ), m_variableName2( variableName2 )
{

	 flag_con2 = true; 
}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void MULT::execute(ProgramState * state, ostream &outf)
{
	//we need to increment the program counter 
	//state->PC = state->PC + 1; 
	state->set_PC(state->get_PC() + 1);
	
	if(flag_con1){
	
		map<std::string, int>::iterator it;
		std::map<std::string, int> map_copy = state->get_map();
		for (it = map_copy.begin(); it != map_copy.end(); it++)
		{	
			if(it->first == m_variableName1){
				//we found the variable 
			    //overwrite the value 
				//state->MAP.at(it->first) = it->second * m_value;
				state->set_map(it->first, it->second * m_value);
				break; 		
			}
		}		

	} 
	
	else if(flag_con2){
	// I will use another method here 
	
	// I will immediatley use find 
	std::map<std::string, int> map_copy = state->get_map();
	std::map<std::string, int>::iterator it1 = map_copy.find(m_variableName1); 
	std::map<std::string, int>::iterator it2 = map_copy.find(m_variableName2); 
	if ((it1 != map_copy.end()) && (it2 != map_copy.end())) //means we found it 
    	//it1->second = it1->second * it2->second;
    	state->set_map(it1->first, it1->second * it2->second);
	
	}	
}
