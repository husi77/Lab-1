#include <iostream>
#include "Stack.h"
#include "MyStack.h"
using namespace std;

const int MAX_SIZE = 50;

void read(Stack* s, istream& in, int n);
void display(Stack* s, ostream& out);
void copy(Stack* src, Stack* dst);
void insert(Stack* src, Stack* dst, int pos);
void shiftUp(Stack* s, int pos);
void shiftDown(Stack* s, int pos);
void stats(Stack* s, int& max, float& average);

int main() {
    int n = 0;

    Stack* A = new MyStack(MAX_SIZE);

    cout << "please select a number between 1 and " << MAX_SIZE << ": ";
    cin >> n;

    read(A, cin, n);

    cout << "Stack A Values: ";
    display(A, cout);

    Stack* B = new MyStack(MAX_SIZE);
    copy(A, B);
    cout << "Stack B Values: ";
    display(B, cout);

    Stack* C = new MyStack(MAX_SIZE);

    C->push(9);
    C->push(7);
    C->push(5);

    insert(A, C, 2);
    cout << "Stack C Values: ";
    display(C, cout);

    shiftDown(C, 2);
    cout << "Stack C Values: ";
    display(C, cout);

    shiftUp(C, 2);
    cout << "Stack C Values: ";
    display(C, cout);

    int mx = 0;
    float ag = 0.0;
    stats(C, mx, ag);

    cout << "Stack C Values: ";
    display(C, cout);

    cout << "Average is " << ag << " maximum is " << mx << endl;

    delete A;
    delete B;
    delete C;

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
    out << endl;
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

void insert(Stack* src, Stack* dst, int pos) {
    MyStack tempDst(MAX_SIZE);
    MyStack tempSrc(MAX_SIZE);
    int val;
    int countDst = 0;

    while (dst->pop(val)) {
        tempDst.push(val);
        countDst++;
    }

    for (int i = 0; i < pos && i < countDst; i++) {
        tempDst.pop(val);
        dst->push(val);
    }

    while (src->pop(val)) {
        tempSrc.push(val);
    }

    while (tempSrc.pop(val)) {
        src->push(val);
        dst->push(val);
    }

    while (tempDst.pop(val)) {
        dst->push(val);
    }
}

void shiftUp(Stack* s, int pos) {
    MyStack temp(MAX_SIZE);
    int val;
    int count = 0;

    while (s->pop(val)) {
        temp.push(val);
        count++;
    }

    for (int i = 0; i < count; i++) {
        temp.pop(val);
        s->push(val);
        if (i == pos) {
            s->push(val);
        }
    }
}

void shiftDown(Stack* s, int pos) {
    MyStack temp(MAX_SIZE);
    int val;
    int count = 0;

    while (s->pop(val)) {
        temp.push(val);
        count++;
    }

    for (int i = 0; i < count; i++) {
        temp.pop(val);
        if (i != pos) {
            s->push(val);
        }
    }
}

void stats(Stack* s, int& max, float& average) {
    MyStack temp(MAX_SIZE);
    int val;
    int sum = 0;
    int count = 0;
    max = -999999;

    while (s->pop(val)) {
        if (val > max) {
            max = val;
        }
        sum = sum + val;
        count++;
        temp.push(val);
    }

    while (temp.pop(val)) {
        s->push(val);
    }

    if (count > 0) {
        average = (float)sum / count;
    }
    else {
        average = 0.0;
    }
}