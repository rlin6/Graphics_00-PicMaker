all: picmaker.c
	gcc -o picmaker picmaker.c
	./picmaker

clean:
	rm picmaker
