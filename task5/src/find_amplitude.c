#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float find_amplitude(float* input, int length) //Find amplitude function
{
	float high = -256; //Set high value
	float low = 256;  //Set low value

	for (int i = 0; i < length; i++) //For loop to run through lenth of amplitude
	{
		if(input[i] > high) high = input[i]; // if statement for high value in input array
		if(input[i] < low) low = input[i]; // if statement for low value in input array
	}
	
	float amplitude = (high-low)/2; //Averages amplitude values
	return amplitude;
}
