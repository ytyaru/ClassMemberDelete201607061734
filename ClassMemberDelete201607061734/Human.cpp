#include "Human.h"


Human::Human(void)
{
	this->item.Name = _T("アイテム");
	this->pItem = new Item();
	this->pItem->Name.assign(_T("アイテムポインタ"));
	//this->pItem = new Item(_T("アイテムポインタ")); // error C2664: 'Item::Item(const Item &)' : 1 番目の引数を 'const wchar_t [9]' から 'const Item &' に変換できません。(新しい機能 ; ヘルプを参照)
}

Human::~Human(void)
{
	//delete this->item; // error C2440: 'delete' : 'Item' から 'void *' に変換できません。
	//delete this->pItem; // 0xC0000005: 場所 0xfeeefee2 を読み込み中にアクセス違反が発生しました。

	if (NULL != this->pItem) {
		delete this->pItem;
		this->pItem = NULL;
	}

	//// error C2678: 二項演算子 '!=' : 型 'int' の左オペランドを扱う演算子が見つかりません (または変換できません) (新しい動作; ヘルプを参照)。
	//if (NULL != this->item) {
	//	this->item.~Item();
	//	this->item = NULL; // error C2679: 二項演算子 '=' : 型 'int' の右オペランドを扱う演算子が見つかりません (または変換できません)。
	//}
}
