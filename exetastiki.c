#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int i,v,aem[200],max_aem,count0,count1,count2,count3,count4,count5,count6,count7,count8,count9,count10;
float sum=0.0,Grades[200],average,max;
int main()
{
	for (i=0; i<=200;i++)
	{ aem[i]=i+4000;
	}
    for (i=0; i<=199;i++)
	{
		Grades[i]=rand()%100;
		Grades[i]=Grades[i]/10;
		printf(" \t%d : %.1f",aem[i],Grades[i]);
		sum=sum+Grades[i];
	}
	printf("\n_____________________________________");
	for (i=0; i<=200;i++)
	{
	    sum=sum+Grades[i];
	}
    average=sum/200;
    printf("\no μεσος ορος της βαθμολογιας των 200 φοιτητων ειναι : %f",average);
    max=Grades[0];
    max_aem=aem[200];
    for (i=1; i<=200;i++)
    {
    if (Grades[i]>=max) max=Grades[i];
    if (Grades[i]>=max) max_aem=aem[i];
    }
    printf("\no μεγιστος βαθμος ανηκει στον μαθητη με αριθμο μητρωου :%d",max_aem);
    printf("\ και ειναι :%.1f",max);
    for (i=0; i<=200;i++)
    {
    	if (Grades[i]<1) (count0=count0+1);
    	if (Grades[i]<2 && Grades[i]>0.9)  (count1=count1+1);
    	if (Grades[i]<3 && Grades[i]>1.9) (count2=count2+1);
    	if (Grades[i]<4 && Grades[i]>2.9) (count3=count3+1);
    	if (Grades[i]<5 && Grades[i]>3.9) (count4=count4+1);
    	if (Grades[i]<6 && Grades[i]>4.9) (count5=count5+1);
    	if (Grades[i]<7 && Grades[i]>5.9) (count6=count6+1);
    	if (Grades[i]<8 && Grades[i]>6.9) (count7=count7+1);
    	if (Grades[i]<9 && Grades[i]>7.9) (count8=count8+1);
    	if (Grades[i]<10 && Grades[i]>8.9) (count9=count9+1);
    	if (Grades[i]<11 && Grades[i]>9.9) (count10=count10+1);
	}
	printf("\nη κατανομη την βαθμολογιας ειναι :\n");
	printf("_____________________________________");
	printf("\n0-0.9=%d",count0);
	printf("\n1-1.9=%d",count1);
	printf("\n2-2.9=%d",count2);
	printf("\n3-3.9=%d",count3);
	printf("\n4-4.9=%d",count4);
	printf("\n5-5.9=%d",count5);
	printf("\n6-6.9=%d",count6);
	printf("\n7-7.9=%d",count7);
	printf("\n8-8.9=%d",count8);
	printf("\n9-9.9=%d",count9);
	printf("\n10=%d\t",count10);
	printf("\n\nστο μοντελο που προσεγγιζει την πραγματικοτητα\n_____________________________________\n");
	
	
	float rand_double()
	{
		return((float)rand())/((float)RAND_MAX);
	}
    float rand_double_interval(float a,float b)
    {
    	return rand_double()*(b-a)+a;
	}
srand(4445);
int ari=3999,j,o[201];

for (j=0; j<201;j++)
{
	o[j]=ari+1;
	ari=ari+1;
}
float bathm[201];
int per=200*60/100,z,temp,pros;
for(j=0; j<200;j++)
{
	z=(rand()%199)+1;
	pros=o[j];
	o[j]=o[z];
	o[z]=pros;
	temp=aem[j];
	aem[j]=aem[z];
	aem[z]=temp;
}
sum=0;
count0=0;
count1=0;
count2=0;
count3=0;
count4=0;
count5=0;
count6=0;
count7=0;
count8=0;
count9=0;
count10=0;
int per2=(per*5)/100;
for(i=0;i<=per2;i++)
{
	bathm[i]=rand_double_interval(8.5,10.0);
}
int i1,per3=(per*15)/100;
for(i1=0; i1<=per3;i1++)
{
	bathm[per2+1+i1]=rand_double_interval(6.5,8.4);
}
int i4,per4=(per*20)/100;

for(i4=0; i4<=per4;i4++)
{
	bathm[per3+1+i4]=rand_double_interval(5.0,6.4);
}
int i2,per5=(per*30)/100;
for(i2=0; i2<=per5;i2++)
{
	bathm[per4+1+i2]=rand_double_interval(3.0,5.0);
}
int i3,per6=per5*2;
for(i3=0; i3<=per6;i3++)
{
	bathm[per5+1+i3]=rand_double_interval(0,2.9);
}
for (i=0; i<=120;i++)
	{
	
		printf(" \t%d : %.1f",aem[i],bathm[i]);
		sum=sum+bathm[i];
	}
	printf("\n_____________________________________");
	printf("\nοι φοιτητες που δεν προσηλθαν στις εξετασεις ειναι οι εξης :");
	printf("\n");
	int k;
		for(k=121; k<201;k++)
	    {
	    	printf("%d,",o[k]);
		}
		printf("\n__________________________________");
	max=0;
	    average=sum/per;
    printf("\no μεσος ορος της βαθμολογιας των  φοιτητων ειναι : %f",average);
    max=bathm[0];
    max_aem=aem[120];
    for (i=1; i<=120;i++)
    {
    if (bathm[i]>=max) max=bathm[i];
    if (bathm[i]>=max) max_aem=aem[i];
    }
    printf("\no μεγιστος βαθμος ανηκει στον μαθητη με αριθμο μητρωου :%d",max_aem);
    printf("\ και ειναι :%.1f",max);
    for (i=0; i<=120;i++)
    {
    	if (bathm[i]>8.5) (count0=count0+1);
    	if (bathm[i]>=6.5 && bathm[i]<8.5) (count1=count1+1);
    	if (bathm[i]>=5.0 && bathm[i]<6.4) (count2=count2+1);
    	if (bathm[i]>=3.0 && bathm[i]<5.0) (count3=count3+1);
    	if (bathm[i]>=0.0 && bathm[i]<3.0) (count4=count4+1);
	}
	printf("\nη κατανομη την βαθμολογιας ειναι :\n");
	printf("_____________________________________");
printf("\n8.5-10=%d",count0);
	printf("\n6.5-8.4=%d",count1);
	printf("\n5-6.4=%d",count2);
	printf("\n3-4.9=%d",count3);
	printf("\n0-2.9=%d",count4);



}























