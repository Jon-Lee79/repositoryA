#include <stdio.h>
#include <stdlib.h>

int main()
{   
    /*
	char a[65];
	char b = "Number %f";
	char c = "2.74 1.87";

	sscanf(c,"%f %f",&x,&y);

	sprintf(a,"Number %f",x);
	sprintf(a,b,x);
	*/

	FILE * input_file;

	float x;
	float y;

	input_file = fopen("data.dat","r");

	if(input_file !=NULL)
	{
	fscanf(input_file,"%f %f",&x,&y);

	fclose(input_file);
    }
    
	input_file = fopen("hello.txt","w");

	fprintf(input_file, "Hello from x %f and y",x,y);
	fclose(input_file);
}
