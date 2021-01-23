#ifndef __CONFIG_H
#define __CONFIG_H

#ifndef CONFIG_SPIDEV_FILENAME
#define CONFIG_SPIDEV_FILENAME "/dev/spidev0.0"
#endif

#ifndef CONFIG_GPIO_CONSUMER
#define CONFIG_GPIO_CONSUMER "jlx_lcd"
#endif

#ifndef CONFIG_GPIO_CHIP
#define CONFIG_GPIO_CHIP "/dev/gpiochip0"
#endif

#ifndef CONFIG_RES_PIN
#define CONFIG_RES_PIN 27
#endif

#ifndef CONFIG_DC_PIN
#define CONFIG_DC_PIN 25
#endif

#endif