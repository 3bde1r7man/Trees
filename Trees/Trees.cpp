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
    while (true){

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
        case 2:{
            StudentAVL *avl = new StudentAVL;
            avl->AVLMenu();
            break;
        }

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
    build_min_heap(minArr);
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
    build_max_heap(maxArr);
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

StudentAVL::StudentAVL():root(nullptr),size(0){
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
        root = insert(root,id, gpa, name, dept);
    }
    dataFile.close();
}

int StudentAVL::getHeight(StudentNode *node)
{
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int StudentAVL::getBalanceFactor(StudentNode *node)
{
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int StudentAVL::AVLSize()
{
    return size;
}

StudentNode* StudentAVL::insert(StudentNode* root,int id,float GPA,string name,string dp)
{
        if (root == nullptr) {
        StudentNode* newNode = new StudentNode;
        newNode->id = id;
        newNode->GPA = GPA;
        newNode->name = name;
        newNode->dp = dp;
        newNode->height = 1;
        size++;
        return newNode;
    }
    if (id < root->id) {
        root->left = insert(root->left, id, GPA, name, dp);
    } else {
        root->right = insert(root->right, id, GPA, name, dp);
    }
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1 && id < root->left->id) {
        return rotateRight(root);
    }
    if (balanceFactor < -1 && id > root->right->id) {
        return rotateLeft(root);
    }
    if (balanceFactor > 1 && id > root->left->id) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balanceFactor < -1 && id < root->right->id) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

StudentNode* StudentAVL::rotateRight(StudentNode *node)
{
    StudentNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

StudentNode* StudentAVL::rotateLeft(StudentNode *node)
{
    StudentNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}


StudentNode* StudentAVL::findMin(StudentNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

StudentNode* StudentAVL::deleteNode(StudentNode* root, int id) {
    if (root == nullptr) {
        return root;
    }
    if (id < root->id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            StudentNode* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            StudentNode* temp = root;
            root = root->left;
            delete temp;
        } else {
            StudentNode* temp = findMin(root->right);
            root->id = temp->id;
            root->right = deleteNode(root->right, temp->id);
        }
    }
    if (root == nullptr) {
        return root;
    }
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rotateRight(root);
    }
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

StudentNode *StudentAVL::search(StudentNode *root, int id)
{
    if (root == nullptr) {
        return nullptr; // id not found
    }
    if (id == root->id) {
        return root; // id found
    }
    if (id < root->id) {
        return search(root->left, id); // search in left subtree
    } else {
        return search(root->right, id); // search in right subtree
    }
}

void StudentAVL::inorder(StudentNode *root)
{
        if (root == nullptr) {
            return ;
        }
        inorder(root->left);
        cout<<"["<<root->id<<","<<root->name<<","<<root->GPA<<","<<root->dp<<"]"<<endl;
        inorder(root->right);
}

void StudentAVL::saveInFile(StudentNode *root, bool& firstTime, fstream& dataFile) {
    if (firstTime) {
        dataFile.open("data.txt", ios::out);
        firstTime = false;
    }
    if (root == nullptr) {
        return;
    }
    saveInFile(root->left, firstTime, dataFile);
    dataFile << root->id << endl;
    dataFile << root->name << endl;
    dataFile << root->GPA << endl;
    dataFile << root->dp << endl;
    saveInFile(root->right, firstTime, dataFile);
}

void StudentAVL::print()
{
    inorder(root);
}

void StudentAVL::addStudent()
{
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
    StudentNode *student = search(root, id);
    if(student==nullptr){
        insert(root,id,gpa,name,dept);
        cout << "The student is added.\n";
    }else{
        cout << "ID already in use";
    }

}

void StudentAVL::removeStudent()
{
    int id;
    cout << "ID: ";
    cin >> id;
    StudentNode *student = search(root, id);
    if(student==nullptr){
        cout << "Student Not Found!.." << endl;
    }else{
        root = deleteNode(root, id);
        cout << "Student Deleted Successfully";
    }
    
}

void StudentAVL::searchStudent()
{
    int id;
    cout << "ID: ";
    cin >> id;
    StudentNode *student = search(root, id);
    if(student == nullptr){}
}

void StudentAVL::printStudents()
{
    cout << "Size of Students is: " << AVLSize()<<endl;
    print();
}

void StudentAVL::AVLMenu()
{
    while (true){
        int userIn=0;
        while(userIn>5 || userIn<1){
            cout << "1-Add student\n";
            cout << "2-Remove student\n";
            cout << "3-Search student\n";
            cout << "4-Print All students\n";
            cout << "5-Return to main menu\n";
            cout << "--> ";
            cin >> userIn;
        }
        switch (userIn)
        {
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            printStudents();
            break;
        case 5:{
            bool firstTime = true; 
            fstream dataFile;
            saveInFile(root, firstTime,dataFile);
            dataFile.close();
            return;
            }
        default:
            cout << "Enter Valid Input!.."<<endl;
            return;
        }
    }
}


