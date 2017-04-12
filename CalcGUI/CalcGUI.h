#ifndef CALCGUI_H
#define CALCGUI_H

#include <QWidget>
#include <QLineEdit>

class CalcGUI : public QWidget
{
    Q_OBJECT
public:
    explicit CalcGUI(QWidget *parent = 0);

signals:

public slots:
    void numberClicked();
    void handleOperation();
    void equalsPressed();
    void clear();
    void clearEntry();
    void backspace();
    void decimal();
    void percentage();
    void xSquared();
    void oneOverX();
    void plusMinus();



private:
    QLineEdit *display;
};

#endif // CALCGUI_H
