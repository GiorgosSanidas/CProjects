#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,sel,log[1000],ar,s_pin,pin,found,am,pin2,money,x_50=10,x_20=20,mik=1000,meg=50000;
float ch[1000]; 
char username,username2;
int dek2oct(int num);




int main()
{
	
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
	
	
	printf("\n\n      ����������� ��� �������� ������������   ");
	printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	printf("\n\n1. ���������                                  3. �������");
	printf("\n\n2. ��������                                   4. ��������");
	
	printf("\n\n        �������� �������� �� ������ (1-4) ");
	scanf("%d",&sel);
	
	switch (sel)
	{	
		case 1:
	        printf("\n\n        �������������� ��� ������ ����������� ���  ");
	        scanf("%d",&num); 
	        s_pin=dek2oct(num);
	        printf("\n\n        ����� �� pin ���   ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        ����� �������� pin   ");
		        printf("\n\n        ��� ��������� %d �����������   ",tmes+1);
		
		        printf("\n\n        ����� �� pin ���   ");
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
		   printf("\n\n       �� �������� ��� ����������� ����� :  %.1f  ",ch[found]);
	     }
		   break;
		case 2: 
	        printf("\n\n        �������������� ��� ������ ����������� ���  ");
	        scanf("%d",&num); 
	        s_pin=dek2oct(num);
	        printf("\n\n        ����� �� pin ���  ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        ����� �������� pin   ");
		        printf("\n\n        ��� ��������� %d �����������   ",tmes+1);
		
		        printf("\n\n        ����� �� pin ���   ");
		        scanf("%d",&pin);
		   }
		    if(tmes>=1){
		    printf("\n\n       �� �������� ��� ����������� ��� ����� :  %.1f  ",ch[found]);
	     	printf("\n ������ ���������� ��� �������� :");
	     	scanf("%d", &am);
	     	printf("\n ������ ���� ���������  ");
	     	scanf("%d", &money);
	     	if(money>ch[found]){
	     		printf("\n �� �������� ��� ��� ������� ��� ��� ��������");
				}
			 else if(money<=ch[found]){
		
			 	printf("\n � �������� ����� ");
			 	ch[found]=(ch[found]-money);
			 	printf("\n ��� �������� :%.1f", ch[found]);
			 }
			}
			 break;
		case 3:
			printf("\n\n        �������������� ��� ������ ����������� ���  ");
	        scanf("%d",&num); 
	        s_pin=dek2oct(num);
	        printf("\n\n        ����� �� pin ���   ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        ����� pin  ");
		        printf("\n\n        ��� ��������� %d �����������   ",tmes+1);
		
		        printf("\n\n        ����� �� pin ���   ");
		        scanf("%d",&pin);
		   }
		 if(tmes>=1){
		   printf("\n\n       �� �������� ��� ����������� ��� ����� :  %.1f  ",ch[found]);
	       printf("\n ���� ����� �� ��������� ���� �������� ; ");
	       scanf("%d", &money);
	    	if(money<=900){
					
	     	printf("\n ���������� �� ������� ��� ");
	     	ch[found]= (ch[found] -money);
	     	printf("\n �� ��� �������� ����� :%.1f", ch[found]);
	     }
	     else if(money>900){
		 printf("\n ��� �������� �� ���������� ���� �� ���� ");}   
		}
	break;
		case 4:
			printf("\n\n     �������������� ��� ������ ����������� ���   ");
	        scanf("%d",&num);  
	        s_pin=dek2oct(num);
	        printf("\n\n     ����� �� pin ���   ");
            scanf("%d",&pin);
	        while (pin!=s_pin && tmes>=1)
	       {
	    	    tmes=tmes-1;
		        printf("\n\n        ����� pin   ");
		        printf("\n\n        ��� ��������� %d �����������   ",tmes+1);
		
		        printf("\n\n        ����� �� pin ���   ");
		        scanf("%d",&pin);
		   }
			if(tmes>=1){
				printf("\n ������ ���� ��������� :");
				scanf("%d", &money);
				ch[found]=(ch[found] + money);
				printf(" \n ��� ��������:%.1f", ch[found]);
			}
		   break;
		case 101:
				printf("\n\n        ����� �� ������� ��� ����� �� ���������� ����������  ");
	        scanf("%s",&username); 
	        s_pin=dek2oct(num);
	        printf("\n\n        ����� �� pin ���   ");
            scanf("%d",&pin);
            printf("\n\n");
	        
	       {
	    	    printf("        �������� %d �������������� ���  50\n\n",x_50 );
                printf("        �������� %d �������������� ���  20",x_20);



		   }
		   break;
		case 102:
			 printf("\n\n   ����� �� ������� ��� ����� �� ���������� ����������    ");
                scanf("%s",&username2);


                printf("\n\n     ���� �� pin ���   ");
                scanf("%d",&pin2);

                x_50=10;
                x_20=20;

                printf("\n\n   ������������ � ���������� ��� ���  ");

                break;
		   break;
		case 103:
			printf("\n\n ����� �� ������� ��� ����� �� ���������� ����������  ");
			scanf("%s",&username);
			
			printf("\n\n ���� �� pin ��� ");
			scanf("%d",&pin2);
			
			printf("\n\n � ������� ���� �� ���������� �������� �� ������� ");
		    return 0;
			
			break;
			
			  
    }	
    printf("\n\n\nPress Enter to continue...   \n");
    fflush(stdin);
    scanf("%c", &trde);
    if (trde == '�'|| trde == '�')
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
printf(" \n\n �� �������� ��� ����������� �����: %.1f ", ch[found]);
}
