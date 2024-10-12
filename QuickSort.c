// include needed libraries 
#include <stdio.h>
// function for swapping
void swap(int *a,int *b)	//usage of pointers as arguments will even make changes on actual parameters
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
// for sorting sub-array with pivot
int subsort(int arr[],int low,int high)
{
	int pivot = arr[high];	//pivot is always last(high) element in a given sub-array
	int j = low;	//j traverse from low to high-1(1 element less than pivot) and checks for element that are less than pivot 
	int i=low-1;	//its main task is to hold index for elements less than pivot
	for(j;j<=high-1;j++)
	{
		if(arr[j]<=pivot)	//if any element less than pivot is found
		{
			swap(&arr[++i],&arr[j]); //swap that element with largest elenents befor it...
			/*1st largest will be swapped with first smallest and second largest with second smallest
			in this way all elements less than pivot are arranged from low*/
			
		}
	}
	// if loop is completed it means j traversed all elements in array
	//all the elements from low to current ith position are less than pivot so swap i+1 pos with pivot
	swap(&arr[++i],&arr[j]);	//so after swapping elements to left of pivot are less than it
	return i;	//return current pivot position for further divison of left and right sub arrays
}
//main sort function that recursively divides array into small parts and sort these parts individually
void quicksort(int arr[],int low,int high)
{
	if(low<high)	//stops exectution if further divison of array is possible(ie:- if single element is only left)
	{
		int pivotposition = subsort(arr,low,high);	//performs sort on array[low..high] and return pivot position
		quicksort(arr,low,pivotposition-1);	//performs sort on array[low,pivot-1]--on elements left of pivot
		quicksort(arr,pivotposition+1,high);	//performs sort on array[pivot+1,high]--on elements right of pivot
	}
}
//display function
void display(int arr[],int size)
{
	int i=0;
	for(i;i<size;i++)
	{
		printf("%d |",arr[i]);
	}
}
int main()
{
	int size;
	printf("enter size of your array\n");
	scanf("%d",&size);
	if(size<=0)
	{
		printf("%d is not valid value for size always size>=1",size);
	}
	int arr[size];
	int i =0;
	printf("enter elements of your array\n");
	for(i;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nbefore sorting\n");
	display(arr,size);
	quicksort(arr,0,size-1);
	printf("\nafter sorting\n");
	display(arr,size);
	return 0;
	
}

