#pragma once
class ObCircle : public GameObject
{
private:
	Vector2 vertex[360];

public:
	ObCircle();
	virtual void Render() override;
};

