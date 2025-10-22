/*
23 A 91. Write a program to implement Insertion Sort using Array. 
*/
#include<stdio.h>
#include<string.h>
void insertion_sort(int arr[],int n){
	int key,i=1,j=i-1;
	while(i<n){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
		i++;
	}
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
	insertion_sort(arr,n);
	printf("Sorted Array : [ ");
	for(i=0;i<n;i++){
		printf("%d, ",arr[i]);
	}printf("]");
}
