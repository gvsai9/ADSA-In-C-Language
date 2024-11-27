//include needed packages
#include <stdio.h>
#include <limits.h> //to create a variable that holds +inf 
#define max 16
int dist[max][max];	//it is dist table dist[i][j] gives path cost from ith city to jth city -rows and col reprensent city numbers(0,1,2...)
int dp[1<<max][max]; //it is eqvivalent to dp[2^max][max] where row represent set of cities already visited and col represent current city no of person after travelling those set of cities
int n;	//total number of cities
//main tsp function
int tsp(visited,current)//when visited is converted to binary..all position with value(1) are visted and value(0) are unvisited...EX:-(0101) 0 and 2nd pos from right are 1...so 0 and 2 are visited
{
	if(visited==(1<<n)-1) // (1<<n)-1 always return a binary number with all "n" digits as 1.Ex:n=4 (1<<3)-1=1111(means all cities arw visited
	{
		return dist[current][0]; //when all cities are visited salesman should travel back from current pos to starting(ie:0) directly
	}
	if(dp[visited][current]!=-1)	//in some cases we get a situation to recalculate calculated part.then dont recalculate instead return calculated and stored value
	{
		return dp[visited][current]; 
	}
	int ans = INT_MAX; 
	int city;
	for(city=0;city<n;city++)
	{
		if((visited & (1<<city))==0) 	//1<k return a binary number with only kth pos from right as 1 Ex(1<<1) is 0010
		{
			int currentAns=dist[current][city]+tsp(visited|1<<city,city);
			ans = (currentAns < ans) ? currentAns : ans;

		}
	}
	dp[visited][current]=ans;
	return ans;
}

int main()
{
	printf("Enter number of cities\n");
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("enter path cost b/w city-%d and city-%d\n",i,j);
			scanf("%d",&dist[i][j]);
		}
	}
	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++)
		{
			dp[i][j]=-1;
		}
	}
		for(i=0;i<n;i++){
			printf("\n");
		for(j=0;j<n;j++){
			printf("%d	",dist[i][j]);
		}
	}
	int ans = tsp(1,0);
	printf("%d",ans);
	return 0;
}
