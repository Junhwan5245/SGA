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
	void Release(); //����
	void Update();
	void LateUpdate();//����
	void Render();
	void ResizeScreen();

	
};

