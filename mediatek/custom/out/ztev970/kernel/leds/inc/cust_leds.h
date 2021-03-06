#ifndef _CUST_LEDS_H
#define _CUST_LEDS_H

enum mt65xx_led_type
{
	MT65XX_LED_TYPE_RED = 0,
	MT65XX_LED_TYPE_GREEN,
	MT65XX_LED_TYPE_BLUE,
	MT65XX_LED_TYPE_JOGBALL,
	MT65XX_LED_TYPE_KEYBOARD,
	MT65XX_LED_TYPE_BUTTON,	
	MT65XX_LED_TYPE_LCD,
	MT65XX_LED_TYPE_TOTAL,
};

enum mt65xx_led_mode
{
	MT65XX_LED_MODE_NONE,
	MT65XX_LED_MODE_PWM,
	MT65XX_LED_MODE_GPIO,
	MT65XX_LED_MODE_PMIC,
	MT65XX_LED_MODE_CUST
};

enum mt65xx_led_pmic
{
	MT65XX_LED_PMIC_BUTTON=0,
	MT65XX_LED_PMIC_LCD,
	MT65XX_LED_PMIC_LCD_ISINK,
	MT65XX_LED_PMIC_LCD_BOOST,
	MT65XX_LED_PMIC_NLED_ISINK4,
	MT65XX_LED_PMIC_NLED_ISINK5
};
struct PWM_config
{
	int clock_source;
	int div;
	int low_duration;
	int High_duration;
};
typedef int (*cust_brightness_set)(int level, int div);

/*
 * name : must the same as lights HAL
 * mode : control mode
 * data :
 *    PWM:  pwm number
 *    GPIO: gpio id
 *    PMIC: enum mt65xx_led_pmic
 *    CUST: custom set brightness function pointer
*/
struct cust_mt65xx_led {
	char                 *name;
	enum mt65xx_led_mode  mode;
	int                   data;
 struct PWM_config config_data;
};

extern struct cust_mt65xx_led *get_cust_led_list(void);

#define FIXED_BUTTON_LEDS_BRIGHTNESS 0x9
#define FIXED_R_LEDS_BRIGHTNESS 10  //max 31
#define FIXED_G_LEDS_BRIGHTNESS 10  //max 31

#endif


