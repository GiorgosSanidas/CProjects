#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,sel,log[1000],ar,s_pin,pin,found,am,pin2,money,x_50=10,x_20=20,mik=1000,meg=50000;
float ch[1000]; 
char username,username2;
int dek2oct(int num);




int main()
{
	FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  pFile = fopen ( "accounts" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  

  
  fclose (pFile);
  free (buffer);
	
	
	
	
	int num,k, i,j,tmes=2;
	
	char trde;
	
	srand(time(NULL));
	
	for(i=0; i<1000; i++)
    {
    	log[i]=i+2000;
	}
	
	for(i=0; i<1000; i++)
    {
    	ch[i]= (rand()%(meg-mik+1)) + mik;
		
	    ch[i]= ch[i]/10; 
    	
		
		
	}
	
	do{
	
	
	printf("\n\n      πειραματικο ΑΤΜ τμηματος πληροφορικης   ");
	printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	printf("\n\n1. ενημερωση                                  3. αναληψη                                  5.πληρωμες");
	printf("\n\n2. μεταφορα                                   4. καταθεση                                 6.αλλαγη pin");
	
	printf("\n\n        παρακαλω επιλεξτε τι θελετε (1-6) ");
	scanf("%d",&sel);
	
	switch (sel)
	{	
		case 1:
	        printf("\n\n        πληκτρολογηστε τον αριθμο λογαριασμου σας  ");
	        scanf("%d",&num); 
	        s_pin=dek2oct(num);
	        printf("\n\n        δωστε το pin σας   ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        λαθος εισαγωση pin   ");
		        printf("\n\n        σας απομενουν %d προσπαθειες   ",tmes+1);
		
		        printf("\n\n        δωστε το pin σας   ");
		        scanf("%d",&pin);
		   }
		    for (i=0; i<1000; i++)
		    {
		   	    if (log[i]==num)
		   	    {
		   	    	found=i;
		   	    }
		    }
	       if(tmes>=1){
		   printf("\n\n       το υπολοιπο του λογαριασμου ειναι :  %.1f  ",ch[found]);
	     }
		   break;
		case 2: 
	        printf("\n\n        πληκτρολογηστε τον αριθμο λογαριασμου σας  ");
	        scanf("%d",&num); 
	        s_pin=dek2oct(num);
	        printf("\n\n        δωστε το pin σας  ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        λαθος εισαγωγη pin   ");
		        printf("\n\n        σας απομενουν %d προσπαθειες   ",tmes+1);
		
		        printf("\n\n        δωστε το pin σας   ");
		        scanf("%d",&pin);
		   }
		    if(tmes>=1){
		    printf("\n\n       το υπολοιπο του λογαριασμου σου ειναι :  %.1f  ",ch[found]);
	     	printf("\n γραψτε λογαριασμο για μεταφορα :");
	     	scanf("%d", &am);
	     	printf("\n γραψτε ποσο μεταφορας  ");
	     	scanf("%d", &money);
	     	if(money>ch[found]){
	     		printf("\n το υπολοιπο σας δεν επαρκει για την μεταφορα");
				}
			 else if(money<=ch[found]){
		
			 	printf("\n η μεταφορα εγινε ");
			 	ch[found]=(ch[found]-money);
			 	printf("\n νεο υπολοιπο :%.1f", ch[found]);
			 }
			}
			 break;
		case 3:
			printf("\n\n        πληκτρολογηστε τον αριθμο λογαριασμου σας  ");
	        scanf("%d",&num); 
	        s_pin=dek2oct(num);
	        printf("\n\n        δωστε το pin σας   ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        λαθος pin  ");
		        printf("\n\n        σας απομενουν %d προσπαθειες   ",tmes+1);
		
		        printf("\n\n        δωστε το pin σας   ");
		        scanf("%d",&pin);
		   }
		 if(tmes>=1){
		   printf("\n\n       το υπολοιπο του λογαριασμου σας ειναι :  %.1f  ",ch[found]);
	       printf("\n ποιο ειναι το επιθυμιτο ποσο αναληψης ; ");
	       scanf("%d", &money);
	    	if(money<=900){
					
	     	printf("\n παραλαβετε τα χρηματα σας ");
	     	ch[found]= (ch[found] -money);
	     	printf("\n το νεο υπολοιπο ειναι :%.1f", ch[found]);
	     }
	     else if(money>900){
		 printf("\n δεν μπορειτε να παραλαβετε αυτο το ποσο ");}   
		}
	break;
		case 4:
			printf("\n\n     πληκτρολογηστε τον αριθμο λογαριασμου σας   ");
	        scanf("%d",&num);  
	        s_pin=dek2oct(num);
	        printf("\n\n     δωστε το pin σας   ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        λαθος pin   ");
		        printf("\n\n        σας απομενουν %d προσπαθειες   ",tmes+1);
		
		        printf("\n\n        δωστε το pin σας   ");
		        scanf("%d",&pin);
		   }
			if(tmes>=1){
				printf("\n γραψτε ποσο καταθεσης :");
				scanf("%d", &money);
				ch[found]=(ch[found] + money);
				printf(" \n νεο υπολοιπο:%.1f", ch[found]);
			}
		   break;
		   case 5:
		   	FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  pFile = fopen ( "transactions" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}


  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);


  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}


  fclose (pFile);
  free (buffer);
  printf("\nΛυπουμαστε η επιλογη (5)  (ΠΛΗΡΩΜΕΣ)  βρισκεται υπο συντηρηση !! παρακαλω δοκιμαστε αργοτερα!!!");
  break;
		   case 6:
		   	printf("\n γραψτε το νεο πιν σας :");
		   	scanf("d",pin);
		   	break;
		case 101:
				printf("\n\n        γραψε το επωνυμο σου σωστα με λατινικους χαρακτηρες  ");
	        scanf("%s",&username); 
	        s_pin=dek2oct(num);
	        printf("\n\n        δωστε το pin σας   ");
            scanf("%d",&pin);
            printf("\n\n");
	        
	       {
	    	    printf("        υπαρχουν %d χαρτονομισματα των  50\n\n",x_50 );
                printf("        υπαρχουν %d χαρτονομισματα των  20",x_20);



		   }
		   break;
		case 102:
			 printf("\n\n   γραψε το επωνυμο σου σωστα με λατινικους χαρακτηρες    ");
                scanf("%s",&username2);


                printf("\n\n     δωσε το pin σου   ");
                scanf("%d",&pin2);

                x_50=10;
                x_20=20;

                printf("\n\n   ολοκληρωθηκε η τροφοδοσια του ΑΤΜ  ");

                break;
		   break;
		case 103:
			printf("\n\n γραψε το επωνυμο σου σωστα με λατινικους χαρακτηρες  ");
			scanf("%s",&username);
			
			printf("\n\n δωσε το pin σου ");
			scanf("%d",&pin2);
			
			printf("\n\n η επιλογη αυτη θα τερματισει οριστικα το συστημα ");
		    return 0;
			
			break;
			
			  
    }	
    printf("\n\n\nPress Enter to continue...   \n");
    fflush(stdin);
    scanf("%c", &trde);
    if (trde == 'ο'|| trde == 'Ο')
        k = 1;
    }while (!k);
}

    
int dek2oct(int num)
{
    int oct = 0, i = 1;
    int ipol;
    while(num != 0)
    {
        ipol = num % 8;
        num = num / 8;
        oct = oct + (ipol * i);
        i = i * 10;
    }
     return oct;
}
int inform ( int num)
{
 for(i=0; i<1000; i++)
 {
  if(log[i]==num) 
   {
    found=i; 
   }
 }
printf(" \n\n το υπολοιπο του λογαριασμου ειναι: %.1f ", ch[found]);
}
