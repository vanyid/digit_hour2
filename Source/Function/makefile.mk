 

SUBDIRS += $(FUNCTION_DIR)/CT_ClockTimer \
           $(FUNCTION_DIR)/UPD_UpdateDigits \
           $(FUNCTION_DIR)/HMI_HumanMaschineInterface \
           $(FUNCTION_DIR)/HMI_HumanMaschineInterface/SLT_SetLocalTime \
           

SOURCES += $(FUNCTION_DIR)/CT_ClockTimer/ct_main.c \
           $(FUNCTION_DIR)/UPD_UpdateDigits/upd_main.c \
           $(FUNCTION_DIR)/HMI_HumanMaschineInterface/hmi_main.c \
           $(FUNCTION_DIR)/HMI_HumanMaschineInterface/SLT_SetLocalTime/slt_main.c \
           