//
// Created by Asus on 11.03.2023.
//

#include "hal.h"
#include <iostream>

int leds[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_11, GPIO_PIN_12};
unsigned int sw[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};

//Светодиод VD6 горит зеленым
void green() {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

//Светодиод VD7 горит желтым
void yellow() {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

//Светодиод VD7 горит красным
void red() {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

//Нажатие на nBtn
void stop_animation() {
    red();
    HAL_Delay(200);
    GPIO_PinState state = GPIO_PIN_SET;
    while (state == GPIO_PIN_SET)
        state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);
    green();

}

//Сброс всех
void clear_all() {
    for (int i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(GPIOD, leds[i], GPIO_PIN_RESET);
    }
}

//Если нажали на nBtn - остановка
void checkBTN(){
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_RESET) {
        stop_animation();
    }
}

bool checkCondition(){
    return(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == GPIO_PIN_SET &&
          HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == GPIO_PIN_RESET &&
          HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == GPIO_PIN_SET &&
          HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == GPIO_PIN_RESET);
}
//Зажигание нужных светодиодов
void start_animation() {
    clear_all();
    for (int i = 0; i < 14; i++) {
        if (i < 8) {
            HAL_GPIO_WritePin(GPIOD, leds[i], GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(GPIOD, leds[14 - i + 1], GPIO_PIN_RESET);
        }
        //Время показа одного кадра – 0.5 с
        HAL_Delay(500);

        checkBTN();

        //0x5 = 0101
        if (!checkCondition())
            break;

    }
}

void show_sw() {
    for (int i = 0; i < 4; i++) {
        GPIO_PinState state = HAL_GPIO_ReadPin(GPIOE, sw[i]);
        HAL_GPIO_WritePin(GPIOD, leds[i], state);
    }
}


int umain() {
    while (true) {
        //0x5 = 0101
        if (checkCondition()) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            green();
            start_animation();
        } else {
            show_sw();
            yellow();
        }
    }

    return 0;
}
