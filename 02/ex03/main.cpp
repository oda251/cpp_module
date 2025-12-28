#include <iostream>
#include <string>
#include <cstdlib>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

#include <ios>

#define MAX (2147483648.0f/256)
#define MIN (1.0f/256)
int main( void ) {
	// > https://discord.com/channels/691903146909237289/758877501832429608/1159096139103088651
	std::cout << "--- snara test ---" << std::endl;
	Point a(0,0);
    Point b(MAX,MAX);
    Point c(MAX,0);
    Point pt1(-1,-1);

    std::cout<<std::boolalpha;
    std::cout<< bsp(a,b,c,pt1) <<std::endl;
    std::cout<< (Fixed(MAX-1)-Fixed(MIN) == Fixed(MAX-1)) <<std::endl;

	std::cout << "--- on edge ---" << std::endl;
	std::cout << bsp(Point(0, 0), Point(0, 4), Point(4, 0), Point(2, 2)) << std::endl;
	std::cout << "--- inside ---" << std::endl;
	std::cout << bsp(Point(0, 0), Point(0, 4), Point(4, 0), Point(2, 1.9)) << std::endl;
	std::cout << "--- outside ---" << std::endl;
	std::cout << bsp(Point(0, 0), Point(0, 4), Point(4, 0), Point(2, 2.1)) << std::endl;
	return 0;
}
