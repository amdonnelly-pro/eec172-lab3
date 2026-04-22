// This file was automatically generated on 7/21/2014 at 3:06:20 PM
#include "pinmux.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_gpio.h"
#include "pin.h"
#include "rom.h"
#include "rom_map.h"
#include "gpio.h"
#include "prcm.h"

//*****************************************************************************
void
PinMuxConfig(void)
{
    // Enable Peripheral Clocks 
    MAP_PRCMPeripheralClkEnable(PRCM_UARTA0, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_I2CA0, PRCM_RUN_MODE_CLK);

    // UART
    // PIN_55  = TX, PIN_57  = RX
    MAP_PinTypeUART(PIN_55, PIN_MODE_3);
    MAP_PinTypeUART(PIN_57, PIN_MODE_3);

    // I2C (DO NOT CONNECT TO THESE, for contacting PuTTY)
    // PIN_01 = I2C0 I2C_SCL
    // PIN_02  = I2C0 I2C_SDA
    MAP_PinTypeI2C(PIN_01, PIN_MODE_1);
    MAP_PinTypeI2C(PIN_02, PIN_MODE_1);


    // Set unused pins to PIN_MODE_0 except JTAG pins 16,17,19,20
    PinModeSet(PIN_04, PIN_MODE_0);
    PinModeSet(PIN_08, PIN_MODE_0);
    PinModeSet(PIN_15, PIN_MODE_0);
    PinModeSet(PIN_21, PIN_MODE_0);
    PinModeSet(PIN_45, PIN_MODE_0);
    PinModeSet(PIN_52, PIN_MODE_0);
    PinModeSet(PIN_53, PIN_MODE_0);
    PinModeSet(PIN_55, PIN_MODE_0);
    PinModeSet(PIN_57, PIN_MODE_0);
    PinModeSet(PIN_59, PIN_MODE_0);
    PinModeSet(PIN_60, PIN_MODE_0);
    PinModeSet(PIN_61, PIN_MODE_0);
    PinModeSet(PIN_62, PIN_MODE_0);
    PinModeSet(PIN_63, PIN_MODE_0);
    PinModeSet(PIN_64, PIN_MODE_0);

    // Enable Peripheral Clocks
    PRCMPeripheralClkEnable(PRCM_GPIOA0, PRCM_RUN_MODE_CLK);
    PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);
    PRCMPeripheralClkEnable(PRCM_GPIOA3, PRCM_RUN_MODE_CLK);
    PRCMPeripheralClkEnable(PRCM_GSPI, PRCM_RUN_MODE_CLK);

    // PIN_58 = Chip select (OC)
    // PIN_03 = DC
    // PIN_18 = Reset (R)
    PinTypeGPIO(PIN_58, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA0_BASE, 0x8, GPIO_DIR_MODE_OUT);

    PinTypeGPIO(PIN_03, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA1_BASE, 0x10, GPIO_DIR_MODE_OUT);

    PinTypeGPIO(PIN_18, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA3_BASE, 0x10, GPIO_DIR_MODE_OUT);

    // PIN_50 = SPI_CS (This is the useless one TI does)
    PinTypeSPI(PIN_50, PIN_MODE_9);

    // PIN_05  = SPI_CLK (CL)
    PinTypeSPI(PIN_05, PIN_MODE_7);

    //  PIN_06 = SPI_MISO (Don't care)
    PinTypeSPI(PIN_06, PIN_MODE_7);

    // PIN_07 = SPI_MOSI (SI)
    PinTypeSPI(PIN_07, PIN_MODE_7);
}
