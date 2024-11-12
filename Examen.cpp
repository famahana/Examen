#include <iostream>
#include <cstring>
using namespace std;

struct Todo
{
	char *name;
	int priority;
	char *description;
	int date;
	int second_date;
	int time;
	int second_time;
};


void showToDolist(Todo& td)
{
	cout << "Name of TODO: " << td.name << endl;
	cout << "Priority of TODO: " << td.priority << endl;
	cout << "Description of TODO: " << td.description << endl;
	cout << "Date: DAY " << td.date << "." << td.second_date << endl;
	cout << "Time: " << td.time << ":" << td.second_time << endl;
}


void removeTodolist(Todo*& td,int& size,int userinput)
{
	for (int i = userinput; i < size - 1; i++) {
		td[i] = td[i + 1];
	}
	size--;
}



void sortByDateandTime(Todo todos[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (todos[j].date > todos[j + 1].date ||
				(todos[j].date == todos[j + 1].date && todos[j].second_date > todos[j + 1].second_date) 
				||(todos[j].date == todos[j + 1].date && todos[j].second_date == todos[j + 1].second_date && todos[j].time > todos[j + 1].time) 
				||(todos[j].date == todos[j + 1].date && todos[j].second_date == todos[j + 1].second_date && todos[j].time == todos[j + 1].time && todos[j].second_time > todos[j + 1].second_time))
			{
				Todo temp = todos[j];
				todos[j] = todos[j + 1];
				todos[j + 1] = temp;
			}
		}
	}

}

void sortByPriority(Todo*& td, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (td[j].priority > td[j + 1].priority)
			{
				Todo temp = td[j];
				td[j] = td[j + 1];
				td[j + 1] = temp;
			}
		}
	}
}

void showTodoListByTime(Todo todos[], int size)
{
	int userinput;
	int userinput_2;
	int day;
	int week;
	int month;
	cout << "Show Todolist by (1 - Day, 2 - Week, 3 - Month): ";
	cin >> userinput;
	if (userinput == 1)
	{
		cout << "Enter your day : ";
		cin >> day;
		cout << "If you wanna sort you Todolist by priority or date and time enter(1 - priority, 2 - date and time, 3 - dont sort and show): ";
		cin >> userinput_2;
		if (userinput_2 == 1)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].date == day)
				{
					sortByPriority(todos, size);
					cout << "Sort complete" << endl;
					showToDolist(todos[i]);
				}
			}
		}
		else if (userinput_2 == 2)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].date == day)
				{
					sortByDateandTime(todos, size);
					cout << "Sort complete" << endl;
					showToDolist(todos[i]);
				}
			}
		}
		else if (userinput_2 == 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].date == day)
				{
					showToDolist(todos[i]);
				}
			}
		}
	}
	if (userinput == 2)
	{
		cout << "Enter your week : ";
		cin >> week;
		cout << "If you wanna sort you Todolist by priority or date and time enter(1 - priority, 2 - date and time, 3 - dont sort and show): ";
		cin >> userinput_2;
		int startDay = (week - 1) * 7 + 1;
		int endDay = week * 7;
		if (userinput_2 == 1)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].date >= startDay && todos[i].date <= endDay)
				{
					sortByPriority(todos, size);
					cout << "Sort complete" << endl;
					showToDolist(todos[i]);
				}
			}
		}
		else if (userinput_2 == 2)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].date >= startDay && todos[i].date <= endDay)
				{
					sortByDateandTime(todos, size);
					cout << "Sort complete" << endl;
					showToDolist(todos[i]);
				}
			}
		}
		else if (userinput_2 == 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].date >= startDay && todos[i].date <= endDay)
				{
					showToDolist(todos[i]);
				}
			}
		}
	}
	else if (userinput == 3)
	{
		cout << "Enter your Month : ";
		cin >> month;
		cout << "If you wanna sort you Todolist by priority or date and time enter(1 - priority, 2 - date and time, 3 - dont sort and show): ";
		cin >> userinput_2;
		if (userinput_2 == 1)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].second_date == month)
				{
					sortByPriority(todos, size);
					cout << "Sort complete" << endl;
					showToDolist(todos[i]);
				}
			}
		}
		else if (userinput_2 == 1)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].second_date == month)
				{
					sortByPriority(todos, size);
					cout << "Sort complete" << endl;
					showToDolist(todos[i]);
				}
			}
		}
		else if (userinput_2 == 2)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].second_date == month)
				{
					sortByDateandTime(todos, size);
					cout << "Sort complete" << endl;
					showToDolist(todos[i]);
				}
			}
		}
		else if (userinput_2 == 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (todos[i].second_date == month)
				{
					showToDolist(todos[i]);
				}
			}
		}
	}
}


void findByToDolist(Todo todos[], int size)
{
	char userinput_name[20];
	char userinput_description[20];
	int userinput_priority;
	int userinput_time;
	int userinput_time_second;
	int userinput_date;
	int userinput_date_second;
	int userinput;
	cout << "Hello. This is findByin Todolist menu" << endl;
	cout << "Enter what value to search for(1 - Name, 2 - Priority, 3 - Description, 4 - date, 5 - time.): ";
	cin >> userinput;
	if (userinput == 1)
	{
		cout << "Enter name: ";
		cin.ignore();
		cin.getline(userinput_name, 20);
		for (int i = 0; i < size; i++)
		{
			if (strcmp(todos[i].name, userinput_name) == 0)
			{
				showToDolist(todos[i]);
			}
		}
	}
	else if (userinput == 2)
	{
		cout << "Enter priority: ";
		cin >> userinput_priority;
		for (int i = 0; i < size; i++)
		{
			if (todos[i].priority == userinput_priority)
			{
				showToDolist(todos[i]);
			}
		}
	}
	else if (userinput == 3)
	{
		cout << "Enter description: ";
		cin.ignore();
		cin.getline(userinput_description, 20);
		for (int i = 0; i < size; i++)
		{
			if (strcmp(todos[i].description, userinput_description) == 0)
			{
				showToDolist(todos[i]);
			}
		}
	}
	else if (userinput == 4)
	{
		cout << "Enter date (First): ";
		cin >> userinput_date;
		cout << "Enter date (Second after - .): ";
		cin >> userinput_date_second;
		for (int i = 0; i < size; i++)
		{
			if (todos[i].date == userinput_date && todos[i].second_date == userinput_date_second)
			{
				showToDolist(todos[i]);
			}
		}
	}
	else if (userinput == 5)
	{
		cout << "Enter time(First): ";
		cin >> userinput_time;
		cout << "Enter time (Second after - .): ";
		cin >> userinput_time_second;
		for (int i = 0; i < size; i++)
		{
			if (todos[i].time == userinput_time && todos[i].second_time == userinput_time_second)
			{
				showToDolist(todos[i]);
			}
		}
	}
}

void editToDolist(Todo& td)
{
	int userinput;
	char* userinput_name = new char[20];
	char* userinput_description = new char[20];
	int userinput_priority;
	int userinput_time;
	int userinput_time_second;
	int userinput_date;
	int userinput_date_second;
	cout << "Hello this is edit menu for Todolist." << endl;
	cout << "You wanna change all Todo or a specific parameter?" << endl;
	cout << "If you wanna change all Todo Enter 1" << endl;
	cout << "(2 - change name,3 - change description, 4 - change priority,5 - change date, 6 - change time.): ";
	cin >> userinput;
	if (userinput == 1)
	{
		cout << "Enter new name of TODO: ";
		cin >> userinput_name;
		td.name = userinput_name;
		cout << "Enter new description of TODO: ";
		cin >> userinput_description;
		td.description = userinput_description;
		cout << "Enter new priority of TODO: ";
		cin >> userinput_priority;
		td.priority = userinput_priority;
		cout << "Enter new date of TODO(First): ";
		cin >> userinput_date;
		td.date = userinput_date;
		cout << "Enter new date of TODO(Second after - .): ";
		cin >> userinput_date_second;
		td.second_date = userinput_date_second;
		cout << "Enter new time of TODO(First): ";
		cin >> userinput_time;
		td.time = userinput_time;
		cout << "Enter new time of TODO(Second after - .): ";
		cin >> userinput_time_second;
		td.second_time = userinput_time_second;
	}
	else if (userinput == 2)
	{
		cout << "Enter new name of TODO: ";
		cin >> userinput_name;
		td.name = userinput_name;
	}
	else if (userinput == 3)
	{
		cout << "Enter new description of TODO: ";
		cin >> userinput_description;
		td.description = userinput_description;
	}
	else if (userinput == 4)
	{
		cout << "Enter new priority of TODO: ";
		cin >> userinput_priority;
		td.priority = userinput_priority;
	}
	else if (userinput == 5)
	{
		cout << "Enter new date of TODO(First): ";
		cin >> userinput_date;
		td.date = userinput_date;
		cout << "Enter new date of TODO(Second after - .): ";
		cin >> userinput_date_second;
		td.second_date = userinput_date_second;
	}
	else if (userinput == 6)
	{
		cout << "Enter new time of TODO(First): ";
		cin >> userinput_time;
		td.time = userinput_time;
		cout << "Enter new time of TODO(Second after - .): ";
		cin >> userinput_time_second;
		td.second_time = userinput_time_second;
	}
}


void writeToDolist(const char* namefile, Todo todos[], int size)
{
	FILE* file;
	if (fopen_s(&file, namefile,"w")==NULL)
	{
		fwrite(todos, sizeof(Todo), size,file);
		fclose(file);
	}
}
void readToDolist(const char* namefile,Todo todos[], int size)
{
	FILE* file;
	if (fopen_s(&file, namefile, "r") == NULL)
	{
		fread(todos, sizeof(Todo), size, file);
		fclose(file);
	}
}

Todo createToDo()
{
	Todo td;
	td.name = new char[20];
	cout << "Enter name of TODO(20 symbols max): ";
	cin >> td.name;
	cout << "Enter priority of TODO: ";
	cin >> td.priority;
	td.description = new char[20];
	cout << "Enter description of TODO(20 symbols max): ";
	cin >> td.description;
	cout << "Enter date of TODO(First): ";
	cin >> td.date;
	cout << "Enter date of TODO(second after - . ): ";
	cin >> td.second_date;
	cout << "Enter time of TODO first: ";
	cin >> td.time;
	cout << "Enter time of TODO second: ";
	cin >> td.second_time;
	return td;
}

void usermenu(const char* namefile)
{
	int SIZE = 0;
	int choice;
	int choice_1;
	Todo* todos = nullptr;
	cout << "Hello! This is usermenu for TODO list" << endl;
	do
	{
		cout << "Choice your action(1 - create Todolist,2 - Save your file." << endl;
		cout << "3 - Edit Todolist, 4 - Delete Todolist, 5 - findBymenu, 6 - FindbyDayweekmonth, 9 - Show Todolist, 0 - EXIT): ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "OK. Enter amount of TODOS: ";
			cin >> SIZE;
			todos = new Todo[SIZE];
			for (int i = 0; i < SIZE; i++)
			{
				todos[i] = createToDo();
			}
			cout << "You wanna see Todolist?(1 - YES, 0 - NO): ";
			cin >> choice_1;
			if (choice_1 == 1)
			{
				for (int i = 0; i < SIZE; i++)
				{
					showToDolist(todos[i]);
				}
			}
			else if (choice_1 == 0)
			{
				cout << "Ok." << endl;
			}
		}
		else if (choice == 2 && todos != nullptr)
		{
			writeToDolist(namefile, todos, SIZE);
			cout << "You wanna see Todolist from file?(1 - YES, 0 - NO): ";
			cin >> choice_1;
			if (choice_1 == 1)
			{
				Todo* todosfromfile = new Todo[SIZE];
				readToDolist(namefile, todosfromfile, SIZE);
				for (int i = 0; i < SIZE; i++)
				{
					showToDolist(todosfromfile[i]);
				}
				delete[]todosfromfile;
			}
			else if (choice_1 == 0)
			{
				cout << "Ok." << endl;
			}
		}
		else if (choice == 3 && todos != nullptr)
		{
			int userinput_2;
			cout << "Ok." << endl;
			cout << "Enter what to-do list you want to change: - ";
			cin >> userinput_2;
			if (userinput_2 > 0 && userinput_2 <= SIZE)
			{
				editToDolist(todos[userinput_2 - 1]);
			}
			else
			{
				cout << "Wrong value!!!" << endl;
			}
		}
		else if (choice == 4 && todos != nullptr)
		{
			int userinput_3;
			cout << "Ok." << endl;
			cout << "Enter what to-do list you want to delete: - ";
			cin >> userinput_3;
			if (userinput_3 > 0 && userinput_3 <= SIZE)
			{
				removeTodolist(todos,SIZE,userinput_3 - 1);
			}
			else
			{
				cout << "Wrong value!!!" << endl;
			}
		}
		else if (choice == 5 && todos != nullptr)
		{
			findByToDolist(todos, SIZE);
		}
		else if (choice == 6 && todos != nullptr)
		{
			showTodoListByTime(todos, SIZE);
		}
		else if (choice == 6 && todos == nullptr)
		{
			cout << "Todo list is empty. Create a Todolist first!!!" << endl;
		}
		else if (choice == 5 && todos == nullptr)
		{
			cout << "Todo list is empty. Create a Todolist first!!!" << endl;
		}
		else if (choice == 4 && todos == nullptr)
		{
			cout << "Todo list is empty. Create a Todolist first!!!" << endl;
		}
		else if (choice == 3 && todos == nullptr)
		{
			cout << "Todo list is empty. Create a Todolist first!!!" << endl;
		}
		else if (choice == 9&& todos!=nullptr)
		{
			for (int i = 0; i < SIZE; i++)
			{
				showToDolist(todos[i]);
			}
		}
		else if (choice == 9 && todos == nullptr)
		{
			cout << "Todo list is empty. Create a Todolist first!!!" << endl;
		}
		else if (choice == 2 && todos == nullptr)
		{
			cout << "Todo list is empty. Create a Todolist first!!!" << endl;
		}
	} while (choice != 0);
	delete[] todos;
}

int main()
{
	const char* pathToFile = "List of TODO.bin";
	usermenu(pathToFile);
	return 0;
}