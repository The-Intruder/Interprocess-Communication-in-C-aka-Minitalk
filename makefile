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

NC := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror
CC_OPTS := ./libs/get_next_line/get_next_line.c \
		./libs/get_next_line/get_next_line_utils.c \
		-L./libs/libft -lft \
		-L. -lmt

SRCS_DIR := srcs/
SRCS_LST := 
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

HEADER := minitalk.h
NAME := libmt.a

.PHONY: all clean fclean re server client both

all: ${NAME}

${NAME}: ${OBJS} minitalk.h
	@make -C libs/libft/
	@echo "\n\n${BLU}Creating ${GRA}${NAME}${BLU} archive file ...${NC}"
	@ar -rcs ${NAME} ${OBJS}
	@echo "\n${GRN}Library created successfully ...\n${NC}"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c minitalk.h
	@echo "\n${MGN}Creating ${GRA}$@${MGN} file from ${GRA}$<${MGN} file ...${NC}"
	@${CC} ${CC_FLAGS} -c $< -o $@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@echo "\n${RED}Cleaning up ${GRA}libft${RED} Object files ...\n${NC}"
	@rm -f ./libs/libft/*.o
	@echo "${RED}Removing ${GRA}objs/${RED}folder ...\n${NC}"
	@rm -rf ${OBJS_DIR}

fclean: clean
	@echo "${RED}Cleaning up Archive files ...\n${NC}"
	@rm -f ${NAME} ./libs/libft/*.a

client: client_main.c minitalk.h
	@gcc -Wall -Werror -Wextra client_main.c -L./libs/libft -lft -o client

server: server_main.c minitalk.h
	@gcc -Wall -Werror -Wextra server_main.c -L./libs/libft -lft -o server

both: server client