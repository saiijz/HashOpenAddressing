#include "hash.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	Hash hash;
	hash.createHash(5);
	hash.fixedInsert("ubin", 55);
	hash.fixedInsert("susu", 42);
	hash.fixedInsert("imin", 17);
	hash.fixedInsert("uboa", 22);
	hash.fixedInsert("hoa", 87);
	hash.search(117);
	hash.deleteKey(22);
	hash.deleteKey(87);
	hash.deleteKey(17);
	hash.deleteKey(55);
	hash.deleteKey(42);
	srand(time(NULL));
	for (int i{ 0 }; i < 5; i++) {
		int temp{ rand() % 100 };
		hash.fixedInsert("unnamed",temp);
	}
	std::cout << "ting jian xia yu de sheng yin" << std::endl;
	system("pause");
}