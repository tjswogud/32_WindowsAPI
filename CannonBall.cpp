#include "Framework.h"
#include "CannonBall.h"

CannonBall::CannonBall()
	: angle(0), speed(0), isFire(false), gravity(0)
{
	ball = new Circle({ 0, 0 }, 10);
}

CannonBall::~CannonBall()
{
	delete ball;
}

void CannonBall::Update()
{
	if (!isFire)
		return;

	ball->Pos().x +=  cos(angle) * speed;
	ball->Pos().y += -sin(angle) * speed;

	//gravity += 0.98;
	//ball->Pos().y += gravity + power;

}

void CannonBall::Render()
{

	if (!isFire)
		return;

	ball->Render();
}

void CannonBall::Fire(Vector2 pos, double angle, double power)
{
	ball->Pos()  = pos; // 받아온걸로
	this->angle  = angle;
	this->speed  = power * 0.1;
	this->isFire = true;

	gravity = 0; // 위에 탄을 쏠때마다 누적이되기 떄문에 초기화를 해줘야한다.
}


