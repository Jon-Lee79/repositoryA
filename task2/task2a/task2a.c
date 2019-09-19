#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	int y;
	int* p;

	x=5;
	y=7;
	p=&x;

	printf("x=%d\ny=%d\np=%p",x,y,p);

	printf("\n*p=%d",*p);

	*p += 2;

	printf("\nx=%d\ny=%d\n*p=%d",x,y,p);

	p += 2000;
	printf("\nx=%d\ny=%d\n*p=%d",x,y,p);
}