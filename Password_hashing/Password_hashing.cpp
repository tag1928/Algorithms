#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

const char allowed_chars[] =
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', //10
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', //26
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' //26
};

class User
{	
	public:
		
		string name;
		string password;
		
		User(string name, string password)
		{
			this -> name = name;
			this -> password = password;
		}
};

string hash_string(string input)
{
	string output = "";
	
	const int string_size = 64;
	
	if (input.size() < string_size)
	{
		int input_cursor = 0;
		
		for (int i = 0; i < string_size; i++)
		{
			output += input[input_cursor];
			input_cursor++;
			
			if (input_cursor >= input.size())
			{
				input_cursor = 0;
			}
		}
	}
	
	else
	{
		output = input.substr(0, string_size);
	}
	
	//
	
	int constant_n = input.size();
	int constant_s = 0;
	
	long int buffer = 0;
	
	for (int i = 0; i < string_size; i++)
	{
		constant_s += (int)output[i];
	}
	
	for (int i = 0; i < string_size; i++)
	{
		buffer = (int)output[i] + constant_n + constant_s + i;
		
		output[i] = allowed_chars[buffer % 62];
	}
	
	return output;
}

void sign_in()
{
	ofstream jamal("users.txt", ios::app);
	string input;
	
	cout << "Username: ";
	
	cin >> input;
	
	jamal << hash_string(input) << "\n";
	
	cout << "Password: ";
	
	cin >> input;
	
	jamal << hash_string(input) << "\n";
		
	return;
}

void login()
{
	ifstream jamal("users.txt");
	
	vector <User> array;
	
	while(!jamal.eof())
	{
		string name;
		string surname;
		
		getline(jamal, name);
		getline(jamal, surname);
		
		array.push_back(User(name, surname));
	}
	
	string input;
	
	cout << "Username: ";
	
	cin >> input;
	
	for (int i = 0; i < array.size(); i++)
	{
		if (hash_string(input) == array[i].name)
		{
			cout << "Password: ";
			cin >> input;
			
			if (hash_string(input) == array[i].password)
			{
				cout << "Welcome!" << endl;
				return;
			}
			
			else
			{
				cout << "Sorry, wrong password" << endl;
				return login();
			}
		}
	}
	
	cout << "No such user exists." << endl;
	
	return;
}

int main()
{
	int option;
	
	cout << "Sign in or login?" << "\n";
	cout << "1. Sign in." << "\n" << "2. Login." << "\n" << "3. Exit." << endl;
	
	cin >> option;
	
	switch(option)
	{
		case 1: sign_in(); break;
		case 2: login(); break;
		case 3: return 0;
	}
	
	return main();
}
