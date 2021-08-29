CFLAGS=-g -Wall -Werror
CC=c++ $(CFLAGS) # > - < hihi

INCLUDE=src/include
BIN=src/bin

all: install
		
run:
	$(BIN)/main

clean:
	rm -fr $(INCLUDE)/objs
	rm $(BIN)/main

install:
	@ rm -fr $(INCLUDE)/objs
	@ mkdir  $(INCLUDE)/objs
	@ $(CC) -c $(INCLUDE)/blockchain/blockchain.cpp -I $(INCLUDE)/blockchain  -o $(INCLUDE)/objs/blockchain.o 
	@ $(CC) -c $(INCLUDE)/blockchain/block.cpp      -I $(INCLUDE)/blockchain  -o $(INCLUDE)/objs/block.o 
	@ $(CC) -c $(INCLUDE)/consensus/validation.cpp  -I $(INCLUDE)/blockchain  -o $(INCLUDE)/objs/validation.o
	@ $(CC) -c $(INCLUDE)/crypto/sha256.cpp         -I $(INCLUDE) -lcrypto    -o $(INCLUDE)/objs/sha256.o
	@ $(CC) $(BIN)/main.cpp $(INCLUDE)/objs/*.o     -I $(INCLUDE)/blockchain/ -o $(BIN)/main -lcrypto
	@ echo "[inf] Done!! Execute [make run]!!"