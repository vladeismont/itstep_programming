#include <Windows.h>

HWND hWndChild;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc2(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#define ID_BUTTON 3000
HWND hWnd, hWndBut;
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow){
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
	wndclass.hbrBackground = CreateSolidBrush(RGB(255, 0, 255));//(HBRUSH)GetStockObject(WHITE_BRUSH);// или CreateSolidBrush(RGB(0,0,0));
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass)){ MessageBox(NULL, L"WND unregistered - 1!", L"WND", MB_YESNO); return 1; }

	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window", WS_OVERLAPPEDWINDOW, 100, 100, 350, 350, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd){
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}
	LPWSTR szClassName2 = L"MyWindowClass 1";
	LPWSTR szTitleName2 = L"Myfirst window";
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

	if (!RegisterClassEx(&wndclass2)){ MessageBox(NULL, L"WND unregistered - 1!", L"WND", MB_YESNO); return 1; }

	hWndBut = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Click", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		10, 10, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUTTON,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut) { return false; }

	hWndChild = CreateWindowEx(WS_EX_TOPMOST,
		szClassName2,
		L"ChildWindow",
		WS_CHILD | WS_OVERLAPPEDWINDOW, //WS_POPUP or WS_OVERLAPPEDWINDOW
		10, 10, 200, 200,
		hWnd,
		NULL,
		hInstance,
		NULL);
	if (!hWndChild){ return false; }
	
	ShowWindow(hWndChild, 1);
	UpdateWindow(hWndChild);

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
	TEXTMETRIC tm;//структура содержит настройки шрифта
	
	wchar_t str[50];	//для юникода
	long x;
	static int height;
	static int th;
	switch (iMsg){
	case WM_CREATE:	//событие создание окна
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		height = tm.tmExternalLeading + tm.tmHeight;
		th = tm.tmHeight;
		ReleaseDC(hwnd, hdc);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)){
		case ID_BUTTON:
			MessageBox(hwnd, L"But1", L"1", MB_OK);
			SendMessage((HWND)lParam, BM_SETSTATE, TRUE, 0);
			/*if (!SendMessage(hWndButton2, BM_GETCHECK, 0, 0))
				SendMessage(hWndButton2, BM_SETSTATE, FALSE, 0);*/
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);	//дескриптор контекста устройства
		GetClientRect(hwnd, &rect);
		x = rect.right;
		
		/*wsprintf(str, TEXT("rect.right= %li \n"), x);
		MessageBox(NULL, str, L"my text", MB_ICONINFORMATION);
		*/
		//DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE /*| DT_VCENTER*/);

		TextOut(hdc, 10, 10, L"Это текстовая строка", 20);
		TextOut(hdc, 0, height + 10, L"Это текстовая строка", 20);
		TextOut(hdc, 10, height + 50, L"Это текстовая строка", 20);

		//wsprintf(str, TEXT("tm.Height 16= %li \n"), th);
		//MessageBox(NULL, str, L"my text", MB_ICONINFORMATION);

		SetTextColor(hdc, RGB(50, 50, 150)); // Цвет шрифта
		SetBkMode(hdc, TRANSPARENT);// Не закрашивать фон // под текстом
		DrawText(hdc, L"Hello, Step\nBye, Step", -1, &rect, DT_CENTER | DT_TOP );
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text 1!", L"my text", MB_ICONINFORMATION);
		break;
	case WM_LBUTTONDOWN:
		SetParent(hWndChild, NULL);//null or desktop
		//MoveWindow(hwnd, 300, 300, 500,500, true);
		//PostQuitMessage(0);
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
	switch (iMsg){
	/*case WM_LBUTTONDOWN:
		SetClassLong(hwnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_WAIT));
		break;*/
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, L"Hello, Step", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text! 2", L"my text", MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}