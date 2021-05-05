#include "std_lib_facilities.h"

template<typename T> 
struct S
{
    private:
       T val;
       T n_val;
    public:   
	   explicit S(T v=0) : val{v} {};
       
	   T& get();
	   const T& get() const;

	   void set(T n_val) {val=n_val;};
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
void read_val(T& v)
{
	cin>>v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    os<<"{";
    for(int i=0; i<v.size(); ++i)
    {
        os<<v[i]<<(i<v.size()-1?", ");
    }
    os<<"}\n";

    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    char c=0;
    is>>c;
    if(c!='{'){
        is.unget();
        return is;
    }
    for(T val; is>>val;){
        v.push_back(val);
        is>>c;
        if (c!=',') break;
    }
    return is;
}

int main()
{
	S<int> S_int {8};
        cout<<S_int.get()<<endl;

	S<char> S_char {'p'};
        cout<<S_char.get()<<endl;

	S<double> S_double {14.5};
        cout<<S_double.get()<<endl;

	S<string> S_string {"Lalyos"};
        cout<<S_string.get()<<endl;

	S<vector<int>> S_vector {vector<int>{11, 22, 33, 69}};
        cout<<S_vector.get()<<endl;

    int i;
    cout<<"Int: ";
    read_val(i);
    S<int> S_int2 {i};
    cout<<S_int2.get()<<endl;

    char c;
    cout<<"Char: ";
    read_val(c);
    S<char> S_char2 {c};
    cout<<S_char2.get()<<endl;

    double d;
    cout<<"Double: ";
    read_val(d);
    S<double> S_double2 {d};
    cout<<S_double2.get()<<endl;

    string s;
    cout<<"String: ";
    read_val(s);
    S<string> S_string2 {s};
    cout<<S_string2.get()<<endl;

    vector<int> v2;
    cout<<"Vector<int> { val1, val2, val3 }: ";
    read_val(v2);
    S<vector<int>> S_vector2 {v2};
    cout<<S_vector2.get();
    
    return 0;
}
