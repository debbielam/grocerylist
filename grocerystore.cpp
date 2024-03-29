#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

typedef struct
{
	char number[7];
	char name[21];
	char size[7];
	char brand[21];
	char price[7];
	char quantity[7];
	char supplier[21];
	char contact[21];
}INFO;

void display(INFO product[], int rows);
void search_number(INFO product[], int rows);
void low_inventories(INFO product[], int rows);
void update(INFO product[], int& rows);
void add_item(INFO product[], int& rows);
void delete_item(INFO product[], int& rows);
void exit(INFO product[], int rows);

int main(void)
{
	ifstream infile("test(1).txt");
	if (!infile)
		cout << "ERROR OPENING INPUT FILE!" << endl;
	else
	{
		INFO item[50];
		int choice, index = 0, search_selection;
		char heading[200];

		infile.getline(heading, 200);
		infile.getline(item[index].number, 7, '\t');
		while (infile)
		{
			infile.getline(item[index].name, 21, '\t');
			infile.getline(item[index].size, 7, '\t');
			infile.getline(item[index].brand, 21, '\t');
			infile.getline(item[index].price, 7, '\t');
			infile.getline(item[index].quantity, 7, '\t');
			infile.getline(item[index].supplier, 21, '\t');
			infile.getline(item[index].contact, 21, '\n');

			if (infile.peek() == '\n')
				infile.ignore(256, '\n');

			infile.getline(item[++index].number, 7, '\t');
		}
		infile.close();

		do
		{
			cout << "\n\n\t\t\t*********WELCOME TO LUCKY99 GROCERY STORE*********" << endl;
			cout << "\n\t\t\t\tHERE ARE THE ACTIONS THAT YOU CAN DO:" << endl;
			cout << "\n\t\t\t\t1   List all products" << endl;
			cout << "\t\t\t\t2   Search product by item number" << endl;
			cout << "\t\t\t\t3   Search product by keyword" << endl;
			cout << "\t\t\t\t4   Show low inventories" << endl;
			cout << "\t\t\t\t5   Update inventory" << endl;
			cout << "\t\t\t\t6   Add new product" << endl;
			cout << "\t\t\t\t7   Delete product" << endl;
			cout << "\t\t\t\t8   Save & Exit" << endl;
			cout << "\n\t\t\t\tPlease enter your choice: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				display(item, index);
				break;
			case 2:
				search_number(item, index);
				break;
			case 3: 
				break;
			case 4: 
				low_inventories(item, index);
				break;
			case 5: 
				update(item, index);
				break;
			case 6:
				add_item(item, index);
				break;
			case 7:
				delete_item(item, index);
				break;
			case 8:
				exit(item, index);
				cout << "\n\t\t\t\tGOODBYE! HAVE A NICE DAY!\n";
				break;
			default: cout << "INVALID INPUT!" << endl;
			}
		} while (choice != 8);
	}
	return 0;
}

void display(INFO product[], int rows)
{
	system("cls");
	int i;
	cout << "\nITEM NUMBER\tITEM NAME\t\tSIZE(kg)\tBRAND\t\tPRICE(RM)\tQUANTITY\tSUPPLIER\tCONTACT INFO" << endl;
	cout << "===================================================================================================================================" << endl;
	for (i = 0; i < rows; i++)
	{
		cout << product[i].number << "\t\t" << product[i].name << "\t\t"
			<< product[i].size << "\t\t" << product[i].brand << "\t"
			<< product[i].price << "\t\t" << product[i].quantity << "\t\t"
			<< product[i].supplier << "\t" << product[i].contact << endl;
	}
	return;
}

void search_number(INFO product[], int rows)
{
	system("cls");
	char ans[7], reply;
	int i, j;
	do
	{
		cout << "Enter an item number: ";
		cin >> ans;
		for (j = 0; j < rows; j++)
		{
			if (strcmp(ans, product[j].number) == 0)
			{
				cout << "\nITEM NUMBER\tITEM NAME\tSIZE(kg)\tBRAND\tPRICE(RM)\tQUANTITY\tSUPPLIER\tCONTACT INFO" << endl;
				cout << "====================================================================================================================" << endl;
				cout << "\t" << product[j].number << "\t" << product[j].name << "\t"
					<< product[j].size << "\t" << product[j].brand << "\t"
					<< product[j].price << "\t" << product[j].quantity << "\t"
					<< product[j].supplier << "\t" << product[j].contact << endl;
			}
		}
		cout << "Anything else to search (Y/N)? ";
		cin >> reply;
	} while (reply == 'Y' || reply == 'y');
	return;
}


void low_inventories(INFO product[], int rows)
{
	int tick = 0;
	system("cls");
	cout << "\nITEM NUMBER\tITEM NAME\tSIZE(kg)\tBRAND\t\t\tPRICE(RM)\tQUANTITY\tSUPPLIER\tCONTACT INFO" << endl;
	cout << "===================================================================================================================================" << endl;
	for (int i = 0; i < rows; i++)
	{
		int len = strlen(product[i].quantity);
		if (len == 1 || ((strcmp(product[i].quantity, "10")) == 0))
		{
			cout << product[i].number << "\t\t" << product[i].name << "\t"
				<< product[i].size << "\t\t" << product[i].brand << "\t\t"
				<< product[i].price << "\t" << setw(15) << right << product[i].quantity << "\t\t"
				<< product[i].supplier << "\t" << product[i].contact << endl;
			tick = 1;
		}
	}
	if (tick == 0)
		cout << "\nNO LOW INVENTORY ITEMS FOUND!" << endl;
}

void update(INFO product[], int& rows)
{
	system("cls");
	int i, j, select, found = 0;
	char insert[7], respond;
	INFO toupdate[1];
	do
	{
		cout << "\nEnter item number of product to be updated: ";
		cin >> insert;
		found = 0; // always reset your flag
		for (i = 0; i < rows; i++)
		{
			if (strcmp(insert, product[i].number) == 0)
			{
				j = i;
				cout << "\n---INFORMATION OF ITEM---" << endl;
				cout << "1   Item name: " << product[i].name << endl;
				cout << "2   Item size: " << product[i].size << endl;
				cout << "3   Item brand: " << product[i].brand << endl;
				cout << "4   Item price: " << product[i].price << endl;
				cout << "5   Item quantity: " << product[i].quantity << endl;
				cout << "6   Supplier name: " << product[i].supplier << endl;
				cout << "7   Supplier contact: " << product[i].contact << endl;
				cout << "\nWhich info do you want to update (1-8)? ";
				cin >> select;
				found = 1;
				break; // always remember to break the loop after found
			}
		}
		if (found == 0)
			cout << "\nNO RECORD FOUND! NOTHING UPDATED!" << endl;
		else
		{
			switch (select)
			{
			case 1:
				cout << "\nEnter new item name: ";
				cin.ignore();
				cin.getline(toupdate[1].name, 21);
				strcpy_s(product[j].name, toupdate[1].name);
				break;
			case 2:
				cout << "\nEnter new item size: ";
				cin.ignore();
				cin.getline(toupdate[1].size, 7);
				strcpy_s(product[j].size, toupdate[1].size);
				break;
			case 3:
				cout << "\nEnter new item brand: ";
				cin.ignore();
				cin.getline(toupdate[1].brand, 21);
				strcpy_s(product[j].brand, toupdate[1].brand);
				break;
			case 4:
				cout << "\nEnter new price: ";
				cin.ignore();
				cin.getline(toupdate[1].price, 7);
				strcpy_s(product[j].price, toupdate[1].price);
				break;
			case 5:
				cout << "\nEnter new quantity: ";
				cin.ignore();
				cin.getline(toupdate[1].quantity, 7);
				strcpy_s(product[j].quantity, toupdate[1].quantity);
				break;
			case 6:
				cout << "\nEnter new supplier name: ";
				cin.ignore();
				cin.getline(toupdate[1].supplier, 21);
				strcpy_s(product[j].supplier, toupdate[1].supplier);
				break;
			case 7:
				cout << "\nEnter new supplier contact: ";
				cin.ignore();
				cin.getline(toupdate[1].contact, 21);
				strcpy_s(product[j].contact, toupdate[1].contact);
				break;
			}
			cout << "\nITEM INFO UPDATED SUCCESSFULLY!" << endl;
		}		
		cout << "\nAnything else to update (Y/N)? ";
		cin >> respond;
	} while (respond == 'Y' || respond == 'y');
	return;
}


void add_item(INFO product[], int& rows)
{
	system("cls");
	int length;
	cout << "\n***NEW PRODUCT***" << endl;
	cout << "Enter item number: ";
	cin.ignore();
	cin.getline(product[rows].number, 7);
	cout << "\nEnter item name: ";
	cin.getline(product[rows].name, 21);
	cout << "\nEnter size: ";
	cin.getline(product[rows].size, 7);
	cout << "\nEnter brand: ";
	cin.getline(product[rows].brand, 21);
	cout << "\nEnter price: ";
	cin.getline(product[rows].price, 7);
	cout << "\nEnter quantity: ";
	cin.getline(product[rows].quantity, 7);
	cout << "\nEnter supplier name: ";
	cin.getline(product[rows].supplier, 21);
	cout << "\nEnter supplier contact info: ";
	cin.getline(product[rows].contact, 21);

	cout << "\nNEW ITEM ADDED SUCCESSFULLY! " << endl;
	rows++;
	return;
}

void delete_item(INFO product[], int& rows)
{
	system("cls");
	int ans, i, j, check = 0;
	char deleting[7], confirmation, again;
	do{
		cout << "\nEnter item number to be deleted: ";
		cin.ignore();
		cin.getline(deleting, 7);
		for (i = 0; i < rows; i++)
		{
			if (strcmp(deleting, product[i].number) == 0)
			{
				check = 1;
				cout << "\n---INFORMATION OF ITEM---" << endl;
				cout << "Item number: " << product[i].number << endl;
				cout << "Item name: " << product[i].name << endl;
				cout << "Item size: " << product[i].size << endl;
				cout << "Item brand: " << product[i].brand << endl;
				cout << "Item price: " << product[i].price << endl;
				cout << "Item quantity: " << product[i].quantity << endl;
				cout << "Supplier name: " << product[i].supplier << endl;
				cout << "Supplier contact: " << product[i].contact << endl;
				j = i;
				cout << "Confirm to delete (Y/N)? ";
				cin >> confirmation;
				break; //once found, no need to cont loop
			}
			//			if (strcmp(deleting, product[i].number) != 0)
			//				check = 0;
		}
		if (check)
		{
			if (confirmation == 'y' || confirmation == 'Y')
			{
				for (j = 0; j < rows - 1; j++)
				{
					strcpy_s(product[j].number, product[j + 1].number);
					strcpy_s(product[j].name, product[j + 1].name);
					strcpy_s(product[j].size, product[j + 1].size);
					strcpy_s(product[j].brand, product[j + 1].brand);
					strcpy_s(product[j].price, product[j + 1].price);
					strcpy_s(product[j].quantity, product[j + 1].quantity);
					strcpy_s(product[j].supplier, product[j + 1].supplier);
					strcpy_s(product[j].contact, product[j + 1].contact);
				}
				rows--;
				cout << "\nITEM SUCCESSFULLY DELETED!\n" << endl;
			}
			if (confirmation == 'n' || confirmation == 'N')
				cout << "\nACTION DENIED! NO ITEM DELETED!" << endl;
		}
		else
			cout << "\nNO RECORD FOUND! NO ITEM DELETED!" << endl;
		cout << "Anything else to delete (Y/N)? ";
		cin >> again;
	} while (again == 'y' || again == 'Y');
	return;
}

void exit(INFO product[], int rows)
{
	system("cls");
	ofstream outfile("test(1).txt");
	if (!outfile)
	{
		cout << "\nERROR LOADING OUTFILE! LATEST INFORMATION NOT UPDATED!" << endl;
		exit(100);
	}
	else
	{
		outfile << left;
		outfile << "No";
		outfile << "\tName";
		outfile << "\t\tSize";
		outfile << "\tBrand";
		outfile << "\t\tPrice";
		outfile << "\tQty";
		outfile << "\tSupplier";
		outfile << "\tContact";
		outfile << endl;

		for (int i = 0; i < rows; i++)  for (i = 0; i < rows; i++)
		{
			outfile << left;
			outfile << product[i].number;
			outfile << "\t" << product[i].name;
			outfile << "\t" << product[i].size;
			outfile << "\t" << product[i].brand;
			outfile << "\t" << product[i].price;
			outfile << "\t" << product[i].quantity;
			outfile << "\t" << product[i].supplier;
			outfile << "\t" << product[i].contact;
			outfile << endl;
		}
		outfile.close();
	}
}

