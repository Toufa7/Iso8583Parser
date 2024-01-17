NAME = iosParser

C_FLAG = cc -Wall -Wextra -Werror

FILES = isoParser.c

all : $(NAME)

$(NAME) : $(FILES)
		$(C_FLAG) $(FILES) -o $(NAME)
