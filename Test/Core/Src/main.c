/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
// 流水灯-用于观察单片机是否正常运行
uint32_t SysTick_Interrupt_Counter = 0;
uint8_t Toggle_Run_Led_Flag = 0;

// 串口通信-全双工
uint8_t Uart1_Rx_Buf[MAX_UART1_LENBUF] = {0};
uint16_t Uart1_Rx_Buf_p = 0;
uint16_t Uart1_Rx_Message_Num = 0;
enum Uart1_Rx_Statues{
    go_on,wait
}Uart1_Rx_Statue;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  // 串口接收函数起始中断
  HAL_UART_Receive_IT(&huart1,(uint8_t*)Uart1_Rx_Buf,1);
  // 设置初始状态
  Uart1_Rx_Statue = go_on;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    if(Toggle_Run_Led_Flag){
        Toggle_Run_Led_Flag = 0;
        HAL_GPIO_TogglePin(Run_GPIO_Port,Run_Pin);
    }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/**
 * 接受中断回调函数
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
    // 数据缓冲区
    if (UartHandle == &huart1) {//如果接受到串口1的数据
        switch (Uart1_Rx_Statue) {
            case go_on:
                if (Uart1_Rx_Buf[Uart1_Rx_Buf_p] != '\r') {//非\r 非\n--保持当前状态（go_on）
                    Uart1_Rx_Buf_p++;
                    if (Uart1_Rx_Buf_p > MAX_UART1_LENBUF - 1) {//索引值从0开始
                        Uart1_Rx_Buf_p = 0;
                    }
                } else {//遇到\r--需要改变状态(go_on -> wait)
                    Uart1_Rx_Statue = wait;
                }
                break;
            case wait:
                if (Uart1_Rx_Buf[Uart1_Rx_Buf_p] != '\n') {//等待\n-保持当前状态(wait)
                    //保持当前Statue
                } else {//遇见\n--需要改变状态(wait -> go_on)
                    Uart1_Rx_Message_Num++;
                    Uart1_Rx_Buf_p++;
                    if (Uart1_Rx_Buf_p > MAX_UART1_LENBUF - 1) {//索引值从0开始
                        Uart1_Rx_Buf_p = 0;
                    }
                    //状态设置为继续
                    Uart1_Rx_Statue = go_on;
                }
                break;
            default:
                break;
        }
        //中断
        HAL_UART_Receive_IT(&huart1, &Uart1_Rx_Buf[Uart1_Rx_Buf_p], 1);
    }
}
/**
   * Function_Definition
   * SysTick_Interrupt_Server
   */
void Set_Flag_Regularly_Interrupt_Server(void){
    SysTick_Interrupt_Counter++;
    if(SysTick_Interrupt_Counter%1000==0){
        Toggle_Run_Led_Flag = 1;
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
