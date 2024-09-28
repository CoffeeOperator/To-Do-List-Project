//Basic to do list application as an project 
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

struct Task {
    string description;
    bool isCompleted;
};

void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskComplete(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markTaskComplete(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 5);

    return 0;
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }
    cout << "\n--- Tasks ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << (tasks[i].isCompleted ? " [Completed]" : " [Pending]") << endl;
    }
}

void markTaskComplete(vector<Task>& tasks) {
    int taskNum;
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter task number to mark as complete: ";
        cin >> taskNum;
        if (taskNum > 0 && taskNum <= tasks.size()) {
            tasks[taskNum - 1].isCompleted = true;
            cout << "Task marked as complete!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }
}

void removeTask(vector<Task>& tasks) {
    int taskNum;
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter task number to remove: ";
        cin >> taskNum;
        if (taskNum > 0 && taskNum <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNum - 1);
            cout << "Task removed!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }
}
