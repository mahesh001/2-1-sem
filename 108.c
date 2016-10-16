#include<stdio.h>
main()
{
	unsigned int a = 0xffff;
	a=~a;
	printf("%x %x %x",a,+ + a,a);
}
