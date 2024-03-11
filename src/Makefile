NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -g3 #-Ofast
LIBMLX	:= ../MLX42/
LIBFT	:= ../libft/
LIBFT_MAKE = $(MAKE) -C $(LIBFT) --no-print-directory
LIBFT_LIB = $(LIBFT)/libft.a


HEADERS	:= -I ../include -I $(LIBMLX)/include $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= $(shell find ./src -iname "*.c")
SRCS	:= cub3D.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(LIBFT_LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -L $(LIBFT) -lft

$(LIBFT_LIB):
	@$(LIBFT_MAKE)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@$(LIBFT_MAKE) fclean
	@$(LIBFT_MAKE) clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx