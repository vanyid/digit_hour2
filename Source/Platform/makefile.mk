 

SUBDIRS += $(PLATFORM_DIR)/  \
           $(PLATFORM_DIR)/isr  \
           $(PLATFORM_DIR)/OUTD_OutputDriver  \
           $(PLATFORM_DIR)/TSCHED_TaskScheduler  \
           

SOURCES += $(PLATFORM_DIR)/main.c  \
           $(PLATFORM_DIR)/isr/isr_main.c  \
           $(PLATFORM_DIR)/OUTD_OutputDriver/outd_main.c  \
           $(PLATFORM_DIR)/TSCHED_TaskScheduler/tsched_main.c \
           $(PLATFORM_DIR)/task.c  \

