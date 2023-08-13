#pragma once
class UI
{
public:
	ObImage* playerLevelUIOut;
	ObImage* playerLevelUImiddle;
	ObImage* playerLevelUIin;
	ObImage* playerHpUIOut;
	ObImage* playerHpUIin;
	RECT HpUi;
	RECT levelUi;
	
	UI();
	~UI();
	void Init();
	void Release(); //해제
	void Update();
	void LateUpdate();//갱신
	void Render();
	void ResizeScreen();

	
};

