#include "stdafx.h"
#include "Scene1.h"
#include "SceneChoice.h"
#include "Scene2.h"
#include "Main.h"

Main::Main()
{
	SC1 = new Scene1();
	SCC = new SceneChoice();
	SC2 = new Scene2();

}

Main::~Main()
{

}

void Main::Init()
{
	
	SCENE->AddScene("SC1",SC1);
	SCENE->AddScene("SCC", SCC);
	SCENE->AddScene("SC2", SC2);

	SCENE->ChangeScene("SC1");
}

void Main::Release()
{
   
}

void Main::Update()
{
	ImGui::Text("Frame %d", (int)TIMER->GetFramePerSecond());
	SCENE->Update();
}

void Main::LateUpdate()
{
	
	SCENE->LateUpdate();

}

void Main::Render()
{
	SCENE->Render();
}

void Main::ResizeScreen()
{
	SCENE->ResizeScreen();
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Nuclear Throne");
    app.SetInstance(instance);
	app.InitWidthHeight(1000.0f,600.0f);
    app.background = Color(0.3, 0.3, 0.3);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}