#include "tree_header.h"

#include <iostream>

bool tree::add(item theItem) {
	bool inserted = false;
	item *newPointer, *currentPointer;
	newPointer = new item;

	if (newPointer != NULL) {
		newPointer->ID = theItem.ID;
		newPointer->description = theItem.description;
		newPointer->onHand = theItem.onHand;
		newPointer->onOrder = theItem.onOrder;

		newPointer->left = NULL;
		newPointer->right = NULL;
		currentPointer = root;

		while (inserted == false) {
			if (currentPointer == NULL) {
				root = newPointer;
				inserted = true;
			}
			else {
				if (theItem.ID.compare(currentPointer->ID) == 0) {
					return false;
				}
				else if (theItem.ID.compare(currentPointer->ID) < 0) {
					if (currentPointer->left != NULL) {
						currentPointer = currentPointer->left;
					}
					else {
						currentPointer->left = newPointer;
						inserted = true;
					}
				}
				else {
					if (currentPointer->right != NULL) currentPointer = currentPointer->right;
					else {
						currentPointer->right = newPointer;
						inserted = true;
					}
				}
			}
		}
	}
	return true;
}

bool tree::patchParent(item *newParent, item *parent, item *del) {
	if (parent == NULL)	root = newParent;
	else if (parent->left == del) parent->left = newParent;
	else parent->right = newParent;

	return true;
}

bool tree::del(item theItem) {
	item *del, *parent, *strNull, *node1, *node2, *node3;
	bool found = false;
	del = root;
	parent = NULL;
	strNull = NULL;

	while ((found == false) && (del != NULL)) {
		if (theItem.ID.compare(del->ID) == 0)
			found = true;
		else {
			parent = del;
			if (del->ID.compare(theItem.ID) < 0) del = del->left;
			else del = del->right;
		}
	}

	if (found == false) {
		return false;
	}
	else {
		if (del->left == NULL) {
			if (del->right == NULL) patchParent(strNull, parent, del);
			else patchParent(del->right, parent, del);
		}
		else {
			if (del->right == NULL) patchParent(del->left, parent, del);
			else {
				node1 = del;
				node2 = del->left;
				node3 = del->right;

				while (node3 != NULL) {
					node1 = node2;
					node2 = node3;
					node3 = node3->right;

					if (node1 != del) {
						node1->right = node2->left;
						node2->left = del->left;

						node2->right = del->right;
						patchParent(node2, parent, del);
					}
				}
			}
		}
	}

	return true;
}
bool tree::sell(item) {

	return true;
}
bool tree::order(item) {

	return true;
}
bool tree::receive(item) {

	return true;
}

item * tree::search(item theItem) {
	item *current = root;
	
	while (current != NULL) {
		if (theItem.ID.compare(current->ID) == 0) return current;

		if (current->left != NULL) current = current->left;
		else current = current->right;
	}
	return NULL;
}
