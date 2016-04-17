//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME: tree.cpp                 ASSIGNMENT #: 7                  Grade: _________   *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     _________________________________________                                   *
//*                                    Hein Htet Zaw                                                  *
//*                                                                                                   *
//*   COURSE #:  CSC 36000 11                                               DUE DATE: April 22, 2015  *
//*                                                                                                   *
//*****************************************************************************************************
//*****************************************************************************************************
//                                                                                                    *
//   Program description: The program is to employ a Binary Tree to store and print information on a  *
//                        store's database inventory. The program is to read in the information given,*
//                        delete the item inventory, change the quantity on hand, change the quantity *
//                        on order, or change the quantity in both on hand and on order according to  *
//                        the command given in the data file. It can also print the given specific    *
//                        item information and the entire inventory on request. Every activity is to  *
//                        notify the user whether or not the process succeed.                         *
//                                                                                                    *
//*****************************************************************************************************
#include <iostream>
#include <string>

#include "tree_header.h"
#include "tree_helpers.cpp"

using namespace std;

int main() {
			//prepare for read in each line of given input file
	string temp;
	char command;
	
			//create a binary tree from the tree class to use in main
	tree theTree;

			//print header for output file
	header();

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

					//read in all the given values into their respective variables
			getline(input, theItem.ID, '\n');							//read the ID
			getline(input, theItem.description, '\n');					//read the Description
			getline(input, temp, '\n');									//read Quantity on Hand
			theItem.onHand = stoi(temp);								//convert it into integer value
			getline(input, temp, '\n');									//read Quantity on Order
			theItem.onOrder = stoi(temp);								//convert it into integer value

					//insert the item in the tree
			if (theTree.add(theItem)) print ('A', true, theItem);		//notify success	
			else print('A', false, theItem);							//notify duplicate

					//print 60 '-'s
			print('-');

			break;

		case 'D':
					//delete an item for command 'D'

					//read the given values
			getline(input, theItem.ID, '\n');							//read the ID
			getline(input, theItem.description, '\n');					//read the Description

					//delete the described item
			if (theTree.del(theItem)) print('D', true, theItem);		//notify success
			else print('D', false, theItem);							//notify error

					//print 60 '-'s
			print('-');

			break;

		case 'P':
					//print for command 'P'

					//read in the given command to print everything(E) or one node(N)
			getline(input, temp, '\n');

					//print everything for 'E'
			if (temp[0] == 'E') {
						
						//print the header for item list
				print('H');
						//print the entire tree
				print('E', &theTree);
			}
					//print one particular node for 'N'
			else if (temp[0] == 'N') {

						//read the given value which entry to print
				getline(input, theItem.ID, '\n');

						//check if the entry is in the list
				item *found = theTree.search(theItem);

						//print the result if the item is in tree
				if (found != NULL) {
							//print header for the item
					print('H');
							//print the item
					print('N', true, *found);
				}
				else {
							//print error message if the item is not in tree
					print('N', false, theItem);
							//print 60 '-'s
					print('-');
				}
			}

			break;

		case 'S':
					//count items sold for command 'S'
					
					//read in the given values
			getline(input, theItem.ID, '\n');				//read item ID to update
			getline(input, temp, '\n');						//read in the quantity to update
			theItem.quantity = stoi(temp);					//convert it into integer

					//print success message if item is valid and updated
			if (theTree.sell(theItem)) print('S', true, theItem);

					//print error message if updating did not happen
			else print('S', false, theItem);

					//print 60 '-'s
			print('-');

			break;

		case 'O':
					//count items ordered for command 'O'

					//read in the given values
			getline(input, theItem.ID, '\n');				//read item ID to update
			getline(input, temp, '\n');						//read in the quantity to update
			theItem.quantity = stoi(temp);					//convert it into integer

					//print success message if item is valid and updated
			if (theTree.order(theItem)) print('O', true, theItem);

					//print error message if updating did not happen
			else print('O', false, theItem);

					//print 60 '-'s
			print('-');

			break;

		case 'R':
					//count items received for command 'R'

					//read in the given values
			getline(input, theItem.ID, '\n');				//read item ID to update
			getline(input, temp, '\n');						//read in the quantity to update
			theItem.quantity = stoi(temp);					//convert it into integer

					//print success message if item is valid and updated
			if (theTree.receive(theItem)) print('R', true, theItem);

					//print error message if updating did not happen
			else print('R', false, theItem);

					//print 60 '-'s
			print('-');

			break;

		}

				//read the next command to perform
		getline(input, temp, '\n');
		command = temp[0];
	}
			//print footer at the end of the output file
	footer();

	return 0; 

}