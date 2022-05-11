#include <iostream>
#include <string>
#include "PriorityQueue.h"

template <typename T>
void testCopyConstructor(PriorityQueue<T> origObj, T element)
{
	origObj.enqueue(element);
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	const int CAP = 10;
	int intQueueEntries[11] = { 164, 72, 84, 37, 4, 45, 62, 7, 58, 92, 103 };
	std::string stringQueueEntries[11] = { "Stacy", "Eric", "Chris", "Monica", "James", "Amanda", "Alexander", "Regina", "Jasmine", "Tom", "Shawn" };

	PriorityQueue <int> *queue1;
	PriorityQueue <int> *queue2;
	PriorityQueue <std::string> *queue3;
	PriorityQueue <std::string> *queue4;

	queue1 = new PriorityQueue <int>(CAP);

	std::cout << "-----------------------------------------Test 1------------------------------------------" << std::endl;
	std::cout << "Testing output from member functions on an object with no entries enqueued (type int)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	std::cout << "Program output: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue1->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue1->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue1->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	std::cout << "-----------------------------------------Test 2------------------------------------------" << std::endl;
	std::cout << "Testing enqueuing, dequeueing and returning the entry first in queue (type int)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "Just dequeued: 164" << std::endl;
	std::cout << "Next in queue: 103" << std::endl;
	std::cout << "Just dequeued: 103" << std::endl;
	std::cout << "Next in queue: 92" << std::endl;
	std::cout << "Just dequeued: 92" << std::endl;
	std::cout << "Next in queue: 84" << std::endl;
	std::cout << "Just dequeued: 84" << std::endl;
	std::cout << "Next in queue: 72" << std::endl;
	std::cout << "Just dequeued: 72" << std::endl;
	std::cout << "Next in queue: 62" << std::endl;
	std::cout << "Just dequeued: 62" << std::endl;
	std::cout << "Next in queue: 58" << std::endl;
	std::cout << "Just dequeued: 58" << std::endl;
	std::cout << "Next in queue: 45" << std::endl;
	std::cout << "Just dequeued: 45" << std::endl;
	std::cout << "Next in queue: 37" << std::endl;
	std::cout << "Just dequeued: 37" << std::endl;
	std::cout << "Next in queue: 7" << std::endl;
	std::cout << "Just dequeued: 7" << std::endl;
	std::cout << "Next in queue: 4" << std::endl;
	std::cout << "Just dequeued: 4" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	for (int i = 0; i < 11; i++)
	{
		queue1->enqueue(intQueueEntries[i]); // Enqueuing all entries in intQueueEntries (11 entries) - forcing the expand function to be used within the class
	}

	std::cout << "Program output: " << std::endl;
	
	for (int i = 0; i < 11; i++)
	{
		try
		{
			std::cout << "Just dequeued: " << queue1->dequeue() << std::endl; // Dequeuing all entries (11 entries) - forcing the shrink function to be used within the class after the first element has been dequeued
		}
		catch (char *exceptionMsg)
		{
			std::cout << exceptionMsg << std::endl;
		}

		try
		{
			std::cout << "Next in queue: " << queue1->front() << std::endl; // Returning the entry that is next in queue
		}
		catch (char *exceptionMsg)
		{
			std::cout << exceptionMsg << std::endl;
		}
	}

	delete[] queue1;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue1 = new PriorityQueue <int>(CAP);
	std::cout << "-----------------------------------------Test 3------------------------------------------" << std::endl;
	std::cout << "Testing the copy constructor on an object without any entries enqueued (type int)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	testCopyConstructor(*queue1, intQueueEntries[0]); // Enqueuing 164 to the copy of queue1

	std::cout << "Program output: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue1->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	delete[] queue1;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue1 = new PriorityQueue <int>(CAP);

	std::cout << "-----------------------------------------Test 4------------------------------------------" << std::endl;
	std::cout << "Testing the copy constructor on an object with entries enqueued (type int)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "Just dequeued: 164" << std::endl;
	std::cout << "Just dequeued: 72" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	queue1->enqueue(intQueueEntries[0]); // Enqueuing 164 in queue1
	queue1->enqueue(intQueueEntries[1]); // Enqueuing 72 in queue1
	testCopyConstructor(*queue1, intQueueEntries[2]); // Enqueuing 84 in the copy of queue1

	std::cout << "Program output: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue1->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	delete[] queue1;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue1 = new PriorityQueue <int>(CAP);
	queue2 = new PriorityQueue <int>(CAP);

	std::cout << "-----------------------------------------Test 5------------------------------------------" << std::endl;
	std::cout << "Testing the assignment operator between two objects without any entries enqueued (type int)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl << std::endl;

	std::cout << "Object 2:" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	*queue1 = *queue2; // Assigning queue2 to queue1

	std::cout << "Program output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;
	
	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue1->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue1->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl << std::endl;
	}
	else if (!queue1->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "Object 2: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue2->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue2->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue2->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue2->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	delete[] queue1;
	delete[] queue2;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue1 = new PriorityQueue <int>(CAP);
	queue2 = new PriorityQueue <int>(CAP);

	std::cout << "-----------------------------------------Test 6------------------------------------------" << std::endl;
	std::cout << "Testing the assignment operator between two objects where only one has entries enqueued (type int)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;
	std::cout << "Just dequeued: 164" << std::endl;
	std::cout << "Just dequeued: 45" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl << std::endl;

	std::cout << "Object 2:" << std::endl;
	std::cout << "Just dequeued: 45" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	queue2->enqueue(intQueueEntries[5]); // Enqueuing 45 in queue2
	*queue1 = *queue2; // Assigning queue2 to queue1
	queue1->enqueue(intQueueEntries[0]); // Enqueueing 164 in queue1

	std::cout << "Program output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;

	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue1->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue1->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl << std::endl;
	}
	else if (!queue1->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "Object 2: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue2->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue2->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue2->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue2->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	delete[] queue1;
	delete[] queue2;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue1 = new PriorityQueue <int>(CAP);
	queue2 = new PriorityQueue <int>(CAP);

	std::cout << "-----------------------------------------Test 7------------------------------------------" << std::endl;
	std::cout << "Testing the assignment operator between two objects which both have entries enqueued (type int)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;
	std::cout << "Just dequeued: 45" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl << std::endl;

	std::cout << "Object 2:" << std::endl;
	std::cout << "Just dequeued: 62" << std::endl;
	std::cout << "Just dequeued: 45" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	queue2->enqueue(intQueueEntries[0]); // Enqueuing 164 in queue2
	queue1->enqueue(intQueueEntries[5]); // Enqueuing 45 in queue1
	queue1->enqueue(intQueueEntries[6]); // Enqueuing 62 in queue1

	*queue2 = *queue1; // Assigning queue1 to queue2

	queue1->dequeue(); // Dequeuing 62 in queue1

	std::cout << "Program output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;

	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue1->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue1->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue1->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl << std::endl;
	}
	else if (!queue1->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "Object 2: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue2->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue2->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue2->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue2->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue2->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	delete[] queue1;
	delete[] queue2;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue3 = new PriorityQueue <std::string>(CAP);

	std::cout << "-----------------------------------------Test 8------------------------------------------" << std::endl;
	std::cout << "Testing output from member functions on an object without entries enqueued (type string)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	std::cout << "Program output: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue3->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue3->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue3->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	std::cout << "-----------------------------------------Test 9------------------------------------------" << std::endl;
	std::cout << "Testing enqueuing, dequeueing and returning the entry first in queue (type string)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "Just dequeued: Tom" << std::endl;
	std::cout << "Next in queue: Stacy" << std::endl;
	std::cout << "Just dequeued: Stacy" << std::endl;
	std::cout << "Next in queue: Shawn" << std::endl;
	std::cout << "Just dequeued: Shawn" << std::endl;
	std::cout << "Next in queue: Regina" << std::endl;
	std::cout << "Just dequeued: Regina" << std::endl;
	std::cout << "Next in queue: Monica" << std::endl;
	std::cout << "Just dequeued: Monica" << std::endl;
	std::cout << "Next in queue: Jasmine" << std::endl;
	std::cout << "Just dequeued: Jasmine" << std::endl;
	std::cout << "Next in queue: James" << std::endl;
	std::cout << "Just dequeued: James" << std::endl;
	std::cout << "Next in queue: Eric" << std::endl;
	std::cout << "Just dequeued: Eric" << std::endl;
	std::cout << "Next in queue: Chris" << std::endl;
	std::cout << "Just dequeued: Chris" << std::endl;
	std::cout << "Next in queue: Amanda" << std::endl;
	std::cout << "Just dequeued: Amanda" << std::endl;
	std::cout << "Next in queue: Alexander" << std::endl;
	std::cout << "Just dequeued: Alexander" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	for (int i = 0; i < 11; i++)
	{
		queue3->enqueue(stringQueueEntries[i]); // Enqueuing all entries in stringQueueEntries (11 entries) - forcing the expand function to be used within the class
	}

	std::cout << "Program output: " << std::endl;

	for (int i = 0; i < 11; i++)
	{
		try
		{
			std::cout << "Just dequeued: " << queue3->dequeue() << std::endl; // Dequeuing all entries (11 entries) - forcing the shrink function to be used within the class after the first entry has been dequeued
		}
		catch (char *exceptionMsg)
		{
			std::cout << exceptionMsg << std::endl;
		}

		try
		{
			std::cout << "Next in queue: " << queue3->front() << std::endl; // Returning the entry that is next in queue
		}
		catch (char *exceptionMsg)
		{
			std::cout << exceptionMsg << std::endl;
		}
	}

	delete[] queue3;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue3 = new PriorityQueue <std::string>(CAP);
	std::cout << "-----------------------------------------Test 10------------------------------------------" << std::endl;
	std::cout << "Testing the copy constructor on an object without any entries enqueued (type string)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	testCopyConstructor(*queue3, stringQueueEntries[0]); // Enqueuing Stacy in the copy of queue3

	std::cout << "Program output: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue3->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	delete[] queue3;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue3 = new PriorityQueue <std::string>(CAP);

	std::cout << "-----------------------------------------Test 11------------------------------------------" << std::endl;
	std::cout << "Testing the copy constructor on an object with entries enqueued (type string)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl;
	std::cout << "Just dequeued: Stacy" << std::endl;
	std::cout << "Just dequeued: Chris" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	queue3->enqueue(stringQueueEntries[0]); // Enqueuing Stacy in queue3
	queue3->enqueue(stringQueueEntries[2]); // Enqueuing Chris in queue3
	testCopyConstructor(*queue3, stringQueueEntries[3]); // Enqueuing Monica in the copy of queue3

	std::cout << "Program output: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue3->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	delete[] queue3;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue3 = new PriorityQueue <std::string>(CAP);
	queue4 = new PriorityQueue <std::string>(CAP);

	std::cout << "-----------------------------------------Test 12------------------------------------------" << std::endl;
	std::cout << "Testing the assignment operator between two objects without any entries enqueued (type string)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl << std::endl;

	std::cout << "Object 2:" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	*queue3 = *queue4; // Assigning queue4 to queue3

	std::cout << "Program output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;

	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue3->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue3->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl << std::endl;
	}
	else if (!queue3->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "Object 2: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue4->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue4->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue4->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue4->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	delete[] queue3;
	delete[] queue4;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue3 = new PriorityQueue <std::string>(CAP);
	queue4 = new PriorityQueue <std::string>(CAP);

	std::cout << "-----------------------------------------Test 13------------------------------------------" << std::endl;
	std::cout << "Testing the assignment operator between two objects where only one has entries enqueued (type string)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;
	std::cout << "Just dequeued: Monica" << std::endl;
	std::cout << "Just dequeued: James" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl << std::endl;

	std::cout << "Object 2:" << std::endl;
	std::cout << "Just dequeued: James" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	queue3->enqueue(stringQueueEntries[4]); // Enqueuing James in queue3

	*queue4 = *queue3; // Assigning queue3 to queue4

	queue3->enqueue(stringQueueEntries[3]); // Enqueuing Monica in queue3

	std::cout << "Program output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;

	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue3->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue3->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl << std::endl;
	}
	else if (!queue3->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "Object 2: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue4->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue4->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue4->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue4->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	delete[] queue3;
	delete[] queue4;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");

	queue3 = new PriorityQueue <std::string>(CAP);
	queue4 = new PriorityQueue <std::string>(CAP);

	std::cout << "-----------------------------------------Test 14------------------------------------------" << std::endl;
	std::cout << "Testing the assignment operator between two objects which both have entries enqueued (type string)" << std::endl << std::endl;

	std::cout << "Expected output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;
	std::cout << "Just dequeued: Stacy" << std::endl;
	std::cout << "Just dequeued: James" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl << std::endl;

	std::cout << "Object 2:" << std::endl;
	std::cout << "Just dequeued: James" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "No entries enqueued" << std::endl;
	std::cout << "Correct output from isEmpty()" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;

	queue4->enqueue(stringQueueEntries[2]); // Enqueuing Chris in queue4
	queue3->enqueue(stringQueueEntries[4]); // Enqueuing James in queue3
	queue3->enqueue(stringQueueEntries[0]); // Enqueuing Stacy in queue3

	*queue4 = *queue3; // Assigning queue3 to queue4

	queue4->dequeue(); // Dequeuing Stacy in queue4

	std::cout << "Program output: " << std::endl << std::endl;
	std::cout << "Object 1:" << std::endl;

	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue3->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue3->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue3->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl << std::endl;
	}
	else if (!queue3->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	std::cout << "Object 2: " << std::endl;
	try
	{
		std::cout << "Just dequeued: " << queue4->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Just dequeued: " << queue4->dequeue() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	try
	{
		std::cout << "Next in queue: " << queue4->front() << std::endl;
	}
	catch (char *exceptionMsg)
	{
		std::cout << exceptionMsg << std::endl;
	}

	if (queue4->isEmpty())
	{
		std::cout << "Correct output from isEmpty()" << std::endl;
	}
	else if (!queue4->isEmpty())
	{
		std::cout << "Incorrect output from isEmpty()" << std::endl;
	}

	delete[] queue3;
	delete[] queue4;

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
	system("@cls||clear");
	
	std::cout << "All tests have been completed..." << std::endl << std::endl;

	system("pause");
	return 0;
}