#include <iostream> 
#include <map>
#include <memory>
#include <string>
#include <vector>

class Uniform
{
public:
    //TYPES
    enum Classification {
        NONE,
        UNIT,
        CONTAINER
    };

    Uniform() : m_classification(Uniform::Classification::NONE) {}
    virtual ~Uniform() {}

    Uniform::Classification getClassification() const { return m_classification; }
    virtual void findLocations() { std::cout << "Uniform\n"; }

protected:
    Uniform::Classification m_classification;
};

class UniformUnit : public Uniform
{
public:
    UniformUnit() { m_classification = Uniform::Classification::UNIT; }
    virtual ~UniformUnit() {}

    virtual void findLocations() { std::cout << "UniformUnit\n"; }
};

class UniformContainer : public Uniform
{
public:
    //TYPES
    enum Type {
        NONE,
        ARRAY,
        STRUCT
    };

    UniformContainer() { m_classification = Uniform::Classification::CONTAINER; }
    virtual ~UniformContainer() {}

    virtual void findLocations() { std::cout << "UniformContainer\n"; }

protected:
    UniformContainer::Type m_type;
};

class UniformArray : public UniformContainer
{
public:
    UniformArray() { m_type = UniformContainer::Type::ARRAY; }
    virtual ~UniformArray() {}

    virtual void findLocations() { std::cout << "UniformArray\n"; }
};

class UniformStruct : public UniformContainer
{
public:
    UniformStruct() { m_type = UniformContainer::Type::STRUCT; }
    virtual ~UniformStruct() {}

    virtual void findLocations() { std::cout << "UniformStruct\n"; }
};

int main(int argc, char* argv[])
{
    std::vector<std::unique_ptr<Uniform>> uniformList;

    std::unique_ptr<UniformUnit> p_uniformUnit(new UniformUnit);
    uniformList.push_back(std::move(p_uniformUnit));

    std::unique_ptr<UniformArray> p_uniformArray(new UniformArray);
    uniformList.push_back(std::move(p_uniformArray));

    std::unique_ptr<UniformStruct> p_uniformStruct(new UniformStruct);
    uniformList.push_back(std::move(p_uniformStruct));

    for (auto& p_uniform : uniformList)
    {
        if (p_uniform->getClassification() == Uniform::Classification::CONTAINER)
        {
            //UniformContainer* p_uniformContainer = static_cast<UniformContainer*>(p_uniform.get());
            //p_uniformContainer->findLocations();
            p_uniform->findLocations();
        }
        else
        {
            //UniformUnit* p_uniformUnit = static_cast<UniformUnit*>(p_uniform.get());
            //p_uniformUnit->findLocations();
            p_uniform->findLocations();
        }
    }

    return 0;
}