#pragma once
class Scene2 : public Scene
{
private:

	
	ObTileMap* map;
	ObTileMap* floor;
	class ItemBox* Itembox;
	class UI* Ui;




public:
	Scene2();
	~Scene2();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
	
	bool collide(class Bullet* bullet);//�÷��̾� �Ѿ��� �浹
	bool Moncollide(class Bullet* monbullet);//���� �Ѿ��� �浹

};

