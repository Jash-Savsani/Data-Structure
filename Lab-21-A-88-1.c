/*88. Write a program to implement a Binary Search using Array. (Iterative) */
#include<stdio.h>
#include<math.h>
void main(){
	int n,i,find,middle,temp=0;
	printf("Enter Size of Sorted Array:");
	scanf("%d",&n);
	int arr[n],left=0,right=n-1;
	for(i=0;i<n;i++){
		printf("Enter arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter Element to Find in Array:");
	scanf("%d",&find);
	while(left<=right){
		middle = (left + right)/2;
		middle = floor(middle);
		if(find == arr[middle]){
			printf("Given Element %d is Found in %d Index.",find,middle);
			temp=1;
			break;	
		}
		else if(find < arr[middle]){
			right = middle - 1;
		}
		else if(find > arr[middle]){
			left = middle + 1;
		}
	}
	if(temp==0){
		printf("Given Element %d id Not Found in Array.",find);
	}
}
