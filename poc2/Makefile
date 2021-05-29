all: spy victim 

spy: spy.c ../cacheutils.h
	gcc -std=gnu11 -O3 -o $@ $@.c -lvul -lvul2

victim: victim.c ../cacheutils.h 
	gcc -std=gnu11 -O3 -o $@ $@.c -lvul -lvul2

clean:
	rm spy victim
