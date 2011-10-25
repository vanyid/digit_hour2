
MKDIR := mkdir -p
ECHO := echo
CC := picc18
PERL := perl
CAT := cat
MV := mv
RM := rm


PROC := --chip=18F4520
CC_SWITCHES := --opt=all -Q

ifeq "$(MAKECMDGOALS)" ""
TARGET := ora
endif
ifeq "$(MAKECMDGOALS)" "all"
TARGET := ora
endif

TARGET_NAME := $(TARGET)

SOURCE_DIR := ./Source
FUNCTION_DIR := $(SOURCE_DIR)/Function
PLATFORM_DIR := $(SOURCE_DIR)/Platform
OUTPUT_DIR := ./Builds
TARGET_DIR := $(OUTPUT_DIR)
DEP_DIR := $(TARGET_DIR)/dep
OBJ_DIR := $(TARGET_DIR)/obj
SCRIPTS := ./Scripts

TARGET_HEX := $(OUTPUT_DIR)/$(addsuffix .hex, $(TARGET_NAME))

MAKEFILE := makefile
PLATFORM_MAKEFILE := $(PLATFORM_DIR)/makefile.mk
FUNCTION_MAKEFILE := $(FUNCTION_DIR)/makefile.mk

#SUBDIRS := $(SOURCE_DIR)/
#SOURCES := $(PLATFORM_DIR)/main.c

include $(PLATFORM_MAKEFILE)
include $(FUNCTION_MAKEFILE)

PICC18_DEP_GEN := $(SCRIPTS)/picc18_dep.pl

DEP_FILES := $(addprefix $(DEP_DIR)/, \
              $(notdir               \
                $(subst .c,.dep,$(filter %.c, $(SOURCES)))))

OBJ_FILES := $(addprefix $(OBJ_DIR)/, \
              $(notdir               \
                $(subst .c,.p1,$(filter %.c, $(SOURCES)))))

vpath %.c $(SUBDIRS)

#################################
# Macros
#################################
#$(call make-depend,source-file,object-file,depend-file,options)
# options: GCC with perl preprocess, GCC with SED preprocess, Cosmic with postprocess
#	perl $(GCC_DEP_GEN) -src_file=$1 | $(GCC) -E -MM -MF $3 -MT $2 -MT $3 -MP $4 -
#  $(SED) -e's/#asm//' -e's/#endasm//' $1 | $(GCC) -E -MM -MF $3 -MT $2 -MT $3 -MP $4 -
define make-depend
	$(CC) $(PROC) $(CC_SWITCHES) --OUTDIR=$(DEP_DIR) $(addprefix -I, $(SUBDIRS)) $(DEFINES) --scandep $1; \
	$(MV) $3 temp.dep; \
	$(CAT) temp.dep | $(PERL) -n -s $(PICC18_DEP_GEN) -dep_file=$3 -obj_file=$2 > $3; \
	$(RM) temp.dep
endef

#$(call check_and_create_dir,directory)
define check_and_create_dir
	if [ ! -d $1 ]; then \
		$(MKDIR) $1; \
		fi;
endef

#$(call check_and_create_dir,directory)
define check_and_create_dir
	if [ ! -d $1 ]; then \
		$(MKDIR) $1; \
		fi;
endef

##################################
# Rules
##################################
.PHONY: all clean

clean:
	$(RM) -R $(OUTPUT_DIR)

all : $(MAKEFILE) $(DEP_FILES) $(OBJ_FILES) $(TARGET_HEX)
	@$(ECHO) "#Success!"
#	$(CC) $(PROC) $(addprefix -I, $(SUBDIRS)) $(addprefix -c ,$(SOURCES))
#	$(CC) $(PROC) $(CC_SWITCHES) $(addprefix -I, $(SUBDIRS)) $(SOURCES)
	
$(OBJ_DIR)/%.p1: %.c 
	@$(call check_and_create_dir,$(OBJ_DIR))
#	@$(RM) $@ $(OBJ_DIR)/$(subst .c,.lst,$(notdir $<)) $(OBJ_DIR)/$(subst .c,.pre,$(notdir $<))
	@$(ECHO) "#Compiling $<"
	@$(CC) $(PROC) $(CC_SWITCHES) --OUTDIR=$(OBJ_DIR) --pass1 $(addprefix -I, $(SUBDIRS)) $<

$(DEP_DIR)/%.dep: %.c  
	@$(call check_and_create_dir,$(DEP_DIR))
	@$(ECHO) "#Dependency $<" 
#	@$(ECHO) "$(call make-depend,$<,$(addprefix $(OBJ_DIR)/,$(subst .c,.o, $(notdir $<))),$@)"
	@$(call make-depend,$<,$(addprefix $(OBJ_DIR)/,$(subst .c,.p1, $(notdir $<))),$@)

$(TARGET_HEX): $(OBJ_FILES) $(MAKEFILE) $(PLATFORM_MAKEFILE) $(PLATFORM_MAKEFILE)
	@$(ECHO) "Linking $@"
	@$(CC) $(PROC) $(CC_SWITCHES) -O$(OBJ_DIR)/$(notdir $(TARGET_HEX)) $(OBJ_FILES)
	@if [ ! -f $(TARGET_HEX) ]; then $(MV) $(OBJ_DIR)/$(notdir $(TARGET_HEX)) $(TARGET_HEX); fi;

ifneq "$(MAKECMDGOALS)" "clean"
include $(DEP_FILES)
endif
