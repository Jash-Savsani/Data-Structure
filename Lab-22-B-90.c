/*
90. Write a program to implement Selection Sort using Array. 
*/
#include<stdio.h>
#include<string.h>
void selection_sort(int arr[],int n){
	int i,j,min_index,temp;
	for(i=0;i<=n-2;i++){
		min_index=i;
		for(j=i+1;j<=n-1;j++){
			if(arr[j]<arr[min_index]){
				min_index=j;
			}
		}
		if(min_index != i){
			temp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = temp;
		}
	}
	return;
}
void main(){
	int i,n;
	printf("Enter Number of Elements to Store in Array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Enter arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	printf("Sorted Array : [ ");
	for(i=0;i<5;i++){
		printf("%d, ",arr[i]);
	}printf("]");
}
