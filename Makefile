NAME = iosParser 

C_FLAG = cc -Wall -Wextra -Werror

FILES = isoParser.c check_bitmap.c init_data_element.c 

all : $(NAME)

$(NAME) : $(FILES)
		$(C_FLAG) $(FILES) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
