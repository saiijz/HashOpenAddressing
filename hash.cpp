#include "hash.h"

Contact::Contact() {
	name = DEFAULT_NAME;
	phoneNumber = DEFAULT_NUMBER;
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
	Node * pTemp{ pHead };
	while (pTemp->pNext != NULL) {
		pTemp = pTemp->pNext;
	}
	pTemp->pNext = new Node(name, phoneNumber);
	++size;
	return 1;
}

int LinkedList::addPosition(std::string name, long phoneNumber, int pos)
{
	if (pos < 1 || pos > size + 1) {
		return -1;
	}
	
	if (pos == 0) {
		addHead(name, phoneNumber);
		return 1;
	}

	if (pos == size) {
		addTail(name, phoneNumber);
		return 1;
	}
	
	Node* pTemp{ pHead };

	for (int i{ 1 }; i < pos; i++) {
		pTemp = pTemp->pNext;
	}
	
	pTemp->pNext = new Node(name, phoneNumber, pTemp->pNext->pNext);
	++size;
	return 1;
}



int LinkedList::addNodeBiggerPosition(std::string name, long phoneNumber, int balance)
{
	int charge{ balance };
	while (charge > 1) {
		addTail("DEFAULT NAME", 0);
		--charge;
	}
	addTail(name, phoneNumber);
	return 1;
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

int Hash::createHash(int capacity)
{
	if (capacity > 1) {
		hashTable.createLinkedList(DEFAULT_NAME, DEFAULT_NUMBER);
		for (int i{ 1 }; i < capacity; i++) {
			hashTable.addTail(DEFAULT_NAME, DEFAULT_NUMBER);
		}
		this->hashFactor = capacity;
		size = 0;
		return 1;
	}
	return -1;
}

int Hash::hashFunction(int key) {
	return key % hashFactor;
}

Node * Hash::linearProbing(Node *pTemp)
{
	Node * pCheck{ pTemp };
	while (pCheck->contact.name != DEFAULT_NAME) {
		if (pCheck->pNext == NULL) {
			break;
		}
		pCheck = pCheck->pNext;
	}
	if (pCheck->contact.name == DEFAULT_NAME) {
		return pCheck;
	}
	else {
		return nullptr;
	}
}

Node * Hash::quadraticProbing(long phoneNumber)
{
	int i{ 1 };
	int hashQuad;
	int count{ 0 };
	while (true) {
		if (count == hashFactor) {
			return nullptr;
		}
		hashQuad = (phoneNumber + static_cast<long>(pow(i, 2))) % hashFactor;
		if (hashTable[hashQuad]->contact.phoneNumber == DEFAULT_NUMBER) {
			return hashTable[hashQuad];
		}
		++i;
		++count;
	}
}

int Hash::insert(std::string name, long phoneNumber)
{
	if (search(phoneNumber) != -1) {
		return -1;
	}
	if (size >= hashFactor - 1) {
		return -1;
	}

	int hashKey{ hashFunction(phoneNumber) };

	if (hashTable[hashKey]->contact.name == DEFAULT_NAME) {
		hashTable[hashKey]->contact.name = name;
		hashTable[hashKey]->contact.phoneNumber = phoneNumber;
		++size;
		return 1;
	}
	else {
		//linear probing
		/*Node *pIns{ linearProbing(hashTable[hashKey]) };
		if (!pIns) {
			pIns = linearProbing(hashTable[0]);
		}*/
		//quadratic probing
		Node *pIns{ quadraticProbing(phoneNumber) };
		if (!pIns) {
			return -1;
		}
		pIns->contact.name = name;
		pIns->contact.phoneNumber = phoneNumber;
		++size;
		return 1;
	}
}

Node* Hash::searchLinearProbing(long phoneNumber)
{
	int hashKey{ hashFunction(phoneNumber) };
	Node *pTemp{ hashTable[hashKey] };

	while (true) {
		if (pTemp->contact.phoneNumber == phoneNumber) {
			return pTemp;
		}
		if (pTemp->pNext == NULL) {
			break;
		}
		pTemp = pTemp->pNext;
	}

	pTemp = hashTable[0];
	while (pTemp != hashTable[hashKey]) {
		if (pTemp->contact.phoneNumber == DEFAULT_NUMBER) {
			break;
		}
		if (pTemp->contact.phoneNumber == phoneNumber) {
				return pTemp;
		}
		pTemp = pTemp->pNext;
	}

	return nullptr;
}

Node * Hash::searchQuadraticProbing(long phoneNumber) {
	int i{ 0 };
	long hash{ 0 };
	int count{ 0 };

	while (true) {
		if (count == hashFactor) {
			return nullptr;
		}
		hash = (phoneNumber + static_cast<long>(pow(i, 2))) % hashFactor;
		if (i >= hashFactor) {
			return nullptr;
		}
		if (hashTable[hash]->contact.phoneNumber == phoneNumber) {
			return hashTable[hash];
		}
		++i;
		++count;
	}
}

int Hash::deleteKey(long phoneNumber)
{
	//Node *pTemp{ searchLinearProbing(phoneNumber) };
	Node *pTemp { searchQuadraticProbing(phoneNumber) };
	if (!pTemp) {
		return -1;
	}

	pTemp->contact.name = DEFAULT_NAME;
	pTemp->contact.phoneNumber = DEFAULT_NUMBER;
	--size;
	return 1;
}

int Hash::search(long phoneNumber)
{
	Node* result;

	result = searchQuadraticProbing(phoneNumber);
	//result = searchLinearProbing(phoneNumber);

	if (!result) {
		return -1;
	}

	return result->contact.phoneNumber;
}


Hash::Hash()
{
}


