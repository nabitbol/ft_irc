# #############################################################################
#
# Sources lists
#
# #############################################################################

# Project name
NAME		=	ircserv

CC			=	c++

# CPP files
SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d)
TEM_DIR		=	$(shell find templates -type d)
OBJ_DIR		=	bin/obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRC			=	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.opp))

# #############################################################################
#
# Compiler options
#
# #############################################################################

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

TFLAGS		=	$(foreach dir, $(TEM_DIR), -I $(dir))

# #############################################################################
#
# Rules
#
# #############################################################################

.DEFAULT_GOAL = all

# Build target
$(NAME): $(OBJ)
	@echo -e "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@mv ircserv bin
	@echo -e "$(_GREEN)DONE$(_NC)\n-----"

# Build obj binaries
$(OBJ_DIR)/%.opp: %.cpp
	@echo -e "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo -e "$(_GREEN)DONE$(_WHITE)"

# Build all targets
all: $(NAME)

# Show macro details
show:
	@echo -e "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo -e "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo -e "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo -e "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo -e "$(_BLUE)TFLAGS :\n$(_YELLOW)  $(TFLAGS)$(NC)\n"
	@echo -e "\n-----\n"
	@echo -e "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(_WHITE)"


# Remove objects
clean:
	@echo -e "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo -e "$(_GREEN)DONE$(_WHITE)\n-----"

# Remove every built binary
fclean: clean
	@echo -e "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -rf bin/
	@echo -e "$(_GREEN)DONE$(_WHITE)\n-----"

# Remove and rebuild everything
re: fclean all

.PHONY: all show clean fclean re

.ONESHELL:

# #############################################################################
#
# Makefile misc
#
# #############################################################################

# Colors
_GREY=   $(shell tput setaf 0)
_RED=    $(shell tput setaf 1)
_GREEN=  $(shell tput setaf 2)
_YELLOW= $(shell tput setaf 3)
_BLUE=   $(shell tput setaf 4)
_PURPLE= $(shell tput setaf 5)
_CYAN=   $(shell tput setaf 6)
_WHITE=  $(shell tput setaf 7)
_NC=     $(shell tput sgr0) 

# Colored messages
SUCCESS=$(GREEN)SUCCESS$(NC)
COMPILING=$(_BLUE)COMPILING$(NC)

# #############################################################################
