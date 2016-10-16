//#define INC #include
//INC <stdio.h>
#include<stdio.h>

main()
{
	static int i=10,*j,**k;
	j=&i;
	k=&j;
	j++;
	printf("the address of i is %u and the value in j is %d\n",&i,j);
	printf("k is %d\n",k);
	printf("the j is %u\t the k is %u\n",j,k);
}
