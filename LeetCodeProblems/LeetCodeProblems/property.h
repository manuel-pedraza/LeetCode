#ifndef PROPERTY_H__
#define PROPERTY_H__

#include <iostream>
#include <vector>

class Property
{
public:
    Property(){}
    virtual ~Property() {}
private:
};


template<typename T>
class TypedProperty : public Property {
public:
    TypedProperty(const std::string& name, const T& data) : m_name(name), m_data(data) {};
    T GetData();
    void SetData(T data);
    TypedProperty<T>* SetDataAndReturn(T data);
    bool Compare(TypedProperty tp);
private:
    std::string m_name;
    T m_data;
};


template<typename T>
inline T TypedProperty<T>::GetData()
{
    return m_data;
}

template<typename T>
inline void TypedProperty<T>::SetData(T data)
{
    m_data = data;
}

template<typename T>
inline TypedProperty<T>* TypedProperty<T>::SetDataAndReturn(T data)
{
    return new TypedProperty<T>(std::string(m_name), data);
}

template<typename T>
inline bool TypedProperty<T>::Compare(TypedProperty tp)
{
    return this->m_data == tp.m_data;
}

typedef std::vector< std::shared_ptr<Property>> property_list_type;


#endif // !PROPERTY_H_
