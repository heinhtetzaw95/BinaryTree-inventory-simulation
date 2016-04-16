#include <iostream>
#include <string>

#include "tree_functions.cpp"

using namespace std;

int main() {
			//prepare for read in each line of given input file
	string temp;
	char command;

			//create a binary tree from the tree class
	tree theTree;

			//read in the very first line and extract the command
	getline(input, temp, '\n');
	command = temp[0];

			//check commands and work accordingly
	while (check(command)) {
		item theItem;

				//work according to the given command
		switch (command) {
		case 'I':
					//insert an item for command 'I'

			cout << "Add" << endl;

			getline(input, theItem.ID, '\n');
			getline(input, theItem.description, '\n');
			getline(input, temp, '\n');
			theItem.onHand = stoi(temp);
			getline(input, temp, '\n');
			theItem.onOrder = stoi(temp);

//			if (theTree.add(theItem))
				print ('A', true, theItem);
//			else print('A', false, theItem);

			break;

		case 'D':
					//delete an item for command 'D'

			getline(input, theItem.ID, '\n');
			getline(input, theItem.description, '\n');

//			if (del(theItem))
				print('D', true, theItem);
//			else print('D', false, theItem);

			break;

		case 'P':
					//print for command 'P'

			getline(input, temp, '\n');

					//print everything for 'E'
			if (temp[0] == 'E') {

				print('H');
				print('E');
				
			}
					//print one particular node for 'N'
			else if (temp[0] == 'N') {
				getline(input, theItem.ID, '\n');

				print('H');
				print('N', true, theItem);

			}

			break;

		case 'S':
					//count items sold for command 'S'

			getline(input, theItem.ID, '\n');
			getline(input, temp, '\n');
			theItem.quantity = stoi(temp);

//			if (sell(theItem))
				print('S', true, theItem);
//			else print('S', false, theItem);

			break;

		case 'O':
					//count items ordered for command 'O'

			getline(input, theItem.ID, '\n');
			getline(input, temp, '\n');
			theItem.quantity = stoi(temp);

//			if (order(theItem))
				print('O', true, theItem);
//			else print('O', false, theItem);

			break;

		case 'R':
					//count items received for command 'R'

			getline(input, theItem.ID, '\n');
			getline(input, temp, '\n');
			theItem.quantity = stoi(temp);

//			if (receive(theItem))
				print('R', true, theItem);
//			else print('R', false, theItem);

			break;

		}

		getline(input, temp, '\n');
		command = temp[0];
	}

//	cin.get();
	return 0; 

}