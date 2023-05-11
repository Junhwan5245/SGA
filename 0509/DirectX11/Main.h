#pragma once
 class Main final : public Scene
{

	 class Bullet* bullet[30];

	 ObStar* star[4];
	 //시계프레임
	 ObCircle* cc;
	 //시침분침초침
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
	void Release()		override;	//해제
	void Update()		override;
	void LateUpdate()	override;	//갱신
	void Render()		override;
	void ResizeScreen() override;

};

