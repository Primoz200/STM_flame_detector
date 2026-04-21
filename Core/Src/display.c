#include "stm32h750b_discovery_lcd.h"
#include "stm32_lcd.h"



void drawArrow(float angle, Point* tocke){

	//druga tocka premice okoli naredimo premico
	float angle_rad = angle * M_PI / 180.0f;
	float length = 200.0f;
	float halfWidth = 10.0f;

	float sinx = sinf(angle_rad);
	float cosx = cosf(angle_rad);

	uint16_t xBase = 240;
	uint16_t yBase = 20;
	uint16_t xBase2 = (uint16_t)(xBase + sinx * length);
	uint16_t yBase2 = (uint16_t)(yBase  + cosx * length);

	tocke[0] = (Point){
		xBase,
		yBase
	};
	tocke[1] = (Point){
		xBase2,
		yBase2
	};
	UTIL_LCD_DrawLine(xBase, yBase, xBase2, yBase2, UTIL_LCD_COLOR_BLACK);
}
