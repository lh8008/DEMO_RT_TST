/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-25     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "led_thread.h"
//#define LEDR_PIN    GET_PIN(E, 7)
//#define LEDG_PIN    GET_PIN(E, 8)
//#define LEDB_PIN    GET_PIN(E, 9)

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;



/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

rt_uint32_t get_adc_value(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);

    return (rt_uint32_t)HAL_ADC_GetValue(&hadc1);
}


int main(void)
{
    int count = 1;
    rt_uint32_t read_value = 0;

//    rt_hw_board_init();
//    /* set LED0 pin mode to output */
//   rt_pin_mode(LEDR_PIN, PIN_MODE_OUTPUT);
//   rt_pin_mode(LEDG_PIN, PIN_MODE_OUTPUT);
//   rt_pin_mode(LEDB_PIN, PIN_MODE_OUTPUT);
//   rt_pin_write(LEDG_PIN, 1);
//   rt_pin_write(LEDB_PIN, 1);
//    while (count++)
//    {
//        rt_pin_write(LEDR_PIN, count % 2);
//                LOG_D("Hello RT-Thread!");
//                rt_thread_mdelay(1000);
//    }
    //GIT TEST
    //test -- ok
//    thread_sample();
//    MX_ADC1_Init();
//        while (count++)
//        {
//            read_value = get_adc_value();
//            rt_thread_mdelay(1000);
//            rt_kprintf("adc value = %d\r\n", read_value);
//        }
    return RT_EOK;
}
