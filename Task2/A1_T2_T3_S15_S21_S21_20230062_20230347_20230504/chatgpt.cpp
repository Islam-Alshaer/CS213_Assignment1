#include "Polynomial.h"

// Default constructor (zero polynomial)
Polynomial::Polynomial() : coeffs(4, 0.0) {}

// Constructor with coefficients
Polynomial::Polynomial(const vector<double>& coefficients) {
    if (coefficients.size() > 4) {
        coeffs = vector<double>(coefficients.begin(), coefficients.begin() + 4);
    } else {
        coeffs = coefficients;
        coeffs.resize(4, 0.0); // Ensure it's a degree 3 polynomial
    }
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}

// Destructor
Polynomial::~Polynomial() {}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coeffs = other.coeffs;
    }
    return *this;
}

// Addition operator
Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result;
    for (int i = 0; i < 4; ++i) {
        result.coeffs[i] = this->coeffs[i] + other.coeffs[i];
    }
    return result;
}

// Subtraction operator
Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result;
    for (int i = 0; i < 4; ++i) {
        result.coeffs[i] = this->coeffs[i] - other.coeffs[i];
    }
    return result;
}

// Multiplication operator
Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result;
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (i + j <= 3) {
                result.coeffs[i + j] += this->coeffs[i] * other.coeffs[j];
            }
        }
    }
    return result;
}

// Equality operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// Output operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    bool first = true;
    for (int i = 3; i >= 0; --i) {
        if (poly.coeffs[i] != 0) {
            if (!first && poly.coeffs[i] > 0) {
                out << " + ";
            } else if (poly.coeffs[i] < 0) {
                out << " - ";
            }
            out << abs(poly.coeffs[i]) << "x^" << i;
            first = false;
        }
    }
    if (first) {
        out << "0";
    }
    return out;
}

// Get the degree of the polynomial
int Polynomial::degree() const {
    for (int i = 3; i >= 0; --i) {
        if (coeffs[i] != 0) {
            return i;
        }
    }
    return 0; // Zero polynomial has degree 0
}

// Evaluate the polynomial at a given x
double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i <= 3; ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

// Polynomial composition
Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result;
    for (int i = 0; i <= 3; ++i) {
        Polynomial temp;
        double coeff = coeffs[i];
        temp.coeffs[0] = coeff;
        for (int j = 1; j <= i; ++j) {
            temp = temp * q;
        }
        result = result + temp;
    }
    return result;
}

// Derivative of the polynomial
Polynomial Polynomial::derivative() const {
    Polynomial result;
    for (int i = 1; i <= 3; ++i) {
        result.coeffs[i - 1] = i * coeffs[i];
    }
    return result;
}

// Return a polynomial of integration (without constant term)
Polynomial Polynomial::integral() const {
    Polynomial result;
    for (int i = 0; i <= 2; ++i) {
        result.coeffs[i + 1] = coeffs[i] / (i + 1);
    }
    return result;
}

// Definite integral from x1 to x2
double Polynomial::integral(double x1, double x2) const {
    Polynomial indefiniteIntegral = this->integral();
    return indefiniteIntegral.evaluate(x2) - indefiniteIntegral.evaluate(x1);
}

// Find a root using Newton's method
double Polynomial::getRoot(double guess, double tolerance, int maxIter) {
    double x = guess;
    Polynomial deriv = this->derivative();
    for (int i = 0; i < maxIter; ++i) {
        double y = this->evaluate(x);
        if (abs(y) < tolerance) {
            return x;
        }
        double yPrime = deriv.evaluate(x);
        if (abs(yPrime) < tolerance) {
            break; // Avoid division by near-zero
        }
        x = x - y / yPrime;
    }
    return x; // Return the best approximation
}

// Set coefficients for the polynomial
void Polynomial::setCoefficients(const vector<double>& coefficients) {
    if (coefficients.size() > 4) {
        coeffs = vector<double>(coefficients.begin(), coefficients.begin() + 4);
    } else {
        coeffs = coefficients;
        coeffs.resize(4, 0.0);
    }
}

// Get the coefficient of a specific degree
double Polynomial::getCoefficient(int degree) const {
    if (degree < 0 || degree > 3) {
        throw out_of_range("Degree out of range");
    }
    return coeffs[degree];
}