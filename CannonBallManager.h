#pragma once

class CannonBallManager
{
public:
	CannonBallManager(UINT poolCount);
	~CannonBallManager();

	void Update();
	void Render();

	void Fire(Vector2 pos, double angle, double power);


private:
	vector<CannonBall*> cannonBalls;

};

