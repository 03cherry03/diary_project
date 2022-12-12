all: diary.c diary_Allday.c diary_lastday.c diary_Star_PR.c diary_Rto_thatday.c diary_Wto_today.c diary_Wto_thatday.c
	gcc -c diary_Allday.c
	gcc -c diary_lastday.c
	gcc -c diary_Star_PR.c
	gcc -c diary_Rto_thatday.c
	gcc -c diary_Wto_today.c
	gcc -c diary_Wto_thatday.c
	gcc -c diary.c
	gcc -o diary diary.o diary_Allday.o diary_lastday.o diary_Star_PR.o diary_Rto_thatday.o diary_Wto_today.o diary_Wto_thatday.o
clean:
	rm *.o diary