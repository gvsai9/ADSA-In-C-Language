#include <stdio.h>
#define max 100
#include <stdlib.h>
void swap(int *a,int *b){
	int temp =*a;
	*a = *b;
	*b= temp;
}
int size =0;
void insert(int arr[],int data){
	arr[size]=data;
	int current = size;
	size++;
	while(current!=0){
	
	int parent = (current-1)/2;
	if(arr[parent]>arr[current]){
		swap(&arr[parent],&arr[current]);
		current = parent;
	}
	else{
		break;
	}
}
}
void heapify(int size,int arr[],int i){
	int smallest = i;
	int l =2*i+1;
	int r =2*i+2;
	if(l<size && arr[l]<arr[smallest]){
		smallest = l;
	}
	if(r<size && arr[r]<arr[smallest]){
		smallest = r;
	}
	if(smallest!=i){
		swap(&arr[i],&arr[smallest]);
		heapify(size,arr,smallest);
	}
}
void del(int arr[],int data){
	int i;
	for(i=0;i<size;i++){
		if(arr[i]==data){
			break;
		}
	}
	if(i==size){
		printf("no trace of element	");
		return;
	}
	swap(&arr[i],&arr[size-1]);
	size--;
	if(i<size){
		heapify(size,arr,i);	
	}
	
}	
void display(int arr[]){
	int i;
	for(i=0;i<size;i++){
		printf("	%d",arr[i]);
	}
}
int main(){
	int arr[max];
	while(1){
		int ch,data;
		printf("Enter your choice:	");
		printf("\n0 for exit\n1 for display\n2 for insert\n3 for delete\n");
		scanf("%d",&ch);
		switch(ch){
		
		case 0:
			exit(0);
		case 1:
			display(arr);
			break;
		case 2:
			printf("\nenter key to be inserted	");
			scanf("%d",&data);
			insert(arr,data);
			break;
		case 3:
			printf("\nenter key to be deleted	");
			scanf("%d",&data);
			del(arr,data);
			break;
		default:
			printf("\nchoose available options only	");
			break;
	}
}
	return 0;
}
