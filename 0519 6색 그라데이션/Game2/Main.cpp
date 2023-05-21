#include "stdafx.h"
#include "Main.h"

Main::Main()
{
	target = new ObCircle();
}

Main::~Main()
{
	delete target;
}
void Main::Init()
{
	target->scale.x = app.GetHalfWidth();
	target->scale.y = app.GetHalfWidth();


}

void Main::Release()
{
}

void Main::Update()
{
	target->Update();
}

void Main::LateUpdate()
{
	
}

void Main::Render()
{
	target->Render();
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game2");
	app.SetInstance(instance);
	app.InitWidthHeight(1000.0f, 800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}