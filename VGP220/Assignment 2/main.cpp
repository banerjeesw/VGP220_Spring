#include <iostream>

//Grade: 100/100 + 5 bonus!

//TODO:  
//Question 1:
//How much time does the following method take? Use the big-O notation in terms
//of the parameter n.
int foo_1(int n)
{
    int counter = 0;
    int current = 1;
    while (current < n)
    {
        counter++;
        current *= 2;
    }
    return current;
}
//Answer: O(log n)


//TODO:
//Question 2: The methods "pow_a" and "pow_b" bellow determines m to the power of n without using
//math libraries. How much time each one of the methods take using big - O notation in terms of n.
int pow_a(int m, int n)
{
    int ret = 1;
    for (int i = 0; i < n; i++)
    {
        ret *= m;
    }
    return ret;
}
//Answer for pow_a: O(n)

int pow_b(int m, int n) {
    int ret = 1;
    int k = m;
    int i = n;
    while (i > 0)
    {
        if (i % 2 == 1) ret *= k;
        k *= k;
        i /= 2;
    }
    return ret;
}
//Answer for pow_b: O(log n)

//TODO:
//Question 3:
//The method bellow finds and removes duplicated numbers in the parameter array. 
//Note that it has three loops. Using Big O notation, in terms of the length of the arr, how
//much time this function takes ?
int removeDuplicates(char arr[], int n)
{
    int len = n;
    int i = 0;           // index of current item to find
    while (i < len)
    {
        int j;           // will be index of duplicate of arr[i]
        for (j = i + 1; j < len; j++)
        {
            if (arr[i] == arr[j]) break;
        }
        if (j == len)
        {   // no duplicate of arr[i] found; go to next i
            i++;
        }
        else
        {         // duplicate found; shift array over arr[j]
            for (int k = j + 1; k < len; k++)
            {
                arr[k - 1] = arr[k];
            }
            len--;
            arr[len] = 0;
        }
    }
    return len;
}
//Answer: O(n^2)

//TODO:
//Question 4: 
//Write an exponential function that returns an array with 
//the multiplications results which has the time complexity O(n) and a space complexity O(n)
//For example: Pow(3, 3) means that is 3 ^ 3 and the returned array will be: [1, 3, 9, 27]
int* Pow(int n, int e)
{
    int * powArray = new int[e + 1];

    for (int i = 0; i < e + 1; ++i)
    {
        if (i == 0)
        {
            powArray[i] = 1;
        }
        else
        {
            powArray[i] = powArray[i - 1] * n;
        }
    }

    return powArray;
}

//TODO:
//Question 5:
//Create a display function that prints an array of size n with this format:
// [2, 3, 4, 1, 6, 20, 0]
void DisplayArray(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i == 0) std::cout << "[";

        std::cout << arr[i];

        if (i == n - 1)
        {
            std::cout << "]";
        }
        else
        {
            std::cout << ", ";
        }
    }
}

//TODO: This question is optional. It's bonus if you don't search or copy anything from the internet.
//There are no wrong answers. Interview questions like this one is just to evaluate how you think.
//Of course that you can find this question on the internet, but try not to. Think about what is the worst case scenario.
//and how can you make this better.

//Question 6: EA's and Google's Interview question

//You work in a 100 floor building and you get 2 identical eggs. 
//You need to figure out the highest floor an egg can be dropped without breaking. 
//Find an algorithm that is minimizing number of throws in the worst-case scenario.
//Code is not necessary. You can explain with your own words.
//You can make some assumptions like:
//1)If an egg doesn?t break when dropped from some floor, then it will not break when dropped from any lower floors.
//2)An egg that survives a fall can be used again.
//3)A broken egg must be discarded.
//4)The effect of a fall is the same for all eggs.
//5)If an egg breaks when dropped, then it would break if dropped from a higher floor.

/*
* Answer: 
Starting from the 1st floor, I would test throw the first egg. If it breaks at the 1st floor, then ground floor is the highest we can go.
If it doesn't break on the 1st floor, then I would try the 2nd floor, then the 4th, 8th, 16th, 32nd, 64th, and finally the 100th floor.
If the first egg breaks on any of the floors listed (for example, it breaks on 32nd), I would go back down to the previous floor I tested (in this case, 16th).
Then I would throw test throw the second egg on every floor in between this floor and where the first egg broke. Eventually, the second egg will break.
The exact answer will be the floor previous to the one where the second egg breaks (nothing stipulated in the rules that I need an egg remaining to give the answer).
If it doesn't break on the 100th floor, then you have some magic eggs and that's a bigger prize/problems than getting a programming gig.
*/

int main(int argc, char* argv[])
{
    //Test:
    const int number = 2;
    const int order = 4;
    int* powerResults = Pow(number, order);
    DisplayArray(powerResults, order + 1);
    //EXPECTED RESULT: [1, 3, 9, 27]
}