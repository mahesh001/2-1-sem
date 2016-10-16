#include<stdio.h>
struct s
{
	unsigned a:5;
	unsigned b:5;
//	unsigned c:5;
//	unsigned d:5;
}v={1,2};
main()
{
	printf("size of v = %d",sizeof(v));

}
