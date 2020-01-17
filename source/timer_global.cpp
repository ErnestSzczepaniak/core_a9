#include "timer_global.h"
#include "core.h"

Timer_global timer_global(core.private_base() + 0x0200);

void Timer_global::enable()
{
	_map->control |= 0x1;
}

void Timer_global::disable()
{
	_map->control &= ~0x1;
}

bool Timer_global::is_enabled()
{
	return (_map->control & 0x1);
}

void Timer_global::comparator_enable()
{
	_map->control |= 0x2;
}

void Timer_global::comparator_disable()
{
	_map->control &= ~0x2;
}

bool Timer_global::is_comparator_enabled()
{
	return (_map->control & 0x2);
}

void Timer_global::irq_enable()
{
	_map->control |= 0x4;
}

void Timer_global::irq_disable()
{
	_map->control &= ~0x4;
}

bool Timer_global::is_irq_enabled()
{
	return (_map->control & 0x4);
}

void Timer_global::increment_mode(Timer_global_increment_mode mode)
{
	if (mode == Timer_global_increment_mode::Single_shot)
	{
		_map->control &= ~0x8;
	}
	else if (mode == Timer_global_increment_mode::Auto_reload)
	{
		_map->control |= 0x8;
	}
}

Timer_global_increment_mode Timer_global::increment_mode()
{
	return (Timer_global_increment_mode)((_map->control >> 3) & 0x1);
}

void Timer_global::prescaler(unsigned int value)
{
	_map->control &= 0xffff00ff;
	_map->control |= value << 8;
}

unsigned int Timer_global::prescaler()
{
	return ((_map->control >> 8) & 0xff);
}

void Timer_global::counter(Timer_global_counter value)
{
	disable();

	_map->counter.lower = value.lower;
	_map->counter.upper = value.upper;

	enable();
}

Timer_global_counter Timer_global::counter()
{
	auto lower = _map->counter.lower;
	auto upper = _map->counter.upper;

	if (upper == _map->counter.upper)
	{
		return {lower, upper};
	}
	else
	{
		return {0, 0};
	}
}

bool Timer_global::event_occured()
{
	return _map->interrupt_status;
}

void Timer_global::event_clear()
{
	_map->interrupt_status = 1;
}

void Timer_global::comparator(Timer_global_comparator value)
{
	comparator_disable();

	_map->comparator.lower = value.lower;
	_map->comparator.upper = value.upper;

	comparator_enable();
}

Timer_global_comparator Timer_global::comparator()
{
	return {_map->comparator.lower, _map->comparator.upper};
}

void Timer_global::auto_increment(unsigned int value)
{
	_map->auto_increment = value;
}

unsigned int Timer_global::auto_increment()
{
	return _map->auto_increment;
}
