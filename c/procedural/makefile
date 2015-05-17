SRC=main.c cpf.c
OBJ=$(SRC:.c=.o)
CFLAGS=-g
OUT=cpfcheck
$(OUT) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
.o : .c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	\rm -f $(OBJ)
	\rm -f $(OUT)