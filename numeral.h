//! @file numeral.c
//! @authors Люпа Ростислав А.
//! @note Ответственный: Пышняк Марина О.
//! @brief Исходный файл с заголовками библиотеки numeral-lib

#ifndef NUMERAL_H
#define NUMERAL_H

int HexDigitToDec(const char digit);
int PosToDec(float *dec_number, const char* number);
int TimeToSec(int *seconds, const char *time);
int SecToTime(char *time, const int seconds);

#endif // NUMERAL_H
