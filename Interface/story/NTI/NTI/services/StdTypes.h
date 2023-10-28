
#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char   u8;
typedef   signed char   s8;

typedef unsigned short u16;
typedef   signed short s16;

typedef unsigned long  u32;
typedef   signed long  s32; 

typedef	float				f32;
typedef	double				f64;

#define  MAX_U8   ((u8)255)
#define  MIN_U8   ((u8)0)

#define  MAX_S8   ((s8)127)
#define  MIN_S8   ((s8)-128)
#define  NULLPTR ((void*)0)


#endif /* STDTYPES_H_ */