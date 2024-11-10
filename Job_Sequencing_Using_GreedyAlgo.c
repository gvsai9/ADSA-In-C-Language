//include needed libraries
#include <stdio.h>
 //create a structure of job type
 struct job{
 	char ID;
 	int profit;
 	int deadline;
 };
 void jobSequencing(struct job jobs[],int num_of_jobs){
 	//sort jobs according to profits
 	int i,j;
 	for(i=0;i<num_of_jobs-1;i++){
 		for(j=i+1;j<num_of_jobs;j++){
 			if (jobs[j].profit>jobs[i].profit){ //if true swap them
 				struct job temp = jobs[i];
 				jobs[i]=jobs[j];
 				jobs[j]=temp;
			 }
			 
		 }
	 }
	//now all jobs are sorted according to their profits
	int ans[num_of_jobs];//final answer is in this array
	for(i=0;i<num_of_jobs;i++){
		ans[i]=-1;
	} 
	for(i=0;i<num_of_jobs;i++){
		for(j=jobs[i].deadline-1;j>=0;j--){
			if(ans[j]==-1){
				ans[j]=i;
				break;
			}
			
		}
	}
	for(i=0;i<num_of_jobs;i++){
		if(ans[i]!=-1){
			printf("%c	",jobs[ans[i]].ID);
		}
	}
 }
 int main(){
 	int num_of_jobs;
 	printf("enter number of jobs");
 	scanf("%d",&num_of_jobs);
 	getchar();
 	struct job jobs[num_of_jobs];
 	int i;
 	
 	for(i=0;i<num_of_jobs;i++)
 	{
 		printf("enter ID of job-%d\n",i+1);
 		jobs[i].ID=getchar();
 		getchar();
 		
 		printf("enter profit of job-%d\n",i+1);
 		scanf("%d",&jobs[i].profit);
 		printf("enter deadline of job-%d\n",i+1);
 		scanf("%d",&jobs[i].deadline);
 		getchar();
 		
	 }
	 jobSequencing(jobs,num_of_jobs);
	 return 0;
 	
 }
