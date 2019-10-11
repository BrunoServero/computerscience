#ifndef AVLNODE_H
#define AVLNODE_H


class AVLNode
{
    public:
        AVLNode();
        AVLNode(int);
        virtual ~AVLNode();
        int getData();
        int getHeight();
        void setData(int);
        void setHeight(int);
        AVLNode* getLeft();
        AVLNode* getRight();
        void setRight(AVLNode*);
        void setLeft(AVLNode*);

    protected:

    private:
        AVLNode* left, *right;
        int data;
        int height;
};

#endif // AVLNODE_H
