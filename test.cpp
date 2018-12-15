#include "hash.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	Hash hash;
	hash.createHash(1000);
	srand(time(NULL));
	for (int i{ 0 }; i < 1000; i++) {
		int temp{ rand() % 1000 };
		hash.insert("unnamed", temp);
	}
	
	std::cout << "ting jian xia yu de sheng yin" << std::endl;
	system("pause");
}