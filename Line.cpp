#include "Framework.h"
#include "Line.h"

Line::Line()
	:start(0, 0), end(0, 0)
{
}

Line::Line(Vector2 start, Vector2 end)
	: start(start), end(end)
{
}

Line::~Line()
{
}

void Line::Render()
{
	MoveToEx(hdc, start.x, start.y, nullptr);
	LineTo(hdc, end.x, end.y);
}

bool Line::IsBetween(Line* other)
{
	return false;
}
