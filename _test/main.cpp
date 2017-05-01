#include <iostream> 
#include <map>
#include <string>
#include <vector>

#include <glm/glm.hpp>

class A
{
public:
    A() : m_value(99) {}
    ~A() {}

    void	setValue(int val) { m_value = val; }
    int		getValue() const { return m_value; }

protected:
    int m_value;
};

class B : public A
{
public:
    B() : m_value("haha") {}
    ~B() {}

    void			setValue(std::string val) { m_value = val; }
    std::string		getValue() const { return m_value; }

protected:
    std::string		m_value;
};

int main(int argc, char* argv[])
{
    B benc;
    int halo = benc.getValue();
}