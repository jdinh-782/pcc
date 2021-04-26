//
// Created by jdinh on 10/8/2020.
//

#ifndef CHAPTER11PROGRAMMINGPROJECT3_DECIMALBOOKINFO_H
#define CHAPTER11PROGRAMMINGPROJECT3_DECIMALBOOKINFO_H

#include <iostream>

using namespace std;

class DecimalBookInfo
{
private:
    float subcategoryCode;

public:
    string bookName;
    int subjectAreaCode = 516;
    float decimalClassificationNumber;

    DecimalBookInfo();
    DecimalBookInfo(string bookNameInput, float subcategoryCodeInput);

    float getDecimalClassificationNumber();

    bool operator <(const DecimalBookInfo& num);
    bool operator <=(const DecimalBookInfo& num);
    bool operator >(const DecimalBookInfo& num);
    bool operator >=(const DecimalBookInfo& num);


};


#endif //CHAPTER11PROGRAMMINGPROJECT3_DECIMALBOOKINFO_H
