#include<stdio.h>
void main()
{
	int i,j=0,t1,t2,n;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("Enter Number of Array to You want to Replace:");
	scanf("%d",&t1);
	printf("Enter Number to Replace %d By:",t1);
	scanf("%d",&t2);
	for(i=0;i<n;i++)
	{
		if(a[i]==t1)
		{
			a[i]=t2;
			j=1;
		}
	}
	if(j==0)
	{
		printf("Given Replacement Number %d is Not in Array.",t1);
	}
	else
	{
		printf("\nNow New Array a = [");
		for(i=0;i<n;i++)
		{
			printf("%d,",a[i]);
		}
		printf("]");
	}
}
