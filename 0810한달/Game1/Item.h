#pragma once

class Item
{
protected:
    

public:
    ObImage* ItemImg;
    ObRect* col;
    int ItemNum;
    bool isUsed;
    Item();
    //Item(const Item& other); // ���� ���縦 ���� ���� ������
    virtual ~Item();
    virtual void Init();
    virtual void Update();
    virtual void Render();
    virtual void ApplyItem();
};


