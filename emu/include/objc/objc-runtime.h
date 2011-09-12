#ifndef _OBJC_OBJC_RUNTIME_H_
#define _OBJC_OBJC_RUNTIME_H_

#define CLS_GETINFO(cls,infomask) ((cls)->info & (infomask))

#define CLS_CLASS               0x1
#define CLS_META                0x2

#endif
