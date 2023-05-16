#include <windows.h>
#include <string>
#include <chrono>
#include <random>
using namespace std;

#include "../Libs/DirectXTK/SimpleMath.h"
using namespace DirectX;
using namespace SimpleMath;

#include "Types.h"
#include "GameObject.h"
#include "ObStar.h"
#include "ObCircle.h"
#include "ObLine.h"
#include "ObRect.h"
#include "Input.h"
#include "Timer.h"
#include "Random.h"

#define PI XM_PI
#define ToRadian PI/180.0f
#define INPUT Input::GetInstance()
#define TIMER Timer::GetInstance()
#define DELTA Timer::GetInstance()->GetDeltaSacle()
#define RANDOM Random::GetInstance()

#define	UP					Vector2(0.0f,-1.0f)
#define	DOWN				Vector2(0.0f,1.0f)
#define	LEFT				Vector2(-1.0f,0.0f)
#define	RIGHT				Vector2(1.0f, 0.0f)

#define OFFSET_N            Vector2(0.0f, 0.0f)
#define OFFSET_L            Vector2(0.5f, 0.0f)
#define OFFSET_R            Vector2(-0.5f, 0.0f)
#define OFFSET_B            Vector2(0.0f, -0.5f)
#define OFFSET_T            Vector2(0.0f, 0.5f)
#define OFFSET_LB           Vector2(0.5f, -0.5f)
#define OFFSET_RB           Vector2(-0.5f, -0.5f)
#define OFFSET_LT           Vector2(0.5f, 0.5f)
#define OFFSET_RT           Vector2(-0.5f, 0.5f)

extern HINSTANCE			g_hInst;
extern HWND					g_hwnd;
extern class Main*			g_main;
extern HDC					g_hdc;
extern HDC					g_frontHdc;
extern float				deltaScale;