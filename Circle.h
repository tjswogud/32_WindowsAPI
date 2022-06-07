#pragma once

class Circle
{
public:
	Circle();
	Circle(Vector2 pos, double radius); // 생성자 오버로딩
	~Circle();

	void Render();

	double Left()   { return pos.x - radius; }
	double Right()  { return pos.x + radius; }
	double Top()    { return pos.y - radius; }
	double Bottom() { return pos.y + radius; }

	Vector2& Pos() { return pos; }
	double& Radius() { return radius; }
	

private:
	Vector2 pos;
	double radius;
};
