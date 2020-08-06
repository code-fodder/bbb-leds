#######################################################################
# Include the common makefiles:
#   - Variables:     Sets up the variables with some default values
include make_utils/common_targets.mk
#######################################################################

.PHONY: install
install:
	make target_bbb
	scp bin/leds_bbbd  root@bbb:/root/testing
