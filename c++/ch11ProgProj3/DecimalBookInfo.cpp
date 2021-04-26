//
// Created by jdinh on 10/8/2020.
//

#include "DecimalBookInfo.h"

DecimalBookInfo::DecimalBookInfo()
{
    bookName = "The Legend";
    subcategoryCode = 0.1;
}


DecimalBookInfo::DecimalBookInfo(string bookNameInput, float subcategoryCodeInput)
{
    bookName = bookNameInput;
    subcategoryCode = subcategoryCodeInput;
}


float DecimalBookInfo::getDecimalClassificationNumber()
{
    decimalClassificationNumber = subjectAreaCode + subcategoryCode;
    return decimalClassificationNumber;
}


bool DecimalBookInfo::operator <(const DecimalBookInfo& num)
{
    if (subcategoryCode < num.subcategoryCode)
    {
        return true;
    }
    return false;
}


bool DecimalBookInfo::operator <=(const DecimalBookInfo& num)
{
    if (subcategoryCode <= num.subcategoryCode)
    {
        return true;
    }
    return false;
}


bool DecimalBookInfo::operator >(const DecimalBookInfo& num)
{
    if (subcategoryCode > num.subcategoryCode)
    {
        return true;
    }
    return false;
}


bool DecimalBookInfo::operator >=(const DecimalBookInfo& num)
{
    if (subcategoryCode >= num.subcategoryCode)
    {
        return true;
    }
    return false;
}