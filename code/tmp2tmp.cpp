// template clas with non-template friends
#include <iostream>
// #include <cstdlib>
using std::cout;
using std::endl;
using std::string;

template <typename T>
void reports(T &);
template <class T>
void counts();

template <typename T>
class HasFriendT
{
  private:
    T item;
    static int ct;

  public:
    HasFriendT(const T &i) : item(i) { ct++; }
    ~HasFriendT() { ct--; }
    friend void counts<T>();
    friend void reports<>(HasFriendT<T> &); // template parameter
};

// each specialization has its onw static data member
template <typename T>
int HasFriendT<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template count: " << HasFriendT<T>::ct << endl;
}

// not-template friend to the hasFriend<T> classes
template <typename T>
void reports(T &hf)
{
    cout << "HasFriend: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts<int>();

    HasFriendT<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts<int>();
    counts<double>();

    HasFriendT<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts<int>();
    HasFriendT<double> hfd1(10.4);
    cout << "After hfd1 declared: ";
    counts<double>();
    HasFriendT<string> hfs1("string");
    cout << "After hfs1 declared: ";
    counts<string>();
    reports(hfi1);
    reports(hfi2);
    reports(hfd1);
    reports(hfs1);

    return 0;
}