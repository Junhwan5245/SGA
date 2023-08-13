#pragma once
#define ITEMMAX 7

class Scene2 : public Scene
{
private:

	ObRect* door;
	ObImage* doorImg;
	ObTileMap* map;
	ObTileMap* floor;
	class ItemBox* Itembox[ITEMMAX];
	class UI* Ui;
	int killCount;
	bool isChangeScene=false;


public:
	Scene2();
	~Scene2();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
	
	bool collide(class Bullet* bullet);//플레이어 총알의 충돌
	bool Moncollide(class Bullet* monbullet);//몬스터 총알의 충돌
	bool bossCollide(class Bullet* bossbullet);//몬스터 총알의 충돌

};

