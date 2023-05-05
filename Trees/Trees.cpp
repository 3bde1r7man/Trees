#include "Trees.h"

template <class T>
void MaxHeapify(vector<T>& arr) {
     int child = arr.size() - 1;
     int parent = (arr.size() - 1) / 2;
     while (arr[child] > arr[parent])
     {
         swap(arr[child], arr[parent]);
         child /= 2;
         parent /= 2;
     }

}

template<class T>
void MinHeapify(vector<T>& arr) {
    int child = arr.size() - 1;
    int parent = (arr.size() - 1) / 2;
    while (arr[child] < arr[parent])
    {
        swap(arr[child], arr[parent]);
        child /= 2;
        parent /= 2;
    }

}

template<class T>
void maxHeapify(vector<T>& arr, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

template<class T>
void build_max_heap(vector<T>& arr) {
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, i, n);
    }
}

template<class T>
void minHeapify(vector<T>& arr, int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest, n);
    }
}

template<class T>
void build_min_heap(vector<T>& arr) {
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(arr, i, n);
    }
}

template<class T>
void heapSort(vector<T>& arr, bool flag) {
    int n = arr.size();
    if (flag) {
        build_max_heap(arr);

        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            maxHeapify(arr, 0, i);
        }
    }
    else {
        build_min_heap(arr);

        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            minHeapify(arr, 0, i);
        }
    }
}

void Menu::mainMenu() {
    int n;
    while (true)
    {
        cout << "1. BST\n";
        cout << "2. AVL\n";
        cout << "3. Min Heap\n";
        cout << "4. Max Heap\n";
        cout << "5. Exit Program\n";
        cout << "--> ";
        cin >> n;
        if (n >= 1 && n < 6)
            break;
    }
    switch (n)
    {
    case 3:
        minHeapMenu();
        break;
    case 4:
        maxHeapMenu();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}

void Menu::saveAtFile(vector<Student>& arr) {
    fstream dataFile;
    dataFile.open("data.txt", ios::out);
    for (int i = 0; i < arr.size(); i++) {
        dataFile << arr[i].getID();
        dataFile << endl;
        dataFile << arr[i].getName();
        dataFile << endl;
        dataFile << arr[i].getGPA();
        dataFile << endl;
        dataFile << arr[i].getDept();
        dataFile << endl;
    }
    dataFile.close();
}

void Menu::readFromFile(vector<Student>& arr) {
    fstream dataFile;
    string temp;
    int id;
    float gpa;
    string name, dept;
    dataFile.open("data.txt", ios::in);
    while (!dataFile.eof() && dataFile.peek() != EOF) {
        getline(dataFile, temp);
        id = stoi(temp);
        getline(dataFile, temp);
        name = temp;
        getline(dataFile, temp);
        gpa = stof(temp);
        getline(dataFile, temp);
        dept = temp;
        arr.push_back(Student(id, gpa, name, dept));
    }
    dataFile.close();
}

void Menu::minHeapMenu() {
    int n;
    minArr.clear();
    readFromFile(minArr);
    while (true)
    {
        cout << "1. Add student\n";
        cout << "2. Print All(sorted by gpa)\n";
        cout << "3. Return to main menu\n";
        cout << "--> ";
        cin >> n;
        if (n < 4 && n > 0)
            break;
    }
    switch (n)
    {
    case 1:
        addStud(minArr);
        MinHeapify(minArr);
        saveAtFile(minArr);
        break;
    case 2:
        printAll(minArr, 1);
        break;
    case 3:
        mainMenu();
        break;
    default:
        break;
    }
    minHeapMenu();
}

void Menu::maxHeapMenu() {
    int n;
    maxArr.clear();
    readFromFile(maxArr);
    while (true)
    {
        cout << "1. Add student\n";
        cout << "2. Print All(sorted by gpa)\n";
        cout << "3. Return to main menu\n";
        cout << "--> ";
        cin >> n;
        if (n < 4 && n > 0)
            break;
    }
    switch (n)
    {
    case 1:
        addStud(maxArr);
        MaxHeapify(maxArr);
        saveAtFile(maxArr);
        break;
    case 2:
        printAll(maxArr, 0);
        break;
    case 3:
        mainMenu();
        break;
    default:
        break;
    }
    maxHeapMenu();
}

void Menu::addStud(vector<Student>& arr) {
    int id;
    float gpa;
    string name, dept;

    cout << "Id: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "GPA: ";
    cin >> gpa;
    cout << "Department: ";
    cin >> dept;
    arr.push_back(Student(id, gpa, name, dept));
    cout << "The student is added.\n";
}

void Menu::printAll(vector<Student>& arr, bool sort) {
    if (sort) {
        heapSort(arr, 1);
    }
    else
    {
        heapSort(arr, 0);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
}