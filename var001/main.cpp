#if 0x0

#include "mainwindow.h"
#include <QApplication>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
    qDebug() << "hello!";
}
#endif

#include <iostream>
#include <string>
#include <boost/variant.hpp>

struct var_printer : boost::static_visitor<void> {
    void operator()(int x) const
        { std::cout << x << std::endl; }

    void operator()(std::string& s) const
        { std::cout << s << std::endl; }

    void operator()(double x) const
        { std::cout << x << std::endl; }
};

int main()
{
    // int, string, doubleのオブジェクトが格納されうる型
    boost::variant<int, std::string, double> v;

    v = 3; // int型の値を代入
    boost::apply_visitor(var_printer(), v); // visitorで型ごとの処理を行う

    v = "hello"; // 文字列を代入
    boost::apply_visitor(var_printer(), v);
}
