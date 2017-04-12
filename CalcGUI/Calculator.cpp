#include "Calculator.h"
#include <stdexcept>
#include <cmath>
using namespace std;

Calculator::Calculator() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}

void Calculator::store(double value) {
    num2 = value;
}

double Calculator::handleOperation(Calculator::opType newOperation) {
    if ( oper == NONE ) {
        num1 = num2;
        oper = newOperation;
        return num1;
    }

    if ( newOperation == SQRT ) {
        this->sqrtPressed();
        return num2;
    }



    num1 = this->equalsPressed();

    oper = newOperation;

    return num1;
}

double Calculator::equalsPressed() {
    switch ( oper ) {
    case ADD:
        num1 = num1 + num2;
        return num1;

    case SUBTRACT:
        num1 = num1 - num2;
        return num1;

    case MULTIPLY:
        num1 = num1 * num2;
        return num1;

    case DIVIDE:
        num1 = num1 / num2;
        return num1;

    default:
        break;
    }

    return 0;
}

void Calculator::clear() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}

void Calculator::sqrtPressed() {
    num2 = sqrt ( num2 );
}

double Calculator :: getNum1() {
    return num1;
}

double Calculator :: getNum2() {
    return num2;
}

void Calculator :: changeOperation ( opType newOperation ) {
    oper = newOperation;
}
