#include "timer_private.h"
#include "core.h"

Timer_private timer_private(core.private_base() + 0x0600);

void Timer_private::enable()
{
	_map->control |= 0x1;
}

void Timer_private::disable()
{
	_map->control &= ~0x1;
}

bool Timer_private::is_enabled()
{
	return (_map->control & 0x1);
}

void Timer_private::reload_mode(Timer_private_reload_mode mode)
{
	if (mode == Timer_private_reload_mode::Single_shot)
	{
		_map->control &= ~0x2;
	}
	else if (mode == Timer_private_reload_mode::Auto_reload)
	{
		_map->control |= 0x2;
	}
}

Timer_private_reload_mode Timer_private::reload_mode()
{
	return ((Timer_private_reload_mode) (_map->control >> 1));
}

void Timer_private::irq_enable()
{
	_map->control |= 0x4;
}

void Timer_private::irq_disable()
{
	_map->control &= ~0x4;
}

bool Timer_private::is_irq_enabled()
{
	return (_map->control & 0x4);
}

void Timer_private::prescaler(unsigned int value)
{
	_map->control &= 0xffff00ff;
	_map->control |= value << 8;
}

unsigned int Timer_private::prescaler()
{
	return ((_map->control >> 8) & 0xff);
}

void Timer_private::load(unsigned int value)
{
	_map->load = value;
}

unsigned int Timer_private::load()
{
	return _map->load;
}

unsigned int Timer_private::counter()
{
	return _map->counter;
}

bool Timer_private::event_occured()
{
	return _map->interrupt_status;
}

void Timer_private::event_clear()
{
	_map->interrupt_status = 1;
}
