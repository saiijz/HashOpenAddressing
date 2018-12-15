#include "hash.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	Hash hash;
	hash.createHash(5);
	hash.insert("ubin", 55);
	hash.insert("susu", 42);
	hash.insert("imin", 17);
	hash.insert("uboa", 22);
	hash.insert("hoa", 87);
	hash.search(117);
	hash.deleteKey(22);
	hash.deleteKey(87);
	hash.deleteKey(17);
	hash.deleteKey(55);
	hash.deleteKey(42);
	srand(time(NULL));
	for (int i{ 0 }; i < 5; i++) {
		int temp{ rand() % 100 };
		hash.insert("unnamed",temp);
	}
	std::cout << "ting jian xia yu de sheng yin" << std::endl;
	system("pause");
}