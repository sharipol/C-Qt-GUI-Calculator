#include <iostream>
#include "Calculator.h"
#include "CalcGUI.h"
#include <QApplication>

using namespace std;

int main( int argc, char *argv[] )
{
    QApplication app ( argc, argv );

    CalcGUI calc;
    calc.show();

    return app.exec();
}

