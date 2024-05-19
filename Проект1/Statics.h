#pragma once
#include <map>
#include "StorageDevice.h" // Header
#include <iostream>
#include "TemplateTree.h"
class Statics
{
public:
	double SummCost(IStorageDevice* sd);
	double SummCost(TemplateTree<IStorageDevice>* tr);
	void print();
private:
	map<IStorageDevice*, int> Stats;
	double Costsum;
};

