#include "StorageDevice.h" // Header
#include "TypeSD.h"
#include "SSD.h"
#include "HDD.h"
#include "Flash.h"
#include "Hybrid.h"
#include <iostream>
#include "TemplateTree.h"
#include "Statics.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	//////Конструктор по умолчанию//////
	//StorageDevice HDD2;
	//HDD2.set_nameStoregeDevice("Жёсткий диск");
	//HDD2.set_costSD(800);
	//HDD2.set_typeSD(TypeSD::Analog);
	//HDD2.set_sizeSD(32);
	////Конструктор c параметрами//////
	//StorageDevice HDD("Жёсткий диск WD", TypeSD::Digital, 512, 3000);
	//StorageDevice FLASH("Флешка", TypeSD::Analog, 32, 800);
	//StorageDevice SSD("SSD диск", TypeSD::Digital, 256, 2900);

	////////Копирующий конструктор//////
	//StorageDevice flash2(FLASH);
	//TemplateTree<IStorageDevice> Tr;
	//Tr.Add(&HDD);
	//Tr.Add(&HDD2);
	//Tr.Add(&FLASH);
	//Tr.Add(&SSD);
	//Tr.Add(&flash2);
	//Tr.Add(&FLASH);
	//Tr.Add(&SSD);
	//Tr.Add(&HDD2);
	//Tr.Add(&FLASH);
	//Tr.Show();


	/*Tr.Show();
	cout << "|||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "Поиск по объёму памяти" << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||" << endl;
	Tr.Search_Memory(32);
	cout << endl;
	Tr.Sorting();
	cout << "|||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "Отсортированное дерево:" << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||" << endl;
	Tr.Show();*/

	/*if (SSD > FLASH) {
		cout << SSD.get_nameStoregeDevice();
		cout << " больше по объёму чем ";
		cout << FLASH.get_nameStoregeDevice();
	}
	else
	{
		cout << FLASH.get_nameStoregeDevice();
		cout << " больше по объёму чем ";
		cout << SSD.get_nameStoregeDevice();
	}
	cout << endl;	*/


	HDDdisc hdd("hdd диск wd", TypeSD::Digital, 1024, -5000.0, 90000);
	
	SSDdisc ssddisc("ssd диск toshiba", TypeSD::Analog, 512, 3000, 3.5);
	
	Flash flash("флешка samsung", TypeSD::Analog, 64, 1600, 3.1);
	
	Hybrid hy("MsI", TypeSD::Digital, 1536, 50000, 14000, 6.5, 40);
	
	TemplateTree<IStorageDevice> tr;

	//исключения
	try {// цена hdd диска
		//hdd.set_costSD(-1.0);
		hdd.set_Speed(20000);
	}
	catch (double cost) {
		cout << "Цена диска: " << cost << "Меньше 0" << endl;
	}
	catch (const overflow_error& err) {
		cout << err.what() << endl;
	}
	/*catch (const char* err) {
		cout << "ОШИБКА:" << err << endl;
	}*/
	catch(const exception& err){
		cout << err.what() << endl;
	}
	catch (...) {
		cout << "FATAL ERROR" << endl;
	}


	tr.Add(&hdd);
	tr.Add(&ssddisc);
	tr.Add(&flash);
	tr.Add(&hy);
	tr.Show();

	Statics st1;
	st1.SummCost(&hy);
	st1.SummCost(&tr);
	st1.print();
	system("pause");
	return 0;
}

