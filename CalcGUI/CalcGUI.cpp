#include "CalcGUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include "Calculator.h"


Calculator myCalculator;

bool operationActive = false;
bool equalBtnPressed = false;

//Calculator GUI Setup

CalcGUI::CalcGUI(QWidget *parent) : QWidget(parent)
{

    //Display Setup
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setMinimumSize(200,100);

    QFont font = display->font();
        font.setPointSize(font.pointSize() + 20);
        display->setFont(font);

    QHBoxLayout *displayBox = new QHBoxLayout;
    displayBox->addWidget(display);




    //Numerical Buttons Setup
    QPushButton *numericalButtons[10];

    for ( int i = 0; i < 10; i++ ) {
        QString digit = QString :: number(i);
        numericalButtons[i] = new QPushButton(digit);
        numericalButtons[i]->setMinimumSize( 50, 50 );
        connect ( numericalButtons[i], SIGNAL( clicked() ), this, SLOT( numberClicked() ) );
    }




    //Operational Buttons Setup
    QPushButton *btnAdd = new QPushButton("+");
    btnAdd->setMinimumSize( 50, 50 );
    connect( btnAdd, SIGNAL( clicked() ), this, SLOT ( handleOperation() ) );

    QPushButton *btnSubtract = new QPushButton("-");
    btnSubtract->setMinimumSize( 50, 50 );
    connect( btnSubtract, SIGNAL( clicked() ), this, SLOT ( handleOperation() ) );

    QPushButton *btnMultuply = new QPushButton("X");
    btnMultuply->setMinimumSize( 50, 50 );
    connect( btnMultuply, SIGNAL( clicked() ), this, SLOT ( handleOperation() ) );

    QPushButton *btnDivide = new QPushButton("/");
    btnDivide->setMinimumSize( 50, 50 );
    connect( btnDivide, SIGNAL( clicked() ), this, SLOT ( handleOperation() ) );

    QPushButton *btnClear = new QPushButton("C");
    btnClear->setMinimumSize( 50, 50 );
    connect( btnClear, SIGNAL( clicked() ), this, SLOT( clear() ) );

    QPushButton *btnClearEntry = new QPushButton("CE");
    btnClearEntry->setMinimumSize( 50, 50 );
    connect( btnClearEntry, SIGNAL( clicked() ), this, SLOT( clearEntry() ) );

    QPushButton *btnDecimal = new QPushButton(".");
    btnDecimal->setMinimumSize( 50, 50 );
    connect( btnDecimal, SIGNAL( clicked() ), this, SLOT( decimal() ) );

    QPushButton *btnEquals = new QPushButton("=");
    btnEquals->setMinimumSize( 50, 50 );
    connect( btnEquals, SIGNAL( clicked() ), this, SLOT ( equalsPressed() ) );

    QPushButton *btnSQRT = new QPushButton("√");
    btnSQRT->setMinimumSize( 50, 50 );
    connect( btnSQRT, SIGNAL( clicked() ), this, SLOT ( handleOperation() ) );

    QPushButton *btnDelete = new QPushButton("DEL");
    btnDelete->setMinimumSize( 50, 50 );
    connect( btnDelete, SIGNAL( clicked() ), this, SLOT( backspace() ) );

    QPushButton *btnPercent = new QPushButton("%");
    btnPercent->setMinimumSize( 50, 50 );
    connect( btnPercent, SIGNAL( clicked() ), this, SLOT( percentage() ) );

    QPushButton *btnOneOverX = new QPushButton("1/x");
    btnOneOverX->setMinimumSize( 50, 50 );
    connect( btnOneOverX, SIGNAL( clicked() ), this, SLOT( oneOverX() ) );

    QPushButton *btnXSquared = new QPushButton("x²");
    btnXSquared->setMinimumSize( 50, 50 );
    connect( btnXSquared, SIGNAL( clicked() ), this, SLOT( xSquared() ) );

    QPushButton *btnPlusMinus = new QPushButton ("±");
    btnPlusMinus->setMinimumSize( 50, 50 );
    connect( btnPlusMinus, SIGNAL( clicked() ), this, SLOT( plusMinus() ) );





    //Layouts Setup
    QHBoxLayout *hButtonsRow1 = new QHBoxLayout;
    hButtonsRow1->addWidget(btnPercent);
    hButtonsRow1->addWidget(btnSQRT);
    hButtonsRow1->addWidget(btnXSquared);
    hButtonsRow1->addWidget(btnOneOverX);

    QHBoxLayout *hButtonsRow2 = new QHBoxLayout;
    hButtonsRow2->addWidget(btnClearEntry);
    hButtonsRow2->addWidget(btnClear);
    hButtonsRow2->addWidget(btnDelete);
    hButtonsRow2->addWidget(btnDivide);

    QHBoxLayout *hButtonsRow3 = new QHBoxLayout;
    hButtonsRow3->addWidget(numericalButtons[7]);
    hButtonsRow3->addWidget(numericalButtons[8]);
    hButtonsRow3->addWidget(numericalButtons[9]);
    hButtonsRow3->addWidget(btnMultuply);

    QHBoxLayout *hButtonsRow4 = new QHBoxLayout;
    hButtonsRow4->addWidget(numericalButtons[4]);
    hButtonsRow4->addWidget(numericalButtons[5]);
    hButtonsRow4->addWidget(numericalButtons[6]);
    hButtonsRow4->addWidget(btnSubtract);

    QHBoxLayout *hButtonsRow5 = new QHBoxLayout;
    hButtonsRow5->addWidget(numericalButtons[1]);
    hButtonsRow5->addWidget(numericalButtons[2]);
    hButtonsRow5->addWidget(numericalButtons[3]);
    hButtonsRow5->addWidget(btnAdd);

    QHBoxLayout *hButtonsRow6 = new QHBoxLayout;
    hButtonsRow6->addWidget(btnPlusMinus);
    hButtonsRow6->addWidget(numericalButtons[0]);
    hButtonsRow6->addWidget(btnDecimal);
    hButtonsRow6->addWidget(btnEquals);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(displayBox);
    mainLayout->addLayout(hButtonsRow1);
    mainLayout->addLayout(hButtonsRow2);
    mainLayout->addLayout(hButtonsRow3);
    mainLayout->addLayout(hButtonsRow4);
    mainLayout->addLayout(hButtonsRow5);
    mainLayout->addLayout(hButtonsRow6);

    setLayout(mainLayout);

}




void CalcGUI :: numberClicked() {
    QPushButton *senderButton = dynamic_cast<QPushButton*>(sender());

    if ( equalBtnPressed == true ) {
        myCalculator.clear();
        display->setText( senderButton->text() );
        equalBtnPressed = false;
    }

    else if ( operationActive == true || display->text() == "0") {
        display->setText( senderButton->text() );
        operationActive = false;
    }

    else {
        display->setText( display->text() + senderButton->text() );
    }
}

void CalcGUI :: handleOperation() {
    operationActive = true;

    QString displayString = display->text();
    double displayNumber = displayString.toDouble();

    myCalculator.store( displayNumber );
    double value;
    QPushButton *senderButton = dynamic_cast<QPushButton*>(sender());

        if ( senderButton->text() == "+" ) {
            if ( equalBtnPressed == true ) {
                myCalculator.changeOperation( myCalculator.ADD );
                equalBtnPressed = false;
                value = displayNumber;
            }
            else {
            value = myCalculator.handleOperation( myCalculator.ADD );
            }
            myCalculator.store( 0 );
        }

        else if ( senderButton->text() == "-" ) {
            if ( equalBtnPressed == true ) {
                myCalculator.changeOperation( myCalculator.SUBTRACT );
                equalBtnPressed = false;
                value = displayNumber;
            }
            else {
            value = myCalculator.handleOperation( myCalculator.SUBTRACT );
            }
            myCalculator.store( 0 );
        }

        else if ( senderButton->text() == "X" ) {
            if ( equalBtnPressed == true ) {
                myCalculator.changeOperation( myCalculator.MULTIPLY );
                equalBtnPressed = false;
                value = displayNumber;
            }
            else {
            value = myCalculator.handleOperation( myCalculator.MULTIPLY );
            }
            myCalculator.store( 0 );
        }

        else if ( senderButton->text() == "/" ) {
            if ( equalBtnPressed == true ) {
                myCalculator.changeOperation( myCalculator.DIVIDE );
                equalBtnPressed = false;
                value = displayNumber;
            }
            else {
            value = myCalculator.handleOperation( myCalculator.DIVIDE );
            }
            myCalculator.store( 0 );
        }

        else if ( senderButton->text() == "√" ) {
            myCalculator.sqrtPressed();
            value = myCalculator.getNum2();
        }

    QString newValue = QString::number(value);
    display->setText( newValue );
}

void CalcGUI :: equalsPressed() {
    equalBtnPressed = true;
    if ( myCalculator.getNum2() == 0 ) {
        QString displayString = display->text();
        double displayNumber = displayString.toDouble();
        myCalculator.store( displayNumber );
    }
    double value = myCalculator.equalsPressed();
    QString newValue = QString :: number(value);
    display->setText( newValue );
}

void CalcGUI :: clear() {
    display->setText("0");
    operationActive = false;
    equalBtnPressed = false;
    myCalculator.clear();
}


void CalcGUI :: clearEntry() {
    display->setText("0");
}


void CalcGUI :: backspace() {
    QString displayString = display->text();
    if ( displayString.size() > 1 ) {
        displayString = displayString.left(displayString.size()-1);
        display->setText( displayString );
    }
    else {
        display->setText("0");
    }
}


void CalcGUI :: decimal() {
    QString displayString = display->text();
    if ( displayString.contains(".") ) {
    }
    else {
        display->setText( displayString + "." );
    }

}


void CalcGUI :: percentage() {
    QString displayString = display->text();
    double value = displayString.toDouble();
    value = myCalculator.getNum1() * ( value / 100 );
    displayString = QString :: number( value );
    display->setText( displayString );
}

void CalcGUI :: xSquared() {
    QString displayString = display->text();
    double value = displayString.toDouble();
    value = value * value;
    displayString = QString :: number( value );
    display->setText( displayString );
}


void CalcGUI :: oneOverX() {
    QString displayString = display->text();
    double value = displayString.toDouble();
    value = 1 / value;
    displayString = QString :: number( value );
    display->setText( displayString );
}


void CalcGUI :: plusMinus() {
    QString displayString = display->text();
    double value = displayString.toDouble();
    value = value * ( -1 );
    displayString = QString :: number( value );
    display->setText( displayString );
}




