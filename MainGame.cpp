#include "Framework.h"
#include "MainGame.h"

/*
해상도:

HD : 1280 * 720

FHD : 1920 * 1080

QHD : 2560 * 1440

FPS == FrameRete(Frame Per Second) : 초당 프레임 수

Frame : 쉽게 생각해서 한 화면, 예를 들어서 60fps면, 1초에 60번의 화면이 갱신된다

주사율 : 모니터의 개념, 이 모니터가 표현할 수 있는 최대 프레임

Vsyne(수직동기화) : 모니터의 주사율에 맞춰서 프레임의 상한치를 제한해두는 기술

결론 : FPS가 올라갈수록 게임 성능이 올라간다.

*/

MainGame::MainGame()
{
	//scene = new PaintScene;
	//scene = new CollisionScene;
	scene = new AngleScene;

}

MainGame::~MainGame()
{
	delete scene;
}

void MainGame::Update()
{
	scene->Update();
}

void MainGame::Render()
{
	scene->Render();
}
