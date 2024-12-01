//include needed packages
#include <stdio.h>
#include <stdbool.h>
#define max 256
int N;	//Size of chess board
int board[max][max]={0};
//function that says if queen can be placed in the given pos
bool isValid(int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)	//check if there is any queen in this col form "0" ROW to "row-1" ROW 
	{
		if(board[i][col]==1){	//if there is queen then it is invalid pos to place so return Falsw
			return false;
		}
	}
	for(i=row,j=col;i>=0&&j>=0;i--,j--){	//check if there is any queen in upper-left diagonal
		if(board[i][j]==1){
			return false;
		}
	}
	for(i=row,j=col;i>=0&&j<=N;i--,j++){	//check if there are any queen in upper right diagonal
		if(board[i][j]==1){
			return false;
		}
	}
	return true;	//if pos [row][col] is valid ("no need to check lower diagonals as we start placing from 0th row and come down..there will be no queen present as of now
}
//main queenFunction that is callled in recursions
bool NQueen(int row)	//returns a valid pos [row][col] for the given row
{
	if (row>=N){
		return true;
	}
	int col;
	for(col=0;col<N;col++){
		if(isValid(row,col)){
			board[row][col]=1;
			if(NQueen(row+1)){
				return true;
			}
			board[row][col]=0;
		}
	}
	return false;
}
void display()
{
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%s",board[i][j]==1?"Q":"*");

		}
		printf("\n");
	}
}
int main(){
	printf("enter size of board\n");
	scanf("%d",&N);
//	board[max][max]={0};
	if(NQueen(0)){
		display();
	}
	else{
		printf("no solution");
	}
	return 0;
}

