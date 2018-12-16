


#include <iostream>

 int main()
 {
 int sum{0};
 int count{};
 int x;
 while (std::cin >> x /*&& x != 0*/)
 {
	 sum = sum + x;
	 count = count + 1;
 }

if (count)
 std::cout << "average = " << sum / count << '\n';
 }
