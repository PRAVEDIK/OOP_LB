#include "StorageDevice.h"
#include <iostream>
#include <string>

using namespace std;


StorageDevice::StorageDevice(const char * name, TypeSD type, int size, double cost) :StorageDevice()// ����������� � �����������
{

	set_nameStoregeDevice(name); // ������ ���� 
	set_typeSD(type);// ������ ���� 
	set_sizeSD(size);// ������ ���� 
	set_costSD(cost);// ������ ���� 
}
StorageDevice::StorageDevice() { // ����������� �� ��������
	amount++; 
}

StorageDevice::StorageDevice(const StorageDevice & st) :StorageDevice(st.nameStoregeDevice, st.typeSD, st.sizeSD, st.costSD) // ���������� �����������
{

}

void StorageDevice::set_nameStoregeDevice(const char * name) //������
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
	if (costSD < 0) throw exception(" ���� �� ����� ����� ������������� ��������!!");
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
	cout << "�������� ����������: " << get_nameStoregeDevice() << endl;
	cout << "����� ������ ��: " << get_sizeSD() << " ��." << endl;
	cout << "��� ��: ";
	if (typeSD == TypeSD::Digital) cout << "��������";
	else if (typeSD == TypeSD::Analog) cout << "����������";
	cout << endl;
	cout << "��������� ��: " <<get_costSD() << " ���." << endl;
	cout << "���������� ���������: " << amount << endl;
}

StorageDevice::~StorageDevice() // ����������
{
	delete[] nameStoregeDevice;
	amount--;
}
int StorageDevice::amount = 0;
ostream& operator<<(ostream &v, const StorageDevice& Storagedevice) {
	v << "�������� ������������� ����������: " << Storagedevice.get_nameStoregeDevice() << endl;
	v << "����� ������ ��: " << Storagedevice.get_sizeSD() << " ��." << endl;
	v << "��� ��: ";
	if (Storagedevice.get_typeSD() == TypeSD::Digital) cout << "��������";
	else if (Storagedevice.get_typeSD() == TypeSD::Analog) cout << "����������";
	v << endl;
	v << "��������� ��: " << Storagedevice.get_costSD() << " ���." << endl;
	cout << "���������� ���������: " << Storagedevice.amount << endl;
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

