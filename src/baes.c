#include "baes.h"

void bs_sbox(u8 x[8])
{
    u8 s[8];
    u8
        y1,y2,y3,y4,y5,y6,y7,y8,
        y9,y10,y11,y12,y13,y14,y15,y16,
        y17,y18,y19,y20,y21;

    u8
        t0,t1,t2,t3,t4,t5,t6,t7,t8,
        t9,t10,t11,t12,t13,t14,t15,
        t16,t17,t18,t19,t20,t21,t22,
        t23,t24,t25,t26,t27,t28,t29,
        t30,t31,t32,t33,t34,t35,t36,
        t37,t38,t39,t40,t41,t42,t43,
        t44,t45,t46,t47,t48,t49,t50,
        t51,t52,t53,t54,t55,t56,t57,
        t58,t59,t60,t61,t62,t63,t64,
        t65,t66,t67;

    u8
        z0,z1,z2,z3,z4,z5,z6,z7,z8,
        z9,z10,z11,z12,z13,z14,
        z15,z16,z17;

    y14 = x[3] ^ x[5];
    y13 = x[0] ^ x[6];
    y9 = x[0] ^ x[3];
    y8 = x[0] ^ x[5];
    t0 = x[1] ^ x[2];
    y1 = t0 ^ x[7];
    y4 = y1 ^ x[3];
    y12 = y13 ^ y14;
    y2 = y1 ^ x[0];
    y5 = y1 ^ x[6];
    y3 = y5 ^ y8;
    t1 = x[4] ^ y12;
    y15 = t1 ^ x[5];
    y20 = t1 ^ x[1];
    y6 = y15 ^ x[7];
    y10 = y15 ^ t0;
    y11 = y20 ^ y9;
    y7 = x[7] ^ y11;
    y17 = y10 ^ y11;
    y19 = y10 ^ y8;
    y16 = t0 ^ y11;
    y21 = y13 ^ y16;
    y18 = x[0] ^ y16;

    t2 = y12 & y15;
    t3 = y3 & y6;
    t4 = t3 ^ t2;
    t5 = y4 & x[7];
    t6 = t5 ^ t2;
    t7 = y13 & y16;
    t8 = y5 & y1;
    t9 = t8 ^ t7;
    t10 = y2 & y7;
    t11 = t10 ^ t7;
    t12 = y9 & y11;
    t13 = y14 & y17;
    t14 = t13 ^ t12;
    t15 = y8 & y10;
    t16 = t15 ^ t12;
    t17 = t4 ^ t14;
    t18 = t6 ^  t16;
    t19 = t9 ^ t14;
    t20 = t11 ^  t16;
    t21 = t17 ^ y20;
    t22 = t18 ^ y19;
    t23 = t19 ^ y21;
    t24 = t20 ^ y18;

    t25 = t21 ^ t22;
    t26 = t21 & t23;
    t27 = t24 ^ t26;
    t28 = t25 & t27;
    t29 = t28 ^ t22;
    t30 = t23 ^ t24;
    t31 = t22 ^ t26;
    t32 = t31 & t30;
    t33 = t32 ^ t24;
    t34 = t23 ^ t33;
    t35 = t27 ^ t33;
    t36 = t24 & t35;
    t37 = t36 ^ t34;
    t38 = t27 ^ t36;
    t39 = t29 & t38;
    t40 = t25 ^ t39;

    t41 = t40 ^ t37;
    t42 = t29 ^ t33;
    t43 = t29 ^ t40;
    t44 = t33 ^ t37;
    t45 = t42 ^ t41;
    z0 = t44 & y15;
    z1 = t37 & y6;
    z2 = t33 & x[7];
    z3 = t43 & y16;
    z4 = t40 & y1;
    z5 = t29 & y7;
    z6 = t42 & y11;
    z7 = t45 & y17;
    z8 = t41 & y10;
    z9 = t44 & y12;
    z10 = t37 & y3;
    z11 = t33 & y4;
    z12 = t43 & y13;
    z13 = t40 & y5;
    z14 = t29 & y2;
    z15 = t42 & y9;
    z16 = t45 & y14;
    z17 = t41 & y8;

    t46 = z15 ^ z16;
    t47 = z10 ^ z11;
    t48 = z5 ^ z13;
    t49 = z9 ^ z10;
    t50 = z2 ^ z12;
    t51 = z2 ^ z5;
    t52 = z7 ^ z8;
    t53 = z0 ^ z3;
    t54 = z6 ^ z7;
    t55 = z16 ^ z17;
    t56 = z12 ^ t48;
    t57 = t50 ^ t53;
    t58 = z4 ^ t46;
    t59 = z3 ^ t54;
    t60 = t46 ^ t57;
    t61 = z14 ^ t57;
    t62 = t52 ^ t58;
    t63 = t49 ^ t58;
    t64 = z4 ^ t59;
    t65 = t61 ^ t62;
    t66 = z1 ^ t63;
    s[0] = (t59 ^ t63) & 0x1;
    s[6] = (~ (t56 ^ t62)) & 0x1;
    s[7] = (~ (t48 ^ t60)) & 0x1;
    t67 = (t64 ^ t65) & 0x1;
    s[3] = (t53 ^ t66) & 0x1;
    s[4] = (t51 ^ t66) & 0x1;
    s[5] = (t47 ^ t65) & 0x1;
    s[1] = (~ (t64 ^ s[3])) & 0x1;
    s[2] = (~ (t55 ^ t67)) & 0x1;

    memmove(x,s,sizeof(s));
}

void bs_mc(u8 x[32])
{
  u8 s[32] = {0};
  u8 t0, t1, t2, t3, t4;
  t0 = x[1] ^ x[8];
  t1 = t0 ^ x[9];
  t2 = t1 ^ x[16];
  s[0] = t2 ^ x[24];

  t0 = x[2] ^ x[9];
  t1 = t0 ^ x[10];
  t2 = t1 ^ x[17];
  s[1] = t2 ^ x[25];

  t0 = x[3] ^ x[10];
  t1 = t0 ^ x[11];
  t2 = t1 ^ x[18];
  s[2] = t2 ^ x[26];

  t0 = x[0] ^ x[4];
  t1 = t0 ^ x[8];
  t2 = t1 ^ x[11];
  t3 = t2 ^ x[12];
  t4 = t3 ^ x[19];
  s[3] = t4 ^ x[27];

  t0 = x[0] ^ x[5];
  t1 = t0 ^ x[8];
  t2 = t1 ^ x[12];
  t3 = t2 ^ x[13];
  t4 = t3 ^ x[20];
  s[4] = t4 ^ x[28];

  t0 = x[6] ^ x[13];
  t1 = t0 ^ x[14];
  t2 = t1 ^ x[21];
  s[5] = t2 ^ x[29];

  t0 = x[0] ^ x[7];
  t1 = t0 ^ x[8];
  t2 = t1 ^ x[14];
  t3 = t2 ^ x[15];
  t4 = t3 ^ x[22];
  s[6] = t4 ^ x[30];

  t0 = x[0] ^ x[8];
  t1 = t0 ^ x[15];
  t2 = t1 ^ x[23];
  s[7] = t2 ^ x[31];

  t0 = x[0] ^ x[9];
  t1 = t0 ^ x[16];
  t2 = t1 ^ x[17];
  s[8] = t2 ^ x[24];

  t0 = x[1] ^ x[10];
  t1 = t0 ^ x[17];
  t2 = t1 ^ x[18];
  s[9] = t2 ^ x[25];

  t0 = x[2] ^ x[11];
  t1 = t0 ^ x[18];
  t2 = t1 ^ x[19];
  s[10] = t2 ^ x[26];

  t0 = x[3] ^ x[8];
  t1 = t0 ^ x[12];
  t2 = t1 ^ x[16];
  t3 = t2 ^ x[19];
  t4 = t3 ^ x[20];
  s[11] = t4 ^ x[27];

  t0 = x[4] ^ x[8];
  t1 = t0 ^ x[13];
  t2 = t1 ^ x[16];
  t3 = t2 ^ x[20];
  t4 = t3 ^ x[21];
  s[12] = t4 ^ x[28];

  t0 = x[5] ^ x[14];
  t1 = t0 ^ x[21];
  t2 = t1 ^ x[22];
  s[13] = t2 ^ x[29];

  t0 = x[6] ^ x[8];
  t1 = t0 ^ x[15];
  t2 = t1 ^ x[16];
  t3 = t2 ^ x[22];
  t4 = t3 ^ x[23];
  s[14] = t4 ^ x[30];

  t0 = x[7] ^ x[8];
  t1 = t0 ^ x[16];
  t2 = t1 ^ x[23];
  s[15] = t2 ^ x[31];

  t0 = x[0] ^ x[8];
  t1 = t0 ^ x[17];
  t2 = t1 ^ x[24];
  s[16] = t2 ^ x[25];

  t0 = x[1] ^ x[9];
  t1 = t0 ^ x[18];
  t2 = t1 ^ x[25];
  s[17] = t2 ^ x[26];

  t0 = x[2] ^ x[10];
  t1 = t0 ^ x[19];
  t2 = t1 ^ x[26];
  s[18] = t2 ^ x[27];

  t0 = x[3] ^ x[11];
  t1 = t0 ^ x[16];
  t2 = t1 ^ x[20];
  t3 = t2 ^ x[24];
  t4 = t3 ^ x[27];
  s[19] = t4 ^ x[28];

  t0 = x[4] ^ x[12];
  t1 = t0 ^ x[16];
  t2 = t1 ^ x[21];
  t3 = t2 ^ x[24];
  t4 = t3 ^ x[28];
  s[20] = t4 ^ x[29];

  t0 = x[5] ^ x[13];
  t1 = t0 ^ x[22];
  t2 = t1 ^ x[29];
  s[21] = t2 ^ x[30];

  t0 = x[6] ^ x[14];
  t1 = t0 ^ x[16];
  t2 = t1 ^ x[23];
  t3 = t2 ^ x[24];
  t4 = t3 ^ x[30];
  s[22] = t4 ^ x[31];

  t0 = x[7] ^ x[15];
  t1 = t0 ^ x[16];
  t2 = t1 ^ x[24];
  s[23] = t2 ^ x[31];

  t0 = x[0] ^ x[1];
  t1 = t0 ^ x[8];
  t2 = t1 ^ x[16];
  s[24] = t2 ^ x[25];

  t0 = x[1] ^ x[2];
  t1 = t0 ^ x[9];
  t2 = t1 ^ x[17];
  s[25] = t2 ^ x[26];

  t0 = x[2] ^ x[3];
  t1 = t0 ^ x[10];
  t2 = t1 ^ x[18];
  s[26] = t2 ^ x[27];

  t0 = x[0] ^ x[3];
  t1 = t0 ^ x[4];
  t2 = t1 ^ x[11];
  t3 = t2 ^ x[19];
  t4 = t3 ^ x[24];
  s[27] = t4 ^ x[28];

  t0 = x[0] ^ x[4];
  t1 = t0 ^ x[5];
  t2 = t1 ^ x[12];
  t3 = t2 ^ x[20];
  t4 = t3 ^ x[24];
  s[28] = t4 ^ x[29];

  t0 = x[5] ^ x[6];
  t1 = t0 ^ x[13];
  t2 = t1 ^ x[21];
  s[29] = t2 ^ x[30];

  t0 = x[0] ^ x[6];
  t1 = t0 ^ x[7];
  t2 = t1 ^ x[14];
  t3 = t2 ^ x[22];
  t4 = t3 ^ x[24];
  s[30] = t4 ^ x[31];

  t0 = x[0] ^ x[7];
  t1 = t0 ^ x[15];
  t2 = t1 ^ x[23];
  s[31] = t2 ^ x[24];

  memmove(x, s, sizeof(s));
}

void bs_sr(u8 x[128])
{
  u8 s[128];
  for(int i = 0; i < 8; i++)
  {
    s[i] = x[i];
    s[32 + i] = x[32 + i];
    s[64 + i] = x[64 + i];
    s[96 + i] = x[96 + i];

    s[8 + i] = x[40 + i];
    s[40 + i] = x[72 + i];
    s[72 + i] = x[104 + i];
    s[104 + i] = x[8 + i];

    s[16 + i] = x[80 + i];
    s[48 + i] = x[112 + i];
    s[80 + i] = x[16 + i];
    s[112 + i] = x[48 + i];

    s[24 + i] = x[120 + i];
    s[56 + i] = x[24 + i];
    s[88 + i] = x[56 + i];
    s[120 + i] = x[88 + i];
  }
  memmove(x, s, sizeof(s));
}
void SubBytes(u8 x[128])
{
    int i;
    for(i = 0; i < 16; i++)
    {
        bs_sbox(x + i * 8);
    }
}
void ShiftRows(u8 x[128])
{
    bs_sr(x);
}
void MixColumns(u8 x[128])
{
    bs_mc(x);
    bs_mc(x + 32);
    bs_mc(x + 64);
    bs_mc(x + 96);
}
void AddRoundKey(u8 x[128], u8 k[128])
{
    int i;
    for(i = 0; i < 128; i++)
    {
        x[i] = x[i] ^ k[i];
    }
}
void bs_aes(u8 x[128], u8 k[11][128], u8 y[128])
{
    int r;
    memmove(y, x, sizeof(u8) * 128);
    AddRoundKey(y, k[0]);
    for(r = 1; r < 10; r++)
    {
        SubBytes(y);
        ShiftRows(y);
        MixColumns(y);
        AddRoundKey(y, k[r]);
    }
    SubBytes(y);
    ShiftRows(y);
    AddRoundKey(y, k[10]);
}

void import(u8 in[16], u8 x[128])
{
    int j, r;
    u8 temp;
    for(j = 0; j < 16; j++)
    {
        temp = in[j];
        for(r = 0; r < 8; r++)
        {
            if(temp & idM8[r]) x[j * 8 + r] = 1;
            else x[j * 8 + r] = 0;
        }
    }
}
void export(u8 y[128], u8 out[16])
{
    int j;
    memset(out, 0, sizeof(u8) * 16);
    for(j = 0; j < 128; j++)
    {
        if(y[j]) out[j / 8] ^= idM8[j % 8];
    }
}
void genenkey(u8 key[16], u8 k[11][128])
{
    u8 kk[176];
    int i, j, r;
    u8 temp;
    expandKey(key, kk);
    for(i = 0; i < 11; i++)
    {
        for(j = 0; j < 16; j++)
        {
            temp = kk[i * 16 + j];
            for(r = 0; r < 8; r++)
            {
                if(temp & idM8[r]) k[i][j * 8 + r] = 1;
                else k[i][j * 8 + r] = 0;
            }
        }
    }
}