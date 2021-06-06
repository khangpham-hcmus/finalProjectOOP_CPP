#include"ManageHeaders.h"
string _FILENAME_ = "ListHero.txt";
int main() {
	DeclareHeros _declare_;
	vector<Hero*> DanhSachAnhHung = Hero::GET_LIST_HEROS_FROM_FILE(_FILENAME_);
	for (auto& i : DanhSachAnhHung)
	{
		cout << i->toString() << endl;
		cout << i->className() << endl << "---------------------------------------" << endl;
	}
	return 0;
}