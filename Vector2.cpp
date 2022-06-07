#include "Framework.h"
#include "Vector2.h"

Vector2::Vector2()
	:x(0), y(0)
{
}

Vector2::Vector2(double x, double y)
	:x(x), y(y)
{
}

double Vector2::Length()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

//Vector2 v = { 5, 5 }
//v.Normalize(); 
void Vector2::Normalize()
{
	// 원본값 바꾸는 작업
	*this /= Length();
	*this /= Length();

	/*this*->x /= Length();
	this*>y\ /= Length();*/
}

//Vector2 v = { 5, 5 }
//Vector2 nV = v.Normal();
Vector2 Vector2::Normal()
{
	// 원본값 변화업음
	return Vector2(*this / Length());

	//return Vector2(this->x / Length(), this->y / Length());
}

double Vector2::Dot(Vector2 other)
{
	return this->x * other.x + this->y * other.y;
}

double Vector2::Cross(Vector2 other)
{
	return this->x * other.y - this->y * other.x;
}

bool Vector2::IsBetween(Vector2 v1, Vector2 v2)
{
	return this->Cross(v1) * this->Cross(v2) < 0;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator*(const double& value) const
{
	return Vector2(this->x * value, this->y * value);
}

Vector2 Vector2::operator/(const double& value) const
{
	return Vector2(this->x / value, this->y / value);

}

void Vector2::operator+=(const Vector2& other)
{
	this->x += other.x;
	this->y += other.y;

}

void Vector2::operator-=(const Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;
}

void Vector2::operator*=(const double& value)
{
	this->x *= value;
	this->y *= value;

}

void Vector2::operator/=(const double& value)
{
	this->x /= value;
	this->y /= value;
}

