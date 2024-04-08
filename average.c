#include <stdio.h>		
#include <stdlib.h>
#include <time.h>

int main (){


	int i,A[10],max,min,sum,positionMin,positionMax;
	double m_o=0;
	
	srand (4402);
	
	for (i=0; i<10; i++){
		
    	A[i] = (rand() % (100 - 1 + 1)) + 1;
    	
	}
	
	max=A[0];
	min=A[0];
	
	for (i=0; i<10; i++){
		
    	sum=sum+A[i];
    	
		if (max<A[i]) {
			
			max=A[i];
			positionMax=i;
		}
		
		if (min>A[i]) {
			
			min=A[i];
			positionMin=i;
			
		}

	}
	
	m_o=sum/10;
	
	printf("H mesh timh ton 10 arithmon einai : %.1f\n",m_o);	
	printf("O megistos arithmos einai : %d kai brethike stin thesi : %d\n",max,positionMax);
	printf("O mikroteros arithmos einai : %d kai brethike stin thesi : %d\n",min,positionMin);
	
	return 0;
	
	
}
