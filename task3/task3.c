/*
#include <stdio.h>
#include <stdlib.h>

int main()
{   

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

	FILE * input_file;
	

	float x;
	float y;

	input_file = fopen("data.dat","r");

	if(input_file !=NULL)
	{
	fscanf(input_file,"%f %f",&x[i],&y[i]);

	fclose(input_file);
    }

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float meanfunction(float *y, int count);
float std_devfunction(float *y, int count, float mean, FILE *output_file);

int main()
{  
    char fname[128];
    float sum;
    float mean, std_dev;
    int count = 20;
	float x[count];
    float y[count];
    FILE *input_file, *output_file;

    printf("Enter .dat file name: \n"); //Enter file name
    gets(fname);

	input_file = fopen(fname,"r"); //Opens/reads input file name

    if (input_file == NULL)
    {
         printf("\nError! opening file");
         exit(1);
    }

    output_file = fopen("output.dat","w"); //Opens output file 
	
	if (output_file == NULL)
    {
         printf("\nError! opening file");
         exit(1);
    }

/*
	for (int i = 0; i < count; ++i)
	{
		x[i]=i*1.0/4.0;
		y[i]=sin(i*1.0/4.0);

		printf("\n%f", y[i]);
	}
*/

	for (int i = 0; i < count; ++i)
	{   
        fscanf(input_file, "%f %f",&x[i],&y[i])   //scans input file
		fprintf(output_file,"%f %f\n",x[i],y[i]); //prints output to output file
        sum+=y[i];
	}

        

	mean = sum/(float)count; 


    mean  = meanfunction(y,count);  //mean of y data
	std_dev = std_devfunction(y,count, mean, output_file);  //standard deviation of y data

	fclose(input_file);    //closes input file
 	fclose(output_file);   //closes output file
	printf("Data output successful!\n");
   
}

float meanfunction(float *y, int count) // Calculates mean of y column of data
{
/*	Here you can put the code to find the standard deviation of the data array	*/
	float sum = 0;
    for (int i = 0; i < count; ++i)
    {
    	sum+=y[i]; //Calculating the sum of numbers in data
    }

    float mean = sum/(float)count; //Calculating mean
    return mean;
}

float std_devfunction(float *y, int count, float mean, FILE *output_file) // Calculates mean of y column of data
{

    float numerator = 0;
	for (int i=0; i < count; ++i)
    {
        numerator += pow((y[i] - mean),2); //calcuating the numerator of standard deviation

    }
    
    float std_dev = sqrt(numerator/(float)count); //calculating standard deviation

    fprintf(output_file,"\nMean of y data = %.3f", mean); //mean output
	fprintf(output_file,"\nStandard deviation of y data = %.3f", std_dev); //standard deviation output

	return std_dev;
}