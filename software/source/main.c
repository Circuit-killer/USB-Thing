
#include <stdio.h>
#include <unistd.h>

#include "usbthing.h"

int main(int argc, char **argv)
{
    struct usbthing_s usbthing;
    int res;

    USBTHING_init();

    res = USBTHING_list_devices(0x0001, 0x0001);

setup:

    res = USBTHING_connect(&usbthing, 0x0001, 0x0001);
    if (res < 0) {
        printf("Error opening USB thing\n");
        goto teardown;
    }

    /* TODO: actual things */
    printf("Connected\n");

    USBTHING_get_firmware_version(&usbthing, NULL, NULL);

    unsigned char data_out[] = "tick";
    unsigned char data_in[sizeof(data_out)];
    USBTHING_spi_transfer(&usbthing, data_out, data_in, sizeof(data_out));
    USBTHING_i2c_transfer(&usbthing, data_out, data_in, sizeof(data_out));

    USBTHING_led_set(&usbthing, 0, 1);

    sleep(1);

    USBTHING_led_set(&usbthing, 0, 0);



teardown:

    res = USBTHING_disconnect(&usbthing);
    if (res < 0) {
        printf("Error closing USB thing\n");
    }

    printf("Disconnected\n");

    USBTHING_close();

    return 0;
}

