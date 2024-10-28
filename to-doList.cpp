#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) {
        description = desc;
        isCompleted = false;
    }
};

void displayMenu() {
    cout << "\nTo-Do List Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

void addTask(vector<Task> &tasks) {
    cout << "Enter the task description: ";
    string desc;
    cin.ignore(); 
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\nList of Tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].isCompleted)
            cout << " [Completed]";
        else
            cout << " [Pending]";
        cout << endl;
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber <= 0 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    }
}

void removeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber <= 0 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please choose a valid option.\n";
        }
    }
}
