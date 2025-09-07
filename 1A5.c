#include<stdio.h>
void main()
{
	int n;
	printf("Enter Year:");
	scanf("%d",&n);
	if((n%4==0 && n%100!=0)||(n%400==0)){
		printf("%d is Leap Year.",n);
	}
	else{
		printf("%d is not Leap Year.",n);
	}
}
