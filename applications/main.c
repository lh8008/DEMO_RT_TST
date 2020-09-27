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
int main(void)
{
//    int count = 1;
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
    thread_sample();
    return RT_EOK;
}
