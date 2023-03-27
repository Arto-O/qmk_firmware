ifeq ($(MCU),atmega32u4)
	# Space saving settings.
	TAP_DANCE_ENABLE = no
	COMBO_ENABLE = no
	QMK_SETTINGS = no
else ifeq ($(MCU),STM32F411)
	EEPROM_DRIVER = vendor
endif

CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
