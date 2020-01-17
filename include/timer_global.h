#ifndef _timer_global_h
#define _timer_global_h

struct Timer_global_counter
{
	unsigned int lower;
	unsigned int upper;
};

struct Timer_global_comparator
{
	unsigned int lower;
	unsigned int upper;
};

enum class Timer_global_increment_mode
{
	Single_shot = 0,
	Auto_reload
};

struct Map_timer_global
{
	Timer_global_counter counter;
	unsigned int control;
	unsigned int interrupt_status;
	Timer_global_comparator comparator;
	unsigned int auto_increment;
};

class Timer_global
{
public:
	Timer_global(unsigned int address) : _map((Map_timer_global *) address) {}
	~Timer_global() {}

	void enable();
	void disable();
	bool is_enabled();

	void comparator_enable();
	void comparator_disable();
	bool is_comparator_enabled();

	void irq_enable();
	void irq_disable();
	bool is_irq_enabled();

	void increment_mode(Timer_global_increment_mode mode);
	Timer_global_increment_mode increment_mode();

	void prescaler(unsigned int value);
	unsigned int prescaler();

	void counter(Timer_global_counter value);
	Timer_global_counter counter();

	bool event_occured();
	void event_clear();

	void comparator(Timer_global_comparator value);
	Timer_global_comparator comparator();

	void auto_increment(unsigned int value);
	unsigned int auto_increment();

private:
	Map_timer_global * _map;

};

extern Timer_global timer_global;

#endif
