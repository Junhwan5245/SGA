#pragma once


 class Main final : public Scene
{
	 class Player* pl[2];
	 int turn;
	 int damage = 0;
	 float damageTime = 0.0f;
	 int releasebullet;
public:
	Main();
	~Main();

	void Init()			override;
	void Release()		override;	//해제
	void Update()		override;
	void LateUpdate()	override;	//갱신
	void Render()		override;
	void ResizeScreen() override;

};

