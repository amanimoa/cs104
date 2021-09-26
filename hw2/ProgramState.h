// ProgramState.h
//
// CS 104 / Fall 2021
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <stack> 

class ProgramState
{
	
public:
	ProgramState(int numLines);
	ProgramState();
	
	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.
	
	int get_PC(); //returns program counter
	void set_PC(int PC); //sets program counter
	
	std::map<std::string, int> get_map(); //return map
	void set_map(std::string, int); //sets the map
	
	//std::stack <int> get_stack();
	void add_stack(int program_line);
	int delete_stack();
	 
	 int get_numLines(); 

		
	//declare a map to keep store of the variable and its value



private:
	std::map<std::string, int> MAP; 
	int m_numLines;
	// program counter
	int PC = 1; 
	std::stack <int> STACK; //this stack used for [GOSUB]
};

#endif
