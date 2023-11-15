#include <stdio.h>
#include <stdlib.h>

// Define the structure for student details
struct Student {
    char firstName[50];
    char lastName[50];
    int regNumber;
    char course[50];
    float scores;
    char grade;
};

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for an array of students
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input student details
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("First Name: ");
        scanf("%s", students[i].firstName);
        printf("Last Name: ");
        scanf("%s", students[i].lastName);
        printf("Registration Number: ");
        scanf("%d", &students[i].regNumber);
        printf("Course: ");
        scanf("%s", students[i].course);
        printf("Scores: ");
        scanf("%f", &students[i].scores);

        // Calculate the grade based on scores (you can customize the grading criteria)
        if (students[i].scores >= 90) {
            students[i].grade = 'A';
        } else if (students[i].scores >= 80) {
            students[i].grade = 'B';
        } else if (students[i].scores >= 70) {
            students[i].grade = 'C';
        } else if (students[i].scores >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }

    // Display student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("First Name: %s\n", students[i].firstName);
        printf("Last Name: %s\n", students[i].lastName);
        printf("Registration Number: %d\n", students[i].regNumber);
        printf("Course: %s\n", students[i].course);
        printf("Scores: %.2f\n", students[i].scores);
        printf("Grade: %c\n", students[i].grade);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}