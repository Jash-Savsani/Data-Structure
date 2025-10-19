#include<stdio.h>
void main()
{
	int i,n;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	int max=a[0],m1=0;
	int min=a[0],m2=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>max){
			max=a[i];
			m1=i;
		}
		if(a[i]<min){
			max=a[i];
			m2=i;
		}
	}
	printf("Largest Number: %d \n Position(Index): %d",max,m1);
	printf("\n\n\nSmallest Number: %d \n Position(Index): %d",min,m2);
}
