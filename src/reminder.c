#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "reminder.h"
#include "linked_list.h"
//Clair (Wantong) Yu 251350213
//This program initializes the current month and displays the calendar
struct Month month;

//Initializes current month
void initializeMonth() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    month.month_idx = t->tm_mon;
    t->tm_mday = 1;
    mktime(t);
    month.start_day = t->tm_wday;

    month.month_days = t->tm_mday;
    while (t->tm_mon == month.month_idx) {
        month.month_days = t->tm_mday;
        t->tm_mday++;
        mktime(t);
    }

    for (int i = 0; i < 31; i++) {
        month.reminders[i] = NULL;
    }
}
//Displays calendar accoridng to current month
void displayCalendar() {
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    int current_day = 1;
    for (int i = 0; i < month.start_day; i++) {
        printf("    ");
    }
    while (current_day <= month.month_days) {
        struct Node* temp = month.reminders[current_day - 1];
        if (temp != NULL) {
            printf("(%2d)", current_day);
        } else {
            printf("%3d ", current_day);
        }

        if ((current_day + month.start_day) % 7 == 0) {
            printf("\n");
        }
        current_day++;
    }
    printf("\n");
}
char* getWeekday(int day) {
    static char* weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int weekday_idx = (month.start_day + (day - 1)) % 7;
    return weekdays[weekday_idx];
}
