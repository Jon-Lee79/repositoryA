#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 

void meanfunction();
void stdfunction();


float data [] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};
float sum=0;
int i;
float mean;
float std_dev;
float numerator;
int numbers;

int main()
{
	

	meanfunction();
	stdfunction();
	
	return 0;  // Functions which return a value MUST contain at least one return statement
}

void meanfunction() //function for determining mean of data
{
	printf("Enter the size of the array from data->"); //user input for which numbers of data to include in following functions
    scanf("%d", &numbers);
    printf("%d",numbers);

    for (int i = 0; i < numbers; ++i)
    {
    	sum+=data[i]; //Calculating the sum of numbers in data
    }

    mean = sum/(float)numbers; //Calculating mean
    printf("\nMean = %.3f", mean); //mean output

    return;
}

void stdfunction() //function for determining standard deviation of data
{


    for (int i=0; i < numbers; ++i)
    {
        numerator += pow((data[i] - mean),2); //calcuating the numerator of standard deviation

    }
    
    std_dev = sqrt(numerator/(float)numbers); //calculating standard deviation
    printf("\nStandard deviation = %.3f", std_dev); //standard deviation output

    return;

}