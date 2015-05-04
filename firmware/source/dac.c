
#include "dac.h"

#include <stdint.h>

#include "em_cmu.h"
#include "em_dac.h"

void DAC_init() 
{
    DAC_Init_TypeDef dac_init = DAC_INIT_DEFAULT;
    DAC_InitChannel_TypeDef channel_init = DAC_INITCHANNEL_DEFAULT

    CMU_ClockEnable(cmuClockDAC0, true);

    //Todo: fine tuned config here

    DAC_Init(DAC_DEVICE, &dac_init);
    DAC_InitChannel(DAC_DEVICE, &channel_init);
}

void DAC_close()
{
    ADC_Reset(DAC_DEVICE);

    CMU_ClockEnable(cmuClockADC0, false);
}

void DAC_enable(bool enable) 
{
    DAC_Enable(DAC_DEVICE, DAC_CHANNEL, enable);
}

void DAC_write(uint32_t value) 
{
    if(DAC_CHANNEL == 0) {
        DAC_Channel0OutputSet(DAC_DEVICE, value);
    } else if(DAC_CHANNEL == 1)  {
        DAC_Channel1OutputSet(DAC_DEVICE, value);
    }
}