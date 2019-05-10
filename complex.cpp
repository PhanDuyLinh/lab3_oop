#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
class complex
{
private:
    float real;
    float image;
public:
    complex(float r = 0, float i= 0)
    {
        real = r;
        image = i;
    }
    complex (const complex &that)
    {
        this->real = that.real;
        this->image = that.image;
    }
    complex operator+(complex &that)
    {
        complex tmp;
        tmp.real = this->real + that.real;
        tmp.image = this->image + that.image;
        return tmp;
    }
    complex operator-(complex &that)
    {
        complex tmp;
        tmp.real = this->real - that.real;
        tmp.image = this->image - that.image;
        return tmp;
    }
    complex operator*(complex &that)
    {
        complex tmp;
        tmp.real = this->real*that.real - this->image*that.image;
        tmp.image = this->real*that.image + this->image*that.image;
        return tmp;
    }
    bool operator ==(complex &that)
    {
        if (real == that.real && image == that.image)
            return true;
        return false;

    }
    void display()
    {
        cout <<"Real part is: "<<real << endl;
        cout <<"Image part is: "<<image << endl;
        cout <<"The complex number is form: "<< real << "+j" << image << endl;
    }


};
int main()
{
    complex A (1, 2);
    A.display();
    complex B(3, 4);
    B.display();
    complex C = A+B;
    complex D = A-B;
    complex E = A*B;
    complex F = A;
    cout <<"Plus 2 complex number: ";
    C.display();
    cout<< endl;
    cout <<"Minus 2 complex number: ";
    D.display();
    cout<<endl;
    cout <<"Multi 2 complex number: ";
    E.display();
    cout<<endl;
    cout <<"Coppy complex number: ";
    F.display();
    cout<<endl;
    return 0;
}
