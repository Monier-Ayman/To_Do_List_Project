/*
  Simple C++ To-Do List
  Author: Monier Ayman
  Description: A console-based To-Do List with add, edit, delete, sort, search, and count features.
*/
#include <bits/stdc++.h>
using namespace std;

struct Task{
    string name;
    bool done;
};

vector<Task> tasks;

void ShowTasks(){
    cout << "\nCurrent Tasks:\n";
    for(int i=0 ; i<tasks.size() ; i++){
        cout<< i+1 << ". [" << (tasks[i].done? "x" : " ")<<"] " << tasks[i].name<<"\n";
    }
}

// 1. Add a Task:
void Add(){
    string x;
    cout<<"Enter task: ";
    cin.ignore();
    getline(cin, x);

    Task t;
    t.name= x;
    t.done= false;
    tasks.push_back(t);

    cout << "Task added successfully!\n";
}

// 2. View All Tasks:
void View(){
    if(tasks.size()==0){
        cout<<"No tasks yet.\n";
    }
    else{
        ShowTasks();
    }

}

// 3. Mark Task as Done:
void MarkDone(){
    if(tasks.size()==0){
        cout<< "No tasks yet.\n";
        return;
    }

    ShowTasks();

    int index;
    cout<< "Enter task number to mark as done: ";
    cin>> index;

    if(index< 1 || index>tasks.size()){
        cout << "Invalid task number!\n";
        return;
    }

    tasks[index-1].done= true;

    cout << "Task marked as done!\n";
}

// 4. Edit a Task:
void Edit(){
    if(tasks.size()==0){
        cout<< "No tasks to edit.\n";
        return;
    }

    ShowTasks();

    int index;
    cout<< "Enter task number to edit: ";
    cin>> index;

    if(index< 1 || index>tasks.size()){
        cout << "Invalid task number!\n";
        return;
    }

    cin.ignore(); 
    string newName;
    cout<< "Enter new task name: ";
    getline(cin, newName);

    tasks[index-1].name= newName;

    cout<< "Task updated successfully!\n";
}

// 5. Delete a Task:
void DeleteTask(){
    if(tasks.size()==0){
        cout<< "No tasks to delete.\n";
        return;
    }

    ShowTasks();

    int index;
    cout<< "Enter task number to delete: ";
    cin>> index;

    if(index<1 || index>tasks.size()){
        cout<< "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + index-1);

    cout<< "Task deleted successfully!\n";
}

// 6. Sort Tasks (A-Z): (Bubble Sort)
void BubbleSort(){
    int n= tasks.size();
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(tasks[j].name > tasks[j+1].name){
                swap(tasks[j], tasks[j+1]);
            }
        }
    }

    cout<< "Tasks sorted alphabetically!\n";
}

// 7. Search Tasks: (Binary search function)
// The tasks are first sorted alphabetically using Bubble Sort.
// Binary search is then used to find a task by its exact name.
// This demonstrates understanding of sorting and searching algorithms.
void SearchTask(){
    if(tasks.size()==0){
        cout<< "No tasks to search.\n";
        return;
    }

    cin.ignore();
    string key;
    cout<< "Enter task name to search: ";
    getline(cin, key);

    BubbleSort();

    int left= 0, right= tasks.size()-1;
    bool found= false;

    while(left<=right){
        int mid= left+(right-left)/2;
        if(tasks[mid].name==key){
            cout<< "Task found: "<< tasks[mid].name << " [" << (tasks[mid].done ? "x" : " ") << "]\n";
            found= true;
            break;
        }
        else if(tasks[mid].name < key){
            left= mid+1;
        }
        else{
            right= mid-1;
        }
    }

    if(!found){
        cout<< "Task not found!\n";
    }
}

// 8. Count Tasks:
void CountTasks(){
    int total= tasks.size();
    int doneCount= 0;

    for(int i=0 ; i<total ; i++){
        if(tasks[i].done){
            doneCount++;
        }    
    }

    cout<< "Total tasks: "<< total << "\n";
    cout<< "Completed tasks: "<< doneCount << "\n";
    cout<< "Pending tasks: "<< total-doneCount << "\n";
}

int main(){
    while(true){
        cout<< "\n--- SIMPLE TO-DO LIST ---\n";
        cout<< "1. Add a Task\n";
        cout<< "2. View All Tasks\n";
        cout<< "3. Mark Task as Done\n";
        cout<< "4. Edit a Task\n";
        cout<< "5. Delete a Task\n";
        cout<< "6. Sort Tasks (A-Z)\n";
        cout<< "7. Search Tasks\n";
        cout<< "8. Count Tasks\n";
        cout<< "9. Exit\n";
        cout<< "Choose: ";
 
        int choice;
        cin>> choice;

        if(choice==1){
            Add();
        }
        else if(choice==2){
            View();
        }
        else if(choice==3){
            MarkDone();
        }
        else if(choice==4){
            Edit();
        }
        else if(choice==5){
            DeleteTask();
        }
        else if(choice==6){
            BubbleSort();
        }
        else if(choice==7){
            SearchTask();
        }
        else if(choice==8){
            CountTasks();
        }
        else if(choice==9){  
            cout<< "Exiting program. Goodbye!\n";
            break; 
        }
        else{
            cout<< "Invalid choice!\n";
        }

    }    

    return 0;
}
