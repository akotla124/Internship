#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>  

class Task {
public:
    std::string description;
    bool completed;
    time_t dueDate;

    Task(const std::string& desc, time_t due = 0) : description(desc), completed(false), dueDate(due) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription, time_t dueDate = 0) {
        tasks.push_back(Task(taskDescription, dueDate));
        std::cout << "Task added successfully." << std::endl;
    }

    void viewTasks() {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << " - "
                      << (tasks[i].completed ? "Completed" : "Pending");

            if (tasks[i].dueDate != 0) {
                std::tm* dueDateInfo = std::localtime(&tasks[i].dueDate);
                std::cout << " - Due: " << std::put_time(dueDateInfo, "%Y-%m-%d %H:%M:%S");
            }

            std::cout << std::endl;
        }
    }

    void markAsCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task removed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        std::cout << "\n===== To-Do List Manager =====" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter the task: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);

                time_t dueDate = 0;
                std::cout << "Enter due date and time (YYYY-MM-DD HH:MM:SS), or press Enter for no due date: ";
                std::string dueDateStr;
                std::getline(std::cin, dueDateStr);

                if (!dueDateStr.empty()) {
                    std::tm dueDateInfo = {};
                    std::istringstream dueDateStream(dueDateStr);  // Corrected line
                    dueDateStream >> std::get_time(&dueDateInfo, "%Y-%m-%d %H:%M:%S");
                    dueDateInfo.tm_isdst = -1; // Daylight Saving Time information is not available
                    dueDate = std::mktime(&dueDateInfo);
                }

                todoList.addTask(taskDescription, dueDate);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                std::cout << "Enter the task index to remove: ";
                std::cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the To-Do List Manager. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }
    }

    return 0;
}

