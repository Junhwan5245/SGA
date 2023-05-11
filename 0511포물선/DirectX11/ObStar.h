#pragma once
class ObStar : public GameObject
{
private:
	Vector2 vertex[5];

public:
	ObStar();
	virtual void Render() override;
};

