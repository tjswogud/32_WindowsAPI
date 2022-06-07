#include "Framework.h"
#include "Math.h"

double Math::Distance(Vector2 p1, Vector2 p2)
{
    Vector2 distance = p1 - p2;

    return sqrt(pow(distance.x, 2) + pow(distance.y, 2));

}
