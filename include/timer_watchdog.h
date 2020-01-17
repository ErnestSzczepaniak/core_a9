#ifndef _timer_watchdog_h
#define _timer_watchdog_h

struct Map_timer_watchdog
{
	unsigned int load;
	unsigned int counter;
	unsigned int control;
	unsigned int interrupt_status;
	unsigned int reset_status;
	unsigned int disable;
};

enum class Timer_watchdog_reload_mode
{
	Single_shot = 0,
	Auto_reload
};

enum class Timer_watchdog_mode
{
	Timer = 0,
	Watchdog
};

class Timer_watchdog
{
public:
	Timer_watchdog(unsigned int address) : _map((Map_timer_watchdog *) address) {}
	~Timer_watchdog() {}

	void enable();
	void disable();
	bool is_enabled();

	void reload_mode(Timer_watchdog_reload_mode mode);
	Timer_watchdog_reload_mode reload_mode();

	void irq_enable();
	void irq_disable();
	bool is_irq_enabled();

	void mode(Timer_watchdog_mode mode);
	Timer_watchdog_mode mode();

	void prescaler(unsigned int value);
	unsigned int prescaler();

	bool event_occured();
	void event_clear();

	bool reset_occured();
	void reset_clear();

	void update();

	void load(unsigned int value);
	unsigned int load();

	unsigned int counter();

private:
	Map_timer_watchdog * _map;
	unsigned int _load;

};

extern Timer_watchdog timer_watchdog;

#endif
