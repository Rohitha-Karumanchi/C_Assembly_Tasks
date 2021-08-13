//Implementing the python int() function in C.

#include<stdio.h>
#include<string.h>

void intfun(char s[])
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
				// Print the answer
				printf("%d", num);
			}
			
	// Main function
	int main()
			{
				// Given string of number
				//char s[] = "123"; can use this instead of reading value from user
				char s[30];
			  printf("Enter a number string : ");
			  scanf("%s",s);
				// Function Call
				intfun(s);
				return 0;
			}
