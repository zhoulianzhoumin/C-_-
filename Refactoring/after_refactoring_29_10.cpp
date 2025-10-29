#include <iostream>
#include <cmath>


int main(int argc, char* argv[]) {
	double angle;
	std::cout << "请输入角度：" << endl;
	std::cin >> angle;
	
	if  (cos(2 * angle) != 1) {
		double result = (1 + sin(2 * angle)) / (1 - cos(2 * angle));
		std::cout << "F(angle1)=" << result << endl;
	} else if  (cos(2 * angle) == 1) {
		std::cout << "对于F(angle1)输入有误！" << endl;
	}
	
	if  (tan(angle) != 1) {
		double result = (1 + tan(angle) * tan(angle)) / (1 - tan(angle) * tan(angle));
		std::cout << "F(angle2)=" << result << endl;
	} else if (tan(angle) == 1) {
		std::cout << "对于F(angle2)输入有误！" << endl;
	}
	
	system ("pause");
	return 0;
}