//#include <bits/stdc++.h>
//using namespace std;
//
//struct node {
//    int height;
//    int key;
//    node* left;
//    node* right;
//};
//
//int high(node* root) {
//    if (!root)
//        return 0;
//    return max(high(root->left),high(root->right)) + 1;
//}
//
//int balanceValue(node* root) {
//    if (!root)
//        return 0;
//    return root->left->height - root->right->height;
//}
//
//void insert(node** ptr, int value) {
//    node* newNode;
//    node* root = *ptr;
//
//    if (!root) {
//        newNode = new node;
//        newNode->key = value;
//        newNode->left = newNode->right = nullptr;
//    }
//    else if (root->key == value)
//        return;
//    else {
//        if (root->key < value)
//            insert(&root->left, value);
//        else
//            insert(&root->right, value);
//    }
//}
//
//void deleteNode(node** ptr, int value) {
//    node** toFree;
//    node* root = *ptr;
//
//    if(root) {
//        if (root->key == value)
//
//    }
//}
//
//
//
//
//int main() {
//    return 0;
//}
