COURSE = cs310
SEMESTER = fall2023
CP_NUMBER = 2
LASTNAME = Zheng
GITUSERID = ChinnyChilla
EXE = MyLL
MENU_EXE = menu_sample

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = ../CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar
ZIPFILE = $(TARFILE).gz

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -Wextra -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/MyLL.o $(OBJ)/Node.o
	$(CC) $(FLAGS) $(OBJ)/MyLL.o $(OBJ)/Node.o -o $@
$(OBJ)/MyLL.o: MyLL.cpp MyLL.h Node.h
	$(CC) $(FLAGS) -c MyLL.cpp -o $@

$(OBJ)/Node.o: Node.h Node.cpp
	$(CC) $(FLAGS) -c Node.cpp -o $@

test: ${BIN}/test

${BIN}/test: ${OBJ}/Test.o $(OBJ)/MyLL.o $(OBJ)/Node.o 
	$(CC) $(FLAGS) ${OBJ}/Test.o $(OBJ)/MyLL.o $(OBJ)/Node.o -o $@

$(OBJ)/Test.o: test.cpp 
	$(CC) $(FLAGS) -c test.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(ZIPFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(ZIPFILE)
