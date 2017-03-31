ifeq (Windows_NT, $(OS))
TARGET=demo.exe
NEWTARGET=pa2.exe
lib=ncurses_lib/pdcurses
flag=_WIN_
ifeq (, $(OSTYPE))
GUESS_OS=native-windows
else
GUESS_OS=cygwin-or-msys
endif
else
GUESS_OS=MAC_OR_OTHER
TARGET=demo.out
NEWTARGET=pa2.out
lib=ncurses
flag=_MAC_
endif




HEADER =	Board.h Cell.h Player.h param.h Property.h View.h 
TODOHEADER = TodoBoard.h TodoPlace.h TodoPlayer.h TodoRestaurant.h TodoProperty.h

COMMON= Property.o View.o Board.o 
DEMO=  mainForDemo.o 
TODO=  TodoBoard.o TodoPlayer.o TodoPlace.o mainForTodo.o TodoRestaurant.o TodoProperty.o

COMMON_OBJ= $(addprefix common/, $(COMMON))
DEMO_OBJ= $(addprefix demo/, $(DEMO))
TODO_OBJ= $(addprefix todo/, $(TODO))
OBJ =	$(COMMON_OBJ) $(DEMO_OBJ) $(TODO_OBJ)

all: echo demo $(NEWTARGET)

demo: create_directory $(TARGET)

create_directory: 
	mkdir -p common todo demo

echo:
	echo $(GUESS_OS) $(COMMON_OBJ)


demo.exe: *.cpp $(DEMO_OBJ) $(COMMON_OBJ)  
	g++ -Wall -D$(flag) -o $(TARGET) -l$(lib) -static -L".\\" $(COMMON_OBJ) $(DEMO_OBJ) pdcurses.dll

demo.out: *.cpp $(COMMON_OBJ) $(DEMO_OBJ)
	g++ -Wall -D$(flag) -o $(TARGET) -l$(lib) $(COMMON_OBJ) $(DEMO_OBJ)

pa2.exe: *.cpp $(COMMON_OBJ) $(TODO_OBJ)
	g++ -Wall -D$(flag) -o $(NEWTARGET) -l$(lib) -static -L".\\"  $(COMMON_OBJ) $(TODO_OBJ) pdcurses.dll

pa2.out: *.cpp $(COMMON_OBJ) $(TODO_OBJ)
	g++ -Wall -D$(flag) -o $(NEWTARGET) -l$(lib) $(COMMON_OBJ) $(TODO_OBJ)


todo/TodoBoard.o: TodoBoard.cpp $(HEADER) $(TODOHEADER)
	g++ -D$(flag) -c -o todo/TodoBoard.o TodoBoard.cpp

todo/TodoPlayer.o: TodoPlayer.cpp $(HEADER) $(TODOHEADER)
	g++ -D$(flag) -c -o todo/TodoPlayer.o TodoPlayer.cpp

todo/TodoProperty.o: TodoProperty.cpp $(HEADER) $(TODOHEADER)
	g++ -D$(flag) -c -o todo/TodoProperty.o TodoProperty.cpp

todo/TodoPlace.o: TodoPlace.cpp $(HEADER) $(TODOHEADER)
	g++ -D$(flag) -c -o todo/TodoPlace.o TodoPlace.cpp

todo/TodoRestaurant.o: TodoRestaurant.cpp $(HEADER) $(TODOHEADER)
	g++ -D$(flag) -c -o todo/TodoRestaurant.o TodoRestaurant.cpp


todo/mainForTodo.o: mainForTodo.cpp $(HEADER) $(TODOHEADER)
	g++ -D$(flag) -c -o todo/mainForTodo.o mainForTodo.cpp


demo/mainForDemo.o: mainForDemo.cpp $(HEADER)
	g++ -D$(flag) -c -o demo/mainForDemo.o mainForDemo.cpp



common/Board.o:  Board.cpp $(HEADER)
	g++ -D$(flag) -c -o common/Board.o Board.cpp

common/Property.o: Property.cpp $(HEADER)
	g++ -D$(flag) -c -o common/Property.o Property.cpp

common/View.o: View.cpp $(HEADER)
	g++ -D$(flag) -c -o common/View.o View.cpp




clean:
	rm -f $(OBJ) $(TARGET) $(NEWTARGET)
