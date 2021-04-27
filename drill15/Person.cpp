#include "std_lib_facilities.h"
using namespace std;

struct Person
{
	private:
	string first_name;
	string last_name;
	int age;

	public:
	Person(){};
	Person(string first, string last, int a)
	{
		for(char x : first){
			switch(x){
			case ';': case ':': case '"':
			case '/': case '[': case ']': 
			case '*': case '&': case '^': 
			case '%': case '$': case '#': 
			case '@': case '!':
				error("Wrong frist name");
			}
		}
		for(char x : last){
			switch(x){
			case ';': case ':': case '"':
			case '/': case '[': case ']': 
			case '*': case '&': case '^': 
			case '%': case '$': case '#': 
			case '@': case '!':
				error("Wrong last name");
			}
		}
		if (a<0 || a>150) error("Wrong age");

		first_name=first;
		last_name=last;
		age=a;
	}

	string func_first() const {
		return first_name;
	}
	string func_last() const {
		return last_name;
	}
	int func_age() const {
		return age;
	}

};

	ostream& operator<< (ostream& os, Person& p)
	{
	return os<<p.func_first()<<' '<<p.func_last()<<' '<<p.func_age();		
	}

	istream& operator>> (istream& is, Person& p)
	{
		string first;
		string last;
		int a;

		is>>first>>last>>a;

		p = Person(first,last,a);

		return is;
	}

int main()
{
	Person p2;

	cout<<"What's your first name, last name and age?"<<endl;
	cin>>p2;
	cout<<p2<<endl;

	vector<Person> ppl;
	cout<<"What's your first name, last name and age?(vector)"<<endl;
	Person y;
	int number=0;
	while(cin>>y)
	{
		ppl.push_back(y);
		cout<<ppl[number]<<endl;
		++number;
	}

	return 0;
}
