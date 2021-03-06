/////////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2017, xizaixuan. All rights reserved.
/// \brief   引擎控制类
/// \author  xizaixuan
/// \date    2017-07
/////////////////////////////////////////////////////////////////////////////////
#ifndef Engine_H_
#define Engine_H_

#include <Windows.h>
#include "..\Utility\Singleton.h"
#include "..\Mathematics\Float2.h"

class Camera;

class Engine : public Singleton<Engine>
{
	SINGLETON_DEFINE(Engine)
private:
	Engine();
	~Engine();

public:
	/// \brief 初始化
	void Init(HINSTANCE hInstance, int nCmdShow, int width, int height);

	/// \brief 资源销毁
	void Destroy();

	/// \brief 更新
	void Update(float dt);

	/// \brief 场景绘制
	void RenderScene();

	void OnMouseMove(WPARAM btnState, int x, int y);

	void LoadModel();

private:
	Camera* m_Camera;

	float m_Theta;
	float m_Phi;
	float m_Radius;

	float2 m_LastMousePos;
};


#endif