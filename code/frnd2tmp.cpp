// template clas with non-template friends
#include <iostream>
// #include <cstdlib>
using std::cout;
using std::endl;
using std::string;

// template <typename T>
// void report(T &);

template <typename T>
class HasFriend
{
  private:
    T item;
    static int ct;

  public:
    HasFriend(const T &i) : item(i) { ct++; }
    ~HasFriend() { ct--; }
    friend void counts();
    friend void reports(HasFriend<T> &); // template parameter
};

// each specialization has its onw static data member
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
template <typename T>
void counts()
{
    cout << "int count: " << HasFriend<T>::ct << " \t double count: "<<endl;
        //  << HasFriend<double>::ct << " \t string count: " << HasFriend<string>::ct << endl;
}

// not-template friend to the hasFriend<T> classes
// template <typename T>
void reports(HasFriend<int> &hf)
{
    cout << "HasFriend: " << hf.item << endl;
}

void reports(HasFriend<double> &hf)
{
    cout << "HasFriend: " << hf.item << endl;
}

void reports(HasFriend<string> &hf)
{
    cout << "HasFriend: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts<double>();

    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts<int>();
    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts<int>();
    HasFriend<double> hfd1(10.4);
    cout << "After hfd1 declared: ";
    counts<double>();
    HasFriend<string> hfs1("string");
    cout << "After hfs1 declared: ";
    counts<string>();
    reports(hfi1);
    reports(hfi2);
    reports(hfd1);
    reports(hfs1);

    return 0;
}