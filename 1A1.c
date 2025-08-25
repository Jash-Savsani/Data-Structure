#include<stdio.h>
#define PI 3.14
void main()
{
	int radius;
	float area;
	printf("Enter Radius:");
	scanf("%d",&radius);
	area = (radius*radius*PI);
	printf("\nArea: %f",area);
	
}
