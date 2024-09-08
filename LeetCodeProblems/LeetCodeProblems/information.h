#ifndef INFORMATION_H__
#define INFORMATION_H__

#include <iostream>
#include <vector>
#include "property.h"

class Information {

public:
	Information();
	~Information();
	property_list_type GetList();
	void AddProperty(std::shared_ptr<Property> prop);

private:
	property_list_type list;

};

inline Information::Information()
{
}

inline Information::~Information()
{
}

inline property_list_type Information::GetList()
{
	return list;
}

inline void Information::AddProperty(std::shared_ptr<Property> prop)
{
	/*
	property_list_type.push_back(prop);

	Property* p = new TypedProperty<int>("hi", 10);

	std::shared_ptr<Property> p2(p);

	property_list_type.push_back(p2);

	TypedProperty<int>* a = dynamic_cast<TypedProperty<int>*>(property_list_type.at(0).get());

	if (a)
		std::cout << "DATA: " << a->GetData() << std::endl;

	*/
	//property_list_type.push_back(std::shared_ptr<p>().get();
}

#endif // !INFORMATION_H_