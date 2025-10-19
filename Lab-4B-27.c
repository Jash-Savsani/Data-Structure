#include<stdio.h>
void main()
{
	int i,j,n,n2,i2,temp=0;
	printf("Enter Number of Size of Array:");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter All Elements in Assending Order:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("Enter Number For Deletaion:");
	scanf("%d",&n2);
	for(i=0;i<n;i++)
	{
		if(a[i]==n2)
		{
			for(j=i;j<n;j++)
			{
				a[j]=a[j+1];
			}
			a[n-1]=n2;
			temp=1;
			break;
		}
	}
	if(temp==0)
	{
		printf("\nGiven Number is Not Found.");
	}
	else
	{
		n--;
	}
	printf("\nAfter Deletation: a=[");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	printf("]");
	
}
