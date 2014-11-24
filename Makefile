OBJ = main.o function.o

a4: 	$(OBJ)
	gcc -o a4 $(OBJ)

main.o:	main.c stuDefs.h mhDefs.h
	gcc -c main.c

function.o:function.c stuDefs.h mhDefs.h
	gcc -c function.c

clean:
	rm *.o a4
