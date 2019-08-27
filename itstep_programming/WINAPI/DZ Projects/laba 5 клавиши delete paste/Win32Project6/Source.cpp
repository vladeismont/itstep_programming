#include <Windows.h>
#include <tchar.h>
//#include <winuser.h>
HWND hWndChild;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#define ID_BUTTON 3000
#define ID_BUTTON1 3001
#define ID_BUTTON2 3002
#define ID_BUTTON3 3003
HWND hWnd, hWndBut, hWndBut1, hWndBut2, hWndBut3;
#define ID_EDIT 100
#define ID_EDIT1 101
HWND hEdit, hEdit1;
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

	hWndBut1 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"delete", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		60, 10, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUTTON1,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut1) { return false; }
	hWndBut2 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"paste", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		110, 10, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUTTON2,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut2) { return false; }
	hWndBut3 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"copy", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		160, 10, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUTTON2,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut3) { return false; }

	hEdit = CreateWindowEx(WS_EX_TOPMOST, L"EDIT",// класс
		L"???", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE | ES_MULTILINE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		60, 60, 100, 50,hWnd,// Родительское окно
		(HMENU) ID_EDIT,// идентификатор
		hInstance,NULL);
	hEdit1 = CreateWindowEx(WS_EX_TOPMOST, L"EDIT",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE | ES_MULTILINE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		170, 60, 100, 50, hWnd,// Родительское окно
		(HMENU)ID_EDIT,// идентификатор
		hInstance, NULL);
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

	wchar_t str[512];	//для юникода
	long x;
	static int height;
	static int th;
	LONG style;
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
			//SendMessage((HWND)lParam, BM_SETSTATE, TRUE, 0);
			/*if (!SendMessage(hWndButton2, BM_GETCHECK, 0, 0))
			SendMessage(hWndButton2, BM_SETSTATE, FALSE, 0);*/
			break;
		case ID_BUTTON1:
			SendMessage(hEdit, EM_SETSEL, 0, -1);
			SendMessage(hEdit, WM_CUT, 0, 0);
			break;
		case ID_BUTTON2:
			SendMessage(hEdit1, WM_PASTE, 0, 0);
			SetFocus(hEdit);
			break;
		case ID_BUTTON3:
			//SendMessage(hEdit, WM_COPY, 0, 0);	//WM_COPY несовместима с юникодом (не работает)
			//SendMessage(hEdit1, WM_PASTE, 0, 0);
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

		/*TextOut(hdc, 10, 10, L"Это текстовая строка", 20);
		TextOut(hdc, 0, height + 10, L"Это текстовая строка", 20);
		TextOut(hdc, 10, height + 50, L"Это текстовая строка", 20);*/
		SetTextColor(hdc, RGB(50, 50, 150)); // Цвет шрифта
		SetBkMode(hdc, TRANSPARENT);// Не закрашивать фон // под текстом
		DrawText(hdc, L"Hello, Step\nBye, Step", -1, &rect, DT_CENTER | DT_TOP);
		EndPaint(hwnd, &ps);
		//MessageBox(NULL, L"text 1!", L"my text", MB_ICONINFORMATION);
		break;
	case WM_LBUTTONDOWN:
		SetWindowText(hEdit,L"this is text");
		style = GetWindowLong(hEdit, GWL_STYLE);
		SetWindowLong(hEdit, GWL_STYLE, style/* | ES_NUMBER*/);	//только цыфры, ES_MULTILINE убрался
		wsprintf(str, L"tm.Height = %d \n", th);
		MessageBox(NULL, str, L"my text", MB_ICONINFORMATION);
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
