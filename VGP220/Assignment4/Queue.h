#pragma once

//TODO: 5 - Implement a Queue class from scratch
//Remember that your queue should follow the FIFO standard (First In First Out)

template<typename T>
class Queue
{
public:
	Queue() : front(0), rear(9), mCurrentSize(0), mCapacity(10)
	{
		mData = new T[10];
	}

	~Queue()
	{
		if (isEmpty())
		{
			return;
		}

		delete mData;
		front = 0;
		rear = 0;
		mCurrentSize = 0;
		mCapacity = 0;
		mData = nullptr;
	}

	//Inserts the data in the queue.
	void Enqueue(T data)
	{
		if (!isEmpty())
		{
			for (int i = mCurrentSize; i > front; --i)
			{
				mData[i] = mData[i - 1];
			}
		}

		mData[front] = data;

		if (mCurrentSize < mCapacity)
		{
			mCurrentSize++;
		}
	}

	//Removes an element from the queue and returns this element in the output parameter
	//Also it returns true if the object was removed and false if the Queue is empty
	bool Daqueue(T& output)
	{
		if (isEmpty())
		{
			return false;
		}

		output = mData[front];

		for (int i = front; i < mCurrentSize; ++i)
		{
			mData[i] = mData[i + 1];
		}

		if (mCurrentSize > 0)
		{
			mCurrentSize--;
		}

		return true;
	}

	//Returns true if queue is empty, false otherwise
	bool isEmpty()
	{
		if (mCurrentSize == 0)
		{
			return true;
		}

		return false;
	}

	//Display all the elements in the queue:
	//Example, lets suppose you inserted 1, 2, 3, 4, 5
	//Display should print: "front->1, 2, 3, 4, 5<-rear"
	void DisplayQueue()
	{
		std::cout << "front->";

		for (int i = front; i < mCurrentSize; ++i)
		{
			std::cout << mData[i] << ", ";
		}

		std::cout << "<-rear\n";
	}

private:
	int front;
	int rear;
	int mCurrentSize;
	int mCapacity;
	T* mData;
};