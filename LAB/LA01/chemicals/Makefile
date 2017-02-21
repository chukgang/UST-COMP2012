all: laughingGas.exe lime.exe

laughingGas.exe: laughingGasMain.o nitrogen.o oxygen.o
	g++ -o laughingGas.exe laughingGasMain.o nitrogen.o oxygen.o

laughingGasMain.o: laughingGasMain.cpp nitrogen.h oxygen.h
	g++ -c laughingGasMain.cpp
	
lime.exe: limeMain.o calcium.o oxygen.o
	g++ -o lime.exe limeMain.o calcium.o oxygen.o

limeMain.o: limeMain.cpp calcium.h oxygen.h
	g++ -c limeMain.cpp

calcium.o: calcium.cpp calcium.h
	g++ -c calcium.cpp 

nitrogen.o:  nitrogen.cpp  nitrogen.h
	g++ -c  nitrogen.cpp 

oxygen.o: oxygen.cpp oxygen.h
	g++ -c oxygen.cpp 

clean:
	rm -rf *.o
	rm -rf *.exe