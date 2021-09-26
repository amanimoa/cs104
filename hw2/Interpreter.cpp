// Interpreter.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "ADD.h"
#include "SUB.h"
#include "MULT.h"
#include "DIV.h"
#include "END.h"
#include "IFThen.h"
#include "GOTO.h"
#include "GOSUB.h"
#include "RETURN.h"
#include "PrintALL.h"
#include "PrintStatement.h"


#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter BASIC program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
	
		getline(inf, line);
		
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var, var2;
	int val;

	ss << line;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var; //key
		ss >> val; //value
		
		//cout << "I am in LET" <<endl; 
		
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		
		statement = new LetStatement(var, val);
		
	}

	// Incomplete;  TODO:  Finish this function!
	
	/*math operations have 2 constructors so we need to know
	if we are reading an int or string for the second parameter */
	
	if(type == "ADD")
	{	
		bool check_int = false; //start as not int
		ss >> var; // (key)
		ss >> var2; //second value
		//check if number or string
   		for (int i = 0; i < (int) var2.length(); i++)
   			if (isdigit(var2[i]))
   				check_int = true; //it is int 
   				
   		//if it turns out to be int then store it in an int variable 
   			
   		if(check_int){ //true
   		//pass in an int to the contructor
   			val = stoi(var2);  //convert first to int
   			statement = new ADD(var, val); //pass it
   		} 
   		
   		else
   		{
   			//pass in a string as to the constructor 
   			statement = new ADD(var, var2); 
   		
   		}   			
		
	}
	
	if(type == "SUB")
	{	
		bool check_int = false; //start as not int
		ss >> var; // (key)
		ss >> var2; //second value
		//check if number or string
   		for (int i = 0; i < (int) var2.length(); i++)
   			if (isdigit(var2[i]))
   				check_int = true; //it is int 
   				
   		//if it turns out to be int then store it in an int variable 
   			
   		if(check_int){ //true
   		//pass in an int to the contructor
   			val = stoi(var2);  //convert first to int
   			statement = new SUB(var, val); //pass it
   		} 
   		
   		else
   		{
   			//pass in a string as to the constructor 
   			statement = new SUB(var, var2); 
   		
   		}   			
		
	}
	
	if(type == "MULT")
	{	
		bool check_int = false; //start as not int
		ss >> var; // (key)
		ss >> var2; //second value
		//check if number or string
   		for (int i = 0; i < (int) var2.length(); i++)
   			if (isdigit(var2[i]))
   				check_int = true; //it is int 
   				
   		//if it turns out to be int then store it in an int variable 
   			
   		if(check_int){ //true
   		//pass in an int to the contructor
   			val = stoi(var2);  //convert first to int
   			statement = new MULT(var, val); //pass it
   		} 
   		
   		else
   		{
   			//pass in a string as to the constructor 
   			statement = new MULT(var, var2); 
   		
   		}   			
		
	}
	
	if(type == "SUB")
	{	
		bool check_int = false; //start as not int
		ss >> var; // (key)
		ss >> var2; //second value
		//check if number or string
   		for (int i = 0; i < (int) var2.length(); i++)
   			if (isdigit(var2[i]))
   				check_int = true; //it is int 
   				
   		//if it turns out to be int then store it in an int variable 
   			
   		if(check_int){ //true
   		//pass in an int to the contructor
   			val = stoi(var2);  //convert first to int
   			statement = new SUB(var, val); //pass it
   		} 
   		
   		else
   		{
   			//pass in a string as to the constructor 
   			statement = new SUB(var, var2); 
   		
   		}   			
		
	}
	
	if(type == "PRINT"){
		ss >> var;
		statement = new PrintStatement(var);
	}
	
	if(type == "PRINTALL"){
	
		statement = new PrintALL();
	
	}
	
	if(type == "GOTO"){
		ss >> val;
		statement = new GOTO(val);
		
	}
	
	if(type == "IF"){
	//IF *var* *op* *int* THEN *linenum*  
		ss >> var; // *var*
		ss >> var2; //*op*
		ss >> val; //*int* 
		//THEN 
		string then; 
		ss >> then; 
		int line; 
		ss >> line;
		statement = new IFThen(var, var2, val, line);

		
	
	}
	
	if(type == "GOSUB"){
		ss >> val;
		statement = new GOSUB(val);
	
	}
	
	if(type == "RETURN"){
	
		statement = new RETURN();
	
	}
	
	if( type == "END"|| type == "."){
		//I want to terminate the program 
			statement = new END(); 
		
	}


		
	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	
	vector<Statement *> program;
	
	parseProgram( inf, program );
	
	ProgramState *obj = new ProgramState(program.size());
	
	// Incomplete;  TODO:  Finish this function!
	
	//use program counter to know where are are

	//cout <<  "before looping: " << obj->get_PC() << endl;
	// once we hit a -1 it's like a flag that we reached end
	//int flag = obj->get_PC(); 
	//while(flag != -1){
	
	while(program[obj->get_PC()] != NULL){ 
	
		//cout <<  "first entering the loop: " << obj->get_PC() << endl;

		
		program[obj->get_PC()]->execute(obj, outf); 
		
		//cout <<  "after calling execute : " <<obj->get_PC() << endl;
		
	} 
	
	//call destructor for programState? 
	delete obj; 
	
	
	
}
