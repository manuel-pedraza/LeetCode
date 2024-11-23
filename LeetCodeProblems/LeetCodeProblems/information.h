#ifndef INFORMATION_H__
#define INFORMATION_H__

#include <iostream>
#include <vector>
#include "property.h"
#include <tuple>

class Information {

public:

	typedef bool (*Comparator) (Property*, Property*);
	Information();
	Information(property_list_type lstTmp);
	Information(std::vector<Property*> lstTmp);
	~Information();
	void ChangePropData(int pos, Property* prop, void (*func)(int, Property*));
	int GetSize();
	property_list_type GetList();
	bool Compare(Information output);
	void AddProperty(Property* prop);

	Property* GetPropByPos(int pos);
	
	template<typename T>
	TypedProperty<T>* GetTypedPropByPos(int pos);

	template<typename T>
	T GetValueByPos(int pos);

	Comparator PropComparator = nullptr;
	template<typename T>
	static std::tuple<bool, T, T> GeneralPropComparator(Property* prop1, Property* prop2);

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

template<typename T>
inline TypedProperty<T>* Information::GetTypedPropByPos(int pos)
{
	return dynamic_cast<TypedProperty<T>*>(GetPropByPos(pos));
}

template<typename T>
inline T Information::GetValueByPos(int pos)
{
	return GetTypedPropByPos<T>(pos)->GetData();
}

template<typename T>
inline std::tuple<bool, T, T> Information::GeneralPropComparator(Property* prop1, Property* prop2)
{
	TypedProperty<T>* out1 = dynamic_cast<TypedProperty<T>*>(prop1);
	TypedProperty<T>* out2 = dynamic_cast<TypedProperty<T>*>(prop2);

	if (!(out1 && out2)) return { false, T(), T() };

	T value1, value2;
	out1->SetDataByRef(value1);
	out2->SetDataByRef(value2);

	bool assertion = out1->Compare(*out2);

	return { assertion, value1, value2 };

	/*
	// code prior C++17:
	// Function:
	TypedProperty<T>* out1 = dynamic_cast<TypedProperty<T>*>(prop1);
	TypedProperty<T>* out2 = dynamic_cast<TypedProperty<T>*>(prop2);

	if (!(out1 && out2)) return std::make_tuple(false, T(), T());

	T value1, value2;
	out1->SetDataByRef(value1);
	out2->SetDataByRef(value2);

	bool assertion = out1->Compare(*out2);

	return std::make_tuple(assertion, value1, value2);
	// Function in use (for string):
	bool assertion;
	std::string received, expected;
	tie(assertion, received, expected) = GeneralPropComparator<bool, std::string, std::string>(p1, p2);
	*/
}

#endif // !INFORMATION_H_
