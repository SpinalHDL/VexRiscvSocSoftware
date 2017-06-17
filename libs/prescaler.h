#ifndef PRESCALERCTRL_H_
#define PRESCALERCTRL_H_

#include <stdint.h>


typedef struct
{
  volatile uint32_t LIMIT;
} Prescaler_Reg;

void prescaler_init(Prescaler_Reg* reg){

}

#endif /* PRESCALERCTRL_H_ */
