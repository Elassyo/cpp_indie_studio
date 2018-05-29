##
## EPITECH PROJECT, 2018
## cpp_indie_studio
## File description:
## Makefile
##

NAME		=	bomberman

BUILD_DIR	=	cmake-build-debug

CMAKE		=	cmake
MKDIR		=	mkdir
RM		=	rm -rf

all: $(NAME)

cmake-gen:
	cd $(BUILD_DIR) && \
	$(CMAKE) -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug $(SRC_DIR)

$(BUILD_DIR):
	$(MKDIR) $@
	$(MAKE) -C . SRC_DIR=$(abspath .) cmake-gen

$(NAME): | $(BUILD_DIR)
	$(CMAKE) --build $(BUILD_DIR) --target $@
	cp $(BUILD_DIR)/$@ $@

install: | $(BUILD_DIR)
	$(CMAKE) --build $(BUILD_DIR) --target install

clean: | $(BUILD_DIR)
	$(CMAKE) --build $(BUILD_DIR) --target clean

fclean:
	$(RM) $(BUILD_DIR)

re: fclean all

.PHONY:	all cmake-gen clean fclean re core
