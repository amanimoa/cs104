
#ifndef MULT_INCLUDED
#define MULT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

#include <iostream>

class MULT: public Statement
{
private:
	std::string m_variableName1;
	std::string m_variableName2;
	int m_value; 
	bool flag_con1 = false; 
	bool flag_con2 = false; 
	
public:
	MULT(std::string m_variableName1, int m_value);
	MULT(std::string m_variableName1, std::string m_variableName2);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
