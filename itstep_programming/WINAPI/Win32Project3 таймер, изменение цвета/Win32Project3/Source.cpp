#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc2(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow){
	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"Myfirst window";
	WNDCLASSEX wndclass;
	memset(&wndclass, 0, sizeof(wndclass));
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
	wndclass.lpfnWndProc = WndProc;
	//wndclass.cbClsExtra = 0;
	//wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hCursor = LoadCursor(NULL, IDC_UPARROW);
	//wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(104));
	wndclass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(main_icon));
	//wndclass.hIcon = LoadIcon(NULL, IDI_SHIELD);
	wndclass.hbrBackground = CreateSolidBrush(RGB(218,165,32));//(HBRUSH)GetStockObject(WHITE_BRUSH);// или CreateSolidBrush(RGB(0,0,0));
	//wndclass.lpszMenuName = NULL;
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass)){ MessageBox(NULL, L"WND unregistered - 1!", L"WND", MB_YESNO); return 1; }

	//HWND hWnd2 = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window", WS_OVERLAPPEDWINDOW, 100, 100, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window hwnd1", /*WS_POPUPWINDOW*/ WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, 100, 100, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd){
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}

	LPWSTR szClassName2 = L"MyWindowClass 1";
	LPWSTR szTitleName2 = L"Myfirst window 1";
	WNDCLASSEX wndclass2;
	//ZeroMemory(&wndclass2, sizeof(WNDCLASSEX));
	memset(&wndclass2, 0, sizeof(wndclass2));
	wndclass2.cbSize = sizeof(wndclass2);
	wndclass2.lpszClassName = szClassName2;
	wndclass2.style = CS_HREDRAW | CS_VREDRAW;
	wndclass2.lpfnWndProc = WndProc2;
	wndclass2.cbClsExtra = 0;
	wndclass2.cbWndExtra = 0;
	wndclass2.hInstance = hInstance;
	wndclass2.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass2.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass2.hbrBackground = CreateSolidBrush(RGB(106, 90, 205));;// или CreateSolidBrush(RGB(0,0,0));
	wndclass2.lpszMenuName = NULL;
	wndclass2.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass2)){ MessageBox(NULL, L"WND unregistered! - 2", L"WND", MB_YESNO); return 1; }

	//	int res2 = MessageBox(NULL, L"WND text!", L"WND text", MB_ICONINFORMATION | MB_OK);
	//	if (res2 == IDOK){
	//		MessageBox(NULL, L"MessageBox OK!", L"MessageBox text OK", MB_ICONINFORMATION);
	//	}

	

	HWND hWnd2 = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName2, L"My Window hwnd2", WS_OVERLAPPEDWINDOW, 10, 10, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd2){
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}
	ShowWindow(hWnd2, 1);
	UpdateWindow(hWnd2);

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
	HDC hdc;	//дескриптор устройства управления
	PAINTSTRUCT ps;
	RECT rect;	//rectangle
	switch (iMsg){
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, L"Hello, Step", -1, &rect, DT_BOTTOM | DT_SINGLELINE | DT_VCENTER | DT_RIGHT);
		DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text 1!", L"my text", MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
LRESULT CALLBACK WndProc2(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;	//дескриптор устройства управления
	PAINTSTRUCT ps;
	RECT rect;	//rectangle
	int x, y;
	switch (iMsg){
	case WM_CREATE:
		SetTimer(hwnd, 1, 2000, NULL);	//1 - ID таймера, 2секунды
		break;
	case WM_TIMER:
		SetClassLong(hwnd, -10, (LONG)CreateSolidBrush(RGB(10, 10, 10)));	//-10 дескриптор кисти в котором старое значение
		InvalidateRect(hwnd, NULL, true);	// перерисовка окна
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, L"Hello, Step 2", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text! 2", L"my text", MB_ICONINFORMATION);
		break;
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		MoveWindow(hwnd, 0, 0, 500, 350, true);
		break;
	case WM_DESTROY:
		KillTimer(hwnd, 1);	//дескриптор и ID таймера
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}