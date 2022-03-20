# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 15:56:29 by adelille          #+#    #+#              #
#    Updated: 2022/03/20 16:29:18 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	minitalk
NAMES =	server
NAMEC =	client
CC = 	clang -Wall -Werror -Wextra
AR =	ar rcs
RM = 	rm -rf
# FLAGS +=	-O2
#FLAGS =	-g# -fsanitize=address

# **************************************************************************** #

MAKEFLAGS += --silent

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LBPATH =	./libft/
LBNAME =	$(LBPATH)libft.a
LBINC =		-I$(LBPATH)

# **************************************************************************** #

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCSNAMESERVER =	ft_server.c
SRCSNAMECLIENT =	ft_client.c \
					ft_check_arg_client.c
#SRCSNAME =	main.c

#SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
SRCSSERVER = $(addprefix $(SRCSPATH), $(SRCSNAMESERVER))
SRCSCLIENT = $(addprefix $(SRCSPATH), $(SRCSNAMECLIENT))

#OBJSNAME = $(SRCS:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(notdir $(OBJSNAME)))
OBJSNAMESERVER = $(SRCSSERVER:.c=.o)
OBJSSERVER = $(addprefix $(OBJSPATH), $(notdir $(OBJSNAMESERVER)))
OBJSNAMECLIENT = $(SRCSCLIENT:.c=.o)
OBJSCLIENT = $(addprefix $(OBJSPATH), $(notdir $(OBJSNAMECLIENT)))

%.o: %.c
	$(CC) $(FLAGS) $(BUFFER) -I$(INC) -c $< -o $(OBJSPATH)$(notdir $@)

# *************************************************************************** #

all:		$(NAME)

$(NAME):	objs_dir $(OBJSNAMESERVER) $(OBJSNAMECLIENT) $(LBNAME)
	#@$(AR) $(NAME) $(OBJS)
	@$(CC) $(FLAGS) $(OBJSSERVER) $(OBJS) $(LBNAME) -o $(NAMES) -lm
	@$(CC) $(FLAGS) $(OBJSCLIENT) $(OBJS) $(LBNAME) -o $(NAMEC) -lm
	@echo "$(B)$(MAG)$(NAME) compiled.$(D)"

objs_dir:
	@mkdir -p $(OBJSPATH)
	
$(LBNAME):
	@make -C $(LBPATH)

clean:
	@$(RM) $(OBJSSERVER) $(OBJSCLIENT) #$(OBJSNAME)
	@make clean -C $(LBPATH)
	@echo "$(B)Cleared.$(D)"


fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAMES)
	@$(RM) $(NAMEC)
	@make fclean -C $(LBPATH)

re:			fclean all

.PHONY: all clean fclean re objs_dir
