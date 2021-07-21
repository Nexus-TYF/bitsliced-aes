#include "baes.h"

int main()
{
    unsigned char IN[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    u8 key[16] = {0};
    unsigned char OUT[16];
    unsigned char OOUT[16];
    u8 ptx[128];
    u8 k[11][128];
    u8 ctx[128];

    ///// import plaintext
    import(IN, ptx);
    genenkey(key, k);
    ///// encryption
    bs_aes(ptx, k, ctx);
    ///// export ciphertext
    export(ctx, OUT);
    printState(OUT);

    aes_128_encrypt(IN, key, OOUT);
    printState(OOUT);

    return 0;
}