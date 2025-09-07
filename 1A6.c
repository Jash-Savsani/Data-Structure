//minue second hour
#include<stdio.h>
void main()
{
	int n,h,m,s;
	printf("Enter Total Seconds:");
	scanf("%d",&n);
	h=(n/3600);
	n=(n%3600);
	m=(n/60);
	n=(n%60);
	s=n;
	printf("Hour:%d\nMinute:%d\nSecond:%d",h,m,s);	
}
