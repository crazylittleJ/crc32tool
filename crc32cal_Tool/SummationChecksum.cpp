#include "SummationChecksum.h"

C_SChecksum::C_SChecksum() {

}

C_SChecksum::~C_SChecksum() {

}

int C_SChecksum::ChecksumInspection(unsigned char _cs1, unsigned char _cs2) {
	if ((_cs1 + _cs2) != 0xFF) {
		return -1;
	}
	else {
		return 0;
	}
}

//=============================================================================
//=  Compute Internet Checksum for count bytes beginning at location addr     =
//=============================================================================
unsigned char C_SChecksum::computeChecksum(unsigned char* data, int iLen)
{
	register unsigned char sum = 0x00;
	int i;
	for (i = 0; i < iLen; ++i)
		sum += (unsigned int)(*data++);

	return sum;
}