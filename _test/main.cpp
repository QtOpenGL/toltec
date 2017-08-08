#include <algorithm>
#include <iostream> 
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class A
{
public:
    virtual ~A() {}

    std::vector<int>& getChildList() { return m_childList; }
private:
    std::vector<int> m_childList;
};

int main(int argc, char* argv[])
{
    A a;
    a.getChildList().push_back(1);
    a.getChildList().push_back(9);
    a.getChildList().push_back(2);
    a.getChildList().push_back(6);
    a.getChildList().push_back(7);

    for (const int& i : a.getChildList())
    {
        std::cout << i << std::endl;
    }

    auto iter = std::find(a.getChildList().begin(), a.getChildList().end(), 2);
    if (iter != a.getChildList().end())
        a.getChildList().erase(iter);

    std::cout << "-----------------------------" << std::endl;
    for (const int& i : a.getChildList())
    {
        std::cout << i << std::endl;
    }

    return 0;
}