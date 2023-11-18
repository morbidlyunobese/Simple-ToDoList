#include <iostream>
#include <string>
#include <vector>

class ToDoList { // this class will handle all of our variables
	public:
		std::vector<std::string> taskList;

		void addToList() {

			std::string task;

			std::cout << "Enter task: ";
			std::getline(std::cin, task);

			taskList.push_back(task);

			std::cout << "Task: " << task << " successfully added at index size: " << taskList.size() - 1 << std::endl;

		}

		void getList() {

			for (size_t i = 0; i < taskList.size(); ++i) {
				std::cout << "Task "<< i << ": " << taskList[i] << "\n";

			}
		}

		void removeTask() {
			
			int position;

			std::cout << "Which task do you want to remove?: ";
			std::cin >> position;

			if (position >= 0 && position < taskList.size()) {
				taskList.erase(taskList.begin() + position);
				std::cout << "Task at index: " << position << " removed!";

			}
			else {
				std::cout << "Index " << position << " not found or out of range.";
			}
		}
};

int main() {

	ToDoList List;
	int tasks;

	std::cout << "Welcome to my To-Do-List program! This is a temporary program to help manage your tasks at hand. \n";

	std::cout << "How many tasks would you like to add?: ";
	std::cin >> tasks;
	std::cin.ignore();

	for (int i = 0; i < tasks; ++i) {
		List.addToList();
	}

	std::cout << "\n";

	List.getList();

	std::cout << "\n";

	List.removeTask();

	std::cout << "\n";

	List.getList();
}