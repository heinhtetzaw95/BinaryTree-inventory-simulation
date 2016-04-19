#ifndef TREE_HEADER_H_
#define TREE_HEADER_H_

#include <string>
#include <fstream>

using namespace std;

			//create variables to access input and output files
	static ifstream input("tree_in.txt", ios::in);
	static ofstream output("output.txt", ios::out);

			//construct a structure for items
struct item {
	string ID, description;
	int onHand, onOrder, quantity;

			//include left and right pointers for each node
	item *left, *right;
};

class tree {
		//declare private variables
private:
	item *root;

		//declare public functions
public:
	tree() { root = NULL; }						//make constructor function

	bool add(item);								//make function to add nodes
	bool del(item);								//make function to delete nodes
	bool sell(item);							//make function to simulate selling items
	bool order(item);							//make function to simulate ordering more items
	bool receive(item);							//make function to simulate reciving orders

	void patchParent(item*, item*, item*);		//make function to rearrange the nodes when delete

	item * search(item);						//make function for searching if an item exists
	item * getRoot() { return root; };			//make function for identifying the root node

};

#endif // !TREE_HEADER_H_

