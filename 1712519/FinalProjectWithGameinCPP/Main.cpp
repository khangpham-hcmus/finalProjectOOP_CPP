#include"ManageHeaders.h"
int main() {
	DeclareHeros _declare_;
	Hero* hr = Hero::createHero("Water");
	cout << hr->toString();
	cout << hr->className();
	return 0;
}