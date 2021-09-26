// IFThen.cpp:
#include "IFThen.h"
using namespace std;

IFThen::IFThen(std::string variableName, std::string operation, int value,  int line_number)
	: m_variableName( variableName ), m_operation(operation), m_value( value ), m_line_number(line_number)
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void IFThen::execute(ProgramState * state, ostream &outf)
{	
	/* 1. we check if the line number to go is valid/
	   2. if it is valid, we check whatt operation is given
	   3. do the operation and determine true or false
	   4.false: do nothing
	    true: go to this line 
	    */
	bool check_oper = false; 
	int lines_there = state->get_numLines(); 
	std::map<std::string, int> map_copy = state->get_map();
	std::map<std::string, int>::iterator it = map_copy.find(m_variableName);
	
	//did we find the variable ?  
	if(it != map_copy.end()){ //means we found it
		int val = it->second; 
		if(lines_there > m_line_number){ //within the range 
			if(m_operation == "<"){
				if(val < m_value){
					check_oper = true; 
				}
			}
			else if(m_operation == "<="){
				if(val <= m_value){
					check_oper = true; 
				}
			}
			else if(m_operation == ">"){
				if(val > m_value){
					check_oper = true; 
				}
			}
			else if(m_operation == ">="){
				if(val >= m_value){
					check_oper = true; 
				}
			}
			else if(m_operation == "="){
				if(val == m_value){
					check_oper = true; 
				}
			}
			else if(m_operation == "<>"){
				if(val != m_value){
					check_oper = true; 
				}
			}
		
			if(check_oper == true )
				state->set_PC(m_line_number);
		}
	}
}	
