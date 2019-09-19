#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   
	FILE * input_file;
	input_file = fopen("data.dat","w");
	int count = 10;
	float x[count];
	float y[count];

	float mean;
	float std_dev;
	float sum;
	float numerator;
	int i;
	sum=0;

	for (int i = 0; i < count; ++i)
	{
		x[i]=i*1.0/4.0;
		y[i]=sin(i*1.0/4.0);

		printf("%f", y[i]);
	}


	for (int i = 0; i < count; ++i)
	{
		fprintf(input_file,"%f %f\n",x[i],y[i]);

	}

	fclose(input_file);

}

int mean()
{
/*	Here you can put the code to find the standard deviation of the data array	*/
    for (int i = 0; i < count; ++i)
    {
    	sum+=y[i]; //Calculating the sum of numbers in data
    }

    mean = sum/(float)count; //Calculating mean

}

int std_dev()
{
	for (int i=0; i < count; ++i)
    {
        numerator += pow((y[i] - mean),2); //calcuating the numerator of standard deviation

    }
    
    std_dev = sqrt(numerator/(float)count); //calculating standard deviation

    printf("\nMean = %.3f", mean); //mean output
	printf("\nStandard deviation = %.3f", std_dev); //standard deviation output

}