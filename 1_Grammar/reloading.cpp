/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \reloading.cpp                                                                             *
* Project: 9_CppGrammar                                                                            *
* Created Date: Wednesday Jan 11th 2023, 4:27:05 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 11/01/2023 04:27:33                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <iostream>

using namespace std;

int add(int a);
int add(int a, int b);
int add(int a, int b, int c);

int main(){
    int a, b, c, res;
    cin >> a >> b >> c;
    res = add(a);
    cout << "The result of a+1 is " << res << endl;
    res = add(a, b);
    cout << "The result of a+1 is " << res << endl;
    res = add(a, b, c);
    cout << "The result of a+1 is " << res << endl;

    system("pause");

    return 0;
}

int add(int a){
    return ++a;
}

int add(int a, int b){
    return a + b;
}

int add(int a, int b, int c){
    return a + b + c;
}