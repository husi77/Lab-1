#include <iostream>
#include <fstream>
#include <string>
#include "TStack.h"
#include "TMyStack.h"

using namespace std;

const int MAX_SIZE = 100;

void displayStringStack(Stack<string>* s, ostream& out);
void reverseCopy(Stack<string>* src, Stack<string>* dst);
void removeDuplicates(Stack<string>* s);
void countFrequencies(Stack<string>* s, Stack<int>* freq);

int main() {
    Stack<string>* originalStack = new MyStack<string>(MAX_SIZE);

    ifstream file("para.txt");
    string word;
    int wordCount = 0;

    if (file.is_open()) {
        while (file >> word && wordCount < MAX_SIZE) {
            originalStack->push(word);
            wordCount++;
        }
        file.close();
    }

    Stack<string>* reverseStack = new MyStack<string>(MAX_SIZE);
    reverseCopy(originalStack, reverseStack);
    displayStringStack(reverseStack, cout);

    removeDuplicates(reverseStack);
    displayStringStack(reverseStack, cout);

    Stack<int>* frequencyStack = new MyStack<int>(MAX_SIZE);
    countFrequencies(originalStack, frequencyStack);

    delete originalStack;
    delete reverseStack;
    delete frequencyStack;

    return 0;
}

void displayStringStack(Stack<string>* s, ostream& out) {
    MyStack<string> temp(MAX_SIZE);
    string val;

    while (s->pop(val)) {
        temp.push(val);
    }

    while (temp.pop(val)) {
        out << val << " ";
        s->push(val);
    }
    out << "\n";
}

void reverseCopy(Stack<string>* src, Stack<string>* dst) {
    MyStack<string> temp(MAX_SIZE);
    string val;

    while (src->pop(val)) {
        dst->push(val);
        temp.push(val);
    }

    while (temp.pop(val)) {
        src->push(val);
    }
}

void removeDuplicates(Stack<string>* s) {
    MyStack<string> uniqueStack(MAX_SIZE);
    MyStack<string> temp(MAX_SIZE);
    string currentWord, checkWord;

    while (s->pop(currentWord)) {
        bool isDuplicate = false;

        while (uniqueStack.pop(checkWord)) {
            if (checkWord == currentWord) {
                isDuplicate = true;
            }
            temp.push(checkWord);
        }

        while (temp.pop(checkWord)) {
            uniqueStack.push(checkWord);
        }

        if (!isDuplicate) {
            uniqueStack.push(currentWord);
        }
    }

    while (uniqueStack.pop(currentWord)) {
        s->push(currentWord);
    }
}

void countFrequencies(Stack<string>* s, Stack<int>* freq) {
    MyStack<string> tempCopy(MAX_SIZE);
    MyStack<string> temp(MAX_SIZE);
    string val;

    while (s->pop(val)) {
        temp.push(val);
    }
    while (temp.pop(val)) {
        s->push(val);
        tempCopy.push(val);
    }

    string targetWord, currentWord;

    while (tempCopy.pop(targetWord)) {
        int count = 1;
        MyStack<string> remainingWords(MAX_SIZE);

        while (tempCopy.pop(currentWord)) {
            if (currentWord == targetWord) {
                count++;
            }
            else {
                remainingWords.push(currentWord);
            }
        }

        while (remainingWords.pop(currentWord)) {
            tempCopy.push(currentWord);
        }

        freq->push(count);
        cout << targetWord << ": " << count << "\n";
    }
}