#ifndef INFORMATION_H__
#define INFORMATION_H__

#include <iostream>
#include <vector>
#include "property.h"

class Information {

	typedef bool (*Comparator)(Property*, Property*);

public:
	Information();
	Information(property_list_type lstTmp);
	Information(std::vector<Property*> lstTmp);
	~Information();
	void ChangePropData(int pos, Property* prop, void (*func)(int, Property*));
	int GetSize();
	Property* GetPropByPos(int pos);
	property_list_type GetList();
	bool Compare(Information output);
	void AddProperty(Property* prop);
	Comparator PropComparator = nullptr;


private:
	property_list_type list;

};

inline Information::Information()
{
}

inline Information::Information(property_list_type lstTmp)
{
	for (auto i : lstTmp) {
		list.push_back(i);
	}
}

inline Information::Information(std::vector<Property*> lstTmp)
{
	for (auto p : lstTmp) {
		this->AddProperty(p);
	}
}

inline void Information::ChangePropData(int pos, Property* prop, void(*func)(int, Property*))
{
	if(pos < GetSize())
		func(pos, prop);
}

inline int Information::GetSize()
{
	return list.size();
}

inline Property* Information::GetPropByPos(int pos)
{
	if (pos < GetSize())
		return list.at(pos).get();
	else
		return nullptr;
}

inline Information::~Information()
{
	while (!list.empty()){
		list.pop_back();
	}
}

inline property_list_type Information::GetList()
{
	return list;
}

inline bool Information::Compare(Information output)
{
	if (GetSize() != output.GetSize() || !PropComparator)
		return false;

	for (auto lp : list) {
		for (auto op : output.GetList()) {
			if (!PropComparator(lp.get(), op.get()))
				return false;
		}
	}

	return true;
}

inline void Information::AddProperty(Property* prop)
{
	std::shared_ptr<Property> shp(prop);
	list.push_back(shp);
	

	/*
	Property* pTmp = list.at(0).get();
	TypedProperty<int>* a = dynamic_cast<TypedProperty<int>*>(pTmp);


	std::cout << "PROPERTY " << std::endl;
	if (a)
		std::cout << "DATA: " << a->GetData() << std::endl;
	*/

	
}

#endif // !INFORMATION_H_