/*Two Sum Num in Array*/
#include<stdio.h>
void main()
{
	int i,j,n,temp,n2=0;
	printf("Enter Number of Size Of Array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		if(i==0){
			printf("Unsorted Array: a = [");
		}
		printf(" %d, ",a[i]);
		if(i==n-1){
			printf("]");
		}
	}
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			if(a[j]<a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp; 
			}
		}
	}
	for(i=0;i<n;i++){
		if(i==0){
			printf("\nSorted Array: a = [");
		}
		printf(" %d, ",a[i]);
		if(i==n-1){
			printf("]");
		}
	}
	printf("\nEnter Number to Find Sum of Two Numbers:");
	scanf("%d",&temp);
	int *p1,*p2;
	p1=a;
	p2=a;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j && i<j){
				if((*(p1+i) + *(p2+j)) == temp){
					printf("Sum of Two Numbers Answer:[%d,%d]\n",*(p1+i),*(p1+j));
					n2=1;
				}
			}
		}
	}
	if(n2==0){
		printf("Not Pair of Two Element Available For Sum of %d.",temp);
	}
}
