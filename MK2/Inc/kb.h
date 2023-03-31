#ifndef INC_KEYBOARD_H_
#define INC_KEYBOARD_H_

#define ROW1 0x1E
#define ROW2 0x3D
#define ROW3 0x7B
#define ROW4 0xF7


uint8_t Check_Row( uint8_t  Nrow );
HAL_StatusTypeDef Set_Keyboard( void );

#endif /* INC_KEYBOARD_H_ */
