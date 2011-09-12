#ifndef _MACH_I386_THREAD_STATUS_H_
#define _MACH_I386_THREAD_STATUS_H_

#include <mach/message.h>

#define i386_THREAD_STATE    1
#define i386_FLOAT_STATE     2
#define i386_EXCEPTION_STATE 3

#define x86_THREAD_STATE32		1
#define x86_FLOAT_STATE32		2
#define x86_EXCEPTION_STATE32		3
#define x86_THREAD_STATE64		4
#define x86_FLOAT_STATE64		5
#define x86_EXCEPTION_STATE64		6
#define x86_THREAD_STATE		7
#define x86_FLOAT_STATE			8
#define x86_EXCEPTION_STATE		9
#define x86_DEBUG_STATE32		10
#define x86_DEBUG_STATE64		11
#define x86_DEBUG_STATE			12

struct x86_state_hdr {
	int	flavor;
	int	count;
};

typedef struct x86_state_hdr x86_state_hdr_t;

#define _STRUCT_FP_CONTROL struct __darwin_fp_control
_STRUCT_FP_CONTROL
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
						:2,
				__pc		:2,
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define FP_PREC_24B		0
#define	FP_PREC_53B		2
#define FP_PREC_64B		3
#endif /* !_POSIX_C_SOURCE || _DARWIN_C_SOURCE */
				__rc		:2,
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define FP_RND_NEAR		0
#define FP_RND_DOWN		1
#define FP_RND_UP		2
#define FP_CHOP			3
#endif /* !_POSIX_C_SOURCE || _DARWIN_C_SOURCE */
					/*inf*/	:1,
						:3;
};

#define _STRUCT_FP_STATUS	struct __darwin_fp_status
_STRUCT_FP_STATUS
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
				__stkflt	:1,
				__errsumm	:1,
				__c0		:1,
				__c1		:1,
				__c2		:1,
				__tos		:3,
				__c3		:1,
				__busy		:1;
};

#define _STRUCT_MMST_REG	struct __darwin_mmst_reg
_STRUCT_MMST_REG
{
	char	__mmst_reg[10];
	char	__mmst_rsrv[6];
};

#define _STRUCT_XMM_REG		struct __darwin_xmm_reg
_STRUCT_XMM_REG
{
	char		__xmm_reg[16];
};

#define	_STRUCT_X86_THREAD_STATE32	struct __darwin_i386_thread_state
typedef _STRUCT_X86_THREAD_STATE32 i386_thread_state_t;
typedef _STRUCT_X86_THREAD_STATE32 x86_thread_state32_t;
_STRUCT_X86_THREAD_STATE32 {
    unsigned int	__eax;
    unsigned int	__ebx;
    unsigned int	__ecx;
    unsigned int	__edx;
    unsigned int	__edi;
    unsigned int	__esi;
    unsigned int	__ebp;
    unsigned int	__esp;
    unsigned int	__ss;
    unsigned int	__eflags;
    unsigned int	__eip;
    unsigned int	__cs;
    unsigned int	__ds;
    unsigned int	__es;
    unsigned int	__fs;
    unsigned int	__gs;
};

#define	_STRUCT_X86_EXCEPTION_STATE32	struct __darwin_i386_exception_state
typedef _STRUCT_X86_EXCEPTION_STATE32 i386_exception_state_t;
typedef _STRUCT_X86_EXCEPTION_STATE32 x86_exception_state32_t;
_STRUCT_X86_EXCEPTION_STATE32 {
	__uint16_t	__trapno;
	__uint16_t	__cpu;
	__uint32_t	__err;
	__uint32_t	__faultvaddr;
};

#define	_STRUCT_X86_FLOAT_STATE32	struct __darwin_i386_float_state
typedef _STRUCT_X86_FLOAT_STATE32 i386_float_state_t;
typedef _STRUCT_X86_FLOAT_STATE32 x86_float_state32_t;
_STRUCT_X86_FLOAT_STATE32 {
	int 			__fpu_reserved[2];
	_STRUCT_FP_CONTROL	__fpu_fcw;		/* x87 FPU control word */
	_STRUCT_FP_STATUS	__fpu_fsw;		/* x87 FPU status word */
	__uint8_t		__fpu_ftw;		/* x87 FPU tag word */
	__uint8_t		__fpu_rsrv1;		/* reserved */ 
	__uint16_t		__fpu_fop;		/* x87 FPU Opcode */
	__uint32_t		__fpu_ip;		/* x87 FPU Instruction Pointer offset */
	__uint16_t		__fpu_cs;		/* x87 FPU Instruction Pointer Selector */
	__uint16_t		__fpu_rsrv2;		/* reserved */
	__uint32_t		__fpu_dp;		/* x87 FPU Instruction Operand(Data) Pointer offset */
	__uint16_t		__fpu_ds;		/* x87 FPU Instruction Operand(Data) Pointer Selector */
	__uint16_t		__fpu_rsrv3;		/* reserved */
	__uint32_t		__fpu_mxcsr;		/* MXCSR Register state */
	__uint32_t		__fpu_mxcsrmask;	/* MXCSR mask */
	_STRUCT_MMST_REG	__fpu_stmm0;		/* ST0/MM0   */
	_STRUCT_MMST_REG	__fpu_stmm1;		/* ST1/MM1  */
	_STRUCT_MMST_REG	__fpu_stmm2;		/* ST2/MM2  */
	_STRUCT_MMST_REG	__fpu_stmm3;		/* ST3/MM3  */
	_STRUCT_MMST_REG	__fpu_stmm4;		/* ST4/MM4  */
	_STRUCT_MMST_REG	__fpu_stmm5;		/* ST5/MM5  */
	_STRUCT_MMST_REG	__fpu_stmm6;		/* ST6/MM6  */
	_STRUCT_MMST_REG	__fpu_stmm7;		/* ST7/MM7  */
	_STRUCT_XMM_REG		__fpu_xmm0;		/* XMM 0  */
	_STRUCT_XMM_REG		__fpu_xmm1;		/* XMM 1  */
	_STRUCT_XMM_REG		__fpu_xmm2;		/* XMM 2  */
	_STRUCT_XMM_REG		__fpu_xmm3;		/* XMM 3  */
	_STRUCT_XMM_REG		__fpu_xmm4;		/* XMM 4  */
	_STRUCT_XMM_REG		__fpu_xmm5;		/* XMM 5  */
	_STRUCT_XMM_REG		__fpu_xmm6;		/* XMM 6  */
	_STRUCT_XMM_REG		__fpu_xmm7;		/* XMM 7  */
	char			__fpu_rsrv4[14*16];	/* reserved */
	int 			__fpu_reserved1;
};

#define	_STRUCT_X86_THREAD_STATE64	struct __darwin_x86_thread_state64
typedef _STRUCT_X86_THREAD_STATE64 x86_thread_state64_t;
_STRUCT_X86_THREAD_STATE64
{
	__uint64_t	__rax;
	__uint64_t	__rbx;
	__uint64_t	__rcx;
	__uint64_t	__rdx;
	__uint64_t	__rdi;
	__uint64_t	__rsi;
	__uint64_t	__rbp;
	__uint64_t	__rsp;
	__uint64_t	__r8;
	__uint64_t	__r9;
	__uint64_t	__r10;
	__uint64_t	__r11;
	__uint64_t	__r12;
	__uint64_t	__r13;
	__uint64_t	__r14;
	__uint64_t	__r15;
	__uint64_t	__rip;
	__uint64_t	__rflags;
	__uint64_t	__cs;
	__uint64_t	__fs;
	__uint64_t	__gs;
};

#define	_STRUCT_X86_FLOAT_STATE64	struct __darwin_x86_float_state64
typedef _STRUCT_X86_FLOAT_STATE64 x86_float_state64_t;
_STRUCT_X86_FLOAT_STATE64
{
	int 			__fpu_reserved[2];
	_STRUCT_FP_CONTROL	__fpu_fcw;		/* x87 FPU control word */
	_STRUCT_FP_STATUS	__fpu_fsw;		/* x87 FPU status word */
	__uint8_t		__fpu_ftw;		/* x87 FPU tag word */
	__uint8_t		__fpu_rsrv1;		/* reserved */ 
	__uint16_t		__fpu_fop;		/* x87 FPU Opcode */

	/* x87 FPU Instruction Pointer */
	__uint32_t		__fpu_ip;		/* offset */
	__uint16_t		__fpu_cs;		/* Selector */

	__uint16_t		__fpu_rsrv2;		/* reserved */

	/* x87 FPU Instruction Operand(Data) Pointer */
	__uint32_t		__fpu_dp;		/* offset */
	__uint16_t		__fpu_ds;		/* Selector */

	__uint16_t		__fpu_rsrv3;		/* reserved */
	__uint32_t		__fpu_mxcsr;		/* MXCSR Register state */
	__uint32_t		__fpu_mxcsrmask;	/* MXCSR mask */
	_STRUCT_MMST_REG	__fpu_stmm0;		/* ST0/MM0   */
	_STRUCT_MMST_REG	__fpu_stmm1;		/* ST1/MM1  */
	_STRUCT_MMST_REG	__fpu_stmm2;		/* ST2/MM2  */
	_STRUCT_MMST_REG	__fpu_stmm3;		/* ST3/MM3  */
	_STRUCT_MMST_REG	__fpu_stmm4;		/* ST4/MM4  */
	_STRUCT_MMST_REG	__fpu_stmm5;		/* ST5/MM5  */
	_STRUCT_MMST_REG	__fpu_stmm6;		/* ST6/MM6  */
	_STRUCT_MMST_REG	__fpu_stmm7;		/* ST7/MM7  */
	_STRUCT_XMM_REG		__fpu_xmm0;		/* XMM 0  */
	_STRUCT_XMM_REG		__fpu_xmm1;		/* XMM 1  */
	_STRUCT_XMM_REG		__fpu_xmm2;		/* XMM 2  */
	_STRUCT_XMM_REG		__fpu_xmm3;		/* XMM 3  */
	_STRUCT_XMM_REG		__fpu_xmm4;		/* XMM 4  */
	_STRUCT_XMM_REG		__fpu_xmm5;		/* XMM 5  */
	_STRUCT_XMM_REG		__fpu_xmm6;		/* XMM 6  */
	_STRUCT_XMM_REG		__fpu_xmm7;		/* XMM 7  */
	_STRUCT_XMM_REG		__fpu_xmm8;		/* XMM 8  */
	_STRUCT_XMM_REG		__fpu_xmm9;		/* XMM 9  */
	_STRUCT_XMM_REG		__fpu_xmm10;		/* XMM 10  */
	_STRUCT_XMM_REG		__fpu_xmm11;		/* XMM 11 */
	_STRUCT_XMM_REG		__fpu_xmm12;		/* XMM 12  */
	_STRUCT_XMM_REG		__fpu_xmm13;		/* XMM 13  */
	_STRUCT_XMM_REG		__fpu_xmm14;		/* XMM 14  */
	_STRUCT_XMM_REG		__fpu_xmm15;		/* XMM 15  */
	char			__fpu_rsrv4[6*16];	/* reserved */
	int 			__fpu_reserved1;
};

#define _STRUCT_X86_EXCEPTION_STATE64 struct __darwin_x86_exception_state64
typedef _STRUCT_X86_EXCEPTION_STATE64 x86_exception_state64_t;
_STRUCT_X86_EXCEPTION_STATE64
{
    __uint16_t	__trapno;
    __uint16_t	__cpu;
    __uint32_t	__err;
    __uint64_t	__faultvaddr;
};

#define _STRUCT_X86_DEBUG_STATE32 struct __darwin_x86_debug_state32
typedef _STRUCT_X86_DEBUG_STATE32 x86_debug_state32_t;
_STRUCT_X86_DEBUG_STATE32
{
	unsigned int	__dr0;
	unsigned int	__dr1;
	unsigned int	__dr2;
	unsigned int	__dr3;
	unsigned int	__dr4;
	unsigned int	__dr5;
	unsigned int	__dr6;
	unsigned int	__dr7;
};

#define _STRUCT_X86_DEBUG_STATE64	struct __darwin_x86_debug_state64
typedef _STRUCT_X86_DEBUG_STATE64 x86_debug_state64_t;
_STRUCT_X86_DEBUG_STATE64
{
	__uint64_t	__dr0;
	__uint64_t	__dr1;
	__uint64_t	__dr2;
	__uint64_t	__dr3;
	__uint64_t	__dr4;
	__uint64_t	__dr5;
	__uint64_t	__dr6;
	__uint64_t	__dr7;
};

#define i386_THREAD_STATE_COUNT	((mach_msg_type_number_t)( \
	sizeof (i386_thread_state_t) / sizeof (int) \
))
#define i386_EXCEPTION_STATE_COUNT ((mach_msg_type_number_t)( \
	sizeof (i386_exception_state_t) / sizeof (int) \
))
#define i386_FLOAT_STATE_COUNT ((mach_msg_type_number_t)( \
	sizeof(i386_float_state_t) / sizeof(int) \
))
#define x86_THREAD_STATE32_COUNT	((mach_msg_type_number_t)( \
	sizeof (x86_thread_state32_t) / sizeof (int) \
))
#define x86_THREAD_STATE64_COUNT ((mach_msg_type_number_t)( \
	sizeof (x86_thread_state64_t) / sizeof (int) \
))
#define x86_FLOAT_STATE32_COUNT ((mach_msg_type_number_t)( \
	sizeof(x86_float_state32_t)/sizeof(unsigned int) \
))
#define x86_FLOAT_STATE64_COUNT ((mach_msg_type_number_t)( \
	sizeof(x86_float_state64_t)/sizeof(unsigned int) \
))
#define x86_EXCEPTION_STATE32_COUNT	((mach_msg_type_number_t)( \
	sizeof (x86_exception_state32_t) / sizeof (int) \
))
#define x86_EXCEPTION_STATE64_COUNT	((mach_msg_type_number_t)( \
	sizeof (x86_exception_state64_t) / sizeof (int) \
))
#define x86_DEBUG_STATE32_COUNT ((mach_msg_type_number_t)( \
	sizeof (x86_debug_state32_t) / sizeof (int) \
))
#define x86_DEBUG_STATE64_COUNT	((mach_msg_type_number_t)( \
	sizeof (x86_debug_state64_t) / sizeof (int) \
))

#define I386_EXCEPTION_STATE_COUNT i386_EXCEPTION_STATE_COUNT

struct x86_thread_state {
	x86_state_hdr_t			tsh;
	union {
	    x86_thread_state32_t	ts32;
	    x86_thread_state64_t	ts64;
	} uts;
};

struct x86_float_state {
	x86_state_hdr_t			fsh;
	union {
		x86_float_state32_t	fs32;
		x86_float_state64_t	fs64;
	} ufs;
};

struct x86_exception_state {
	x86_state_hdr_t			esh;
	union {
		x86_exception_state32_t	es32;
		x86_exception_state64_t	es64;
	} ues;
};

struct x86_debug_state {
	x86_state_hdr_t			dsh;
	union {
		x86_debug_state32_t	ds32;
		x86_debug_state64_t	ds64;
	} uds;
};

typedef struct x86_thread_state x86_thread_state_t;
#define x86_THREAD_STATE_COUNT	((mach_msg_type_number_t) \
		( sizeof (x86_thread_state_t) / sizeof (int) ))

typedef struct x86_float_state x86_float_state_t;
#define x86_FLOAT_STATE_COUNT ((mach_msg_type_number_t) \
		(sizeof(x86_float_state_t)/sizeof(unsigned int)))

typedef struct x86_exception_state x86_exception_state_t;
#define x86_EXCEPTION_STATE_COUNT ((mach_msg_type_number_t) \
		(sizeof(x86_exception_state_t)/sizeof(unsigned int)))

typedef struct x86_debug_state x86_debug_state_t;
#define x86_DEBUG_STATE_COUNT ((mach_msg_type_number_t) \
		(sizeof(x86_debug_state_t)/sizeof(unsigned int)))

#endif
