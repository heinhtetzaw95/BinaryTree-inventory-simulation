#ifndef TREE_HEADER_H_
#define TREE_HEADER_H_

#include <string>
#include <fstream>

using namespace std;

			//create variables to access input and output files
	static ifstream input("tree_sample.txt", ios::in);
	static ofstream output("output_sample.txt", ios::out);

struct item {
	string ID, description;
	int onHand, onOrder, quantity;

	item *left, *right;
};

class tree {
private:
	item *root;

public:
	tree() { root = NULL; }

	bool add(item);
	bool del(item);
	bool sell(item);
	bool order(item);
	bool receive(item);
	bool patchParent(item*, item*, item*);

	item * search(item);
	item * getRoot() { return root; };

};

#endif // !TREE_HEADER_H_

