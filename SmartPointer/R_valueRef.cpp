#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int nNumerator = 0, int nDenominator = 1) : numerator(nNumerator), denominator(nDenominator)
    {
        std::cout << "Fraction object Created..\n";
    }
    ~Fraction();

    friend std::ostream &operator<<(std::ostream &out, Fraction objF);
};

// Fraction::Fraction(/* args */)
// {
// }

Fraction::~Fraction()
{
    std::cout << "Fraction object is destroyed..\n";
}

std::ostream &operator<<(std::ostream &out, Fraction objF)
{
    out << objF.numerator << " / " << objF.denominator << std::endl;

    return out;
}

int main()
{
    auto &&rref{Fraction{3, 5}};

    std::cout << rref;
    return 0;
}