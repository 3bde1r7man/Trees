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
    while (true) {

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
        case 1:
        {
            BST a;
            a.BSTMenu();
            break;
        }
        case 2: {
            StudentAVL* avl = new StudentAVL;
            avl->AVLMenu();
            break;
        }

        case 3:
        {
            minArr.clear();
            readFromFile(minArr);
            build_min_heap(minArr);
            minHeapMenu();
            break;
        } 
        case 4:
        {
            maxArr.clear();
            readFromFile(maxArr);
            build_max_heap(maxArr);
            maxHeapMenu();
            break;
        } 
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
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

    if (!count(arr.begin(), arr.end(), id)) {
        arr.push_back(Student(id, gpa, name, dept));
        cout << "The student is added.\n";
    }
    else
    {
        cout << "ID already in use\n";
    }
    
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

StudentAVL::StudentAVL() :root(nullptr), size(0) {
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
        root = insert(root, id, gpa, name, dept);
    }
    dataFile.close();
}

int StudentAVL::getHeight(StudentNode* node)
{
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int StudentAVL::getBalanceFactor(StudentNode* node)
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

StudentNode* StudentAVL::insert(StudentNode* root, int id, float GPA, string name, string dp)
{
    if (root == nullptr) {
        StudentNode* newNode = new StudentNode;
        newNode->id = id;
        newNode->GPA = GPA;
        newNode->name = name;
        newNode->dp = dp;
        newNode->height = 1;
        departments[dp]++;

        size++;
        return newNode;
    }
    if (id < root->id) {
        root->left = insert(root->left, id, GPA, name, dp);
    }
    else {
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

StudentNode* StudentAVL::rotateRight(StudentNode* node)
{
    StudentNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

StudentNode* StudentAVL::rotateLeft(StudentNode* node)
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
    }
    else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            StudentNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            StudentNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
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

StudentNode* StudentAVL::search(StudentNode* root, int id)
{
    if (root == nullptr) {
        return nullptr; // id not found
    }
    if (id == root->id) {
        return root; // id found
    }
    if (id < root->id) {
        return search(root->left, id); // search in left subtree
    }
    else {
        return search(root->right, id); // search in right subtree
    }
}

void StudentAVL::inorder(StudentNode* root)
{
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << "[" << root->id << "," << root->name << "," << root->GPA << "," << root->dp << "]" << endl;
    inorder(root->right);
}

void StudentAVL::saveInFile(StudentNode* root, bool& firstTime, fstream& dataFile) {
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
    StudentNode* student = search(root, id);
    if (student == nullptr) {
        insert(root, id, gpa, name, dept);
        cout << "The student is added.\n";
    }
    else {
        cout << "ID already in use\n";
    }

}

void StudentAVL::removeStudent()
{
    int id;
    cout << "ID: ";
    cin >> id;
    StudentNode* student = search(root, id);
    if (student == nullptr) {
        cout << "Student Not Found!.." << endl;
    }else {
        departments[student->dp]--;
        size--;
        root = deleteNode(root, id);
        cout << "Student Deleted Successfully";
    }

}

void StudentAVL::searchStudent()
{
    int id;
    cout << "ID: ";
    cin >> id;
    StudentNode* student = search(root, id);
    if (student == nullptr) {
        cout << "Student Not Found!.." << endl;
    }
    else {
        cout << "[" << student->id << ", " << student->name << ", " << student->dp << ", " << student->GPA << "]" << endl;
    }
}

void StudentAVL::printStudents()
{
    cout << "Print " << AVLSize()<<" Students."<<endl;
    print();
    cout << "Students per Departments:" << endl;    
    for (map<string, int>::iterator it = departments.begin(); it != departments.end(); it++)
    {
        cout << it->first << " " << it->second << " Students." << endl;
    }
    
}

void StudentAVL::AVLMenu()
{
    while (true) {
        int userIn = 0;
        while (userIn > 5 || userIn < 1) {
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
        case 5:
            return;
        default:
            cout << "Enter Valid Input!.." << endl;
            return;
        }
    }
}

Node* BST::remove(Node* root, int id)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->id == id) {
        departments[root->department]--;
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            Node* right_child = root->right;
            delete root;
            return right_child;
        }
        else if (root->right == nullptr)
        {
            Node* left_child = root->left;
            delete root;
            return left_child;
        }
        else
        {
            Node* replacement = root->left;
            while (replacement->right != nullptr) {
                replacement = replacement->right;
            }
            root->id = replacement->id;
            root->name = replacement->name;
            root->department = replacement->department;
            root->GPA = replacement->GPA;
            root->left = remove(root->left, replacement->id);
            return root;
        }
    }
    else if (id < root->id)
    {
        root->left = remove(root->left, id);
        return root;
    }
    else
    {
        root->right = remove(root->right, id);
        return root;
    }
}
void BST::inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << "[" << root->id << ", " << root->name << ", " << root->department << ", " << root->GPA << "]" << endl;
    inorder(root->right);
}

void BST::readFromFile() {
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
        this->insert(id, name, dept, gpa);
    }
    dataFile.close();
}
BST::BST()
{
    root->left = nullptr;
    root->right = nullptr;
    root->id = -1;
}
void BST::insert(int id, string name, string department, float GPA)
{
    departments[department]++;
    if (root->id == -1)
    {
        root->id = id;
        root->name = name;
        root->department = department;
        root->GPA = GPA;
        Size++;
        return;
    }
    else
    {
        Node* node = new Node;
        Node* cur = root;
        int len = Size;
        for (int i = 0; i < len; i++)
        {
            if (cur->left == nullptr && id <= cur->id)
            {
                node->id = id;
                node->name = name;
                node->department = department;
                node->GPA = GPA;
                node->right = nullptr;
                node->left = nullptr;
                cur->left = node;
                Size++;
                return;
            }
            else if (cur->right == nullptr && id > cur->id)
            {
                node->id = id;
                node->name = name;
                node->department = department;
                node->GPA = GPA;
                node->right = nullptr;
                node->left = nullptr;
                cur->right = node;
                Size++;
                return;
            }
            else if (cur->left != nullptr && id <= cur->id)
            {
                cur = cur->left;
                continue;
            }
            else if (cur->right != nullptr && id > cur->id)
            {
                cur = cur->right;
                continue;
            }
        }
    }
}
bool BST::search(int id)
{
    Node* cur = root;
    for (int i = 0; i < Size; i++)
    {
        if (root->id == id)
        {
            cout << "Student Is Found" << endl;
            cout << "[" << root->id << ", " << root->name << ", " << root->department << ", " << root->GPA << "]" << endl;
            return true;
        }
        else
        {
            if (cur->id == id)
            {
                cout << "Student Is Found" << endl;
                cout << "[" << cur->id << ", " << cur->name << ", " << cur->department << ", " << cur->GPA << "]" << endl;
                return true;
            }
            else if (cur->left != nullptr && id <= cur->id)
            {
                cur = cur->left;
                continue;
            }
            else if (cur->right != nullptr && id > cur->id)
            {
                cur = cur->right;
                continue;
            }
        }
    }
    cout << "Student Is Not Found" << endl;
    return false;
}
void BST::removeStudent(int id)
{
    remove(root, id);

}
void BST::print()
{
    inorder(root);
    cout << "Students per Departments:" << endl;
    for (map<string, int>::iterator it = departments.begin(); it != departments.end(); it++)
    {
        cout << it->first << " " << it->second << " Students." << endl;
    }

}

void BST::BSTMenu() {
    BST a;
    a.readFromFile();
    while (true)
    {
        int choice = 0;
        cout << "1. Add student\n2. Remove student\n3. Search student\n4. Print All\n5. Return to main menu\n";
        cin >> choice;
        if (choice == 1)
        {
            int id;
            string name;
            string department;
            float GPA;
            cout << "please enter the id : ";
            cin >> id;
            while (id > 100 || id <= 0)
            {
                cout << "please enter the id in range [0-100] : ";
                cin >> id;
            }
            while (a.search(id))
            {
                cout << " the id is already exist choose another id\n";
                cin >> id;
            }
            cout << "please enter the name : ";
            cin >> name;
            cout << "please enter the department : ";
            cin >> department;
            cout << "please enter the GPA : ";
            cin >> GPA;
            while (GPA < 0 || GPA > 4)
            {
                cout << "Please enter appropriate GPA : ";
                cin >> GPA;
            }
            a.insert(id, name, department, GPA);
        }
        else if (choice == 2)
        {
            int id;
            cout << "please enter the id : ";
            cin >> id;
            if (!a.search(id))
            {
                continue;
            }
            a.removeStudent(id);
        }
        else if (choice == 3)
        {
            int id;
            cout << "please enter the id : ";
            cin >> id;
            a.search(id);
        }
        else if (choice == 4)
        {
            a.print();
        }
        else if(choice == 5)
        {
            return;
        }
        
    }
}

