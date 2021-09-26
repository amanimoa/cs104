// PrintALL.cpp:
#include "PrintALL.h"
using namespace std;



PrintALL::PrintALL()
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void PrintALL::execute(ProgramState * state, ostream &outf)
{
	//we need to increment the program counter 
	//state->PC = state->PC + 1; 
	//set_PC(get_PC() + 1);
	state->set_PC(state->get_PC() + 1);
	
	//iterate through the map to print the whole values
	map<std::string, int>::iterator it;
	std::map<std::string, int> map_copy = state->get_map();

	for (it = map_copy.begin(); it != map_copy.end(); it++)
	{
    	outf << it->first << " " << it->second << endl; 
	}
	
}
