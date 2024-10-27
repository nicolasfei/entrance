#include "button.h"
#include "gd32f10x.h"

static rcu_periph_enum GPIO_CLK[BUTTONn] = {BUTTON1_GPIO_CLK, BUTTON2_GPIO_CLK, 
																						BUTTON3_GPIO_CLK, BUTTON4_GPIO_CLK,
																						BUTTON5_GPIO_CLK, BUTTON6_GPIO_CLK};

static rcu_periph_enum GPIO_PORT[BUTTONn] = {BUTTON1_GPIO_PORT, BUTTON2_GPIO_PORT, 
																						 BUTTON3_GPIO_PORT, BUTTON4_GPIO_PORT,
																						 BUTTON5_GPIO_PORT, BUTTON6_GPIO_PORT};																						
																						
static rcu_periph_enum GPIO_PIN[BUTTONn] = {BUTTON1_PIN, BUTTON2_PIN, 
																						BUTTON3_PIN, BUTTON4_PIN,
																						BUTTON5_PIN, BUTTON6_PIN};

/**
	* button init function 
	*/
void button_init(button_typedef_enum btnNum)
{
	/* enable the led clock */
    rcu_periph_clock_enable(GPIO_CLK[btnNum]);
    /* configure led GPIO port */ 
    gpio_init(GPIO_PORT[btnNum], GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN[btnNum]);

    GPIO_BC(GPIO_PORT[btnNum]) = GPIO_PIN[btnNum];
}

/*!
    \brief      button release function 
    \param[in]  none
    \param[out] none
    \retval     none
*/
void button_release()
{
	gpio_deinit(GPIOB);
}

/**
	* button read function 
	*/
button_status_typedef_enum button_read(button_typedef_enum btnNum)
{
	FlagStatus status = gpio_input_bit_get(GPIO_PORT[btnNum], GPIO_PIN[btnNum]);
	return status == SET ? BUTTON_DOWN : BUTTON_UP;
}

/**
	* button set function 
	*/
void button_set(button_typedef_enum btnNum)
{
	//none
}