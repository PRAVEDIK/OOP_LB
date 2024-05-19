#pragma once
#include <iostream>
using namespace std;

class IStorageDevice {
public:// סועעונû
	virtual void set_nameStoregeDevice(const char* name) = 0;
	virtual void set_typeSD(TypeSD type) = 0;
	virtual void set_sizeSD(int size) = 0;
	virtual void set_costSD(double cost) = 0;
	// דועוננû
	virtual const char* get_nameStoregeDevice()const = 0;
	virtual TypeSD get_typeSD()const = 0;
	virtual int get_sizeSD()const = 0;
	virtual double get_costSD()const = 0;

	virtual void print()const = 0;
};