#ifndef _H_CRC32_
#define _H_CRC32_

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <inttypes.h>
#include <comdef.h>
#include "SummationChecksum.h"
#include <fstream>
#include <vector>

#define DEFAULT_FILE "default.bin"
#define Poly 0xEDB88320L	//CRC32 standard




class Ccrc32 {
public:
	Ccrc32();
	~Ccrc32();
	C_SChecksum* _class_checksum;
	static uint32_t bytesAmount[1];
	const char base = 0x30;
	static uint32_t cChecksum[1];
private:
	static uint32_t crc_tab32[256];
public:
	char charToHex(char c);
	static void init_crc32_tab(void);	//To generate CRC-32 table
	uint32_t get_crc32(uint32_t crcinit, uint8_t * bs, uint32_t bssize);	//get the value of CRC-32
	uint32_t GetFileCRC(FILE *fd, uint32_t* rdlen);	// get the value of CRC-32 from a binary file
	int main_getCrc(int argc, char *argv[]);
};
#endif

