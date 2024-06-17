CC = gcc
LIBS = -lpthread

all: et ep para_mm

et: et.o etime.o
	$(CC) -o et et.o etime.o $(LIBS)

ep: ep.o etime.o
	$(CC) -o ep ep.o etime.o $(LIBS)

para_mm: para_mm.o etime.o
	$(CC) -o para_mm para_mm.o etime.o $(LIBS)

et.o: et.c 
	$(CC) -c et.c 

ep.o: ep.c 
	$(CC) -c ep.c 

para_mm.o: para_mm.c 
	$(CC) -c para_mm.c 

etime.o: etime.c 
	$(CC) -c etime.c 
clean:
	rm *.o et ep para_mm