/*87. Write a program to implement a Linear Search using Array. */
#include<stdio.h>
void main(){
	int i,n,find,temp=0;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Enter arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter Element to Find:");
	scanf("%d",&find);
	for(i=0;i<n;i++){
		if(find == arr[i]){
			printf("Given Element %d is Found in Index : %d",arr[i],i);
			temp=1;
			break;
		}
	}
	if(temp==0){
		printf("Given Element %d is not Found in Array.",find);
	}
}
