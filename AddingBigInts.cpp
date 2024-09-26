#include<iostream>
#include<string>
using namespace std;
string add(string a, string b){
    string result = "";
    int carry = 0;
    int i = a.size()-1;
    int j = b.size()-1;
    while(i>=0 || j>=0 || carry){
        int sum = carry;
        if(i>=0){
            sum += a[i--]-'0';
        }
        if(j>=0){
            sum += b[j--]-'0';
        }
        carry = sum/10;
        result = to_string(sum%10)+result;
    }
    return result;
}
int main(){
    string a = "2345566777844567";
    string b = "9999988777765768009998";
    string sum = add(a, b);
    cout << "Sum: "<< sum<< endl;
    return 0;
}