#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i=0;
int count0=0;
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int max;
int max_aem;
struct record {
 unsigned short aem;
 unsigned char surname[26];
 unsigned char name[24];
 float grade;
};

typedef struct record Record;



float findMaxGrade(Record *records, int size){

  float maxGrade = 0;

  for(i=0 ; i < size; i++){
    if(records[i].grade > maxGrade){
      maxGrade = records[i].grade;
    }
  }

  return maxGrade;
}


int main()
{
    FILE *ptr;
    int numOfRecords = 0;
    int i;

    Record *records = malloc(sizeof(Record));
    int numOfChosenStudents;

    srand(4402);


    if(records == NULL){
      printf("Failed to allocate memory for the records array!");
      exit(1);
    }

    ptr = fopen("InputFile", "rb");

    if(ptr == NULL){
        printf("Failed to open the file!");
        exit(1);
    }


   while(!feof(ptr)){
       Record rec;

       if(numOfRecords > 0){
          records = realloc(records, (numOfRecords+1) * sizeof(Record));

          if (records == NULL){
            printf("Failed to allocate more memory!Exit!");
            exit(1);
          }
       }

       //fread(&rec, sizeof(Record), 1, ptr);
       fread(&rec.aem, sizeof(rec.aem), 1, ptr);
       fread(&rec.surname, sizeof(rec.surname), 1, ptr);
       fread(&rec.name, sizeof(rec.name), 1, ptr);
       rec.grade = -1;
       records[numOfRecords] = rec;
       numOfRecords++;
    }

    fclose(ptr);

    printf("Το συνολικο πληθος εγγραφων των φοιτητων ειναι ισο με : = %d\n\n", numOfRecords);


    for(i=0; i<numOfRecords; i++){
      printf("aem: %d\tsurname: %s\tname: %s\n", records[i].aem, records[i].surname, records[i].name);
    }


    numOfChosenStudents = 0.6 * numOfRecords;

    printf("\nTo 60 τις 100 των φοιτητων που προς ηλθε στις εξετασεις %d\n\n", numOfChosenStudents);


    int random = 0;
    int counter = 0;
    int j = 0;

    while(counter < numOfChosenStudents){

      random = rand() % numOfRecords;
      if(records[random].grade == -1){

        
        records[random].grade = rand() % 10;
        counter++;
      }
      else if(records[random].grade != -1) {
        continue;
      }

    }

    for(i=0; i<numOfRecords; i++){
      if(records[i].grade != -1){
        printf("aem: %d\tsurname: %s\tname: %s\t Grade: %0.1f \n", records[i].aem, records[i].surname, records[i].name, records[i].grade);
      }
    }


    float maxGrade = findMaxGrade(records, numOfRecords);
    printf("Ο μεγαλυτερος βαθμος ηταν :%1.f", maxGrade);
    
    max=records[0].grade;
    max_aem=records[200].aem;
    for (i=1; i<=200;i++)
    {
    if (records[i].grade>=max) max=records[i].grade;
    if (records[i].grade>=max) max_aem=records[i].aem;
    }
    printf("\no μεγαλυτερος βαθμος ανηκει στον μαθητη με αριθμο μητρωου :%d",max_aem);
    
    


    int numOfTopStudents = 0;

    Record *topStudents = malloc(sizeof(Record));

    for(i=0 ; i < numOfRecords; i++){

      if(records[i].grade == maxGrade){

        if(numOfTopStudents > 0){
          topStudents = realloc(topStudents, (numOfTopStudents+1) * sizeof(Record));

          if (topStudents == NULL){
            printf("Failed to allocate more memory!Exit!");
            exit(1);
          }
        }

      topStudents[numOfTopStudents] = records[i];
      numOfTopStudents++;
    }
  }


  // GRAFEI TA DEDOMENA STO ARXEIO.

  FILE *outputFile = fopen("Exam1-4402", "w");
fprintf(outputFile,"OI BATHMOLOGIES TON MATHITON :\n");
fprintf(outputFile,"_____________________________________\n");
  if (!outputFile) {
    printf("Couldn't open output file!\n");
    exit(-1);
  }

  for(i=0; i<numOfRecords; i++){
    if(records[i].grade != -1){
      fprintf(outputFile, "%d, %s, %s, %0.1f\n", records[i].aem, records[i].surname, records[i].name, records[i].grade);
    }
    else{
      fprintf(outputFile, "%d, %s, %s\n", records[i].aem, records[i].surname, records[i].name);
    }
  }
  fprintf(outputFile,"_____________________________________\n");
  fprintf(outputFile, "OI MATHITES ME THN MEGALITERH BATHMOLOGIA:\n");
  fprintf(outputFile,"_____________________________________\n");

  for(i=0; i<numOfTopStudents; i++){
      fprintf(outputFile, "%d, %s, %s, %0.1f\n", topStudents[i].aem, topStudents[i].surname, topStudents[i].name, topStudents[i].grade);
  }
    for (i=0; i<=200;i++)
    {
    	if (records[i].grade>8.5) (count0=count0+1);
    	if (records[i].grade>=6.5 && records[i].grade<8.5) (count1=count1+1);
    	if (records[i].grade>=5.0 && records[i].grade<6.4) (count2=count2+1);
    	if (records[i].grade>=3.0 && records[i].grade<5.0) (count3=count3+1);
    	if (records[i].grade>=0.0 && records[i].grade<3.0) (count4=count4+1);
	}
	fprintf(outputFile,"\n\nH KATANOMH THS BATHMOLOGIAS EINAI :\n");
	fprintf(outputFile,"_____________________________________");
    fprintf(outputFile,"\n8.5-10=%d",count0);
	fprintf(outputFile,"\n6.5-8.4=%d",count1);
	fprintf(outputFile,"\n5-6.4=%d",count2);
	fprintf(outputFile,"\n3-4.9=%d",count3);
	fprintf(outputFile,"\n0-2.9=%d",count4);
  fclose(outputFile);
  
    FILE *outputFilee = fopen("Exam2-4402", "w");

  if (!outputFile) {
    printf("Couldn't open output file!\n");
    exit(-1);
  }
fprintf(outputFile,"AFTOI EINAI OI EN DINAMI EXETAZOMENOI MATHITES GIA TON SEPTEMBRIO :\n");
fprintf(outputFile,"_____________________________________\n");
  for(i=0; i<numOfRecords; i++){
    if(records[i].grade != -1 ){
    	if(records[i].grade < 5){
		
      fprintf(outputFile, "%d, %s, %s, %0.1f\n", records[i].aem, records[i].surname, records[i].name, records[i].grade);
    }
}
    else {
      fprintf(outputFile, "%d, %s, %s\n", records[i].aem, records[i].surname, records[i].name);
    }
   
  }


  

  fclose(outputFilee);





  free(records);
  free(topStudents);

  return 0;
}
