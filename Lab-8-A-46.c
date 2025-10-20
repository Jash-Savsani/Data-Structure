/*
46. Write a menu driven program to implement following operations on the Queue 
using an Array 
• ENQUEUE 
• DEQUEUE 
• DISPLAY
*/
#include<stdio.h>
#define n 5
int f=-1,r=-1;
int queue[n];
void enqueue(int y){
	if(r>=n-1){
		printf("Queue is Overflow.\n");
		return;
	}
	queue[++r]=y;
	if(f==-1){
		f=0;
	}
	return;
}
int dequeue(){
	if(f==-1){
		printf("queue is empty.\n");
		return -1;
	}
	int y=queue[f];
	if(f==r){
		f=-1;
		r=-1;
	}
	else{
		f++;	
	}
	return y;
}
void display(){
	if(f==-1){
		printf("Queue is Empty.\n");
		return;
	}
	int i;
	printf("Queue Elements : ");
	for(i=f;i<=r;i++){
		printf("%d\t",queue[i]);
	}printf("\n");
}
void main(){
	int i,n2;
	printf("1.Enqueue\n2.Dequeue\n3.Display\n\n");
	printf("Enter -1 to Break a Loop.");
	while(1){
		printf("Enter Your Choise:");
		scanf("%d",&i);
		if(i==-1)
			break;
		switch(i){
			case 1:printf("\nEnter Number for Enqueue:");
					scanf("%d",&n2);
					enqueue(n2);
					break;
			case 2: n2 = dequeue();
					printf("\nDequeue Number is : %d\n",n2);
					break;
			case 3: display();
		}
	}
}
