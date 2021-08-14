//Implementing the python int() function in C.
//Implements the python int() function in C. Like atoi(char* ptr, int base) to return the integer stored at the pointer ptr.
//The function accepts a pointer to a string and an integer mode as arguments and outputs the appropriate number.

#include<stdio.h>
#include<string.h>

int intfun(char s[], int b)
			{
				// Initialize a variable
				int num = 0;
        			//getting length of string 
				int n = strlen(s);
			
				// Iterating through the length
				for (int i = 0; i < n; i++)
        				{
					// Subtract 48 from the current digit , ASCII values of  digits from 0 to 9 start from 48 – 57.
					num = num * 10 + (s[i] - 48);
       					 }
				
				if (b==2){
			        	printf("Base is Decimal\n");
			        	printf("Decimal value of String is %d ",num);
			        	}
			       else if (b==8){
			      		     printf("Base is octal\n");
			        	     int dn=num;
                   			     int i=1;
                    			     int ocno=0;
				             for(int j=num;j>0;j=j/8)
                                             {
                                               ocno=ocno+(j % 8)*i;
                                               i=i*10;
                                               num=num/8;
                                             }
			                    printf("Octal Value is : %d", ocno);
			        	   }
			    	else if (b==16){
			        		printf("Base is hexavalue\n");
			        		int decimalNumber=num;
			        		int quotient = decimalNumber;
			        		char hexadecimalNumber[100];
			        		int temp=0;
			        		int i=1;
                    				while(quotient!=0) {
                        				temp = quotient % 16;
                        				//To convert integer into character
                       					 if( temp < 10)
                                				temp =temp + 48; 
                        				else
                                				temp = temp + 55;
                                
                           				 hexadecimalNumber[i++]= temp;
                            				 quotient = quotient / 16;
                       					 }
                       				printf("Hexa value is : ");
                    				for (int j = i -1 ;j> 0;j--)
                        				printf("%c",hexadecimalNumber[j]);
                    				}
			    	else{
			        	printf("Please enter valid base\n");
			        	return 0;
			    	   }
				
				return 0;
			
			}
			
	// Main function
	int main()
			{
				// Given string of number
				//char s[] = "123"; can use this instead of reading value from user
				char s[30];
				int b;
			  	printf("Enter a number string : ");
			  	scanf("%s",s);
				printf("Enter the base 2: for binary, 8 for octal, 16 for hexavalue : ");
			  	scanf("%d",&b);
				// Function Call
				intfun(s,b);
				return 0;
			}
