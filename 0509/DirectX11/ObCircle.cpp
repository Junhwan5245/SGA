#include "framework.h"
#include "ObCircle.h"

ObCircle::ObCircle()
{
    for (int i = 0; i < 360; i++)
    {
        //            ����         �־��� ����
        vertex[i].x = cos((i)*ToRadian)*0.5f;
        vertex[i].y = sin((i)*ToRadian)*0.5f;
    }
}

void ObCircle::Render()
{
    GameObject::Render();

    Vector2 TransformVertex[360];
    for (int i = 0; i < 360; i++)
    {

        //                      vector * M
        TransformVertex[i] = Vector2::Transform(vertex[i], W);

    }

    MoveToEx(g_hdc, TransformVertex[0].x, TransformVertex[0].y, NULL);
    for (int i = 1; i < 360; i++)
    {
        LineTo(g_hdc, TransformVertex[i].x, TransformVertex[i].y);
    }
    LineTo(g_hdc, TransformVertex[0].x, TransformVertex[0].y);
}
