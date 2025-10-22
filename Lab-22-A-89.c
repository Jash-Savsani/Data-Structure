/*
89. Write a program to implement Bubble using Array. 
*/
#include<stdio.h>
#include<string.h>
void bubble_sort(int arr[],int n){
	int last=n-1,exchs=0,temp,i,j;
	for(i=0;i<=n-2;i++){
		exchs=0;
		for(j=0;j<=last-1;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				exchs++;
			}
		}
		if(exchs==0){
			return;	
		}
		last--;
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
	bubble_sort(arr,n);
	printf("Sorted Array : [ ");
	for(i=0;i<n;i++){
		printf("%d, ",arr[i]);
	}printf("]");
}
