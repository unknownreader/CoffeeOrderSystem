#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
using namespace std;

int main(int argc, char *argv[])
{
	string coffee;
	char answer = ' ';

	string listcoffee[10];
	int listprices[10];
	int orderCount = 0;
	int total = 0;

	int result = 0;

	string request = " ";
	int request1 = 0;
	int request2 = 0;
	int request3 = 0;

	string request11 = " ";
	string request22 = " ";
	string request33 = " ";

	string req11[10];
	string req22[10];
	string req33[10];

	int prices;

	// awalan untuk repeat code dari awal

	while (true)
	{
		cout << "\nList of Menu | Price\n"
			 << "\n"
			 << "Cappucino"
			 << " | 25K\n"
			 << "Latte"
			 << " | 20K\n"
			 << "Espresso"
			 << " | 15K\n"
			 << "Americano"
			 << " | 20K\n"
			 << "Drip Coffee"
			 << " | 25K\n";

		cout << "\nWhat type of coffee that you want to order?";

		// Untuk data nya bisa membaca 2 suku kata atau lebih selama masih satu baris
		getline(cin, coffee);

		//to turn off the case sensitivity
		for (char &c : coffee)
		{
			if (c >= 'A' && c <= 'Z')
			{
				c += 32;
			}
		}

		listcoffee[orderCount] = coffee;

		if (coffee == "cappucino")
		{
			prices = 25;
		}
		else if (coffee == "latte")
		{
			prices = 20;
		}
		else if (coffee == "espresso")
		{
			prices = 15;
		}
		else if (coffee == "americano")
		{
			prices = 20;
		}
		else if (coffee == "drip coffee")
		{
			prices = 25;
		}
		else
		{
			prices = 0;
			cout << "\nPlease input the correct item !\n";
			continue;
		}

		for (char &c : coffee)
		{
			if (c >= 'a' && c <= 'z')
			{
				c -= 32;
			}
		}

		listcoffee[orderCount] = coffee;
		listprices[orderCount] = prices;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// REQUEST SECTION

		if (coffee != "ESPRESSO")
		{
			cout << "\nIs there any request that you want? (y/n) ";
			cin >> answer;

			if (answer == 'y')
			{
				request11 = "none";
				request22 = "none";
				request33 = "none";

				for (int i = 0; i < 3; i++)
				{
					cout << "\nList of Request : Sugar (1) Temperature (2) Type of Milk (3) ";

					cin >> result;

					//  Request Sugar
					if (result == 1)
					{
						cout << "\nMore (1) Normal (2) Less (3) ";
						cin >> request1;

						switch (request1)
						{
						case 1:
							request11 = "More Sugar";
							break;

						case 2:
							request11 = "Normal Sugar";
							break;

						case 3:
							request11 = "Less Sugar";
							break;

						default:
							request11 = "Special Custom";
							cout << "\nSpecial Custom";
							return 0;
						}
					}

					//  Request Temperature
					else if (result == 2)
					{
						cout << "\nHot (1) Iced (2) ";
						cin >> request2;

						switch (request2)
						{
						case 1:
							request22 = "Hot";
							break;

						case 2:
							request22 = "Iced";

							break;

						default:
							request22 = "Special Custom";
							cout << "\nSpecial Custom";
						}
					}

					else if (result == 3 && (coffee == "LATTE" || coffee == "CAPPUCINO"))
					{
						cout << "\nFull Cream (1) Oat Milk (2) Almond (3) ";
						cin >> request3;

						switch (request3)
						{
						case 1:
							request33 = "Full Cream";
							break;

						case 2:
							request33 = "Oat Milk";

							break;

						case 3:
							request33 = "Almond Milk";

							break;

						default:
							request33 = "Special Custom";

							cout << "\nSpecial Custom";
						}
					}

					else
					{
						cout << "\nPlease tell our employee if you have special request";
					}
				}
			}

			else
			{
				request11 = "none";
				request22 = "none";
				request33 = "none";
			}
		}

		else
		{
			request11 = "none";
			request22 = "none";
			request33 = "none";
		}

		req11[orderCount] = request11;
		req22[orderCount] = request22;
		req33[orderCount] = request33;
		orderCount++;

		//lanjutan code untuk bisa repeat

		cout << "\nIs there anything you would like to order ? (y/n)";
		cin >> answer;

		if (answer == 'n' || answer == 'N')
		{
			cout << "\nYour order is:\n "
				 << "\n";
			for (int i = 0; i < orderCount; i++)
			{
				cout << listcoffee[i] << "\nWith request: " << req11[i] << " + " << req22[i] << " + " << req33[i] << "\nWith Price :" << listprices[i] << "K\n"
					 << "\n";

				total += listprices[i];
			}

			cout << " \nWith total : " << total << "K";

			cout << "\nThank you for your order, please wait.\n";

			break;
		}

		cin.get();
	}
}
