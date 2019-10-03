/*
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

/*
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
float std_devfunction(float *y, int count, float mean);

int main()
{   
	FILE *input_file;
	input_file = fopen("data.dat","w");

    float sum;
    float mean, std_dev;
    int count = 20;
	float x[count];
    float y[count];

    if ((input_file = fopen("data.dat","r")) == NULL)
    {
         printf("\nError! opening file");
         exit(1);
    }
	

	for (int i = 0; i < count; ++i)
	{
		x[i]=i*1.0/4.0;
		y[i]=sin(i*1.0/4.0);

		printf("\n%f", y[i]);
	}


	for (int i = 0; i < count; ++i)
	{
		fprintf(input_file,"%f %f\n",x[i],y[i]);
        sum+=y[i];
	}
	mean = sum/(float)count;


	fclose(input_file);

	mean  = meanfunction(y,count);
	std_dev = std_devfunction(y,count, mean);

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

float std_devfunction(float *y, int count, float mean) // Calculates mean of y column of data
{

    float numerator = 0;
	for (int i=0; i < count; ++i)
    {
        numerator += pow((y[i] - mean),2); //calcuating the numerator of standard deviation

    }
    
    float std_dev = sqrt(numerator/(float)count); //calculating standard deviation

    printf("\nMean of y data = %.3f", mean); //mean output
	printf("\nStandard deviation of y data = %.3f", std_dev); //standard deviation output

	return std_dev;
}