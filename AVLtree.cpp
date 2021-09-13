//
// Created by LY on 2021/9/13.
//
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node {
public:
    T key;
    int height;
    node * left;
    node * right;

    node(T value, node<T>* le, node<T>* ri) : key(value), height(0), left(le), right(ri) {}
};


template <typename T>
class AVLTree {

private:
    int _size;
    node<T>* _root;
public:
    void insertKey(int value);
    void deleteKey(int value);
    bool balance(node<T>* root);
    int balanceValue(node<T>* root);
    node<T>* search(T key);
    void RR(node<T>* root);
    void LL(node<T>* root);
    void LR(node<T>* root);
    void RL(node<T>* root);
};


