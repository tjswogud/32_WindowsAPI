#pragma once

class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	// 점과 사각형의 충돌
	bool Collision(Vector2 point, Rect* rect);
	bool Collision(Rect* rect, Vector2 point);

	// 점과 원의 충돌
	bool Collision(Vector2 point, Circle* circle1);

	// 사각형과 사각형의 충돌
	bool Collision(Rect* r1, Rect* r2);

	// 원과 원의 충돌
	bool Collision(Circle* c1, Circle* c2);

	// 원과 사각형의 충돌
	bool Collision(Rect* rect, Circle* circle);

	// 선과 선의 충돌
	bool Collision(Line* l1, Line* l2);

private:
	Rect* rect1;
	Rect* rect2;
	
	Circle* circle1;
	Circle* circle2;

	Line* line1;
	Line* line2;

	HBRUSH whiteBrush;
	HBRUSH   redBrush;

	HPEN blackPen;
	HPEN   redPen;

	double speed;
};

