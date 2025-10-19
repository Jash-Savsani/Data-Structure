/*. Write a program to delete duplicate numbers from an array.*/
#include<stdio.h>
void main()
{
	int j,i,n;
	printf("Enter Size Of Array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("Before Inserting: a = [");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	printf("]");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]!=-1 && a[i]==a[j])
			{
				a[j]=-1;
			}
		}
	}
	printf("\nAfter Deletation: a=[");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	printf("]");
}
