#include "Physical.h"

Physical::Physical(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	const std::list<Physical*>& everyPhysicalObject,
	int updateReference) :
	groupBoundTo(groupBoundTo),
	_type(Physical::Type::LIFEFORM),
	DrawableObject(sprite_file, position),
	collider(*this, everyPhysicalObject, updateReference, false)
{
	AddComponent<Collider<Physical>>(&collider);
}
void Physical::removeSelfFromGroup()
{
	groupBoundTo.remove(this);
}



                                             //// Physical JUST ADDS A NEW FEATURE
											 //// IT DOES NOTHING BY ITSELF      ------ INSTEAD OF MANUALLY ADDING THESE COMPONENTS
																								///    AND /////FUNCTIONS\\\\\\ , JUST CALL IT Physical