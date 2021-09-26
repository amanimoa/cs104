#ifndef GOTO_INCLUDED
#define GOTO_INCLUDED

#include "Statement.h"
#include <iostream>

class GOTO: public Statement
{
private:
	int line_N;
	
public:
	GOTO(int line_N);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
