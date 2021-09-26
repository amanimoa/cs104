#ifndef PRINT_ALL_INCLUDED
#define PRINT_ALL_INCLUDED

#include "Statement.h"
#include <iostream>
#include <map>

class PrintALL: public Statement
{

	
public:
	PrintALL();
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
