#pragma once
#include <iostream>
#include <vector>

using namespace std;
template <class T>
class TemplateTree {
private:
	struct Node {
		T* data = NULL;
		Node* left, *right;
	};
	vector<T*> vec;
	Node* root;
	int count = 0;
	void straight(Node* node) {
		if (node != NULL) {
			//cout << *node->data;
			node->data->print();
			straight(node->left);
			straight(node->right);
		};
	};
	T* STR(Node* node) {
		if (node != NULL) {
			return node->data;
			straight(node->left);
			straight(node->right);
		};
	}
	void Search(Node*& node, int m) {
		if (node != NULL) {
			if (*node->data == m) node->data->print();
			Search(node->left, m);
			Search(node->right, m);
		}
	};
public:
	TemplateTree() {
		root = NULL;
	};
	~TemplateTree() {
		Delete(root);
	};
	void Delete(Node*& node) {
		if (node != NULL)    // если дерево не пустое
		{
			Delete(node->left);   // рекурсивно удал€ем левую ветку
			Delete(node->right);  // рекурсивно удал€ем правую ветку
			delete node;           // удал€ем корень
		}
	};// удаление
	void Add(T* data) {
		vec.push_back(data);
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
	};// добавление
	void Show() {
		straight(root);
		cout << " оличество узлов в дереве = " << count << endl;
	};//вывод содержимого
	void Search_Memory(int m) {
		Search(root, m);
	};// ѕосиск по объЄму пам€ти
	void Sorting() {
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
	};
	double Get_count()const {
		return count;
	}
	T* getitem (int index) {
		/*if (root = nullptr) {
			return nullptr;
		}
		Node* tmp=root;
		while (!tmp != 0 && index-- > 0) {
		}
		if (tmp == NULL) return nullptr;
		else return tmp->data;*/
		return vec[index];
	}
};

