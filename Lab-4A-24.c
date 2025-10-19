#include<stdio.h>
void main()
{
	int i,n,n2,i2;
	printf("Enter Number of Size of Array:");
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("Before Insert: a=[");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	printf("]");
	printf("\nEnter New Number For Insert:");
	scanf("%d",&n2);
	printf("Enter index For New Number from 0 to %d:",n);
	scanf("%d",&i2);
	for(i=0;i<n+1;i++)//for index check
	{
		if(i2==i)
		{
			for(i=n;i>=i2;i--)
			{
				if(i2==i)
				{
					a[i2]=n2;
					break;
					printf("hello");
				}
				a[i]=a[i-1];
			}
		}
	}
	printf("After Insert: a=[");
	for(i=0;i<n+1;i++)
	{
		printf("%d,",a[i]);
	}
	printf("]");
}
