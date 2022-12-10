OBJS		= hex.c
OBJ_NAME	= hex.exe
CC			= /bin/gcc


all: $(OBJS)
	$(CC) $(OBJS) -o $(OBJ_NAME) -Wall

clean:
	rm hex.exe