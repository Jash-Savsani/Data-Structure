//days into year,month,days
#include<stdio.h>
void main()
{
	int n,d,m,y;
	printf("Enter Days:");
	scanf("%d",&n);
	y=(n/365);
	n=(n%365);
	m=(n/7);
	n=(n%7);
	d=n;
	printf("Year:%d\nWeek:%d\nDays:%d",y,m,d);
}
