#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Student{
private:
	int ID;
	float GPA;
	string Name, Dept;
public:
	Student(int id, float gpa, string name, string dept): ID(id), GPA(gpa), Name(name), Dept(dept) {}
	
    bool operator>(Student& other) {
		return GPA > other.GPA;
	}

    bool operator<(Student& other) {
        return GPA < other.GPA;
    }

    string getName() {
        return Name;
    }
    
    float getGPA() {
        return GPA;
    }
    
    string getDept() {
        return Dept;
    }

    int getID() {
        return ID;
    }

	

    friend ostream& operator<<(ostream& out, Student& stud) {
        out << "ID: " << stud.ID << ", Name: " << stud.Name << ", Department: " << stud.Dept << ", GPA: " << stud.GPA;
        return out;
    }
};


template <class T>
void MaxHeapify(vector<T>& arr);

template <class T>
void MinHeapify(vector<T>& arr);

template <class T>
void maxHeapify(vector<T>& arr, int i, int n);

template <class T>
void build_max_heap(vector<T>& arr);

template <class T>
void minHeapify(vector<T>& arr, int i, int n);

template <class T>
void build_min_heap(vector<T>& arr);




template <class T>
void heapSort(vector<T>& arr, bool flag);

class Menu
{

    vector<Student> minArr;
    vector<Student> maxArr;
public:
    Menu()
    {
        mainMenu();
    }

    void mainMenu();


    void saveAtFile(vector<Student>& arr);

    void readFromFile(vector<Student>& arr);


    void minHeapMenu();

    void maxHeapMenu();

    void addStud(vector<Student>& arr);

    void printAll(vector<Student>& arr, bool sort);
};

