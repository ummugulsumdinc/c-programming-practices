#include <stdio.h>

#define MAX_STUDENTS 50 // define constant for max number of students to calculate


// declaration of functions 
void calc_average(int grade[], int num_students, float *average, int *max, int *min);
void apply_curve(int grade[], int num_students, int threshold, int curve_value);
void above_threshold(int grade[], int num_students, int threshold);
void input_grades(int grade[], int num_students);
void sort_grades(int grade[], int num_students);

int main() {
    int num_students;
    int grades[MAX_STUDENTS];
    int choice;
    float average;
    int max, min;
    int threshold, curve_value;

    do {  //get the number of students  and collect grades for all students from user
        printf("Enter number of students (1-50): ");
        scanf("%d", &num_students);
    } while (num_students < 1 || num_students > 50);
    input_grades(grades, num_students);

    do {
        printf("----- Menu -----\n");
        printf("1 - Sort grades (ascending)\n");
        printf("2 - Calculate average, maximum, and minimum\n");
        printf("3 - Find grades above a threshold\n");
        printf("4 - Replace grades below threshold with curve value\n");
        printf("5 - Exit\n");
        printf("Select operation: ");
        scanf("%d", &choice);

        switch (choice) { // depend on menu options 
            case 1:  //Sort grades (ascending)
                sort_grades(grades, num_students);
                printf("Grades sorted in ascending order: ");
                for (int i = 0; i < num_students; i++) {
                    printf("%d ", grades[i]);
                }
                printf("\n");
                break;
            case 2:  //Calculate average, maximum, and minimum
                calc_average(grades, num_students, &average, &max, &min);
                printf("Average grade: %.2f\n", average);
                printf("Maximum grade: %d\n", max);
                printf("Minimum grade: %d\n", min);
                break;
            case 3:  //Find grades above a threshold
                printf("Enter threshold: ");
                scanf("%d", &threshold);
                above_threshold(grades, num_students, threshold);
                break;
            case 4:  //Replace grades below threshold with curve value
                printf("Enter threshold: ");
                scanf("%d", &threshold);
                printf("Enter curve value: ");
                scanf("%d", &curve_value);
                apply_curve(grades, num_students, threshold, curve_value);
                printf("Curve applied to grades below threshold. Updated grades: ");
                for (int i = 0; i < num_students; i++) {
                    printf("%d ", grades[i]);
                }
                printf("\n");
                break;
            case 5:  //Exit
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}


//definitions of functions

void calc_average(int grade[], int num_students, float *average, int *max, int *min) {
    // calculates the average, min and max grades
    int sum = 0;
    *max = grade[0];
    *min = grade[0];
    for (int i = 0; i < num_students; i++) {
        sum += grade[i];
        if (grade[i] > *max) {
            *max = grade[i];
        }
        if (grade[i] < *min) {
            *min = grade[i];
        }
    }
    *average = (float)sum / num_students;
}

void sort_grades(int grade[], int num_students) {
    // sorts the grades in ascending order (lowest to highest)
    int temp;
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (grade[i] > grade[j]) {
                temp = grade[i];
                grade[i] = grade[j];
                grade[j] = temp;
            }
        }
    }
}

void above_threshold(int grade[], int num_students, int threshold) {
    printf("Grades above %d: ", threshold);
    for (int i = 0; i < num_students; i++) {
        if (grade[i] > threshold) {
            printf("%d ", grade[i]);
        }
    }
    printf("\n");
}

void input_grades(int grade[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        do {
            printf("Enter grade for student %d (0-100): ", i + 1);
            scanf("%d", &grade[i]);
        } while (grade[i] < 0 || grade[i] > 100);
    }
}

void apply_curve(int grade[], int num_students, int threshold, int curve_value) {
    for (int i = 0; i < num_students; i++) {
        if (grade[i] < threshold) {
            grade[i] = curve_value;
        }
    }
}
