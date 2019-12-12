#include <stdio.h>
#include <math.h>

void smooth_array(float* data, float* output, int length) // Smooth array function
{
  float window_size = 5; // Set window size  
  float smooth_array_size=(length-(window_size-1)); //filtering calculation
  float temp_value = 0;   //temporary values 
  float sum = 0;   //sum of the values in window 
  
  for(int i = 0; i < smooth_array_size; i++) // For loop to run through data over smooth curve
  {
    sum = 0;
    for (int j = 0; j < window_size; j++) //For loop to create a window from a number of elements in array
    { 
      temp_value=(float)(data[i+j]/window_size); //scale each element
      sum+=temp_value; // to average scaled elements
    }
    output[i]=sum;
  }
}
