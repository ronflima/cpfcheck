/*
 * CPF Validation Demo
 * Copyright (C) 2015 - Ronaldo Faria Lima
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define CPF_SIZE 11

static int
checkDigit(const char *, int);
static int
isSingleDigit(const char *);
static int
hasAlpha(const char *);
static int
getCheckDigit(const char *);

int
cpfIsValid(const char *cpf)
{
  int ckDigit, calculatedCkDigit;
  
  if (cpf == NULL) {
	return 0;
  }
  if (strlen(cpf) != CPF_SIZE) {
	return 0;
  }
  if (hasAlpha(cpf)) {
	return 0;
  }  
  if (isSingleDigit(cpf)) {
	return 0;
  }
  ckDigit = getCheckDigit(cpf);
  calculatedCkDigit = checkDigit(cpf, 10) * 10 + checkDigit(cpf, 11);
  return (ckDigit == calculatedCkDigit);
}

static int
checkDigit(const char *cpf, int weight)
{
  int checkDigit = 0;
  int i;
  int len = strlen(cpf);
  for (i = 0; i < len && weight > 1; ++i, --weight) {
	checkDigit += (cpf[i] - '0') * weight;
  }
  int remainder = checkDigit % 11;
  checkDigit = remainder < 2 ? 0 : 11 - remainder;
  return checkDigit;
}

static int
isSingleDigit(const char *cpf)
{
  int singleDigit = 1;
  ++cpf;
  do {
	singleDigit = singleDigit && (*(cpf - 1) == *cpf);
	++cpf;
  } while (*cpf && singleDigit);
  return singleDigit;
}

static int
hasAlpha(const char *cpf)
{
  do {
	if (! isdigit(*cpf)) {
	  return 1;
	}
  } while(*(++cpf));
  return 0;
}

static int
getCheckDigit(const char *cpf)
{
  cpf += strlen(cpf) - 2;
  return atoi (cpf);
}
