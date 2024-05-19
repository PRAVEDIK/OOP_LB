#include <iostream>
#include <string>
#include "Tree.h"
#include "time.h"
#pragma once


using namespace std;
void Tree::straight(Node* node) {
	if (node != NULL) {
		cout << *node->data ;
		//node->data->print();
		straight(node->left);
		straight(node->right);
	}
};
/*
void Tree::reverse(Node* node) {
if (node != NULL) {
reverse(node->left);
reverse(node->right);
cout << node->data << " ";
}
};
void Tree::simmetric(Node* node) {
if (node != NULL) {
simmetric(node->left);
cout << node->data << " ";
simmetric(node->right);
}
};
*/
Tree::Tree() {
	root = NULL;
};
//удаление 
void Tree::Delete(Node*& node) {
	if (node != NULL)    // если дерево не пустое
	{
		Delete(node->left);   // рекурсивно удаляем левую ветку
		Delete(node->right);  // рекурсивно удаляем правую ветку
		delete node;           // удаляем корень
	}
}
//добавление в дерево
void Tree::Add(StorageDevice *data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		Node* tmp = root;
		while (root->left != NULL && root->right != NULL) {
			if (rand() % 2 == 0) root = root->left;
			else  root = root->right;
		}
		if (root->left == NULL) {
			root->left = new Node; root = root->left;
			root->data = data;
			root->left = NULL; root->right = NULL;
			root = tmp;
		}
		else
		{
			root->right = new Node; root = root->right;
			root->data = data;
			root->left = NULL; root->right = NULL;
			root = tmp;
		}
	}
	count++;
}
//вывод дерева
void Tree::Show() {
	straight(root);
	cout << "Количество узлов в дереве = " << count << endl;
}
// поиск 
void Tree::Search(Node*& node, int m) {
	if (node != NULL) {
		if (*node->data == m) node->data->print();
		Search(node->left, m);
		Search(node->right, m);
	}
}
void Tree::Search_Memory(int m) {
	Search(root, m);
}
//сортировка
void Tree::Sorting() {
	if (root == NULL) return;
	for (int i = 0; i < count; i++) {
		Node* tmp1 = root;
		if (tmp1 != NULL) {
			if (tmp1->left != NULL) {
				if (*tmp1->data > *tmp1->left->data) {
					swap(tmp1->data, tmp1->left->data);
				}
			}
			if (tmp1->right != NULL) {
				if (tmp1->data->get_sizeSD() > tmp1->right->data->get_sizeSD()) {
					swap(tmp1->data, tmp1->right->data);
				}
			}
		}
	}
}
//Диструктор дерева
Tree::~Tree() {
	Delete(root);
}
