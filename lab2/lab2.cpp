//
// Created by Asus on 18.03.2023.
//

#include "hal.h"
#include <bitset>

int delay = 100;
int i = 0;
int leds[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_11, GPIO_PIN_12};
unsigned int sw[4] = {GPIO_PIN_12, GPIO_PIN_10, GPIO_PIN_8, GPIO_PIN_4};

//Значение кадров
int cadrs[8][8] = {
        {1,0,0,0,0,0,0,1},
        {1,1,0,0,0,0,1,1},
        {1,1,1,0,0,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,0,0,1,1,1},
        {1,1,0,0,0,0,1,1},
        {1,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0},

};

bitset<4> sw_status;

//Считываем значение с SW
void read_and_set(){
    for(int i = 0; i<4; i++) {
        GPIO_PinState state = HAL_GPIO_ReadPin(GPIOE, sw[i]);
        sw_status[i] = state == GPIO_PIN_SET;
    }
}

//Зажигание нужных светодиодов
void set(int num[8]){
    for (int i = 0; i < 8;i++){
        if (num[i] == 1){
            HAL_GPIO_WritePin(GPIOD,leds[i],GPIO_PIN_SET);
        }
    }
}

//Сброс светодиодов
void unset(int num[8]){
    for (int i = 0; i < 8;i++){
        if (num[i] == 1){
            HAL_GPIO_WritePin(GPIOD,leds[i],GPIO_PIN_RESET);
        }
    }
}

//Обработчик таймера TIM6
void TIM6_IRQ_Handler(){
    set(cadrs[i]);
}

//Обработчик таймера TIM7
void TIM7_IRQ_Handler(){
    unset(cadrs[i]);
    i++;
    if(i == 9){
        i=0;
    }
    read_and_set();
    WRITE_REG(TIM6_ARR, 500 + sw_status.to_ulong()*delay);
    WRITE_REG(TIM7_ARR, 500 + sw_status.to_ulong()*delay);
}

//Регистрация и настройка таймеров, разрешение прерываний
int umain(){
    i = 0;
    registerTIM6_IRQHandler(TIM6_IRQ_Handler);
    registerTIM7_IRQHandler(TIM7_IRQ_Handler);

    WRITE_REG(TIM6_ARR, 500);
    WRITE_REG(TIM6_DIER, TIM_DIER_UIE);
    WRITE_REG(TIM6_PSC,0);

    WRITE_REG(TIM7_ARR, 500);
    WRITE_REG(TIM7_DIER, TIM_DIER_UIE);
    WRITE_REG(TIM7_PSC,1);

    __enable_irq();

    WRITE_REG(TIM6_CR1, TIM_CR1_CEN);
    WRITE_REG(TIM7_CR1, TIM_CR1_CEN);

    return 0;
}
