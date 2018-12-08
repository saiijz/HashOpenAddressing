#include "hash.h"

Contact::Contact() {
	name = "";
	phoneNumber = 0;
}

Node::Node() {
	pNext = NULL;
}

Node::Node(std::string name, long phoneNumber) {
	contact.name = name;
	contact.phoneNumber = phoneNumber;
	pNext = NULL;
}

Node::Node(std::string name, long phoneNumber, Node* pNext) {
	contact.name = name;
	contact.phoneNumber = phoneNumber;
	this->pNext = pNext;
}

int LinkedList::createLinkedList(std::string name, long phoneNumber) {
	if (!pHead) {
		pHead = new Node(name, phoneNumber, NULL);
		if (!pHead) {
			return -1;
		}
		size = 1;
		return 0;
	}
	else {
		return -1;
	}
}

int LinkedList::addHead(std::string name, long phoneNumber)
{
	if (!pHead) {
		return -1;
	}
	else {
		Node* pNode = new Node(name, phoneNumber, pHead);
		pHead = pNode;
		++size;
		return 1;
	}
}

int LinkedList::deleteHead() {
	if (!pHead) {
		return -1;
	}
	else {
		Node* pDel = pHead;
		pHead = pHead->pNext;
		pDel->pNext = NULL;
		delete pDel;
		pDel = NULL;
		--size;
		return 1;
	}
}

int LinkedList::deleteTail()
{
	Node * pTemp = pHead;
	while (pTemp->pNext->pNext != NULL) {
		pTemp = pTemp->pNext;
	}
	Node * pDel = pTemp->pNext;
	delete pDel;
	pDel = NULL;
	pTemp->pNext = NULL;
	--size;
	return 1;
}

Node* LinkedList::seekHeadNode() {
	return pHead;
}

Node* LinkedList::seekNode(int index) {
	if (index >= size) {
		return NULL;
	}
	else if (index == 0) {
		return pHead;
	}
	else {
		Node *pTemp{ pHead };
		for (int i{ 0 }; i < index; i++) {
			pTemp = pTemp->pNext;
		}
		return pTemp;
	}

}

Node* LinkedList::operator[](int index) {
	if (index >= size) {
		return NULL;
	}
	Node* pTemp = this->pHead;
	for (int i{ 0 }; i < index; i++) {
		pTemp = pTemp->pNext;
	}
	return pTemp;
}

int LinkedList::addTail(std::string name, long phoneNumber) {
	Node * pTemp = pHead;
	while (pTemp->pNext != NULL) {
		pTemp = pTemp->pNext;
	}
	pTemp->pNext = new Node(name, phoneNumber);
	++size;
	return 1;
}

int LinkedList::addNodeBiggerPosition(std::string name, long phoneNumber, int balance)
{
	int charge{ balance };

}

Node* LinkedList::getHeadPointer() {
	return this->pHead;
}

int LinkedList::getSize()
{
	return this->size;
}

void LinkedList::setSize(int value)
{
	this->size = this->size + value;
}

LinkedList::LinkedList() {
	pHead = NULL;
	size = 0;
}

int Hash::hashFunction(int key) {
	return key % HASH_FACTOR;
}

int Hash::insert(int value)
{
	int hash{ hashFunction(value) };

	if (!this->hashTable.getHeadPointer()) {

	}

}

Hash::Hash()
{
}
