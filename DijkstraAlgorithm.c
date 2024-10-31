//import needed libraries
#include <stdio.h>
#include <stdbool.h>	//to create variables of boolean data type
#include<limits.h>	//for +inf and -inf
#define v 10
int minDistanceFinder(int minDistance[],bool visited[]) //function that finds nearest unvisited nodes from source which be connected directly pr indirectly
{	
	int i;	//for traversal
	int currentMin = INT_MAX; 	//stores dist of node that seemed to have min dist from source until iteration of loop
	int min=0; 		//returns final answer
	for(i=0;i<v;i++)
	{
		if(visited[i] == false && minDistance[i]<=currentMin){
			currentMin = minDistance[i];
			min = i;
	}
	}
	return min;
}
//display
void display(int dist[])
{	int i;
    printf("Vertex Number \t\t Distance from Source Node\n");
    for (i = 0; i < v; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}
//main function
void DijkstraAlgorithm(int graph[v][v],int source)
{
	int minDistance[v];	//array that holds cost efficent dist of ith node from source node
	bool visited[v];	//array that tells if the ith is visted
	int i;	//for traversal
	for(i=0;i<v;i++)
	{	//set all the values in node to default value 
		minDistance[i]=INT_MAX;	//all are set to +inf
		visited[i]=false;	//all are set as unvisited initally
	}
	minDistance[source]=0;	//set source vertex as visted
	for(i=0;i<v-1;i++) // we run v-1 times but not v times because at vth(last time) when we select a node there will node unvisited node left
	{					//one will be unvisited
		int u = minDistanceFinder(minDistance,visited); // so u have the node that is nearest to source node and still is unvisited
		visited[u]=true; //u is made visisted
		int j; //for traversal
		for(j=0;j<v;j++)
		{
			if(!visited[j] && graph[u][j] && minDistance[u]!=INT_MAX &&minDistance[u]+graph[u][j]<minDistance[j])//if not visited and path exist and path of jth node via uth node from source node 
			{																										//is less than the path that current jth node is holding
				minDistance[j]= minDistance[u]+graph[u][j]; //update new costefficent path
			}
		}
	}
	display(minDistance);
}
int main(){
	//v = 9;
	  int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0,19 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 ,0},
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 ,0},
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 ,9 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 ,0},
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0,0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 ,0},
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7,0 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 ,1}, 
						{ 0, 0, 0, 1, 0, 3, 4, 0, 0, 0}
						};
        DijkstraAlgorithm(graph,0);
        return 0;
}
