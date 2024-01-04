#ifndef H_EQUATION_H
#define H_EQUATION_H
#include <stdlib.h>
typedef struct {
  char **coefficients; // Coefficients des variables (X, Y, Z, ...)
  char constant;       // Terme constant
  bool hasConstant;
} Equation;
 #endif
