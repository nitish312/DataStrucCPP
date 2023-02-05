#include <iostream>

class ByteStruc
{
private:
	bool *byte;
public:

	// num to byte func
	static void num_to_byte(int in_num, bool *returnable)
	{

		// check for extranius values
		if ((in_num >= 255) || (in_num <= 0))
		{
			// tell user what happend and let fall to trailing nullptr
			std::cout << "number too large or small, sorry :^(" << std::endl;
		}
		else 
		{
			// create iterable, and difference
			int i{ 0 };
			int dif{ 128 };

			// loop til' end of array :^)
			while (i <= 7)
			{
				if (in_num >= dif)
				{
					returnable[i] = 1;
					in_num -= dif;
				}
				else
				{
					returnable[i] = 0;
				}
				dif /= 2;
				i++;
			}
		}
		returnable = nullptr;
	}

	ByteStruc(bool t_ptr[8])
	{
		//make new bool array on heap
		this->byte = new bool[8];

		// copy array by value into member
		for (int i{}; i <= 7; i++)
		{
			this->byte[i] = t_ptr[i];
		}
	}

	void print_byte()
	{
		std::cout << "printing byte:" << std::endl;
		for (int i{}; i <= 7; i++)
		{
			std::cout << "byte at [" << i << "]: " << this->byte[i] << std::endl;
		}
	}

	
	~ByteStruc()
	{
		// reallocate the array 
		delete [] byte;
	}
};
