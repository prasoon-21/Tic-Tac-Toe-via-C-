#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct Task
{   
    int id;
    string name;
    string description;
    bool completed=false;
    int priority;
};

ostream& operator<<(ostream& os, const Task& task)
{
    os<<"Task Name     : " << task.name << endl;
    os<<"Description   : " << task.description << endl;
    os<<"Priority      : " << task.priority << endl;
    return os;
}

istream& operator>>(istream& is, Task& task)
{
    cout << "Enter task name           : ";
    is >> task.name;
    cout << "Enter task description    : ";
    is.ignore();
    getline(is, task.description);
    cout << "Enter task priority       : ";
    is >> task.priority;
    return is;
}

class Taskcompare{
public:
    bool operator()(Task &a, Task &b)
    {
        return a.priority > b.priority;
    }
};

class mangeTask{
    private :
    priority_queue <Task, vector<Task>,Taskcompare> ListOfTask;
    protected:
        int taskNo=0;
        void loadTask();
        void saveTask();
    public:
    mangeTask();
    void showMenu();
    void addtask();
    void showTask();
    void deleteTask();
    void completedTask();

 };

 mangeTask::mangeTask(){
    loadTask();
 }

void mangeTask::showMenu(){
    cout<<"--------------------------------------------------"<<endl;
    while(true){
    cout << "1. Add Task" << endl;
    cout << "2. Show Task" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Completed Task" << endl;
    cout << "5. Exit" << endl;
    cout<<"--------------------------------------------------"<<endl;
    cout << "Enter your choice: ";
    int choice;
    cin>> choice;
    // system("cls");
    switch (choice)
    {
        case 1:
            addtask();
            saveTask();
            break;
        case 2:
            showTask();
            break;
        case 3:
            deleteTask();
            saveTask();
            break;
        case 4:
            completedTask();
            break;
        case 5:
            saveTask();
            exit(0);
        default:
            cout << "Invalid choice" << endl;
    }
}
}

void mangeTask::loadTask(){
    ifstream file("ToDoList.txt");

    if (file.is_open())
    {
        Task task;
        file>> taskNo;
        file.ignore();
        while (getline(file, task.name))
        {
            getline(file, task.description);
            file >> task.completed;
            file >> task.priority;
            file>> task.id;
            file.ignore();
            ListOfTask.push(task);
        }
        file.close();   
    }
    else
    {
        cout << "Unable to open file";
    }
 }

void mangeTask::saveTask(){
    ofstream file("ToDoList.txt");

    if (file.is_open())
    {
        file << taskNo << endl;
        auto temp = ListOfTask;
        while (!temp.empty())
        {
            Task task = temp.top();
            temp.pop();
            file << task.name << endl;
            file << task.description << endl;
            file << task.completed << endl;
            file << task.priority << endl;
            file << task.id << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void mangeTask::addtask()
{
    cout<<"--------------------------------------------------"<<endl;
    Task task;
    cin >> task;
    task.id = ++taskNo;
    ListOfTask.push(task);
    cout<<"--------------------------------------------------"<<endl;
    cout << "Task added successfully" << endl;
    cout<<"--------------------------------------------------"<<endl;
}

void mangeTask::deleteTask()
{
    if (ListOfTask.empty())
    {
        cout << "No task to delete" << endl;
        return;
    }
    Task task = ListOfTask.top();
    ListOfTask.pop();
    cout << "Task deleted successfully" << endl;
}

void mangeTask::showTask()
{
    cout<<"--------------------------------------------------"<<endl;
    if (ListOfTask.empty())
    {
        cout << "No task to show" << endl;
        return;
    }
    auto temp = ListOfTask;
    while (!temp.empty()){
        Task task = temp.top();
        temp.pop();
        cout << task << endl;
    }
    cout<<"--------------------------------------------------"<<endl;

}

void mangeTask::completedTask()
{
    if (ListOfTask.empty())
    {
        cout << "No task to complete" << endl;
        return;
    }
    Task task = ListOfTask.top();
    ListOfTask.pop();
    task.completed = true;
    cout << "Task completed successfully" << endl;
    ListOfTask.push(task);
}

int main()
{
    mangeTask t1;
    t1.showMenu();
    return 0;
}