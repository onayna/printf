#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct func - Defining struct
 *
 * @func: The format.
 * @fn: An array of pointers to the associated function.
 */
struct func
{
	char func;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct func func_t - Defining new type struc
 *
 * @func: The format.
 * @func_t: The function associated with the new type.
 */
typedef struct func func_t;

int _printf(const char *format, ...);
int handle_print(const char *func, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* FUNCTIONS */

/* Printing characters and strings */
int print_character(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Printing numbers */
int print_integer(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadec(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list args, char map_to[],
char buffer[], int flags, char flag_check, int width, int precision, int size);

/* Printing non printable characters */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Printing memory address */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Handling other specifiers */
int get_flags(const char *format, int *a);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *x);

/*Function to print string in reverse*/
int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision,
	int length, char padd, char extra_char);
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int index,
char buffer[],
	int flags, int width, int precision, int size);

/* UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif
