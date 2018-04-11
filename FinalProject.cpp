// FinalProject.cpp
// Ryan Balog
// To create a menu based program that will calculate sales receipts, create customer records, balance the user's checkbook, and a time converter

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ios>
#include <fstream>
using namespace std;

void welcome();																																				// Welcome screen
void menu(string &selection);																																// Menu Screen
void salesReceipts();																																		// Sales receipt calculator
void customerRecord();																																		// Customer contact card generator
void checkBook();																																			// Check book 
void conversion();																																			// Time converter
void goodBye();																																				// Leaving screen
void errorChecking(string &selection);																														// Responds to invalid input


int main()
{
	welcome();																																				// Calls welcome screen

	string selection;
	do
	{
		
		menu(selection);																																	// Calls menu screen

		if (selection.at(0) == '1')																															// Calls salesReceipts
		{
			system("cls");
			salesReceipts();
			system("pause");
		}

		else if (selection.at(0) == '2')																													// Calls customerRecord
		{
			system("cls");
			customerRecord();
			system("pause");
		}
		else if (selection.at(0) == '3')																													// Calls checkBook
		{
			system("cls");
			checkBook();
			system("pause");
		}
		else if (selection.at(0) == '4')																													// Calls conversion
		{
			system("cls");
			conversion();
			system("pause");
		}
		else if (selection.at(0) == '0')																													// Calls exit screen
		{
			system("cls");
			goodBye();
			system("pause");
		}

		else                                                                                                                                                // Incorrect input calls error message
		{
			system("cls");
			errorChecking(selection);
			system("pause");
		}
	} while (selection.at(0) != '0');																														// 0 exits the program

	return 0;
}

void welcome()																																				// Welcome screen
{
	string name;

	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*****                  Welcome               ****" << endl;
	cout << "*****                    to                  ****" << endl;
	cout << "*****                Ryan Balog's            ****" << endl;
	cout << "*****               Final Project            ****" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "Who are you? : ";
	getline(cin,name);																																		// Input for user's name
	cout << "Enjoy the program " << name << " !!" << endl << endl;
	system("pause"); 
	return;
}

void menu(string &selection)																																// Menu options for what program they want to run
{
	system("cls");

	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*****                Ryan Balog's            ****" << endl;
	cout << "*****               Final Project            ****" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*****               Menu Options             ****" << endl;
	cout << "*****               ------------             ****" << endl;
	cout << "*****      1:    Calculate sales receipt     ****" << endl;
	cout << "*****      2:    Create customer record      ****" << endl;
	cout << "*****      3:    Balance checkbook           ****" << endl;
	cout << "*****      4:    Convert time                ****" << endl;
	cout << "*****                                        ****" << endl;
	cout << "*****      0:    Close program               ****" << endl;
	cout << "*****                                        ****" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl << endl;

	cout << "Selection: ";
	cin >> selection;																																			// Gets user selection
	return; 
}

void salesReceipts()
{
	int numItems;																																				// Variable declaration
	vector<string>itemName;
	vector<float>itemValue;
	float totalSales;
	float salesTax;
	float grandTotal;
	char answer;


	cout << "This program will store sales items, and their prices input by the user." << endl;																	// Summary header
	cout << "The program will then ask for the sales tax, and calculate the totals for the user." << endl << endl << endl;

	do {

		int numItems = 0;																																		// Variable reset for Do loop
		float totalSales = 0;
		float salesTax = 0;
		float grandTotal = 0;

		cout << "How many sales items do you have?: ";																											// Input for number of items
		cin >> numItems;
		cout << endl;

		itemName.resize(numItems);																																// Setting vector sizes to = the number of items
		itemValue.resize(numItems);

		for (int i = 0; i < numItems; i++)																														// Loop to get item name and values input into two vectors
		{
			cout << "Enter name of item " << i + 1 << " : ";
			cin.ignore();
			getline(cin, itemName.at(i));																														// Use getline to prevent program failure due to input whitespace
			cout << "Enter value for " << itemName.at(i) << " : ";
			cin >> itemValue.at(i);
			totalSales = totalSales + itemValue.at(i);
		}

		cout << "Enter the sales tax percentage: % ";																											// Input for sales tax
		cin >> salesTax;

		salesTax = salesTax / 100;																																// Converting sales tax to percentage
		salesTax = totalSales * salesTax;																														// Sale tax total calculation 
		grandTotal = totalSales + salesTax;

		system("cls");																																			// Move screen down

		cout << "**************************************************" << endl;																					// Final calculation output
		cout << "**************************************************" << endl;
		cout << "**                                              **" << endl;
		cout << "**                    Receipt                   **" << endl;
		cout << "**                                              **" << endl;
		cout << "**************************************************" << endl;
		cout << "**************************************************" << endl;
		cout << "**                                              **" << endl;
		cout << "**                                              **" << endl;

		cout << fixed;

		for (int i = 0; i < numItems; i++)																														// Loop for printing each sale item and price from vectors
		{
			cout << "**" << setw(10) << " " << setw(11) << left << itemName.at(i) << right << ":  $" << setw(10) << setprecision(2) << itemValue.at(i) << "           **" << endl;
		}

		cout << "**                                              **" << endl;
		cout << "**                                              **" << endl;

		cout << "**          Total Sales:  $" << setw(10) << setprecision(2) << totalSales << "           **" << endl;
		cout << "**          Sales Tax  :  $" << setw(10) << setprecision(2) << salesTax << "           **" << endl;
		cout << setw(26) << left << "**" << "  __________" << setw(12) << right << "**" << endl;
		cout << "**          Grand Total:  $" << setw(10) << setprecision(2) << grandTotal << "           **" << endl;

		cout << "**                                              **" << endl;
		cout << "**                                              **" << endl;
		cout << "**************************************************" << endl;
		cout << "**************************************************" << endl;

		cout << "Would you like to run the program again? (Y/N): ";																							    // Input for answer
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');																													// Y repeats the Do loop

	return;
}

void customerRecord()																																			// Creates customer records
{
	char answer;

	do {

		string firstName;																																		// Multiple string variables needed
		string lastName;
		string streetAddress;
		string city;
		string state;
		string zipCode;
		string phoneNumber;

		system("cls");
		
		cout << "This program will ask for the customer's contact information." << endl;																		// Program header
		cout << "It will then output the final record." << endl << endl;

		cout << "Customer first and last name: ";																												// Collecting data inputs
		cin >> firstName >> lastName;
		cout << endl;
		cout << "Customer street address: ";
		cin.ignore();
		getline (cin, streetAddress);
		cout << endl;
		cout << "City: ";
		getline (cin, city);
		cout << endl;
		cout << "State / Province: ";
		getline (cin, state);
		cout << endl;
		cout << "Zip code / Postal code: ";
		getline (cin, zipCode);
		cout << endl;
		cout << "Phone number: ";
		getline (cin, phoneNumber);
		cout << endl;

		system("cls");


		cout << "**********************************************************************" << endl;																// Record output
		cout << "**********************************************************************" << endl;
		cout << "**                                                                  **" << endl;
		cout << "**                                                                  **" << endl;
		cout << "**                         Customer Record                          **" << endl;
		cout << "**                                "<< firstName.at(0) << lastName.at(0) << "                                **" << endl;						// Customer initials
		cout << "**                                                                  **" << endl;
		cout << "**********************************************************************" << endl;
		cout << "**********************************************************************" << endl;
		cout << "**                                                                  **" << endl;
		cout << "** " << firstName << " " << lastName << right << setw(66 - firstName.length() - lastName.length()) << "**" << endl;							// Customer name
		cout << "** " << setw(60) << left << streetAddress << right << setw(7) << "**" << endl;																	// Street address
		cout << "** " << city << ", " << state << " " << zipCode<< right << setw(64 - city.length() - state.length() - zipCode.length()) << "**" << endl;		// City, state and zipcode
		cout << "** " << setw(50) << left << phoneNumber << right << setw(17) << "**" << endl;																	// Phonenumber
		cout << "**                                                                  **" << endl;
		cout << "**********************************************************************" << endl;
		cout << "**********************************************************************" << endl << endl;

		cout << "Would you like to run the program again? (Y/N): ";																							    // Input for answer
		cin >> answer;
		
	} while (answer == 'y' || answer == 'Y');
	return;
}

void checkBook()																																				// Check book program		
{
	char answer;

	do {

		vector<float> deposit;																																	
		vector<float> withdraw;
		vector<float> balance;
		ofstream outSheet;
		int deps = 0;
		int withs = 0;
		int bal = 0;
		int i = 0;
		int x = 0;

		system("cls");

		cout << "This program will create a checkbook balance sheet. Once the spreadsheet is created, the user can save it to a file." << endl << endl;										// Program summary header

		cout << "How many deposits are there? : ";
		cin >> deps;
		cout << endl;

		cout << "How many withdraws are there? : ";
		cin >> withs;
		cout << endl;

		bal = deps + withs;

		deposit.resize(deps);																														// Vector resizing
		withdraw.resize(withs);
		balance.resize(bal + 1);

		cout << "Please use only 2 decimal places" << endl << endl;
		cout << "Enter beginning balance: ";
		cin >> balance.at(0);
		cout << endl << endl;

		

		for (i = 0; i < deps; i++)																													// Inputs for deposits and withdrawls
		{
			cout << "Enter amount deposited for deposit " << i+1 << ": ";
			cin >> deposit.at(i);
			cout << endl;
																																					// Running balance calculation
		}

		for (i = 0; i < withs; i++)																													// Inputs for deposits and withdrawls
		{
			cout << "Enter amount withdrawn for withdraw " << i+1 << ": ";
			cin >> withdraw.at(i);
			cout << endl;
																																					// Running balance calculation
		}

		for (i = 0; i < deps; i++)
		{
			balance.at(i + 1) = balance.at(i) + deposit.at(i);
		}
		x = i;
		i = 0;
		for (x; x < bal; x++)
		{
			balance.at(x + 1) = balance.at(x) - withdraw.at(i);
			i++;
		}

		system("cls");
		cout << fixed;

		cout << "*******************************************************************************" << endl;											// Formatted output
		cout << "*******************************************************************************" << endl;
		cout << "**                                 Check book                                **" << endl;
		cout << "*******************************************************************************" << endl;
		cout << "*******************************************************************************" << endl;
		cout << "**                                                                           **" << endl;
		cout << "**         Deposits              Withdrawls                  Balance         **" << endl;
		cout << "**        ----------            ------------                ---------        **" << endl;
		cout << "**                                                       $:" << setw(10) << setprecision(2) << balance.at(0) << "        **" << endl;
		for (i = 0; i < deps; i++)
		{
			cout << "**      $:" << setw(10) << setprecision(2) << deposit.at(i) <<  "                                     $:" << setw(10) << setprecision(2) << balance.at(i+1) << "        **" << endl;
		}
		x = i + 1;
		i = 0;
		for (x; x <= bal; x++)
		{
			cout << "**                             $:" << setw(10) << setprecision(2) << withdraw.at(i) << "              $:" << setw(10) << setprecision(2) << balance.at(x) << "        **" << endl;
			i++;
		}
		cout << "**                                                                           **" << endl;
		cout << "*******************************************************************************" << endl;
		cout << "*******************************************************************************" << endl << endl;
		
		cout << "Would you like to save a copy of this balance sheet? (Y/N): ";
		cin >> answer;
		cout << endl;
		if (answer == 'y' || answer == 'Y')																														// Saved formatted output
		{
			outSheet.open("BalanceSheet.txt");
			outSheet << fixed;

			outSheet << "*******************************************************************************" << endl;												// Formatted output to file
			outSheet << "*******************************************************************************" << endl;
			outSheet << "**                                 Check book                                **" << endl;
			outSheet << "*******************************************************************************" << endl;
			outSheet << "*******************************************************************************" << endl;
			outSheet << "**                                                                           **" << endl;
			outSheet << "**         Deposits              Withdrawls                  Balance         **" << endl;
			outSheet << "**        ----------            ------------                ---------        **" << endl;
			outSheet << "**                                                       $:" << setw(10) << setprecision(2) << balance.at(0) << "        **" << endl;
			for (i = 0; i < deps; i++)
			{
				outSheet << "**      $:" << setw(10) << setprecision(2) << deposit.at(i) << "                                     $:" << setw(10) << setprecision(2) << balance.at(i + 1) << "        **" << endl;
			}
			x = i + 1;
			i = 0;
			for (x; x <= bal; x++)
			{
				outSheet << "**                             $:" << setw(10) << setprecision(2) << withdraw.at(i) << "              $:" << setw(10) << setprecision(2) << balance.at(x) << "        **" << endl;
				i++;
			}
			outSheet << "**                                                                           **" << endl;
			outSheet << "*******************************************************************************" << endl;
			outSheet << "*******************************************************************************" << endl << endl;
		
			outSheet.close();

			cout << "File BalanceSheet.txt created" << endl << endl;
		}

		cout << "Would you like to run the program again? (Y/N): ";																								// Run program again?
		cin >> answer;


	} while (answer == 'y' || answer == 'Y');
	return;

}

void conversion()																																				// Time conversion
{
	string type;																																				// Mil or Civ?
	int hour;
	int minute;
	string meridiem;																																			// AM or PM?
	char answer;
	do {
		system("cls");

		cout << "*******************************************************************************" << endl;														// Header
		cout << "*******************************************************************************" << endl;
		cout << "**                                Time Conversion                            **" << endl;
		cout << "**                    Convert between civilian and military                  **" << endl;
		cout << "*******************************************************************************" << endl;
		cout << "*******************************************************************************" << endl << endl << endl;

		cout << "What is your current time in? Enter C for civilian or M for military: ";																		// Type input
		cin.ignore();
		getline(cin, type);
		cout << endl << endl;

		if (type.at(0) == 'c' || type.at(0) == 'C')																												// If time is in civilian
		{
			cout << "Civilian Time --> Military Time" << endl;
			cout << "Enter hour: ";																																// Data inputs
			cin >> hour;
			cout << endl;
			cout << "Enter minutes: ";
			cin >> minute;
			cout << endl;
			cout << "Is it AM or PM?: ";
			cin >> meridiem;
			cout << endl << endl << endl;

			cout << "Civilian Time: " << hour << ":" << minute << meridiem << endl;																				// Output civilian time

			if (meridiem.at(0) == 'a' || meridiem.at(0) == 'A')																									// Conversion if civ time is in AM
			{
				if (hour == 12)
				{
					hour = 0;
					cout << "Military Time: " << hour << ":" << minute << endl << endl;
				}
				else
				{
					cout << "Military Time: " << hour << ":" << minute << endl << endl;
				}
			}
			else if (meridiem.at(0) == 'p' || meridiem.at(0) == 'P')																							// Conversion if civ time is in PM
			{
				if (hour == 12)
				{
					cout << "Military Time: " << hour << ":" << minute << endl << endl;
				}
				else
				{
					hour = hour + 12;
					cout << "Military Time: " << hour << ":" << minute << endl << endl;
				}
			}
			else                                                                                                                                                // Error if AM or PM not input
			{
				system("cls");
				cout << "Error, must enter AM or PM!" << endl;
				system("pause");
				system("cls");
				conversion();
			}
		}
		else if (type.at(0) == 'm' || type.at(0) == 'M')																									    // If time is in military
		{
			cout << "Military Time --> Civilian Time" << endl;
			cout << "Enter hour: ";																																// Inputs
			cin >> hour;
			cout << endl;
			cout << "Enter minutes: ";
			cin >> minute;
			cout << endl << endl;

			cout << "Military Time: " << hour << ":" << minute << endl;																							// Outputs mil time
			if (hour == 0)																																		// Conversion mil time is midnight
			{
				hour = 12;
				meridiem = "AM";
				cout << "Civilian Time: " << hour << ":" << minute << meridiem << endl << endl;
			}
			else if (hour < 12)																																	// Conversion if mil time is before noon
			{
				meridiem = "AM";
				cout << "Civilian Time: " << hour << ":" << minute << meridiem << endl << endl;
			}
			else if (hour == 12)																																// Conversion if mil time is noon
			{
				meridiem = "PM";
				cout << "Civilian Time: " << hour << ":" << minute << meridiem << endl << endl;
			}
			else                                                                                                                                                //  Conversion if mil time is after noon
			{
				hour = hour - 12;
				meridiem = "PM";
				cout << "Civilian Time: " << hour << ":" << minute << meridiem << endl << endl;
			}
		}
		else                                                                                                                                                    // Error if Civilian or Military is not selected
		{
			system("cls");
			cout << "Error, must enter C or M!" << endl;
			system("pause");
			system("cls");
		}

		cout << "Would you like to run the program again? (Y/N): ";																								// Run again?
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	return; 
}


void goodBye()																																					// Exiting thank you screen
{
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*****                 Thank You              ****" << endl;
	cout << "*****                 For Using              ****" << endl;
	cout << "*****                Ryan Balog's            ****" << endl;
	cout << "*****               Final Project            ****" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;

	return;
}

void errorChecking(string &selection)																																// Incorrect menu entry response
{
	char answer;

	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*****                   ERROR!               ****" << endl;
	cout << "*****               Invalid Entry            ****" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "Would you like to re-enter the menu? (Y/N) : ";
	cin >> answer;

	if (answer == 'y' || answer == 'Y')																															// Returns to menu
	{
		
	}
	else                                                                                                                                                        // Exits program
	{
		selection.at(0) = '0';
		system("cls");

		cout << "*************************************************" << endl;
		cout << "*************************************************" << endl;
		cout << "*************************************************" << endl;
		cout << "*****                 Thank You              ****" << endl;
		cout << "*****                 For Using              ****" << endl;
		cout << "*****                Ryan Balog's            ****" << endl;
		cout << "*****               Final Project            ****" << endl;
		cout << "*************************************************" << endl;
		cout << "*************************************************" << endl;
		cout << "*************************************************" << endl;
	}
	
	return;
}
