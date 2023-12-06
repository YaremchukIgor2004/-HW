#include <stdio.h>
#include <stdlib.h>

// 10.13d
struct Employee {
    char lastName[50];
    char firstName[50];
    char gender;  // 'M' male, 'F' female
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
};

struct Employee findOldestMale(struct Employee* array, int size) {
    struct Employee oldestMale;
    int flag = 0;

    for (int i = 0; i < size; i++) {
        if (array[i].gender == 'M' && (!flag || array[i].yearOfBirth < oldestMale.yearOfBirth ||
            (array[i].yearOfBirth == oldestMale.yearOfBirth &&
                array[i].monthOfBirth < oldestMale.monthOfBirth) ||
            (array[i].yearOfBirth == oldestMale.yearOfBirth &&
                array[i].monthOfBirth == oldestMale.monthOfBirth &&
                array[i].dayOfBirth < oldestMale.dayOfBirth))) {
            oldestMale = array[i];
            flag = 1;
        }
    }

    if (!flag) {
        oldestMale.yearOfBirth = 0;
    }

    return oldestMale;
}

int main() {
    int N;
    printf("Enter the number of employees: ");
    scanf("%d", &N);
    struct Employee* profiles = (struct Employee*)malloc(N * sizeof(struct Employee));

    for (int i = 0; i < N; i++) {
        printf("Enter information for employee #%d:\n", i + 1);
        printf("Last Name: ");
        scanf("%s", profiles[i].lastName);
        printf("First Name: ");
        scanf("%s", profiles[i].firstName);
        printf("Gender (M/F): ");
        scanf(" %c", &profiles[i].gender);
        printf("Date of Birth (DD MM YYYY): ");
        scanf("%d %d %d", &profiles[i].dayOfBirth, &profiles[i].monthOfBirth, &profiles[i].yearOfBirth);
    }
    struct Employee oldestMale = findOldestMale(profiles, N);

    if (oldestMale.yearOfBirth != 0) {
        printf("\nThe oldest male employee is:\n");
        printf("Last Name: %s\n", oldestMale.lastName);
        printf("First Name: %s\n", oldestMale.firstName);
        printf("Gender: %c\n", oldestMale.gender);
        printf("Date of Birth: %02d/%02d/%04d\n", oldestMale.dayOfBirth, oldestMale.monthOfBirth, oldestMale.yearOfBirth);
    }
    else {
        printf("\nNo male employees found.\n");
    }
    free(profiles);

    return 0;
}
