#include <iostream> 
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class A
{
public:
    A() : mp_int(new int(4)) {}
    virtual ~A() {}
private:
    std::unique_ptr<int>    mp_int;
};

enum Some {
    SOME_A,
    SOME_B
};

int main(int argc, char* argv[])
{
    int* p_someInt2 = new int(4);
    //std::unique_ptr<int> p_someInt(p_someInt2);

    std::map<Some, std::unique_ptr<int>> someMap;
    someMap.insert(std::make_pair(Some::SOME_A, p_someInt2));

    std::cout << *someMap[Some::SOME_A] << std::endl;

    return 0;
}