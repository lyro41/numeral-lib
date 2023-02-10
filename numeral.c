//! @file numeral.c
//! @authors Люпа Ростислав А.
//! @note Ответственный: Пышняк Марина О.
//! @brief Исходный файл с определениями библиотеки numeral-lib

#include <numeral.h>

#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum {
  kSign,
  kBase,
  kSep,
  kInt,
  kFloat,
  kExit,
  kError
};

int HexDigitToDec(const char digit) {
  if (isdigit(digit)) {
    return digit - '0';
  }
  if (digit >= 'A' && digit <= 'F') {
    return digit - 'A' + 10;
  }
  return -1;
}

int PosToDec(float *dec_number, const char* number) {
  const char kSeparator = 'x';
  unsigned pos = 0;
  char sign = '+';
  int base = 10;
  int digit;
  int float_mult = 1;
  float float_buff = 0;
  int state = kSign;
  *dec_number = 0;
  while (state != kExit) {
    switch (state) {
      case kSign:
        switch (number[pos]) {
          case '-':
            sign = '-';
            state = kBase;
            ++pos;
            break;
          case '+':
            sign = '+';
            state = kBase;
            ++pos;
            break;
          default:
            state = kBase;
            break;
        }
        break;
      case kBase:
        base = HexDigitToDec(number[pos]) + 1;
        if (base <= 1) {
          return pos;
        }
        state = kSep;
        ++pos;
        break;
      case kSep:
        if (number[pos] != kSeparator) {
          return pos;
        }
        state = kInt;
        ++pos;
        break;
      case kInt:
        if (number[pos] == '\0') {
          state = kExit;
          break;
        }
        if (number[pos] == '.') {
          state = kFloat;
          ++pos;
          break;
        }
        digit = HexDigitToDec(number[pos]);
        if (digit == -1 || digit >= base) {
          return pos;
        }
        *dec_number *= base;
        *dec_number += digit;
        ++pos;
        break;
      case kFloat:
        if (number[pos] == '\0') {
          *dec_number += float_buff;
          state = kExit;
          break;
        }
        digit = HexDigitToDec(number[pos]);
        if (digit == -1 || digit >= base) {
          return pos;
        }
        float_mult *= base;
        float_buff += (float)digit / float_mult;
        ++pos;
        break;
    }
  }
  return 0;
}

int TimeToSec(int *seconds, const char *time) {
  int h, m, s;
  int ret = sscanf(time, "%d:%d:%d", &h, &m, &s);
  if (ret != 3 || h >= 24 || m >= 60 || s >= 60) {
    return 1;
  }
  *seconds = 60 * (60 * h + m) + s;
  return 0;
}

int SecToTime(char *time, const int seconds) {
  int h = seconds / 3600 % 24;
  int m = seconds / 60 % 60;
  int s = seconds % 60;
  sprintf(time, "%02d:%02d:%02d", h, m, s);
  return 0;
}
