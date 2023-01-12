/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \quotation.cpp                                                                             *
* Project: 9_CppGrammar                                                                            *
* Created Date: Wednesday Jan 11th 2023, 4:34:38 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 11/01/2023 04:35:33                                                               *
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

void increasing(int& a);

int main(){
    int a = 0;
    for(int i = 0; i < 10; i++){
        increasing(a);
        cout << a << endl;
    }

    system("pause");

    return 0;
}

void increasing(int& a){
    a++;
}