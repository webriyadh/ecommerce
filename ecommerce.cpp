
// Develped by Riyadul , Bondy , Orthy, Anik and Ondrila

#include <bits/stdc++.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
map<string, map<string, double> > items;

// map data structure to store category-model in integer
// form as key and their model selected by the customer as
map<pair<int, int>, string> names;

// a function to fill the product data into the data

void fillItems()
{
	items["Mobile"]["Samsung"] = 15000;
	items["Mobile"]["Redmi"] = 12000;
	items["Mobile"]["Apple"] = 100000;
	items["Laptop"]["HP"] = 40000;
	items["Laptop"]["Lenovo"] = 35000;
	items["Laptop"]["Macbook"] = 250000;
	items["Course"]["C"] = 1000;
	items["Course"]["C++"] = 3000;
	items["Course"]["Java"] = 4000;
	items["Course"]["Python"] = 3500;

	// by default, category 1 is Mobile, category 2 is
	// Laptop and category 3 is Course
	/// similarly, 1,2,3 in the second part of the key
	/// represent their model
	names[{ 1, 1 }] = "Apple";
	names[{ 1, 2 }] = "Redmi";
	names[{ 1, 3 }] = "Samsung";

	names[{ 2, 1 }] = "HP";
	names[{ 2, 2 }] = "Lenovo";
	names[{ 2, 3 }] = "Macbook";

	names[{ 3, 1 }] = "C";
	names[{ 3, 2 }] = "C++";
	names[{ 3, 3 }] = "Java";
	names[{ 3, 4 }] = "Python";
}

// class customer to represent a real world entity, in our
// case - a customer
class customer {
	// map data strucute to store category-model as key and
	// their quantity selected by the customer as value
	map<string, map<string, int> > selected_items;

	// name of the customer. Here more data can be collected
	// from customer like phone number etc, but here we have
	// only collected name as an example
	string name;

public:
	// constructor
	customer()
	{
		cout << "Enter your name: ";
		string customer_name;
		getline(cin, customer_name);
		name = customer_name;
		cout << "HI ";
		for (int i = 0; i < customer_name.length(); i++) {
			cout << char(toupper(customer_name[i]));
		}
		cout << "\n\n\n";
	}

	// function to insert item in the data structure alloted
	// to customer
	void addToCart(string a, string b)
	{
		selected_items[a][b]++;
	}

	// function to print the bill during check-out
	void printBill()
	{
		int total_amount = 0;
		cout << "Category\t"
			<< "Item\t"
			<< "Quantity\t"
			<< "Cost\n";

		// iterators to traverse over respective maps
		map<string, map<string, int> >::iterator itr;
		map<string, int>::iterator ptr;
		for (itr = selected_items.begin();
			itr != selected_items.end(); itr++) {
			for (ptr = itr->second.begin();
				ptr != itr->second.end(); ptr++) {
				string category = itr->first;
				string model = ptr->first;
				int quantity = ptr->second;
				int temp
					= quantity * items[category][model];
				cout << category << "\t\t" << model << "\t"
					<< quantity << "\t\t" << temp << endl;
				total_amount += temp;
			}
		}

		cout << "-------------------------------"
			<< "-------------\n";
		cout << "Total amount:			 \t\t"
			<< total_amount << endl;
		cout << "-------------------------------"
			<< "-------------\n";
		cout << "*****THANK YOU && HAPPY"
			<< " ONLINE SHOPPING*****";
	}
};

// class shop to represent a real world entity - in our case
// a shop
class shop {

public:
	shop() {}

	virtual void show()
	{
		// this will be overridden
	}
	virtual void select(customer& obj)
	{
		// this will be overridden
	}

	void showMenu()
	{
		cout << "				 Menu\n";
		cout << " -----------------------------------------"
				"\n";
		cout << "1.Mobile\n2.Laptop\n3"
			<< ".Programming Courses\n4.Checkout\n\n";
		cout << " -----------------------------------------"
				"\n";
	}
};

// class mobile inheriting properties from class shop
class mobile : public shop {
public:
	void show()
	{
		cout << "- - - - - - - - - - -"
			<< " - -\nItem Cost\n";
		int cnt = 1;
		for (auto& it : items["Mobile"]) {
			cout << cnt++ << ". " << it.first << " --- Rs."
				<< it.second << "/-\n";
		}

		cout << "- - - - - - - - - - - - -\n\n";
	}

	void select(customer& obj)
	{
		cout << "These are the smartphone categories we "
				"have....\n";
		int num;
		cout << "Enter your selection\n";
		cin >> num;
		if (num < 1 || num > 3) {
			cout << "Wrong Input\n";
			return;
		}
		cout << "\n\nPURCHASE SUCCESSFULL!! ";
		cout << names[{ 1, num }]
			<< " IS ADDED TO THE CART\n\n";
		obj.addToCart("Mobile", names[{ 1, num }]);
	}
};

// class laptop inheriting properties from class shop
class laptop : public shop {
public:
	void show()
	{
		cout << "- - - - - - - - - - -"
			<< " - -\nItem Cost\n";
		int cnt = 1;
		for (auto& it : items["Laptop"]) {
			cout << cnt++ << ". " << it.first << " --- Rs."
				<< it.second << "/-\n";
		}
		cout << "- - - - - - - - - - - - -\n";
	}
	void select(customer& obj)
	{
		cout << "These are the laptop categories we "
				"have....\n";
		int num;
		cout << "Enter your selection\n";
		cin >> num;
		if (num < 1 || num > 3) {
			cout << "Wrong Input\n";
			return;
		}
		cout << "\n\nPURCHASE SUCCESSFULL!! ";
		cout << names[{ 2, num }]
			<< " IS ADDED TO THE CART\n\n";
		obj.addToCart("Laptop", names[{ 2, num }]);
	}
};

// class courses inheriting properties from class shop
class courses : public shop {
public:
	void show()
	{
		cout << "- - - - - - - - - - "
			<< " - -\nItem	 Cost\n";
		int cnt = 1;
		for (auto& it : items["Course"]) {
			cout << cnt++ << ". " << it.first << " --- Rs."
				<< it.second << "/-\n";
		}
		cout << "- - - - - - - - - - - - -\n";
	}
	void select(customer& obj)
	{
		cout << "These are the courses categories we "
				"have....\n";
		int num;
		cout << "Enter your selection\n";
		cin >> num;
		if (num < 1 || num > 4) {
			cout << "Wrong Input\n";
			return;
		}
		cout << "\n\nPURCHASE SUCCESSFULL!! ";
		cout << names[{ 3, num }]
			<< " IS ADDED TO THE CART\n\n";
		obj.addToCart("Course", names[{ 3, num }]);
	}
};

int main()
{
	// filling the hardcoded shop items in the data
	// structure
	fillItems();
	cout << "WELCOME TO OUR SHOP.\n";
	customer c;
	shop* s;

	while (1) {

		s->showMenu();
		cout
			<< "Please select an option to proceed "
			"further. If you choose to checkout, "
			"shopping will end and bill will be "
			"generated for the items bought so far...\n";
		int val;
		cin >> val;

		if (val == 1) {
			mobile mb;
			s = &mb;
			s->show();
			s->select(c);
		}
		else if (val == 2) {
			laptop lp;
			s = &lp;
			s->show();
			s->select(c);
		}
		else if (val == 3) {
			courses cs;
			s = &cs;
			s->show();
			s->select(c);
		}
		else if (val == 4) {
			c.printBill();
			break;
		}
		else {
			cout << "Wrong Input. If you want to checkout, "
					"you can press 4\n\n";
		}
		cout << "REDIRECTING TO THE MAIN MENU.....\n\n";

		// a function call to add a deliberate delay
		sleep_until(system_clock::now() + seconds(3));

		// clear screen
		system("cls");
	}

	return 0;
}
