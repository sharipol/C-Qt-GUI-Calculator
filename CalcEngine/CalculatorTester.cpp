
#include "catch.hpp"
#include "Calculator.h"
using namespace std;


TEST_CASE( "Calculator/opsplus", "Basic operations + " ) {
    Calculator c;
    c.store(3);
    double result1 = c.handleOperation(Calculator::ADD);
    REQUIRE( result1 == Approx(3) );
    c.store(2);
    double result2 = c.equalsPressed();
    REQUIRE( result2 == Approx(5) );
}

TEST_CASE( "Calculator/opsminus", "Basic operations - " ) {
    Calculator c;
    c.store(3);
    double result1 = c.handleOperation(Calculator::SUBTRACT);
    REQUIRE( result1 == Approx(3) );
    c.store(2);
    double result2 = c.equalsPressed();
    REQUIRE( result2 == Approx(1) );
}

TEST_CASE( "Calculator/opstimes", "Basic operations * " ) {
    Calculator c;
    c.store(3);
    double result1 = c.handleOperation(Calculator::MULTIPLY);
    REQUIRE( result1 == Approx(3) );
    c.store(2);
    double result2 = c.equalsPressed();
    REQUIRE( result2 == Approx(6) );
}

TEST_CASE( "Calculator/opsdivide", "Basic operations / " ) {
    Calculator c;
    c.store(3);
    double result1 = c.handleOperation(Calculator::DIVIDE);
    REQUIRE( result1 == Approx(3) );
    c.store(2);
    double result2 = c.equalsPressed();
    REQUIRE( result2 == Approx(1.5) );
}

TEST_CASE( "Calculator/chain", "Basic operations chain " ) {
    Calculator c;
    c.store(3);
    double result1 = c.handleOperation(Calculator::ADD);
    REQUIRE( result1 == Approx(3) );
    c.store(5);
    double result2 = c.handleOperation(Calculator::SUBTRACT);
    REQUIRE( result2 == Approx(8) );
    c.store(2);
    double result3 = c.equalsPressed();
    REQUIRE( result3 == Approx(6) );
}

TEST_CASE( "Calculator/equalsChain", "Tests hitting equals multiple times" ) {
    //" 3 + 2 = = " should make 7
    Calculator c;
    c.store(3);
    double result1 = c.handleOperation(Calculator::ADD);
    REQUIRE( result1 == Approx(3) );
    c.store(2);
    double result2 = c.equalsPressed();
    REQUIRE( result2 == Approx(5) );
    double result3 = c.equalsPressed();
    REQUIRE( result3 == Approx(7) );
}

TEST_CASE( "Calculator/sqrRoot", "Test square root" ) {
    //" 9 - root(16) --> 5"
    Calculator c;
    c.store(9);
    double result1 = c.handleOperation(Calculator::SUBTRACT);

    c.store(16);
    double result2 = c.handleOperation(Calculator::SQRT);
    REQUIRE( result2 == Approx(4) );

    double result3 = c.equalsPressed();
    REQUIRE( result3 == Approx(5) );
}
