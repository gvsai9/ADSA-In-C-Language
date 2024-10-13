#include <stdio.h>
#define max 100
int adjMatrix[max][max];
int stack[max];
int visted[max] = {0};
int top =-1;
int numberOfVertices=5;
void addEdge(int node1,int node2)
{
	adjMatrix[node1][node2]=1;
	adjMatrix[node1][node2]=1;
}
void push(int data)
{
	stack[++top]=data;
}
int pop()
{
	return stack[top--];
}
void dfs(int key)
{
	push(key);
	visted[key]=1;
	while(top>=0){
		int currentNode = pop();
		int i;
		for(i=0;i<numberOfVertices;i++){
			if(adjMatrix[currentNode][i]==1 && visted[i]==0){
				push(i);
				visted[i]=1;
			}
		}
		printf("-%d-",currentNode);
	}
}
int main()
{
	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(3,4);
	dfs(0);
	return 0;
		
}
