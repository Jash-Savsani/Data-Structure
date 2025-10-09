#include<stdio.h>
void main(){
	int n,i;
	printf("Enter Total Numbers Of Elements in Array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("\n\nArray a = [");
	for(i=0;i<n;i++){
		printf("%d,",a[i]);
	}
	printf("]");
}
