// Nick Gentile Program 2 header file //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHICH 0x8000		//mask to find out data type

#define ONE 1
#define INFILEARG 2		//where infile is found
#define TOTALARGS 3		//max number of args

#define ARRAYSIZE 256		//max number of bits
#define BUFFSIZE 8		//size of buffer 

int payLoad; 			//global payLoad variable
FILE *infile; 			//input file
