#include <string>
#include <iomanip>

#include "tree_header.h"

static bool check(char command) {
	switch (command) {
	case 'I': return true;
	case 'D': return true;
	case 'P': return true;
	case 'S': return true;
	case 'O': return true;
	case 'R': return true;
	}
	return false;
}

static void traverseTree(item *current) {
	if (current != NULL) {
		traverseTree(current->left);

		output << "    "
			<< setw(16) << left << current->ID
			<< setw(25) << left << current->description
			<< setw(14) << right << current->onHand
			<< setw(14) << right << current->onOrder << endl;
		
		traverseTree(current->right);
	}
	return;
}

static void print(char type) {
	switch (type) {
	case 'H':
		output
			<< setw(55) << right << "JAKE’S HARDWARE INVENTORY REPORT" << endl

			<< setw(8) << right << "Item"
			<< setw(19) << right << "Item"
			<< setw(35) << right << "Quantity"
			<< setw(14) << right << "Quantity" << endl

			<< setw(11) << right << "ID Number"
			<< setw(20) << right << "Description"
			<< setw(30) << right << "On Hand"
			<< setw(15) << right << "On Order" << endl;

		print('-');

		break;

	case '-':
		for (int i = 0; i < 80; i++) output << '-';
		output << endl;

		break;
	}

	return;
}

static void print(char type, tree *theTree) {
	if (type == 'E') {
		traverseTree(theTree->getRoot());
	}
	return;
}

static void print(char type, bool success, item theItem) {
	switch (type) {
	case 'A':

		if (success) output << "Item ID Number " << theItem.ID
			<< " successfully entered into database." << endl;

		else output << "ERROR - Attempt to insert a duplicate item (" << theItem.ID
			<< ") into the database." << endl;

		break;

	case 'D':

		if (success) output << "Item ID Number " << theItem.ID
			<< " successfully deleted from database." << endl;

		else output << "ERROR --- Attempt to delete an item (" << theItem.ID
			<< ") not in the database list." << endl;

		break;

	case 'N':

		if (success) {
			output << "    "
				<< setw(16) << left << theItem.ID
				<< setw(25) << left << theItem.description
				<< setw(14) << right << theItem.onHand
				<< setw(14) << right << theItem.onOrder << endl;
		}

		else output << "Item (" << theItem.ID << ") not in database. Print failed." << endl;

		break;

	case 'S':

		if (success) output << "Quantity on Order For item (" << theItem.ID
			<< ") successfully updated." << endl;

		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		break;

	case 'O':

		if (success) output << "Quantity on Hand for item (" << theItem.ID
			<< ") successfully updated." << endl;

		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		break;

	case 'R':

		if (success) output << "Quantity on Hand for item (" << theItem.ID
			<< ") successfully updated." << endl;

		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		break;

	}

	return;
}
