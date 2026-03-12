#include "stm32h750b_discovery_lcd.h"
#include "stm32_lcd.h"



void drawArrow(float angle){
	Point tocke[7];
	//druga tocka premice okoli naredimo premico
	float angle_rad = angle * M_PI / 180.0f;
	float length = 200.0f;
	float halfWidth = 20.0f;

	float sinx = sinf(angle_rad);
	float cosx = cosf(angle_rad);

	uint16_t xBase = 240;
	uint16_t yBase = 20;
	uint16_t xBase2 = (uint16_t)(xBase + sinx * length);
	uint16_t yBase2 = (uint16_t)(yBase  + cosx * length);

	uint16_t xHeadBase = (xBase + xBase2) / 2;
	uint16_t yHeadBase = ((yBase + yBase2) / 3) * 2;

	uint16_t xdiff = cosx*halfWidth;
	uint16_t ydiff = sinx*halfWidth;


	//tocke[0] = (Point){xBase2, yBase2};
	tocke[0] = (Point){
		(uint16_t)(xBase - xdiff),
		(uint16_t)(yBase + ydiff)
	};
	tocke[1] = (Point){
		(uint16_t)(xBase + xdiff),
		(uint16_t)(yBase + ydiff)
	};

	tocke[2] = (Point){
		(uint16_t)(xHeadBase - xdiff),
		(uint16_t)(yHeadBase + ydiff)
	};
	tocke[3] = (Point){
		(uint16_t)(xHeadBase + xdiff),
		(uint16_t)(yHeadBase + ydiff)
	};



	UTIL_LCD_FillPolygon(tocke, 4, UTIL_LCD_COLOR_BLACK);

}
