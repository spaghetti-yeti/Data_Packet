//   Nick Gentile    Program 2   NG358492   3/1/13     //

#include "p2.h"


int main (int argc,  char *argv[])
{

  char *flagc = "-c";		//sets up user input for c command 
  char *flagd = "-d";		//sets up user input for d command
  char *flagcd = "-cd";    	//sets up user input for cd command

//----------------------------- Open the files ------------------------------//

  if (argc != TOTALARGS)				//exit if there are not 3 arguements
  {
	fprintf(stderr, "Not enough arguements.\n");
	exit(1);
  }

  if ((infile = fopen(argv[INFILEARG],"r"))==NULL)	//exit if the file cannot be opened
  {
	fprintf(stderr, "Could not open this file for reading.\n");
	exit(1);
  }


//--------------------------------- Read the flag and call functions -------------------------------//

  
  if(strcmp(argv[ONE], flagc) == 0)				//if user inputs -c
  { 
  flag_c(infile); 
  }

//------------------data---------------------//

  if(strcmp(argv[ONE], flagd) == 0)				//if user inputs -d
  { 
  flag_d(infile);
  }

//------------------data and control-------------//

  if(strcmp(argv[ONE], flagcd) == 0)				//if user inputs -cd
  { 
  flag_cd(infile);
  }
  return 0;
}						//end main



