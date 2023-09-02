#include <QtTest>
#include "../untitled/solver.h"
#include "qtestcase.h"
using namespace std;
// add necessary includes here

class novo_testiranje : public QObject
{
    Q_OBJECT

public:
    novo_testiranje();
    ~novo_testiranje();

private slots:
    void test_wrong_input_dnf();
    void test_wrong_input_cnf();
    void test_wrong_input_cnf2();
    void test_is_literal_pure();
    void test_is_literal_pure_f();
    void test_find_pure_literal();
    void test_find_pure_literal_f();
    void test_empty_clause();
    void test_empty_clause_f();
    void test_find_literal();
    void test_find_literal_f();
    void test_unit_clause();
    void test_unit_clause_f();
    void test_tautolgy_clause();
    void test_tautolgy_clause_f();
    void test_delete_duplicates();

};

novo_testiranje::novo_testiranje()
{

}

novo_testiranje::~novo_testiranje()
{

}

void novo_testiranje::test_wrong_input_dnf()
{
    //QSKIP("ne proverava se ispravnost ulaza\n");
    std::string s="c ovo je komentar\np dnf 3 2\n 1 -2 3 0\n -1 2 0\n";
    std::stringstream sad(s);
    //Solver tmp(sad);

    //QVERIFY_EXCEPTION_THROWN(Solver tmp(sad),QException);
    QEXPECT_FAIL("", "Ne proverava ispravnost", Continue);
    QVERIFY_THROWS_EXCEPTION(QException,Solver tmp(sad));
}
void novo_testiranje::test_wrong_input_cnf()
{
    //QSKIP("ne proverava se ispravnost ulaza\n");
    std::string s="p cnf 3 2\n 1 8 3 0\n -1 -3 8 0\n";
    std::stringstream sad(s);
    //Solver tmp(sad);
    QEXPECT_FAIL("", "Ne proverava ispravnost", Continue);
    QVERIFY_THROWS_EXCEPTION(QException,Solver tmp(sad));
}
void novo_testiranje::test_wrong_input_cnf2()
{
    QSKIP("ne proverava se ispravnost ulaza\n");
    std::string s="p cnf 3 2\n 1 -2 3 0\n -1 -3 2 \n";
    std::stringstream sad(s);
    //Solver tmp(sad);
    QVERIFY_THROWS_EXCEPTION(QException,Solver tmp(sad));
}
void novo_testiranje::test_find_pure_literal()
{
    std::string s="p cnf 3 3\n 1 -2 3 0\n 1 -3 0\n 2 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.contains_pure_literal(),1);
}
void novo_testiranje::test_find_pure_literal_f()
{
    std::string s="p cnf 3 3\n 1 -2 3 0\n -1 -3 0\n 2 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.contains_pure_literal(),NullLiteral);
}
void novo_testiranje::test_is_literal_pure()
{
    std::string s="p cnf 3 2\n 1 -2 0\n 1 2 -3 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QVERIFY(tmp.pure_literal(1));
}
void novo_testiranje::test_is_literal_pure_f()
{
    std::string s="p cnf 3 2\n 1 -2 0\n -1 2 -3 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.pure_literal(1),false);
}
void novo_testiranje::test_empty_clause()
{
    std::string s="p cnf 3 2\n 1 -2 0\n 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.contains_empty_clause(),true);
}
void novo_testiranje::test_empty_clause_f()
{
    std::string s="p cnf 3 2\n 1 -2 0\n 1 2 -3 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.contains_empty_clause(),false);
}
void novo_testiranje::test_find_literal()
{
    std::string s="p cnf 3 2\n 1 2 3 0\n -1 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.find_literal(),1);
}
void novo_testiranje::test_find_literal_f()
{
    std::string s="p cnf 3 2\n 1 -2 3 0\n 1 -2 3 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.find_literal(),NullLiteral);
}
void novo_testiranje::test_unit_clause(){
    std::string s="p cnf 3 3\n 1 -2 3 0\n 1 -2 3 0\n -1 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.unit_clause(),-1);
}
void novo_testiranje::test_unit_clause_f(){
    std::string s="p cnf 3 2\n 1 -2 3 0\n 1 -2 3 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);

    QCOMPARE(tmp.unit_clause(),NullLiteral);
}
void novo_testiranje::test_tautolgy_clause(){
    Clause clause;
    clause.push_back(1);
    clause.push_back(-1);
    std::string s="p cnf 3 2\n  0\n  0\n";
    std::stringstream sad(s);
    Solver tmp(sad);
    QCOMPARE(tmp.tautology(clause),true);

}
void novo_testiranje::test_tautolgy_clause_f(){
    Clause clause;
    clause.push_back(1);
    clause.push_back(-2);
    std::string s="p cnf 3 2\n  0\n 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);
    QCOMPARE(tmp.tautology(clause),false);

}
void novo_testiranje::test_delete_duplicates(){
    Clause clause;
    clause.push_back(1);
    clause.push_back(-2);
    clause.push_back(-1);
    clause.push_back(-1);
    clause.push_back(-2);
    std::string s="p cnf 3 2\n  0\n 0\n";
    std::stringstream sad(s);
    Solver tmp(sad);
    tmp.delete_duplicates(clause);
    QCOMPARE(clause.size(),3);

}

QTEST_APPLESS_MAIN(novo_testiranje)

#include "tst_novo_testiranje.moc"
