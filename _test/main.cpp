#include <iostream> 
#include <map>
#include <string>
#include <vector>


int main(int argc, char* argv[])
{
	std::map<int, std::string> myMap;

	myMap[1] = "alfa";
	std::cout << myMap[1] << std::endl;

	myMap[1] = "gamma";
	std::cout << myMap[1] << std::endl;

	return 0;
}