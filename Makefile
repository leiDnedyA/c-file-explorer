bin/aydens-file-explorer: main.c
	echo "building..."
	sleep 2
	gcc main.c -o bin/aydens-file-explorer

build: main.c
	echo "building..."
	sleep 2
	gcc main.c -o bin/aydens-file-explorer

run:
	./bin/aydens-file-explorer

clean:
	rm -rf bin
	mkdir bin
