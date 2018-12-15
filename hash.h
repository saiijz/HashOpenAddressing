#pragma once
#include <string>
#include <math.h>
#define DEFAULT_NAME "DEFAULT NAME"
constexpr auto DEFAULT_NUMBER = 0;

struct Contact {
	std::string name;
	long phoneNumber;

	Contact();

};

struct Node {
	Contact contact;
	Node *pNext;

	Node();
	Node(std::string, long);
	Node(std::string, long, Node*);

};

class LinkedList {
private:
	Node *pHead;
	int size;
public:
	int createLinkedList(std::string, long);
	int addHead(std::string, long);
	int addTail(std::string, long);
	int addPosition(std::string, long, int);
	int addNodeBiggerPosition(std::string, long, int);
	int deleteHead();
	int deleteTail();
	Node* seekHeadNode();
	Node* seekNode(int);
	Node* operator[](int);
	Node* getHeadPointer();
	int getSize();
	void setSize(int);
	LinkedList();
};

class Hash {

private:
	LinkedList hashTable;
	int hashFactor;
	int size;
public:
	int createHash(int);
	int hashFunction(int);
	Node* linearProbing(Node*);
	Node* quadraticProbing(long);
	int insert(std::string, long);
	Node* searchLinearProbing(long);
	Node* searchQuadraticProbing(long);
	int deleteKey(long);
	int search(long);
	
	Hash();
};