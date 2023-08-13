#pragma once
#define ITEMMAX 7
class Scene3 : public Scene
{
private:


	ObTileMap* map;
	ObTileMap* floor;
	class ItemBox* Itembox[ITEMMAX];
	class UI* Ui;

	


public:
	Scene3();
	~Scene3();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;

	
	bool collide(class Bullet* bullet);//�÷��̾� �Ѿ��� �浹
	bool Moncollide(class Bullet* monbullet);//���� �Ѿ��� �浹
	bool bossCollide(class Bullet* bossbullet);//���� �Ѿ��� �浹
	bool isMove();
};

