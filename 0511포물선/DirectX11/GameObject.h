#pragma once
class GameObject
{
private:
	static class ObLine* axis;
public:
	static void CreateStaticMember();
	static void DeleteStaticMember();

protected:
	Matrix Pi, S, R, T, R2, RT, W;
	Matrix* P;
	Vector2	pos;
public:
	Vector2	scale;

	//자전
	Vector3	rotation;
	//공전
	Vector3	rotation2;
	bool	hasAxis;

	Vector2 pivot;

public:
	GameObject();
	virtual ~GameObject();
	virtual void Update();
	virtual void Render();

	void	SetParentRT(GameObject& src) { P = &src.RT; }
	Vector2 GetRight() { return Vector2(RT._11, RT._12); }
	Vector2 GetUp() { return Vector2(RT._21, RT._22); }
	Vector2 GetWorldPos() { return Vector2(RT._41, RT._42); }
	Vector2 GetLocalPos() { return pos; }

	void	MoveLocalPos(Vector2 Velocity) { pos += Velocity; }
	void	MoveWorldPos(Vector2 Velocity);
	void	MoveWorldPos(Vector2 Velocity,Vector2 gravity);


	void	SetLocalPos(Vector2 location) { pos = location; }
	void	SetLocalPosX(float lcationX) { pos.x = lcationX; }
	void	SetLocalPosY(float lcationY) { pos.y = lcationY; }
	void	SetWorldPos(Vector2 worldPos);
	void	SetWorldPosX(float worldPosX);
	void	SetWorldPosY(float worldPosY);
};

