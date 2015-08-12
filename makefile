rso01:rso01.c
	gcc -o rso01 rso01.c -I/workarea/cprogram/include `pkg-config --cflags --libs gtk+-2.0`
clean:
	rm ./rso01

