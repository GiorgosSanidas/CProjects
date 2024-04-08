#include <stdio.h>
main()
{
	int StudID,TotalGrade;
	float GradeLang,GradeMath,GradeEcon,GradeInfo;
	printf("Δώσε αριθμό μητρώου:\t");
	scanf("%d",&StudID);
	printf("Δώσε βαθμολογία Νεοελληνικής γλώσσας:\t");
	scanf("%f",&GradeLang);
	printf("Δώσε βαθμολογία μαθηματικών:\t");
	scanf("%f",&GradeMath);
	printf("Δώσε βαθμολογία ΑΟΘ:\t");
	scanf("%f",&GradeEcon);
	printf("Δώσε βαθμολογία ανάπτυξης εφαρμογών πληροφορικής:\t");
	scanf("%f",&GradeInfo);
	TotalGrade=GradeLang*200+GradeMath*330+GradeEcon*200+GradeInfo*270;
	int Base1, Base2, Base3, Base4,Base5;
	Base1=3*1654+StudID;
	Base2=3*1630+StudID;
	Base3=3*1603+StudID;
	Base4=3*1554+StudID;
	Base5=3*1548+StudID;
	printf("ο μαθητής με αριθμό μητρώου %d",StudID);
	printf(" πέτυχε %d",TotalGrade);
	printf(" μόρια,με βάση τα οποία μπορεί να εισαχθεί στο τμήμα :\n");
	if (TotalGrade>=Base1)  printf("με κωδικό : 1654 που έχει βάση εισαγωγής :%d\n",Base1);
	if (TotalGrade>=Base2)  printf("με κωδικό : 1630 που έχει βάση εισαγωγής :%d\n",Base2);
	if (TotalGrade>=Base3)  printf("με κωδικό : 1603 που έχει βάση εισαγωγής :%d\n",Base3);
	if (TotalGrade>=Base4)  printf("με κωδικό : 1554 που έχει βάση εισαγωγής :%d\n",Base4);
	if (TotalGrade>=Base5)  printf("με κωδικό : 1548 που έχει βάση εισαγωγής :%d\n",Base5);
	if (TotalGrade<Base1&&TotalGrade<Base2&&TotalGrade<Base3&&TotalGrade<Base4&&TotalGrade<Base5) printf("Δεν εισάγεται σε κανένα απο τα 5 τμήματα");
}
