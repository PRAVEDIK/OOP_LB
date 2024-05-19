#pragma once
#include "StorageDevice.h"
#include "HDD.h"
#include "SSD.h"

class Hybrid : public HDDdisc, public SSDdisc {
public:
	Hybrid(const char* name, TypeSD type, int size, double cost, double speed, double r, double E) :HDDdisc(name, type, size, cost, speed), SSDdisc(name, type, size, cost, r), Energi(E) {}
	void set_Energi(double E) { Energi = E; };
	double get_Energi()const { return Energi; };
	virtual string SubjectWrite() const {
		return "Hybrid SD";
	};
	void print()const {
		StorageDevice::print();
		cout << "—корость фращени€ шпиндел€ в HDD диске: " << get_Speed() << endl;
		cout << "‘орм фактор SSD m2: " << get_Razm() << endl;
		cout << "Ёнергопотребление: " << get_Energi() << endl;
	}
private:
	double Energi;
};
