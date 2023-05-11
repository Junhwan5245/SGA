#pragma once

class Input : public Singleton<Input>
{
    //friend class Window;

private:
    unsigned char keyState[256];
    unsigned char keyOldState[256];
    unsigned char keyMap[256];

  
    //Vector2         mouseWorldPos;

    enum 
    {
        KEY_INPUT_STATUS_DOWN,
        KEY_INPUT_STATUS_PRESS,
        KEY_INPUT_STATUS_NONE,
        KEY_INPUT_STATUS_UP,
    };
public:
    Vector2         mouseScreenPos;
public:
    Input();
    ~Input();

    bool KeyDown(int KeyCode); //�������� ����1ȸ
    bool KeyPress(int KeyCode);//������������
    bool KeyUp(int KeyCode); //�����ٰ� �������� ����1ȸ
    void Update();

    //Vector2 GetScreenMousePos() { return mouseScreenPos; }
    //Vector2 GetWorldMousePos() { return mouseWorldPos; }
};
