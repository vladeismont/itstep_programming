#include <Windows.h>
#include <fstream>
#include <string>
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow) {
	std::wifstream in;
	in.open("karatkevich.txt");
	int strMax=0, average, count = 0,sum=0;
	int strMin = MAXINT;
	std::wstring str;
	if (!in.is_open())
	{
		MessageBox(NULL, L"����� ���", L"!!!!!!!", MB_ICONWARNING);
		return 1;
	}
	else
		while (!in.eof())
		{
			std::getline(in, str);
			++count;
			if (strMax < str.length()) {
				strMax = str.length();
			}
			if (strMin > str.length()) {
				strMin = str.length();
			}
			sum += str.length();
		}
	average = sum / count;
	in.close();
	wchar_t tmp[512];
	wsprintf(tmp, TEXT("����� ����� ������� ������: %d\n����� ����� �������� ������: %d\n������� ����� �����:%d"), strMax, strMin, average);
	MessageBox(NULL, tmp, L"my text", MB_ICONINFORMATION);
	return 0;
}
