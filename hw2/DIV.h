#ifndef DIV_INCLUDED
#define DIV_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <math.h> 
#include <iostream>

class DIV: public Statement
{
private:
	std::string m_variableName1;
	std::string m_variableName2;
	int m_value; 
	bool flag_con1 = false; 
	bool flag_con2 = false; 
	
public:
	DIV(std::string m_variableName1, int m_value);
	DIV(std::string m_variableName1, std::string m_variableName2);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
