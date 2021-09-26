#ifndef GOSUB_INCLUDED
#define GOSUB_INCLUDED

#include "Statement.h"
#include <iostream>

class GOSUB: public Statement
{
private:
	int m_value;
	
public:
	GOSUB(int m_value);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
