/* --------0.Project information--------------------
 * SRF05 Module Distance Measurement
 * Author : TRAN MINH THUAN
 * Date: May 9th 2019
 * Project associate with TM4C123, CCS version 9.
---------------------------------------------------*/


/* --------1.System requirement---------------------
Using mode 1 of SRF05 to get the distance of obstacles (Mode 1)
FB0 - Trigger pin
FB1 - Echo pin

---------------------------------------------------*/



////// ----------------2. Pre-processor Directives Section--------------------///////
#include <UserLibraries/Userlibs.h>
#define IR_GPIO_PORT    GPIO_PORTB_BASE
#define IR0_PIN         GPIO_PIN_0
#define IR1_PIN         GPIO_PIN_1
#define IR2_PIN         GPIO_PIN_2
#define IR3_PIN         GPIO_PIN_3
#define IR4_PIN         GPIO_PIN_4

#define DATA_PB_R       HWREG(0x400053FC)

#define LEFT100         30
#define LEFT75          28
#define LEFT50          29
#define LEFT25          25
#define BALANCED        27
#define OFFLINE         31
#define RIGHT25         19
#define RIGHT50         23
#define RIGHT75         7
#define RIGH100         15

//////------------------------------------------------------------------------///////

////// ----------------3.Global Declarations Section--------------------------///////
void                IR_GPIO_Init(void);
unsigned char       Get_Status(void);
unsigned char       ui8_test=0;
//////------------------------------------------------------------------------///////

////// ----------------4. Subroutines Section---------------------------------///////
void main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_2_5| SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //80MHz
    IR_GPIO_Init();
    while(1)
    {
        ui8_test=Get_Status();
    }
}

void                IR_GPIO_Init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));
    GPIOPinTypeGPIOInput(IR_GPIO_PORT, IR0_PIN|IR1_PIN|IR2_PIN|IR3_PIN|IR4_PIN);
}

unsigned char       Get_Status(void)
{
    uint8_t ui8_value;
    ui8_value= DATA_PB_R& 0x1F;
    return ui8_value;
}

//////------------------------------------------------------------------------///////
