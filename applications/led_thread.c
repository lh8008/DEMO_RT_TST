/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-25     chao       the first version
 */
#include <rtthread.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        5

/*　使用静态线程时，线程的栈需要设置字节对齐　*/
ALIGN(RT_ALIGN_SIZE)
static rt_uint8_t thread_stack[THREAD_STACK_SIZE];
static struct rt_thread tid1;

/* 线程 1 的入口函数 */
static void thread1_entry(void *parameter)
{
    rt_uint32_t count = 0;

    while (1)
    {
        rt_kprintf("thread1 count: %d\n", count ++);
        rt_thread_mdelay(500);
    }
}

/* 线程示例 */
int thread_sample(void)
{
    /* 静态创建线程 */

    /* 初始化线程 1，名称是 thread1，入口是 thread1_entry*/
    rt_thread_init(&tid1,
                   "thread1",
                   thread1_entry,
                   RT_NULL,
                   thread_stack,
                   THREAD_STACK_SIZE,
                   THREAD_PRIORITY,
                   THREAD_TIMESLICE);
        /* 启动线程 */
        rt_thread_startup(&tid1);

    return 0;
}
