#pragma once
//����Ÿ�� ��ǥ
struct Int2
{
	int x;
	int y;
	Int2() : x(0) , y(0){}
	Int2(int x, int y) : x(x), y(y) {}
};



template <typename T>
class Singleton
{
	//static
private:
	static T* instance;

public:
	static T* GetInstance()
	{
		if (!instance)
			instance = new T;

		return instance;
	};

	//member
public:
	virtual ~Singleton() {};
	void DeleteSingleton()
	{
		delete instance;
		instance = nullptr;
	};
};

template <typename T>
T* Singleton<T>::instance = nullptr;

class Scene
{
public:
	//����Ҹ��� (��ĳ�������� ��ü ����ҋ� �Ҹ��ڵ� �����Լ��� ��������)
	virtual ~Scene() {};
	//�ʱ�ȭ
	virtual void Init() = 0;
	//����
	virtual void Release() = 0;
	//Loop
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;
	//Window Resize
	virtual void ResizeScreen() = 0;
};