#include <Windows.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc2(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc3(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc4(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow) {
	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"Myfirst window";
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);// или CreateSolidBrush(RGB(0,0,0));
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass)) { MessageBox(NULL, L"WND unregistered - 1!", L"WND", MB_YESNO); return 1; }

	//HWND hWnd2 = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window", WS_OVERLAPPEDWINDOW, 100, 100, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width

	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window", WS_OVERLAPPEDWINDOW, 100, 100, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd) {
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}
	LPWSTR szClassName2 = L"MyWindowClass 2";
	LPWSTR szTitleName2 = L"Myfirst window2";
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

	if (!RegisterClassEx(&wndclass2)) { MessageBox(NULL, L"WND unregistered! - 2", L"WND", MB_YESNO); return 1; }

	HWND hWnd2 = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName2, L"My Window2", WS_OVERLAPPEDWINDOW, 10, 10, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd2) {
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}
	LPWSTR szClassName3 = L"MyWindowClass 3";
	LPWSTR szTitleName3 = L"Myfirst window 3";
	WNDCLASSEX wndclass3;
	//ZeroMemory(&wndclass3, sizeof(WNDCLASSEX));
	memset(&wndclass3, 0, sizeof(wndclass3));
	wndclass3.cbSize = sizeof(wndclass3);
	wndclass3.lpszClassName = szClassName3;
	wndclass3.style = CS_HREDRAW | CS_VREDRAW;
	wndclass3.lpfnWndProc = WndProc3;
	wndclass3.cbClsExtra = 0;
	wndclass3.cbWndExtra = 0;
	wndclass3.hInstance = hInstance;
	wndclass3.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass3.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass3.hbrBackground = CreateSolidBrush(RGB(10, 10, 10));;// или CreateSolidBrush(RGB(0,0,0));
	wndclass3.lpszMenuName = NULL;
	wndclass3.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass3)) { MessageBox(NULL, L"WND unregistered! - 3", L"WND", MB_YESNO); return 1; }
	HWND hWnd3 = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName3, L"My Window3", WS_OVERLAPPEDWINDOW, 150, 150, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd3) {
		MessageBox(NULL, L"HWND3", L"no hWnd3!", MB_OK); return 1;
	}

	LPWSTR szClassName4 = L"MyWindowClass 4";
	LPWSTR szTitleName4 = L"Myfirst window 4";
	WNDCLASSEX wndclass4;
	//ZeroMemory(&wndclass3, sizeof(WNDCLASSEX));
	memset(&wndclass4, 0, sizeof(wndclass4));
	wndclass4.cbSize = sizeof(wndclass4);
	wndclass4.lpszClassName = szClassName4;
	wndclass4.style = CS_HREDRAW | CS_VREDRAW;
	wndclass4.lpfnWndProc = WndProc4;
	wndclass4.cbClsExtra = 0;
	wndclass4.cbWndExtra = 0;
	wndclass4.hInstance = hInstance;
	wndclass4.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass4.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass4.hbrBackground = CreateSolidBrush(RGB(0, 155, 0));;// или CreateSolidBrush(RGB(0,0,0));
	wndclass4.lpszMenuName = NULL;
	wndclass4.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass4)) { MessageBox(NULL, L"WND unregistered! - 4", L"WND", MB_YESNO); return 1; }
	HWND hWnd4 = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName4, L"My Window4", WS_OVERLAPPEDWINDOW, 250, 250, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd4) {
		MessageBox(NULL, L"HWND3", L"no hWnd4!", MB_OK); return 1;
	}
	ShowWindow(hWnd4, 1);
	UpdateWindow(hWnd4);
	ShowWindow(hWnd3, 1);
	UpdateWindow(hWnd3);
	ShowWindow(hWnd2, 1);
	UpdateWindow(hWnd2);

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) == TRUE) {
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
	switch (iMsg) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		//DrawText(hdc, L"Hello,\n\n Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
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
	switch (iMsg) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		//DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text! 2", L"my text", MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
LRESULT CALLBACK WndProc3(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;	//дескриптор устройства управления
	PAINTSTRUCT ps;
	RECT rect;	//rectangle
	switch (iMsg) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		//DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text! 2", L"my text", MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
LRESULT CALLBACK WndProc4(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;	//дескриптор устройства управления
	PAINTSTRUCT ps;
	RECT rect;	//rectangle
	switch (iMsg) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		//DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text! 2", L"my text", MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}