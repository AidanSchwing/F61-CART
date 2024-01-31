#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"
#include "stm32nucleof7xx_init_board.h"
#include "MW_MbedPinInterface.h"
#include "SysTickScheduler.h"
#include "arm_cortex_m_multitasking.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE STM32 Nucleo F746ZG
#define MW_CONNECTIONINFO_SERIAL_BAUDRATE 115200
#define MW_CONNECTIONINFO_SERIAL_COMPORT COM10
#define MW_CONNECTIONINFO_SERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.stmmbed.internal.EthernetConfigIPAddressExternalMode
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 1
#define MW_EXTMODE_CONFIGURATION serial
#define MW_EXTMODE_SIGNALBUFFERSIZE 2000.000000
#define MW_EXTMODE_USEREALTIMESTAMPLOGGING 0
#define MW_EXTMODE_RUNNING on
#define MW_RTOS Baremetal
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_HOSTDRIVE_SET_HOST_DRIVE 0
#define MW_HOSTDRIVE_DRIVE F:
#define MW_HOSTCOMPORT_COM_PORT_NUMBER COM10
#define MW_SIMULINKIO_TRANSPORTLAYERTYPE 0
#define MW_SIMULINKIO_MODELTRANSPORTDATAFCN codertarget.simulinkIO.stmnucleo.getModelTransportInfo
#define MW_SIMULINKIO_SERVERDEPLOYFCN codertarget.simulinkIO.stmnucleo.updateServer
#define MW_CLOCKING_CPUCLOCKRATEMHZ 216
#define MW_ETHERNET_DHCPENABLED 1
#define MW_ETHERNET_HOSTNAME DIS_F746NG
#define MW_ETHERNET_LOCALIPADDRESS 192.168.1.10
#define MW_ETHERNET_SUBNETMASK 255.255.255.0
#define MW_ETHERNET_GATEWAY 192.168.1.1
#define MW_ETHERNET_MACADDR 00-80-E1-00-00-00
#define MW_I2C0_BUSSPEEDHZ 100000
#define MW_I2C0_SCL_INDEX 0
#define MW_I2C0_SDA_INDEX 0
#define MW_I2C0_SCL D15
#define MW_I2C0_SDA D14
#define MW_I2C2_BUSSPEEDHZ 100000
#define MW_I2C2_SCL_INDEX 0
#define MW_I2C2_SDA_INDEX 0
#define MW_I2C2_SCL PB_10
#define MW_I2C2_SDA PB_11
#define MW_I2C3_BUSSPEEDHZ 100000
#define MW_I2C3_SCL_INDEX 0
#define MW_I2C3_SDA_INDEX 0
#define MW_I2C3_SCL PA_8
#define MW_I2C3_SDA PC_9
#define MW_I2C4_BUSSPEEDHZ 100000
#define MW_I2C4_SCL_INDEX 0
#define MW_I2C4_SDA_INDEX 0
#define MW_I2C4_SCL PF_14
#define MW_I2C4_SDA PF_15
#define MW_SPI0_BUSSPEEDHZ 1000000
#define MW_SPI0_MOSIPIN_INDEX 0
#define MW_SPI0_MISOPIN_INDEX 0
#define MW_SPI0_SCKPIN_INDEX 0
#define MW_SPI0_MOSIPIN D11
#define MW_SPI0_MISOPIN D12
#define MW_SPI0_SCKPIN D13
#define MW_SPI2_BUSSPEEDHZ 1000000
#define MW_SPI2_MOSIPIN_INDEX 0
#define MW_SPI2_MISOPIN_INDEX 0
#define MW_SPI2_SCKPIN_INDEX 0
#define MW_SPI2_MOSIPIN PB_15
#define MW_SPI2_MISOPIN PC_2
#define MW_SPI2_SCKPIN PB_13
#define MW_SPI3_BUSSPEEDHZ 1000000
#define MW_SPI3_MOSIPIN_INDEX 0
#define MW_SPI3_MISOPIN_INDEX 0
#define MW_SPI3_SCKPIN_INDEX 0
#define MW_SPI3_MOSIPIN PC_12
#define MW_SPI3_MISOPIN PC_11
#define MW_SPI3_SCKPIN PC_10
#define MW_SPI4_BUSSPEEDHZ 1000000
#define MW_SPI4_MOSIPIN_INDEX 0
#define MW_SPI4_MISOPIN_INDEX 0
#define MW_SPI4_SCKPIN_INDEX 0
#define MW_SPI4_MOSIPIN PE_14
#define MW_SPI4_MISOPIN D3
#define MW_SPI4_SCKPIN PE_12
#define MW_SCI1_BAUDRATE 115200
#define MW_SCI1_RXPIN_INDEX 0
#define MW_SCI1_TXPIN_INDEX 0
#define MW_SCI1_DATABITS 8
#define MW_SCI1_PARITY 0.000000
#define MW_SCI1_STOPBITS 1.000000
#define MW_SCI1_RXPIN PA_10
#define MW_SCI1_TXPIN PB_6
#define MW_SCI2_BAUDRATE 115200
#define MW_SCI2_RXPIN_INDEX 0
#define MW_SCI2_TXPIN_INDEX 0
#define MW_SCI2_DATABITS 8
#define MW_SCI2_PARITY 0.000000
#define MW_SCI2_STOPBITS 1.000000
#define MW_SCI2_RXPIN PD_6
#define MW_SCI2_TXPIN PD_5
#define MW_SCI0_BAUDRATE 115200
#define MW_SCI0_RXPIN_INDEX 0
#define MW_SCI0_TXPIN_INDEX 0
#define MW_SCI0_DATABITS 8
#define MW_SCI0_PARITY 0.000000
#define MW_SCI0_STOPBITS 1.000000
#define MW_SCI0_RXPIN PB_11
#define MW_SCI0_TXPIN PB_10
#define MW_SCI4_BAUDRATE 115200
#define MW_SCI4_RXPIN_INDEX 0
#define MW_SCI4_TXPIN_INDEX 0
#define MW_SCI4_DATABITS 8
#define MW_SCI4_PARITY 0.000000
#define MW_SCI4_STOPBITS 1.000000
#define MW_SCI4_RXPIN PC_11
#define MW_SCI4_TXPIN PA_0
#define MW_SCI5_BAUDRATE 115200
#define MW_SCI5_RXPIN_INDEX 0
#define MW_SCI5_TXPIN_INDEX 0
#define MW_SCI5_DATABITS 8
#define MW_SCI5_PARITY 0.000000
#define MW_SCI5_STOPBITS 1.000000
#define MW_SCI5_RXPIN PD_2
#define MW_SCI5_TXPIN PC_12
#define MW_SCI6_BAUDRATE 115200
#define MW_SCI6_RXPIN_INDEX 0
#define MW_SCI6_TXPIN_INDEX 0
#define MW_SCI6_DATABITS 8
#define MW_SCI6_PARITY 0.000000
#define MW_SCI6_STOPBITS 1.000000
#define MW_SCI6_RXPIN PC_7
#define MW_SCI6_TXPIN PC_6
#define MW_SCI7_BAUDRATE 115200
#define MW_SCI7_RXPIN_INDEX 0
#define MW_SCI7_TXPIN_INDEX 0
#define MW_SCI7_DATABITS 8
#define MW_SCI7_PARITY 0.000000
#define MW_SCI7_STOPBITS 1.000000
#define MW_SCI7_RXPIN PE_7
#define MW_SCI7_TXPIN PE_8
#define MW_SCI8_BAUDRATE 115200
#define MW_SCI8_RXPIN_INDEX 0
#define MW_SCI8_TXPIN_INDEX 0
#define MW_SCI8_DATABITS 8
#define MW_SCI8_PARITY 0.000000
#define MW_SCI8_STOPBITS 1.000000
#define MW_SCI8_RXPIN PE_0
#define MW_SCI8_TXPIN PE_1
#define MW_RS485_RS485_SERIAL 0
#define MW_RS485_RS485_DEPIN 8
#define MW_RS485_RS485_REPIN 9
#define MW_MODBUS_MODBUS_COMMS 0
#define MW_MODBUS_MODBUS_MODE 0
#define MW_MODBUS_MODBUS_SERVERID 1
#define MW_MODBUS_MODBUS_CONFIGCOIL 49
#define MW_MODBUS_MODBUS_COILADDR 0
#define MW_MODBUS_MODBUS_COILNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUT 49
#define MW_MODBUS_MODBUS_INPUTADDR 0
#define MW_MODBUS_MODBUS_INPUTNUM 1
#define MW_MODBUS_MODBUS_CONFIGHOLDINGREG 49
#define MW_MODBUS_MODBUS_HOLDINGREGADDR 0
#define MW_MODBUS_MODBUS_HOLDINGREGNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUTREG 49
#define MW_MODBUS_MODBUS_INPUTREGADDR 0
#define MW_MODBUS_MODBUS_INPUTREGNUM 1
#define MW_MODBUS_MODBUS_CLIENTTIMEOUT 100
#define MW_THINGSPEAK_CONNECTTIMEOUT 3
#define MW_THINGSPEAK_WRITEBLOCKSRESPONSETIMEOUT 1
#define MW_THINGSPEAK_READBLOCKSRESPONSETIMEOUT 5
#define MW_PIL_INTERFACE 0
#define MW_PIL_COMPORT COM2
#define MW_SENSOR_FILELOCATION codertarget.mbed.internal
#define MW_IOBLOCKSMODE deployed
#define MW_DATAVERSION 2016.02

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
