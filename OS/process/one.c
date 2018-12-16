
#include<stdio.h>
#include<stdarg.h>



int main( int argc, char * argv[])
{

	int a, b;// =0;
	va_list list;


//	va_start(list,argc);

	//va_arg(list,;

	//a = va_arg(list, int);
	//b = va_arg(list, int);
	
	a = atoi(argv[2]);
	b = atoi(argv[3]);

	printf("\nthis is ONE prgram sum %d = ",a+b);
	return 0 ;
}
