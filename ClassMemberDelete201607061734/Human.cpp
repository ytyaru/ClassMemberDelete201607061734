#include "Human.h"


Human::Human(void)
{
	this->item.Name = _T("�A�C�e��");
	this->pItem = new Item();
	this->pItem->Name.assign(_T("�A�C�e���|�C���^"));
	//this->pItem = new Item(_T("�A�C�e���|�C���^")); // error C2664: 'Item::Item(const Item &)' : 1 �Ԗڂ̈����� 'const wchar_t [9]' ���� 'const Item &' �ɕϊ��ł��܂���B(�V�����@�\ ; �w���v���Q��)
}

Human::~Human(void)
{
	//delete this->item; // error C2440: 'delete' : 'Item' ���� 'void *' �ɕϊ��ł��܂���B
	//delete this->pItem; // 0xC0000005: �ꏊ 0xfeeefee2 ��ǂݍ��ݒ��ɃA�N�Z�X�ᔽ���������܂����B

	if (NULL != this->pItem) {
		delete this->pItem;
		this->pItem = NULL;
	}

	//// error C2678: �񍀉��Z�q '!=' : �^ 'int' �̍��I�y�����h���������Z�q��������܂��� (�܂��͕ϊ��ł��܂���) (�V��������; �w���v���Q��)�B
	//if (NULL != this->item) {
	//	this->item.~Item();
	//	this->item = NULL; // error C2679: �񍀉��Z�q '=' : �^ 'int' �̉E�I�y�����h���������Z�q��������܂��� (�܂��͕ϊ��ł��܂���)�B
	//}
}
