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

#define GC_NOT_DLL
#include "gc_cpp.h"
#include <iostream>

class hoe : public gc_cleanup{
public:
  char p[0x100];
  virtual ~hoe() {
      std::cout << "~hoe()" << std::endl;
  }
};

int main()
{
    // int, string, doubleのオブジェクトが格納されうる型
    boost::variant<int, std::string, double> v;

    v = 3; // int型の値を代入
    std::cout << v << std::endl;
    boost::apply_visitor(var_printer(), v); // visitorで型ごとの処理を行う

    v = "hello"; // 文字列を代入
    std::cout << v << std::endl;
    boost::apply_visitor(var_printer(), v);

    while(1){
      hoe *h = new hoe;
    }
    return 0;
}
