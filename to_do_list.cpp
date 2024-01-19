#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        std::cout << "Task added successfully!" << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    std::cout << "[Completed] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }

    void deleteTask(int index) {
        if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task deleted successfully!" << std::endl;
        } else {
            std::cout << "Invalid task index. Please try again." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    std::string description;
                    std::cout << "Enter task description: ";
                    std::cin.ignore();  // Clear the input buffer
                    std::getline(std::cin, description);
                    todoList.addTask(description);
                }
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                {
                    int index;
                    std::cout << "Enter the task index to delete: ";
                    std::cin >> index;
                    todoList.deleteTask(index);
                }
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
