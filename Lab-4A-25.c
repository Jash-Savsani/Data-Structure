#include<stdio.h>
void main()
{
	int i,j,n,n2,i2;
	printf("Enter Number of Size of Array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("Enter Index For Deletaion:");
	scanf("%d",&i2);
	n2=a[i2];
	for(i=0;i<n;i++)
	{
		if(i==i2)
		{
			for(j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			a[n-1]=n2;
		}
	}
	n--;
	printf("After Deletation: a=[");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	printf("]");
}
