#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow) {
	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"Myfirst window";
	WNDCLASSEX wndclass;
	memset(&wndclass, 0, sizeof(wndclass));
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	//wndclass.cbClsExtra = 0;
	//wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_HAND);
	wndclass.hIcon = LoadIcon(NULL, IDI_SHIELD);
	wndclass.hbrBackground = CreateSolidBrush(RGB(218, 165, 32));//(HBRUSH)GetStockObject(WHITE_BRUSH);// или CreateSolidBrush(RGB(0,0,0));
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass)) { MessageBox(NULL, L"WND unregistered - 1!", L"WND", MB_YESNO); return 1; }
	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window hwnd1", /*WS_POPUPWINDOW*/ WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, 100, 100, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd) {
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}

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
	case WM_CREATE:
		SetTimer(hwnd, 1, 2000, NULL);	//1 - ID таймера, 2секунды
		break;
	case WM_TIMER:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text 1!", L"my text", MB_ICONINFORMATION);
		break;
	case WM_LBUTTONDOWN:
		SetClassLong(hwnd, -10, (LONG)CreateSolidBrush(RGB(10, 10, 10)));//-10 дескриптор кисти в котором старое значение
		InvalidateRect(hwnd, NULL, true);	// перерисовка окна
		break;
	case WM_RBUTTONDOWN:
		//case WM_RBUTTONDBLCLK:
		//SetClassLong(hwnd, -10, (LONG)CreateSolidBrush(RGB(218, 165, 32)));
		//InvalidateRect(hwnd, NULL, true);
		//SetWindowPos(hwnd, HWND_BOTTOM, 100, 100, 500 /*width*/, 500 /*height*/, SWP_NOMOVE);	//изменить размер окна
		//InvalidateRect(hwnd, NULL, true);	// перерисовка окна
	//case VK_0:
	case VK_RIGHT:
		KillTimer(hwnd, 1);	//дескриптор и ID таймера
		PostQuitMessage(0);
		return 0;
	case WM_DESTROY:
		KillTimer(hwnd, 1);	//дескриптор и ID таймера
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}