#include<stdio.h>
void main()
{
	int j,i,n,n1;
	printf("Enter Number of Size of Array:");
	scanf("%d",&n);
	int a[n+1];
	printf("\nEnter All Elements in Assending Order:\n");
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
	printf("\nEnter Number:");
	scanf("%d",&n1);
	for(i=0;i<n;i++)
	{
		if(a[i]>n1)
		{
			for(j=n;j>i;j--)
			{
				a[j]=a[j-1];
			}
			a[i]=n1;
			break;
		}
	}
	printf("After Deletation: a=[");
	for(i=0;i<=n;i++)
	{
		printf("%d,",a[i]);
	}
	printf("]");
}
