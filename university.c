#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENTS 200
#define MIN_YEAR 2002
#define MAX_YEAR 2005
int i=0,j=0;

struct DATE {
  unsigned int day;
  unsigned int month;
  unsigned int year;
};

struct STUDENT {
  unsigned int StudentID;
  struct DATE dob;
  float grade;
};

int main(void) {
  // Seed the random number generator
  srand(4402);

  // Create an array of STUDENT structures
  struct STUDENT students[NUM_STUDENTS];

  // Initialize the student data
  for ( i = 0; i < NUM_STUDENTS; i++) {
    students[i].StudentID = 4500 + i;
    students[i].dob.day = rand() % 30 + 1;
    students[i].dob.month = rand() % 12 + 1;
    students[i].dob.year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
    students[i].grade = (float)(rand() % 101) / 10.0f;
  }

  // Group the students by birthday
  printf("Students with same birthday:\n");
  for ( i = 0; i < NUM_STUDENTS; i++) {
    for ( j = i + 1; j < NUM_STUDENTS; j++) {
      if (students[i].dob.day == students[j].dob.day && students[i].dob.month == students[j].dob.month) {
        printf("%d %02d/%02d/%04d %.1f\n", students[i].StudentID, students[i].dob.day, students[i].dob.month, students[i].dob.year, students[i].grade);
        printf("%d %02d/%02d/%04d %.1f\n", students[j].StudentID, students[j].dob.day, students[j].dob.month, students[j].dob.year, students[j].grade);
      }
    }
  }

  // Calculate the score distribution
  int score_distribution[10] = {0};
  for ( i = 0; i < NUM_STUDENTS; i++) {
    int score = (int)students[i].grade;
    score_distribution[score]++;
  }

  // Print the score distribution
  printf("\nScore distribution:\n");
  for ( i = 0; i < 10; i++) {
    printf("%.1f-%.1f: %d\n", (float)i, (float)(i + 1), score_distribution[i]);
  }

  // Calculate the average grade
  float total_grade = 0.0f;
  int TotalGradeID;
  for ( i = 0; i < NUM_STUDENTS; i++) {
    total_grade += students[i].grade;
    TotalGradeID+= students[i].StudentID;
    
  }
  float average_grade = total_grade / NUM_STUDENTS;
  
  //Print the average grade
  printf("\nThe average grade is : %.1f\n",average_grade);


    // Find the student with the highest score
  int highest_score_index = 0;
  float highest_score = students[0].grade;
  for ( i = 1; i < NUM_STUDENTS; i++) {
    if (students[i].grade > highest_score) {
      highest_score = students[i].grade;
      highest_score_index = i;
    }
  }

  // Print the student with the highest grade
  printf("\nStudent with highest grade is :");
  printf("%d %02d/%02d/%04d %.1f\n", students[highest_score_index].StudentID, students[highest_score_index].dob.day, students[highest_score_index].dob.month, students[highest_score_index].dob.year, students[highest_score_index].grade);
  
  
  return 0 ;
}

