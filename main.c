#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student {
    int id;
    char name[50];
    char GPA[3];
};

struct Teacher {
    int id;
    char name[50];
    char subject[50];
};

void adminSignup();
void adminLogin();
void exitProgram();
void addStudent();
void updateStudentInfo();
void removeStudent();
void displayStudents();
void addTeacher();
void updateTeacherInfo();
void removeTeacher();
void calculateAverageGPA();

int main() {
    int choice;
    do {
        printf("\n1. Admin Signup\n");
        printf("2. Admin Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminSignup();
                break;
            case 2:
                adminLogin();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

void adminSignup() {
    char username[50];
    char password[50];
    int valid;

    do {
        valid = 1;
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        for (int i = 0; username[i] != '\0'; i++) {
            if (!isalpha(username[i])) {
                valid = 0;
                printf("Invalid username! Please enter alphabetic characters only.\n");
                break;
            }
        }

        for (int i = 0; password[i] != '\0'; i++) {
            if (!isalpha(password[i])) {
                valid = 0;
                printf("Invalid password! Please enter alphabetic characters only.\n");
                break;
            }
        }

        if (valid) {
            FILE *fp = fopen("admin.txt", "w");
            fprintf(fp, "%s %s", username, password);
            fclose(fp);
            printf("Admin account created successfully!\n");
        }
    } while (!valid);
}

void adminLogin() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("admin.txt", "r");
    char storedUsername[50];
    char storedPassword[50];
    fscanf(fp, "%s %s", storedUsername, storedPassword);
    fclose(fp);

    if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
        printf("Admin login successful!\n");
        int adminChoice;
        do {
            printf("\n--------------------------------------\n");
            printf("1. Add Student\n");
            printf("2. Update Student Information\n");
            printf("3. Remove Student\n");
            printf("4. Display Students\n");
            printf("5. Add Teacher\n");
            printf("6. Update Teacher Information\n");
            printf("7. Remove Teacher\n");
            printf("8. Calculate Average GPA\n");
            printf("9. Exit\n");
            printf("--------------------------------------\n");
            printf("Enter your choice: ");
            scanf("%d", &adminChoice);

            switch (adminChoice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    updateStudentInfo();
                    break;
                case 3:
                    removeStudent();
                    break;
                case 4:
                    displayStudents();
                    break;
                case 5:
                    addTeacher();
                    break;
                case 6:
                    updateTeacherInfo();
                    break;
                case 7:
                    removeTeacher();
                    break;
                case 8:
                    calculateAverageGPA();
                    break;
                case 9:
                    exitProgram();
                    break;
                default:
                    printf("Invalid choice! Please enter a valid option.\n");
            }
        } while (adminChoice != 9);
    } else {
        printf("Invalid username or password! Please try again.\n");
    }
}

void exitProgram() {
    printf("Exiting program...\n");
    exit(0);
}

void addStudent() {
    struct Student newStudent;
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student GPA: ");
    scanf("%s", newStudent.GPA);

    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%d %s %s\n", newStudent.id, newStudent.name, newStudent.GPA);
    fclose(fp);
    printf("Student added successfully!\n");
}

void updateStudentInfo() {
    int id;
    printf("Enter the ID of the student whose information you want to update: ");
    scanf("%d", &id);

    FILE *fp = fopen("students.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (fp == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student student;
    int found = 0;
    while (fscanf(fp, "%d %s %s", &student.id, student.name, student.GPA) != EOF) {
        if (student.id == id) {
            found = 1;
            printf("Enter updated student name: ");
            scanf("%s", student.name);
            printf("Enter updated student GPA: ");
            scanf("%s", student.GPA);
        }
        fprintf(tempFile, "%d %s %s\n", student.id, student.name, student.GPA);
    }

    fclose(fp);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student information updated successfully!\n");
    else
        printf("Student with ID %d not found!\n", id);
}

void removeStudent() {
    int id;
    printf("Enter the ID of the student you want to remove: ");
    scanf("%d", &id);

    FILE *fp = fopen("students.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (fp == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student student;
    int found = 0;
    while (fscanf(fp, "%d %s %s", &student.id, student.name, student.GPA) != EOF) {
        if (student.id == id) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d %s %s\n", student.id, student.name , student.GPA);
    }

    fclose(fp);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student removed successfully!\n");
    else
        printf("Student with ID %d not found!\n", id);
}

void displayStudents() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Student student;
    printf("ID\tName\tGPA\n");
    while (fscanf(fp, "%d %s %s", &student.id, student.name, student.GPA) != EOF) {
        printf("%d\t%s\t%s\n", student.id, student.name, student.GPA);
    }

    fclose(fp);
}

void addTeacher() {
    struct Teacher newTeacher;
    printf("Enter teacher name: ");
    scanf("%s", newTeacher.name);
    printf("Enter teacher ID: ");
    scanf("%d", &newTeacher.id);
    printf("Enter subject taught by the teacher: ");
    scanf("%s", newTeacher.subject);

    FILE *fp = fopen("teachers.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%d %s %s\n", newTeacher.id, newTeacher.name, newTeacher.subject);
    fclose(fp);
    printf("Teacher added successfully!\n");
}

void updateTeacherInfo() {
    int id;
    printf("Enter the ID of the teacher whose information you want to update: ");
    scanf("%d", &id);

    FILE *fp = fopen("teachers.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (fp == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Teacher teacher;
    int found = 0;
    while (fscanf(fp, "%d %s %s", &teacher.id, teacher.name, teacher.subject) != EOF) {
        if (teacher.id == id) {
            found = 1;
            printf("Enter updated teacher name: ");
            scanf("%s", teacher.name);
            printf("Enter updated subject taught by the teacher: ");
            scanf("%s", teacher.subject);
        }
        fprintf(tempFile, "%d %s %s\n", teacher.id, teacher.name, teacher.subject);
    }

    fclose(fp);
    fclose(tempFile);

    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");

    if (found)
        printf("Teacher information updated successfully!\n");
    else
        printf("Teacher with ID %d not found!\n", id);
}

void removeTeacher() {
    int id;
    printf("Enter the ID of the teacher you want to remove: ");
    scanf("%d", &id);

    FILE *fp = fopen("teachers.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (fp == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Teacher teacher;
    int found = 0;
    while (fscanf(fp, "%d %s %s", &teacher.id, teacher.name, teacher.subject) != EOF) {
        if (teacher.id == id) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d %s %s\n", teacher.id, teacher.name , teacher.subject);
    }

    fclose(fp);
    fclose(tempFile);

    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");

    if (found)
        printf("Teacher removed successfully!\n");
    else
        printf("Teacher with ID %d not found!\n", id);
}

void calculateAverageGPA() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int totalStudents = 0;
    float totalGPA = 0.0;
    float studentGPA;

    while (fscanf(fp, "%*d %*s %f", &studentGPA) == 1) {
        totalStudents++;
        totalGPA += studentGPA;
    }

    fclose(fp);

    if (totalStudents == 0) {
        printf("No students found.\n");
        return;
    }

    float averageGPA = totalGPA / totalStudents;
    printf("Average GPA of all students: %.2f\n", averageGPA);
}

