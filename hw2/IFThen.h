#ifndef IFThen_INCLUDED
#define IFThen_INCLUDED

#include "Statement.h"
#include <iostream>

class IFThen: public Statement
{
private:
	std::string m_variableName;
	std::string m_operation; 
	int m_value;
	int m_line_number;
	
public:
	IFThen(std::string m_variableName, std::string m_operation, int m_value,  int m_line_number);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
