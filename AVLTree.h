//
// Created by LY on 2021/9/14.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H
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
    int _size; //树规模
    node<T>* _root; //根节点
public:
    //获取树高
    int getHeight();
    //遍历
    void preOrder();
    void inOrder();
    void postOrder();

    node<T>* search(T key);

    node<T>* iteratorSearch(T key);
    //查询最大、最小节点
    T maximum();
    T minimum();

    void insertKey(int value);
    void removeKey(int value);

    void destroy();

    void print();
private:
    int getHeight(node<T>* root);
    //前中后序遍历
    void preOrder(node<T>* root) const;
    void inOrder(node<T>* root) const;
    void postOrder(node<T>* root) const;
    //搜索节点
    node<T>* search(node<T>* root, T key);
    node<T>* iteratorSearch(node<T>*, T key);
    //树的旋转
    node<T>* leftLeftRotation(node<T>* k2);
    node<T>* rightRightRotation(node<T>* k1);
    node<T>* leftRightRotation(node<T>* k3);
    node<T>* rightLeftRotation(node<T>* k1);
    //插入节点
    node<T>* insert(node<T>* &tree, T key);
    //删除节点
    node<T>* remove(node<T>* &tree, T key);
    //销毁树
    void destroy(node<T>* &tree);
    //打印树
    void print(node<T>* tree, T key, int direction);
    //检查树是否平衡
    bool balance(node<T>* root);
    int balanceValue(node<T>* root);

};
#endif //AVLTREE_AVLTREE_H
