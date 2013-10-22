//   Nick Gentile    Program 2   NG358492   3/1/13     //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p2.h"


  //-------Prototypes-------//
  void flag_d(FILE *infile);
  void flag_c(FILE *infile);
  void flag_cd(FILE *infile);


//---------------------------------------- Data Function ------------------------------------------//

  void flag_d(FILE *infile) 
  {
  char *buffer = (char*) malloc (BUFFSIZE);				//create buffer of size 8 
  int dataArray[ARRAYSIZE];
  int dataPackets = 0;	 						//number of control packets
  int packetID = 0; 							//packet id number 
  int largestPacketD = 0; 						//largest packet
  int i = 0; 								//for loop 
  int largestPay = 0;							//largest payload 
  int startr = 0;							//start range 
  int endr = 0;								//end range

  for(i = 0; i < ARRAYSIZE; i++)					//fill controlArray with 0's 
  {
    dataArray[i] = 0;
  }

	while(fread(buffer, ONE, ONE, infile) != 0)			//while fread is not at the end of the file
	{
	  if((WHICH & *buffer) == 0)				 	//file is a data packet 
	  {
	    payLoad = *buffer; 						//set payload to the payload size
	    fread(buffer, ONE, ONE, infile);				//Skip to packet id 
	    packetID = *buffer; 					//set packet ID
	    dataArray[packetID] = 1;					//set index in array to 1
	    dataPackets++;						//count number of data packets
	    fseek(infile, payLoad, SEEK_CUR);				//skip garbage files 
	  }

		else if((WHICH & *buffer) != 0)				//else it is a control packet, skip these two and check next
		{
		  fseek(infile, ONE, SEEK_CUR);				//skip two bytes
 		}	


		if (packetID > largestPacketD)				//finds largest packet 
		{
		  largestPacketD = packetID;				//largest packet is now highest packet id 
		}

		if (payLoad > largestPay)				//finds largest payload
		{
		  largestPay = payLoad;					//largest payload is now largestPay
		}
	}

  printf("Information about data packets:\n");
  fflush(stdout);

  if(dataPackets == 0)
  {
    printf("There are no data packets.");
    fflush(stdout);
  }

  else if(dataPackets > 0)
  {
  printf("Number of packets = %d\n", dataPackets); 
  fflush(stdout);

  printf("Largest packet Id = %d\n", largestPacketD);
  fflush(stdout);

  printf("Largest payload size = %d\n", largestPay);
  fflush(stdout);

  printf("Missing packets: ");
  fflush(stdout); 
  }  

  for(i = 0; i < largestPacketD; i++) {			//runs through the entire array
		
	if(dataArray[i] !=1 )				//if the index is 0 
	{
	  startr = i;					//set startr to the first missing packet
	  
		while(dataArray[i] != 1)		//keep incrementing until its not
		{
		  i++;
		}
	  
	  endr = i - ONE;				//set endr to the end of the range
	
		if (startr == endr){			//print print print
		  printf("%d, ", startr);
		  fflush(stdout);
		}
		else if(startr + ONE == endr){
		  printf("%d, %d, ", startr, endr);
		  fflush(stdout);
		}
		else{
		 printf("%d-%d, ", startr, endr); 
		  fflush(stdout); 
		}
        }
  }
	printf("\n");
  
   return; 
  }
  

//------------------------------------ Control Packet Function -------------------------------------//

  void flag_c(FILE *infile) 
  {
  char *buffer = (char*) malloc (BUFFSIZE);				//create buffer of size 255 
  int controlArray[ARRAYSIZE];						//array for missing packets
  int controlPackets = 0; 						//number of control packets
  int packetID = 0; 							//packet id number 
  int largestPacket = 0; 						//largest packet
  int i = 0; 								//i for for loop
  int startr = 0;							//start range 
  int endr = 0;								//end range


  for(i = 0; i < ARRAYSIZE; i++)					//fill controlArray with 0's 
  {
    controlArray[i] = 0;
  }

	while(fread(buffer, ONE, ONE, infile) != 0)			//while fread is not at the end of the file
	{
	 
	  if((WHICH & *buffer) != 0)				 	//file is a control packet 
	  {
	    fread(buffer, ONE, ONE, infile);				//Skip to packet id 
	    packetID = *buffer; 					//convert the packet id to an integer
	    controlArray[packetID] = 1;					//set index in array to 1
	    controlPackets++; 						//count number of control packets
	  }

		if (packetID > largestPacket)				//finds largest packet 
		{
		  largestPacket = packetID;				//largest packet is now highest packet id 
		}

	}

  printf("Information about control packets:\n");
  fflush(stdout);
 
  if(controlPackets == 0)
  {
  printf("There are no control packets.\n");
  }

  else if(controlPackets > 0)
  {
  printf("Number of packets = %d\n", controlPackets); 
  fflush(stdout);

  printf("Largest packet ID = %d\n", largestPacket);
  fflush(stdout);

  printf("Missing packets: ");
  fflush(stdout); 
  }
	
  for(i = 0; i < largestPacket; i++) {			//runs through the entire array
		
	if(controlArray[i] !=1 )			//if the index is 0 
	{
	  startr = i;					//set start array to the first missing packet
	  
		while(controlArray[i] != 1)		//keep incrementing until its not
		{
		  i++;
		}
	  
	  endr = i - ONE;				//set endr to the end of the range
	
		if (startr == endr){		
		  printf("%d, ", startr);
		  fflush(stdout);
		}
		else if(startr + ONE == endr){
		  printf("%d, %d, ", startr, endr);
		  fflush(stdout);
		}
		else{
		 printf("%d-%d, ", startr, endr); 
		  fflush(stdout); 
		}
        }
  }
	printf("\n");
 
  return;	
  }


//------------------------------------- Control and Data ------------------------------------------ //

  void flag_cd(FILE *infile)
  {
    flag_d(infile);
    fseek(infile,0,SEEK_SET);
    flag_c(infile);
    return; 
  }
