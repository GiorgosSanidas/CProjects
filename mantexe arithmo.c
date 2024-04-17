#include <stdio.h>		//dilosi vithliothikon pou tha xriastoume
#include <stdlib.h>
#include <time.h>

int main (){
	
	int i,number; // dilosi metavliton 
	time_t t;
	
	srand(4402); // arxikopio thn srand me to aem mou
	  
    int rand_num = (rand() % (300 - 1 + 1)) + 1; // ftiaxno to range pou thelo kai to pernao sthn rand_num oste na to xrisimopio sthn sienexia
   // printf("%d",rand_num);
	
	for (i=0; i<8; i++) // ftiaxno ena for loop oste otan oi prospathies tou xristi ftasoun tis 8 na stamatisi to loop !
	{
		printf("Dwse enan arithmo : "); // dinoume ena arithmo kai ton skanaroume
		scanf("%d",&number);
		
		
		
		if (number<rand_num) { // elegxoume an o arithmos einai megaliteros apo afton pou pliktrologisame
		
	
		printf("O arithmos pou anazitame einai megaliteros apo afton pou pliktrologises\n"); 
		printf("Prospathia %d !!! \n",i+1);
		
		}
		
		else if (number>rand_num) { // elegxoume an o arithmos einai mikroteros apo afton pou pliktrologisame
		printf("O arithmos pou anazitame einai mikroteros apo afton pou pliktrologises\n");
		printf("Prospathia %d !!! \n",i+1); 
		
		}

		else if (number==rand_num) i=10; /* to i ginete megalitero apo 8 opote bgenoume apo to loop , episis to i tha mas xriasti
										  gia na dilosoume if sto opio an to i einai 10 simeni oti o xristis brike ton arithmo */
										  
	}
	
	if (i==10) printf ("RIGHT !"); // i>10 simeni oti o xristis vrike ton arithmo
	
	else printf("FAILURE\nThe number was : %d ",rand_num); // to i apo to for eftase to 8 xoris o xristis na vri ton arithmo
	
	
	return 0; // exodos apo to programma !
}
