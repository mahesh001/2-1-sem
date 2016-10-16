#include<stdio.h>
#define INT 1
main()
{
	struct a
	{
		int type;
	};
	struct c
	{
		int type;
		int e;
	};
	struct b
	{
		int type;
		float f;
	};
	union
	{
		struct a n;
		struct b nf;
		struct c ni;
	}all;
	all.ni.type=INT;
	all.nf.f=10.43;
	all.ni.e=1;
 	printf("%f\n",all.nf.f);
	if(all.nf.type==INT)
		printf("float value =%2.1f",all.nf.f);
	if(all.ni.type==INT)
		printf("\ninteger value=%d",all.ni.e);
	printf("\n%d %d %d %f",all.ni.type,all.nf.type,all.ni.e,all.nf.f);
}
