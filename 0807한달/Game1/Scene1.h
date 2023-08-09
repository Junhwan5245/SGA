#pragma once
class Scene1 : public Scene
{
private:

	
	ObRect* playButton;
	ObRect* settingButton;
	ObRect* quitButton;
	ObImage* play;
	ObImage* setting;
	ObImage* quit;
	ObImage* playClickEffect;
	ObImage* settingClickEffect;
	ObImage* quitClickEffect;
	ObImage* bg;
	bool isPlayClick;
	bool isSettingClick;
	bool isQuitClick;
public:
	Scene1();
	~Scene1();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

