#ifndef END_INCLUDED
#define END_INCLUDED

#include "Statement.h"
#include <iostream>

class END: public Statement
{
/*private:
	std::string m_variableName;*/
	
public:

	END(); //nothing is passed 
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
