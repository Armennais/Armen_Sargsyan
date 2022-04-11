#include "./human.h"
#include "./date.h"

void Human::Eat(Food _food)
{
	if(_food == Banana || _food == Apple)
	{
		_health_level++;
		_spirit += 0.5;
	}else if(_food == Fagottini || _food == Negrito )
	{
		_health_level--;
		_spirit -= 0.2;
	}

}
void Human::Walk()
{
	_health_level++; 
}

void Human::Drink(drink _drink)
{
	if(_drink == Jaguar || _drink == Beer)
	{
		_health_level--;
		_spirit += 3;
	}else if (_drink == Coffee )
	{
		_health_level--;
	}else if(_drink == Tea)
	{
		_health_level++;
	}
}

