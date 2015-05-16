#include<stdio.h>

extern int
cpfIsValid(const char *);

static void
usage(const char *);

int
main(int argc, char **argv)
{
  if (argc == 1) {
	usage(argv[0]);
	return -1;
  }
  printf("CPF %s is %s\n", argv[1], cpfIsValid(argv[1]) ? "valid" : "invalid");
  return 0;
}

static void
usage(const char *currProcess)
{
  printf("Usage: %s cpfnumber\n", currProcess);
}
