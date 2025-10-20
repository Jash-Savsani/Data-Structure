/*WAP to allocate and de-allocate memory for int, char and float variable at 
runtime. */
#include<stdio.h>
#include<stdlib.h>
void main()
{
//	int a = 5;
//	float b = 10.2;
//	char c = 'J';
//	int *a1=&a;
//	float *b1 = &b;
//	char *c = &c;
	int *a = (int*)malloc(sizeof(int));
	float *b = (float*)malloc(sizeof(float));
	char *c = (char*)malloc(sizeof(char)); 
	printf("Enter a(int) = ");
	scanf("%d",a);//here we not need to specify & person
	printf("Enter b(float) = ");
	scanf("%f",b);//here we not need to specify & person
	fflush(stdin);
	printf("Enter c(char) = ");
	scanf("%c",c);//here we not need to specify & person
	printf("&a=%d\na=%d\n&b=%f\nb=%f\n&c=%c\nc=%c",a,*a,b,*b,c,*c);	
}
