#include "Framework.h"
#include "Rect.h"

Rect::Rect()
	: pos(0, 0), size(0, 0)
{
}

Rect::Rect(Vector2 pos, Vector2 size)
	: pos(pos), size(size)
{
}

Rect::Rect(double left, double top, double right, double bottom)
{
	pos.x = (left + right) / 2;
	pos.y = (top + bottom) / 2;

	size.x = abs(right - left);
	size.y = abs(bottom - top);

}

Rect::~Rect()
{
}

void Rect::Render()
{
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}

void Rect::SetRect(double left, double top, double right, double bottom)
{
	pos.x = (left + right) / 2;
	pos.y = (top + bottom) / 2;

	size.x = abs(right - left);
	size.y = abs(bottom - top);
}
