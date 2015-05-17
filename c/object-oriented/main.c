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

#include<stdio.h>
#include "cpf.h"

static void
usage(const char *);

int
main(int argc, char **argv)
{
  if (argc == 1) {
	usage(argv[0]);
	return -1;
  }
  cpf_t cpf = cpf_new(argv[1]);
  printf("CPF %s is %s\n", argv[1], cpf_is_valid(cpf) ? "valid" : "invalid");
  cpf_destroy(cpf);
  return 0;
}

static void
usage(const char *currProcess)
{
  printf("Usage: %s cpfnumber\n", currProcess);
}
