#pragma once

class Main : public Scene
{
private:
	Scene1* SC1;
	SceneChoice* SCC;
	Scene2* SC2;
	

public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
