#include <string>
#include <iomanip>

#include "tree_header.h"

static bool check(char command) {

		// Receives – A command word
		// Task - Check if the command word is valid
		// Returns - Message whether or not valid command

			//check the command and return valid
	switch (command) {
	case 'I': return true;
	case 'D': return true;
	case 'P': return true;
	case 'S': return true;
	case 'O': return true;
	case 'R': return true;
	}
			//return not valid
	return false;
}

//*****************************************************************************************************
static bool traverseTree(item *current) {

		// Receives – A pointer to a node
		// Task - Considering the recieved node is root and print every node below it
		// Returns - Whether or not the received node is valid

	if (current != NULL) {
		traverseTree(current->left);

		output << "   "
			<< setw(11) << left << current->ID
			<< setw(25) << left << current->description
			<< setw(6) << right << current->onHand
			<< setw(11) << right << current->onOrder << endl;
		
		traverseTree(current->right);
	}
	else return false;
	return true;
}

//*****************************************************************************************************
static void print(char type) {

		// Receives – A letter describing what to print
		// Task - Print the messages according to the letter received
		// Returns - Nothing

	switch (type) {
	case 'H':
				//print the header of a list for letter 'H'
		output
					//print title
			<< setw(45) << right << "JAKE’S HARDWARE INVENTORY REPORT" << endl

					//print first header line
			<< setw(7) << right << "Item"
			<< setw(14) << right << "Item"
			<< setw(27) << right << "Quantity"
			<< setw(11) << right << "Quantity" << endl

					//print second header line
			<< setw(10) << right << "ID Number"
			<< setw(15) << right << "Description"
			<< setw(22) << right << "On Hand"
			<< setw(12) << right << "On Order" << endl;

				//print 60 '-'s after titles
		print('-');

		break;

	case '-':
				//print 60 '-'s for character '-'
		for (int i = 0; i < 60; i++) output << '-';
		output << endl;

		break;
	}

	return;
}

//*****************************************************************************************************
static void print(char type, tree *theTree) {

		// Receives – A letter description what to print and the pointer of a tree
		// Task - Prints the list of all entries that is in the tree
		// Returns - Nothing

	if (type == 'E') {
				//print the whole tree as a list, print error if there is no tree
		if (!traverseTree(theTree->getRoot())) output << "Error -- No Entry Found!"<< endl;
	}
	return;
}

//*****************************************************************************************************
static void print(char type, bool success, item theItem) {

		// Receives – A letter description what to print, success or failure message, and the item
		// Task - Prints messages according to the input
		// Returns - Nothing

	switch (type) {

			//print Adding related message for letter 'A'
	case 'A':
				//print for success
		if (success) output << "Item ID Number " << theItem.ID
			<< " successfully entered into database." << endl;

				//print for failure
		else output << "ERROR - Attempt to insert a duplicate item (" << theItem.ID
			<< ") into the database." << endl;

		break;

			//print Deletion related message for letter 'D'
	case 'D':
				//print for success
		if (success) output << "Item ID Number (" << theItem.ID
			<< ") successfully deleted from database." << endl;

				//print for failure
		else output << "ERROR --- Attempt to delete an item (" << theItem.ID
					<< ") not in the database list." << endl;

		break;

			//print a given node from the tree
	case 'N':

				//print the item
		if (success) output << "   "
							<< setw(11) << left << theItem.ID
							<< setw(25) << left << theItem.description
							<< setw(6) << right << theItem.onHand
							<< setw(11) << right << theItem.onOrder << endl;

				//print error for failure
		else output << "Item (" << theItem.ID << ") not in database. Print failed." << endl;

		break;

			//print Selling related message for letter 'S'
	case 'S':

				//print for success
		if (success) output << "Quantity on Hand For item (" << theItem.ID 
							<< ") successfully updated" << endl;

				//print for failure
		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		break;

			//print Ordering related message for letter 'O'
	case 'O':

				//print for success
		if (success) output << "Quantity on Order For item (" << theItem.ID
							<< ") successfully updated." << endl;

				//print for failure
		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		break;

			//print Receiving related messages for letter 'R'
	case 'R':

				//print for success
		if (success) output << "Quantity on Hand for item (" << theItem.ID
							<< ") successfully updated." << endl;

				//print for failure
		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		break;
	}

	return;
}

//*****************************************************************************************************
static void header() {

		// Receives – the output file
		// Task - Prints the output preamble
		// Returns - Nothing

	output << setw(33) << "Hein Htet Zaw";
	output << setw(15) << "CSC 36000";
	output << setw(15) << "Section 11" << endl;
	output << setw(37) << "Spring 2016";
	output << setw(20) << "Assignment #7" << endl;
	output << setw(38) << "-------------------------------------------";
	output << setw(38) << "------------------------------------------\n\n";

	return;
}

//*****************************************************************************************************
static void footer() {

		// Receives – the output file
		// Task - Prints the output salutation
		// Returns - Nothing

	output << endl;
	output << setw(35) << "----------------------------------" << endl;
	output << setw(35) << "|      END OF PROGRAM OUTPUT     |" << endl;
	output << setw(35) << "----------------------------------" << endl;

	return;
}
//*****************************************************************************************************
