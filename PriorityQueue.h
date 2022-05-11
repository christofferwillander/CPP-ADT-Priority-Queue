#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "IPriorityQueue.h"

template <typename T>
class PriorityQueue:public IPriorityQueue<T>
{
public:
	const int EXPINCREMENT = 10;

private:
	T* entries;
	int entryCapacity;
	int nrOfEntries;
	int expansionMultiplicity;
	void expand();
	void shrink();
	void moveForward(int index) const;
	int highestPriorityIndex() const;

public:
	PriorityQueue(int entryCapacity = 10);
	PriorityQueue(const PriorityQueue<T> &origObj);
	virtual ~PriorityQueue();
	PriorityQueue<T>& operator = (const PriorityQueue<T> &origObj);
	void enqueue(const T& element);
	T dequeue() throw(...);
	T front() const throw(...);
	bool isEmpty() const;
};

template <typename T>
PriorityQueue<T>::PriorityQueue(int entryCapacity)
{
	this->entryCapacity = entryCapacity;
	this->nrOfEntries = 0;
	this->expansionMultiplicity = 0;
	this->entries = new T[this->entryCapacity];
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &origObj)
{
	this->entryCapacity = origObj.entryCapacity;
	this->nrOfEntries = origObj.nrOfEntries;
	this->expansionMultiplicity = origObj.expansionMultiplicity;

	this->entries = new T[origObj.entryCapacity];

	for (int i = 0; i < origObj.nrOfEntries; i++)
	{
		this->entries[i] = origObj.entries[i];
	}
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete[] this->entries;
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator = (const PriorityQueue<T> &origObj)
{
	if (this != &origObj)
	{
		delete[] this->entries;

		this->entryCapacity = origObj.entryCapacity;
		this->nrOfEntries = origObj.nrOfEntries;
		this->expansionMultiplicity = origObj.expansionMultiplicity;

		this->entries = new T[origObj.entryCapacity];

		for (int i = 0; i < origObj.nrOfEntries; i++)
		{
			this->entries[i] = origObj.entries[i];
		}
	}

	return *this;
}

template <typename T>
void PriorityQueue<T>::enqueue(const T& element)
{
	if (this->nrOfEntries == this->entryCapacity) // Expands entries array if necessary
	{
		this->expand();
	}

	this->entries[this->nrOfEntries++] = element;
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
	if (this->nrOfEntries == 0)
	{
		throw "No entries enqueued";
	}

	int index = this->highestPriorityIndex(); // Storing the array index of the entry with the highest value in variable index
	T temp = this->entries[index]; // Temporarily storing the entry with the highest value in variable temp

	this->nrOfEntries--;
	this->moveForward(index); // Moving elements positioned after the entry with highest priority forward 1 position
	this->shrink(); // Shrinks array size if deemed appropriate

	return temp;
}

template <typename T>
T PriorityQueue<T>::front() const
{
	if (this->nrOfEntries == 0)
	{
		throw "No entries enqueued";
	}

	return this->entries[this->highestPriorityIndex()]; // Returning the entry with the highest value
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return this->nrOfEntries == 0;
}

template <typename T>
void PriorityQueue<T>::expand()
{
	this->entryCapacity += this->EXPINCREMENT;
	this->expansionMultiplicity++;
	T* newArray = new T[this->entryCapacity];

	for (int i = 0; i < this->nrOfEntries; i++)
	{
		newArray[i] = this->entries[i];
	}

	delete[] this->entries;
	this->entries = newArray;
}

template <typename T>
void PriorityQueue<T>::shrink()
{
	T* newArray;
	int initSize = (this->entryCapacity - (this->expansionMultiplicity * this->EXPINCREMENT)); // Calculating initial size (before any expansion took place)

	if (this->nrOfEntries <= (this->entryCapacity - (this->EXPINCREMENT)) && this->expansionMultiplicity > 0) // Executes only if the number of free slots in the array >= EXPINCREMENT
	{
		this->expansionMultiplicity--;
		this->entryCapacity -= this->EXPINCREMENT;

		newArray = new T[(this->expansionMultiplicity * this->EXPINCREMENT) + initSize];

		for (int i = 0; i < this->nrOfEntries; i++)
		{
			newArray[i] = this->entries[i];
		}

		delete[] this->entries;
		this->entries = newArray;
	}
}

template <typename T>
void PriorityQueue<T>::moveForward(int index) const
{
	for (int i = index; i < this->nrOfEntries; i++)
	{
		this->entries[i] = this->entries[i + 1];
	}
}

template <typename T>
int PriorityQueue<T>::highestPriorityIndex() const
{
	int index = 0;

	if (this->nrOfEntries > 0)
	{
		for (int i = 1; i < this->nrOfEntries; i++)
		{
			if (this->entries[i] > this->entries[index])
			{
				index = i;
			}
		}
	}

	return index;
}

#endif