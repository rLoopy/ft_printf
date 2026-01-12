SRC = $(wildcard *.c)
# wildcard is a tool that search in the current directory
# here I told that it has to search for all .c files

OBJ = $(SRC:%.c=%.o)
# this line converts all %.c in %.o

NAME = libft.a
# this sets the name of the output to libft.a

LIB_H = libft.h

CC = cc
CFLAGS = -Wall -Werror -Wextra
# compilation flags

RM = rm -f

.PHONY = all clean fclean re
#  avoid conflicts and command failures

all : $(NAME)

%.o: %.c $(LIB_H)
		$(CC) $(CFLAGS) -c $< -o $@
#compiles all .c files into .o files

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
# ar = archiver, we need it because we are building a library

clean :
	$(RM) $(OBJ)
# the wildcard command will take a list of files and return
# filtered out all the files that don't match an existing file in the project
fclean : clean
	$(RM) $(NAME)

re: fclean all