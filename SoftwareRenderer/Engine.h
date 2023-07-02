#ifndef Engine_H_
#define Engine_H_

#include <Windows.h>
#include "Utility\Singleton.h"

class Engine : public Singleton<Engine>
{
	SINGLETON_DEFINE(Engine)
private:
	Engine();
	~Engine();

public:
	void Init(HINSTANCE hInstance, int nCmdShow, int width, int height);

	void Destroy();

	void Update(float dt);
};


#endif