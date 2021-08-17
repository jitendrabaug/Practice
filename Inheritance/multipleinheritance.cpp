#include <iostream>
using namespace std;

struct sA
{
    int m_i;
    sA() : m_i(-2) {}
};
struct sB : virtual sA
{
    // void *vptr;
    //
    int m_j;
    sB() : m_j(-1) {}
};
struct sC : virtual sA
{
    int m_k;
    sC() : m_k(0) {}
};
struct sD : sB, sC
{
    // static int SB::offset[]
    // static int SC::offset[]
    int m_l;
    sD() : m_l(+1) {}
};
/*
	int sD::sB::offset[0] = 0;
	int sD::sB::offset[1] = 20;

	int sD::sC::offset[0] = -8;
	int sD::sC::offset[1] = 12;
	*/

void sizes()
{
    cout << "sizeof(sA): " << sizeof(sA) << "\n";
    cout << "sizeof(sB): " << sizeof(sB) << "\n";
    cout << "sizeof(sC): " << sizeof(sC) << "\n";
    cout << "sizeof(sD): " << sizeof(sD) << "\n";
}
void mainFun()
{
    //sizes();
    sD dObj;
    cout << "----------------------\n";
    long *p = (long *)&dObj;
    long *vptr = (long *)p;
    long *offset = (long *)*vptr;
    cout << "first offset : " << *offset << "\n";
    ++offset;
    cout << "*offset (20): " << *offset << "\n";
    p++;
    cout << " *p(m_j=-1): " << *p << "\n";
    p++;
    vptr = (long *)p;
    offset = (long *)*vptr;
    cout << "first offset : " << *offset << "\n";
    ++offset;
    cout << "*offset (12): " << *offset << "\n";
    p++;
    cout << " *p(m_k= 0): " << *p << "\n";
    p++;
    cout << " *p(m_l= +1): " << *p << "\n";
    p++;
    cout << " *p(m_i= -2): " << *p << "\n";

    cout << "----------------------\n";
}

int main()
{
    //basicInheritance::main();
    //multipleInheritance::main();
    //hydrid::main();

    std::cout << sizeof(std::string) << std::endl;
    mainFun();
}