#include "String.h"
int main ()
{

    String s1("dasdas", 6);
    s1.print();
    String s2 = s1;
    s2.print();
    String s3(s2);
    s3.print();
    s3.concat("C++");
    s3.print();
    return 0;
}
