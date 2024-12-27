#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 5 // Maximum number of subjects

// Define the structure for student data
struct Student {
    int roll_no;
    char name[50];
    char grades[MAX_SUBJECTS]; // Array to store grades for each subject
    int credits[MAX_SUBJECTS]; // Array to store credits for each subject
    float cgpa; // CGPA of the student
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count, int roll_no);
int findStudentIndex(struct Student students[], int count, int roll_no);
void calculateCGPA(struct Student *student);

int main() {
    struct Student students[100]; // Array to store students (maximum 100)
    int count = 0; // Current number of students
    int choice, roll_no;

    while(1) {
        // Display menu
        printf("\nStudent Management System with CGPA and Grades (A-F)\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter roll number of the student to delete: ");
                scanf("%d", &roll_no);
                deleteStudent(students, &count, roll_no);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function to add a student
void addStudent(struct Student students[], int *count) {
    struct Student new_student;
    
    printf("Enter roll number: ");
    scanf("%d", &new_student.roll_no);
    printf("Enter name: ");
    getchar(); // To consume the newline character from previous input
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0; // Remove newline character

    // Get grades for each subject and calculate credits
    for(int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter grade for subject %d (A, B, C, D, E, or F): ", i + 1);
        scanf(" %c", &new_student.grades[i]); // Space before %c to skip previous newline
        
        // Determine credits based on grade
        if(new_student.grades[i] == 'A' || new_student.grades[i] == 'B' || new_student.grades[i] == 'C' || new_student.grades[i] == 'D' || new_student.grades[i] == 'E') {
            new_student.credits[i] = 3;  // Passing grade
        } else if(new_student.grades[i] == 'F') {
            new_student.credits[i] = 0;  // Failing grade
        } else {
            printf("Invalid grade entered. Defaulting credits to 0.\n");
            new_student.credits[i] = 0;
        }
    }

    // Calculate CGPA
    calculateCGPA(&new_student);

    // Add the student to the array
    students[*count] = new_student;
    (*count)++; // Increment student count
    printf("Student added successfully!\n");
}

// Function to calculate CGPA
void calculateCGPA(struct Student *student) {
    int total_grade_points = 0;
    int total_credits = 0;

    for(int i = 0; i < MAX_SUBJECTS; i++) {
        // Assign grade points based on grade
        int grade_points = 0;
        if(student->grades[i] == 'A') {
            grade_points = 10;
        } else if(student->grades[i] == 'B') {
            grade_points = 9;
        } else if(student->grades[i] == 'C') {
            grade_points = 8;
        } else if(student->grades[i] == 'D') {
            grade_points = 7;
        } else if(student->grades[i] == 'E') {
            grade_points = 6;
        } else if(student->grades[i] == 'F') {
            grade_points = 0;
        }

        // Calculate total grade points
        total_grade_points += grade_points * student->credits[i];
        // Add to total credits
        total_credits += student->credits[i];
    }

    // Calculate CGPA: (Total Grade Points / Total Credits)
    if(total_credits > 0) {
        student->cgpa = (float)total_grade_points / total_credits;
    } else {
        student->cgpa = 0.0; // Default CGPA if there are no valid credits
    }

    // Ensure CGPA is within the range 1.0 to 10.0
    if(student->cgpa < 1.0) {
        student->cgpa = 1.0;
    } else if(student->cgpa > 10.0) {
        student->cgpa = 10.0;
    }
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
    if(count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    for(int i = 0; i < count; i++) {
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Grades and Credits:\n");
        for(int j = 0; j < MAX_SUBJECTS; j++) {
            printf("  Subject %d: Grade: %c | Credits: %d\n", j + 1, students[i].grades[j], students[i].credits[j]);
        }
        printf("CGPA: %.2f\n", students[i].cgpa);
        printf("-------------------------\n");
    }
}

// Function to delete a student by roll number
void deleteStudent(struct Student students[], int *count, int roll_no) {
    int index = findStudentIndex(students, *count, roll_no);
    
    if(index == -1) {
        printf("Student with roll number %d not found.\n", roll_no);
        return;
    }

    // Shift all students after the deleted one to the left
    for(int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--; // Decrease the student count
    printf("Student with roll number %d deleted successfully!\n", roll_no);
}

// Function to find a student index by roll number
int findStudentIndex(struct Student students[], int count, int roll_no) {
    for(int i = 0; i < count; i++) {
        if(students[i].roll_no == roll_no) {
            return i; // Student found
        }
    }
    return -1; // Student not found
}
