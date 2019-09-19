#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)

{
	/*
	int i = 0;
	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}
    */
    if(argc < 2)
    {
    	

    }

    FILE* inputfile;
    inputfile = fopen(argv[1]);

	return 0;
}