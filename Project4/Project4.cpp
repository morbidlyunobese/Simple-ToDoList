#include <iostream>
#include <string>
#include <vector>

class List {
	public:
		std::vector<std::string> list;

	public:
		void displayActions() {
			std::cout << "{A}dd to list.\n";
				std::cout << "{G}et Tasks.\n";
			std::cout << "{R}emove from list.\n";
				std::cout << "{D}isplay choices.\n";
			std::cout << "{E}xit.\n";
		}

		void setList() {
			std::cout << "How many tasks (0-6): ";
				int size;
			std::cin >> size;
			
			if (size > 0 && size <= 6) {
				for (int i = 0; i < size; i++) {
					std::string task;
						std::cout << "Enter task " << i + 1 << ": ";
					std::cin >> task;
						list.push_back(task);
					std::cout << "\n";
				}
			}
			else {
				std::cout << "Must be between 0-6.\n";
			}
		}

		void getList() {
			if (list.empty()) {
				std::cout << "List is empty. Try adding some tasks!";
			}
			else {
				for (int i = 0; i < list.size(); ++i) {
					std::cout << "Task " << i + 1 << ": " << list[i] << "\n";
				}
			}
			

		}

		void removeTask() {
			char option;
			int index;

			std::cout << "Would you like to display your current tasks? (Y/N): ";
			std::cin >> option;
			
			if (option == 'Y' || option == 'y') {
				getList();
			}
			else if (option == 'N' || option == 'n') {
				std::cout << "\n";
			}

			std::cout << "Enter task to remove: ";
			std::cin >> index;

			if (index >= 0 && index < list.size()) {
				list.erase(list.begin() + index);
				std::cout << "Task at index: " << index << " removed!";
			}
			else {
				std::cout << "Task index not found.";
			}

		}
};


int main() {
	bool userLoop = true;
	char userChoice;
	List list;

	std::cout << "WELCOME TO MY TO-DO-LIST EDITOR!!! IT'S VERY BASIC." << std::endl;
	std::cout << "\n";
	
	list.displayActions();
	std::cout << "\n";

	while (userLoop) {
		std::cout << "Enter option: ";
		std::cin >> userChoice;

		switch (userChoice) {
			case 'A':
				list.setList();
				std::cout << "\n";
				break;

			case 'G':
				list.getList();
				std::cout << "\n";
				break;

			case 'R':
				list.removeTask();
				std::cout << "\n";
				break;

			case 'D':
				list.displayActions();
				std::cout << "\n";
				break;

			case 'E':
				userLoop = false;
				break;
		}
	}
}
