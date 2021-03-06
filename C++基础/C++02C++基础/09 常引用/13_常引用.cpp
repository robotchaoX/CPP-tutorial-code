#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void test01() {
    // int &ref = 10;//引用了不合法的内存，不可以
    const int &ref = 10; //加入const后 ，分配临时内存，编译器处理方式为：
    // int tmp = 10;
    // const int &ref = tmp;
    cout << "ref = " << ref << endl; // ref = 10;

    //! 可以通过指针修改const常量引用的值
    int *p = (int *)&ref; // 引用的指针
    *p = 1000; // 通过指针修改引用的值
    cout << "ref = " << ref << endl; // 1000
}

//常量引用使用场景 用来修饰形参
//如果只是想显示内容，而不修改内容，那么就用const修饰这个形参
void showValue(const int &val) {
    // val += 1000; // error 不可修改报错
    cout << "val = " << val << endl;
}
void test02() {
    int a = 10;
    showValue(a);
}

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}