#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(double x, double y);

	double Length();

	void Normalize();
	Vector2 Normal();

	double Dot(Vector2 other); // ³»Àû
	double Cross(Vector2 other);

	bool IsBetween(Vector2 v1, Vector2 v2);

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(const double& value) const;
	Vector2 operator/(const double& value) const;

	void operator+=(const Vector2& other);
	void operator-=(const Vector2& other);
	void operator*=(const double& value);
	void operator/=(const double& value);

	double x;
	double y;

};