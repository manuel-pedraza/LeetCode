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
    TypedProperty( const T& data) :  m_data(data) {};
    T GetData();
    void SetData(T data);
    void SetDataByRef(T& data);
    bool Compare(TypedProperty tp);
private:
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
inline void TypedProperty<T>::SetDataByRef(T& data)
{
    data = this->m_data;
}

template<typename T>
inline bool TypedProperty<T>::Compare(TypedProperty tp)
{
    //if(tp)

    return this->m_data == tp.m_data;
}

typedef std::vector< std::shared_ptr<Property>> property_list_type;


#endif // !PROPERTY_H_
