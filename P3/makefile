CC= gcc -Wall
LIBS= -time
HEADER_FILES_DIR= ./headerFiles
INCLUDES = -I $(HEADER_FILES_DIR)

MAIN= ejecutable

SRCS= vectordinamico.c main.c quicksort.c burbuja.c seleccion.c

DEPS=$(HEADER_FILES_DIR)/vectordinamico.h $(HEADER_FILES_DIR)/burbuja.h $(HEADER_FILES_DIR)/quicksort.h $(HEADER_FILES_DIR)/seleccion.h

OBJS=$(SRCS:.c=.o)


$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(INCLUDES)

cleanall:clean
	rm -f $(MAIN)
clean:
	rm -f *.o*~	
