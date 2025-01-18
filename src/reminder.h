#ifndef REMINDER_H
#define REMINDER_H

#include "linked_list.h"

struct Month {
    int month_idx;
    int start_day;
    int month_days;
    struct Node* reminders[31];
};

extern struct Month month;

void initializeMonth();
void displayCalendar();
char* getWeekday(int day);

#endif
