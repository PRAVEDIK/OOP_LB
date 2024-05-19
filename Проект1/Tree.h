#pragma once
#include <iostream>
#include "StorageDevice.h" 

using namespace std;
class Tree {
private:
	struct Node {
		StorageDevice* data = NULL;
		Node* left, *right;
	};
	Node* root;
	int count = 0;
	void straight(Node* node);
	/*
	void reverse(Node* node);
	void simmetric(Node* node);
	*/
	void Search(Node*& node, int m);
public:
	Tree();
	~Tree();
	void Delete(Node*& node);// удаление
	void Add(StorageDevice* data);// добавление
	void Show();//вывод содержимого
	void Search_Memory(int m);// Посиск по объёму памяти
	void Sorting();
};
