//MergeSort in C

#include <stdio.h> 
#include <stdlib.h> // include needed libraries
void merge(int arr[],int p,int q,int r) // p is left array starting index and q is its last index where r is right array last index
{
	//create left array and right array
	int lsize = q-p+1;	//size of left array
	int rsize = r-q;	//size of right array
	int la[lsize];
	int ra[rsize];
	//copy elements from main array that belong to left array
	int i=0;	//index for left array
	while(i<lsize)
	{
		la[i]=arr[p+i];
		i++;
		
		}	
	int j=0;	//index for right array
	while(j<rsize)
	{
		ra[j]=arr[q+j+1];
		j++;
		}
	//now re-add the elements from left and right array to main array by sorting
	i=0,j=0;	//index of left and right arrays
	int a=p;	//a is index of main array and it starts from starting index of left array
	while(i<lsize && j<rsize)	//loop break if one of the indexes reach their max size
	{
		if(la[i]<=ra[j])		//if left array i-th element less than right array j-th element add left array i-th element to main array	
		{
			arr[a++]=la[i++];		
			}
		else
		{
			arr[a++]=ra[j++];	//if left array i-th element greater than right array j-th element add right array j-th element to main array
			}	
		}
	//after this loop there will atleast one element unmoved to main array..so check that array and elements in that array and move even those elemenents
	if(i<lsize)	//if left array have elements left
	{	while(i<lsize)
		{
			arr[a++]=la[i++];	
		}
	}
	else		//if right array have elements left 
	{
		while(j<rsize)
		{
			arr[a++]=ra[j++];	
		}
	}
	
	
		
}
//function that recursively divides a array and apply merge function from smallest part
void mergesort(int arr[],int l,int h)	//reperest lowest index and h represnt highest index
{	if(l<h)	//if this condition violates it clearly indicates that we cant perform more divison on that subarray
	{
	int m =l+(h-l)/2;	//m represent highest index of left subarray m+1 is to be lowest index of right subarray
	mergesort(arr,l,m);	//divide left subarray recursively  until there is nothing to divide
	mergesort(arr,m+1,h);	//divide right subarray recursively until there is no subarray ti divide
	merge(arr,l,m,h);
//	display(arr,4);	//sort the subarray 
	}
}
void display(int arr[],int size)
{
	int i=0;
	for(i;i<size;i++)
	{
		printf("| %d ",arr[i]);
		}	
}
int main()
{	
	int size;
	printf("enter size of your array\n");
	scanf("%d",&size);
	int arr[size];
	int i=0;
	printf("enter your elements\n");
	for(i;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("before being sorted your array->");
	display(arr,size);
	mergesort(arr,0,size-1);
	printf("after being sorted your array->");
	display(arr,size);
	return 0;	
}

