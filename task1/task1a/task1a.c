#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	/*Program to do some trig*/

	float fAppex_Angle;
	float hypot = 12;
	float opp;

	for(fAppex_Angle = 0; fAppex_Angle <= M_PI / 2; fAppex_Angle += M_PI / 20)
	{

	opp = hypot * sin(fAppex_Angle);

	printf("\nOpposite %% Side = %f:cm",opp);
     
    }

	return 0;
}