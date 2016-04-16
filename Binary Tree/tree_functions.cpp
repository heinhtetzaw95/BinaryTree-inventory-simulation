#include <string>
#include <iomanip>

#include "tree_header.h"

bool tree::add(item) {

	return true;
}

bool tree::del(item) {

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

static void print(char type) {
	switch (type){
	case 'E':
		output << "Printing All" << endl;
		output << "New Page" << endl;

		break;

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

static void print(char type, bool success, item theItem) {
	switch (type) {
	case 'A':

		if (success) output << "Item ID Number " << theItem.ID
							<< " successfully entered into database." << endl;

		else output << "ERROR - Attempt to insert a duplicate item (" << theItem.ID
					<< ") into the database." << endl;

		print('-');

		break;
		
	case 'D':

		if (success) output << "Item ID Number  " << theItem.ID 
							<< " successfully deleted from database." << endl;

		else output << "ERROR-- - Attempt to delete an item (  " << theItem.ID
					<< ") not in the database list." << endl;

		print('-');

		break;

	case 'N':

		if (success) {
			output << theItem.ID
				<< theItem.description
				<< theItem.onHand
				<< theItem.onOrder << endl;

			output << "Printing THIS Item!" << endl;
		}

		else output << "Item (" << theItem.ID << ") not in database. Print failed." << endl;

		print('-');

		break;

	case 'S':

		if (success) output << "Quantity on Order For item (" << theItem.ID
							<< ") successfully updated." << endl;

		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		print('-');

		break;

	case 'O':

		if (success) output << "Quantity on Hand for item (" << theItem.ID
							<< ") successfully updated." << endl;

		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		print('-');

		break;

	case 'R':

		if (success) output << "Quantity on Hand for item (" << theItem.ID
							<< ") successfully updated." << endl;

		else output << "Item (" << theItem.ID << ") not in database. Data not updated." << endl;

		print('-');

		break;

	}

	return;
}