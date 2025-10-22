/*88. Write a program to implement a Binary Search using Array. (recursive) */
#include<stdio.h>/*For Binary Search Given Array is must be Sorted.*/
#include<math.h>
int recursive_binary_search(int left,int right,int middle,int arr[],int find){
		middle = (left + right)/2;
		middle = floor(middle);
		if(find == arr[middle]){
			return arr[middle];
		}
		else if(find < arr[0] || find > arr[right]){
			return 0;
		}
		else if(find < arr[middle]){
			recursive_binary_search(left,middle-1,middle,arr,find);
		}
		else if(find > arr[middle]){
			recursive_binary_search(middle+1,right,middle,arr,find);
		}
}
void main(){
	int n,i,find,middle=0,temp=0;
	printf("Enter Size of Sorted Array:");
	scanf("%d",&n);
	int arr[n],left=0,right=n-1;
	for(i=0;i<n;i++){
		printf("Enter arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter Element to Find in Array:");
	scanf("%d",&find);
	i = recursive_binary_search(left,right,middle,arr,find);
	if(i!=0){
		printf("\nGiven Element %d is Found.",i);
	}
	else{
		printf("\nGiven Element %d is not Found.",find);
	}
}
