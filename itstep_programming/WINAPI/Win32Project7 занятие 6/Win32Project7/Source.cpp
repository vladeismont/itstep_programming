#include <Windows.h>
#include <tchar.h>
#include <fstream>
#include <string>
#include <codecvt>
#include <commdlg.h>
std::locale loc(std::locale::classic(), new std::codecvt_utf8 <wchar_t>);

static OPENFILENAME openFile;//
static OPENFILENAME saveFile;
 wchar_t szFileName[256];	//диалоговые окна
 wchar_t szFileTitle[100];
 wchar_t szFileNameSave[256];	//диалоговые окна
 wchar_t szFileTitleSave[100];

#define ID_EDIT 100
#define ID_EDIT1 101
#define ID_SHOW 3001
#define ID_DELETE1 3002
#define ID_DELETE2 3003
#define ID_RECORD 3004
#define ID_BUT11 3011
#define ID_BUT12 3012
#define ID_BUT13 3013
#define ID_BUT14 3014
HWND hWndBut1, hWndBut2, hWndBut3, hWndBut4, hWndBut11, hWndBut12, hWndBut13, hWndBut14;

HWND hEdit1, hEdit2, hEdit3;
HWND hStatic1, hStatic2;
CHOOSECOLOR chooseColor;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow){
	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"Myfirst window";
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //WS_HSCROLL | WS_VSCROLL
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

	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW/*WS_EX_TOPMOST - отображать поверх всех окон*/, szClassName, L"My Window", WS_OVERLAPPEDWINDOW, 20, 20, 1600, 1000, NULL, NULL, hInstance, NULL);	//100-отрыв от угла; 350-high, width
	if (!hWnd){
		MessageBox(NULL, L"HWND", L"no hWnd!", MB_OK); return 1;
	}

	hEdit1 = CreateWindowEx(WS_EX_TOPMOST, L"EDIT",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE | ES_MULTILINE |WS_HSCROLL|WS_VSCROLL,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		50, 50, 420, 750, hWnd,// Родительское окно
		(HMENU)ID_EDIT,// идентификатор
		hInstance, NULL);
	hStatic1 = CreateWindowEx(WS_EX_TOPMOST, L"static",// СТАТИК
		L"Исходный текст", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE | SS_SIMPLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		50, 30, 130, 16, hWnd,// Родительское окно
		(HMENU)NULL,// идентификатор
		hInstance, NULL);
	hEdit2 = CreateWindowEx(WS_EX_TOPMOST, L"EDIT",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_HSCROLL | WS_VSCROLL,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		550, 50, 420, 750, hWnd,// Родительское окно
		(HMENU)ID_EDIT,// идентификатор
		hInstance, NULL);
	hStatic2 = CreateWindowEx(WS_EX_TOPMOST, L"static",// СТАТИК
		L"Ваш текст", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE | SS_SIMPLE,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		550, 30, 100, 16, hWnd,// Родительское окно
		(HMENU)NULL,// идентификатор
		hInstance, NULL);
	hEdit3 = CreateWindowEx(WS_EX_TOPMOST, L"listbox",// класс
		L"", // Текст в поле редактора
		WS_CHILD | WS_VISIBLE | LBS_STANDARD/*| WS_HSCROLL | WS_VSCROLL*/,//Стили | ES_READONLY| ES_AUTOHSCROLL| ES_AUTOVSCROLL
		1050, 50, 420, 340, hWnd,// Родительское окно
		(HMENU)ID_EDIT,// идентификатор
		hInstance, NULL);

	hWndBut1 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Показать текст", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		50, 820, 150, 50,
		hWnd,// Родитель
		(HMENU)ID_SHOW,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut1) { return false; }
	hWndBut2 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Удалить текст", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		320, 820, 150, 50,
		hWnd,// Родитель
		(HMENU)ID_DELETE1,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut2) { return false; }
	hWndBut3 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Удалить текст", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		550, 820, 150, 50,
		hWnd,// Родитель
		(HMENU)ID_DELETE2,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut3) { return false; }
	hWndBut4 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"Записать", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		1050, 420, 150, 50,
		hWnd,// Родитель
		(HMENU)ID_RECORD,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut4) { return false; }

	hWndBut11 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L">>", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		480, 340, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUT11,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut11) { return false; }
	hWndBut12 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L">", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		480, 400, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUT12,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut12) { return false; }
	hWndBut13 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L">", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		980, 130, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUT13,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut13) { return false; }
	hWndBut14 = CreateWindowEx(WS_EX_TOPMOST,
		L"button",
		L"X", // Текст на кнопке
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, // Стиль BS_CHECKBOX
		980, 190, 50, 50,
		hWnd,// Родитель
		(HMENU)ID_BUT14,// ID кнопки
		hInstance,
		NULL);
	if (!hWndBut14) { return false; }


	//static wchar_t szFileName[256];	//диалоговые окна
	//static wchar_t szFileTitle[100];
	ZeroMemory(&openFile, sizeof(OPENFILENAME));// заполняем 
	openFile.lStructSize= sizeof(OPENFILENAME);// структуру
	openFile.hInstance= hInstance;
	openFile.hwndOwner= hWnd;
	openFile.lpstrFilter= L"AllFiles(*.*)\0*.*\0\0";
	openFile.nMaxFile= 256;
	openFile.nMaxFileTitle= 30;
	//openFile.lpstrDefExt= L"txt";
	openFile.lpstrFileTitle= szFileTitle;
	openFile.lpstrFile= szFileName;
	openFile.lpstrInitialDir = L"D:";
	//GetOpenFileName(&openFile); //показываем диалог

	ZeroMemory(&saveFile, sizeof(OPENFILENAME));
	saveFile.lStructSize = sizeof(OPENFILENAME);
	saveFile.hInstance = hInstance;
	saveFile.hwndOwner = hWnd;
	saveFile.lpstrFilter = L"AllFiles(*.*)\0*.*\0\0";
	saveFile.nMaxFile = 256;
	saveFile.nMaxFileTitle = 30;
	saveFile.lpstrDefExt = L"txt";
	saveFile.lpstrFileTitle = szFileTitleSave;
	saveFile.lpstrFile = szFileNameSave;
	saveFile.lpstrTitle = L"Сохранить файл?";
	//GetSaveFileName(&openFile);// показываем диалог

	
	static COLORREF colorRef[16];
	ZeroMemory(&chooseColor, sizeof(CHOOSECOLOR));
	chooseColor.lStructSize = sizeof(CHOOSECOLOR);
	chooseColor.hInstance = NULL;
	chooseColor.hwndOwner = hWnd;
	chooseColor.lpCustColors = colorRef;
	chooseColor.rgbResult = RGB(100, 100, 255);
	chooseColor.Flags = CC_RGBINIT | CC_FULLOPEN;
	//выбор цвета
	

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
	//LONG style;
	std::wifstream in;
	std::wstring str;
	std::wstring text;
	switch (iMsg){
	case WM_CREATE:	//событие создание окна
		hdc = GetDC(hwnd);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)){
		case ID_RECORD:
			GetSaveFileName(&openFile);
			break;
		case ID_SHOW:
			MessageBox(hwnd, L"ID_SHOW", L"1", MB_OK);
			GetOpenFileName(&openFile); //показываем диалог

			in.open("text.txt");
			in.imbue(loc);
			if (!in.is_open())
			{
				MessageBox(NULL, L"файла нет", L"!!!!!!!", MB_ICONWARNING);
				return 1;
			}
			else {
				while (!in.eof())
				{
					std::getline(in, str);
					text += str;
					text += '\r';
					text += '\n';
				}
				in.close();
			}
			//MessageBox(NULL,text.c_str(),L"",MB_OK);
			SendMessage(hEdit1, WM_SETTEXT, 0, (LPARAM)text.c_str());
			SendMessage(hEdit1, EM_SETREADONLY, 1, 0);
//			style = GetWindowLong(hEdit1, ES_READONLY);
//			SetWindowLong(hEdit1, GWL_STYLE, style/* | ES_NUMBER*/);
			break;
		case ID_DELETE1:
			SendMessage(hEdit1, EM_SETREADONLY, 0, 0);
			SetWindowText(hEdit1, L"");
			//style = GetWindowLong(hEdit1, GWL_STYLE);
			//SetWindowLong(hEdit1, GWL_STYLE, style/* | ES_NUMBER*/);
			MessageBox(hwnd, L"delete1", L"2", MB_OK);
			break;
		case ID_DELETE2:
			SetWindowText(hEdit2, L"");
			MessageBox(hwnd, L"delete2", L"2", MB_OK);
			break;
		case ID_BUT11:
			MessageBox(hwnd, L"delete11", L"11", MB_OK);
			SendMessage(hEdit1, EM_SETSEL, 0, -1);
			SendMessage(hEdit1, WM_COPY, 0, 0);
			SendMessage(hEdit2, WM_PASTE, 0, 0);
			break;
		case ID_BUT12:
			MessageBox(hwnd, L"delete12", L"12", MB_OK);
			SendMessage(hEdit1, WM_COPY, 0, 0);
			SendMessage(hEdit2, WM_PASTE, 0, 0);
			break;
		case ID_BUT13:
			MessageBox(hwnd, L"delete13", L"13", MB_OK);
			//SendMessage(hEdit2, EM_SETSEL, 0, -1);
			SendMessage(hEdit2, WM_COPY, 0, 0);
			SendMessage(hEdit3, WM_PASTE, 0, 0);
			break;
		case ID_BUT14:
			MessageBox(hwnd, L"delete14", L"14", MB_OK);
			//SendMessage(hEdit2, WM_COPY, 0, 0);
			//SendMessage(hEdit3, WM_PASTE, 0, 0);
			SendMessage(hEdit3, LB_GETCURSEL, 0, 0);
			SendMessage(hEdit3, LB_DELETESTRING, 0, 0);
			break;
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);	//дескриптор контекста устройства
		GetClientRect(hwnd, &rect);
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		
		ChooseColor(&chooseColor);// показываем диалог
		GetClientRect(hwnd, &rect);
		SetClassLong(hwnd, -10, (LONG)CreateSolidBrush(chooseColor.rgbResult));
		InvalidateRect(hwnd, &rect, true);

		/*LOGFONT logFont;
		CHOOSEFONT chFont;
		ZeroMemory(&chFont, sizeof(CHOOSEFONT));
		chFont.lStructSize = sizeof(CHOOSEFONT);
		chFont.hwndOwner = hwnd;
		chFont.lpLogFont = &logFont;
		chFont.Flags = CF_INITTOLOGFONTSTRUCT | CF_SCREENFONTS | CF_EFFECTS;
		ChooseFont(&chFont); hdc = GetDC(hEdit1);
		GetClientRect(hEdit1, &rect);
		hFont = CreateFontIndirect(chFont.lpLogFont);
		SendMessage(hEdit1, WM_SETFONT, (WPARAM)hFont, 0);
		InvalidateRect(hEdit1, &rect, TRUE);
		ReleaseDC(hEdit1, hdc);*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}