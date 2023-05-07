#include<iostream>
#include<cstring>
#include <cctype>
#include <algorithm>
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
    Node* remove(Node* root, int id) 
    {
        if (root == nullptr) 
        {
            return nullptr;
        }
        if (root->id == id) {

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
    void inorder(Node* root)
    {
        if (root == nullptr) {
            return ;
        }
        inorder(root->left);
        cout<<"["<<root->id<<", "<<root->name<<", "<<root->department<<", "<<root->GPA<<"]"<<endl;
        inorder(root->right);
    }
public:
    BST()
    {
        root->left = nullptr;
        root->right = nullptr;
        root->id = -1;
    }
    void insert(int id, string name, string department, float GPA)
    {
        if(root->id == -1)
        {
            root->id = id;
            root->name = name;
            root->department = department;
            root->GPA = GPA;
            Size++;
            return ;
        }
        else
        {
            Node* node = new Node;
            Node* cur = root;
            int len = Size;
            for (int i = 0; i < len; i++)
            {
                if(cur->left == nullptr &&  id <= cur->id)
                {
                    node->id = id;
                    node->name = name;
                    node->department = department;
                    node->GPA = GPA;
                    node->right = nullptr;
                    node->left = nullptr;
                    cur->left = node;
                    Size++;
                    return ;
                }
                else if(cur->right == nullptr && id > cur->id)
                {
                    node->id = id;
                    node->name = name;
                    node->department = department;
                    node->GPA = GPA;
                    node->right = nullptr;
                    node->left = nullptr;
                    cur->right = node;
                    Size++;
                    return ;
                }
                else if(cur->left != nullptr && id <= cur->id)
                {
                    cur = cur->left;
                    continue;
                }
                else if(cur->right != nullptr && id > cur->id)
                {
                    cur = cur->right;
                    continue;   
                }
            }
        }
    }

    bool search(int id)
    {
        Node* cur = root;
        for (int i = 0; i < Size; i++)
        {
            if(root->id == id)
            {
                cout<<"Student Is Found"<<endl;
                cout<<"["<<root->id<<", "<<root->name<<", "<<root->department<<", "<<root->GPA<<"]"<<endl;
                return true ;
            }
            else
            {
                if(cur->id == id)
                {
                    cout<<"Student Is Found"<<endl;
                    cout<<"["<<cur->id<<", "<<cur->name<<", "<<cur->department<<", "<<cur->GPA<<"]"<<endl;
                    return true ;
                }
                else if(cur->left != nullptr && id <= cur->id)
                {
                    cur = cur->left;
                    continue;
                }
                else if(cur->right != nullptr && id > cur->id)
                {
                    cur = cur->right;
                    continue;   
                }
            }
        }
         cout<<"Student Is Not Found"<<endl;
         return false ;
    }


    void removeStudent(int id)
    {
        remove(root,id);

    }

    void print()
    {
       inorder(root);
    }
    

};

//int main()
//{
//    BST a;
//    a.insert(10,"Youssed","IT",3);
//    a.insert(6,"ahmed","CS",2.5);
//    a.insert(5,"abdo","AI",3.5);
//    a.insert(7,"mohamed","IS",2);
//    a.insert(9,"pop","IT",1.5);
//    while(true)
//    {
//        int choice = 0;
//        cout<<"1. Add student\n2. Remove student\n3. Search student\n4. Print All\n5. Return to main menu\n";
//        cin>>choice ;
//        if(choice == 1)
//        {
//            int id;
//            string name;
//            string department;
//            float GPA;
//            cout<<"please enter the id : ";
//            cin >> id ;
//            while(id > 100 || id <= 0)
//            {
//                cout<<"please enter the id in range [0-100] : ";
//                cin >> id ;
//            }
//            while(a.search(id))
//            {
//                cout<<" the id is already exist choose another id\n";
//                cin >> id ;
//            }
//            cout<<"please enter the name : ";
//            cin >> name ;
//            cout<<"please enter the department : ";
//            cin >> department ;
//            transform(department.begin(), department.end(), department.begin(), ::toupper);
//            while (department != "CS" || department != "AI" || department != "IS" || department != "IT")
//            {
//                cout<<"Please enter appropriate department : \n";
//                cin >> department ;
//                transform(department.begin(), department.end(), department.begin(), ::toupper);
//            }
//            
//            cout<<"please enter the GPA : ";
//            cin >> GPA ;
//            while (GPA < 0 || GPA > 4)
//            {
//                cout<<"Please enter appropriate GPA : \n";
//                cin >> GPA ;
//            }
//            a.insert(id,name,department,GPA);
//        }
//        else if (choice == 2)
//        {
//            int id;
//            cout<<"please enter the id : ";
//            cin >> id ;
//            // if(!a.search(id))
//            // {
//            //     continue;
//            // }
//            a.removeStudent(id);
//        }
//        else if (choice == 3)
//        {
//            int id;
//            cout<<"please enter the id : ";
//            cin >> id ;
//            a.search(id);
//        }
//        else if (choice == 4)
//        {
//            a.print();
//        }
//        else
//        {
//            exit(0);
//        }
//    }
//    
//    
//}