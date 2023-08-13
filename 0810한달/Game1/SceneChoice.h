#pragma once
class SceneChoice : public Scene
{
private:

	
	ObImage* fire;
	ObImage* effect1;
	ObImage* effect2;
	ObImage* effect3;
	ObImage* go;
	ObImage* fishMenuIdle;
	ObImage* crystalMenuIdle;
	ObImage* randomPortrait;
	ObImage* fishPortrait;
	ObImage* crystalPortrait;
	ObImage* fishPortrait2;
	ObImage* crystalPortrait2;
	ObImage* fishName;
	ObImage* crystalName;
	ObImage* randomName;
	ObImage* back;
	ObImage* bg;
	

	ObRect* backRect;
	ObRect* goRect;
	ObRect* randomRect;
	ObRect* fishRect;
	ObRect* crystalRect;
	ObRect* fireRect;
	
	/*ObImage* back;*/

	int characterNum;

	
	ObTileMap* map;
	ObTileMap* floor;


public:
	SceneChoice();
	~SceneChoice();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};


