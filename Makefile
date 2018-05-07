##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Global Makefile
##

BINARY_NAME	= bomberman

BUILD_DIR	= build
DEST		= .

RM		= rm -f
MKDIR		= mkdir -p

all:	${BINARY_NAME}

cmake:	| $(BUILD_DIR)
	(cd $(BUILD_DIR) && cmake ..)

$(BINARY_NAME):	cmake | $(BUILD_DIR)
	make -C $(BUILD_DIR) bomberman
	cp $(BUILD_DIR)/bomberman ${BINARY_NAME}

$(BUILD_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(BUILD_DIR)

fclean:	clean
	$(RM) ${BINARY_NAME}

re:	fclean all

.PHONY:	all cmake clean fclean re core
