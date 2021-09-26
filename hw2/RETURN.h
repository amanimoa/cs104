#ifndef RETURN_INCLUDED
#define RETURN_INCLUDED

#include "Statement.h"
#include "GOSUB.h"
#include <iostream>

class RETURN : public Statement
{

	
public:

	RETURN();
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
