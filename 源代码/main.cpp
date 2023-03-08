#include <iostream>
class Fraction
{
	private:
		int m_numerator; // 分子
		int m_denominator; // 分母
	public:
		Fraction(int num, int den = 1): m_numerator(num), m_denominator(den)
		{

		}
		operator double() const
		{
			return (double)(1.0 * m_numerator / m_denominator);
		}
};
int main()
{
	Fraction f(3, 5);
	double d = 4 + f;
	std::cout << d << std::endl;
}
