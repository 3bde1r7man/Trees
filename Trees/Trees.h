#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int id ;
    string name;
    string department;
    float GPA;
};
class BST{
private:
    Node* root = new Node;
    int Size = 0 ;
    map<string, int> departments;
    Node* remove(Node* root, int id);
    void inorder(Node* root);
    void readFromFile();
public:
    BST();
    void insert(int id, string name, string department, float GPA);
    bool search(int id);
    void removeStudent(int id);
    void print();
    void BSTMenu();
};

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
        out << "[" << stud.ID << ", " << stud.Name << ", " << stud.Dept << ", " << stud.GPA << "]" << endl;
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


struct StudentNode
{
    StudentNode *right;
    StudentNode *left;
    int id;
    float GPA;
    string name;
    string dp;
    int height;
    StudentNode() : right(nullptr), left(nullptr){};
};

class StudentAVL
{
private:
    StudentNode *root;
    map<string, int> departments;
    int size;

public:
    StudentAVL();
    int getHeight(StudentNode *node);
    int getBalanceFactor(StudentNode *node);
    int AVLSize();
    StudentNode *insert(StudentNode *root, int id, float GPA, string name, string dp);
    StudentNode *rotateRight(StudentNode *node);
    StudentNode *rotateLeft(StudentNode *node);
    StudentNode *findMin(StudentNode *root);
    StudentNode *deleteNode(StudentNode *root, int id);
    StudentNode *search(StudentNode *root, int key);
    void inorder(StudentNode *root);
    void saveInFile(StudentNode *root,bool& firstTime, fstream& dataFile);
    void print();
    void addStudent();
    void removeStudent();
    void searchStudent();
    void printStudents();
    void AVLMenu();
};