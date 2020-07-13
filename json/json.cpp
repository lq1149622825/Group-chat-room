#include "json.hpp"
using json = nlohmann :: json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//json序列化示例1
void func1()
{
    json js;
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="li si";
    js["msg"]="hell,waht are you doing!";

    //cout<<js<<endl; //实现序列化的json字符串  js对象提供了输出运算符的重载函数

    //将json序列化后的数据转成字符串发送  在网络中进行发送
    string sendBuf=js.dump();//jump输出的意思
    cout<<sendBuf.c_str()<<endl;//网络传送是char*传送 c_str方法打印数据 

}
//json序列化示例2
void func2()
{
    json js; 
    // 添加数组 
    js["id"] = {1,2,3,4,5}; 
    // 添加key-value 
    js["name"] = "zhang san"; 
    // 添加对象 
    js["msg"]["zhang san"] = "hello world"; 
    js["msg"]["liu shuo"] = "hello china"; 
    // 上面等同于下面这句一次性添加数组对象 
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}}; 
    cout << js << endl;
}

//json序列化示例代码3
void func3()
{
    json js; 
    // 直接序列化一个vector容器 
    vector<int> vec; 
    vec.push_back(1); 
    vec.push_back(2); 
    vec.push_back(5); 
    
    js["list"] = vec; 
    // 直接序列化一个map容器 
    map<int, string> m; 
    m.insert({1, "黄山"}); 
    m.insert({2, "华山"}); 
    m.insert({3, "泰山"}); 
    
    js["path"] = m; 
    //cout<<js<<endl;

    string SendBuff=js.dump();
    cout<<SendBuff<<endl;
}

//json反序列化示例1
string func4()
{
    json js;
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="li si";
    js["msg"]="hell,waht are you doing!";

    //cout<<js<<endl; //实现序列化的json字符串  js对象提供了输出运算符的重载函数

    //将json序列化后的数据转成字符串发送  在网络中进行发送
    string sendBuf=js.dump();//jump输出的意思
    //cout<<sendBuf.c_str()<<endl;//网络传送是char*传送 c_str方法打印数据 
    return sendBuf;

}
//json反序列化示例2
string func5()
{
    json js; 
    // 添加数组 
    js["id"] = {1,2,3,4,5}; 
    // 添加key-value 
    js["name"] = "zhang san"; 
    // 添加对象 
    js["msg"]["zhang san"] = "hello world"; 
    js["msg"]["liu shuo"] = "hello china"; 
    // 上面等同于下面这句一次性添加数组对象 
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}}; 
    //cout << js << endl;
    string SendBuff=js.dump();
    return SendBuff;
}

//json反序列化示例代码3
string func6()
{
    json js; 
    // 直接序列化一个vector容器 
    vector<int> vec; 
    vec.push_back(1); 
    vec.push_back(2); 
    vec.push_back(5); 
    
    js["list"] = vec; 
    // 直接序列化一个map容器 
    map<int, string> m; 
    m.insert({1, "黄山"}); 
    m.insert({2, "华山"}); 
    m.insert({3, "泰山"}); 
    
    js["path"] = m; 
    //cout<<js<<endl;

    string SendBuff=js.dump();
    return SendBuff;
}

int main()
{
    func1();
    func2();
    func3();

    string recvBuf1=func4();
    //数据的反序列化 json字符串反序列化 数据对象 看做容器  方便访问
    json jsbuf1=json::parse(recvBuf1);
    cout<<jsbuf1["msg_type"]<<endl;
    cout<<jsbuf1["from"]<<endl;
    cout<<jsbuf1["to"]<<endl;
    cout<<jsbuf1["msg"]<<endl;

    cout<<endl;

    string recvBuf2=func5();
    json jsbuf2=json::parse(recvBuf2);
    cout<<jsbuf2["id"]<<endl;
    cout<<jsbuf2["name"]<<endl;
    cout<<jsbuf2["msg"]<<endl;

    auto arr=jsbuf2["id"];
    cout<<arr[2]<<endl;


    string recvBuf3=func6();
    json jsbuf3=json::parse(recvBuf3);
    vector<int> vec = jsbuf3["list"];//将js对象里面的数据类型 直接放入vector容器中
    for(int &v : vec)
    {
        cout<<v<<" ";
    }
    cout<<endl;

    map<int,string> mymap = jsbuf3["path"];
    for(auto &p : mymap)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;

    return 0;
}
