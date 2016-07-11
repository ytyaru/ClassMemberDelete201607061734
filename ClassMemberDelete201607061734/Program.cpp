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
	hWnd = CreateWindow(szClassName,	// class名
		_T("Classのメンバ変数のうちnewしたものをdeleteする"),		// タイトル
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// 親ウィンドウまたはオーナーウィンドウのハンドル
		NULL,						// メニューハンドルまたは子ウィンドウ ID
		hInstance,					// アプリケーションインスタンスのハンドル
		NULL						// ウィンドウ作成データ
	);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	// スタック領域
	Human human;
	human.~Human(); // 0xC0000005: 場所 0xfeeefee2 を読み込み中にアクセス違反が発生しました。
	// この呼出方法はスタック領域での確保だから呼出元の関数が終了時に自動的に破棄される。
	// なので、ここでの呼出でdeleteされてしまったので関数終了時の呼出で二重解放になってエラーになる。
	// pItemはnullでないときだけ削除するようにすればエラーが出なくなる。
	// デストラクタ呼出のタイミングで解放できるし、遅くとも変数を宣言した関数の終了時に解放できる。

	//delete human; // error C2440: 'delete' : 'Human' から 'void *' に変換できません。
	// 自動変数に対してdeleteはしない。自動変数は関数終了時に自動で解放されるはず。
	
	//delete &human; // Expression: _BLOCK_TYPE_IS_VALID(pHead->nBlockUse)
	// おそらく二重解放エラー。
	// 自動変数だから自動的に解放されるはずなのに、ここで解放したから二重解放エラーになっている？


	// ヒープ領域
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
