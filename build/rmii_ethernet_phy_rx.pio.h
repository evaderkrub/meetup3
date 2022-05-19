// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ------------------------- //
// rmii_ethernet_phy_rx_data //
// ------------------------- //

#define rmii_ethernet_phy_rx_data_wrap_target 6
#define rmii_ethernet_phy_rx_data_wrap 6

static const uint16_t rmii_ethernet_phy_rx_data_program_instructions[] = {
    0x2022, //  0: wait   0 pin, 2                   
    0x2020, //  1: wait   0 pin, 0                   
    0x2021, //  2: wait   0 pin, 1                   
    0x20a2, //  3: wait   1 pin, 2                   
    0x20a0, //  4: wait   1 pin, 0                   
    0x20a1, //  5: wait   1 pin, 1                   
            //     .wrap_target
    0x4002, //  6: in     pins, 2                    
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program rmii_ethernet_phy_rx_data_program = {
    .instructions = rmii_ethernet_phy_rx_data_program_instructions,
    .length = 7,
    .origin = -1,
};

static inline pio_sm_config rmii_ethernet_phy_rx_data_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + rmii_ethernet_phy_rx_data_wrap_target, offset + rmii_ethernet_phy_rx_data_wrap);
    return c;
}

static inline void rmii_ethernet_phy_rx_init(PIO pio, uint sm, uint offset, uint pin) {
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 3, false);
    pio_sm_config c = rmii_ethernet_phy_rx_data_program_get_default_config(offset);
    sm_config_set_in_pins(&c, pin);
    pio_gpio_init(pio, pin);
    pio_gpio_init(pio, pin + 1);
    pio_gpio_init(pio, pin + 2);
    sm_config_set_in_shift(&c, true, true, 8);
    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
    sm_config_set_clkdiv(&c, 10);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

#endif

