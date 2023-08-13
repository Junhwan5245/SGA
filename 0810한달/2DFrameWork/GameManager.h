#pragma once
class GameManager: public Singleton<GameManager>
{
	
public:
	class Player* pl;
	class GunOperateManager* GunOpreateManager;
	vector<class Monster*>monster;
	vector<class Boss*>boss;
	/*map<int, class Item*>Item;*/
	vector<class Item*>ItemManager;
	
	
	virtual ~GameManager();
	virtual void Init();	
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void ResizeScreen();
};

