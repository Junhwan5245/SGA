#pragma once
class ObLine : public GameObject
{
private:
	Vector2 vertex[2];

public:
	ObLine();
	virtual void Render() override;
};

