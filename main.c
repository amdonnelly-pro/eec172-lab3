//*****************************************************************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "rom.h"
#include "rom_map.h"
#include "interrupt.h"
#include "prcm.h"
#include "utils.h"
#include "uart.h"
#include "uart_if.h"
#include "i2c_if.h"

// IMPORTED FROM LAB 2
#include "hw_apps_rcm.h"
#include "gpio.h"
#include "oled_test.h"
#include "Adafruit_SSD1351.h"
#include "Adafruit_GFX.h"

#include "spi.h"
#include "driverlib/spi.h"

// Common interface includes
#include "gpio_if.h"
#include "pinmux.h"

#define APPLICATION_VERSION     "1.4.0"
#define APP_NAME                "I2C Demo"
#define UART_PRINT              Report
#define FOREVER                 1
#define CONSOLE                 UARTA0_BASE
#define FAILURE                 -1
#define SUCCESS                 0
#define RETERR_IF_TRUE(condition) {if(condition) return FAILURE;}
#define RET_IF_ERR(Func)          {int iRetVal = (Func); \
                                   if (SUCCESS != iRetVal) \
                                     return  iRetVal;}
#define SPI_IF_BIT_RATE  100000

//*****************************************************************************
#if defined(ccs)
extern void (* const g_pfnVectors[])(void);
#endif
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif
//*****************************************************************************
static void
BoardInit(void)
{
#ifndef USE_TIRTOS
#if defined(ccs)
    MAP_IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);
#endif
#if defined(ewarm)
    MAP_IntVTableBaseSet((unsigned long)&__vector_table);
#endif
#endif
    MAP_IntMasterEnable();
    MAP_IntEnable(FAULT_SYSTICK);
    PRCMCC3200MCUInit();
}

//*****************************************************************************
void main()
{
    BoardInit();
    PinMuxConfig();
    I2C_IF_Open(I2C_MASTER_MODE_FST);

    MAP_SPIReset(GSPI_BASE);

    // Configure SPI interface
    MAP_SPIConfigSetExpClk(GSPI_BASE,MAP_PRCMPeripheralClockGet(PRCM_GSPI),
                     SPI_IF_BIT_RATE,SPI_MODE_MASTER,SPI_SUB_MODE_0,
                     (SPI_SW_CTRL_CS |
                     SPI_4PIN_MODE |
                     SPI_TURBO_OFF |
                     SPI_CS_ACTIVEHIGH |
                     SPI_WL_8));

    // Enable SPI for communication
    MAP_SPIEnable(GSPI_BASE);

    Adafruit_Init();


    int xLocation;
    int yLocation;
    xLocation = 10;
    yLocation = 10;
    while(FOREVER)
    {
      drawCircle(xLocation, yLocation, 2, BLUE);
    }
}
