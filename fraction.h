#include <math.h>
#include <iostream>
#define MAX_SIZE 100000
#define  MAX_DOUBLE 1000000
class fraction {

private:

    int numerator = 1;
    int denominator = 1;

public:
    fraction() {
        numerator = 1;
        denominator = 1;
    }
    fraction(int a, int b) {
        numerator = a;
        if (b == 0) {
            throw "ERROR denominator == 0";
        }
        denominator = b;
        cut_frac();
    }
    fraction(double a) {
        a *= MAX_DOUBLE;
        numerator = (int) a;
        denominator = MAX_DOUBLE;
        cut_frac();
    }
    int get_numerator() {
        return numerator;
    }
    int get_denominator() {
        return denominator;
    }
    void set_numerator(int a) {
        numerator = a;
    }
    void set_denominator(int a) {
        denominator = a;
    }
    int get_whole() {
        return (int) numerator / denominator;
    }
    void cut_frac() {
        bool pointer_num = true;
        bool pointer_den = true;
        int del_num[MAX_SIZE];
        int del_den[MAX_SIZE];
        int new_numerator;
        int new_denominator;

        if (numerator < 0 && denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        if (denominator < 0) {
            pointer_den = false;
            denominator = -denominator;
        }

        if (numerator < 0) {
            pointer_num = false;
            numerator = -numerator;
        }

        new_denominator = denominator;
        new_numerator = numerator;

        for (int i = 0; i < MAX_SIZE; i ++) {
            del_den[i] = 0;
            del_num[i] = 0;
        }

        for (int i = 2; i <= new_numerator; i ++) {
            while(new_numerator % i == 0) {
                new_numerator = new_numerator / i;
                del_num[i]++;
            }
        }

        for (int i = 2; i <= new_denominator; i ++) {
            while(new_denominator % i == 0) {
                new_denominator = new_denominator / i;
                del_den[i]++;
            }
        }
        new_numerator = numerator;
        new_denominator = denominator;
        for (int i = 2; i <= numerator && i <= denominator; i++) {
            while (del_den[i] > 0 && del_num[i] > 0) {
//                std::cout << del_den[i] << "  "<< del_num[i] << std::endl;
                del_den[i]--;
                del_num[i]--;
                numerator /= i;
                denominator /= i;
            }
        }

        if (!pointer_num) {
            numerator = -numerator;
        }
        if (!pointer_den) {
            denominator = -denominator;
        }

    }

    friend fraction operator+(const fraction& a, const fraction& b) {
        fraction c(a.numerator * b.denominator + b.numerator * a.denominator , a.denominator * b.denominator);
        c.cut_frac();
        return c;

    }
    friend fraction operator+(const fraction& a, const int b) {
        fraction c(a.numerator + b * a.denominator, a.denominator);
        c.cut_frac();
        return c;
    }
    friend fraction operator+(const fraction& a, const double d) {
        fraction b(d);
        fraction c(a.numerator * b.denominator + b.numerator * a.denominator , a.denominator * b.denominator);
        c.cut_frac();
        return c;
    }


    friend fraction operator-(const fraction& a, const fraction& b) {
        fraction c(a.numerator * b.denominator - b.numerator * a.denominator , a.denominator * b.denominator);
        c.cut_frac();
        return c;
    }
    friend fraction operator-(const fraction& a, const int b) {
        fraction c(a.numerator - b * a.denominator, a.denominator);
        c.cut_frac();
        return c;
    }
    friend fraction operator-(const fraction& a, const double d) {
        fraction b(d);
        fraction c(a.numerator * b.denominator - b.numerator * a.denominator , a.denominator * b.denominator);
        c.cut_frac();
        return c;
    }


    friend fraction operator*(const fraction& a, const fraction& b) {
        fraction c(a.numerator * b.numerator , a.denominator * b.denominator);
        c.cut_frac();
        return c;
    }
    friend fraction operator*(const fraction& a, const int b) {
        fraction c(a.numerator * b, a.denominator);
        c.cut_frac();
        return c;
    }
    friend fraction operator*(const fraction& a, const double d) {
        fraction b(d);
        fraction c(a.numerator * b.numerator , a.denominator * b.denominator);
        c.cut_frac();
        return c;
    }


    friend fraction operator/(const fraction& a, const fraction& b) {
        fraction c(a.numerator * b.denominator , a.denominator * b.numerator);
        c.cut_frac();
        return c;
    }
    friend fraction operator/(const fraction& a, const int b) {
        fraction c(a.numerator, a.denominator * b);
        c.cut_frac();
        return c;
    }

    friend fraction operator/(const fraction& a, const double d) {
        fraction b (d);
        fraction c(a.numerator * b.denominator , a.denominator * b.numerator);
        c.cut_frac();
        return c;
    }



    fraction& operator=(const fraction a) {
        this->numerator = a.numerator;
        this->denominator = a.denominator;
        return *this;
    }
    fraction& operator=(const int a) {
        this->numerator = a;
        this->denominator = 1;
        return *this;
    }
    fraction& operator=(const double d) {
        fraction a(d);
        this->numerator = a.numerator;
        this->denominator = a.denominator;
        return *this;
    }



    fraction& operator+=(const fraction& a) {
        *this = *this + a;
        return *this;
    }
    fraction& operator+=(const int a) {
        *this = *this + a;
        return *this;
    }
    fraction& operator+=(const double a) {
        *this = *this + a;
        return *this;
    }


    fraction& operator-=(const fraction& a) {
        *this = *this - a;
        return *this;
    }
    fraction& operator-=(const int a) {
        *this = *this - a;
        return *this;
    }
    fraction& operator-=(const double a) {
        *this = *this - a;
        return *this;
    }


    fraction& operator*=(const fraction& a) {
        *this = *this * a;
        return *this;
    }
    fraction& operator*=(const int a) {
        *this = *this * a;
        return *this;
    }
    fraction& operator*=(const double a) {
        *this = *this * a;
        return *this;
    }

    fraction& operator/=(const fraction& a) {
        *this = *this / a;
        return *this;
    }
    fraction& operator/=(const int a) {
        *this = *this / a;
        return *this;
    }
    fraction& operator/=(const double a) {
        *this = *this / a;
        return *this;
    }

    friend bool operator==(const fraction& left, const fraction& right) {
        if (left.numerator == right.numerator && left.denominator == right.denominator) {
            return true;
        }
        return false;
    }

    friend bool operator!=(const fraction& left, const fraction& right) {
        if (left.numerator != right.numerator && left.denominator != right.denominator) {
            return true;
        }
        return false;
    }

    friend bool operator>(const fraction& left, const fraction& right) {
        int num_left = left.numerator * right.denominator;;
        int num_right = right.numerator * left.denominator;

        if (num_left > num_right)
            return true;
        return false;
    }
    friend bool operator>=(const fraction& left, const fraction& right) {
        int num_left = left.numerator * right.denominator;;
        int num_right = right.numerator * left.denominator;

        if (num_left >= num_right)
            return true;
        return false;
    }
    friend bool operator<(const fraction& left, const fraction& right) {
        int num_left = left.numerator * right.denominator;;
        int num_right = right.numerator * left.denominator;

        if (num_left < num_right)
            return true;
        return false;
    }
    friend bool operator<=(const fraction& left, const fraction& right) {
        int num_left = left.numerator * right.denominator;;
        int num_right = right.numerator * left.denominator;

        if (num_left <= num_right)
            return true;
        return false;
    }

    friend std::ostream& operator<< (std::ostream& out, const fraction& a) {
        out << a.numerator << "/" << a.denominator;
        return out;
    }

    friend std::istream& operator>> (std::istream& in, fraction& a) {
        in >> a.numerator >> a.denominator;
        return in;
    }

};
