#pragma once
 class Main final : public Scene
{

	 class Bullet* bullet[30];

	 ObStar* star[3];
	 //시계프레임
	 ObCircle* cc;
	 //시침분침초침
	 ObLine* line[3];


	 SYSTEMTIME time;

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

