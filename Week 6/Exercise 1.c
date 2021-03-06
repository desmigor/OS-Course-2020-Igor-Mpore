#include <stdio.h>
#include <stdlib.h>

/*
____Result after compilation of the code____

Enter number of processes: 3
Enter Arrival time of process[1]: 1
Enter Burst time of process[1]: 4
Enter Arrival time of process[2]: 2
Enter Burst time of process[2]: 5
Enter Arrival time of process[3]: 3
Enter Burst time of process[3]: 7
P#       AT      BT      CT      TAT     WT

P1       1       4       5       4       0
P2       2       5       10      8       3
P3       3       7       17      14      7

Average TurnAround time= 8.666667
Average WT= 3.333333

In this code that does process sceduling, processess are executed
according to the way they came (FIFO) and each process executes after
another one is done

*/

/*__________
Igor Mpore
BS19-06
*/
int main(){
	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	int i,j,k;
	
	for (i=0;i<n;i++){
		printf ("Enter Arrival time of process[%d]: ",i+1);
		scanf("%d",&at[i]);
		printf ("Enter Burst time of process[%d]: ",i+1);
		scanf("%d",&bt[i]);
	}

	for (j=0;j<n;j++){
		if(j==0) 
		sum=sum+at[0];
		sum=sum+bt[j];
		ct[j]=ct[j]+sum;
	}
	
	for (k=0;k<n;k++){
		tat[k]=ct[k]-at[k];
		totalTAT=totalTAT+tat[k];
	}
	
	for (k=0;k<n;k++){
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}
	
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t \n\n");
	
	for (i=0;i<n;i++)
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	
	printf("\nAverage TurnAround time= %f\n",totalTAT/n);
	printf("Average WT= %f\n\n", totalWT/n);
	return 0;
}

