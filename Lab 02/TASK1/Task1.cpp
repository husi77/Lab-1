#include <iostream>
#include "AbstractArray.h"
#include "MyArray.h"
using namespace std;

const int MAX_SIZE = 50;

void read(AbstractArray* arr, istream& in, int n);
void display(AbstractArray* arr, ostream& out);
void copy(AbstractArray* src, AbstractArray* dst);
void insert(AbstractArray* src, AbstractArray* dst, int pos);
void shiftLeft(AbstractArray* aa, int pos);
void shiftRight(AbstractArray* aa, int pos);
void stats(AbstractArray* AA, int& max, float& average);

int main() {
    int n = 0;

    AbstractArray* A = new MyArray(MAX_SIZE);

    cout << "please select a number between 1 and " << MAX_SIZE << ": ";
    cin >> n;

    read(A, cin, n);

    cout << "Array A Values: ";
    display(A, cout);

    AbstractArray* B = new MyArray(MAX_SIZE);
    copy(A, B);
    cout << "Array B Values: ";
    display(B, cout);

    AbstractArray* C = new MyArray(MAX_SIZE);

    C->add(9);
    C->add(7);
    C->add(5);

    insert(A, C, 2);
    cout << "Array C Values: ";
    display(C, cout);

    shiftLeft(C, 2);
    cout << "Array C Values: ";
    display(C, cout);

    shiftRight(C, 2);
    cout << "Array C Values: ";
    display(C, cout);

    int mx = 0;
    float ag = 0.0;
    stats(C, mx, ag);

    cout << "Array C Values: ";
    display(C, cout);

    cout << "Average is " << ag << " maximum is " << mx << endl;

    delete A;
    delete B;
    delete C;

    return 0;
}

void read(AbstractArray* arr, istream& in, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        in >> val;
        arr->add(val);
    }
}

void display(AbstractArray* arr, ostream& out) {
    int i = 0;
    int val;
    while (arr->get(i, val)) {
        out << val << " ";
        i++;
    }
    out << endl;
}

void copy(AbstractArray* src, AbstractArray* dst) {
    int i = 0;
    int val;
    while (src->get(i, val)) {
        dst->add(val);
        i++;
    }
}

void shiftRight(AbstractArray* aa, int pos) {
    int val;
    int count = 0;

    while (aa->get(count, val)) {
        count++;
    }

    if (!aa->isFull()) {
        aa->add(0);
        for (int i = count - 1; i >= pos; i--) {
            aa->get(i, val);
            aa->insert(i + 1, val);
        }
    }
}

void shiftLeft(AbstractArray* aa, int pos) {
    int val;
    int i = pos + 1;

    while (aa->get(i, val)) {
        aa->insert(i - 1, val);
        i++;
    }

    int temp;
    aa->remove(temp);
}

void insert(AbstractArray* src, AbstractArray* dst, int pos) {
    int val;
    int i = 0;

    while (src->get(i, val)) {
        shiftRight(dst, pos + i);
        dst->insert(pos + i, val);
        i++;
    }
}

void stats(AbstractArray* AA, int& max, float& average) {
    int val;
    int sum = 0;
    int count = 0;
    max = -999999;

    while (AA->get(count, val)) {
        if (val > max) {
            max = val;
        }
        sum = sum + val;
        count++;
    }

    if (count > 0) {
        average = (float)sum / count;
    }
    else {
        average = 0.0;
    }
}