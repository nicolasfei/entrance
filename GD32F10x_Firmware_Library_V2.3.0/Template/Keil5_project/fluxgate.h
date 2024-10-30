#ifndef FLUXGATE_H
#define FLUXGATE_H

#define FLUXGATEn		6U

/* exported types */
typedef enum 
{
    FLUXGATE1 = 0,
    FLUXGATE2 = 1,
    FLUXGATE3 = 2,
    FLUXGATE4 = 3,
		FLUXGATE5 = 4,
		FLUXGATE6 = 5,
} FLUXGATE_typedef_enum;

typedef enum 
{
    FLUXGATE_OPEN = 0,
    FLUXGATE_CLOSE = 1,
    FLUXGATE_NONE   = 2
} FLUXGATE_status_typedef_enum;

typedef enum 
{
    FLUXGATE_MODE_GPIO = 0,
    FLUXGATE_MODE_EXTI = 1
} FLUXGATE_mode_typedef_enum;


#define FLUXGATE1_PIN                         GPIO_PIN_0
#define FLUXGATE1_GPIO_PORT                   GPIOB
#define FLUXGATE1_GPIO_CLK                    RCU_GPIOB

#define FLUXGATE2_PIN                         GPIO_PIN_15
#define FLUXGATE2_GPIO_PORT                   GPIOA
#define FLUXGATE2_GPIO_CLK                    RCU_GPIOA
  
#define FLUXGATE3_PIN                         GPIO_PIN_4
#define FLUXGATE3_GPIO_PORT                   GPIOB
#define FLUXGATE3_GPIO_CLK                    RCU_GPIOB
  
#define FLUXGATE4_PIN                         GPIO_PIN_6
#define FLUXGATE4_GPIO_PORT                   GPIOB
#define FLUXGATE4_GPIO_CLK                    RCU_GPIOB
  
#define FLUXGATE5_PIN                         GPIO_PIN_8
#define FLUXGATE5_GPIO_PORT                   GPIOB
#define FLUXGATE5_GPIO_CLK                    RCU_GPIOB

#define FLUXGATE6_PIN                         GPIO_PIN_10
#define FLUXGATE6_GPIO_PORT                   GPIOB
#define FLUXGATE6_GPIO_CLK                    RCU_GPIOB


/* fluxgate init function */
void fluxgate_init(FLUXGATE_typedef_enum btnNum);

/* fluxgate release function */
void fluxgate_release(void);

/* fluxgate read function */
FLUXGATE_status_typedef_enum fluxgate_read(FLUXGATE_typedef_enum btnNum);

/* fluxgate set function */
void fluxgate_set(FLUXGATE_typedef_enum btnNum);

#endif /* FLUXGATE_H */

