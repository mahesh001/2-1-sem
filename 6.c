#include<stdio.h>
#include<stdlib.h>

main(int argc ,char *argv[])
{
    int c;
	FILE *of;
	FILE *f;
	of=fopen(argv[2],"w");
	f=fopen(argv[1],"r");
	while(c=getc(f)!=EOF)
		putc(c,of);
	close(of);
	close(f);
}
