#ifndef DS18B20_H
#define DS18B20_H

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>

#define DS18B20_ROM_CMD_SEARCH 0xF0
#define DS18B20_ROM_CMD_READ 0x33
#define DS18B20_ROM_CMD_MATCH 0x55
#define DS18B20_ROM_CMD_SKIP 0xCC

#define DS18B20_FUNC_CMD_SCRATCHPAD_READ 0xBE
#define DS18B20_FUNC_CMD_SCRATCHPAD_WRITE 0x4E
#define DS18B20_FUNC_CMD_SCRATCHPAD_COPY 0x48
#define DS18B20_FUNC_CMD_ECEEPROM_RECALL 0xB8
#define DS18B20_FUNC_CMD_PWRSUPPLY_READ 0xB4

typedef enum {
  DS18B20_Power_Parasite = 0,
  DS18B20_Power_External
} DS18B20_Power_Scheme;

// typedef struct {
//   uint16_t sensor_count;
//   uint16_t pin_num;
// } DS18B20_InitCfg;

typedef struct {
  uint64_t rom_code;
  uint8_t is_ready;
  uint8_t *current_read_buf[8];
  uint64_t *current_read_started_at;
  uint64_t *current_read_ended_at;
  uint8_t *last_read_buf[8];
  uint64_t *last_read_started_at;
  uint64_t *last_read_ended_at;
} DS18B20_Sensor;

DS18B20_Sensor DS18B20_Init_Sensor(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
                                   DS18B20_Power_Scheme power_scheme);
DS18B20_Sensor DS18B20_Read_Sensor(TIM_HandleTypeDef *timer_handle,
                                   DS18B20_Sensor *sensor);
// Todo: DS18B20_Init_Many

#endif

// init
// ROM command
// Function command

/*
  Config:

  num_sensors - determines of search or read is used
  pin_num - pin used for data signal
*/

/*
  Init:

  param: *config
  return: sensors hash table?
*/

/*
  sensors hash table?
*/

/*
  sensor struct

  id: 64-bit ROM code ID for sensor
  last_read_value: byte array
  last_read_started_at: time
  last_read_completed_at: time
  current_read_value: byte array
  current_read_started_at: time
  current_read_completed_at: time
*/