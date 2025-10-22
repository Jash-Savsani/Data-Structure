/*94. Write a program to implement Quick Sort using Array. */
#include<stdio.h>
void Quick_Sort(int arr[],int lb,int ub){
 	int i,j,flag=1;
 	if(lb<ub){
 		 i=lb;
 		 j=ub+1;
 		int key=arr[lb],temp;
 		while(flag==1){
 			i++;
 			while(arr[i]<key){
 				i++;
			 }
			 j--;
			while(arr[j]>key){
				j--;
			}
			if(i<j){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			else{
				flag=0;
			}
		 }
		temp=arr[lb];
		arr[lb]=arr[j];
		arr[j]=temp;
		Quick_Sort(arr,lb,j-1);
		Quick_Sort(arr,j+1,ub);
	 }
}
void main(){
	int n,i;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Enter arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	Quick_Sort(arr,0,n-1);
	printf("\nSorted Array : [ ");
	for(i=0;i<n;i++){
		printf("%d, ",arr[i]);
	}printf("]");
}
