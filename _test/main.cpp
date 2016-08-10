#include <iostream> 
#include <map>
#include <string>
#include <vector>

class Foo1
{
public:
	Foo1() { std::cout << "Foo1 created." << std::endl; var = 2; }
	int getVar() const { return var; }

private:
	int var;
};

class Foo2
{
public:
	Foo2 () { std::cout << "Foo2 created." << std::endl;}
	Foo2(const std::string& msg) { std::cout << msg << std::endl; }
};

class Bar
{
public:
	Bar() : m_foo2(Foo2("Foo2 created with argument."))
	{ 
		std::cout << "Bar created." << std::endl; 
		
		//UNDEFINED POINTER BEHAVIOR
		std::cout << "Foo1 var:\t" << mp_foo->getVar() << std::endl
			<< "Foo1 pointer:\t" << mp_foo << std::endl;

		std::cout << "------------------------------------------------\n";

		//NULLPTR POINTER BEHAVIOUR
		mp_foo = nullptr;
		std::cout << "Foo1 var:\tcrash" << /*mp_foo->getVar() <<*/ std::endl;
		std::cout << "Foo1 pointer:\t" << mp_foo << std::endl;

		std::cout << "------------------------------------------------\n";

		//DEFINED POINTER BEHAVIOUR
		mp_foo = new Foo1();
		std::cout << "Foo1 var:\t" << mp_foo->getVar() << std::endl
			<< "Foo1 pointer:\t" << mp_foo << std::endl;
	}

private:
	Foo1	m_foo;
	Foo2	m_foo2;

	Foo1*	mp_foo;

};

int main(int argc, char* argv[])
{
	Bar bar;

	return 0;
}