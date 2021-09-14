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





