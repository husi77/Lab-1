#include <iostream>
#include "Stack.h"
#include "MyStack.h"
using namespace std;

const int MAX_SIZE = 50;

void read(Stack* s, istream& in, int n);
void display(Stack* s, ostream& out);
void copy(Stack* src, Stack* dst);

bool isPrime(int n);
bool isPerfectSquare(int n);
bool isPalindromeNumber(int n);

void displayPrimes(Stack* s);
void displayPerfectSquares(Stack* s);
void displayPalindromeValues(Stack* s);
void checkStackPalindrome(Stack* s);

int main() {
    Stack* A = new MyStack(MAX_SIZE);

    read(A, cin, 10);

    display(A, cout);

    displayPrimes(A);
    displayPerfectSquares(A);
    displayPalindromeValues(A);

    checkStackPalindrome(A);

    delete A;
    return 0;
}

void read(Stack* s, istream& in, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        in >> val;
        s->push(val);
    }
}

void display(Stack* s, ostream& out) {
    MyStack temp(MAX_SIZE);
    int val;

    while (s->pop(val)) {
        temp.push(val);
    }

    while (temp.pop(val)) {
        out << val << " ";
        s->push(val);
    }
    out << "\n";
}

void copy(Stack* src, Stack* dst) {
    MyStack temp(MAX_SIZE);
    int val;

    while (src->pop(val)) {
        temp.push(val);
    }

    while (temp.pop(val)) {
        src->push(val);
        dst->push(val);
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPerfectSquare(int n) {
    if (n < 0) return false;
    for (int i = 0; i * i <= n; i++) {
        if (i * i == n) return true;
    }
    return false;
}

bool isPalindromeNumber(int n) {
    int reversed = 0;
    int remainder;
    int original = n;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return original == reversed;
}

void displayPrimes(Stack* s) {
    MyStack temp(MAX_SIZE);
    int val;

    while (s->pop(val)) {
        temp.push(val);
    }

    while (temp.pop(val)) {
        if (isPrime(val)) {
            cout << val << " ";
        }
        s->push(val);
    }
    cout << "\n";
}

void displayPerfectSquares(Stack* s) {
    MyStack temp(MAX_SIZE);
    int val;

    while (s->pop(val)) {
        temp.push(val);
    }

    while (temp.pop(val)) {
        if (isPerfectSquare(val)) {
            cout << val << " ";
        }
        s->push(val);
    }
    cout << "\n";
}

void displayPalindromeValues(Stack* s) {
    MyStack temp(MAX_SIZE);
    int val;

    while (s->pop(val)) {
        temp.push(val);
    }

    while (temp.pop(val)) {
        if (isPalindromeNumber(val)) {
            cout << val << " ";
        }
        s->push(val);
    }
    cout << "\n";
}

void checkStackPalindrome(Stack* s) {
    MyStack forwardCopy(MAX_SIZE);
    MyStack reverseStack(MAX_SIZE);
    MyStack comparisonCopy(MAX_SIZE);

    int val, val1, val2;
    bool isPalindromeSequence = true;

    copy(s, &forwardCopy);
    copy(s, &comparisonCopy);

    while (forwardCopy.pop(val)) {
        reverseStack.push(val);
    }

    while (comparisonCopy.pop(val1) && reverseStack.pop(val2)) {
        if (val1 != val2) {
            isPalindromeSequence = false;
        }
    }

    if (isPalindromeSequence) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
}