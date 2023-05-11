#include "framework.h"
#include "GameObject.h"


ObLine* GameObject::axis = nullptr;
void GameObject::CreateStaticMember()
{
	axis = new ObLine();
}

void GameObject::DeleteStaticMember()
{
	delete axis;
}

GameObject::GameObject()
{
	pos.x = 0;
	pos.y = 0;

	scale.x = 1.0f;
	scale.y = 1.0f;

	rotation.x = 0.0f;
	rotation.y = 0.0f;
	rotation.z = 0.0f;

	rotation2.x = 0.0f;
	rotation2.y = 0.0f;
	rotation2.z = 0.0f;

	P = nullptr;
	hasAxis = false;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	/*S._11 = scale.x;
	S._22 = scale.y;

	R._11 = cos(rotation * ToRadian);
	R._22 = cos(rotation * ToRadian);
	R._12 = -sin(rotation * ToRadian);
	R._21 = sin(rotation * ToRadian);

	T._41 = pos.x;
	T._42 = pos.y;
	T._43 = 0;*/

	Pi = Matrix::CreateTranslation(pivot.x, pivot.y,0.0f);
	S = Matrix::CreateScale(scale.x, scale.y, 1.0f);
	R = Matrix::CreateFromYawPitchRoll(rotation.y, rotation.x, rotation.z);
	R2 = Matrix::CreateFromYawPitchRoll(rotation2.y, rotation2.x, rotation2.z);
	T= Matrix::CreateTranslation(pos.x,pos.y,0.0f);

	RT = R * T * R2;
	
	//포인터에 주소값이 있다면
	if (P)
	{
		RT *= *P;
	}
	W =Pi * S * RT;
}

void GameObject::Render()
{
	if (hasAxis)
	{
		axis->SetWorldPos(GetWorldPos());
		axis->scale.x = scale.x * 2.0f;
		//         각도   =  단위벡터
		axis->rotation.z = atan2f(GetRight().y, GetRight().x);
		axis->Update();
		axis->Render();

		axis->scale.x = scale.y * 2.0f;
		axis->rotation.z = atan2f(GetUp().y, GetUp().x);
		axis->Update();
		axis->Render();
	}
}

void GameObject::MoveWorldPos(Vector2 Velocity)
{
	if (!P)
	{
		pos += Velocity;
	}
	else
	{
		Vector2 locVelocity = Vector2::TransformNormal(Velocity, (*P).Invert());
		pos += locVelocity;
		
		
	}
}

void GameObject::MoveWorldPos(Vector2 Velocity,Vector2 gravity)
{
	if (!P)
	{
		pos += Velocity;
	}
	else
	{
		Vector2 locVelocity = Vector2::TransformNormal(Velocity, (*P).Invert());
		pos += locVelocity;
		pos += gravity;


	}
}

void GameObject::SetWorldPos(Vector2 worldPos)
{
	if (not P)
	{
		pos = worldPos;
	}
	else
	{
		Vector2 location = Vector2::Transform(worldPos, (*P).Invert());
		pos = location;
	}
}

void GameObject::SetWorldPosX(float worldPosX)
{
	if (!P)
	{
		pos.x = worldPosX;
	}
	else
	{
		Vector2 location = Vector2::Transform(Vector2(worldPosX, 0), (*P).Invert());
		pos.x = location.x;
	}
}

void GameObject::SetWorldPosY(float worldPosY)
{
	if (!P)
	{
		pos.y = worldPosY;
	}
	else
	{
		Vector2 location = Vector2::Transform(Vector2(0, worldPosY), (*P).Invert());
		pos.y = location.y;
	}
}
