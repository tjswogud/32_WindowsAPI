// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN  // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define COLOR_BLACK RGB(  0,   0,   0)
#define COLOR_WHITE RGB(255, 255, 255)

#define COLOR_RED   RGB(255, 0,   0)
#define COLOR_GREEN RGB(0, 255,   0)
#define COLOR_BLUE  RGB(0,   0, 255)


//Utility
#include "Math.h"
#include "Vector2.h"

using namespace Math;

//Object
#include "Point.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"

//GameObject
#include "CannonBall.h"
#include "CannonBallManager.h"
#include "Tank.h"



//Scene
#include "Scene.h"
#include "PaintScene.h"
#include "CollisionScene.h"
#include "AngleScene.h"
#include "MainGame.h"

extern HDC hdc;
extern Vector2 mousePos; // 전역에서도 사용가능하게 된다.