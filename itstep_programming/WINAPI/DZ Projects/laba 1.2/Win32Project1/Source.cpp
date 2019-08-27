#include <Windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow) {
	/*LPWSTR szClassName = L"MyWindowClass";
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

	if (!RegisterClassEx(&wndclass)) { MessageBox(NULL, L"WND unregistered!", L"WND", MB_YESNO); return 1; }
	*/
	//HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window", WS_OVERLAPPEDWINDOW, 100, 100, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	/*if (!hWnd) {
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}
	
	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) == TRUE) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;*/
	MessageBox(NULL, L"some information", L"WND information", MB_ICONINFORMATION | MB_OKCANCEL);
	MessageBox(NULL, L"error", L"WND error", MB_ICONERROR | MB_OK);
	MessageBox(NULL, L"question?", L"WND question", MB_ICONQUESTION | MB_YESNO);
	MessageBox(NULL, L"warning", L"WND warning", MB_ICONWARNING | MB_RETRYCANCEL);
	return 0;
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
		DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}