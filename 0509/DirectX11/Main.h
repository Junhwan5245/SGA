#pragma once
 class Main final : public Scene
{

	 class Bullet* bullet[30];

	 ObStar* star[4];
	 //�ð�������
	 ObCircle* cc;
	 //��ħ��ħ��ħ
	 ObCircle* shield[4];
	 ObLine* line[3];
	 ObRect* gauge;
	 ObCircle* computer;

	 SYSTEMTIME systemtime;

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

