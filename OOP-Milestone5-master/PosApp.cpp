#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include<iostream> 
#include<cstring> 
#include<iomanip>

using namespace std;

namespace ict {
	PosApp::PosApp(const char* filename, const char* billfname) {
		strcpy(m_billfname, billfname);
		strcpy(m_filename, filename);
		m_noOfItems = 0;
		loadRecs();
	}

	int PosApp::menu() {
		int option;
		cout << "The Sene-Store" << endl << "1- List items" << endl << "2- Add Perishable item" << endl << "3- Add Non-Perishable item" << endl << "4- Update item quantity" << endl << "5- Show Item" << endl << "6- POS" << endl << "0- exit program" << endl << "> ";
		cin >> option;
		if (cin.fail() || !(option >= 0 && option <= 6)) {
			option = (-1);
		}
		cin.clear();
		cin.ignore(1024, '\n');
		return option;
	}

	void PosApp::deallocateItems() {
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			delete m_items[i];
		}
		m_noOfItems = 0;
	}

	void PosApp::loadRecs() {
		deallocateItems();
		fstream rec;
		rec.open(m_filename, ios::in);
		if (rec.fail()) {
			rec.clear();
			rec.close();
			rec.open(m_filename, ios::out);
			rec.close();
		}
		else {
			char type;
			while (!rec.eof()) {
				type = rec.get();
				if (type == 'P') {
					Perishable* tempP = new Perishable;
					rec.ignore(1);
					tempP->load(rec);
					m_items[m_noOfItems] = tempP;
					m_noOfItems++;
					type = 0;
				}
				else if (type == 'N') {
					NonPerishable* tempN = new NonPerishable;
					rec.ignore(1);
					tempN->load(rec);
					m_items[m_noOfItems] = tempN;
					m_noOfItems++;
					type = 0;
				}
			}
			rec.close();
		}
	}

	void PosApp::saveRecs() {
		fstream rec; rec.open(m_filename, ios::out);
		for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i]->quantity() > 0) {
				m_items[i]->save(rec);
			}
		}
		rec.close();
		loadRecs();
	}

	int PosApp::searchItems(const char* sku)const {
		int result = (-1);
		for (int i = 0; i < m_noOfItems; i++) {
			if (*m_items[i] == sku) {
				result = i;
			}
		}
		return result;
	}

	void PosApp::updateQty() {
		char sku[MAX_SKU_LEN]; int result;
		cout << "Please enter the SKU: ";
		cin >> sku;
		cin.ignore();
		result = searchItems(sku);
		if (result != (-1)) {
			m_items[result]->write(cout, false);
			cout << endl << "Please enter the number of purchased items: ";
			int qty;
			cin >> qty;
			cin.ignore();
			(*m_items[result]) += qty;
			saveRecs();
			cout << "Updated!" << endl << endl;
		}
		else {
			cout << "Not found!" << endl;
		}
	}

	void PosApp::addItem(bool isPerishable) {
		Item* temp;
		if (isPerishable == true) {
			temp = new Perishable;
		}
		else {
			temp = new NonPerishable;
		}
		temp->read(cin);
		if (!cin.fail()) {
			m_items[m_noOfItems] = temp;
			m_noOfItems++;
			saveRecs();
			cout << "Item added." << endl << endl;
		}
		else {
			cin.clear();
			temp->write(cout, false);
			cout << endl << endl;
		}
	}

	void PosApp::listItems()const {
		double total = 0.0;
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < m_noOfItems; i++) {
			cout << setfill(' ') << setw(4) << right << (i + 1) << " | ";
			m_items[i]->write(cout, true) << endl;
			total += m_items[i]->cost() * m_items[i]->quantity();
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl << "                               Total Asset: $  |" << setw(14) << fixed << setprecision(2) << total << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl << endl;
	}

	void PosApp::truncateBillFile() {
		fstream temp;
		temp.open(m_billfname, ios::out | ios::trunc);
		temp.close();
	}

	void PosApp::showBill() {
		Date current;
		cout << "v--------------------------------------------------------v" << endl << "| ";
		cout << current;
		cout << "                                      |" << endl << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl << "|--------|--------------------|-------|---|----|---------|" << endl;
		fstream rec; rec.open(m_billfname, ios::in);
		if (rec.fail()) {
			rec.clear();
			rec.close();
			rec.open(m_filename, ios::out);
			rec.close();
		}
		else {
			Item* temp = nullptr;
			double total = 0.0;
			char type;
			while (!rec.eof()) {
				type = rec.get();
				if (type == 'P') {
					temp = new Perishable;
				}
				else if (type == 'N') {
					temp = new NonPerishable;
				}
				rec.ignore(1);
				temp->load(rec);
				cout << setfill(' ') << "| ";
				temp->write(cout, true);
				total += temp->cost() * temp->quantity();
				cout << endl;
				delete temp;
			}
			cout << "^--------^--------------------^-------^---^----^---------^" << endl << "|                               Total: $  |" << setw(14) << right << total << "|" << endl << "^-----------------------------------------^--------------^" << endl << endl;
		}
		rec.close();
		truncateBillFile();
	}

	void PosApp::addToBill(Item &I) {
		fstream rec; rec.open(m_billfname, ios::out | ios::app);
		int tempQty = I.quantity();
		I.quantity(1);
		I.save(rec);
		I.quantity(tempQty - 1);
		rec.close();
		saveRecs();
	}

	void PosApp::POS() {
		char sku[MAX_SKU_LEN];
		cout << "Sku: ";
		//1. This loop is modeled by a stackoverflow.com post
		while (cin.getline(sku, MAX_SKU_LEN)) {
			if (strcmp(sku, "") == 0) {
				break;
			}
			else {
				int result = searchItems(sku);
				if (result == (-1)) {
					cout << "Not found!" << endl;
				}
				else if (result != (-1)) {
					cout << "v------------------->" << endl << "| " << m_items[result]->name() << endl << "^------------------->" << endl;
					addToBill(*m_items[result]);
				}
				cout << "Sku: ";
			}
		}
		showBill();
	}

	void PosApp::run() {
		bool done;
		do {
			int selection;
			selection = menu();
			cout << endl;
			if (selection == 0) {
				cout << "Goodbye!" << endl;
				done = true;
				break;
			}
			else if (selection == 1) {
				listItems();
				done = false;
			}
			else if (selection == 2) {
				addItem(true);
				done = false;
			}
			else if (selection == 3) {
				addItem(false);
				done = false;
			}
			else if (selection == 4) {
				updateQty();
				done = false;
			}
			else if (selection == 5) {
				char sku[MAX_SKU_LEN];
				cout << "Please enter the SKU: ";
				cin >> sku;
				int search = searchItems(sku);
				if (search != (-1)) {
					cout << "v-----------------------------------v" << endl;
					m_items[search]->write(cout, false);
					cout << "^-----------------------------------^" << endl << endl;
				}
				else {
					cout << "Not found!" << endl << endl;
				}
				done = false;
			}
			else if (selection == 6) {
				POS();
				done = false;
			}
			else {
				cout << "===Invalid Selection, try again===" << endl;
				done = false;
			}

		} while (done == false);
	}
}



/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
							   Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/
