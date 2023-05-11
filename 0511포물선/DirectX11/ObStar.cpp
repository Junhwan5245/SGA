#include "framework.h"
#include "ObStar.h"

ObStar::ObStar()
{
    for (int i = 0; i < 5; i++)
    {
        //            중점         멀어진 길이
        vertex[i].x = cos((72.0f * i) * ToRadian)*0.5f;
        vertex[i].y = sin((72.0f * i) * ToRadian)*0.5f;
    }
}

void ObStar::Render()
{
    GameObject::Render();
    Vector2 TransformVertex[5];
    for (int i = 0; i < 5; i++)
    {

        //                      vector * M
        TransformVertex[i] = Vector2::Transform(vertex[i], W);

    }

    MoveToEx(g_hdc, TransformVertex[0].x, TransformVertex[0].y, NULL);
    LineTo(g_hdc, TransformVertex[2].x, TransformVertex[2].y);
    LineTo(g_hdc, TransformVertex[4].x, TransformVertex[4].y);
    LineTo(g_hdc, TransformVertex[1].x, TransformVertex[1].y);
    LineTo(g_hdc, TransformVertex[3].x, TransformVertex[3].y);
    LineTo(g_hdc, TransformVertex[0].x, TransformVertex[0].y);
}
