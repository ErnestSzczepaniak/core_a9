#include "core.h"

Core core;

extern "C" unsigned int c_cp15_c0_mpidr_get();

int Core::index()
{
	auto mpidr = c_cp15_c0_mpidr_get();

	return (mpidr & 0x3);
}

Core_mode Core::mode()
{
	return ((Core_mode) (cpsr() & 0x1f));
}

extern "C" void c_cpsie_i();
extern "C" void c_cpsid_i();
extern "C" void c_cpsie_f();
extern "C" void c_cpsid_f();
extern "C" void c_cpsie_a();
extern "C" void c_cpsid_a();

void Core::interrupt(Core_interrupt interrupt, bool value)
{
	switch (interrupt)
	{
		case Core_interrupt::INTERRUPT:
			value ? c_cpsie_i() : c_cpsid_i();
			break;
		case Core_interrupt::FAST_INTERRUPT:
			value ? c_cpsie_f() : c_cpsid_f();
			break;
		case Core_interrupt::IMPRECISE_ABORT:
			value ? c_cpsie_a() : c_cpsid_a();
			break;
		default:
			break;
	}
}

extern "C" void c_cp15_c12_vbar_set(unsigned int value);

void Core::interrupt_base(unsigned int value)
{
	c_cp15_c12_vbar_set(value);
}

extern "C" unsigned int c_cp15_c12_vbar_get();

unsigned int Core::interrupt_base()
{
	return c_cp15_c12_vbar_get();
}

unsigned int Core::vector(int index)
{
	auto * ptr = (unsigned int *) &__vector_start;
	return *(ptr + index);
}

unsigned int Core::runtime(int index)
{
	auto * ptr = (unsigned int *) &__runtime_start;
	return *(ptr + index);
}

unsigned int Core::exchange(int index)
{
	auto * ptr = (unsigned int *) &__exchange_start;
	return *(ptr + index);
}

extern "C" unsigned int c_sp_user_get();
extern "C" unsigned int c_sp_fiq_get();
extern "C" unsigned int c_sp_irq_get();
extern "C" unsigned int c_sp_svc_get();
extern "C" unsigned int c_sp_abort_get();
extern "C" unsigned int c_sp_undefined_get();
extern "C" unsigned int c_sp_system_get();

unsigned int Core::stack_pointer(Core_mode mode)
{
	switch (mode)
	{
		case Core_mode::USER:
			return c_sp_user_get();
		case Core_mode::FIQ:
			return c_sp_fiq_get();
		case Core_mode::IRQ:
			return c_sp_irq_get();
		case Core_mode::SVC:
			return c_sp_svc_get();
		case Core_mode::ABORT:
			return c_sp_abort_get();
		case Core_mode::UNDEFINED:
			return c_sp_undefined_get();
		case Core_mode::SYSTEM:
			return c_sp_system_get();
		default:
			return 0;
	}
}

extern "C" unsigned int c_sp_get();

unsigned int Core::stack_pointer()
{
	return c_sp_get();
}

extern "C" unsigned int c_cp15_c15_cbar_get();

unsigned int Core::private_base()
{
	return c_cp15_c15_cbar_get();
}

extern "C" unsigned int c_cpsr_get();

unsigned int Core::cpsr()
{
	return c_cpsr_get();
}

extern "C" unsigned int c_spsr_get();

unsigned int Core::spsr()
{
	return c_spsr_get();
}

extern "C" void c_wfe();

void Core::wfe()
{
	c_wfe();
}

extern "C" void c_wfi();

void Core::wfi()
{
	c_wfi();
}

extern "C" void c_dsb();

void Core::dsb()
{
	c_dsb();
}

extern "C" void c_isb();

void Core::isb()
{
	c_isb();
}

extern "C" void c_dmb();

void Core::dmb()
{
	c_dmb();
}

extern "C" void c_sev();

void Core::sev()
{
	c_sev();
}
