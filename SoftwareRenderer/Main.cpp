#include <windows.h>
#include "Engine.h"

int	WINAPI	WinMain(	IN HINSTANCE hInstance,
						IN HINSTANCE hPrevInstance,
						IN LPSTR lpCmdLine,
						IN int nCmdShow)
{
	Engine::GetSingletonPtr()->Init(hInstance, nCmdShow, 1920, 1080);

	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	float secsPerCnt = 1.0f/(float)cntsPerSec;

	__int64 prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);
	
	MSG msg;
	for(;;)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if ( msg.message==WM_QUIT) break;
			TranslateMessage(&msg); 
			DispatchMessage(&msg);
		}
		else
		{
			__int64 currTimeStamp = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);

			float dt = (currTimeStamp - prevTimeStamp)*secsPerCnt;

			Engine::GetSingletonPtr()->Update(dt);

			prevTimeStamp = currTimeStamp;
		}
	}

	Engine::GetSingletonPtr()->Destroy();

	return (int) msg.wParam;
}