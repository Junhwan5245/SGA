#include "stdafx.h"
#include "Scene2.h"
#include "Scene1.h"
#include "SceneChoice.h"


SceneChoice::SceneChoice()
{


	fire = new ObImage(L"Fire.png");
	effect1 = new ObImage(L"SceneMenu1.png");
	effect2 = new ObImage(L"SceneMenu2.png");
	effect3 = new ObImage(L"SceneMenu3.png");
	go = new ObImage(L"go.png");
	fishMenuIdle = new ObImage(L"FishMenuIdle.png");
	crystalMenuIdle = new ObImage(L"crystalMenuIdle.png");
	randomPortrait = new ObImage(L"randomPortrait.png");
	fishPortrait = new ObImage(L"FishPortrait.png");
	crystalPortrait = new ObImage(L"CrystalPortrait.png");
	fishPortrait2 = new ObImage(L"fishPortrait2.png");
	crystalPortrait2 = new ObImage(L"crystalPortrait2.png");
	fishName = new ObImage(L"Fish.png");
	crystalName = new ObImage(L"Crystal.png");
	back = new ObImage(L"back.png");
	bg = new ObImage(L"bg.png");
	

	goRect = new ObRect();
	fireRect = new ObRect();
	fishRect = new ObRect();
	randomRect = new ObRect();
	crystalRect = new ObRect();
	backRect = new ObRect();
	
	

	goRect->isFilled = false;
	fireRect->isFilled = false;
	fishRect->isFilled = false;
	crystalRect->isFilled = false;
	randomRect->isFilled = false;
	backRect->isFilled = false;

	
	
	back->maxFrame.x = 4;
	back->scale.x = back->imageSize.x / back->maxFrame.x* 2;
	back->scale.y = back->imageSize.y * 2;
	

	fire->maxFrame.x = 8;
	fire->scale.x = fire->imageSize.x / fire->maxFrame.x * 2;
	fire->scale.y = fire->imageSize.y * 2;
	fire->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	effect1->scale.x = effect1->imageSize.x * 6;
	effect1->scale.y = effect1->imageSize.y * 4;

	effect2->scale.x = effect2->imageSize.x * 3;
	effect2->scale.y = effect2->imageSize.y * 2;

	effect3->scale.x = effect3->imageSize.x * 3;
	effect3->scale.y = effect3->imageSize.y * 2.5;

	

	go->maxFrame.x = 6;
	go->scale.x = go->imageSize.x / go->maxFrame.x * 3;
	go->scale.y = go->imageSize.y*2;

	fishMenuIdle->maxFrame.x = 16;
	fishMenuIdle->scale.x = fishMenuIdle->imageSize.x/ fishMenuIdle->maxFrame.x * 3;
	fishMenuIdle->scale.y = fishMenuIdle->imageSize.y * 3;
	fishMenuIdle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	crystalMenuIdle->maxFrame.x = 19;
	crystalMenuIdle->scale.x = crystalMenuIdle->imageSize.x / crystalMenuIdle->maxFrame.x * 3;
	crystalMenuIdle->scale.y = crystalMenuIdle->imageSize.y * 3;
	crystalMenuIdle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	

	fireRect->scale.x = fire->imageSize.x / fire->maxFrame.x * 2;
	fireRect->scale.y = fire->imageSize.y * 2;

	goRect->scale.x = go->imageSize.x/go->maxFrame.x *3;
	goRect->scale.y = go->imageSize.y * 3;

	backRect->scale.x = back->imageSize.x/back->maxFrame.x * 2;
	backRect->scale.y = back->imageSize.y * 2;

	fireRect->scale.x = fire->imageSize.x / fire->maxFrame.x * 2;
	fireRect->scale.y = fire->imageSize.y * 2;

	randomPortrait->scale.x = randomPortrait->imageSize.x * 3;
	randomPortrait->scale.y = randomPortrait->imageSize.y * 3;
	fishPortrait->scale.x = fishPortrait->imageSize.x * 3;
	fishPortrait->scale.y = fishPortrait->imageSize.y * 3;
	crystalPortrait->scale.x = crystalPortrait->imageSize.x * 3;
	crystalPortrait->scale.y = crystalPortrait->imageSize.y * 3;

	randomRect->scale.x = randomPortrait->imageSize.x * 3;
	randomRect->scale.y = randomPortrait->imageSize.y * 3;
	
	fishRect->scale.x = fishPortrait->imageSize.x *3;
	fishRect->scale.y = fishPortrait->imageSize.y * 3;

	crystalRect->scale.x = crystalPortrait->imageSize.x * 3;
	crystalRect->scale.y = crystalPortrait->imageSize.y * 3;

	fishPortrait2->scale.x = fishPortrait2->imageSize.x * 3.5;
	fishPortrait2->scale.y = fishPortrait2->imageSize.y * 3;
	crystalPortrait2->scale.x = crystalPortrait2->imageSize.x * 3.5;
	crystalPortrait2->scale.y = crystalPortrait2->imageSize.y * 3;

	fishName->scale.x = fishName->imageSize.x * 3;
	fishName->scale.y = fishName->imageSize.y * 2;

	crystalName->scale.x = fishName->imageSize.x * 5;
	crystalName->scale.y = fishName->imageSize.y * 2.5;

	bg->scale.x = bg->imageSize.x*1000/1355;
	bg->scale.y = bg->imageSize.y * 692 / 600;
		
	

	fire->SetParentT(*fireRect);
	randomPortrait->SetParentT(*randomRect);
	fishPortrait->SetParentT(*fishRect);
	crystalPortrait->SetParentT(*crystalRect);
	go->SetParentT(*goRect);
	fishMenuIdle->SetParentT(*fireRect);
	crystalMenuIdle->SetParentT(*fireRect);
	back->SetParentT(*backRect);
	effect2->pivot = OFFSET_L;
	effect3->pivot = OFFSET_R;
	/*crystalMenu = new ObImage(L"go.png");
	*/

	characterNum = 1;
}

SceneChoice::~SceneChoice()
{
	delete fire;
	delete effect1;
	delete effect2;
	delete effect3;
	delete go;
	delete fishMenuIdle;
	delete	goRect;
	delete	fireRect;
	delete	fishRect;
	delete	randomRect;
	delete  randomPortrait;
	delete  fishPortrait;
	delete  crystalPortrait;
	delete  fishPortrait2;
	delete  crystalPortrait2;
	delete  fishName;
	delete	crystalName;
	delete	randomName;
	delete	back;
	delete	backRect;
		
}			

void SceneChoice::Init()
{
	
	fireRect->SetWorldPosX(0);
	fireRect->SetWorldPosY(20);
	fishMenuIdle->SetLocalPosY(100);
	crystalMenuIdle->SetLocalPosY(-100);
	effect1->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetHalfWidth(), app.GetHeight()*0.9)));
	
	effect2->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth(), app.GetHeight()*0.7)));
	
	effect3->SetWorldPos(Utility::WorldToScreen(Vector2(0, app.GetHeight()*0.65)));
	
	randomRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth()+ app.GetWidth()*0.05, app.GetHeight() *0.9)));

	fishRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.125, app.GetHeight() * 0.9)));

	crystalRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.2, app.GetHeight() * 0.9)));
	
	fishPortrait2->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.15, app.GetHeight() * 0.37)));

	crystalPortrait2->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.15, app.GetHeight() * 0.37)));

	fishName->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.130, app.GetHeight() * 0.6)));

	crystalName->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.23, app.GetHeight() * 0.6)));

	backRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.03, app.GetHeight() * 0.05)));

	goRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.925, app.GetHeight() * 0.9)));

	/*bg->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() , app.GetHeight() )));*/
	
}

void SceneChoice::Release()
{
}

void SceneChoice::Update()
{
	Vector2 asd = Utility::WorldToScreen(INPUT->GetWorldMousePos());
	ImGui::Text("mousePosX,%f", INPUT->GetWorldMousePos().x);
	ImGui::Text("mousePosy,%f", INPUT->GetWorldMousePos().y);
	ImGui::Text("scPosX,%f", asd.x);
	ImGui::Text("scPosX,%f", asd.y);
	ImGui::Text("characterNum,%d", characterNum);

	if (fishRect->Intersect(INPUT->GetWorldMousePos()))
	{
		if (INPUT->KeyDown(VK_LBUTTON))
		{
			characterNum = 2;
					
		}
	}

	if (crystalRect->Intersect(INPUT->GetWorldMousePos()))
	{

		if (INPUT->KeyDown(VK_LBUTTON))
		{
			characterNum = 3;
		
		}
	}

	if (backRect->Intersect(INPUT->GetWorldMousePos()))
	{
		
		back->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		if (INPUT->KeyDown(VK_LBUTTON))
		{
			SCENE->ChangeScene("SC1", 0.0f);
		}
	}

	else if (goRect->Intersect(INPUT->GetWorldMousePos()))
	{
		go->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		if (INPUT->KeyDown(VK_LBUTTON))
		{
				cout << SCENE->playerNum << endl;
				SCENE->playerNum = characterNum;
				cout << SCENE->playerNum << endl;
				SCENE->ChangeScene("SC2", 0.0f);
			
		}
	}
	
	else
	{
		go->ChangeAnim(ANIMSTATE::STOP, 0.0);
		go->frame.x = 0;
		back->ChangeAnim(ANIMSTATE::STOP,0.0);
		back->frame.x = 0;
	}

	/*CAM->position = Vector2(0, 0);*/
	fireRect->Update();
	fire->Update();
	fishRect->Update();
	fishMenuIdle->Update();
	crystalMenuIdle->Update();
	crystalRect->Update();
	effect1->Update();
	effect2->Update();
	effect3->Update();
	randomRect->Update();
	randomPortrait->Update();
	fishPortrait->Update();
	crystalPortrait->Update();
	fishPortrait2->Update();
	crystalPortrait2->Update();
	fishName->Update();
	crystalName->Update();
	back->Update();
	backRect->Update();
	go->Update();
	goRect->Update();
	bg->Update();

}

void SceneChoice::LateUpdate()
{
}

void SceneChoice::Render()
{
	bg->Render();
	if(characterNum==2)
	fishPortrait2->Render();
	
	if (characterNum == 3)
	crystalPortrait2->Render();
	
	/*fireRect->Render();*/
	fire->Render();
	fishMenuIdle->Render();
	crystalMenuIdle->Render();
	effect1->Render();
	effect2->Render();
	effect3->Render();
	/*randomRect->Render();
	fishRect->Render();
	crystalRect->Render();*/
	randomPortrait->Render();
	fishPortrait->Render();
	crystalPortrait->Render();
	
	if (characterNum == 2)
	fishName->Render();
	
	if (characterNum == 3)
	crystalName->Render();
	
	backRect->Render();
	back->Render();

	goRect->Render();
	go->Render();
	
	

}

void SceneChoice::ResizeScreen()
{
	/*effect1->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetHalfWidth(), app.GetHeight() * 0.9)));

	effect2->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth(), app.GetHeight() * 0.7)));

	effect3->SetWorldPos(Utility::WorldToScreen(Vector2(0, app.GetHeight() * 0.65)));

	randomRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.05, app.GetHeight() * 0.9)));

	fishRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.125, app.GetHeight() * 0.9)));

	crystalRect->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.2, app.GetHeight() * 0.9)));

	fishPortrait2->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.15, app.GetHeight() * 0.37)));

	crystalPortrait2->SetWorldPos(Utility::WorldToScreen(Vector2(-app.GetWidth() + app.GetWidth() * 0.15, app.GetHeight() * 0.37)));*/
	Init();

	effect1->scale.x = effect1->imageSize.x * 6 * (app.GetWidth() / 1000);
	effect1->scale.y = effect1->imageSize.y * 4 * (app.GetHeight() / 600);

	effect2->scale.x = effect2->imageSize.x * 3 * (app.GetWidth() / 1000);
	effect2->scale.y = effect2->imageSize.y * 2 * (app.GetHeight() / 600);

	effect3->scale.x = effect3->imageSize.x * 3 * (app.GetWidth() / 1000);
	effect3->scale.y = effect3->imageSize.y * 2.5 * (app.GetHeight() / 600);



	randomPortrait->scale.x = randomPortrait->imageSize.x * 3 * (app.GetWidth() / 1000);
	randomPortrait->scale.y = randomPortrait->imageSize.y * 3 * (app.GetHeight() / 600);

	fishPortrait->scale.x = randomPortrait->imageSize.x * 3 * (app.GetWidth() / 1000);
	fishPortrait->scale.y = randomPortrait->imageSize.y * 3 * (app.GetHeight() / 600);

	crystalPortrait->scale.x = randomPortrait->imageSize.x * 3 * (app.GetWidth() / 1000);
	crystalPortrait->scale.y = randomPortrait->imageSize.y * 3 * (app.GetHeight() / 600);

	randomRect->scale.x = randomPortrait->imageSize.x * 2 * (app.GetWidth() / 1000);
	randomRect->scale.y = randomPortrait->imageSize.y * 2 * (app.GetHeight() / 600);

	fishRect->scale.x = fishPortrait->imageSize.x * 2 * (app.GetWidth() / 1000);
	fishRect->scale.y = fishPortrait->imageSize.y * 2 * (app.GetHeight() / 600);

	crystalRect->scale.x = crystalPortrait->imageSize.x * 2 * (app.GetWidth() / 1000);
	crystalRect->scale.y = crystalPortrait->imageSize.y * 2 * (app.GetHeight() / 600);

	fishPortrait2->scale.x = fishPortrait2->imageSize.x * 3.5 * (app.GetWidth() / 1000);
	fishPortrait2->scale.y = fishPortrait2->imageSize.y * 3 * (app.GetHeight() / 600);

	crystalPortrait2->scale.x = crystalPortrait2->imageSize.x * 3.5 * (app.GetWidth() / 1000);
	crystalPortrait2->scale.y = crystalPortrait2->imageSize.y * 3 * (app.GetHeight() / 600);
	
	fishName->scale.x = fishName->imageSize.x * 3.5 * (app.GetWidth() / 1000);
	fishName->scale.y = fishName->imageSize.y * 3 * (app.GetHeight() / 600);

	crystalName->scale.x = crystalName->imageSize.x * 3.5 * (app.GetWidth() / 1000);
	crystalName->scale.y = crystalName->imageSize.y * 3 * (app.GetHeight() / 600);

	
}
