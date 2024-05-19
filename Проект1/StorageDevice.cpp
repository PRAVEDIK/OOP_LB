#include "StorageDevice.h"
#include <iostream>
#include <string>

using namespace std;


StorageDevice::StorageDevice(const char * name, TypeSD type, int size, double cost) :StorageDevice()// конструктор с параметрами
{

	set_nameStoregeDevice(name); // Сеттер поля 
	set_typeSD(type);// Сеттер поля 
	set_sizeSD(size);// Сеттер поля 
	set_costSD(cost);// Сеттер поля 
}
StorageDevice::StorageDevice() { // конструктор по умолчнию
	amount++; 
}

StorageDevice::StorageDevice(const StorageDevice & st) :StorageDevice(st.nameStoregeDevice, st.typeSD, st.sizeSD, st.costSD) // копирующий конструктор
{

}

void StorageDevice::set_nameStoregeDevice(const char * name) //сеттер
{
	delete nameStoregeDevice;
	nameStoregeDevice = new char[strlen(name) + 1];
	strcpy_s(nameStoregeDevice, strlen(name) + 1, name);
}

void StorageDevice::set_typeSD(TypeSD type)
{
	typeSD = type;
}

void StorageDevice::set_sizeSD(int size)
{
	sizeSD = size;
}

void StorageDevice::set_costSD(double cost) throw(double)
{
	if (costSD < 0) throw exception(" Цена не может иметь отрицательное значение!!");
	costSD = cost;
}

const char * StorageDevice::get_nameStoregeDevice() const
{
	return nameStoregeDevice;
}

TypeSD StorageDevice::get_typeSD() const
{
	return TypeSD();
}


int StorageDevice::get_sizeSD() const
{
	return sizeSD;
}

double StorageDevice::get_costSD() const
{
	return costSD;
}

void StorageDevice::print() const
{
	cout << ">>> "<< SubjectWrite() <<" <<<"<< endl;
	cout << "Название устройства: " << get_nameStoregeDevice() << endl;
	cout << "Объём памяти ЗУ: " << get_sizeSD() << " Гб." << endl;
	cout << "Тип ЗУ: ";
	if (typeSD == TypeSD::Digital) cout << "Цифровое";
	else if (typeSD == TypeSD::Analog) cout << "Аналоговое";
	cout << endl;
	cout << "Стоимость ЗУ: " <<get_costSD() << " руб." << endl;
	cout << "Количество устройств: " << amount << endl;
}

StorageDevice::~StorageDevice() // диструктор
{
	delete[] nameStoregeDevice;
	amount--;
}
int StorageDevice::amount = 0;
ostream& operator<<(ostream &v, const StorageDevice& Storagedevice) {
	v << "Название запоминающего устройства: " << Storagedevice.get_nameStoregeDevice() << endl;
	v << "Объём памяти ЗУ: " << Storagedevice.get_sizeSD() << " Гб." << endl;
	v << "Тип ЗУ: ";
	if (Storagedevice.get_typeSD() == TypeSD::Digital) cout << "Цифровое";
	else if (Storagedevice.get_typeSD() == TypeSD::Analog) cout << "Аналоговое";
	v << endl;
	v << "Стоимость ЗУ: " << Storagedevice.get_costSD() << " руб." << endl;
	cout << "Количество устройств: " << Storagedevice.amount << endl;
	v << endl << endl;
	return v;
}

bool StorageDevice::operator==(int m)
{
	return sizeSD == m;
}

bool StorageDevice::operator>(const StorageDevice & right)
{
	return sizeSD > right.get_sizeSD();
}

