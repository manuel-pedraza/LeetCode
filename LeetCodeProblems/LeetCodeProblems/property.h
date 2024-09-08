#ifndef PROPERTY_H__
#define PROPERTY_H__

#include <iostream>
#include <vector>

class Property
{
public:
    Property(const std::string& name) : m_name(name) {}
    virtual ~Property() {}
private:
    std::string m_name;
};


template<typename T>
class TypedProperty : public Property {
public:
    TypedProperty(const std::string& name, const T& data) : Property(name), m_data(data) {};
    T GetData();
private:
    T m_data;
};

template<typename T>
inline T TypedProperty<T>::GetData()
{
    return m_data;
}

typedef std::vector< std::shared_ptr<Property> > property_list_type;


#endif // !PROPERTY_H_


