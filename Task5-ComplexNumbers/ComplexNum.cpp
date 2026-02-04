#include <iostream>
#include <stdexcept>

class ComplexNumber
{
private:
    float real;
    float imagin;

public:

    ComplexNumber() : real(0.0f), imagin(0.0f) {}                                           // Konstruktor domyœlny
    ComplexNumber(float re, float img) : real(re), imagin(img) {}                           // Konstruktor parametryczny
    ComplexNumber(const ComplexNumber& other) : real(other.real), imagin(other.imagin) {}   // Konstruktor kopiuj¹cy

    ~ComplexNumber(){}

    ComplexNumber& operator=(const ComplexNumber& other)
    {
        if (this != &other)
        {
            real = other.real;
            imagin = other.imagin;
        }
        return *this;
    }

    ComplexNumber operator+(const ComplexNumber& other) const
    {
        return ComplexNumber( real + other.real, imagin + other.imagin);
    }

    ComplexNumber operator-(const ComplexNumber& other) const
    {
        return ComplexNumber(real - other.real, imagin - other.imagin);
    }


    ComplexNumber operator*(const ComplexNumber& other) const
    {
        return ComplexNumber(
            real * other.real - imagin * other.imagin,
            real * other.imagin + imagin * other.real
        );
    }

    ComplexNumber operator/(const ComplexNumber& other) const
    {
        float denominator = (other.real * other.real) + (other.imagin * other.imagin);

        if (denominator == 0.0f)
        {
            throw std::runtime_error("dzielenie przez zero");
        }

        return ComplexNumber(
            (real * other.real + imagin * other.imagin) / denominator,
            (imagin * other.real - real * other.imagin) / denominator
        );
    }


    void print() const
    {
        if (imagin == 0.0f) {
            std::cout << real << std::endl;
        }
        else if (imagin == 1.0f) {
            std::cout << real << " + " << "i" << std::endl;
        }
        else {
            std::cout << real << " + " << imagin << "i" << std::endl;
        }
        
    }
};

int main()
{
    ComplexNumber num1(2.0f, 0.5f);
    ComplexNumber num2(8.0f, 2.0f);
    ComplexNumber num3(0.0f, 0.0f);

    ComplexNumber sum = num1 + num2;
    sum.print();

    ComplexNumber difference = num1 - num2;
    difference.print();

    ComplexNumber product = num1 * num2;
    product.print();

    try {
        ComplexNumber quotient = num1 / num2;
        quotient.print();
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    //dzielenie dla num3 = 0
    try {
        ComplexNumber quotient0 = num1 / num3;
        quotient0.print();
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}