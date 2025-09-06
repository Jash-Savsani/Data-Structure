#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Enter First Number:");
	scanf("%d",&a);
	printf("Enter Second Number:");
	scanf("%d",&b);
	printf("Enter Third Number:");
	scanf("%d",&c);
	if(a>=b && a>=c){
		printf("%d is Largest.",a);
	}
	if(b>=c){
		printf("%d is Largest.",b);
	}
	else{
		printf("%d is Largest.",c);
	}
}
