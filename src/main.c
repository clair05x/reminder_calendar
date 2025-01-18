//Clair (Wantong) Yu 251350213
//This is the main program for a reminder calendar
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "reminder.h"
#include "interact.h"

//signal handling function
void handle_signal(int signal) {
    if (signal == SIGINT || signal == SIGTERM) {
        printf("\nProgram terminated...\nWriting to file...\n");
        saveReminders();
        exit(0);
    }
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    initializeMonth();
    loadReminders();

    while (1) {
        addReminder();
    }

    return 0;
}
