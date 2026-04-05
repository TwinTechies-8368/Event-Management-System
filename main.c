#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Event structure
struct Event {
    int id;
    char name[100];
};

struct Event events[MAX];
int adj[MAX][MAX];   // adjacency matrix
int eventCount = 0;
int idCounter = 1;

// Find index by ID
int findIndex(int id) {
    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id)
            return i;
    }
    return -1;
}

// Create Event
void createEvent() {
    if (eventCount >= MAX) {
        printf("Limit reached!\n");
        return;
    }

    char name[100];
    printf("Enter event name: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    events[eventCount].id = idCounter++;
    strcpy(events[eventCount].name, name);

    eventCount++;

    printf("Event created!\n");
}

// Add dependency (edge)
int hasCycleUtil(int v, int visited[], int recStack[]) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < eventCount; i++) {
            if (adj[v][i]) {
                if (!visited[i] && hasCycleUtil(i, visited, recStack))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int hasCycle() {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < eventCount; i++) {
        if (hasCycleUtil(i, visited, recStack))
            return 1;
    }
    return 0;
}

void addDependency() {
    int from, to;
    printf("Enter prerequisite event ID: ");
    scanf("%d", &from);
    printf("Enter dependent event ID: ");
    scanf("%d", &to);

    int i = findIndex(from);
    int j = findIndex(to);

    if (i == -1 || j == -1) {
        printf("Invalid IDs!\n");
        return;
    }

    adj[i][j] = 1;

    if (hasCycle()) {
        adj[i][j] = 0;
        printf("Cycle detected! Dependency not added.\n");
    } else {
        printf("Dependency added!\n");
    }
}

// Display DAG
void display() {
    printf("\nEvents:\n");
    for (int i = 0; i < eventCount; i++) {
        printf("[%d] %s\n", events[i].id, events[i].name);
    }

    printf("\nDependencies:\n");
    for (int i = 0; i < eventCount; i++) {
        for (int j = 0; j < eventCount; j++) {
            if (adj[i][j]) {
                printf("%s -> %s\n", events[i].name, events[j].name);
            }
        }
    }
}

// Update Event
void updateEvent() {
    int id;
    printf("Enter event ID to update: ");
    scanf("%d", &id);

    int idx = findIndex(id);

    if (idx == -1) {
        printf("Event not found!\n");
        return;
    }

    char name[100];
    printf("Enter new name: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    strcpy(events[idx].name, name);
    printf("Event updated!\n");
}

// Delete Event
void deleteEvent() {
    int id;
    printf("Enter event ID to delete: ");
    scanf("%d", &id);

    int idx = findIndex(id);

    if (idx == -1) {
        printf("Event not found!\n");
        return;
    }

    // Shift events
    for (int i = idx; i < eventCount - 1; i++) {
        events[i] = events[i + 1];
    }

    // Update adjacency matrix
    for (int i = idx; i < eventCount - 1; i++) {
        for (int j = 0; j < eventCount; j++) {
            adj[i][j] = adj[i + 1][j];
        }
    }

    for (int j = idx; j < eventCount - 1; j++) {
        for (int i = 0; i < eventCount; i++) {
            adj[i][j] = adj[i][j + 1];
        }
    }

    eventCount--;
    printf("Event deleted!\n");
}

// Menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Event Management System ---\n");
        printf("1. Create Event\n");
        printf("2. Add Dependency\n");
        printf("3. Display Events & Dependencies\n");
        printf("4. Update Event\n");
        printf("5. Delete Event\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEvent();
                break;
            case 2:
                addDependency();
                break;
            case 3:
                display();
                break;
            case 4:
                updateEvent();
                break;
            case 5:
                deleteEvent();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
