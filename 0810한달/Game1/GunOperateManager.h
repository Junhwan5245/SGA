#pragma once
class GunOperateManager
{
public:
	
	vector<class Gun*>GunManager;
	GunOperateManager()=default;
	virtual ~GunOperateManager()=default;
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void SwapItem(Gun* gun);
};

