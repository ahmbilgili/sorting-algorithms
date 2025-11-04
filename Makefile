all: mergesort quicksort insertionsort

clean:
	rm mergesort.out quicksort.out insertionsort.out

mergesort: mergesort.cpp
	g++ -o mergesort.out mergesort.cpp

quicksort: quicksort.cpp
	g++ -o quicksort.out quicksort.cpp

insertionsort: insertionsort.cpp
	g++ -o insertionsort.out insertionsort.cpp