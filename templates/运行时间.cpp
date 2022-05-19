#include <iostream>
#include <cstdio>
#include <chrono> // 头文件chrono 自c++ 11起

using namespace std::chrono; // chrono的所有函数都存储在命名空间chrono中

int main(){
    // 核心部分
    auto start = system_clock::now(); // 获取代码开始时的时间戳
    //...代码部分
    auto finish = system_clock::now(); // 获取代码结束时的时间戳

    // 计算时间差，对结果进行微秒类型转换
    // 除microseconds，还可以使用
    // hours(小时), minutes（分钟）, seconds（秒）, milliseconds（毫秒）, nanoseconds（纳秒）
    auto duration = duration_cast<microseconds>(finish - start);

    // count计算时间差 
    // xx::period::num / xx::period::den (分子和分母) 
    // 简单来说就是一种单位换算之间的比例关系，这里是微秒 / 秒(1 / 1e6)
    auto cost = double(duration.count()) * microseconds::period::num / microseconds::period::den;
    return 0;
}