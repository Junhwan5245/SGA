#pragma once
class ObRect : public GameObject
{
private:
	Vector2 vertex[4];

public:
	ObRect();
	virtual void Render() override;
};

