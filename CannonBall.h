#pragma once

class CannonBall
{
public:
	CannonBall();
	~CannonBall();

	void Update();
	void Render();

	void Fire(Vector2 pos, double angle, double power);

	bool& IsFire() { return isFire; } // 수정이 가능하도록 레퍼런스

private:
	Circle* ball;

	double angle;
	double speed;

	bool isFire;

	double gravity; // 중력
	double power;

};

