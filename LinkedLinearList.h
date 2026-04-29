#pragma once
#include <ostream>

template <class T>
class LinkedLinearList{
private:
		class Node{
		public:
			T	mData;
			Node*	mPrev;
			Node*	mNext;
		};

public:
	class Iterator{
	public:
		//constructors:
		Iterator ()
			:mCurNode (NULL){}

		Iterator (const Iterator &other)
			:mCurNode (other.mCurNode){}
		
		Iterator (Node* node)
			:mCurNode (node){}
		
		//overloading operators:
		virtual Iterator& operator++(){ // preincrement
			//++it;
			mCurNode = mCurNode->mNext;
			return *this;
		}

		virtual Iterator operator++(int dummy){ // postincrement
			Iterator it(mCurNode);
			this->mCurNode = this->mCurNode->mNext;
			return it;
		}

		virtual Iterator& operator--(){ // predecrement
			mCurNode = mCurNode->mPrev;
			return *this;
		}

		virtual Iterator operator--(int dummy){ // postdecrement
			Iterator it(mCurNode);
			this->mCurNode = this->mCurNode->mPrev;
			return it;
		}

		bool operator!=(const Iterator& right)const {
			return this->mCurNode != right.mCurNode;
		}

		bool operator==(const Iterator& right)const {
			return this->mCurNode == right.mCurNode;
		}

		T* operator->() const {
			return &this->mCurNode->mData;
		}

		T& operator*() const {
			return this->mCurNode->mData;
		}

		friend class LinkedLinearList;
	private:
		//const LinkedLinearList<T> *mLinkedList;
		Node *mCurNode;
	};

	LinkedLinearList(void){
		mSize = 0;
		mHeaderNode = new Node();
		mHeaderNode->mNext = mHeaderNode;
		mHeaderNode->mPrev = mHeaderNode;
	}

	virtual ~LinkedLinearList(void) {
		Node *n, *nn; 
		for (n = mHeaderNode->mNext; n != mHeaderNode;){
			nn = n->mNext;
			delete n;
			n = nn;
		}
		delete mHeaderNode;
	}

public:
	virtual Iterator begin() const {
		return mHeaderNode->mNext;
	}

	virtual Iterator end() const {
		return Iterator(mHeaderNode);
	}

	virtual Iterator rbegin() const {
		return mHeaderNode->mPrev;
	}

	virtual Iterator rend() const {
		return Iterator(mHeaderNode);
	}

	// The returned iterator would point to the inserted element.
	virtual Iterator insert (Iterator it, const T& data) {
		Node* node = new Node();
		node->mData = data;
		node->mPrev = it.mCurNode;
		node->mNext = it.mCurNode->mNext;
		it.mCurNode->mNext->mPrev = node;
		it.mCurNode->mNext = node;
		Iterator it2(node);
		mSize++;
		return it2; 
	}

	// The returned iterator would point to the element after the removed one.
	virtual Iterator remove (Iterator it){
		it.mCurNode->mPrev->mNext = it.mCurNode->mNext;
		it.mCurNode->mNext->mPrev = it.mCurNode->mPrev;
		it.mCurNode = it.mCurNode->mNext;
		mSize--;
		return it;
	}

	virtual int size() const {
		return mSize;
	};

private:
	Node* mHeaderNode;
	int mSize;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedLinearList<T>& ll){
	typename LinkedLinearList<T>::Iterator itr;

	for (itr = ll.begin(); itr != ll.end(); itr++)
		os << *itr << "\t";
	os << "\n";
	return os;
}
