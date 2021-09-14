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
int AVLTree<T>::getHeight(node<T> *root) {
    if (!root)
        return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

template<typename T>
int AVLTree<T>::height(node<T> *root) {
    if (root)
        return root->height;
    return -1;
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
            cout << root->key;
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
        cout << root->key;
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
            cout << root->key;
        }
    }
}