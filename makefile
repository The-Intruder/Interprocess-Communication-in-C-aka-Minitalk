################################################################################
################################################################################
##                                                                            ##
##       ███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗       ##
##       ████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝       ##
##       ██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗         ##
##       ██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝         ##
##       ██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗       ##
##       ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝       ##
##                                                                            ##
################################################################################
################################################################################

############################# Terminal Color Codes #############################

NC := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

################################################################################

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror
CC_OPTS := -Lft_printf/ -lftprintf

HEADER := minitalk.h
NAME := libminitalk.a

################################################################################

.PHONY: all clean fclean re ${NAME} compile-server compile-client compile-all \
	compile-bonus compile-client-bonus compile-server-bonus compile-bonus;

all: ${NAME}

${NAME}: minitalk.h
	@make -C ft_printf/

clean:
	@echo "\n${RED}Cleaning up Object files ...\n${NC}"
	@rm -f *.o ft_printf/*.o

fclean: clean
	@echo "${RED}Cleaning up Archive files ...\n${NC}"
	@rm -f ${NAME} ft_printf/*.a

re: exclean all

bonus: re

################################################################################

exclean: fclean
	@echo "${RED}Cleaning up Executable files ...\n${NC}"
	@rm -f client server

compile-client: client_main.c minitalk.h
	@${CC} ${CC_FLAGS} ${CC_OPTS} client_main.c -o client

compile-server: server_main.c minitalk.h
	@${CC} ${CC_FLAGS} ${CC_OPTS} server_main.c -o server

compile-all: re compile-server compile-client
	@echo "\n${YEL}Executables compiled successfully${NC}\n"

################################################################################

compile-client-bonus: client_main_bonus.c minitalk_bonus.h
	@${CC} ${CC_FLAGS} ${CC_OPTS} client_main_bonus.c -o client

compile-server-bonus: server_main_bonus.c minitalk_bonus.h
	@${CC} ${CC_FLAGS} ${CC_OPTS} server_main_bonus.c -o server

compile-bonus: re compile-server-bonus compile-client-bonus
	@echo "\n${YEL}Executables compiled successfully${NC}\n"

################################################################################