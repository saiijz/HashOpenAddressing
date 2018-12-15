#include "hash.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	Hash hash;
	hash.createHash(7);
	hash.insert("a", 111);
	hash.insert("b", 6);
	hash.insert("c", 27);
	hash.insert("d", 9213908);
	hash.insert("e", 8478648);

	hash.deleteKey(27);
	hash.deleteKey(8478648);
	hash.deleteKey(9213908);
	hash.deleteKey(27);
	/*
	hash.createHash(1000);
	srand(time(NULL));
	for (int i{ 0 }; i < 1000; i++) {
		hash.insert("unnamed", rand() % 10000);
	}*/
	std::cout << "ting jian xia yu de sheng yin" << std::endl;
	system("pause");
}