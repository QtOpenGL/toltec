#include <algorithm>
#include <iostream> 
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<int> someV = { 9, 8, 2, 5, 2, 4 };
    unsigned int index = 0;
    std::size_t someVSize = someV.size();

    for (; index < someVSize; index++)
    {
        if (someV[index] == 5)
            break;
    }

    std::cout << index << std::endl;

    return 0;
}