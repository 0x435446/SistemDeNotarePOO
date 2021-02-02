#include "LifeForm.h"

LifeForm::LifeForm(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	const std::list<Physical*>& everyLifeFormObject,
	int healthPoints,
	int baseHpRegen,
	int updateReference) :
	Physical(groupBoundTo, sprite_file, position, everyLifeFormObject, updateReference),
	biologicalComponent(*this, healthPoints, baseHpRegen)
{
	AddComponent<BiologicalComponent<LifeForm>>(&biologicalComponent);
}
LifeForm::LifeForm(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	const std::list<Physical*>& everyLifeFormObject,
	int healthPoints,
	int updateReference) :
	Physical(groupBoundTo, sprite_file, position, everyLifeFormObject, updateReference),
	biologicalComponent(*this, healthPoints)
{
	AddComponent<BiologicalComponent<LifeForm>>(&biologicalComponent);
}



///// S A M E