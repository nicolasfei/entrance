#ifndef BUTTON_H
#define BUTTON_H

#include "gd32f10x.h"

#define BUTTONn		6U

/* exported types */
typedef enum 
{
    BUTTON1 = 0,
    BUTTON2 = 1,
    BUTTON3 = 2,
    BUTTON4 = 3,
		BUTTON5 = 4,
		BUTTON6 = 5,
} button_typedef_enum;

typedef enum 
{
    BUTTON_UP = 0,
    BUTTON_DOWN = 1,
    BUTTON_NONE   = 2
} button_status_typedef_enum;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} button_mode_typedef_enum;


#define BUTTON1_PIN                         GPIO_PIN_1
#define BUTTON1_GPIO_PORT                   GPIOB
#define BUTTON1_GPIO_CLK                    RCU_GPIOB

#define BUTTON2_PIN                         GPIO_PIN_3
#define BUTTON2_GPIO_PORT                   GPIOB
#define BUTTON2_GPIO_CLK                    RCU_GPIOB
  
#define BUTTON3_PIN                         GPIO_PIN_5
#define BUTTON3_GPIO_PORT                   GPIOB
#define BUTTON3_GPIO_CLK                    RCU_GPIOB
  
#define BUTTON4_PIN                         GPIO_PIN_7
#define BUTTON4_GPIO_PORT                   GPIOB
#define BUTTON4_GPIO_CLK                    RCU_GPIOB
  
#define BUTTON5_PIN                         GPIO_PIN_9
#define BUTTON5_GPIO_PORT                   GPIOB
#define BUTTON5_GPIO_CLK                    RCU_GPIOB

#define BUTTON6_PIN                         GPIO_PIN_11
#define BUTTON6_GPIO_PORT                   GPIOB
#define BUTTON6_GPIO_CLK                    RCU_GPIOB

/* button init function */
void button_init(button_typedef_enum btnNum);

/* button release function */
void button_release(void);

/* button read function */
button_status_typedef_enum button_read(button_typedef_enum btnNum);

/* button set function */
void button_set(button_typedef_enum btnNum);

#endif /* BUTTON_H */

