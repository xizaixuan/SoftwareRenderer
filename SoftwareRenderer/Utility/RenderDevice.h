#ifndef _RenderDevice_H_
#define _RenderDevice_H_

#include <windows.h>
#include <D2D1_1.h>
#include "..\Utility\Singleton.h"


#define SAFE_RELEASE(P) if(P != nullptr){P->Release() ; P = nullptr;}
#define SAFE_DELETE(P) if(P != nullptr){delete P; P = nullptr;}
#define SAFE_DELETE_ARRAY(P) if(P != nullptr){delete[] P; P = nullptr;}

class RenderDevice :public Singleton <RenderDevice>
{
	SINGLETON_DEFINE(RenderDevice)
private:
	RenderDevice(void);
	~RenderDevice(void);

public: 
	void InitRenderDevice(HWND hWndMain,int WindowWidth,int WindowHeight);
	 
	void RenderBegin();
	 
	void RenderEnd();
	 
	void RenderBuffer();
	 
	void DrawPixel(DWORD x, DWORD y, DWORD color);

private: 
	DWORD	m_WindowWidth;
	 
	DWORD	m_WindowHeight;
	 
	HWND	m_HWND;
	 
	ID2D1Factory*			m_Factory;
	 
	ID2D1HwndRenderTarget*	m_RenderTarget;
	 
	ID2D1Bitmap*			m_Bitmap;
	 
	DWORD*					m_DataBuffer;
};

#endif
