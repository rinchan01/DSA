#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int ID;
    string name;
    string classroom;

    Student();
    Student(int id, string name, string classroom);
    int getID();
    string getName();
    string getClass();
    void setStudent(int id, string name, string classroom);
};

Student :: Student() {
    ID = 0;
    name = "";
    classroom = "";
}

void Student :: setStudent(int id, string name, string classroom) {
    this->ID = id;
    this->name = name;
    this->classroom = classroom;
}

string Student :: getClass() {
    return classroom;
}

string Student :: getName() {
    return name;
}

int Student :: getID() {
    return ID;
}

vector<Student> list;
string res = "";

void Insert(int id, string name, string classroom) {
    Student newStudent;
    newStudent.setStudent(id, name, classroom);
    list.push_back(newStudent);
}

void Delete(int id) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].ID == id) {
            list.erase(list.begin() + i);
        }
    }
}

void Infor(int id) {
    if (id-1 >= list.size() || id-1 < 0) {
        res += "NA, NA\n";
    } else {
        res += (list[id-1].getName() + ", " + list[id-1].getClass() + "\n");
    }
}

int main() {
    int ID;
    string name = "";
    string classroom = "";
    string commandLine;
    int total;
    cin >> total;

    for (int i = 0; i < total; i++) {
        cin >> commandLine;
        int j = 0;
        string command = "";

        // check the command
        while (commandLine[j] != '(') {
            command += commandLine[j];
            j++;
        }

        if (command == "Insert") {

            // set j as index of char of commandLine
            j++;
            string id = "";

            // check the id from command
            while (commandLine[j] != ',') {
                id += commandLine[j];
                j++;
            }
            ID = stoi(id);
            
            // check the name from command
            j++;
            while (commandLine[j] != ',') {
                name += commandLine[j];
                j++;
            }

            //check the classroom from command
            j++;
            while (commandLine[j] != ')') {
                classroom += commandLine[j];
                j++;
            }
            Insert(ID, name, classroom);  
        } else if (command == "Delete") {
            j++;
            string id;
            while (commandLine[j] != ')') {
                id += commandLine[j];
                j++;
            }
            ID = stoi(id);
            Delete(ID);
        } else {
            j++;
            string id;
            while (commandLine[j] != ')') {
                id += commandLine[j];
                j++;
            }
            ID = stoi(id);
            Infor(ID);
        }
    }
    cout << res;
    return 0;
}