#include "timer_watchdog.h"
#include "core.h"

Timer_watchdog timer_watchdog(core.private_base() + 0x0620);

void Timer_watchdog::enable()
{
	_map->control |= 0x1;
}

void Timer_watchdog::disable()
{
	_map->control &= ~0x1;
}

bool Timer_watchdog::is_enabled()
{
	return (_map->control & 0x1);
}

void Timer_watchdog::reload_mode(Timer_watchdog_reload_mode mode)
{
	if (mode == Timer_watchdog_reload_mode::Single_shot)
	{
		_map->control &= ~0x2;
	}
	else
	{
		_map->control |= 0x2;
	}
}

Timer_watchdog_reload_mode Timer_watchdog::reload_mode()
{
	return ((Timer_watchdog_reload_mode) ((_map->control >> 1) & 0x1));
}

void Timer_watchdog::irq_enable()
{
	_map->control |= 0x4;
}

void Timer_watchdog::irq_disable()
{
	_map->control &= ~0x4;
}

bool Timer_watchdog::is_irq_enabled()
{
	return ((_map->control >> 2) & 0x1);
}

void Timer_watchdog::mode(Timer_watchdog_mode mode)
{
	if (mode == Timer_watchdog_mode::Watchdog)
	{
		_map->control |= 0x8;
	}
	else if (mode == Timer_watchdog_mode::Timer)
	{
		_map->disable = 0x12345678;
		_map->disable = 0x87654321;
	}
}

Timer_watchdog_mode Timer_watchdog::mode()
{
	return (Timer_watchdog_mode)((_map->control >> 8) & 0x1);
}

void Timer_watchdog::prescaler(unsigned int value)
{
	_map->control &= 0xffff00ff;
	_map->control |= value << 8;
}

unsigned int Timer_watchdog::prescaler()
{
	return ((_map->control >> 8) & 0xff);
}

bool Timer_watchdog::event_occured()
{
	return (_map->interrupt_status);
}

void Timer_watchdog::event_clear()
{
	_map->interrupt_status = 1;
}

bool Timer_watchdog::reset_occured()
{
	return _map->reset_status;
}

void Timer_watchdog::reset_clear()
{
	_map->reset_status = 1;
}

void Timer_watchdog::update()
{
	_map->load = _load;
}

void Timer_watchdog::load(unsigned int value)
{
	_map->load = value;
	_load = value;
}

unsigned int Timer_watchdog::load()
{
	return _map->load;
}

unsigned int Timer_watchdog::counter()
{
	return _map->counter;
}
