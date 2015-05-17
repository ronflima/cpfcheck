SRC=cpf_destroy.c cpf_get_check_digits.c cpf_is_valid.c cpf_new.c main.c
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
