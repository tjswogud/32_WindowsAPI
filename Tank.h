#pragma once

#define MAX_POWER 650

class Tank
{
public:
	Tank();
	~Tank();

	void Update();
	void Render();

private:
	Rect* body; // 몸통
	Line* barrel; // 포신

	double barrelLength;
	double angle; // 세타 / 각도
	double speed;

	//CannonBall* cannonBall;
	CannonBallManager* cbManager;

	bool isCharging;
	double power;
	
	Rect* powerBarFront;
	Rect* powerBarBack;

	HBRUSH blackBrush;
	HBRUSH   redBrush;


};
