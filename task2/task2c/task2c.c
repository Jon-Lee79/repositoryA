#include <stdio.h>
#include <stdlib.h>

int divide (int a, int b, int*d)
{
	int c = a/b;
	*d = a%b; //gives remainder of division operation

    return c;
}

void divide_list(int*inp, int divisor, int* outp, int len)
{
	int i=0;
	for (i=0;i<len;i++)
	{
		outp[i] = inp[i]/divisor;
	}
}

int main()
{
	int a[] = {1,2,3,4,5};
	int b[4];

	divide_list(a,2,b,4);
	/*
	int x=5;
	int y=3;
	int z;
	int rem;

	z=divide(x,y,&rem);

	printf("%d remainder %d",z,rem);
	*/
}