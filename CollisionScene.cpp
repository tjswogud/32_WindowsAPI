#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
	:speed(5)
{
	rect1 = new Rect(100, 100, 200, 200);
	rect2 = new Rect(Vector2(300, 100), Vector2(100, 50));

	circle1 = new Circle(Vector2(300, 300), 50);
	circle2 = new Circle({ 500, 300 }, 50);
	// 위랑 같은식 {} 사용가능
	// circle2 = new Circle({ 500, 300 }, 50);

	line1 = new Line;
	line2 = new Line(Vector2(400, 100), Vector2(100, 400));

	whiteBrush = CreateSolidBrush(COLOR_WHITE);
	redBrush = CreateSolidBrush(COLOR_RED);

	blackPen = CreatePen(PS_SOLID, 5, COLOR_BLACK);
	redPen = CreatePen(PS_SOLID, 5, COLOR_RED);
}

CollisionScene::~CollisionScene()
{
	delete rect1;
	delete rect2;
	delete circle1;
	delete circle2;
	delete line1;
	delete line2;

	DeleteObject(whiteBrush);
	DeleteObject(redBrush);
}

void CollisionScene::Update()
{
	if (GetAsyncKeyState(VK_LEFT))
		rect1->Pos().x -= speed;
	if (GetAsyncKeyState(VK_RIGHT))
		rect1->Pos().x += speed;

	if (GetAsyncKeyState(VK_UP))
		rect1->Pos().y -= speed;
	if (GetAsyncKeyState(VK_DOWN))
		rect1->Pos().y += speed;

	line1->End() = mousePos;
}

void CollisionScene::Render()
{
	rect1->Render();
	rect2->Render();

	circle1->Render();
	circle2->Render();

	// 충돌했다면 빨강색
	if (Collision(line1, line2))
		SelectObject(hdc, redPen);
	else
		// 충돌된게 아니라면 하얀색
		SelectObject(hdc, blackPen);

	line1->Render();
	line2->Render();
}

bool CollisionScene::Collision(Vector2 point, Rect* rect)
{
	if
		(
			point.x > rect->Left() &&
			point.x < rect->Right() &&
			point.y > rect->Top() &&
			point.y < rect->Bottom()
			)
		return true;

	return false;
}

bool CollisionScene::Collision(Rect* rect, Vector2 point)
{
	return Collision(point, rect);
}

bool CollisionScene::Collision(Vector2 point, Circle* circle)
{
	//거리 = x^2 + y^2 = z^2  
	// sqrt(x^2 + y^2) = z;
	// power = 승수, squared = 제곱, square root = 제곱근(1/2승)

	/*double x = mousePos.x - circle->Pos().x;
	double y = mousePos.y - circle->Pos().y;

	double distance = sqrt(pow(x, 2) + pow(y, 2));*/

	double distance = Math::Distance(point, circle->Pos());

	if (distance <= circle->Radius())
		return true;

	return false;
}

bool CollisionScene::Collision(Rect* r1, Rect* r2)
{
	if
		(
			r1->Left() < r2->Right() &&
			r1->Right() > r2->Left() &&
			r1->Top() < r2->Bottom() &&
			r1->Bottom() > r2->Top()
			)
		return true;

	return false;
}

bool CollisionScene::Collision(Circle* c1, Circle* c2)
{
	if (Distance(c1->Pos(), c2->Pos()) < c1->Radius() + c2->Radius())
		return true;

	return false;
}

bool CollisionScene::Collision(Rect* rect, Circle* circle)
{
	if
		(
			(circle->Pos().x > rect->Left() && circle->Pos().x < rect->Right()) ||
			(circle->Pos().y > rect->Top() && circle->Pos().y < rect->Bottom())
			)
	{
		Rect cRect(circle->Pos(), { circle->Radius() * 2 , circle->Radius() * 2 });

		return Collision(&cRect, rect); // 사각형끼리 충돌로 판단하겠다
	}
	else
	{
		Vector2 edges[4];

		edges[0] = { rect->Left(),  rect->Top() };
		edges[1] = { rect->Left(),  rect->Bottom() };
		edges[2] = { rect->Right(), rect->Top() };
		edges[3] = { rect->Right(), rect->Bottom() };

		for (UINT i = 0; i < 4; i++)
		{
			if (Collision(edges[i], circle))
				return true;
		}
	}

	return false;


}

bool CollisionScene::Collision(Line* l1, Line* l2)
{
	Vector2 v1 = l1->End() - l1->Start();
	Vector2 v2 = l2->End() - l2->Start();

	Vector2 temp1 = l2->Start() - l1->Start();
	Vector2 temp2 = l2->End()   - l1->Start();

	Vector2 temp3 = l1->End()   - l2->Start();
	Vector2 temp4 = l1->Start() - l2->Start();

	// return이 bool이기 떄문에
	return v1.IsBetween(temp1, temp2) && v2.IsBetween(temp3, temp4);

	return false;
}
