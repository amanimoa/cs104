// ProgramState.cpp:
#include "ProgramState.h"
using namespace std;



ProgramState::ProgramState(int numLines): m_numLines(numLines)
{}

int ProgramState::get_numLines(){
 	return m_numLines;
 }

	//returns program counter
int ProgramState::get_PC(){

	return this->PC;	
}
	//sets program counter
void ProgramState::set_PC(int pc){
	
	this->PC = pc; 
	
}

	//return map
std::map<std::string, int> ProgramState::get_map() {
	return MAP;
}
	//sets the map
void ProgramState::set_map(string variable, int value)
{
	//add to the map 
		
	//is it already there? 
	std::map<std::string, int>::iterator it = MAP.find(variable); 
	if(it != MAP.end()){ //means we found it
		//overwrite the value
		MAP.at(it->first) = value; //give the key this value
	}
		
	//no? then add it to the map with the assigned value 
	MAP.insert(pair<std::string, int> (variable, value)); 
	
} 
	

void ProgramState::add_stack(int program_line){
	//we want to push program counter here 
	//each time it tells what line the most recent GOSUB 
	STACK.push(program_line); 
		
}
	
int  ProgramState::delete_stack(){
	//we want to delete recent used GOSUB
	int last = STACK.top();
	STACK.pop();
	return last; 
		
}
	
	

