#ifndef _H_SUMMATION_CHECKSUM_
#define _H_SUMMATION_CHECKSUM_

class C_SChecksum {
public:
	C_SChecksum();
	~C_SChecksum();
public:
	int ChecksumInspection(unsigned char _cs1, unsigned char _cs2);

	//=============================================================================
	//=  Compute Internet Checksum for count bytes beginning at location addr     =
	//=============================================================================
	unsigned char computeChecksum(unsigned char* data, int iLen);
};

#endif