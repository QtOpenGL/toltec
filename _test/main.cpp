#include <iostream> 
#include <map>
#include <memory>
#include <string>
#include <vector>

class A
{
public:
    explicit A(int val) : m_int(val) {}
    void setInt(int val) { m_int = val; }
    int getInt() const { return m_int; }
private:
    int m_int;
};

class B
{
public:
    B() : mp_a(new A(4)) {}
    std::unique_ptr<A>& getA() { return mp_a; }
private:
    std::unique_ptr<A> mp_a;
};

int main(int argc, char* argv[])
{
    B b;
    std::cout << b.getA()->getInt() << std::endl;

    b.getA()->setInt(5);
    std::cout << b.getA()->getInt() << std::endl;

    return 0;
}