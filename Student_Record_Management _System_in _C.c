#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for student record
struct Student {
    char name[50];
    int rollNo;
    float marks[3];
    float average;
    char grade;
};

void addRecord();
void displayRecords();
void searchRecord();
char calculateGrade(float avg);

int main() {
    int choice;
    while (1) {
        printf("\n===== STUDENT REPORT CARD SYSTEM =====\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to calculate grade based on average marks
char calculateGrade(float avg) {
    if (avg >= 90)
        return 'A';
    else if (avg >= 75)
        return 'B';
    else if (avg >= 60)
        return 'C';
    else if (avg >= 45)
        return 'D';
    else
        return 'F';
}

// Function to add a new student record
void addRecord() {
    FILE *fp;
    struct Student s;
    float total = 0;

    fp = fopen("students.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Name: ");
    getchar(); // clear newline from buffer
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove trailing newline

    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);

    printf("Enter Marks in 3 Subjects: ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &s.marks[i]);
        total += s.marks[i];
    }

    s.average = total / 3.0;
    s.grade = calculateGrade(s.average);

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("Record added successfully!\n");
}

// Function to display all student records
void displayRecords() {
    FILE *fp;
    struct Student s;
    fp = fopen("students.dat", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "Roll No", "Name", "Average", "Grade");
    printf("-----------------------------------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("%-10d %-20s %-10.2f %-10c\n", s.rollNo, s.name, s.average, s.grade);
    }

    fclose(fp);
}

// Function to search for a student record by roll number
void searchRecord() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.rollNo == roll) {
            printf("\nRecord Found:\n");
            printf("Name: %s\n", s.name);
            printf("Roll No: %d\n", s.rollNo);
            printf("Marks: %.2f, %.2f, %.2f\n", s.marks[0], s.marks[1], s.marks[2]);
            printf("Average: %.2f\n", s.average);
            printf("Grade: %c\n", s.grade);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No record found for Roll No: %d\n", roll);

    fclose(fp);
}
