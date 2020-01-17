#ifndef _timer_private_h
#define _timer_private_h

struct Map_timer_private
{
	unsigned int load;
	unsigned int counter;
	unsigned int control;
	unsigned int interrupt_status;
};

enum class Timer_private_reload_mode
{
	Single_shot = 0,
	Auto_reload
};

class Timer_private
{
public:
	Timer_private(unsigned int address) : _map((Map_timer_private *) address) {}
	~Timer_private() {}

	void enable();
	void disable();
	bool is_enabled();

	void reload_mode(Timer_private_reload_mode mode);
	Timer_private_reload_mode reload_mode();

	void irq_enable();
	void irq_disable();
	bool is_irq_enabled();

	void prescaler(unsigned int value);
	unsigned int prescaler();

	bool event_occured();
	void event_clear();

	void load(unsigned int value);
	unsigned int load();

	unsigned int counter();

private:
	Map_timer_private * _map;

};

extern Timer_private timer_private;

#endif
