#include <iostream> 
#include <map>
#include <string>
#include <vector>

const std::string& giveTheName()
{
	std::string theName = "Piotr Makal";
	return theName;
}

int main(int argc, char* argv[])
{
	std::string theName;

	theName = giveTheName();
	std::cout << theName << std::endl;

	return 0;
}