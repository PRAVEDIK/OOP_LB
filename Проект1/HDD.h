#pragma once
#include "StorageDevice.h"
#include <iostream>

class HDDdisc :public StorageDevice {
public:
	HDDdisc(const char* name, TypeSD type, int size, double cost, int speed) :StorageDevice(name, type, size, cost), Speed(speed) {}
	void set_Speed(double speed) throw(int) { 
		if (Speed >20000) throw overflow_error("Невозможная скорость вращения");
		Speed = speed; };
	int get_Speed() const { return Speed; };
	virtual string SubjectWrite() const {
		return "HDD";
	};
	void print()const {
		StorageDevice::print();
		cout << "Скорость вращения шпинделя: " << get_Speed() << endl << endl;
	}
private:
	int Speed;
};