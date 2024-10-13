#include <stdio.h> // import needed package
int size = 0;     // it dosent resemble final size of heap that user needed else it resembles instantaneus size of heap array
void swap(int *a,int *b) //swap inputs pointers as arguments
{
	int temp = *a;   //changes made to a,b pointers even affect the value at that memoray location pointed by them	
	*a = *b;
	*b = temp;
}
void maxheapify(int arr[],int size,int i) //it is useful in deletion
{
	int largest = i;	//after moving element to be deleted to last place and reducing size by a unit we continously swap on the element from
	int l = 2*i+1;		// deleted position to end of array until array is found to be sorted
	int r = 2*i+2;
	if(l<size && arr[l]>arr[largest])
	{
		largest =l;
	}
	if(r<size && arr[r]>arr[largest])	
	{
		largest = r;	
	}
	if(largest!=i){
		swap(&arr[largest],&arr[i]);
		heapify(arr,size,largest);
	}
}	
void maxinsert(int arr[],int key)	
{
	arr[size]=key;		//size resemble current space of index for insertion
	int current = size;
	size++;				//incerease size to make sure that it have space left for next elemnt insertion-----2|3|3|size(with no elemeent)
	while(current!=0)
	{	int parent = (current-1)/2;
		if(arr[current]>arr[parent])
		{
			swap(&arr[current],&arr[parent]);
			current = parent;	
	    }
		else
		break;
	}
}
void del(int arr[],int key)
{	int i;
	for(i =0;i<size;i++)
	{
		if(arr[i]==key)
		    break;
	}
	swap(&arr[i],&arr[size-1]);
	size=size-1;
	if(i<size){
		maxheapify(arr,size,i);
	}	
}
void display(int arr[])
{	int i;
	for(i =0;i<size;i++)		
	{
		printf("%d ",arr[i]);
	}
	
}

int main(){
	int arr[10];
	insert(arr,3);
	insert(arr,6);
	insert(arr,18);
	insert(arr,1);
	display(arr);
	return 0;
}

