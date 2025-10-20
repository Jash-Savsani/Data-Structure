/*WAP to sort the array elements using Pointer. */
#include<stdio.h>
void main()
{
	int i,n,j,temp;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	int *ptr = (int*) malloc (sizeof(int));
	for(i=0;i<n;i++){
		ptr = (int*)realloc(ptr,(i+1)*sizeof(int));
		printf("Enter a[%d]:",i);
		scanf("%d",(ptr+i));	
	}
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			if(*(ptr+j) <= *(ptr+j-1)){
				temp = *(ptr+j);
				*(ptr+j) = *(ptr+j-1);
				*(ptr+j-1) = temp;
			}
		}	
	}
	printf("\nSorted Array is : a = [");
	for(i=0;i<n;i++){
		printf("%d ,",*(ptr+i));	
	}
	printf("]"); 
}
