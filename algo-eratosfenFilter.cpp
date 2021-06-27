// algo-eratosfenFilter.cpp : Defines the entry point for the application.
//

#include "algo-eratosfenFilter.h"
#include <vector>
#include <algorithm>

using item_t = size_t;
using RangeInt_t = std::vector<item_t>;

RangeInt_t createRangeAB(size_t a, size_t b) {
	RangeInt_t range;
	range.resize(b - a);
	item_t i = a;
	std::for_each(range.begin(), range.end(), [&i](item_t& d) {
		d = i;
		++i;
	});
	return range;
}

RangeInt_t* eratosfetFiltr(RangeInt_t range) {
	RangeInt_t *filtrRange = new RangeInt_t;
	int n = range.size();
	int i = 0;
	int p = 0;
	for (i = 2; i < n; i++)
	{
		if (range[i] != 0)
		{
			//std::cout << range[i] << " ";
			filtrRange->push_back(range[i]);
			for (p = 2 * i; p < n; p += i)
			{
				range[p] = 0;
			}
		}
	}	
	return filtrRange;
}

#define PRINT_RANGE_INT(x) std::copy(x.begin(),x.end(),std::ostream_iterator<item_t>(std::cout," "))

int main()
{
	RangeInt_t range = createRangeAB(0, 100);
	PRINT_RANGE_INT(range);

	std::cout << std::endl <<  "Eratosfen filter print " << std::endl;
	RangeInt_t filtered = *eratosfetFiltr(range);
	PRINT_RANGE_INT(filtered);


	return 0;
}
