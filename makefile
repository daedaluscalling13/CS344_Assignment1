movies: process.o prompt.o prompt1.o prompt2.o prompt3.o movies.o
	gcc --std=gnu99 -o movies process.o prompt.o prompt1.o prompt2.o prompt3.o movies.o

movies.o: movies.c movie.h
	gcc --std=gnu99 -c -g movies.c

process.o: process.h process.c movie.h
	gcc --std=gnu99 -c -g process.h process.c

prompt.o: prompt.h prompt.c
	gcc --std=gnu99 -c -g prompt.h prompt.c

prompt1.o: prompt1.h prompt1.c movie.h
	gcc --std=gnu99 -c -g prompt1.h prompt1.c

prompt2.o: prompt2.h prompt2.c movie.h
	gcc --std=gnu99 -c -g prompt2.h prompt2.c

prompt3.o: prompt3.h prompt3.c movie.h
	gcc --std=gnu99 -c -g prompt3.h prompt3.c