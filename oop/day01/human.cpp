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
		if(_health_level > 0 && _health_level < 100)
		{
			_health_level--;
			_spirit -= 0.2;
		}
	}

}
void Human::Walk()
{
	_fatigue--;
	_health_level++; 
}

void Human::Drink(drink _drink)
{
	unsigned int count_coffe = 0;
	if(_drink == Jaguar || _drink == Beer)
	{
		_health_level--;
		_spirit += 3;
	}else if (_drink == Coffee )
	{
		count_coffee++;
		_fatique++;
		if(count_coffee <= 5)
		{
			_health_level++;
		}else 
		{
			_health_level--;	
		}
	}else if(_drink == Tea)
	{
		_health_level++;
	}
}

