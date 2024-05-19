#pragma once
#include "StorageDevice.h"

class Flash :public StorageDevice {
public:
	Flash(const char* name, TypeSD type, int size, double cost, double VR) :StorageDevice(name, type, size, cost), VerRaz(VR) {}
	void set_VerRaz(double VR) { VerRaz = VR; };
	double get_VerRaz()const { return VerRaz; };
	virtual string SubjectWrite() const {
		return "Flash";
	};
	void print()const {
		StorageDevice::print();
		cout << "Модель интерфейса USB: " << get_VerRaz() << endl << endl;
	}
private:
	double VerRaz;
};