#include "InteractableObject.h"

InteractableObject::InteractableObject(std::list<InteractableObject*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position) :
	DrawableObject(sprite_file, position),
	inputProcesser(*this),
	groupBoundTo(groupBoundTo)
{
	AddComponent<InputProcesser<InteractableObject>>(&inputProcesser);
}



//// InteractableObject JUST ADDS A NEW FEATURE
//// IT DOES NOTHING BY ITSELF      ------ INSTEAD OF MANUALLY ADDING THESE COMPONENTS, JUST CALL IT InteractableObject