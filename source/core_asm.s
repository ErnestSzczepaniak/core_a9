.global c_cp15_c0_tlbtr_get
.global c_cp15_c0_mpidr_get
.global c_cp15_c1_sctlr_get
.global c_cp15_c1_sctlr_set
.global c_cp15_c1_actlr_get
.global c_cp15_c1_actlr_set
.global c_cp15_c5_dfsr_get
.global c_cp15_c5_ifsr_get
.global c_cp15_c5_dfar_get
.global c_cp15_c5_ifar_get
.global c_cp15_c12_vbar_get
.global c_cp15_c12_vbar_set
.global c_cp15_c15_cbar_get
.global c_cp15_c15_cbar_set
.global c_cpsr_get
.global c_spsr_get

.global c_sp_get
.global c_sp_set
.global c_sp_user_get
.global c_sp_user_set
.global c_sp_fiq_get
.global c_sp_fiq_set
.global c_sp_irq_get
.global c_sp_irq_set
.global c_sp_svc_get
.global c_sp_svc_set
.global c_sp_abort_get
.global c_sp_abort_set
.global c_sp_undefined_get
.global c_sp_undefined_set
.global c_sp_system_get
.global c_sp_system_set

.global c_wfe
.global c_wfi
.global c_sev
.global c_svc
.global c_switch
.global c_dsb
.global c_isb
.global c_dmb

.global c_cpsie_i
.global c_cpsid_i
.global c_cpsie_f
.global c_cpsid_f
.global c_cpsie_a
.global c_cpsid_a

.text

c_cp15_c0_tlbtr_get:
	mrc p15,0, r0, c0, c0, 3
	bx lr

c_cp15_c0_mpidr_get:
	mrc p15, 0, r0, c0, c0, 5
	bx lr

c_cp15_c1_sctlr_get:
	mrc p15, 0, r0, c1, c0, 0
	bx lr

c_cp15_c1_sctlr_set:
	mcr p15, 0, r0, c1, c0, 0
	bx lr

c_cp15_c1_actlr_get:
	mrc p15, 0, r0, c1, c0, 1
	bx lr

c_cp15_c1_actlr_set:
	mcr p15, 0, r0, c1, c0, 1
	bx lr

c_cp15_c5_dfsr_get:
	mrc p15, 0, r0, c5, c0, 0
	bx lr

c_cp15_c5_ifsr_get:
	mrc p15, 0, r0, c5, c0, 1

c_cp15_c5_dfar_get:
	mrc p15, 0, r0, c6, c0, 0

c_cp15_c5_ifar_get:
	mrc p15, 0, r0, c6, c0, 2

c_cp15_c12_vbar_get:
	mrc p15, 0, r0, c12, c0, 0
	bx lr

c_cp15_c12_vbar_set:
	mcr p15, 0, r0, c12, c0, 0
	bx lr

c_cp15_c15_cbar_get:
	mrc p15, 4, r0, c15, c0, 0
	bx lr

c_cp15_c15_cbar_set:
	mcr p15, 4, r0, c15, c0, 0
	bx lr

c_cpsr_get:
	mrs r0, cpsr
	bx lr

c_spsr_get:
	mrs r0, spsr
	bx lr

c_sp_get:
	mov r0, sp
	bx lr

c_sp_set:
	mov sp, r0
	bx lr

c_sp_user_get:
	mrs r1, cpsr
	cps #0x1f
	mov r0, sp
	msr cpsr, r1
	bx lr

c_sp_user_set:
	mrs r1, cpsr
	cps #0x1f
	mov sp, r0
	msr cpsr, r1
	bx lr

c_sp_fiq_get:
	mrs r1, cpsr
	cps #0x11
	mov r0, sp
	msr cpsr, r1
	bx lr

c_sp_fiq_set:
	mrs r1, cpsr
	cps #0x11
	mov sp, r0
	msr cpsr, r1
	bx lr

c_sp_irq_get:
	mrs r1, cpsr
	cps #0x12
	mov r0, sp
	msr cpsr, r1
	bx lr

c_sp_irq_set:
	mrs r1, cpsr
	cps #0x12
	mov sp, r0
	msr cpsr, r1
	bx lr

c_sp_svc_get:
	mrs r1, cpsr
	cps #0x13
	mov r0, sp
	msr cpsr, r1
	bx lr

c_sp_svc_set:
	mrs r1, cpsr
	cps #0x13
	mov sp, r0
	msr cpsr, r1
	bx lr

c_sp_abort_get:
	mrs r1, cpsr
	cps #0x17
	mov r0, sp
	msr cpsr, r1
	bx lr

c_sp_abort_set:
	mrs r1, cpsr
	cps #0x17
	mov sp, r0
	msr cpsr, r1
	bx lr

c_sp_undefined_get:
	mrs r1, cpsr
	cps #0x1b
	mov r0, sp
	msr cpsr, r1
	bx lr

c_sp_undefined_set:
	mrs r1, cpsr
	cps #0x1b
	mov sp, r0
	msr cpsr, r1
	bx lr

c_sp_system_get:
	mrs r1, cpsr
	cps #0x1f
	mov r0, sp
	msr cpsr, r1
	bx lr

c_sp_system_set:
	mrs r1, cpsr
	cps #0x1f
	mov sp, r0
	msr cpsr, r1
	bx lr

c_wfe:
	wfe
	bx lr

c_wfi:
	wfi
	bx lr

c_dsb:
	dsb
	bx lr

c_isb:
	isb
	bx lr

c_dmb:
	dmb
	bx lr

c_sev:
	sev
	bx lr

c_svc:
	svc 0
	bx lr

c_cpsie_i:
	cpsie i
	bx lr

c_cpsid_i:
	cpsid i
	bx lr

c_cpsie_f:
	cpsie f
	bx lr

c_cpsid_f:
	cpsid f
	bx lr

c_cpsie_a:
	cpsie a
	bx lr

c_cpsid_a:
	cpsid a
	bx lr
