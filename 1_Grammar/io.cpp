/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \io.cpp                                                                                    *
* Project: 9_CppGrammar                                                                            *
* Created Date: Wednesday Jan 11th 2023, 2:41:29 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 11/01/2023 03:02:15                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <iostream>
#include <string>

using namespace std;

int main(){
    int a;
    char c[80];
    string b;
    getline(cin, b);
    cin.getline(c, 8);
    cout << "Hello, " << b << " and " << c << endl;

    system("pause");

    return 0;
}