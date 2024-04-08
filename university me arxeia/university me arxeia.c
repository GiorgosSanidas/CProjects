#include <stdio.h>
#include <stdlib.h>

#define PASSING_GRADE 5.0
#define ABSENT_GRADE 11.0

struct DATE {
    unsigned int Day;
    unsigned int Month;
    unsigned int Year;
};

struct STUDENT {
    unsigned int StudentID;
    struct DATE DateOfBirth;
    float Grade;
};

int main() {
    srand(4402);

    FILE *fp = fopen("StudentList", "rb+"); // open file in read/write mode
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // initialize counters for statistics
    int total_students ;
    int graded_students ;
    int passing_students ;
    int failing_students  ;
    int absent_students ;
    int absent_2002 ;
    int absent_2003 ;
    int absent_2004 ;
    int absent_2005 ;
    float total_grade = 0;

    struct STUDENT student;
    while (fread(&student, sizeof(struct STUDENT), 1, fp) == 1) {
        total_students++;
        if (student.Grade != ABSENT_GRADE) {
            graded_students++;
            total_grade += student.Grade;
            if (student.Grade >= PASSING_GRADE) {
                passing_students++;
            } else {
                failing_students++;
            }
        } else {
            absent_students++;
            if (student.DateOfBirth.Year == 2002) {
                absent_2002++;
            } else if (student.DateOfBirth.Year == 2003) {
                absent_2003++;
            } else if (student.DateOfBirth.Year == 2004) {
                absent_2004++;
            } else if (student.DateOfBirth.Year == 2005) {
                absent_2005++;
            }
        }

        // update student's grade for second exam period
        if (student.Grade < PASSING_GRADE || student.Grade == ABSENT_GRADE) {
            int chance = rand() % 100;
            if (student.DateOfBirth.Year == 2005 && chance < 80) {
                student.Grade = (rand() % 50) + PASSING_GRADE;
            } else if (student.DateOfBirth.Year == 2004 && chance < 70) {
                student.Grade = (rand() % 50) + PASSING_GRADE;
            } else if (student.DateOfBirth.Year == 2003 && chance < 50) {
                student.Grade = (rand() % 50) + PASSING_GRADE;
            } else if (student.DateOfBirth.Year <= 2002 && chance < 30) {
                student.Grade = (rand() % 50) + PASSING_GRADE;
            } else {
                student.Grade = ABSENT_GRADE;
            }
        //    fseek(fp, -1 * sizeof(struct STUDENT), SEEK_CUR);
            fwrite(&student, sizeof(struct STUDENT), 1, fp);
        }
    }

    // reset counters for second exam period statistics
    total_students = 0;
	graded_students = 0;
	passing_students = 0;
	failing_students = 0;
	absent_students = 0;
	total_grade = 0;
	float highest_grade = 0;
	struct STUDENT highest_student;
	
	rewind(fp); // move file pointer back to beginning of file
	while (fread(&student, sizeof(struct STUDENT), 1, fp) == 1) {
    	total_students++;
    	if (student.Grade != ABSENT_GRADE) {
        	graded_students++;
        	total_grade += student.Grade;
        	if (student.Grade >= PASSING_GRADE) {
            	passing_students++;
        } 	else {
            	failing_students++;
        }
        	if (student.Grade > highest_grade) {
            	highest_grade = student.Grade;
            	highest_student = student;
        	}
    } 	else {
        	absent_students++;
    }
}

// display second exam period statistics
	printf("Number of students who appeared for the second period exam: %d\n", graded_students);
	printf("Average score for the second period exam: %f\n", total_grade / graded_students);
	printf("Number of students who passed the second period exam: %d\n", passing_students);
	printf("Number of students who failed the second period exam: %d\n", failing_students);
	printf("Number of students who were absent for the second period exam: %d\n", absent_students);
	printf("Number of students who were absent for both periods (by year of birth):\n");
	printf("2002: %d\n", absent_2002);
	printf("2003: %d\n", absent_2003);
	printf("2004: %d\n", absent_2004);
	printf("2005: %d\n", absent_2005);
	printf("Student with highest grade: ID %d, DOB %d/%d/%d, Grade %f\n", highest_student.StudentID, highest_student.DateOfBirth.Day, highest_student.DateOfBirth.Month, highest_student.DateOfBirth.Year, highest_student.Grade);

	fclose(fp);
return 0;
}


