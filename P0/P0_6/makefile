CC= gcc -Wall
LIBS= -lm
HEADER_FILES_DIR= ./headerFiles
INCLUDES = -I $(HEADER_FILES_DIR)

MAIN= ejecutable

SRCS= asignarElemento.c destrueMatriz.c main.c prodEscalar.c suma.c creaMatriz.c imprimeMatriz.c obterElemento.c produto.c 

DEPS=$(HEADER_FILES_DIR)/matriz.h

OBJS=$(SRCS:.c=.o)


$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(INCLUDES)

cleanall:clean
	rm -f $(MAIN)
clean:
	rm -f *.o*~	
