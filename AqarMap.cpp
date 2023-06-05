#include <iostream>
#include <string>
using namespace std;

bool loop = true;
static int user_in_controll = -1;
static int new_owner = 2, choice = 0;
static int list_of_apartments = 0;
static int Installements_of_apartments = 2;

struct location
{
	string StreetName;
	string City;
};

struct ApartmentInfo
{
	string Apartment_ID;
	string Apartment_PaymentMethod;
	int Apartment_price = 0;
	string Apartment_view;
	location Apartment_location;
};

struct ApartmentOwner
{
	string Owner_ID;
	string Owner_name;
	string Owner_password;
	string Owner_phone;
	ApartmentInfo List_of_apartments[5];
};

struct ApartmentInstallments
{
	string Apartment_ID;
	string Down_Payment;
	string Installements_Years;
	string Installements[10];
};

/************************************************************/

////////////////////////////////////////////////////////////////// default data base for the system ///////////////////////////////////////////////////////////////

static ApartmentOwner owners[10] = {
	{"#10","tarek","12345","011xxxxxx87",{ {"1001","Cash",100000,"garden","11","city1"},{"1002","Installements",500000,"street","Third Settlement", "city2"} } },
	{"#20","ahmed","14789","012xxxxxx45",{ {"1003","Installements",300000,"pool", "12","city3"},{"1004","Cash",450000,"nile", "Fifth Settlement","city4"} } }
};

static ApartmentInstallments Installements[10] = { {"1002","150000","3"},{"1003","250000","5"} };

/***********************************************************/

int first_menu(int& c)
{
	while (true)
	{
		cout << "\nPress 1 for owner or 2 for client : \n";
		cout << "Enter your choice : "; cin >> c;
		if ((c == 1) || (c == 2))
			break;
		else
			cout << "Invalid choice\n\n";
	}
	return c;
}

int owner_menu(int& c)
{
	while (true)
	{
		cout << "\n\nPress 1 to sign up or 2 to login : \n";
		cout << "Enter your choice : "; cin >> c;
		if ((c == 1) || (c == 2))
			break;
		else
			cout << "Invalid choice\n\n";
	}
	return c;
}

int client_menu(int& c)
{
	while (true)
	{
		cout << "\n\nPress 1 to search by location :\nPress 2 to search with certain price range :\nPress 3 to search by payment method :\nPress 4 to search by view :\n";
		cout << "Enter your choice : "; cin >> c;
		if ((c == 1) || (c == 2) || (c == 3) || (c == 4))
			break;
		else
			cout << "Invalid choice\n\n";
	}
	return c;
}

void sign_up()
{
	int j;
	j = new_owner;
	cout << "Choose username : \n";
	cin >> owners[j].Owner_name;
	cout << "Choose password : \n";
	cin >> owners[j].Owner_password;
	cout << "Enter your phone number :\n";
	cin >> owners[j].Owner_phone;
	cout << "Enter you ID :\n";
	cin >> owners[j].Owner_ID;
}

int login(int& k)
{
	static int user_in_controll = -1;
	while (loop)
	{
		string user;
		string password;
		int d = 0;

		cout << "\nEnter your user name : ";
		cin >> user;
		cout << "\nEnter your password : ";
		cin >> password;

		for (int i = 0; i < 10; i++)
		{
			if ((owners[i].Owner_name == user) && (owners[i].Owner_password == password))
			{
				cout << " \n--------------------Login successfully welcome to our system <3--------------------\n\n";
				loop = false;
				k = i;
				break;
			}
		}
		if (loop != false)
			cout << "Incorrect user name or password \n\n \n\n ";
		while (loop)
		{
			cout << "Do you want to re-enter your username and password\n1.yes\n2.no\n\n";
			cin >> d;
			if (d == 1 || d == 2)
				break;
			else
				cout << "Invalid choice";
		}
		if (d == 1)
			continue;
		else if (d == 2)
		{
			k = user_in_controll;
			break;
		}
	}
	loop = true;
	return k;
}

int second_menu(int& c)
{
	while (true)
	{
		cout << "Press 1 to advertise for an apartment :\nPress 2 to edit an advertisement :\n";
		cout << "Enter your choice : "; cin >> c;
		if ((c == 1) || (c == 2))
			break;
		else
			cout << "Invalid choise\n\n";
	}
	return c;
}

void Apartments_data_from_user()
{
	int j, c, h, u;
	j = new_owner;
	h = list_of_apartments;
	u = Installements_of_apartments;
	cout << "Apartment ID : "; cin >> owners[j].List_of_apartments[h].Apartment_ID;
	cout << "Apartment location --->\n";
	cout << "City : "; cin >> owners[j].List_of_apartments[h].Apartment_location.City;
	cout << "Street : "; cin >> owners[j].List_of_apartments[h].Apartment_location.StreetName;
	cout << "Price (must be number) : "; cin >> owners[j].List_of_apartments[h].Apartment_price;
	cout << "View : "; cin >> owners[j].List_of_apartments[h].Apartment_view;

	cout << "\nChoose the payment method you want for your apartment --->\n";
	cout << "1) Installements.\n2) Cash.\n";
	cout << "Enter your choice : "; cin >> choice;
	if (choice == 1)
	{
		owners[j].List_of_apartments[h].Apartment_PaymentMethod = "Installements";
		cout << "Down Payment : "; cin >> Installements[u].Down_Payment;
		cout << "Installment years : "; cin >> Installements[u].Installements_Years;
	}
	else if (choice == 2)
	{
		owners[j].List_of_apartments[h].Apartment_PaymentMethod = "Cash";
	}

	cout << "\n\nPress 1 to display your apparment info or press any other key to continue :\n\n";
	cin >> c;
	if (c == 1)
	{
		cout << "Apartment ID : " << owners[j].List_of_apartments[h].Apartment_ID << endl;
		cout << "Apartment location --->\n";
		cout << "City : " << owners[j].List_of_apartments[h].Apartment_location.City << endl;
		cout << "Street : " << owners[j].List_of_apartments[h].Apartment_location.StreetName << endl;
		cout << "Price : " << owners[j].List_of_apartments[h].Apartment_price << endl;
		cout << "View : " << owners[j].List_of_apartments[h].Apartment_view << endl;
		cout << "Payment method : " << owners[j].List_of_apartments[h].Apartment_PaymentMethod << "\n\n\n";
	}
	list_of_apartments++;
	new_owner++;
	Installements_of_apartments++;
}

void edit_apartments(int k)
{
	int j, h, u, c = 0;
	j = new_owner;
	h = list_of_apartments;
	u = Installements_of_apartments;
	ApartmentInfo edit;
	ApartmentInstallments edit2;

	cout << "\n\nEnter the new data of your apartment ----->>\n\n";
	cout << "Apartment ID : "; cin >> edit.Apartment_ID;
	cout << "Apartment location --->\n";
	cout << "City : "; cin >> edit.Apartment_location.City;
	cout << "Street : "; cin >> edit.Apartment_location.StreetName;
	cout << "Price (must be number) : "; cin >> edit.Apartment_price;
	cout << "View : "; cin >> edit.Apartment_view;

	cout << "\n\nChoose the payment method you want for your apartment --->\n";
	cout << "1) Installements.\n2) Cash.\n";
	cout << "Enter your choice : "; cin >> choice;
	if (choice == 1)
	{
		edit.Apartment_PaymentMethod = "Installements";
		cout << "Down Payment : "; cin >> edit2.Down_Payment;
		cout << "Installment years : "; cin >> edit2.Installements_Years;
	}
	else if (choice == 2)
	{
		edit.Apartment_PaymentMethod = "Cash";
	}

	owners[k].List_of_apartments[k].Apartment_ID = edit.Apartment_ID;
	owners[k].List_of_apartments[k].Apartment_location.City = edit.Apartment_location.City;
	owners[k].List_of_apartments[k].Apartment_location.StreetName = edit.Apartment_location.StreetName;
	owners[k].List_of_apartments[k].Apartment_price = edit.Apartment_price;
	owners[k].List_of_apartments[k].Apartment_view = edit.Apartment_view;
	owners[k].List_of_apartments[k].Apartment_PaymentMethod = edit.Apartment_PaymentMethod;
	Installements[k].Down_Payment = edit2.Down_Payment;
	Installements[k].Installements_Years = edit2.Installements_Years;

	cout << "\n\nYour apartment data has been updated.....\n";

	cout << "\n\nPress 1 to display your new apparment info or press any other key to continue :\n\n";
	cin >> c;
	if (c == 1)
	{
		cout << "Apartment ID : " << owners[k].List_of_apartments[k].Apartment_ID << endl;
		cout << "Apartment location --->\n";
		cout << "City : " << owners[k].List_of_apartments[k].Apartment_location.City << endl;
		cout << "Street : " << owners[k].List_of_apartments[k].Apartment_location.StreetName << endl;
		cout << "Price : " << owners[k].List_of_apartments[k].Apartment_price << endl;
		cout << "View : " << owners[k].List_of_apartments[k].Apartment_view << endl;
		cout << "Payment method : " << owners[k].List_of_apartments[k].Apartment_PaymentMethod << endl;
	}
}

/********************************************************/

void search_by_location()
{
	int j, num = 1;
	j = new_owner;
	bool valid = false;
	string location;
	while (true)
	{
		cout << "\n\nEnter the location of the city you want to search by : ";
		cin >> location;
		for (int i = 0; i < 10; i++)
		{
			for (int u = 0; u < 5; u++)
			{
				if (owners[i].List_of_apartments[u].Apartment_location.City == location)
				{
					cout << "\n\n***********************************\n\n";
					cout << "\nApartment " << num << " that exsist with this price range :\n\n";
					cout << "Owner info ---->\n\n";
					cout << "Name : " << owners[i].Owner_name << endl;
					cout << "ID : " << owners[i].Owner_ID << endl;
					cout << "Phone number : " << owners[i].Owner_phone << "\n\n";
					cout << "Apartment info ---->\n\n";
					cout << "Apartment ID : " << owners[i].List_of_apartments[u].Apartment_ID << endl;
					cout << "City : " << owners[i].List_of_apartments[u].Apartment_location.City << endl;
					cout << "Street : " << owners[i].List_of_apartments[u].Apartment_location.StreetName << endl;
					cout << "Price : " << owners[i].List_of_apartments[u].Apartment_price << endl;
					cout << "View : " << owners[i].List_of_apartments[u].Apartment_view << endl;
					if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Installements")
					{
						cout << "\nPayment method : Installements\n\n";
						cout << "Installment methods ---->\n\n";
						cout << "Down Payment : " << Installements[i].Down_Payment << endl;
						cout << "Installment years : " << Installements[i].Installements_Years << endl;
					}
					else if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Cash")
					{
						cout << "Payment method : Cash\n";
					}
					valid = true;
					num++;
				}
			}
		}
		if (valid == false)
		{
			cout << "\n\nApartment with this location does not exsist....\n\n\n";
		}
		cout << "\n\n***********************************\n\n";
		cout << "\nIf you want to continue press 1 or press any other key to go to first menu :\n";
		cout << "Enter your choice : "; cin >> choice;
		if (choice == 1)
		{
			num = 1;
		}
		else
			break;
		valid = false;
	}
}

void Search_with_certain_Price_Range()
{
	int j, num = 1, price1, price2;
	j = new_owner;
	bool valid = false;
	while (loop)
	{
		cout << "\n\nEnter the Price Range you want to search by ---->>\n";
		cout << "Enter the fisrt price range : "; cin >> price1;
		cout << "Enter the second price range : "; cin >> price2;
		for (int i = 0; i < 10; i++)
		{
			for (int u = 0; u < 5; u++)
			{
				if ((owners[i].List_of_apartments[u].Apartment_price >= price1) && (owners[i].List_of_apartments[u].Apartment_price <= price2))
				{
					cout << "\n\n***********************************\n\n";
					cout << "\nApartment " << num << " that exsist with this price range :\n\n";
					cout << "Owner info ---->\n\n";
					cout << "Name : " << owners[i].Owner_name << endl;
					cout << "ID : " << owners[i].Owner_ID << endl;
					cout << "Phone number : " << owners[i].Owner_phone << "\n\n";
					cout << "Apartment info ---->\n\n";
					cout << "Apartment ID : " << owners[i].List_of_apartments[u].Apartment_ID << endl;
					cout << "City : " << owners[i].List_of_apartments[u].Apartment_location.City << endl;
					cout << "Street : " << owners[i].List_of_apartments[u].Apartment_location.StreetName << endl;
					cout << "Price : " << owners[i].List_of_apartments[u].Apartment_price << endl;
					cout << "View : " << owners[i].List_of_apartments[u].Apartment_view << endl;
					if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Installements")
					{
						cout << "\nPayment method : Installements\n\n";
						cout << "Installment methods ---->\n\n";
						cout << "Down Payment : " << Installements[i].Down_Payment << endl;
						cout << "Installment years : " << Installements[i].Installements_Years << endl;
					}
					else if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Cash")
					{
						cout << "Payment method : Cash\n";
					}
					valid = true;
					num++;
				}
			}
		}
		if (valid == false)
		{
			cout << "\n\nApartment with this price range does not exsist....\n\n\n";
		}
		cout << "\n\n***********************************\n\n";
		cout << "If you want to continue press 1 or press any other key to go to first menu :\n";
		cout << "Enter your choice : "; cin >> choice;
		if (choice == 1)
		{
			loop = true;
			num = 1;
		}
		else
			loop = false;
		valid = false;
	}
}

void Search_by_payment_method()
{
	int j, num = 1, z = 0;
	j = new_owner;
	while (true)
	{
		cout << "1) Installements.\n2) Cash.\n";
		cout << "Enter your answer : "; cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int u = 0; u < 5; u++)
				{
					if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Installements")
					{
						cout << "\n\n***********************************\n\n";
						cout << "\nApartment " << num << " available with this payment method :\n\n";
						cout << "Owner info ---->\n\n";
						cout << "Name : " << owners[i].Owner_name << endl;
						cout << "ID : " << owners[i].Owner_ID << endl;
						cout << "Phone number : " << owners[i].Owner_phone << "\n\n";
						cout << "Apartment info ---->\n\n";
						cout << "Apartment ID : " << owners[i].List_of_apartments[u].Apartment_ID << endl;
						cout << "City : " << owners[i].List_of_apartments[u].Apartment_location.City << endl;
						cout << "Street : " << owners[i].List_of_apartments[u].Apartment_location.StreetName << endl;
						cout << "Price : " << owners[i].List_of_apartments[u].Apartment_price << endl;
						cout << "View : " << owners[i].List_of_apartments[u].Apartment_view << endl;
						cout << "Payment method : Installements\n\n";
						cout << "Installment methods ---->\n\n";
						cout << "Down Payment : " << Installements[i].Down_Payment << endl;
						cout << "Installment years : " << Installements[i].Installements_Years << endl;
						num++;
					}
				}
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int u = 0; u < 5; u++)
				{
					if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Cash")
					{
						cout << "\n\n***********************************\n\n";
						cout << "\nApartment " << num << " available with this payment method :\n\n";
						cout << "Owner info ---->\n\n";
						cout << "Name : " << owners[i].Owner_name << endl;
						cout << "ID : " << owners[i].Owner_ID << endl;
						cout << "Phone number : " << owners[i].Owner_phone << "\n\n";
						cout << "Apartment info ---->\n\n";
						cout << "Apartment ID : " << owners[i].List_of_apartments[u].Apartment_ID << endl;
						cout << "City : " << owners[i].List_of_apartments[u].Apartment_location.City << endl;
						cout << "Street : " << owners[i].List_of_apartments[u].Apartment_location.StreetName << endl;
						cout << "Price : " << owners[i].List_of_apartments[u].Apartment_price << endl;
						cout << "View : " << owners[i].List_of_apartments[u].Apartment_view << endl;
						cout << "Payment method : Cash\n";
						num++;
					}
				}
			}
		}
		cout << "\n\n***********************************\n\n";
		cout << "\nIf you want to continue press 1 or press any other key to go to first menu :\n";
		cout << "Enter your choice : "; cin >> choice;
		if (choice == 1)
		{
			num = 1;
		}
		else
			break;
	}
}

void search_by_view()
{
	int j, num = 1;
	j = new_owner;
	bool valid = false;
	string view;
	while (true)
	{
		cout << "\n\nEnter the view you want to search by : ";
		cin >> view;
		for (int i = 0; i < 10; i++)
		{
			for (int u = 0; u < 5; u++)
			{
				if (owners[i].List_of_apartments[u].Apartment_view == view)
				{
					cout << "\n\n*************\n\n";
					cout << "\nApartment " << num << " that exsist with this price range :\n\n";
					cout << "Owner info ---->\n\n";
					cout << "Name : " << owners[i].Owner_name << endl;
					cout << "ID : " << owners[i].Owner_ID << endl;
					cout << "Phone number : " << owners[i].Owner_phone << "\n\n";
					cout << "Apartment info ---->\n\n";
					cout << "Apartment ID : " << owners[i].List_of_apartments[u].Apartment_ID << endl;
					cout << "City : " << owners[i].List_of_apartments[u].Apartment_location.City << endl;
					cout << "Street : " << owners[i].List_of_apartments[u].Apartment_location.StreetName << endl;
					cout << "Price : " << owners[i].List_of_apartments[u].Apartment_price << endl;
					cout << "View : " << owners[i].List_of_apartments[u].Apartment_view << endl;
					if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Installements")
					{
						cout << "\nPayment method : Installements\n\n";
						cout << "Installment methods ---->\n\n";
						cout << "Down Payment : " << Installements[i].Down_Payment << endl;
						cout << "Installment years : " << Installements[i].Installements_Years << endl;
					}
					else if (owners[i].List_of_apartments[u].Apartment_PaymentMethod == "Cash")
					{
						cout << "Payment method : Cash\n";
					}
					valid = true;
					num++;
				}
			}
		}
		if (valid == false)
		{
			cout << "\n\nApartment with this view does not exsist....\n\n\n";
		}
		cout << "\n\n*************\n\n";
		cout << "\nIf you want to continue press 1 or press any other key to go to first menu :\n";
		cout << "Enter your choice : "; cin >> choice;
		if (choice == 1)
		{
			num = 1;
		}
		else
			break;
		valid = false;
	}
}

/******************************************************/

int main()
{
	cout << "\t\t\t\t\t**** Welcome to 'AqarMap' system ****\t\t\t\n\n\n\n";

	while (true)
	{
		while (true)
		{
			first_menu(choice);
			if (choice == 1)
			{
				owner_menu(choice);
				if (choice == 1)
				{
					sign_up();
					break;
				}
				else if (choice == 2)
				{
					login(user_in_controll);
				}
				second_menu(choice);
				if (choice == 1)
				{
					Apartments_data_from_user();
					break;
				}
				else if (choice == 2)
				{
					edit_apartments(user_in_controll);
					break;
				}
			}
			else if (choice == 2)
			{
				client_menu(choice);
				if (choice == 1)
				{
					search_by_location();
					break;
				}
				else if (choice == 2)
				{
					Search_with_certain_Price_Range();
					break;
				}
				else if (choice == 3)
				{
					Search_by_payment_method();
					break;
				}
				else if (choice == 4)
				{
					search_by_view();
					break;
				}
			}
		}
	}

	return 0;
}