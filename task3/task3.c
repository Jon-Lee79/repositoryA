#include <stdio.h>
#include <stdlib.h>

int main()
{   

/*
1 0.2
2 0.3
3 0.7
4 0.2
5 0.4
6 0.5
7 0.6
8 0.8
9 0.8
10 0.1
*/
	FILE * input_file;
	

	float x;
	float y;

	input_file = fopen("data.dat","r");

	if(input_file !=NULL)
	{
	fscanf(input_file,"%f %f",&x[i],&y[i]);

	fclose(input_file);
    }
}