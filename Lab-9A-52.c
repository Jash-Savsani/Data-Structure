#include<stdio.h>
void main()
{
	int i,n,max;
	printf("Enter Total Numbers:");
	scanf("%d",&n);
	int *ptr = (int*)malloc(sizeof(int));
	for(i=0;i<n;i++){
		ptr = (int*)realloc(ptr,((i+1)*sizeof(int)));
		printf("Enter %d. Number: ",i+1);
		scanf("%d",(ptr+i));
		if(i==0){
			max=*ptr;
		}
		if(i>0){
			if(max < *(ptr+i)){
				max = *(ptr+i);
			}
		}
	}
	printf("\nMAX:%d",max);
}
