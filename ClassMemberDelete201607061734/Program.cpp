#include <windows.h>
#include <random>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <sstream>
#include <iostream>
#include "Human.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassName[] = _T("ClassMemberDelete201607061734");
HWND hWnd;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS myProg;

	if (!hPreInst) {
		myProg.style			= CS_HREDRAW | CS_VREDRAW;
		myProg.lpfnWndProc		= WndProc;
		myProg.cbClsExtra		= 0;
		myProg.cbWndExtra		= 0;
		myProg.hInstance		= hInstance;
		myProg.hIcon			= NULL;
		myProg.hCursor			= LoadCursor(NULL, IDC_ARROW);
		myProg.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
		myProg.lpszMenuName		= NULL;
		myProg.lpszClassName	= szClassName;
		if (!RegisterClass(&myProg)) { return FALSE; }
	}
	hWnd = CreateWindow(szClassName,	// class��
		_T("Class�̃����o�ϐ��̂���new�������̂�delete����"),		// �^�C�g��
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
		NULL,						// ���j���[�n���h���܂��͎q�E�B���h�E ID
		hInstance,					// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL						// �E�B���h�E�쐬�f�[�^
	);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	// �X�^�b�N�̈�
	Human human;
	human.~Human(); // 0xC0000005: �ꏊ 0xfeeefee2 ��ǂݍ��ݒ��ɃA�N�Z�X�ᔽ���������܂����B
	// ���̌ďo���@�̓X�^�b�N�̈�ł̊m�ۂ�����ďo���̊֐����I�����Ɏ����I�ɔj�������B
	// �Ȃ̂ŁA�����ł̌ďo��delete����Ă��܂����̂Ŋ֐��I�����̌ďo�œ�d����ɂȂ��ăG���[�ɂȂ�B
	// pItem��null�łȂ��Ƃ������폜����悤�ɂ���΃G���[���o�Ȃ��Ȃ�B
	// �f�X�g���N�^�ďo�̃^�C�~���O�ŉ���ł��邵�A�x���Ƃ��ϐ���錾�����֐��̏I�����ɉ���ł���B

	//delete human; // error C2440: 'delete' : 'Human' ���� 'void *' �ɕϊ��ł��܂���B
	// �����ϐ��ɑ΂���delete�͂��Ȃ��B�����ϐ��͊֐��I�����Ɏ����ŉ�������͂��B
	
	//delete &human; // Expression: _BLOCK_TYPE_IS_VALID(pHead->nBlockUse)
	// �����炭��d����G���[�B
	// �����ϐ������玩���I�ɉ�������͂��Ȃ̂ɁA�����ŉ�����������d����G���[�ɂȂ��Ă���H


	// �q�[�v�̈�
	Human* pHuman = new Human();
	delete pHuman;

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return(DefWindowProc(hWnd, msg, wParam, lParam));
	}
	return (0L);
}
