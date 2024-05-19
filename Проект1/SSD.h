#pragma once
#include "StorageDevice.h"

class SSDdisc :public StorageDevice {
public:
	SSDdisc(const char* name, TypeSD type, int size, double cost, double r) :StorageDevice(name, type, size, cost), Razm(r) {}
	void set_Razm(double r) { Razm = r; };
	double get_Razm()const { return Razm; };
	virtual string SubjectWrite() const {
		return "SSD";
	};
	void print()const {
		StorageDevice::print();
		cout << "Размер SSD форм-фактора M.2 (в см.): " << get_Razm() << endl << endl;
	}
private:
	double Razm;
};