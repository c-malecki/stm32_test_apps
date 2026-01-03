#include "ds18b20.h"
#include "stm32f1xx_hal_tim.h"

// datasheet: https://cdn-shop.adafruit.com/datasheets/DS18B20.pdf

/*
  ROM Commands:
    - Search ROM [F0h]
    - Read ROM [33h]
    - Match ROM [55h]
    - Skip ROM [CCh]
    - Alarm Search [ECh]
    - Convert T [44h]
    - Write Scratchpad [4Eh]
    - Read Scratchpad [BEh]
    - Copy Scratchpad [48h]
    - Recall E^2 [B8h]
    - Read Power Supply [B4h]
*/

/*
  Transactions (Tx) Sequence:

  Little endian

  Must follow this sequence everytime sensor is accessed.

  Step 1. Initilization
  Step 2. ROM Command (followed by any required data exchange)
  Step 3. Function Command (followed by any required data exchange)
  (Loop back to step 1)

  Exceptions (Step 2. ROM Commands):
    - Search ROM [F0h]
    - Alarm Search [ECh]

  Step 1. Initilization
  Step 2. Search ROM (followed by any required data exchange)
  (Loop back to step 1)
*/

/*
  Signals:

  Uses strict 1-wire com protocol:
    - Reset Pulse (master)
    - Presence Pulse (slave)
    - Write 0 (master)
    - Write 1 (master)
    - Read 0 (master)
    - Read 1 (master)

  [Reset Pulse]
  Master Tx by pulling 1-Wire bus low for
  minimum of 480us. Master releases the bus and goes into Receiever (Rx) mode.

  [Presense Pulse]
  After Master releases, 5kohm pullup resistor pulls bus high. Sensor detects
  rising edge, waits 15us - 60us then slave Tx by pulling low for 60us
  - 240us.

  Write & Read use time slots for each operation where master pulls low for min
  60us duration with min 1us recovery time.

  [Write 1]
  Master release within 15us of the 60us duration.

  [Write 0]
  Master hold low min 60us duration.

  Master must generate read time slots immediately after issuing:
    - Read Scratchpad [BEh]
    - Read Power Supply [B4h]

  To find out status of the opperation as explained in the DS18B20 Function
  Commands section:
    - Convert T [44h]
    - Recall E^2 [B8h]

  [Read 1]
  Master release after min 1us. Sensor Tx a 1 by staying high.

  [Read 0]
  Master release after min 1us. Sensor Tx a 0 by pulling low. Sensor will
  release by end of time slot and bus will pullup to idle high.

  Output data is valid for 15us after falling edge that initiated read time
  slot. Master must release then sample state within 15us from the start of
  slot.
*/

/*
  Initialization:

  Master must identify ROM codes of all slave devices on the bus.
    - One sensor: Read ROM [33h] can be used.
    - Multiple Sensors: Search ROM [F0h] process must be used.

  If more than one salve is connected and master tries to read salve's 64-bit
  ROM code, a data collision will occur.

  [Reset Pulse] -> [Presence Pulse] -> [ROM Command] (including skip command) ->
  [Function Command]
*/

// referenced
// https://controllerstech.com/create-microsecond-delay-stm32/#:~:text=Limitation%20of%20HAL_Delay,requires%20precise%20timing%20in%20microseconds.
static void delay_us(TIM_HandleTypeDef *timer_handle, uint16_t us) {
  __HAL_TIM_SET_COUNTER(timer_handle, us);
  while (__HAL_TIM_GET_COUNTER(timer_handle) < us)
    ;
};

static reset_pulse(TIM_HandleTypeDef *timer_handle, GPIO_TypeDef *GPIOx,
                   uint16_t GPIO_Pin, DS18B20_Power_Scheme PowerScheme) {
  // if (PowerScheme == DS18B20_Power_Parasite) {

  // } else {

  // }
  // mcu sends reset pulse
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
  delay_us(timer_handle, 480);
  // mcu releases and sensor detects rising edge and waits 15us-60us
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);

  //
};

static DS18B20_Power_Scheme DS18B20_Check_Power_Scheme() {
  // Reset Pulse
  // Presense Pulse
  // Skip Rom
  // Read Power Supply
  // read time slot

  // get pin state
  // bus pulls low = parasite
  // bus stays high = external
};

DS18B20_Sensor DS18B20_Init_Sensor(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
                                   DS18B20_Power_Scheme power_scheme) {
  // Reset Pulse
  // Presense Pulse
  // Read ROM
};

DS18B20_Sensor DS18B20_Read_Sensor(TIM_HandleTypeDef *timer_handle,
                                   DS18B20_Sensor *sensor) {

};