//include needed packages
#include <stdio.h>
//function that check max of two elements.In this program it check max of profits when included or exclude the items
int max_of_two(int a,int b)
{
	return a>b?a:b;	//in returns the max of both
 }
 
 //main knapsack method
 int knapsack(int capacity,int weights[],int profits[],int items)	//capacity-bag total capacity	weights and profits- ith in profits resemeble and ith weight are pair 
 {
 	int i ,pc;	//for iterations  pc-present capacity
 	int table[items+1][capacity+1]; 	//table that stores max profit for first ith items upto limit of capacity pc
 	for(i=0;i<=items;i++){
 		for(pc=0;pc<=capacity;pc++){
 			if(i==0||pc==0){
 				table[i][pc]=0;
			 }
			else if(weights[i-1]<=pc){	//if present item's wt is less that present capacity that is being considered then include it
			 	table[i][pc] = max_of_two(profits[i-1]+table[i-1][pc-weights[i-1]],table[i-1][pc]);	//max(sum of current profit + profit with remaining items with 1 item less,profit exluding this item)
				}
			else{
				table[i][pc]=table[i-1][pc];
			}
		 }
	 }
	 return table[items][capacity];
	 
  } 
//main function starts
int main(){
	int items;
	printf("enter number of items:	");
	scanf("%d",&items);
	int i;
	int weights[items];
	int profits[items];
	for(i=0;i<items;i++){
		printf("enter weight of %d item:	",i+1);
		scanf("%d",&weights[i]);
		printf("enter profit of %d item:	",i+1);
		scanf("%d",&profits[i]);
	}
	printf("your list of weight-profits pair\n");
	for(i=0;i<items;i++){
		printf("%d	%d\n",weights[i],profits[i]);
	}
	int capacity;
	printf("enter capacity:	");
	scanf("%d",&capacity);
	printf("%d",capacity);
	int ans = knapsack(capacity,weights,profits,items);
	printf("Maximum profit can be made:	%d",ans);
	return 0;
}
