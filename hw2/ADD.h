#ifndef ADD_INCLUDED
#define ADD_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

#include <iostream>


class ADD: public Statement
{
private:
	std::string m_variableName1;
	std::string m_variableName2;
	int m_value; 
	bool flag_con1 = false; 
	bool flag_con2 = false; 
	
	
public:
	ADD(std::string m_variableName1, int m_value);
	ADD(std::string m_variableName1, std::string m_variableName2);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
