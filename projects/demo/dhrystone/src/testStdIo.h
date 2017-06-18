#include <briey.h>

#ifdef __cplusplus
extern "C" {
#endif



int close(int fd) {
	return 0;
}

int fstat(int fd, struct _stat *buffer) {
	return 0;
}

int isatty(int fd) {
	return 0;
}

long lseek(int fd, long offset, int origin) {
	return 0;
}

int read(int fd, void *buffer, unsigned int count) {
	return 0;
}


void writeChar(char value) {
	uart_write(UART,value);
}

void writeChars(char* value) {
	while (*value) {
		writeChar(*(value++));
	}
}

int write(int fd, const void *buffer, unsigned int count) {
	for (int idx = 0; idx < count; idx++) {
		writeChar(((char*) buffer)[idx]);
	}
	return count;
}

#ifdef __cplusplus
}
#endif





