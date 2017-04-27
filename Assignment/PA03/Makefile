SRCS	= course.cpp timeslot.cpp student.cpp main.cpp
OBJS	= $(SRCS:.cpp=.o)

all:	$(OBJS)
	g++ -o $@ $^

clean:
	/bin/rm -f $(OBJS) *~

course.o: course.h timeslot.h
student.o: student.h course.h timeslot.h bt.h bst.h avl.h bt.cpp bst.cpp avl.cpp
timeslot.o: timeslot.h 
main.o: student.h course.h timeslot.h bt.h bst.h avl.h bt.cpp bst.cpp avl.cpp

depend:
	makedepend $(SCRS)

