#pragma once

class Point
{
public:
	Point()
		:x(0), y(0)
	{
	}

	Point(double x, double y)
		:x(x), y(y)
	{
	}

	// 레퍼런스를 쓰지만 본래의 값을 바꾸려고 하는게 아니고 접근만 하기위해 사용
	// 그래서 const를 사용해서 막아준다.
	Point operator+(const Point point) const
	{
		return Point(this->x + point.x, this->y + point.y);
	}

	Point operator-(const Point point) const
	{
		return Point(this->x - point.x, this->y - point.y);
	}

	double x;
	double y;
};

