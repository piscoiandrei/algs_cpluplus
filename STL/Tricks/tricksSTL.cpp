#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
            // size, init everything with 3 // also works on other STL data structures
vector<int> v(10, 3);

void print(vector<int> const &input) /** vector print*/
{
	copy(input.begin(),
			input.end(),
			ostream_iterator<int>(cout, " "));
			// works with files also
}

void outputPairVector()
{
    vector<pair<int, int>> vec =
   {
      {1,1},
      {2,2}
   };
   for (const auto& p : vec)
   {
      cout << p.first << " " << p.second << endl;
   }
}


//define the function:
bool comparator(const MyStruct& lhs, const MyStruct& rhs) {
   return lhs.key < rhs.key;   /** < crescator
                                   > descrescator */
}
// pass it to sort:
//sort(vec.begin(), vec.end(), &comparator);


int main()
{
	vector<int> input = { 1, 2, 3, 4, 5 };
	print(input);

	return 0;
}
