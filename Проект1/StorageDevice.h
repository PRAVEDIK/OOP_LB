#pragma once
#include <String>
#include "TypeSD.h"
#include "IStorageDevice.h"
#include <iostream>
using namespace std;


class StorageDevice :public virtual IStorageDevice{     //10 ������������ ����������
public:
	StorageDevice();//����������� �� ��������� 
	StorageDevice(const char* name, TypeSD type, int size, double cost);// ����������� � �����������
	StorageDevice(const StorageDevice& st);//���������� �����������

	void set_nameStoregeDevice(const char* name); // ������ ���� �����
	void set_typeSD(TypeSD type);// ������ ���� ����
	void set_sizeSD(int size);// ������ ���� ������� 
	void set_costSD(double cost);// ������ ���� ���������

	const char* get_nameStoregeDevice()const;//������ �����
	TypeSD get_typeSD()const;//������ ����
	int get_sizeSD()const;//������ ������� 
	double get_costSD()const;//������ ������ ��������� 

	void print()const;//�����
	~StorageDevice();//����������
	// ���������
	bool operator== (int m);
	bool operator>(const StorageDevice& right);
	friend ostream& operator<<(ostream &v, const StorageDevice& Storagedevice);

protected:
	virtual string SubjectWrite() const = 0;
private:
	char* nameStoregeDevice; // �������� ��
	TypeSD typeSD; // ��� ��
	int sizeSD; // ������ ��
	double costSD; // ��������� ��
	static int amount;
};

