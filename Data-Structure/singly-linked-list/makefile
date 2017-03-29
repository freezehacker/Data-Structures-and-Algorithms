a.out: testSinglyLinkedList.o SinglyLinkedList.o
	g++ testSinglyLinkedList.o SinglyLinkedList.o -o a.out

testSinglyLinkedList.o: testSinglyLinkedList.cpp SinglyLinkedList.h
	g++ -c testSinglyLinkedList.cpp

SinglyLinkedList.o: SinglyLinkedList.cpp SinglyLinkedList.h
	g++ -c SinglyLinkedList.cpp

clean:
	rm *.out *.o
