#include <iostream>
#include <vector>

using namespace std;

class Student
{
	public:
		
		int id;
		int grade;
		int age;
		
		char gender;
		
		string name;
		string surname;
		
		void print_info()
		{
			cout << "ID: " << id << "\n";
			cout << "Grade: " << grade << "\n";
			cout << "Age: " << age << "\n";
			cout << "Gender: " << gender << "\n";
			cout << "Name: " << name << "\n";
			cout << "Surname: " << surname << endl;

			return;
		}
		
		Student(int id, int grade, int age, char gender, string name, string surname)
		{
			this -> id = id;
			this -> grade = grade;
			this -> age = age;
			this -> name = name;
			this -> surname = surname;
		}
		
		Student(){};
};

struct Node
{
	Node *left_node = NULL;
	Node *right_node = NULL;
	
	Student *student = NULL;
};

void add_nodes_by_age(Node *root, Student &student)
{
	if (student.age < root -> student -> age)
	{
		if (root -> left_node == NULL)
		{
			root -> left_node = new Node;
			root -> left_node -> student = &student;
		}

		else
		{
			return add_nodes_by_age(root -> left_node, student);
		}
	}
	
	else
	{
		if (root -> right_node == NULL)
		{
			root -> right_node = new Node;
			root -> right_node -> student = &student;
		}

		else
		{
			return add_nodes_by_age(root -> right_node, student);
		}
	}
	
	return;
}

void add_nodes_by_age(Node *root, vector <Student> &array)
{
	for (int i = 0; i < array.size(); i++)
	{
		add_nodes_by_age(root, array[i]);
	}
	
	return;
}

void search_by_age(Node *root, int age)
{
	if (root -> student -> age == age)
	{
		root -> student -> print_info();
		return;
	}
	
	bool left_is_null = false;
	bool right_is_null = false;
	
	if (root -> left_node == NULL) left_is_null = true;
	if (root -> right_node == NULL) right_is_null = true;
	
	if (left_is_null and right_is_null)
	{
		cout << "No student exists with the given age." << endl;
		return;
	}
	
	if (age < root -> student -> age)
	{
		if (left_is_null == false)
		{
			return search_by_age(root -> left_node, age);
		}
	}
	
	else
	{
		if (right_is_null == false)
		{
			return search_by_age(root -> right_node, age);
		}
	}
}

////

int main()
{
	Node root;
	root.student = new Student(0, 0, 0, 'n', " ", " ");
	
	Student a(0, 5, 8, 'm', "Jerome", "Bludmonette");
	Student b(1, 9, 14, 'm', "Zigga", "Mabigga");
	Student c(2, 10, 16, 'm', "Jigsaw", "Tripper");
	Student d(3, 1, 6, 'f', "Lily", "Bro");
	
	vector <Student> array;
	
	array.push_back(a);
	array.push_back(b);
	array.push_back(c);
	array.push_back(d);
	
	add_nodes_by_age(&root, array);
	
	search_by_age(&root, 6);
	
	return 0;
}
