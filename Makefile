CC=gcc
CFLAGS=-W -Wall -Wextra -I.
EXEC=Taquin

all: $(EXEC) clean
	@echo "All is ok !"

$(EXEC): main.o game.o
	$(CC) -o $@ $^  $(LDFLAGS)
main.o: main.c
	$(CC) -o $@ -c $< $(CFLAGS)
game.o: game.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

