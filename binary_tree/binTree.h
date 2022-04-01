#ifndef BINTREE_H
#define BINTREE_H

#include "node.h" 

template<typename T>
class BinTree {
private:
	node<T>* m_root;

	void insert(T key, node<T>* leaf);
	node<T>* search(T key, node<T>* leaf);
	void print_tree(node<T>* leaf);
	void destroy_tree(node<T>* leaf);
public:
	BinTree();
	~BinTree();
	void insert(T key);
	node<T>* search(T key);
	void print_tree();
	void destroy_tree();
};
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
BinTree<T>::BinTree() {
	std::cout << "Creating a tree object\n";
	m_root = nullptr;
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
BinTree<T>::~BinTree() {
	destroy_tree();
	if (!m_root) { std::cout << "tree successfully deallocated\n"; }
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
void BinTree<T>::insert(T key) {
	if (m_root!=nullptr) {
		insert(key, m_root);
	}
	else {
		m_root = new node<T>;
		m_root->key_value = key;
		m_root->left = nullptr;
		m_root->right = nullptr;
	}
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
void BinTree<T>::insert(T key, node<T>* leaf) {
	if (key < leaf->key_value) {
		if (leaf->left!=nullptr) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new node<T>;
			leaf->left->key_value = key;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (key >= leaf->key_value) {
		if (leaf->right!=nullptr) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node<T>;
			leaf->right->key_value = key;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
void BinTree<T>::destroy_tree() {
	destroy_tree(m_root);
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
void BinTree<T>::destroy_tree(node<T>* leaf) {
	if (leaf!=nullptr) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
		leaf = nullptr;
	}
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T> 
void BinTree<T>::print_tree() {
	print_tree(m_root);
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
void BinTree<T>::print_tree(node<T>* leaf) {
	if (leaf != nullptr) {
		std::cout << "leaf: " << leaf->key_value;
		if (leaf->left != nullptr && leaf->right != nullptr) {
			std::cout << ", left: " << leaf->left->key_value << ", right: " << leaf->right->key_value << '\n';
		}
		else {
			std::cout << ", left: empty" << ", right: empty"  << '\n';
		}

		if (leaf->left != nullptr) {
			print_tree(leaf->left);
		}

		if (leaf->right != nullptr) { 
			print_tree(leaf->right);
		}
	}
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
node<T>* BinTree<T>::search(T key) {
	return search(key, m_root);
}
//--------------------------------------------------------------------------------------------------------------------
template<typename T>
node<T>* BinTree<T>::search(T key, node<T>* leaf) {
	if (key = leaf->key_value) {
		return leaf;
	}
	else if (key < leaf->key_value) {
		search(key, leaf->left);
	}
	else if (key >= leaf->key_value) {
		search(key, leaf->right);
	}
	else {
		return nullptr;
	}
}
//--------------------------------------------------------------------------------------------------------------------

#endif 