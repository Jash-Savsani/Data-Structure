/* WAP to get and print the array elements using Pointer*/
#include<stdio.h>
#include<stdlib.h>
void main(){
	int i,n;
	printf("Enter Size Of Array:");
	scanf("%d",&n);
//	int a[n];
//	int *ptr;
//	ptr=a;
//	for(i=0;i<n;i++)
//	{
//		printf("Enter a[%d]:",i);
//		scanf("%d",(a+i));
//	}
//	for(i=0;i<n;i++)
//	{
//		printf("\na[%d]:%d",i,(*a+i));
//	}
	int *ptr = (int*)malloc(sizeof(int));//array mate pan ekj ele mate gjya karvi.pachi neche na steps mujab.
	for(i=0;i<n;i++){
		ptr = (int*)realloc(ptr, (i+1)*sizeof(int));
		if(!ptr){
			printf("MEMORY ALLOCATION FAILED ---");
			return;
		}
		printf("Enter a[%d]:",i);
		scanf("%d",(ptr + i));//realloc karvathi pointer size vadhse but te point 
	}	//to pahelana first byte ne j karse&&ptr + (i * sizeof(int));===>this is for store element in that address
	for(i=0;i<n;i++){
		printf("\na[%d]:%d",i,*(ptr+i));//*(ptr+(i*sizeof(int)));==>this is for print element in that address
	}
}
