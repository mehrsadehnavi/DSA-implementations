// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2021 (1400 Hijri Shamsi)
//
// Author: Kamaledin Ghiasi-Shirazi

#pragma once

#include <stack>
#include "InternalBinaryTreeNode.h"
#include "Drawer.h"
using namespace std;


template<class T, class IBTN>
class BinaryTree {
public:

    class BinaryTreeNode {
    public:
        virtual ~BinaryTreeNode(void) {}

        virtual T &getData() { return mActualNode->getData(); }

        virtual void setData(const T &data) { return mActualNode->setData(data); }

        virtual bool hasLeftChild() const { return mActualNode->getLeftChild() != 0; }

        virtual BinaryTreeNode getLeftChild() const { return BinaryTreeNode(mActualNode->getLeftChild()); }

        virtual bool hasRightChild() const { return mActualNode->getRightChild() != 0; }

        virtual BinaryTreeNode getRightChild() const { return BinaryTreeNode(mActualNode->getRightChild()); }

    private:
        template<class R, class S>
        friend
        class BinaryTree;

        BinaryTreeNode(IBTN *node) { mActualNode = node; }

        IBTN *mActualNode;
    };


public:
    class Iterator {
    public:
        Iterator(IBTN *currentNode) : mCurrentNode(currentNode) {}

        virtual T &operator*() { return mCurrentNode->mData; }

        virtual T *operator->() { return &mCurrentNode->mData; }

        virtual bool operator==(Iterator &itr) { return mCurrentNode == itr.mCurrentNode; }

        virtual bool operator!=(Iterator &itr) { return mCurrentNode != itr.mCurrentNode; }

        virtual void operator++() = 0;

        virtual void operator--() = 0;

    protected:
        IBTN *mCurrentNode;
        stack<IBTN *> mParents;

        friend class BinaryTree<T, InternalBinaryTreeNode<T>>;
    };

    class InOrderIterator : public Iterator {
    public:
        InOrderIterator(IBTN *currentNode) : Iterator(currentNode) {

        }

        virtual void operator++() {
            // Write your code here
        }

        virtual void operator--() {
            // Write your code here
        }
    };

    class PreOrderIterator : public Iterator {
    public:
        PreOrderIterator(IBTN *currentNode) : Iterator(currentNode) {}

        virtual void operator++() {
            // Write your code here

        }


        virtual void operator--() {
            //Write your code here

    };

    class PostOrderIterator : public Iterator {
    public:
        PostOrderIterator(IBTN *currentNode) : Iterator(currentNode) {}

        virtual void operator++() {
            // Write your code here
        }

        virtual void operator--() {
            // Write your code here
        }
    };

protected:

    IBTN *mInorderPreBegin;
    IBTN *mPostorderPreBegin;
    IBTN *mRevInorderPreBegin;
    IBTN *mPreorderPreBegin;
    IBTN *mRevPreorderPreBegin;
    IBTN *mRevPostorderPreBegin;

    IBTN *mRevInorderEnd;
    IBTN *mRevPostorderEnd;
    IBTN *mInorderEnd;
    IBTN *mRevPreorderEnd;
    IBTN *mPreorderEnd;
    IBTN *mPostorderEnd;
    int mNodeDisplayWidth;
    int mSize;

public:
    BinaryTree(void) {
        mNodeDisplayWidth = 2;
        mSize = 0;
		// Write your code here	
    }

    // caution: don't interpret virtual destrucor as an ordinary virtual function!
    virtual ~BinaryTree(void) {
        DeleteSubtree(mRevInorderEnd);
    }

    int size() { return mSize; }

    void DeleteSubtree(IBTN *node) {
        if (node->mLeftChild)
            DeleteSubtree(node->mLeftChild);
        if (node->mRightChild)
            DeleteSubtree(node->mRightChild);
        delete node;
    }

    bool isEmpty() {
        return mInorderEnd->mLeftChild == 0;
    }

    // error if the root already exists.
    virtual BinaryTreeNode insertRootNode(T data) {
		// Write your code here
    }

    virtual BinaryTreeNode getRootNode() { return BinaryTreeNode(mInorderEnd->mLeftChild); }

    virtual BinaryTreeNode getHeaderRootNode() { return BinaryTreeNode(mRevInorderEnd); }

    // error if a left child already exists.
    virtual BinaryTreeNode insertLeftChild(const BinaryTreeNode &parentNode, T data) {
        // Write your code here


        updateAfterInsert(/*childNode*/);
        return BinaryTreeNode(/*childNode*/);
    }


    // error if a right child already exists.
    virtual BinaryTreeNode insertRightChild(const BinaryTreeNode &parentNode, T data) {
        // Write your code here

        updateAfterInsert(/*childNode*/);
        return BinaryTreeNode(/*childNode*/);
    }

    virtual void deleteLeftChild(const BinaryTreeNode &node) {
        IBTN *theParent = node.mActualNode;
        IBTN *theNode = theParent->getLeftChild();
        deleteNode(theNode, theParent);
    }

    virtual void deleteRightChild(const BinaryTreeNode &node) {
        IBTN *theParent = node.mActualNode;
        IBTN *theNode = theParent->getRightChild();
        deleteNode(theNode, theParent);
    }

    virtual InOrderIterator inOrderBegin() {
        // Write your code here

    }

    virtual InOrderIterator inOrderEnd() {
        return InOrderIterator(mInorderEnd);
    }

    virtual InOrderIterator inOrderReverseBegin() {
        // Write your code here

    }

    virtual InOrderIterator inOrderReverseEnd() {
        return InOrderIterator(mRevInorderEnd);
    }

    virtual PreOrderIterator preOrderBegin() {
        // Write your code here

    }

    virtual PreOrderIterator preOrderEnd() {
        return PreOrderIterator(mPreorderEnd);
    }

    virtual PreOrderIterator preOrderReverseBegin() {
        // Write your code here

    }

    virtual PreOrderIterator preOrderReverseEnd() {
        return PreOrderIterator(mRevPreorderEnd);
    }

    virtual PostOrderIterator postOrderBegin() {
        // Write your code here

    }

    virtual PostOrderIterator postOrderEnd() {
        return PostOrderIterator(mPostorderEnd);
    }

    virtual PostOrderIterator postOrderReverseBegin() {
        // Write your code here

    }

    virtual PostOrderIterator postOrderReverseEnd() {
        return PostOrderIterator(mRevPostorderEnd);
    }

    void setNodeDisplayWidth(int width) {
        mNodeDisplayWidth = width;
    }

public:
    string printTree(string string1){
        cout<<"\n\n***************"+string1+"*****************\n"<<endl;

        return print2D(mInorderEnd->mLeftChild);
    }



public:
    virtual void insert(IBTN *node, int i) {}

public:
    virtual void updateAfterInsert(IBTN *node) {
        return;
    }

    virtual void updateBeforeDelete(IBTN * node) {
        return;
    }

    virtual void updateAfterDelete(IBTN *node) {
        return;
    }

protected:
    // Only leaf nodes and nodes with degree 1 can be deleted.
    // If a degree-1 node is deleted, it is replaced by its subtree.
    virtual void deleteNode(IBTN* theNode, IBTN* theParent) {

        updateBeforeDelete(theNode);
        // Write your code here

    }




protected:
    virtual IBTN *getActualNode(const BinaryTreeNode &node) { return node.mActualNode; }
};

