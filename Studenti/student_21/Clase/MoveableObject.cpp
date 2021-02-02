#include "MoveableObject.h"

MoveableObject::MoveableObject(Transform& transform,
    int speed,
    int direction) :
    mover(transform, speed, direction, false)
{
    AddComponent<Mover>(&mover);
}
MoveableObject::MoveableObject(Transform& transform,
    int speed,
    int direction,
    int _is_moving_vertically) :
    mover(transform, speed, direction, _is_moving_vertically, false)
{
    AddComponent<Mover>(&mover);
}




                                               //// MOVEABLE OBJECT JUST ADDS A NEW FEATURE
                                               //// IT DOES NOTHING BY ITSELF      ------ INSTEAD OF MANUALLY ADDING THESE COMPONENTS, JUST CALL IT MOVEABLE