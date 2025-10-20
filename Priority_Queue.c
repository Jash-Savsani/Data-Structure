#include<stdio.h>
#define N 5
struct element{
	int val;
	int priority;
};
struct element PQ[N];
int f=-1,r=-1;
void enqueue(int x,int y){
	if(r == N-1){
		printf("Priority Queue is Overflow.\n");
	return;
	}
	r++;
	PQ[r].val=x;
	PQ[r].priority=y;
	if(f==-1){
		f=0;
	}
	return;
}
void dequeue(){
	if(f==-1){
		printf("Priority Queue is Overflow.\n");
		return;
	}
	if(f==r){
		printf("Deleted Element : {%d : %d}\n",PQ[f].val,PQ[f].priority);
		f=-1;
		r=-1;
		return;
	}
	int temp = f;
	int i;
	for(i=f+1;i<=r;i++){
		if(PQ[i].priority>PQ[temp].priority){
			temp = i;
		}
	}
	printf("Deleted Element : {%d : %d}\n",PQ[temp].val,PQ[temp].priority);
	for(i=temp+1;i<=r;i++){
		PQ[i-1] = PQ[i];
	}
	r--;
}
void display(){
	if(f==-1){
		printf("Priority Queue is Empty.\n");
		return;
	}
	int i;
	for(i=f;i<=r;i++){
		printf("{%d : %d}\n",PQ[i].val,PQ[i].priority);
	}
}
void main(){
	enqueue(101,9);
	enqueue(115,8);
	enqueue(120,10);
	enqueue(123,7);
	enqueue(145,10);
	dequeue();
	display();
}
