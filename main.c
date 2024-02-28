#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_STUDENTS 50
#define MAX_TEACHERS 20
#define ACCOUNTS_FILE "#define FILENAME "D:\\School C\\accounts\\accounts.txt"
#define MAX_ADMIN_ACCOUNTS 1

// Define structures
struct Student {
    int studentID;
    char name[50];
    int grade;
};

struct Teacher {
    int teacherID;
    char name[50];
    double salary;
};

struct Admin {
    char username[50];
    char password[50];  
};

// Function to initialize the array of students and set the number of students to zero
void initializeStudents(struct Student students[MAX_STUDENTS], int *numStudents) {
    *numStudents = 0;
}

// Function to initialize the array of teachers and set the number of teachers to zero
void initializeTeachers(struct Teacher teachers[MAX_TEACHERS], int *numTeachers) {
    *numTeachers = 0;
}

// Function to add a new student to the array, validating name and grade
void addStudent(struct Student students[MAX_STUDENTS], int numStudents) {
    int isValidName, isValidGrade;

    do {
        isValidName = 1;
        printf("Enter student name: ");
        scanf("%s", students[*numStudents].name);

        for (int i = 0; students[*numStudents].name[i] != '\0'; i++) {
            if (!isalpha(students[*numStudents].name[i])) {
                isValidName = 0;
                break;
            }
        }

        if (!isValidName) {
            printf("Invalid name. Please enter alphabetic characters only.\n");
        }

    } while (!isValidName);

    do {
        isValidGrade = 1;
        printf("Enter student grade: ");
        if (scanf("%d", &students[*numStudents].grade) != 1 || students[*numStudents].grade < 0 || students[*numStudents].grade > 100) {
            isValidGrade = 0;
            printf("Grade must be numeric \n");
            while (getchar() != '\n');
        }

    } while (!isValidGrade);

    students[*numStudents].studentID = *numStudents + 1;
    (*numStudents)++;
    printf("Student added successfully.\n");
}

// Function to update information for an existing student based on studentID
void updateStudent(struct Student students[MAX_STUDENTS], int numStudents, int studentID) {
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == studentID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter new student name: ");
        scanf("%s", students[index].name);
        printf("Enter new student grade: ");
        scanf("%d", &students[index].grade);
        printf("Student information updated successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

// Function to remove a student based on studentID
void removeStudent(struct Student students[MAX_STUDENTS], int *numStudents, int studentID) {
    int index = -1;
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].studentID == studentID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *numStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        (*numStudents)--;
        printf("Student removed successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

// Function to display information for a student based on studentID
void displayStudentInfo(struct Student students[MAX_STUDENTS], int studentID) {
    int index = -1;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].studentID == studentID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Student ID: %d\n", students[index].studentID);
        printf("Name: %s\n", students[index].name);
        printf("Grade: %d\n", students[index].grade);
    } else {
        printf("Student not found.\n");
    }
}

// Function to add a new teacher to the array
void addTeacher(struct Teacher teachers[MAX_TEACHERS], int *numTeachers) {
    printf("Enter teacher name: ");
    scanf("%s", teachers[*numTeachers].name);
    printf("Enter teacher salary: ");
    scanf("%lf", &teachers[*numTeachers].salary);
    teachers[*numTeachers].teacherID = *numTeachers + 1;
    (*numTeachers)++;
    printf("Teacher added successfully.\n");
}

// Function to update information for an existing teacher based on teacherID
void updateTeacher(struct Teacher teachers[MAX_TEACHERS], int numTeachers, int teacherID) {
    int index = -1;
    for (int i = 0; i < numTeachers; i++) {
        if (teachers[i].teacherID == teacherID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter new teacher name: ");
        scanf("%s", teachers[index].name);
        printf("Enter new teacher salary: ");
        scanf("%lf", &teachers[index].salary);
        printf("Teacher information updated successfully.\n");
    } else {
        printf("Teacher not found.\n");
    }
}

// Function to remove a teacher based on teacherID
void removeTeacher(struct Teacher teachers[MAX_TEACHERS], int *numTeachers, int teacherID) {
    int index = -1;
    for (int i = 0; i < *numTeachers; i++) {
        if (teachers[i].teacherID == teacherID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *numTeachers - 1; i++) {
            teachers[i] = teachers[i + 1];
        }
        (*numTeachers)--;
        printf("Teacher removed successfully.\n");
    } else {
        printf("Teacher not found.\n");
    }
}

// Function to display information for a teacher based on teacherID
void displayTeacherInfo(struct Teacher teachers[MAX_TEACHERS], int teacherID) {
    int index = -1;
    for (int i = 0; i < MAX_TEACHERS; i++) {
        if (teachers[i].teacherID == teacherID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Teacher ID: %d\n", teachers[index].teacherID);
        printf("Name: %s\n", teachers[index].name);
        printf("Salary: %.2lf\n", teachers[index].salary);
    } else {
        printf("Teacher not found.\n");
    }
}

// Function to calculate and display the average grade of all students
void calculateAverageGrade(struct Student students[MAX_STUDENTS], int numStudents) {
    if (numStudents > 0) {
        int totalGrade = 0;
        for (int i = 0; i < numStudents; i++) {
            totalGrade += students[i].grade;
        }
        double averageGrade = (double)totalGrade / numStudents;
        printf("Average Grade: %.2lf\n", averageGrade);
    } else {
        printf("No students available.\n");
    }
}

// Function to calculate and display the average salary of all teachers
void calculateAverageSalary(struct Teacher teachers[MAX_TEACHERS], int numTeachers) {
    if (numTeachers > 0) {
        double totalSalary = 0;
        for (int i = 0; i < numTeachers; i++) {
            totalSalary += teachers[i].salary;
        }
        double averageSalary = totalSalary / numTeachers;
        printf("Average Salary: %.2lf\n", averageSalary);
    } else {
        printf("No teachers available.\n");
    }
}

// Function to display the total number of students and teachers
void displayTotalCounts(int numStudents, int numTeachers) {
    printf("Total Students: %d\n", numStudents);
    printf("Total Teachers: %d\n", numTeachers);
}

void saveDataToFile(struct Student students[MAX_STUDENTS], int numStudents,
                    struct Teacher teachers[MAX_TEACHERS], int numTeachers
                    struct Admin admins[MAX_ADMIN_ACCOUNTS]) {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        fprintf(file, "%d\n", numStudents);
        for (int i = 0; i < numStudents; i++) {
            fprintf(file, "%d %s %d\n", students[i].studentID, students[i].name, students[i].grade);
        }

        fprintf(file, "%d\n", numTeachers);
        for (int i = 0; i < numTeachers; i++) {
            fprintf(file, "%d %s %.2lf\n", teachers[i].teacherID, teachers[i].name, teachers[i].salary);
        }

        // Save admin data
        fprintf(file, "%s %s\n", admins[0].username, admins[0].password);

        fclose(file);
        printf("Data saved to file.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}


void loadDataFromFile(struct Student students[MAX_STUDENTS], int *numStudents,
                      struct Teacher teachers[MAX_TEACHERS], int *numTeachers,
                      struct Admin admins[MAX_ADMIN_ACCOUNTS]) {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        fscanf(file, "%d", numStudents);
        for (int i = 0; i < *numStudents; i++) {
            fscanf(file, "%d %s %d", &students[i].studentID, students[i].name, &students[i].grade);
        }

        fscanf(file, "%d", numTeachers);
        for (int i = 0; i < *numTeachers; i++) {
            fscanf(file, "%d %s %lf", &teachers[i].teacherID, teachers[i].name, &teachers[i].salary);
        }

        // Load admin data
        fscanf(file, "%s %s", admins[0].username, admins[0].password);

        fclose(file);
        printf("Data loaded from file.\n");
    } else {
        printf("No existing data file found.\n");
    }
}

int adminLogin(struct Admin admins[MAX_ADMIN_ACCOUNTS]) {
    char inputUsername[50];
    char inputPassword[50];

    printf("Enter admin username: ");
    scanf("%s", inputUsername);

    printf("Enter admin password: ");
    scanf("%s", inputPassword);

    if (strcmp(inputUsername, admins[0].username) == 0 && strcmp(inputPassword, admins[0].password) == 0) {
        printf("Admin login successful!\n");
        return 1;  // Return 1 to indicate successful login
    } else {
        printf("Incorrect username or password. Access denied.\n");
        return 0;  // Return 0 to indicate failed login
    }
}

// Function to perform admin signup
void adminSignUp(struct Admin admins[MAX_ADMIN_ACCOUNTS]) {
    printf("Enter admin username: ");
    scanf("%s", admins[0].username);

    printf("Enter admin password: ");
    scanf("%s", admins[0].password);

    printf("Admin account created successfully.\n");
}

// Function to enter the school name
void enterSchoolName(char schoolName[]) {
    printf("Enter the name of the school: ");
    scanf("%s", schoolName);

    // Validate that the name contains only alphabetic characters
    for (int i = 0; schoolName[i] != '\0'; i++) {
        if (!isalpha(schoolName[i])) {
            printf("Invalid school name. Please enter alphabetic characters only.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Function to display the admin menu
void adminMenu(struct Student students[MAX_STUDENTS], int *numStudents,
               struct Teacher teachers[MAX_TEACHERS], int *numTeachers,
               struct Admin admins[MAX_ADMIN_ACCOUNTS]) {
    char schoolName[50];

    // Enter the school name
    enterSchoolName(schoolName);

int choice;
    do {
        printf("\nAdmin Menu\n");
        printf("1. Admin Sign Up\n");
        printf("2. Admin Login\n");
        printf("3. Perform Admin Operation\n");
        printf("0. Exit Admin Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminSignUp(admins);
                saveDataToFile(students, *numStudents, teachers, *numTeachers, admins);
                break;
            case 2:
                if (adminLogin(admins)) {
                    printf("Admin Login Successful!\n");
                } else {
                    printf("Admin Login Failed. Exiting...\n");
                    return;
                }
                break;
            case 3:
                // Additional admin functionalities can be added here
                break;
            case 0:
                printf("Exiting admin menu.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 3.\n");
        }
    } while (choice != 0);
}

// Main function
int main() {
    struct Student students[MAX_STUDENTS];
    struct Teacher teachers[MAX_TEACHERS];
    struct Admin admins[MAX_ADMIN_ACCOUNTS];
    int numStudents = 0;
    int numTeachers = 0;

    initializeStudents(students, &numStudents);
    initializeTeachers(teachers, &numTeachers);

    adminSignUp(admins);

    if (!adminLogin(admins)) {
        printf("Admin login failed. Exiting...\n");
        return 1;  // Return an error code to indicate failure
    }

    // Main menu
   void mainMenu(struct Student students[MAX_STUDENTS], int *numStudents,
              struct Teacher teachers[MAX_TEACHERS], int *numTeachers,
              struct Admin admins[MAX_ADMIN_ACCOUNTS]) {
    int choice;
    do {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. Update Student Information\n");
        printf("3. Remove Student\n");
        printf("4. Display Student Information\n");
        printf("5. Add Teacher\n");
        printf("6. Update Teacher Information\n");
        printf("7. Remove Teacher\n");
        printf("8. Display Teacher Information\n");
        printf("9. Calculate Average Grade\n");
        printf("10. Calculate Average Salary\n");
        printf("11. Display Total Counts\n");
        printf("12. Save Data to File\n");
        printf("13. Load Data from File\n");
        printf("14. Admin Menu\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2: {
                int studentID;
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                updateStudent(students, numStudents, studentID);
                break;
            }
            case 3: {
                int studentID;
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                removeStudent(students, &numStudents, studentID);
                break;
            }
            case 4: {
                int studentID;
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                displayStudentInfo(students, studentID);
                break;
            }
            case 5:
                addTeacher(teachers, &numTeachers);
                break;
            case 6: {
                int teacherID;
                printf("Enter teacher ID: ");
                scanf("%d", &teacherID);
                updateTeacher(teachers, numTeachers, teacherID);
                break;
            }
            case 7: {
                int teacherID;
                printf("Enter teacher ID: ");
                scanf("%d", &teacherID);
                removeTeacher(teachers, &numTeachers, teacherID);
                break;
            }
            case 8: {
                int teacherID;
                printf("Enter teacher ID: ");
                scanf("%d", &teacherID);
                displayTeacherInfo(teachers, teacherID);
                break;
            }
            case 9:
                calculateAverageGrade(students, numStudents);
                break;
            case 10:
                calculateAverageSalary(teachers, numTeachers);
                break;
            case 11:
                displayTotalCounts(numStudents, numTeachers);
                break;
            case 12:
                saveDataToFile(students, numStudents, teachers, numTeachers);
                break;
            case 13:
                loadDataFromFile(students, &numStudents, teachers, &numTeachers);
                break;
            case 14:
                adminMenu(students, &numStudents, teachers, &numTeachers);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 14.\n");
        }
    } while (choice != 0);

}
int main() {
    struct Student students[MAX_STUDENTS];
    struct Teacher teachers[MAX_TEACHERS];
    struct Admin admins[MAX_ADMIN_ACCOUNTS];
    int numStudents = 0;
    int numTeachers = 0;

    initializeStudents(students, &numStudents);
    initializeTeachers(teachers, &numTeachers);

    loadDataFromFile(students, &numStudents, teachers, &numTeachers, admins);

    // Main menu
    mainMenu(students, &numStudents, teachers, &numTeachers, admins);

    return 0;
}