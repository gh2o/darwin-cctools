#ifndef _LIBKERN_OSBYTEORDER_H_
#define _LIBKERN_OSBYTEORDER_H_

#include <config.h>
#include <mach/mach_types.h>

#define __DARWIN_OSSwapConstInt16(x) \
  ((__uint16_t)((((__uint16_t)(x) & 0xff00) >> 8) | \
        (((__uint16_t)(x) & 0x00ff) << 8)))

#define __DARWIN_OSSwapConstInt32(x) \
  ((__uint32_t)((((__uint32_t)(x) & 0xff000000) >> 24) | \
        (((__uint32_t)(x) & 0x00ff0000) >> 8) | \
        (((__uint32_t)(x) & 0x0000ff00) << 8) | \
        (((__uint32_t)(x) & 0x000000ff) << 24)))

#define __DARWIN_OSSwapConstInt64(x) \
  ((__uint64_t)((((__uint64_t)(x) & 0xff00000000000000ULL) >> 56) | \
        (((__uint64_t)(x) & 0x00ff000000000000ULL) >> 40) | \
        (((__uint64_t)(x) & 0x0000ff0000000000ULL) >> 24) | \
        (((__uint64_t)(x) & 0x000000ff00000000ULL) >> 8) | \
        (((__uint64_t)(x) & 0x00000000ff000000ULL) << 8) | \
        (((__uint64_t)(x) & 0x0000000000ff0000ULL) << 24) | \
        (((__uint64_t)(x) & 0x000000000000ff00ULL) << 40) | \
        (((__uint64_t)(x) & 0x00000000000000ffULL) << 56)))

#define OSSwapConstInt16(x)	__DARWIN_OSSwapConstInt16(x)
#define OSSwapConstInt32(x)	__DARWIN_OSSwapConstInt32(x)
#define OSSwapConstInt64(x)	__DARWIN_OSSwapConstInt64(x)

#define OSSwapInt16(x) _OSSwapInt16(x)
#define OSSwapInt32(x) _OSSwapInt32(x)
#define OSSwapInt64(x) _OSSwapInt64(x)

static inline uint16_t _OSReadInt16 (
	const volatile void * base,
	uintptr_t byteOffset
)
{
	return *(volatile uint16_t *)((uintptr_t)base + byteOffset);
}

static inline uint32_t _OSReadInt32 (
	const volatile void * base,
	uintptr_t byteOffset
)
{
	return *(volatile uint32_t *)((uintptr_t)base + byteOffset);
}

static inline uint64_t _OSReadInt64 (
	const volatile void * base,
	uintptr_t byteOffset
)
{
	return *(volatile uint64_t *)((uintptr_t)base + byteOffset);
}

static inline void _OSWriteInt16 (
	volatile void * base,
	uintptr_t byteOffset,
	uint16_t data
)
{
	*(volatile uint16_t *)((uintptr_t)base + byteOffset) = data;
}

static inline void _OSWriteInt32 (
	volatile void * base,
	uintptr_t byteOffset,
	uint32_t data
)
{
	*(volatile uint32_t *)((uintptr_t)base + byteOffset) = data;
}

static inline void _OSWriteInt64 (
	volatile void * base,
	uintptr_t byteOffset,
	uint64_t data
)
{
	*(volatile uint64_t *)((uintptr_t)base + byteOffset) = data;
}

static inline uint16_t _OSSwapInt16 (uint16_t data)
{
	return OSSwapConstInt16(data);
}

static inline uint32_t _OSSwapInt32 (uint32_t data )
{
	return OSSwapConstInt32(data);
}

static inline uint64_t _OSSwapInt64 (uint64_t data)
{
	return OSSwapConstInt64(data);
}

static inline uint16_t OSReadSwapInt16 (
	const volatile void * base,
	uintptr_t byteOffset
)
{
	uint16_t data = *(volatile uint16_t *)((uintptr_t)base + byteOffset);
	return _OSSwapInt16(data);
}

static inline uint32_t OSReadSwapInt32 (
	const volatile void * base,
	uintptr_t byteOffset
)
{
	uint32_t data = *(volatile uint32_t *)((uintptr_t)base + byteOffset);
	return _OSSwapInt32(data);
}

static inline uint64_t OSReadSwapInt64 (
	const volatile void * base,
	uintptr_t byteOffset
)
{
	uint64_t data = *(volatile uint64_t *)((uintptr_t)base + byteOffset);
	return _OSSwapInt64(data);
}

static inline void OSWriteSwapInt16 (
	volatile void * base,
	uintptr_t byteOffset,
	uint16_t data
)
{
	*(volatile uint16_t *)((uintptr_t)base + byteOffset) = _OSSwapInt16(data);
}

static inline void OSWriteSwapInt32 (
	volatile void * base,
	uintptr_t byteOffset,
	uint32_t data
)
{
	*(volatile uint32_t *)((uintptr_t)base + byteOffset) = _OSSwapInt32(data);
}

static inline void OSWriteSwapInt64 (
	volatile void * base,
	uintptr_t byteOffset,
	uint64_t data
)
{
	*(volatile uint64_t *)((uintptr_t)base + byteOffset) = _OSSwapInt64(data);
}

#if defined(__BIG_ENDIAN__)

/* Functions for loading big endian to host endianess. */

#define OSReadBigInt16(base, byteOffset) _OSReadInt16(base, byteOffset)
#define OSReadBigInt32(base, byteOffset) _OSReadInt32(base, byteOffset)
#define OSReadBigInt64(base, byteOffset) _OSReadInt64(base, byteOffset)

/* Functions for storing host endianess to big endian. */

#define OSWriteBigInt16(base, byteOffset, data) _OSWriteInt16(base, byteOffset, data)
#define OSWriteBigInt32(base, byteOffset, data) _OSWriteInt32(base, byteOffset, data)
#define OSWriteBigInt64(base, byteOffset, data) _OSWriteInt64(base, byteOffset, data)

/* Functions for loading little endian to host endianess. */

#define OSReadLittleInt16(base, byteOffset) OSReadSwapInt16(base, byteOffset)
#define OSReadLittleInt32(base, byteOffset) OSReadSwapInt32(base, byteOffset)
#define OSReadLittleInt64(base, byteOffset) OSReadSwapInt64(base, byteOffset)

/* Functions for storing host endianess to little endian. */

#define OSWriteLittleInt16(base, byteOffset, data) OSWriteSwapInt16(base, byteOffset, data)
#define OSWriteLittleInt32(base, byteOffset, data) OSWriteSwapInt32(base, byteOffset, data)
#define OSWriteLittleInt64(base, byteOffset, data) OSWriteSwapInt64(base, byteOffset, data)

/* Generic big endian to host endianess byte swapping functions. */

#define OSSwapBigToHostInt16(x) ((uint16_t)(x))
#define OSSwapBigToHostInt32(x) ((uint32_t)(x))
#define OSSwapBigToHostInt64(x) ((uint64_t)(x))

#elif defined(__LITTLE_ENDIAN__)

/* Functions for loading big endian to host endianess. */

#define OSReadBigInt16(base, byteOffset) OSReadSwapInt16(base, byteOffset)
#define OSReadBigInt32(base, byteOffset) OSReadSwapInt32(base, byteOffset)
#define OSReadBigInt64(base, byteOffset) OSReadSwapInt64(base, byteOffset)

/* Functions for storing host endianess to big endian. */

#define OSWriteBigInt16(base, byteOffset, data) OSWriteSwapInt16(base, byteOffset, data)
#define OSWriteBigInt32(base, byteOffset, data) OSWriteSwapInt32(base, byteOffset, data)
#define OSWriteBigInt64(base, byteOffset, data) OSWriteSwapInt64(base, byteOffset, data)

/* Functions for loading little endian to host endianess. */

#define OSReadLittleInt16(base, byteOffset) _OSReadInt16(base, byteOffset)
#define OSReadLittleInt32(base, byteOffset) _OSReadInt32(base, byteOffset)
#define OSReadLittleInt64(base, byteOffset) _OSReadInt64(base, byteOffset)

/* Functions for storing host endianess to little endian. */

#define OSWriteLittleInt16(base, byteOffset, data) _OSWriteInt16(base, byteOffset, data)
#define OSWriteLittleInt32(base, byteOffset, data) _OSWriteInt32(base, byteOffset, data)
#define OSWriteLittleInt64(base, byteOffset, data) _OSWriteInt64(base, byteOffset, data)

/* Generic big endian to host endianess byte swapping functions. */

#define OSSwapBigToHostInt16(x) OSSwapInt16(x)
#define OSSwapBigToHostInt32(x) OSSwapInt32(x)
#define OSSwapBigToHostInt64(x) OSSwapInt64(x)

#endif

#endif
