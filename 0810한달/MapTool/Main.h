#pragma once

class Main : public Scene
{
private:

	ObTileMap*	map;
	ObTileMap*	floor;
	Int2		tileSize;
	ObRect*		LineX, *LineY;

	bool		isLayer1=false;
	bool		isLayer2=false;
	
	int			brushImgIdx;
	Int2		brushFrame;
	int			brushState;
	Color		brushColor;


public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
