A3:    main.o Control.o Restaurant.o RsvList.o Reservation.o Date.o Time.o Table.o View.o
	g++ -o a3 main.o Control.o Restaurant.o RsvList.o Reservation.o Date.o Time.o Table.o View.o
main.o: main.cc
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc
View.o: View.cc View.h
	g++ -c View.cc

Restaurant.o: Restaurant.cc Restaurant.h
	g++ -c Restaurant.cc

RsvList.o: RsvList.cc RsvList.h
	g++ -c RsvList.cc

Reservation.o:	Reservation.cc Reservation.h
	g++ -c Reservation.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Time.o:	Time.cc Time.h
	g++ -c Time.cc
	
Table.o: Table.cc Table.h
	g++ -c Table.cc
	

clean:
	rm -f *.o A3
