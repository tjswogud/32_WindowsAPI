#pragma once

class Rect
{
public:
	Rect();
	Rect(Vector2 pos, Vector2 size);
	Rect(double left, double top, double right, double bottom);

	~Rect();

	void Render();

	void SetRect(double left, double top, double right, double bottom);

	double Left()   { return pos.x - size.x / 2; }
	double Right()  { return pos.x + size.x / 2; }
	double Top()    { return pos.y - size.y / 2; }
	double Bottom() { return pos.y + size.y / 2; }

	Vector2& Pos() { return pos; }
	Vector2& Size() { return size; }

private:
	Vector2 pos;
	Vector2 size;
};

