#ifndef ASTEROID_H_
#define ASTEROID_H_
#define FIXED_POINT_SHIFT 16
#define GRAVITATIONAL_CONSTANT 98 // Gravitational constant (scaled by 2^16)


typedef struct{
	int16_t px, py;
	int8_t vx, vy, state;
} ast_s;

typedef struct{
	int32_t x, y;
} Coordinate;

volatile uint8_t force;

volatile ast_s ship;
volatile ast_s bllt;
volatile ast_s ast1;
volatile ast_s ast2;
volatile ast_s ast3;





#endif /* ASTEROID_H_ */
