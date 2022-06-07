#include "Framework.h"
#include "CannonBallManager.h"

CannonBallManager::CannonBallManager(UINT poolCount)
{
	for (UINT i = 0; i < poolCount; i++)
	{
		CannonBall* cannonBall = new CannonBall;
		cannonBalls.push_back(cannonBall); // 정보가 없는 객체를 넣어준다 기본 생성자로
	}
}

CannonBallManager::~CannonBallManager()
{
	for (CannonBall* cannonBall : cannonBalls)
		delete cannonBall;

	cannonBalls.clear(); // 벡터를 초기화해서 비워줘야한다.
}

void CannonBallManager::Update()
{
	for (CannonBall* cannonBall : cannonBalls)
		cannonBall->Update();
}

void CannonBallManager::Render()
{
	for (CannonBall* cannonBall : cannonBalls)
		cannonBall->Render();
}

void CannonBallManager::Fire(Vector2 pos, double angle, double power)
{
	for (CannonBall* cannonBall : cannonBalls)
	{
		if (!cannonBall->IsFire())
		{
			cannonBall->Fire(pos, angle, power);
			return;
		}
	}
}
 
// 위에 동적할당하고 초기화하고 등등 하는 방법은 다른데서도 동일하게 이 구조를 가진다