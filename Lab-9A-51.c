/*WAP to calculate the sum of n numbers using Pointer.*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,n,total=0;
	printf("Enter Total Numbers:");
	scanf("%d",&n);
	int *ptr = (int*)malloc(sizeof(int));
	for(i=0;i<n;i++)
	{
		ptr = (int*)realloc(ptr,((i+1)*sizeof(int)));
		printf("Enter %d. Number: ",i+1);
		scanf("%d",(ptr+i));
		total+=*(ptr+i);
	}
	printf("Sum Of Total %d Number is : %d",n,total);
}
