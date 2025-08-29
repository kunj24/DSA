#include<iostream>
using namespace std;
void fun(string str,int i,int j){

    if(i<=j)
    {
        if(str[i]==str[j])
        {
            fun(str,i+1,j-1);
        }
        else{
            cout<<"This is not pallindrome"<<endl;
            return ;
        }
    }
    else{
    cout<<"palindrome"<<endl;
    }

}

int main(){

    string str="abaa";
    fun(str,0,str.length()-1);
    return 0;
}

