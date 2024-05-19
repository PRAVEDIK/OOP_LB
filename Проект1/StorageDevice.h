#pragma once
#include <String>
#include "TypeSD.h"
#include "IStorageDevice.h"
#include <iostream>
using namespace std;


class StorageDevice :public virtual IStorageDevice{     //10 Запоминающие устройства
public:
	StorageDevice();//Конструктор по умолчанию 
	StorageDevice(const char* name, TypeSD type, int size, double cost);// Конструктор с параметрами
	StorageDevice(const StorageDevice& st);//Копирующий конструктор

	void set_nameStoregeDevice(const char* name); // Сеттер поля имени
	void set_typeSD(TypeSD type);// Сеттер поля типа
	void set_sizeSD(int size);// Сеттер поля размера 
	void set_costSD(double cost);// Сеттер поля стоимости

	const char* get_nameStoregeDevice()const;//геттер имени
	TypeSD get_typeSD()const;//геттер типа
	int get_sizeSD()const;//геттер размера 
	double get_costSD()const;//геттер геттер стоимости 

	void print()const;//Вывод
	~StorageDevice();//диструктор
	// Операторы
	bool operator== (int m);
	bool operator>(const StorageDevice& right);
	friend ostream& operator<<(ostream &v, const StorageDevice& Storagedevice);

protected:
	virtual string SubjectWrite() const = 0;
private:
	char* nameStoregeDevice; // название ЗУ
	TypeSD typeSD; // тип ЗУ
	int sizeSD; // размер ЗУ
	double costSD; // стоимость ЗУ
	static int amount;
};

