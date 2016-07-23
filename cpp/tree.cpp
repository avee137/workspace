#include <iostream>


using namespace std ;


/*
 *Basics -
 *creation of binary search tree class
 *basic operations - creation, search a node, insert, delete
 *BFS (breadth first search), DFS(depth first search)
 *traversal - inorder, preorder, postorder
 *
 */


class Node {
	public:
		int getNodeVal(void);
		Node(int val);//ctr
		bool findNode(void);
		void* insertNode(Node* node);

	private:
		int val;
		Node *lChild;
		Node *rChild;
};

Node::Node (int val) {
	this->val = val;
}

int main(){
	Node *BSTree = NULL;

	return 0;
}
