#pragma once
 class Main final : public Scene
{

	 class Bullet* bullet[30];

	 ObStar* star[3];
	 //�ð�������
	 ObCircle* cc;
	 //��ħ��ħ��ħ
	 ObLine* line[3];


	 SYSTEMTIME time;

	 float pressPower;

	 int fireidx;

public:
	Main();
	~Main();

	void Init()			override;
	void Release()		override;	//����
	void Update()		override;
	void LateUpdate()	override;	//����
	void Render()		override;
	void ResizeScreen() override;

};

