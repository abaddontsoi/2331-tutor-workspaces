#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;
  
/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node
{
    int data;
    Node* left, * right;
};
  
/*Function for creating a new Node structure */
Node* newNode(int data)
{
    Node* node = new Node;
    //Node* node = (Node*)malloc(sizeof(Node)); //will also work.
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
  
// Function to insert nodes in level order. This function takes an array-based tree representation as input and
// convert it into a linked list-based tree representation
Node* insertLevelOrder(vector<int> tree_vec,
                       //tree_vec: array implementation, create node for position i.
                       int i, int n)
{
      Node *root = nullptr;
    // Base case for recursion
    if (i < n)
    {
        root = newNode(tree_vec[i]);
          
        // insert left child
        root->left = insertLevelOrder(tree_vec,
                   2 * i + 1, n);
  
        // insert right child
        root->right = insertLevelOrder(tree_vec,
                  2 * i + 2, n);
    }
    return root;
}
  
// Example code for InOrder traversal
void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}

void preOrder(Node* root){
    if (root) {
        cout << root->data <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data <<" ";
    }
}

int getLeafCount(Node* root){
    if (!(root->left || root->right)) {
        return 1;
    }
    if(root->left && root->right)
        return getLeafCount(root->left)+getLeafCount(root->right);
    if (root->left) {
        return getLeafCount(root->left);
    }
    if(root->right)
        return getLeafCount(root->right);
    return 0;
}

int main()
{
    vector<int> tree_vec;
    string file_name;
    int temp_data;
    cout << "Please input the file name of a complete binary tree:";
    cin >> file_name;
    ifstream tree_file(file_name, ios::in);

    if(tree_file.fail())
    {
        cout << "Fail to open the tree file.";
        return 0;
    }
    
    while (!tree_file.fail() && !tree_file.eof())
    {
        tree_file >> temp_data;
        tree_vec.push_back(temp_data);
    }
    
    /*Transform the array-based tree into linked-list in level-order.*/
    Node* root = insertLevelOrder(tree_vec, 0, tree_vec.size());
    
    /*Task 1, to be implemented*/
    cout << "The Preorder Traversal result is: " << endl;
    preOrder(root);
    cout << endl;

    /*Example implementation*/
    cout << "The Inorder Traversal result is: " << endl;
    inOrder(root);
    cout << endl;
    
    /*Task 2, to be implemented*/
    cout << "The Postorder Traversal result is: " << endl;
    postOrder(root);
    cout << endl;
    
    /*Task 3, to be implemented*/
    cout << "The number of leaf nodes is: " << endl;
    cout << getLeafCount(root)<<endl;
    
    return 0;
}
  
