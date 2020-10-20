#include "character.h"

#include <cmath>
#include <limits>

Character::Character(
	std::pair<int, int> xy, 
	int health_points, 
	int attack, 
	int defence, 
	const std::string& name) :
		xy_(xy),
		health_points_(health_points),
		attack_(attack),
		defence_(defence),
		name_(name) {}

void Character::Attack(Character& enemy) const
{
	if (Distance(enemy) == 1)
	{
		enemy.SetHealthPoints(enemy.GetHealthPoints() - GetAttack() + enemy.GetDefence());
	}
}

bool Character::IsDead() const
{
	if (GetHealthPoints() <= 0)
	{
		return true;
	}
	return false;
}

float Character::Distance(const Character& character) const
{
	int x1 = GetPosition().first;
	int x2 = character.GetPosition().first;
	int y1 = GetPosition().second;
	int y2 = character.GetPosition().second;

	float d = std::sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return d;
}
