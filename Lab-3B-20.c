#include<stdio.h>
void main()
{
	int i,j,n;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	int a[n],temp=0;
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i != j){
				if(a[i]==a[j] && i<j )
				{
					printf("\nYes. Duplicate Element is a[%d]=a[%d]=%d",i,j,a[i]);
					temp=1;
				}
			}
		}
	}
	if(temp==0){
		printf("\n Given Array not contains Duplicate Elements.");
	}
	else
	{
		printf("\nYes Given Array contains Duplicate Elements.");
	}
}
