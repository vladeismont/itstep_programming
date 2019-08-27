#include <Windows.h>
#include <tchar.h>
#include "resource.h"
#include <commdlg.h>

HWND hWndChild;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#define ID_BUTTON1 3001
#define ID_BUTTON2 3002
#define ID_BUTTON3 3003
HWND hWndBut1, hWndBut2, hWndBut3;
HWND hEdit1, hEdit2, hEdit3, hEdit4, hEdit5, hEdit6;
#define ID_EDIT1 101
#define ID_EDIT2 102
#define ID_EDIT3 103
#define ID_EDIT4 104
#define ID_EDIT5 105
#define ID_EDIT6 106
CHOOSECOLOR chooseColor;
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow){
	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"Myfirst window";
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(101));
	wndclass.hbrBackground = CreateSolidBrush(RGB(205, 201, 201));//(HBRUSH)GetStockObject(WHITE_BRUSH);// или CreateSolidBrush(RGB(0,0,0));
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(101));

	if (!RegisterClassEx(&wndclass)){ MessageBox(NULL, L"WND unregistered - 1!", L"WND", MB_YESNO); return 1; }

	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"Регистрация", WS_OVERLAPPEDWINDOW, 100, 100, 400, 420, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd){
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}
	hEdit1 = CreateWindowEx(WS_EX_TOPMOST, L"EDIT",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		150, 57, 150, 16, hWnd,// Родительское окно
		(HMENU)ID_EDIT1,// идентификатор
		hInstance, NULL);
	hEdit2 = CreateWindowEx(WS_EX_TOPMOST, L"EDIT",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		150, 97, 150, 16, hWnd,// Родительское окно
		(HMENU)ID_EDIT2,// идентификатор
		hInstance, NULL);
	hEdit3 = CreateWindowEx(WS_EX_TOPMOST, L"EDIT",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		150, 137, 150, 16, hWnd,// Родительское окно
		(HMENU)ID_EDIT3,// идентификатор
		hInstance, NULL);
	hEdit4 = CreateWindowEx(WS_EX_TOPMOST, L"listbox",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		150, 177, 150, 16, hWnd,// Родительское окно
		(HMENU)ID_EDIT4,// идентификатор
		hInstance, NULL);
	hEdit5 = CreateWindowEx(WS_EX_TOPMOST, L"listbox",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		150, 217, 150, 16, hWnd,// Родительское окно
		(HMENU)ID_EDIT5,// идентификатор
		hInstance, NULL);
	hEdit6 = CreateWindowEx(WS_EX_TOPMOST, L"listbox",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		150, 257, 150, 16, hWnd,// Родительское окно
		(HMENU)ID_EDIT6,// идентификатор
		hInstance, NULL);
	hWndBut1 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Сохранить", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		40, 300, 80, 50,
		hWnd,// Родитель
		(HMENU)ID_BUTTON1,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut1) { return false; }
	hWndBut2 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Удалить", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		140, 300, 80, 50,
		hWnd,// Родитель
		(HMENU)ID_BUTTON2,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut2) { return false; }
	hWndBut3 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Записать", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		240, 300, 80, 50,
		hWnd,// Родитель
		(HMENU)ID_BUTTON3,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut3) { return false; }

	static COLORREF colorRef[16];
	ZeroMemory(&chooseColor, sizeof(CHOOSECOLOR));
	chooseColor.lStructSize = sizeof(CHOOSECOLOR);
	chooseColor.hInstance = NULL;
	chooseColor.hwndOwner = hWnd;
	chooseColor.lpCustColors = colorRef;
	chooseColor.rgbResult = RGB(100, 100, 255);
	chooseColor.Flags = CC_RGBINIT | CC_FULLOPEN;
	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) == TRUE){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	TEXTMETRIC tm;//структура содержит настройки шрифта
	switch (iMsg){
	case WM_CREATE:	
		SendMessage(hEdit4, LB_ADDSTRING, 0, (LPARAM)L"11816");
		SendMessage(hEdit4, LB_ADDSTRING, 0, (LPARAM)L"22563");
		hdc = GetDC(hwnd);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)){
		case ID_BUTTON1:
			MessageBox(hwnd, L"But1", L"1", MB_OK);
			break;
		case ID_BUTTON2:
			SetWindowText(hEdit1, L"");
			SetWindowText(hEdit2, L"");
			SetWindowText(hEdit3, L"");
			MessageBox(hwnd, L"But2", L"2", MB_OK);
			break;
		case ID_BUTTON3:
			MessageBox(hwnd, L"But3", L"3", MB_OK);
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, 120, 20, L"АНКЕТА СТУДЕНТА", 15);
		TextOut(hdc, 50, 60, L"Фамилия", 7);
		TextOut(hdc, 50, 100, L"Имя", 3);
		TextOut(hdc, 50, 140, L"Отчество", 8);
		TextOut(hdc, 50, 180, L"Группа", 6);
		TextOut(hdc, 50, 220, L"Форма", 5);
		TextOut(hdc, 50, 260, L"Курс", 4);
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		ChooseColor(&chooseColor);
		GetClientRect(hwnd, &rect);
		SetClassLong(hwnd, -10, (LONG)CreateSolidBrush(chooseColor.rgbResult));
		InvalidateRect(hwnd, &rect, true);
		break;
	case WM_RBUTTONDBLCLK:
		MoveWindow(hwnd, 700, 100, 400, 420, true);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
