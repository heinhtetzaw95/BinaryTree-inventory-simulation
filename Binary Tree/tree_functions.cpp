#include <iostream>
#include "tree_header.h"

bool tree::add(item theItem) {

		// Receives – The item to insert
		// Task - Insert the item into the tree
		// Returns - Whether or not success

			//reserve vrequired variables
	bool inserted = false;
	item *newPointer, *currentPointer;

			//instantiate the variables
	newPointer = new item;

			//if a new pointer is successfully created (no memory outage)
	if (newPointer != NULL) {

				//copy the information from given item in a new node 
		newPointer->ID = theItem.ID;
		newPointer->description = theItem.description;
		newPointer->onHand = theItem.onHand;
		newPointer->onOrder = theItem.onOrder;

				//set left and right pointers to NULL for new node
		newPointer->left = NULL;
		newPointer->right = NULL;

				//the first ever node is root
		currentPointer = root;

				//loop if not inserted yet
		while (inserted == false) {

					//put the node in root if the root is empty
			if (currentPointer == NULL) {
				root = newPointer;
				inserted = true;
			}

					//reject the item if the same item information is already in the tree
			else if (newPointer->ID.compare(currentPointer->ID) == 0) return false;

					//branch to left if the new node is less than current node
			else if (newPointer->ID.compare(currentPointer->ID) < 0) {
						
						//extend branch from the free side
				if (currentPointer->left != NULL) currentPointer = currentPointer->left;
				else {
					currentPointer->left = newPointer;
					inserted = true;
				}
			}

					//branch to right side if the new node is higher than current one
			else {

						//extend the branch from the free side
				if (currentPointer->right != NULL) currentPointer = currentPointer->right;
				else {
					currentPointer->right = newPointer;
					inserted = true;
				}
			}
		}
	}
	return true;
}

//*****************************************************************************************************
void tree::patchParent(item *newParent, item *parent, item *toDel) {

		// Receives – The new parent pointer, current parent pointer, and pointer to node to delete
		// Task - Exchange the nodes to make sure the parent gets into correct location
		// Returns - Nothing

	if (parent == NULL)	root = newParent;
	else if (parent->left == toDel) parent->left = newParent;
	else parent->right = newParent;

	return;
}

//*****************************************************************************************************
bool tree::del(item theItem) {

		// Receives – The information of the node to delete
		// Task - Deletes the node from the tree
		// Returns - Whether or not the deletion success

			//declare required variables and instantiate
	item *toDel, *parent, *node1, *node2, *node3;
	bool found = false;

			//set very first node to check to root
	toDel = root;
	parent = NULL;			//set NULL since root has no parent

			//check if the node exists in the tree
	while (found == false && toDel != NULL) {

				//set found flag if it exists
		if (theItem.ID.compare(toDel->ID) == 0) found = true;

				//search the whole tree until it is found or till ends
		else {
			parent = toDel;
			if (theItem.ID.compare(toDel->ID) < 0) toDel = toDel->left;
			else toDel = toDel->right;
		}
	}

			//return failure if node doesn't exist in the tree (Case-1)
	if (found == false) {
		return false;
	}

			//delete the node if exists
	else {
		if (toDel->left == NULL) {

					//turn back if the node has no child (Case-2)
			if (toDel->right == NULL) patchParent(NULL, parent, toDel);

					//follow right if the node has only right child (Case-3)
			else patchParent(toDel->right, parent, toDel);
		}
		else {
					//follow left if the node has only left child (Case-4)
			if (toDel->right == NULL) patchParent(toDel->left, parent, toDel);

					//do swapping and replacing jobs when the node has both children (Case-5)
			else {
						//maintain the left child
				node1 = toDel;
				node2 = toDel->left;
				node3 = node2->right;

						//search the appropiate place to replace
				while (node3 != NULL) {
					node1 = node2;
					node2 = node3;
					node3 = node3->right;
				}

						//delete the node if it is the one
				if (node1 != toDel) {
					node1->right = node2->left;
					node2->left = toDel->left;
				}

						//maintain the right child
				node2->right = toDel->right;
				patchParent(node2, parent, toDel);
			}
		}
	}

	return true;
}

//*****************************************************************************************************
bool tree::sell(item theItem) {

		// Receives – The information for item to sell and quantity to sell
		// Task - Simulate selling for given item
		// Returns - Whether or not success

			//check if the item exists
	item *toChange = search(theItem);
	
			//return failure if item doesn't exists in the tree
	if (toChange == NULL) return false;

			//sell given quantity of given item
	toChange->onHand -= theItem.quantity;

			//return success
	return true;
}

//*****************************************************************************************************
bool tree::order(item theItem) {

		// Receives – The information for item to order and quantity to order
		// Task - Simulate ordering for given item
		// Returns - Whether or not success

			//check if the item exists
	item *toChange = search(theItem);

			//return failure if item doesn't exists in the tree
	if (toChange == NULL) return false;

			//order given quantity of given item
	toChange->onOrder += theItem.quantity;

			//return success
	return true;
}

//*****************************************************************************************************
bool tree::receive(item theItem) {

		// Receives – The information for item received and quantity received
		// Task - Simulate receiving for given item
		// Returns - Whether or not success

			//check if the item exists
	item *toChange = search(theItem);

			//return failure if item doesn't exists in the tree
	if (toChange == NULL) return false;

			//simulate receive given quantity of given item
	toChange->onOrder -= theItem.quantity;
	toChange->onHand += theItem.quantity;

			//return success
	return true;
}

//*****************************************************************************************************
item * tree::search(item theItem) {

		// Receives – Information of an item
		// Task - Search the item in the tree
		// Returns - The pointer of the node if found, NULL pointer if not found

			//begin at root
	item *current = root;
	
			//go through the whole tree
	while (current != NULL) {

				//return the node if found
		if (theItem.ID.compare(current->ID) == 0) return current;

				//keep searching till found or the end
		else {
			if (theItem.ID.compare(current->ID) < 0) current = current->left;
			else current = current->right;
		}
	}

			//return NULL pointer if not found
	return NULL;
}

//*****************************************************************************************************
