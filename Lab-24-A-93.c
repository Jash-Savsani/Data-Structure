/*93. Write a program to implement Merge Sort using Array.*/
#include<stdio.h>
#include<math.h>
int n; 
int a[] = {5,4,3,2,1};
void mergesort(int low,int high){
	if(low<high){
		int mid = floor((low+high)/2);
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}
void merge(int low,int mid,int high){
	int b[] = {5,4,3,2,1};
	int i,j,k,h;
	h=low;
	i=low;
	j=mid+1;
	while(h<=mid && j<=high){
		if(a[h]<=a[j]){
			b[i] = a[h];
			h++;
		}else{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>mid){
		for(k=j;k<=high;k++){
			b[i]=a[k];
			i++;
		}
	}else{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}for(k=low;k<=high;k++){
		a[k]=b[k];
	}
}
void main(){
	int i;
	mergesort(0,4);
	printf("Sorted Array : [ ");
	for(i=0;i<n;i++){
		printf("%d, ",a[i]);
	}printf("]");
}
