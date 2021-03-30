clean:
	rm *.o
	rm *.gch
	rm words
	rm *~
	rm *#

word:	
	g++ Word.cpp Word.h Noun.cpp Noun.h Word_list.cpp Word_list.h Handler.cpp Handler.h  testMain.cpp -o words
	./words

word3.o: testMain.cpp 
	g++  -Wall -c testMain.cpp

word2.o: Word_list.cpp Word_list.h Word.h Noun.h
	g++  -Wall  -c Word_list.cpp  Word_list.h

word1.o: Word.cpp Noun.cpp Word.h Noun.h
	g++  -Wall -c Word.cpp Noun.cpp Word.h Noun.h








start:
	./wxtest

full:
	g++ *.cpp *.h  `wx-config --cxxflags --libs std` -o  wxtest
	./wxtest


all: part1.o part2.o part3.o partGui.o
	echo last step
	g++ -c *.o `wx-config --cxxflags --libs std` -o  wxtest

partGui.o: part1.o part2.o part3.o Word.h Noun.h Handler.h Word_list.h
	echo "GUI"
	g++ -Wall -c cApp.cpp cMain.cpp cApp.h cMain.h  `wx-config --cxxflags --libs std`


part3.o: part1.o  Word.h Noun.h Handler.cpp Handler.h
	echo Handler*******************	
	g++ -Wall -c Handler.cpp Handler.h

part2.o: part1.o
	echo part2
	g++  -Wall -c Word_list.cpp Word_list.h 
part1.o:
	echo part1
	g++ -Wall -c Word.cpp Word.h  Noun.cpp Noun.h 

#compile:
#	g++ t.est.cpp `wx-config --cxxflags --libs std,aui` -o p.rogram
#start:
#	./p.rogram
#all:
#	g++ te.st.cpp `wx-config --cxxflags --libs std` -o 
#	./pr.ogram
#	
