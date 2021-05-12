#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <array>

using namespace std;

template<typename I>
void increase(I first, I last, int number)
{
	while(first!=last)
	{
		*first+=number;
		++first;
	}
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (Iter1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
{	
	array<int, 10> int_array {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> int_vec {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> int_list {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	array<int, 10> int_array_2 = int_array;
	vector<int> int_vec_2 = int_vec;
	list<int> int_list_2 = int_list;

	increase(int_array_2.begin(), int_array_2.end(), 2);
	increase(int_vec_2.begin(), int_vec_2.end(), 3);
	increase(int_list_2.begin(), int_list_2.end(), 5);

	my_copy(int_array_2.begin(), int_array_2.end(), int_vec_2.begin());
	my_copy(int_list_2.begin(), int_list_2.end(), int_array_2.begin());

	int value=3;
	int value2=27;

	auto place=find(int_vec.begin(), int_vec.end(), value);
	if (place!=int_vec.end())
        cout<<"Value found at: " <<distance(int_vec.begin(), place)<<endl;
    else
        cout<<"Value is not found."<<endl;

    auto place2=find(int_list.begin(), int_list.end(), value2);
    if (place2!=int_list.end())
        cout<<"Value2 is found at: "<<distance(int_list.begin(), place2)<<endl;
    else
        cout<<"Value2 is not found."<<endl;
}	
