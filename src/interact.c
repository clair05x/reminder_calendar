//Clair (Wantong) Yu 251350213
//This program is responsible for adding reminders, managing reminder files, and displaying reminders.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "reminder.h"
#include "linked_list.h"
//Add reminder and validate user input

void addReminder() {
    int day;
    char input[150], reminder[100];
    printf("Enter day and reminder (0 to quit): ");
    fgets(input, 150, stdin);

    sscanf(input, "%d %[^\n]", &day, reminder);

    if (day == 0) {
        saveReminders();
        printf("Exiting program.\n");
        exit(0);
    }

    if (day < 1 || day > month.month_days) {
        printf("Invalid day. Please enter a day between 1 and %d.\n", month.month_days);
        return;
    }

    addNode(&month.reminders[day - 1], reminder);
    printf("Reminder added for day %d: %s\n", day, reminder);

    displayCalendar();
    displayReminders();
}
//Display reminders
void displayReminders() {
const char *monthNames[] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};
printf("\n%s reminders:\n", monthNames[month.month_idx]); 
    for (int i = 0; i < month.month_days; i++) {
        struct Node* temp = month.reminders[i];
        if (temp != NULL) {
            printf("%s %2d::", getWeekday(i + 1), i + 1);

            int count = 1;
            printf(" (%d) %s\n", count++, temp->reminder);
            temp = temp->next;

            while (temp != NULL) {
                printf("         (%d) %s\n", count++, temp->reminder);
                temp = temp->next;
            }
        }
    }printf("_________________\n");
}
//read reminders from the file
void loadReminders() {
    FILE* file = fopen("reminders.txt", "r");
    if (file == NULL) return;

    int day;
    char reminder[100];
    while (fscanf(file, "%d %[^\n]", &day, reminder) == 2) {
        addNode(&month.reminders[day - 1], reminder);
    }
    fclose(file);
}
//save reminders to the file
void saveReminders() {
    FILE* file = fopen("reminders.txt", "w");
    if (file == NULL) {
        printf("Error saving reminders.\n");
        return;
    }

    for (int i = 0; i < month.month_days; i++) {
        struct Node* temp = month.reminders[i];
        while (temp != NULL) {
            fprintf(file, "%d %s\n", i + 1, temp->reminder);
            temp = temp->next;
        }
    }
    fclose(file);
}
