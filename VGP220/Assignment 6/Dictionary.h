#pragma once

#include <string>
#include <list>
#include <random>
#include <chrono>
#include <iostream>

//Solve collision with chaining
//This Dictionary does not allows similar keys.

//This struct represents the Data that will be inserted into your dictionary(Hash Map)
template<typename T>
struct Data
{
	std::string key;
	T value;
};

template<typename T>
class Dictionary
{
public:
	Dictionary(int capacity)
		: mCapacity(capacity)
		, mCurrentSize(0)
	{
		//Task 1: Implement the new constructor.
		//	Initialize mData with the capacity: for example:
		//      - mData = new...*[capacity];
		//  Then loop through mData initializing each one of the arrays with size 5. This can be done in 2 ways:
		//      I) mData[i] = new... *[5];   or
		//     II) mData[i] = new...[5];
		//  If you choose I, nested for loop to initialize each element of the sub arrays with nullptr:
		//        mData[i][j] = nullptr;
		//  If you choose II, nested for loop to initialize each key as empty:
		//        mData[i][j].key = "";
		//This initialization is required that you can check if the position for insertion is available or not

		mData = new Data<T>*[capacity];
		for (int i = 0; i < capacity; ++i)
		{
			mData[i] = new Data<T>[5];

			for (int j = 0; j < 5; ++j)
			{
				mData[i][j].key = "";
			}
		}
	}

	~Dictionary()
	{
		//Task 2
		// Implement the destructor for this class.
		// Don't forget that if you "new" a data, you have to "delete" this data;

		for (int i = 0; i < mCapacity; ++i)
		{
			delete[] mData[i];
		}

		delete[] mData;
	}

	//Task 3 - This hash function receives a key and transforms this key into a int that
	//will be used as an index. Since you have one array with multiples arrays inside, you need at least 
	//one modifiable hash function or 2 different hash functions, that gives you different indices for the same 
	//key.

	//Your task is to:
	// I) Implement a second Hash function, different than this one 
	//                              OR 
	// II) Modify this one in a way, that you can send a parameter 
	//to this function and this hash returns a different index for the same key.

	//If you choose the I, you can keep this Hash, and implement a new one:
	//   example:  int Hash_2(const std::string& key)

	// If you choose II, one of the variables that you can use as parameter is the seed.
	//  example: int Hash(const std::string& key, int seed)
	int Hash(const std::string& key)
	{
		int seed = 131;
		int hash = 0;
		for (int i = 0; i < key.length(); ++i)
		{
			//You don't need to cast, since hash is an integer and you are adding
			//a character, the cast is implicit. static_cast<int> in this case is ambiguous.
			hash += key[i];
		}
		hash *= seed;
		return hash % mCapacity;
	}

	//Method II Implementation

	int Hash(const std::string& key, int seed)
	{
		int hash = 0;
		for (int i = 0; i < key.length(); ++i)
		{
			hash += key[i];
		}
		hash *= seed;
		return hash % mCapacity;
	}

	void Insert(const std::string& key, T value)
	{
		//Task 4: This is the hardest method to be implemented. You will need to hash 2 times.
		// Make sure to find two indices (Using your hash functions) and insert to the next available position. If you don't 
		//	have an available position, print a message to the user saying:
		// "Element cannot be inserted. Bucket at index %s is full." %s = hashIndex. 

		//Randomizing seeds

		std::default_random_engine generator;
		generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<int> distribution(0, 255);

		//Finding indices

		int index1 = Hash(key, distribution(generator));
		int index2 = Hash(key, distribution(generator));

		//Checking if available

		if (mData[index1][index2].key == "")
		{
			//If available, put in the key and value

			mData[index1][index2].key = key;
			mData[index1][index2].value = value;
			std::cout << "Inserted " << std::string(value) << " at index " << index1 << "!" << std::endl;
		}
		else
		{
			//If not available, print error message
			std::cout << "Element cannot be inserted. Bucket at index " << index1 << " is full." << std::endl;
		}
	}

	//Function for Debugging

	void PrintAll()
	{
		std::cout << "Dictionary Visualization: " << std::endl;

		for (int i = 0; i < mCapacity; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (mData[i][j].key != "")
				{
					std::cout << std::string(mData[i][j].value) << ", ";
				}
				else
				{
					std::cout << "---, ";
				}
			}

			std::cout << std::endl;
		}
	}

private:
	//mData is an array of arrays.
	Data<T>** mData;
	//Capacity should keep track of the total size of mData. (Number of Arrays * Number of Elements)
	int mCapacity;
	//Current size starts with zero elements and keep track of current size of the data structure.
	int mCurrentSize;
};