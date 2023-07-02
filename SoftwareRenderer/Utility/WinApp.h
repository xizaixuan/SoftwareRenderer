#ifndef WinApp_H_
#define WinApp_H_

#include <windows.h>
#include "..\Utility\Singleton.h"

class WinApp : public Singleton<WinApp>
{
	SINGLETON_DEFINE(WinApp)
private:
	WinApp();
	~WinApp();

public:
	void	Create(HINSTANCE hInstance, int nCmdShow, int width, int height, LPCSTR caption);	

	int		GetWidth();

	int		GetHeight();

	HWND	GetHwnd();

private:
	WORD	RegisterClass(HINSTANCE hInstance);

	bool	Init(HINSTANCE hInstance, int nCmdShow);

	static	LRESULT CALLBACK  WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	LPCSTR	m_Caption;

	int		m_Height;

	int		m_Width;

	HWND	m_HWND;
};

#endif