#ifndef _lib_os_core_h
#define _lib_os_core_h

constexpr auto core_runtime_stack = 0;
constexpr auto core_runtime_reset = 1;
constexpr auto core_runtime_undefined = 2;
constexpr auto core_runtime_svc = 3;
constexpr auto core_runtime_prefetch_abort = 4;
constexpr auto core_runtime_data_abort = 5;
constexpr auto core_runtime_reserved = 6;
constexpr auto core_runtime_irq = 7;
constexpr auto core_runtime_fiq = 8;

enum class Core_mode
{
	USER = 0x10,
	FIQ = 0x11,
	IRQ = 0x12,
	SVC = 0x13,
	ABORT = 0x17,
	UNDEFINED = 0x1b,
	SYSTEM = 0x1f
};

enum class Core_interrupt
{
	IMPRECISE_ABORT,
	INTERRUPT,
	FAST_INTERRUPT
};

class Core
{
public:
	Core() {}
	~Core() {}

	int index();
	Core_mode mode();

	void interrupt(Core_interrupt interrupt, bool value);

    void interrupt_base(unsigned int value);
    unsigned int interrupt_base();

	template<typename T> void vector(int index, T value);
	unsigned int vector(int index);

    template<typename T> void runtime(int index, T value);
    unsigned int runtime(int index);
	
	template<typename T> void exchange(int index, T value);
	unsigned int exchange(int index);

	template<typename T> void stack_pointer(Core_mode mode, T value);
    void * stack_pointer(Core_mode mode);

	template<typename T> void stack_pointer(T value);
	void * stack_pointer();

	unsigned int private_base();

	unsigned int cpsr();
	unsigned int spsr();

	void wfe();
	void wfi();
	void dsb();
	void isb();
	void dmb();
	void sev();

	void wakeup(int index);
};

extern void * __vector_start;

template<typename T>
void Core::vector(int index, T value)
{
	auto * ptr = (unsigned int *) &__vector_start;
	*(ptr + index) = (unsigned int) value;
}

extern void * __runtime_start;

template<typename T>
void Core::runtime(int index, T value)
{
	auto * ptr = (unsigned int *) &__runtime_start;
	*(ptr + index) = (unsigned int) value;
}

extern void * __exchange_start;

template<typename T>
void Core::exchange(int index, T value)
{
	auto * ptr = (unsigned int *) &__exchange_start;
	*(ptr + index) = (unsigned int) value;
}

extern "C" void c_sp_user_set(unsigned int value);
extern "C" void c_sp_fiq_set(unsigned int value);
extern "C" void c_sp_irq_set(unsigned int value);
extern "C" void c_sp_svc_set(unsigned int value);
extern "C" void c_sp_abort_set(unsigned int value);
extern "C" void c_sp_undefined_set(unsigned int value);
extern "C" void c_sp_system_set(unsigned int value);

template<typename T>
void Core::stack_pointer(Core_mode mode, T value)
{
	switch (mode)
	{
		case Core_mode::USER:
			c_sp_user_set((unsigned int) value);
			break;
		case Core_mode::FIQ:
			c_sp_fiq_set((unsigned int) value);
			break;
		case Core_mode::IRQ:
			c_sp_irq_set((unsigned int) value);
			break;
		case Core_mode::SVC:
			c_sp_svc_set((unsigned int) value);
			break;
		case Core_mode::ABORT:
			c_sp_abort_set((unsigned int) value);
			break;
		case Core_mode::UNDEFINED:
			c_sp_undefined_set((unsigned int) value);
			break;
		case Core_mode::SYSTEM:
			c_sp_system_set((unsigned int) value);
			break;
		default:
			break;
	}
}

extern "C" void c_sp_set(unsigned int value);

template<typename T>
void Core::stack_pointer(T value)
{
	c_sp_set((unsigned int) value);
}

extern Core core;

#endif
