#ifndef ENC28J60_H
#define ENC28J60_H

// Macro to define a specific bit
#define BIT(n) (1 << (n)) // Shifts 1 by n positions to create a bitmask for the nth bit

/* Register Addresses */

// PHY Register Addresses
#define PHCON1  0x00  // Physical Control Register 1
#define PHSTAT1 0x01  // Physical Status Register 1
#define PHID1   0x02  // Physical Identifier Register 1
#define PHID2   0x03  // Physical Identifier Register 2
#define PHCON2  0x10  // Physical Control Register 2
#define PHSTAT2 0x11  // Physical Status Register 2
#define PHIE    0x12  // Physical Interrupt Enable Register
#define PHIR    0x13  // Physical Interrupt Register
#define PHLCON  0x14  // Physical LED Control Register


/* Bit and Offset Definitions */

// PHCON1 Bit Definitions
#define PHCON1_PRST       BIT(15) // PHY Software Reset bit (1 = Processing reset, 0 = Normal operation)
#define PHCON1_PLOOPBK    BIT(14) // PHY Loopback bit (1 = Loopback enabled, 0 = Normal operation)
#define PHCON1_PPWRSV     BIT(11) // PHY Power-Down bit (1 = Shut down, 0 = Normal operation)
#define PHCON1_PDPXMD     BIT(8)  // PHY Duplex Mode bit (1 = Full-duplex, 0 = Half-duplex)

// PHSTAT1 Bit Definitions
#define PHSTAT1_PFDPX     BIT(12) // PHY Full-Duplex Capable bit (1 = Capable of 10 Mbps in Full-Duplex mode, always set)
#define PHSTAT1_PHDPX     BIT(11) // PHY Half-Duplex Capable bit (1 = Capable of 10 Mbps in Half-Duplex mode, always set)
#define PHSTAT1_LLSTAT    BIT(2)  // PHY Latching Link Status bit (1 = Link is up continuously since last read, 0 = Link is or was down)
#define PHSTAT1_JBSTAT    BIT(1)  // PHY Latching Jabber Status bit (1 = Jabber detected since last read, 0 = No jabber detected since last read)

// PHCON2 Bit Definitions
#define PHCON2_FRCLNK     BIT(14) // PHY Force Linkup bit (1 = Force linkup even if no partner detected, 0 = Normal operation)
#define PHCON2_TXDIS      BIT(13) // Twisted-Pair Transmitter Disable bit (1 = Disable transmitter, 0 = Normal operation)
#define PHCON2_JABBER     BIT(10) // Jabber Correction Disable bit (1 = Disable jabber correction, 0 = Normal operation)
#define PHCON2_HDLDIS     BIT(8)  // Half-Duplex Loopback Disable (ignored if PHCON1<8>=1 or <14>=1, else 1=twisted-pair only, 0=loopback+twisted-pair)

// PHSTAT2 Bit Definitions
#define PHSTAT2_TXSTAT    BIT(13) // PHY Transmit Status bit (1 = PHY is transmitting data, 0 = PHY is not transmitting data)
#define PHSTAT2_RXSTAT    BIT(12) // PHY Receive Status bit (1 = PHY is receiving data, 0 = PHY is not receiving data)
#define PHSTAT2_COLSTAT   BIT(11) // PHY Collision Status bit (1 = Collision is occurring, 0 = No collision is occurring)
#define PHSTAT2_LSTAT     BIT(10) // PHY Link Status bit (1 = Link is up, 0 = Link is down)
#define PHSTAT2_DPXSTAT   BIT(9)  // PHY Duplex Status bit (1 = Full-duplex operation, 0 = Half-duplex operation)
#define PHSTAT2_PLRITY    BIT(4)  // Polarity Status bit (1 = Signal polarity is reversed, 0 = Signal polarity is correct)

// PHIE Bit Definitions
#define PHIE_PLNKIE       BIT(4) // PHY Link Change Interrupt Enable (1 = Enabled, 0 = Disabled)
#define PHIE_PGEIE        BIT(1) // PHY Global Interrupt Enable (1 = Interrupts enabled, 0 = Interrupts disabled)

// PHIR Bit Definitions
#define PHIR_PLNKIF       BIT(4) // PHY Link Change Interrupt Flag (1 = Link status changed since last read, 0 = No change)
#define PHIR_PGIF         BIT(2) // PHY Global Interrupt Flag (1 = One or more interrupts occurred since last read, 0 = None)

// PHLCON Bit Definitions and Offsets
#define PHLCON_LACFG      (BIT(11) | BIT(10) | BIT(9) | BIT(8)) // LEDA Configuration bits (Controls LEDA behavior)
#define PHLCON_LACFG_O    8 // Offset for LEDA Configuration bits

#define PHLCON_LBCFG      (BIT(7) | BIT(6) | BIT(5) | BIT(4)) // LEDB Configuration bits (Controls LEDB behavior)
#define PHLCON_LBCFG_O    4 // Offset for LEDB Configuration bits

#define PHLCON_LFRQ       (BIT(3) | BIT(2)) // LED Pulse Stretch Time Configuration bits (Sets pulse stretch timing)
#define PHLCON_LFRQ_O     2 // Offset for LED Pulse Stretch Time Configuration bits

#define PHLCON_STRCH      BIT(1) // LED Pulse Stretching Enable bit (1 = Enable pulse stretching, 0 = Display events as they occur)


/* Value Definitions */

// LACFG<3:0>: LEDA Configuration bits (PHLCON bits 11-8)
#define PHLCON_LACFG_RESERVED      0xF  // 1111 - Reserved
#define PHLCON_LACFG_DUPLEX_COL    0xE  // 1110 - Display duplex status and collision activity (always stretched)
#define PHLCON_LACFG_LINK_TXRX     0xD  // 1101 - Display link status and transmit/receive activity (always stretched)
#define PHLCON_LACFG_LINK_RX       0xC  // 1100 - Display link status and receive activity (always stretched)
#define PHLCON_LACFG_BLINK_SLOW    0xB  // 1011 - Blink slow
#define PHLCON_LACFG_BLINK_FAST    0xA  // 1010 - Blink fast
#define PHLCON_LACFG_OFF           0x9  // 1001 - Off
#define PHLCON_LACFG_ON            0x8  // 1000 - On
#define PHLCON_LACFG_TXRX_ACT      0x7  // 0111 - Display transmit and receive activity (stretchable)
#define PHLCON_LACFG_DUPLEX        0x5  // 0101 - Display duplex status
#define PHLCON_LACFG_LINK          0x4  // 0100 - Display link status
#define PHLCON_LACFG_COLLISION     0x3  // 0011 - Display collision activity (stretchable)
#define PHLCON_LACFG_RX_ACT        0x2  // 0010 - Display receive activity (stretchable)
#define PHLCON_LACFG_TX_ACT        0x1  // 0001 - Display transmit activity (stretchable)
#define PHLCON_LACFG_RESERVED_LOW  0x0  // 0000 - Reserved

// LBCFG<3:0>: LEDB Configuration bits (PHLCON bits 7-4)
#define PHLCON_LBCFG_DUPLEX_COL    0xE  // 1110 - Display duplex status and collision activity (always stretched)
#define PHLCON_LBCFG_LINK_TXRX     0xD  // 1101 - Display link status and transmit/receive activity (always stretched)
#define PHLCON_LBCFG_LINK_RX       0xC  // 1100 - Display link status and receive activity (always stretched)
#define PHLCON_LBCFG_BLINK_SLOW    0xB  // 1011 - Blink slow
#define PHLCON_LBCFG_BLINK_FAST    0xA  // 1010 - Blink fast
#define PHLCON_LBCFG_OFF           0x9  // 1001 - Off
#define PHLCON_LBCFG_ON            0x8  // 1000 - On
#define PHLCON_LBCFG_TXRX_ACT      0x7  // 0111 - Display transmit and receive activity (stretchable)
#define PHLCON_LBCFG_DUPLEX        0x5  // 0101 - Display duplex status
#define PHLCON_LBCFG_LINK          0x4  // 0100 - Display link status
#define PHLCON_LBCFG_COLLISION     0x3  // 0011 - Display collision activity (stretchable)
#define PHLCON_LBCFG_RX_ACT        0x2  // 0010 - Display receive activity (stretchable)
#define PHLCON_LBCFG_TX_ACT        0x1  // 0001 - Display transmit activity (stretchable)
#define PHLCON_LBCFG_RESERVED_LOW  0x0  // 0000 - Reserved

// LFRQ<1:0>: LED Pulse Stretch Time Configuration bits (PHLCON bits 3-2)
#define PHLCON_LFRQ_RESERVED       0x3  // 11 - Reserved
#define PHLCON_LFRQ_TLSTRCH        0x2  // 10 - Stretch LED events by TLSTRCH
#define PHLCON_LFRQ_TMSTRCH        0x1  // 01 - Stretch LED events by TMSTRCH
#define PHLCON_LFRQ_TNSTRCH        0x0  // 00 - Stretch LED events by TNSTRCH

// STRCH: LED Pulse Stretching Enable bit (PHLCON bit 1)
#define PHLCON_STRCH_ENABLED       0x1  // 1 - Stretchable LED events will cause lengthened LED pulses
#define PHLCON_STRCH_DISABLED      0x0  // 0 - Stretchable LED events will only be displayed while occurring

#endif