#ifndef __STM32F4xx_HAL_CONF_H
#define __STM32F4xx_HAL_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif

#define HAL_MODULE_ENABLED

#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED

#if !defined  (HSE_VALUE)
  #define HSE_VALUE    8000000U
#endif

#if !defined  (HSE_STARTUP_TIMEOUT)
  #define HSE_STARTUP_TIMEOUT    100U
#endif

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)16000000U)
#endif

#if !defined  (LSI_VALUE)
 #define LSI_VALUE  32000U
#endif

#if !defined  (LSE_VALUE)
 #define LSE_VALUE  32768U
#endif

#if !defined  (LSE_STARTUP_TIMEOUT)
  #define LSE_STARTUP_TIMEOUT    5000U
#endif

#if !defined  (EXTERNAL_CLOCK_VALUE)
  #define EXTERNAL_CLOCK_VALUE    12288000U
#endif

#define  VDD_VALUE		      3300U
#define  TICK_INT_PRIORITY            15U
#define  USE_RTOS                     0U
#define  PREFETCH_ENABLE              1U
#define  INSTRUCTION_CACHE_ENABLE     1U
#define  DATA_CACHE_ENABLE            1U

#define  USE_HAL_ADC_REGISTER_CALLBACKS         0U
#define  USE_HAL_CAN_REGISTER_CALLBACKS         0U
#define  USE_HAL_CEC_REGISTER_CALLBACKS         0U
#define  USE_HAL_CRYP_REGISTER_CALLBACKS        0U
#define  USE_HAL_DAC_REGISTER_CALLBACKS         0U
#define  USE_HAL_DCMI_REGISTER_CALLBACKS        0U
#define  USE_HAL_DFSDM_REGISTER_CALLBACKS       0U
#define  USE_HAL_DMA2D_REGISTER_CALLBACKS       0U
#define  USE_HAL_DSI_REGISTER_CALLBACKS         0U
#define  USE_HAL_ETH_REGISTER_CALLBACKS         0U
#define  USE_HAL_HASH_REGISTER_CALLBACKS        0U
#define  USE_HAL_HCD_REGISTER_CALLBACKS         0U
#define  USE_HAL_I2C_REGISTER_CALLBACKS         0U
#define  USE_HAL_FMPI2C_REGISTER_CALLBACKS      0U
#define  USE_HAL_FMPSMBUS_REGISTER_CALLBACKS    0U
#define  USE_HAL_I2S_REGISTER_CALLBACKS         0U
#define  USE_HAL_IRDA_REGISTER_CALLBACKS        0U
#define  USE_HAL_LPTIM_REGISTER_CALLBACKS       0U
#define  USE_HAL_LTDC_REGISTER_CALLBACKS        0U
#define  USE_HAL_MMC_REGISTER_CALLBACKS         0U
#define  USE_HAL_NAND_REGISTER_CALLBACKS        0U
#define  USE_HAL_NOR_REGISTER_CALLBACKS         0U
#define  USE_HAL_PCCARD_REGISTER_CALLBACKS      0U
#define  USE_HAL_PCD_REGISTER_CALLBACKS         0U
#define  USE_HAL_QSPI_REGISTER_CALLBACKS        0U
#define  USE_HAL_RNG_REGISTER_CALLBACKS         0U
#define  USE_HAL_RTC_REGISTER_CALLBACKS         0U
#define  USE_HAL_SAI_REGISTER_CALLBACKS         0U
#define  USE_HAL_SD_REGISTER_CALLBACKS          0U
#define  USE_HAL_SMARTCARD_REGISTER_CALLBACKS   0U
#define  USE_HAL_SDRAM_REGISTER_CALLBACKS       0U
#define  USE_HAL_SRAM_REGISTER_CALLBACKS        0U
#define  USE_HAL_SPDIFRX_REGISTER_CALLBACKS     0U
#define  USE_HAL_SMBUS_REGISTER_CALLBACKS       0U
#define  USE_HAL_SPI_REGISTER_CALLBACKS         0U
#define  USE_HAL_TIM_REGISTER_CALLBACKS         0U
#define  USE_HAL_UART_REGISTER_CALLBACKS        0U
#define  USE_HAL_USART_REGISTER_CALLBACKS       0U
#define  USE_HAL_WWDG_REGISTER_CALLBACKS        0U

#define MAC_ADDR0   2U
#define MAC_ADDR1   0U
#define MAC_ADDR2   0U
#define MAC_ADDR3   0U
#define MAC_ADDR4   0U
#define MAC_ADDR5   0U

#define ETH_RX_BUF_SIZE                ETH_MAX_PACKET_SIZE
#define ETH_TX_BUF_SIZE                ETH_MAX_PACKET_SIZE
#define ETH_RXBUFNB                    4U
#define ETH_TXBUFNB                    4U

#define DP83848_PHY_ADDRESS
#define PHY_RESET_DELAY                 0x000000FFU
#define PHY_CONFIG_DELAY                0x00000FFFU
#define PHY_READ_TO                     0x0000FFFFU
#define PHY_WRITE_TO                    0x0000FFFFU

#define PHY_BCR                         ((uint16_t)0x0000U)
#define PHY_BSR                         ((uint16_t)0x0001U)
#define PHY_RESET                       ((uint16_t)0x8000U)
#define PHY_LOOPBACK                    ((uint16_t)0x4000U)
#define PHY_FULLDUPLEX_100M             ((uint16_t)0x2100U)
#define PHY_HALFDUPLEX_100M             ((uint16_t)0x2000U)
#define PHY_FULLDUPLEX_10M              ((uint16_t)0x0100U)
#define PHY_HALFDUPLEX_10M              ((uint16_t)0x0000U)
#define PHY_AUTONEGOTIATION             ((uint16_t)0x1000U)
#define PHY_RESTART_AUTONEGOTIATION     ((uint16_t)0x0200U)
#define PHY_POWERDOWN                   ((uint16_t)0x0800U)
#define PHY_ISOLATE                     ((uint16_t)0x0400U)
#define PHY_AUTONEGO_COMPLETE           ((uint16_t)0x0020U)
#define PHY_LINKED_STATUS               ((uint16_t)0x0004U)
#define PHY_JABBER_DETECTION            ((uint16_t)0x0002U)

#define USE_SPI_CRC                     0U

#ifdef HAL_RCC_MODULE_ENABLED
  #include "stm32f4xx_hal_rcc.h"
#endif

#ifdef HAL_GPIO_MODULE_ENABLED
  #include "stm32f4xx_hal_gpio.h"
#endif

#ifdef HAL_EXTI_MODULE_ENABLED
  #include "stm32f4xx_hal_exti.h"
#endif

#ifdef HAL_DMA_MODULE_ENABLED
  #include "stm32f4xx_hal_dma.h"
#endif

#ifdef HAL_CORTEX_MODULE_ENABLED
  #include "stm32f4xx_hal_cortex.h"
#endif

#ifdef HAL_ADC_MODULE_ENABLED
  #include "stm32f4xx_hal_adc.h"
#endif

#ifdef HAL_CAN_MODULE_ENABLED
  #include "stm32f4xx_hal_can.h"
#endif

#ifdef HAL_CAN_LEGACY_MODULE_ENABLED
  #include "stm32f4xx_hal_can_legacy.h"
#endif

#ifdef HAL_CRC_MODULE_ENABLED
  #include "stm32f4xx_hal_crc.h"
#endif

#ifdef HAL_CRYP_MODULE_ENABLED
  #include "stm32f4xx_hal_cryp.h"
#endif

#ifdef HAL_DMA2D_MODULE_ENABLED
  #include "stm32f4xx_hal_dma2d.h"
#endif

#ifdef HAL_DAC_MODULE_ENABLED
  #include "stm32f4xx_hal_dac.h"
#endif

#ifdef HAL_DCMI_MODULE_ENABLED
  #include "stm32f4xx_hal_dcmi.h"
#endif

#ifdef HAL_ETH_MODULE_ENABLED
  #include "stm32f4xx_hal_eth.h"
#endif

#ifdef HAL_ETH_LEGACY_MODULE_ENABLED
  #include "stm32f4xx_hal_eth_legacy.h"
#endif

#ifdef HAL_FLASH_MODULE_ENABLED
  #include "stm32f4xx_hal_flash.h"
#endif

#ifdef HAL_SRAM_MODULE_ENABLED
  #include "stm32f4xx_hal_sram.h"
#endif

#ifdef HAL_NOR_MODULE_ENABLED
  #include "stm32f4xx_hal_nor.h"
#endif

#ifdef HAL_NAND_MODULE_ENABLED
  #include "stm32f4xx_hal_nand.h"
#endif

#ifdef HAL_PCCARD_MODULE_ENABLED
  #include "stm32f4xx_hal_pccard.h"
#endif

#ifdef HAL_SDRAM_MODULE_ENABLED
  #include "stm32f4xx_hal_sdram.h"
#endif

#ifdef HAL_HASH_MODULE_ENABLED
 #include "stm32f4xx_hal_hash.h"
#endif

#ifdef HAL_I2C_MODULE_ENABLED
 #include "stm32f4xx_hal_i2c.h"
#endif

#ifdef HAL_SMBUS_MODULE_ENABLED
 #include "stm32f4xx_hal_smbus.h"
#endif

#ifdef HAL_I2S_MODULE_ENABLED
 #include "stm32f4xx_hal_i2s.h"
#endif

#ifdef HAL_IWDG_MODULE_ENABLED
 #include "stm32f4xx_hal_iwdg.h"
#endif

#ifdef HAL_LTDC_MODULE_ENABLED
 #include "stm32f4xx_hal_ltdc.h"
#endif

#ifdef HAL_PWR_MODULE_ENABLED
 #include "stm32f4xx_hal_pwr.h"
#endif

#ifdef HAL_RNG_MODULE_ENABLED
 #include "stm32f4xx_hal_rng.h"
#endif

#ifdef HAL_RTC_MODULE_ENABLED
 #include "stm32f4xx_hal_rtc.h"
#endif

#ifdef HAL_SAI_MODULE_ENABLED
 #include "stm32f4xx_hal_sai.h"
#endif

#ifdef HAL_SD_MODULE_ENABLED
 #include "stm32f4xx_hal_sd.h"
#endif

#ifdef HAL_SPI_MODULE_ENABLED
 #include "stm32f4xx_hal_spi.h"
#endif

#ifdef HAL_TIM_MODULE_ENABLED
 #include "stm32f4xx_hal_tim.h"
#endif

#ifdef HAL_UART_MODULE_ENABLED
 #include "stm32f4xx_hal_uart.h"
#endif

#ifdef HAL_USART_MODULE_ENABLED
 #include "stm32f4xx_hal_usart.h"
#endif

#ifdef HAL_IRDA_MODULE_ENABLED
 #include "stm32f4xx_hal_irda.h"
#endif

#ifdef HAL_SMARTCARD_MODULE_ENABLED
 #include "stm32f4xx_hal_smartcard.h"
#endif

#ifdef HAL_WWDG_MODULE_ENABLED
 #include "stm32f4xx_hal_wwdg.h"
#endif

#ifdef HAL_PCD_MODULE_ENABLED
 #include "stm32f4xx_hal_pcd.h"
#endif

#ifdef HAL_HCD_MODULE_ENABLED
 #include "stm32f4xx_hal_hcd.h"
#endif

#ifdef HAL_DSI_MODULE_ENABLED
 #include "stm32f4xx_hal_dsi.h"
#endif

#ifdef HAL_QSPI_MODULE_ENABLED
 #include "stm32f4xx_hal_qspi.h"
#endif

#ifdef HAL_CEC_MODULE_ENABLED
 #include "stm32f4xx_hal_cec.h"
#endif

#ifdef HAL_FMPI2C_MODULE_ENABLED
 #include "stm32f4xx_hal_fmpi2c.h"
#endif

#ifdef HAL_FMPSMBUS_MODULE_ENABLED
 #include "stm32f4xx_hal_fmpsmbus.h"
#endif

#ifdef HAL_SPDIFRX_MODULE_ENABLED
 #include "stm32f4xx_hal_spdifrx.h"
#endif

#ifdef HAL_DFSDM_MODULE_ENABLED
 #include "stm32f4xx_hal_dfsdm.h"
#endif

#ifdef HAL_LPTIM_MODULE_ENABLED
 #include "stm32f4xx_hal_lptim.h"
#endif

#ifdef HAL_MMC_MODULE_ENABLED
 #include "stm32f4xx_hal_mmc.h"
#endif

#ifdef HAL_CORTEX_MODULE_ENABLED
  #include "stm32f4xx_hal_cortex.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_CONF_H */