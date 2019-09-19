#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* string = "Helllo World";
	char input[64];
	//char* cursor = words;
	int x = 5;
	float y = 3.1415;
	char a = 'a';
	float inputx;
  

    do
    {
     printf("\nPlease enter a number\n");
     fflush(stdout);
     fflush(stdin);
     int correct = scanf("%f",&inputx);
     x=1;
     printf("\nscanf returned %d. input was %f",correct,inputx);


    if(correct==1)
    {
      printf("\nNumber is entered\n");
   
    }
    else
    {
      printf("\nNumber is not entered\n");
      
    }
    }
    while (x==1);
// Format specifiers
	//	printf("\nThis is a int = %d float = %f char = %c",x,y,a);
	//	printf("\ninput was %f",inputx);
	//	printf("\nCopy of string %s",string);
		//cursor++;


}