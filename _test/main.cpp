#include <iostream> 
#include <map>
#include <string>
#include <vector>

class Node
{
public:
	virtual ~Node() {}
};

class CameraNavigation
{
public:
	virtual ~CameraNavigation() {}

	void tumble();
};

class TNode : public Node, public CameraNavigation
{
public:
	TNode() { x = 1; }
	virtual ~TNode() {}

private:
	int x;
};

int main(int argc, char* argv[])
{
	std::string theName;

	theName = giveTheName();
	std::cout << theName << std::endl;

	return 0;
}