//
// Created by LY on 2021/9/13.
//
#include<bits/stdc++.h>
#include"AVLTree.h"
using namespace std;

/*
 * 获取树高
 * */
template <typename T>
int AVLTree<T>::getHeight(){
    return getHeight(_root);
}

template <typename T>
int AVLTree<T>::height(node<T> *root) {
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

template<typename T>
int AVLTree<T>::getHeight(node<T> *root) {
    if (root)
        return root->height;
    return 0;
}

template <typename T>
void AVLTree<T>::preOrder() {
    preOrder(_root);
}

template <typename T>
void AVLTree<T>::preOrder(node<T> *root) const {
    if (!root) return;
    stack<node<T>*> s;
    s.push(root);
    while (!s.empty()) {
        while (root) {
            cout << root->key << ' ';
            s.push(root->right);
            root = root->left;
        }
        root = s.top();
        s.pop();
    }
}

template <typename T>
void AVLTree<T>::inOrder() {
    return inOrder(_root);
}

template <typename T>
void AVLTree<T>::inOrder(node<T> *root) const {
    if (!root) return;
    stack<node<T>*> s;
    while (!s.empty() || root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->key << ' ';
    }
}

template <typename T>
void AVLTree<T>::postOrder() {
    return postOrder(_root);
}

template <typename T>
void AVLTree<T>::postOrder(node<T>* root) const {
    if (!root) return;
    stack<node<T>*> s;
    s.push(root);
    while (!s.empty()) {
        root = s.top();
        if (root) {
            s.pop();
            s.push(root);
            s.push(nullptr);
            if (root->left) s.push(root->left);
            if (root->right) s.push(root->right);
        }
        else {
            s.pop();
            root = s.top();
            s.pop();
            cout << root->key << ' ';
        }
    }
}

template <typename T>
node<T>* AVLTree<T>::search(T key) {
    return search(_root, key);
}

template <typename T>
node<T>* AVLTree<T>::search(node<T>* root, T key) {
    if (!root) return nullptr;
    if (root->key == key) return root;
    if (root->key > key)
        return research(root->left, key);
    else
        return search(root->right, key);
}

template <typename T>
node<T>* AVLTree<T>::iteratorSearch(T key) {
    return iteratorSearch(_root, key);
}

template <typename T>
node<T>* AVLTree<T>::iteratorSearch(node<T> * root, T key) {
    while (root) {
        if (root->key == key)
            break;
        else if (root->key > key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

template <typename T>
T AVLTree<T>::maximum() {
    node<T>* root = maximum(_root);
    if (root)
        return root->key;
    return (T) nullptr;
}
template <typename T>
node<T>* AVLTree<T>::maximum(node<T> *root) {
    if (!root)
        return nullptr;
    while (root->right)
        root = root->right;
    return root;
}

template <typename T>
T AVLTree<T>::minimum() {
    node<T>* root = minimum(_root);
    if (root)
        return root->key;
    return (T) nullptr;
}
template <typename T>
node<T>* AVLTree<T>::minimum(node<T> *root) {
    if (!root)
        return nullptr;
    while (root->left)
        root = root->left;
    return root;
}


//LL
template <typename T>
node<T>* AVLTree<T>::leftLeftRotation(node<T> *k2) {
    node<T>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    k1->height = max(getHeight(k1->left), k2->height) + 1;
    return k1;
}
//RR
template <typename T>
node<T>* AVLTree<T>::rightRightRotation(node<T> *k1) {
    node<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
    k2->height = max(k1->height, getHeight(k2->right)) + 1;
    return k2;
}
//LR
template <typename T>
node<T>* AVLTree<T>::leftRightRotation(node<T> *k3) {
    k3->left = rightRightRotation(k3->left);
    return leftLeftRotation(k3);
}
//RL
template <typename T>
node<T>* AVLTree<T>::rightLeftRotation(node<T> *k1) {
    k1->right = leftLeftRotation(k1->right);
    return rightRightRotation(k1);
}
//插入节点
template <typename T>
node<T>* AVLTree<T>::insert(node<T> *&tree, T key) {
    if (tree == nullptr) {
        tree = new node<T>(key, nullptr, nullptr);
    }
    else if (tree->key > key) {
        tree->left = insert(tree->left, key);
        if (getHeight(tree->left) - getHeight(tree->right) > 1) {
            if (tree->left->key > key)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else if (tree-> key < key) {
        tree->right = insert(tree->right, key);
        if (getHeight(tree->right) - getHeight(tree->left) > 1) {
            if (tree->right->key < key)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    else {
        cout << "Error: insert a same number!" <<endl;
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    return tree;
}

//删除节点
template <typename T>
node<T>* AVLTree<T>::remove(node<T>* &tree, node<T>* root) {
    if (tree == nullptr || root == nullptr)
        return nullptr;
    if (tree->key > root->key) {
        tree->left = remove(tree->left, root);
        if (getHeight(tree->right) - getHeight(tree->left) > 1) {
            if (tree->right->left->height >= tree->right->right->height)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    else if (tree->key < root->key) {
        tree->right = remove(tree->right, root);
        if (getHeight(tree->left) - getHeight(tree->right) > 1) {
            if (tree->left->left->height >= tree->left->right->height)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else {
        if (tree->right && tree->left) {
            if (getHeight(tree->left) > getHeight(tree->right)) {
                node<T>* Max = maximum(tree->left);
                tree = Max;
                tree->left = remove(tree->left, Max);
            }
            else {
                node<T>* Min = minimum(tree->right);
                tree = Min;
                tree->right = remove(tree->right, Min);
            }
        }
        else {
            node<T>* tmp = tree;
            tree = (tree->left) ? tree->left : tree->right;
            delete tmp;
        }
    }
    return tree;
}

template <typename T>
void AVLTree<T>::insertKey(T value) {
    insert(_root, value);
}
template <typename T>
void AVLTree<T>::removeKey(T value) {
    node<T>* p = search(_root, value);
    if (p) remove(_root, p);
}

template <typename T>
void AVLTree<T>::destroy(node<T> *&tree) {
    if (!tree)
        return;
    if (tree->left)
        destroy(tree->left);
    if (tree->right)
        destroy(tree->right);
    delete tree;
}
template <typename T>
void AVLTree<T>::destroy() {
    return destroy(_root);
}

template <typename T>
void AVLTree<T>::print(node<T> *tree, T key, int direction) {
    if (tree) {
        if (direction == 0)
            cout << setw(2) << tree->key << "is root" << endl;
        else
            cout << setw(2) << tree->key << " is " << setw(2) << key << "'s "<< setw(12) << (direction==1?"right child" : "left child") << endl;

        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
    }
}

template <typename T>
void AVLTree<T>::print() {
    if (_root)
        print(_root, _root->key, 0);
}


int main() {
    vector<int> num {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    AVLTree<int>* tree = new AVLTree<int>();
    for (auto i : num)
        tree->insertKey(i);
    tree->print();
}
