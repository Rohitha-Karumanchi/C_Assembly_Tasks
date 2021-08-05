//Printing Addresses of variables using & operator
//Note : address values change for each execution and notice the - sign before external, global and static variable addresses.
//Move to the end for output

#include<stdio.h>

extern int exnum = 1;    //External Variable
int glnum = 2;           //Global Variable 

int main(void){
  int locnum = 3;       //Local Variable
  static int stnum = 5; //Static Variable 
  auto int aunum = 6;   //Automatic
  const int conum = 7;  //Constant
  
  printf("External Variable : %d \t Address : %d \n" ,exnum, &exnum);
  printf("Global Variable : %d \t Address : %d \n" ,glnum,  &glnum);
  printf("Local Variable : %d \t Address : %d \n" ,locnum, &locnum);
  printf("Static Variable : %d \t Address : %d \n" ,stnum, &stnum);
  printf("Automatic Variable : %d \t Address : %d \n" ,aunum, &aunum);
  printf("Constant Variable : %d \t Address : %d \n" ,conum, &conum);
  
  localfunc();
  
  return 0;
  }

void localfunc() {
    int locfnum = 4;     //Local Variable
    printf("Local Variable inside function Variable : %d \t Address : %d " ,locfnum, &locfnum);
    printf("\n\n Accessing variables inside function\n");
    printf("External Variable : %d \t Address : %d \n" ,exnum, &exnum);
    printf("Global Variable : %d \t Address : %d \n" ,glnum, &glnum);
   }

/*
OUTPUT:

 $ gcc addramp.c -o addramp.o
addramp.c:3:12: warning: ‘exnum’ initialized and declared ‘extern’
    3 | extern int exnum = 1;    //External Variable
      |            ^~~~~
addramp.c: In function ‘main’:
addramp.c:19:3: warning: implicit declaration of function ‘localfunc’ [-Wimplicit-function-declaration]
   19 |   localfunc();
      |   ^~~~~~~~~
addramp.c: At top level:
addramp.c:24:6: warning: conflicting types for ‘localfunc’
   24 | void localfunc() {
      |      ^~~~~~~~~
addramp.c:19:3: note: previous implicit declaration of ‘localfunc’ was here
   19 |   localfunc();
      |   ^~~~~~~~~
                                                                                                                                                                                                                                             
$ ./addramp.o                       
External Variable : 1    Address : -1255432136 
Global Variable : 2      Address : -1255432132 
Local Variable : 3       Address : 1340567068 
Static Variable : 5      Address : -1255432128 
Automatic Variable : 6   Address : 1340567064 
Constant Variable : 7    Address : 1340567060 
Local Variable inside function Variable : 4      Address : 1340567036 

 Accessing variables inside function
External Variable : 1    Address : -1255432136 
Global Variable : 2      Address : -1255432132 

*/
