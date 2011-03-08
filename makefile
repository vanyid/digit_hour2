
CC := picc18
PROC := --chip=18F4520

SOURCE_DIR := ./Source
FUNCTION_DIR := $(SOURCE_DIR)/Function
PLATFORM_DIR := $(SOURCE_DIR)/Platform
OUTPUT_DIR := $(SOURCE_DIR)/Builds
TARGER_DIR := $(OUTPUT_DIR)

PLATFORM_MAKEFILE := $(PLATFORM_DIR)/makefile.mk
FUNCTION_MAKEFILE := $(FUNCTION_DIR)/makefile.mk

#SUBDIRS := $(SOURCE_DIR)/
#SOURCES := $(PLATFORM_DIR)/main.c

include $(PLATFORM_MAKEFILE)
include $(FUNCTION_MAKEFILE)


##################################
# Rules
##################################
.PHONY: all

all : 
#	$(CC) $(PROC) $(addprefix -I, $(SUBDIRS)) $(addprefix -c ,$(SOURCES))
	$(CC) $(PROC) $(addprefix -I, $(SUBDIRS)) $(SOURCES)
	
