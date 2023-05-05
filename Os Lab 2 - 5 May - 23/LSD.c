#include<stdio.h>
int main(){
	int amount , notes[10] = {0};
	printf("Enter the amount: " );
	scanf("%d",&amount);
	int denom[10]={2000,500,200,100,50,20,10,5,2,1};
	for(int i=0 ; i<5;i++){
		notes[i] = amount / denom[i];
		amount %= denom[i];
	}
	printf("Number of 2000 notes: %d\n",notes[0]);
    printf("Number of 500 notes: %d\n", notes[1]);
	printf("Number of 200 notes: %d\n", notes[2]);
	printf("Number of 100 notes: %d\n", notes[3]);
	printf("Number of 50 notes: %d\n", notes[4]);
	printf("Number of 20 notes: %d\n", notes[5]);
	printf("Number of 10 notes: %d\n", notes[6]);
	printf("Number of 5  notes: %d\n", notes[7]);
	printf("Number of 2 notes: %d\n", notes[8]);
	printf("Number of 1 notes: %d\n", notes[9]);
	return 0;
}
