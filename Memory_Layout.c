//There are multiple programs, execute each one and see the memory allocations of variables to each section of memory layout.
//5 Sections- Text Segment, Initialised data segment, Uninitialised Data Segment, Stack, Heap
//Check OUTPUT for commands.

//1 Basic Program (basic.c)
#include<stdio.h>
int main(void){
  return 0;
}
/* OUTPUT
$ gcc basic.c -o basic.o                                                                                                                                                                                                               1 ⨯
$ size basic.o         
   text    data     bss     dec     hex filename
   1358     528       8    1894     766 basic.o

*/

//2 External Variable (externalv.c)
#include<stdio.h>
extern int exnum = 1;    //External Variable
int main(void){
  return 0;
}

/*OUTPUT
$ gcc externalv.c -o externalv.o
$ size externalv.o              
   text    data     bss     dec     hex filename
   1358     532       4    1894     766 externalv.o

*/

//3 Global Variable (globalv.c)
#include<stdio.h>
int glnum = 2;           //Global Variable
int main(void){
  return 0;
}

/* OUTPUT
─$ gcc globalv.c -o globalv.o
$ size globalv.o            
   text    data     bss     dec     hex filename
   1358     532       4    1894     766 globalv.o
*/

//4 Local Variable  (localv.c)
#include<stdio.h>
int main(void){
  int locnum = 3;       //Local Variable
  return 0;
}
/* OUTPUT
$ gcc localv.c -o localv.o
$ size localv.o           
   text    data     bss     dec     hex filename
   1374     528       8    1910     776 localv.o
*/

//5 Static Variable  (staticv.c)
#include<stdio.h>
int main(void){
  static int stnum = 5; //Static Variable
  return 0;
}
/* OUTPUT
$ gcc staticv.c -o staticv.o
$ size staticv.o            
   text    data     bss     dec     hex filename
   1358     532       4    1894     766 staticv.o
  */

//6 Automatic Variable  (automaticv.c)
#include<stdio.h>
int main(void){
  auto int aunum = 6;   //Automatic Variable
  return 0;
}
/* OUTPUT
$ gcc automaticv.c -o automaticv.o
$ size automaticv.o               
   text    data     bss     dec     hex filename
   1374     528       8    1910     776 automaticv.o
*/

//7 Constant Variable   (constantv.c)
#include<stdio.h>
int main(void){
  const int conum = 7;  //Constant Variable
  return 0;
}
/* OUTPUT
$ gcc constantv.c -o constantv.o
$ size constantv.o              
   text    data     bss     dec     hex filename
   1374     528       8    1910     776 constantv.o
 */

//8 Local Variable Within a Function  (localfv.c)
#include<stdio.h>
int main(void){
  localfunc();
  return 0;
}
void localfunc() {
  int locfnum = 4;
  }
 /* OUTPUT
$ gcc localfv.c -o localfv.o
$ size localfv.o            
   text    data     bss     dec     hex filename
   1430     528       8    1966     7ae localfv.o
*/

//Combining all the above   (memory_layout.c)
#include<stdio.h>
extern int exnum = 1;    //External Variable
int glnum = 2;           //Global Variable

int main(void){
  int locnum = 3;       //Local Variable 
  static int stnum = 5; //Static Variable
  auto int aunum = 6;   //Automatic Variable
  const int conum = 7;  //Constant Variable
  localfunc();
  
  return 0;
  }

void localfunc() {
    int locfnum = 4;     //Local Variable
        }
/* OUTPUT
$ gcc memory_layout.c -o memory_layout.o
$ size memory_layout.o                  
   text    data     bss     dec     hex filename
   1462     540       4    2006     7d6 memory_layout.o
                                                         
*/
