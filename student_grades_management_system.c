#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

// structure for storing student information
struct Student {
    char name[50];
    int grade;
};

// function declarations
void calc_average(struct Student students[], int num_students,
                  float *average, int *max, int *min);

void apply_curve(struct Student students[], int num_students,
                 int threshold, int curve_value);

void above_threshold(struct Student students[],
                     int num_students,
                     int threshold);

void input_grades(struct Student students[], int num_students);

void sort_grades(struct Student students[], int num_students);

int main() {

    int num_students;
    struct Student students[MAX_STUDENTS];

    int choice;

    float average;
    int max, min;

    int threshold;
    int curve_value;

    // get number of students
    do {

        printf("Enter number of students (1-50): ");
        scanf("%d", &num_students);

    } while (num_students < 1 || num_students > 50);

    // collect student data
    input_grades(students, num_students);

    // menu loop
    do {

        printf("\n----- MENU -----\n");

        printf("1 - Sort grades (ascending)\n");
        printf("2 - Calculate average, maximum, and minimum\n");
        printf("3 - Find grades above a threshold\n");
        printf("4 - Replace grades below threshold with curve value\n");
        printf("5 - Exit\n");

        printf("Select operation: ");
        scanf("%d", &choice);

        switch (choice) {

            // sort grades
            case 1:

                sort_grades(students, num_students);

                printf("\nSorted Grades:\n");

                for (int i = 0; i < num_students; i++) {

                    printf("%s : %d\n",
                           students[i].name,
                           students[i].grade);
                }

                break;

            // calculate average, max and min
            case 2:

                calc_average(students,
                             num_students,
                             &average,
                             &max,
                             &min);

                printf("\nAverage grade: %.2f\n", average);
                printf("Maximum grade: %d\n", max);
                printf("Minimum grade: %d\n", min);

                break;

            // find grades above threshold
            case 3:

                printf("Enter threshold: ");
                scanf("%d", &threshold);

                above_threshold(students,
                                num_students,
                                threshold);

                break;

            // apply curve
            case 4:

                printf("Enter threshold: ");
                scanf("%d", &threshold);

                printf("Enter curve value: ");
                scanf("%d", &curve_value);

                apply_curve(students,
                            num_students,
                            threshold,
                            curve_value);

                printf("\nUpdated Grades:\n");

                for (int i = 0; i < num_students; i++) {

                    printf("%s : %d\n",
                           students[i].name,
                           students[i].grade);
                }

                break;

            // exit
            case 5:

                printf("Exiting program. Goodbye!\n");

                break;

            default:

                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}


// calculates average, maximum and minimum grades
void calc_average(struct Student students[],
                  int num_students,
                  float *average,
                  int *max,
                  int *min) {

    int sum = 0;

    *max = students[0].grade;
    *min = students[0].grade;

    for (int i = 0; i < num_students; i++) {

        sum += students[i].grade;

        if (students[i].grade > *max) {
            *max = students[i].grade;
        }

        if (students[i].grade < *min) {
            *min = students[i].grade;
        }
    }

    *average = (float)sum / num_students;
}


// sorts grades from lowest to highest
void sort_grades(struct Student students[], int num_students) {

    struct Student temp;

    for (int i = 0; i < num_students - 1; i++) {

        for (int j = i + 1; j < num_students; j++) {

            if (students[i].grade > students[j].grade) {

                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


// prints students above threshold
void above_threshold(struct Student students[],
                     int num_students,
                     int threshold) {

    printf("\nStudents above %d:\n", threshold);

    for (int i = 0; i < num_students; i++) {

        if (students[i].grade > threshold) {

            printf("%s : %d\n",
                   students[i].name,
                   students[i].grade);
        }
    }
}


// gets student names and grades from user
void input_grades(struct Student students[], int num_students) {

    for (int i = 0; i < num_students; i++) {

        printf("\nEnter name for student %d: ", i + 1);

        scanf(" %[^\n]", students[i].name);

        do {

            printf("Enter grade for %s (0-100): ",
                   students[i].name);

            scanf("%d", &students[i].grade);

        } while (students[i].grade < 0 ||
                 students[i].grade > 100);
    }
}


// replaces grades below threshold
void apply_curve(struct Student students[],
                 int num_students,
                 int threshold,
                 int curve_value) {

    for (int i = 0; i < num_students; i++) {

        if (students[i].grade < threshold) {

            students[i].grade = curve_value;
        }
    }
}
