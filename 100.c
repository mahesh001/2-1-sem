#include<stdio.h>
main()
{
	int a;
	int i=10;
	printf("%d %d %d\n",i+++i,i,i---i);
	printf("%d\n",i---i);
	a=i---i;
	printf("%d \n%d",a,i);
	return 0;
}
