#include <stdio.h>
main()
{
	int StudID,TotalGrade;
	float GradeLang,GradeMath,GradeEcon,GradeInfo;
	printf("���� ������ �������:\t");
	scanf("%d",&StudID);
	printf("���� ���������� ������������ �������:\t");
	scanf("%f",&GradeLang);
	printf("���� ���������� �����������:\t");
	scanf("%f",&GradeMath);
	printf("���� ���������� ���:\t");
	scanf("%f",&GradeEcon);
	printf("���� ���������� ��������� ��������� ������������:\t");
	scanf("%f",&GradeInfo);
	TotalGrade=GradeLang*200+GradeMath*330+GradeEcon*200+GradeInfo*270;
	int Base1, Base2, Base3, Base4,Base5;
	Base1=3*1654+StudID;
	Base2=3*1630+StudID;
	Base3=3*1603+StudID;
	Base4=3*1554+StudID;
	Base5=3*1548+StudID;
	printf("� ������� �� ������ ������� %d",StudID);
	printf(" ������ %d",TotalGrade);
	printf(" �����,�� ���� �� ����� ������ �� �������� ��� ����� :\n");
	if (TotalGrade>=Base1)  printf("�� ������ : 1654 ��� ���� ���� ��������� :%d\n",Base1);
	if (TotalGrade>=Base2)  printf("�� ������ : 1630 ��� ���� ���� ��������� :%d\n",Base2);
	if (TotalGrade>=Base3)  printf("�� ������ : 1603 ��� ���� ���� ��������� :%d\n",Base3);
	if (TotalGrade>=Base4)  printf("�� ������ : 1554 ��� ���� ���� ��������� :%d\n",Base4);
	if (TotalGrade>=Base5)  printf("�� ������ : 1548 ��� ���� ���� ��������� :%d\n",Base5);
	if (TotalGrade<Base1&&TotalGrade<Base2&&TotalGrade<Base3&&TotalGrade<Base4&&TotalGrade<Base5) printf("��� ��������� �� ������ ��� �� 5 �������");
}
