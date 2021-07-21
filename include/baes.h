#ifndef BAES_H
#define BAES_H

#include "aes.h"

static const u8 idM8[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

void bs_sbox(u8 x[8]);
void bs_mc(u8 x[32]);
void bs_sr(u8 x[128]);
void SubBytes(u8 x[128]);
void ShiftRows(u8 x[128]);
void MixColumns(u8 x[128]);
void AddRoundKey(u8 x[128], u8 k[128]);
void bs_aes(u8 x[128], u8 k[11][128], u8 y[128]);
void import(u8 in[16], u8 x[128]);
void export(u8 y[128], u8 out[16]);
void genenkey(u8 key[16], u8 k[11][128]);

#endif // BAES_H