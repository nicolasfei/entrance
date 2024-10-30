#include "fluxgate.h"
#include "gd32f10x.h"

static rcu_periph_enum FG_GPIO_CLK[FLUXGATEn] = {FLUXGATE1_GPIO_CLK, FLUXGATE2_GPIO_CLK, 
																						FLUXGATE3_GPIO_CLK, FLUXGATE4_GPIO_CLK,
																						FLUXGATE5_GPIO_CLK, FLUXGATE6_GPIO_CLK};

static uint32_t FG_GPIO_PORT[FLUXGATEn] = {FLUXGATE1_GPIO_PORT, FLUXGATE2_GPIO_PORT, 
																						 FLUXGATE3_GPIO_PORT, FLUXGATE4_GPIO_PORT,
																						 FLUXGATE5_GPIO_PORT, FLUXGATE6_GPIO_PORT};																						
																						
static uint32_t FG_GPIO_PIN[FLUXGATEn] = {FLUXGATE1_PIN, FLUXGATE2_PIN, 
																						FLUXGATE3_PIN, FLUXGATE4_PIN,
																						FLUXGATE5_PIN, FLUXGATE6_PIN};


/**
	*fluxgate init function 
	*/
void fluxgate_init(FLUXGATE_typedef_enum fgtNum)
{
		/* enable the led clock */
    rcu_periph_clock_enable(FG_GPIO_CLK[fgtNum]);
    /* configure led GPIO port */ 
    gpio_init(FG_GPIO_PORT[fgtNum], GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, FG_GPIO_PIN[fgtNum]);

    GPIO_BC(FG_GPIO_PORT[fgtNum]) = FG_GPIO_PIN[fgtNum];
}

/**
	*fluxgate release function 
	*/
void fluxgate_release(void)
{
	gpio_deinit(GPIOB);
	gpio_deinit(GPIOA);
}

/**
	*fluxgate read function 
	*/
FLUXGATE_status_typedef_enum fluxgate_read(FLUXGATE_typedef_enum fgtNum)
{
	FlagStatus status = gpio_input_bit_get(FG_GPIO_PORT[fgtNum], FG_GPIO_PIN[fgtNum]);
	return status == SET ? FLUXGATE_OPEN : FLUXGATE_CLOSE;
}

/**
	*fluxgate set function 
	*/
void fluxgate_set(FLUXGATE_typedef_enum fgtNum)
{
	//NONE
}


