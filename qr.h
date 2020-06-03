#ifndef __QR_H__
#define __QR_H__

typedef enum {
	TYPE_ANSI,
	TYPE_UNICODE
} output_type_e;

void parseMessage(char* filename, const char* freetext, unsigned char test_vector[], output_type_e out_type);
#endif
