#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<cstring>
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;
typedef node* tree;

void display(tree root) {
	if(!root) {
		return;
  }
	display(root->left);
	cout << root->data << ' ';
	display(root->right);
}

void deleteUtil(tree &root) {
	if(!root) { 
		return;
  }
	deleteUtil(root->left);
	deleteUtil(root->right);
	delete(root);
}

void deleteTree(tree &root) {
	deleteUtil(root);
	root = NULL;
}

tree createNode(int key) {
	tree temp = new node;
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}
void createTree(tree &root, int key) {
	tree newNode = createNode(key);
	if(!root) {
		root = newNode;
		return;
  }	
	if(root->data > key) {
		createTree(root->left, key);
  }
	if(root->data < key) {
		createTree(root->right, key);
  }
}	


int main() {
	tree root = NULL;
	int data;
	char ch;
	cout << "Press y to enter data:";
	cin >> ch;
	while(tolower(ch) == 'y') {
		cout << "Enter data:";
		cin >> data;
		createTree(root, data);
	  cout << "Press y to enter more data:";
   	cin >> ch;	
  }
	display(root);
	cout << endl;
	deleteTree(root);
  display(root);
	cout << endl;
	return 0;
}
/* Time Complexity to create BST is O(n) in worst case and Time Cmeplxity to delete the full tree is O(n) */
