#include "Framework.h"
#include "Tank.h"

Tank::Tank()
	: barrelLength(200), angle(0), speed(5),power(5)
{
	body = new Rect({ 200, 500 }, { 200, 100 });
	barrel = new Line(body->Pos(), { body->Pos().x + barrelLength, body->Pos().y });

	//cannonBall = new CannonBall();
	cbManager = new CannonBallManager(30);

	powerBarBack = new Rect(50, 650, 50 + MAX_POWER, 700);
	powerBarFront = new Rect(50, 650, 50, 700);

	blackBrush = CreateSolidBrush(COLOR_BLACK);
	  redBrush = CreateSolidBrush(COLOR_RED);
	  //d
}

Tank::~Tank()
{
	delete body;
	delete barrel;

	//delete cannonBall;
	delete cbManager;

	DeleteObject(blackBrush);
	DeleteObject(redBrush);
}

void Tank::Update()
{
	//회전시키기
	if (GetAsyncKeyState(VK_UP))
		angle += 0.05;
	else if (GetAsyncKeyState(VK_DOWN))
		angle -= 0.05;

	barrel->End().x = body->Pos().x + barrelLength *  cos(angle);
	barrel->End().y = body->Pos().y + barrelLength * -sin(angle);

	// 움직이기
	if (GetAsyncKeyState(VK_LEFT))
		body->Pos().x -= speed;
	else if (GetAsyncKeyState(VK_RIGHT))
		body->Pos().x += speed;

	barrel->Start() = body->Pos();

	//캐논볼 발사
	if (GetAsyncKeyState(VK_SPACE))
	{
		isCharging = true;
		power += 3; // 증가량

		if (power > MAX_POWER)
			power = MAX_POWER;

		powerBarFront->SetRect
		(
			powerBarFront->Left(),
			powerBarFront->Top(),
			powerBarFront->Left() + power,
			powerBarFront->Bottom()
		);
		
	}
	else if (isCharging)
	{
		isCharging = false;

		//cannonBall->IsFire() = true;
		//cannonBall->Fire(barrel->End(), angle, power);

		cbManager->Fire(barrel->End(), angle, power);

		power = 5;
	}

	//cannonBall->Update();
	cbManager->Update();
	
}

void Tank::Render()
{
	  body->Render();
	barrel->Render();

	//cannonBall->Render();
	cbManager->Render();

	SelectObject(hdc, blackBrush);
	powerBarBack->Render();

	SelectObject(hdc, redBrush);
	powerBarFront->Render();
}
