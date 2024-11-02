#include "Polynomial.h"

// Constructors
Polynomial::Polynomial() {
    coeffs = {0.0};
}

Polynomial::Polynomial(const vector<double>& coefficients) {
    coeffs = coefficients;
}

Polynomial::Polynomial(const Polynomial& other) {
    coeffs = other.coeffs;
}

// Destructor
Polynomial::~Polynomial() {}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    coeffs = other.coeffs;
    return *this;
}

// Arithmetic operators
Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxDegree = max(degree(), other.degree());
    vector<double> result(maxDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        result[i] += coeffs[i];
    }

    for (int i = 0; i <= other.degree(); ++i) {
        result[i] += other.coeffs[i];
    }

    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    return *this + (-other);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    int resultDegree = degree() + other.degree();
    vector<double> result(resultDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        for (int j = 0; j <= other.degree(); ++j) {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }

    return Polynomial(result);
}

// Equality operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// Output operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    bool firstTerm = true;
    for (int i = poly.degree(); i >= 0; --i) {
        if (poly.coeffs[i] != 0) {
            if (!firstTerm) {
                if (poly.coeffs[i] > 0) {
                    out << " + ";
                } else {
                    out << " - ";
                }
            }
            firstTerm = false;
            if (poly.coeffs[i] != 1 || i == 0) {
                out << abs(poly.coeffs[i]);
            }
            if (i > 1) {
                out << "x^" << i;
            } else if (i == 1) {
                out << "x";
            }
        }
    }
    if (firstTerm) {
        out << "0";
    }
    return out;
}

// Utility functions
int Polynomial::degree() const {
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        if (coeffs[i] != 0) {
            return i;
        }
    }
    return 0;
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree(); ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::compose(const Polynomial& q) const {
    int resultDegree = degree() * q.degree();
    vector<double> result(resultDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        for (int j = 0; j <= q.degree(); ++j) {
            result[i * j] += coeffs[i] * pow(q.getCoefficient(j), i);
        }
    }

    return Polynomial(result);
}

Polynomial Polynomial::derivative() const {
    int resultDegree = degree() - 1;
    vector<double> result(resultDegree + 1, 0.0);

    for (int i = 1; i <= degree(); ++i) {
        result[i - 1] = coeffs[i] * i;
    }

    return Polynomial(result);
}


Polynomial Polynomial::integral() const {
    int resultDegree = degree() + 1;
    vector<double> result(resultDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        result[i + 1] = coeffs[i] / (i + 1);
    }

    return Polynomial(result);
}


double Polynomial::getRoot(double guess = 1, double tolerance = 1e-6, int maxIter = 100) {
    for (int i = 0; i < maxIter; ++i) {
        double f = evaluate(guess);
        double df = derivative().evaluate(guess);
        double newGuess = guess - f / df;

        if (abs(newGuess - guess) < tolerance) {
            return newGuess;
        }

        guess = newGuess;
    }

    return guess;
}


void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;
}

double Polynomial::getCoefficient(int degree) const {
    if (degree >= 0 && degree < coeffs.size()) {
        return coeffs[degree];
    }
    return 0.0;
