#include<stdio.h>
void main()
{
	int sum=0,i,n1,n2;
	printf("Enter First Number:");
	scanf("%d",&n1);
	printf("Enter Second Number:");
	scanf("%d",&n2);
	for(i=n1;i<=n2;i++)
	{
		sum+=i;
	}
	printf("Sum of %d to %d is : %d",n1,n2,sum);
}
