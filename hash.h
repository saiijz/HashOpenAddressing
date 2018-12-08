#pragma once
#include <string>
#define HASH_FACTOR 25

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

public:
	int hashFunction(int);
	int insert(int);
	Hash();
};