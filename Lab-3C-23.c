#include<string.h>/*Capital and Small Both Considering Same.*/
#include<stdio.h>
void main()
{	
	int i,j,n;
	printf("Enter Total Number for Adding Names:");
	scanf("%d",&n);
	char name[n][50];
	char temp[50]="";
	for(i=0;i<n;i++)
	{
		printf("Enter name[%d][50]:",i);
		scanf("%s",name[i]);
	}
	for(j=1;j<n;j++)
	{
		for(i=1;i<n;i++)
		{
			if(name[i][0] < name[i-1][0])
			{
				strncpy(temp,name[i-1],50);
				strncpy(name[i-1],name[i],50);
				strncpy(name[i],temp,50);
			}
		}
	}
	printf("After Sorting Alfabatic Assending Order : name = [");
	for(i=0;i<n;i++)
	{
		printf(" %s, ",name[i]);
		if(i==n-1)
		{
			printf("]");
		}
	}
}
