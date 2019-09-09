#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	/*Program to do some trig*/

	float angle;
	float hypot = 12;
	float opp[30];
	int i;

	for(i = 0; i < 30; i++)
	{

	angle = (M_PI/2) * (i/30.0);
	opp[i] = hypot * sin(angle);

	printf("\nOpposite %% Side = %f:cm",opp[i]);
     
    }

    printf("Angle S = %f",opp[4]);

	return 0;
}