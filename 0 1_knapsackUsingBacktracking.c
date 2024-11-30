//include needed packages
#include <stdio.h>
#define size 100
int noOfItems;	//total number of items
int weights[size];	//array of weights
int profits[size];	//array of profits
int maxProfit=0;	//final answer that have maximum profit(initally make it zero at the end answer will be stored)
int capacity;	//total capacity of bag

//max function that returns max of 2 values
int maxOfTwo(int a,int b)
{
	return (a>b)?a:b;
}
//knapsack function
void knapsack(int currentWeight,int currentProfit,int itemNo,int *max)	
{
	if(itemNo==noOfItems)//if bag is full then need not to add more items instead check the profit made by this particular combination
	{
		if(currentWeight<=capacity)	//make sure the currentWt is not being exceeded than capacity of bag
		{
			*max = maxOfTwo(currentProfit,*max);
		}
		return;
	}
	//if bag have still space left
	
	if(currentWeight+weights[itemNo]<=capacity)	//if even after adding new item if bag have capacity to hold
	{
		knapsack(currentWeight+weights[itemNo],currentProfit+profits[itemNo],itemNo+1,max);
	}
	knapsack(currentWeight,currentProfit,itemNo+1,max);	//now try to not to add item and proceed further
	
	
}
//main function
int main()
{
	printf("Enter number of items\n");
	scanf("%d",&noOfItems);
	int i; //for traversal
	for(i=0;i<noOfItems;i++)
	{
		printf("Enter weight of item-%d\n",i+1);
		scanf("%d",&weights[i]);
		printf("Enter profit of item-%d\n",i+1);
		scanf("%d",&profits[i]);
	}
	printf("Enter capacity\n");
	scanf("%d",&capacity);
	knapsack(0,0,0,&maxProfit);
	printf("weights");
	for(i=0;i<noOfItems;i++){
		printf("	%d",weights[i]);
	}
	printf("\nprofits");
	for(i=0;i<noOfItems;i++){
		printf("	%d",profits[i]);
	}
	printf("\ncapacity-%d",capacity);
	printf("\nMaximum profit from above data-%d",maxProfit);
	return 0;
}
