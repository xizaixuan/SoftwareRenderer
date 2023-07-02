#include "Engine.h"
#include "Utility/WinApp.h"
#include "Utility/RenderDevice.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Init(HINSTANCE hInstance, int nCmdShow, int width, int height)
{
	WinApp::GetSingletonPtr()->Create(hInstance, nCmdShow, width, height, "SoftwareRenderer");

	RenderDevice::GetSingletonPtr()->InitRenderDevice(WinApp::GetSingletonPtr()->GetHwnd(), width, height);
}

void Engine::Destroy()
{

}

void Engine::Update(float dt)
{
	RenderDevice::GetSingletonPtr()->RenderBegin();

	RenderDevice::GetSingletonPtr()->RenderBuffer();

	RenderDevice::GetSingletonPtr()->RenderEnd();
}