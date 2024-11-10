#include <stdio.h>
#include <stdlib.h>
#define max 100
int n;
struct node{
	int data;
	struct node *next;
};
int queue[max];
int visited[max] = {0};
struct node *arr[max];
int i;
int front=0,rear=-1;
void enqueue(int data){
	queue[++rear]=data;
}
int dequeue(){
	return queue[front++];

}
struct node *create(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next =NULL;
	return temp;
}
void add(int a ,int b){
	struct node *temp = create(b);
	temp->next = arr[a];
	arr[a]=temp;
	
	temp = create(a);
	temp->next = arr[b];
	arr[b]=temp;
}
void bft(int src){
	enqueue(src);
	visited[src]=1;
	while(front<=rear){
		int node = dequeue();
		printf("%d",node);
		struct node *temp = arr[node];
		while(temp!=NULL){
			if(visited[temp->data]==0){
				enqueue(temp->data);
				visited[temp->data]=1;
			}
			temp=temp->next;
		}
	}
}
int main(){
	n =6;
	for(i=0;i<n;i++){
	arr[i]=NULL;
}
	add(0,1);
	add(0,2);
	add(1,3);
	add(2,4);
	add(3,5);
	bft(0);
	return 0;
}
