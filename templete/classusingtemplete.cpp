#include <iostream>
using namespace std;
template <typename T>
class Pair
{
    T x;
    T y;

 public:
    void setData(T x,T y)
    {
        this->x = x;
        this->y = y;
    }

    void showData()
    {
        cout << x << " " << y;
    }
};

int main()
{
    Pair<int> p1;
    p1.setData(1,2);
    p1.showData();
    return 0;
}