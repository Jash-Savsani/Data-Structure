#include<stdio.h>
void main()
{
	int n,i,j,l1=0,l2=0,l3=0;
	printf("Enter Size of Array a1:");
	scanf("%d",&n);
	int a1[n];
	for(i=0;i<n;i++)
	{
		printf("Enter a1[%d]:",i);
		scanf("%d",&a1[i]);
		l1++;
	}
	printf("Enter Size of Array a2:");
	scanf("%d",&n);
	int a2[n];
	for(i=0;i<n;i++)
	{
		printf("Enter a2[%d]:",i);
		scanf("%d",&a2[i]);
		l2++;
	}
	l3=l1+l2;
	int a3[l3];
	for(j=0;j<l1;j++)
	{
		a3[j]=a1[j];
	}
	for(j=0;j<l2;j++)
	{
		a3[l1+j]=a2[j];
	}
	printf("\n\nAfter Merging:\na1=[");
	for(i=0;i<l1;i++)
	{
		printf("%d,",a1[i]);
	}
	printf("]");
	printf("\na2=[");
	for(i=0;i<l2;i++)
	{
		printf("%d,",a2[i]);
	}
	printf("]");
	printf("\na3=[");
	for(i=0;i<l3;i++)
	{
		printf("%d,",a3[i]);
	}
	printf("]");	
}
