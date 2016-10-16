#include<stdio.h>
main()
{
	int *i,*j,**k;
    j=i+2;
	k=&i;
	printf("\n*k=%u j=%u i=%u",*k,j,i);
}
