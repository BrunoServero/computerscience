#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree()
{
    //ctor
    root = NULL;
}

AVLTree::~AVLTree()
{
    //destrutor
    //TODO - Implementar destrutor
}

bool AVLTree::isEmpty()
{
    return root==NULL;
}

int AVLTree::height()
{
	return height(root); //altura da árvore é a altura do seu nó raiz
}

int AVLTree::height(AVLNode *no)
{/*Se o nó for NULL retorna -1, senão retorna o que vier do método getHeight()*/
	
	return no==NULL? -1:no->getHeight();

}

int AVLTree::maximo(int lhs, int rhs)
{
    return lhs>rhs? lhs: rhs;
}

int AVLTree::qtNodes()
{
    return qtNodes(root);
}

int AVLTree::qtNodes(AVLNode* no)
{
    if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}
/*Inserir é polimorfico. o Método publico é pra inserir na árvore. Esse método invoca o método privado, que é recursivo*/
void AVLTree::inserir (int valor)
{
    root = inserir(root,valor);
}

AVLNode* AVLTree::remover(int valor){
    if (node == root){

    }    
    if (valor < root){
        node->getLeft();
        remover(int valor);
    }
    else (valor > root){
        node->getRight();
        remover(int valor);
    }

}


AVLNode* AVLTree::inserir(AVLNode* node, int valor)
{

    /*Se é uma arvore ou subarvore vazia, cria 1 novo nó e retorna*/
    if (node == NULL)
       	return new AVLNode(valor);
    if (valor < node->getData())
    {
            node->setLeft(inserir(node->getLeft(), valor));
            if( height( node->getRight() ) - height( node->getLeft() ) == -2 )
            {
                if(  valor< node->getLeft()->getData() )
                     {
                        node = rotateLL( node );
                     }
                 else{
                        node = rotateLR( node );
                     }
            }
    }
    else
    {
        if (valor > node->getData())
            {
                    node->setRight(inserir(node->getRight(),valor));
                    if( height( node->getRight() ) - height( node->getLeft() ) == 2 )
                    {
                        if( valor > node->getRight()->getData())
                            node = rotateRR( node );
                        else
                            node = rotateRL( node );

                    }

            }
    }
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1);

    return node;
}

AVLNode* AVLTree::rotateLL(AVLNode *node)
     {
         AVLNode *leftSubTree = node->getLeft();
         node->setLeft(leftSubTree->getRight());
         leftSubTree->setRight( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         leftSubTree->setHeight( maximo(height(leftSubTree->getLeft()), height(node) + 1));
         return leftSubTree;
     }

AVLNode* AVLTree::rotateRR(AVLNode *node)
     {
         AVLNode *rightSubTree = node->getRight();
         node->setRight(rightSubTree->getLeft());
         rightSubTree->setLeft( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         rightSubTree->setHeight( maximo(height(rightSubTree->getRight()), height(node) + 1));
         return rightSubTree;
     }


AVLNode* AVLTree::rotateLR(AVLNode *node)
{
    node->setLeft(rotateRR(node->getLeft()));
    return rotateLL(node);
}

AVLNode* AVLTree::rotateRL(AVLNode *node)
{
    node->setRight(rotateLL(node->getRight()));
    return rotateRR(node);
}


void AVLTree::preOrder()
{
    preOrder(root);
}

void AVLTree::inOrder()
{
    inOrder(root);
}

void AVLTree::posOrder()
{
    posOrder(root);
}
void AVLTree::reverseOrder()
{
    reverseOrder(root);
}
void AVLTree::preOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        cout<<no->getData()<<endl;
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void AVLTree::posOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout<<no->getData()<<endl;
    }
}

void AVLTree::inOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        inOrder(no->getLeft());
        cout<<no->getData()<<endl;
        inOrder(no->getRight());

    }
}

void AVLTree::reverseOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        reverseOrder(no->getRight());
cout<<no->getData()<<endl;

        reverseOrder(no->getLeft());

    }
}



