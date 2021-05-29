all: spy victim 

spy: spy.c ../cacheutils.h
	gcc -std=gnu11 -O3 -o $@ $@.c

victim: victim.c ../cacheutils.h
	gcc -std=gnu11 -O3 -o $@ $@.c

clean:
	rm spy victim
