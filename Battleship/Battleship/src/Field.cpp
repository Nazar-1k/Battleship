#include "Field.h"

Field::Field()
	: ship(false), noShip(true)
{
	faield.setSize({ 30,30 });
	faield.setFillColor(sf::Color(72, 61, 139));
}
