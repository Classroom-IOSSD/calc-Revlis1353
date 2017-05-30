#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...){
	va_list list;
	va_start(list, format);
	while(*format) {
		if(*format == '%'){
			format++;
			switch(*format) {
			
			case 'c':
				{
					char c = getc(fp);
					while(c == ' ')
						c = getc(fp);
					*va_arg(list, char*) = c;
					break;
				}
			case 'd':
				{
					char c = getc(fp);
					int i, result = 0;
					while(c == ' ')
						c = getc(fp);
					for(i = 0; isdigit(c); i++){
						result *= 10;
						result += c - '0';
						c = getc(fp);
					}
					*va_arg(list, int*) = result;
				break;
				}
			}
		}
		else
			format++;
	}
	va_end(list);
}
