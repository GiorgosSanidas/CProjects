#include <stdio.h>		
#include <stdlib.h>
#include <time.h>

int main (){
	
	int i,A[10];
	
	srand (4402);
	
	for (i=0; i<10; i++){
		
		
    	A[i] = (rand() % (10 - 0 + 1)) + 0;

    	if (A[i]<5) printf("The grade is : %d - insufficiently\n",A[i]);
    	
    	else if (A[i]<7) printf("The grade is : %d - good\n",A[i]);
    	
    	else if (A[i]<9) printf("The grade is : %d - very good\n",A[i]);
    	
    	else  printf("The grade is : %d - excellent\n",A[i]);
	
	}
	
	return 0;
}
