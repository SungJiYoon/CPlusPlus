#include <iostream>
#include <string>

using namespace std;
// string 문자열의 문자의 갯수를 돌려주는 기능.
class ExtString : public std::string {
public:
    ExtString() {}

    ExtString(char* pstr)
        : std::string(pstr) {}

    ExtString(std::string str)
        : std::string(str) {}

    int GetLength() {
        const char* pstr = c_str();   // c_str() : 문자열이 저장된 선두번째 메모리주소값을 전달하는 string 클래스의 멤버함수
                                      // const로 받은 이유는 선두번째 주소값을 바꾸지말라, 변경되지 말라는 의미로 cosnt로 정의함

        int count = 0;
        for (count = 0; pstr[count] != 0; count++);

        return count;
    }
};


int main() {
    using namespace std;

    ExtString str((char*)"monster");

    cout << "str 문자열 길이: " << str.GetLength() << endl;

    cout << "str = " << str << endl;


    string str2 = "I am a boy!!";
    ExtString extStr(str2);

    cout << "extStr 문자열 길이: " << extStr.GetLength() << endl;
    cout << extStr << endl;

    ExtString str3 = str + extStr;

    cout << "str3 문자열 길이: " << str3.GetLength() << endl;
    cout << str3 << endl;


    return 0;
}