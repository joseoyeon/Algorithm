#ifndef _HIGHT_H_

#include "../define/define.h"
#define HIGHT_BLOCK_SIZE 8

typedef struct
{
	uint32_t sk[32];
	uint32_t wk[2];
} HIGHT_RK;

HIGHT_RK hight_rk;
#define B_ROL(X, Y, n) T = X; X = (((T) << ((n) * 8)) ^ ((Y) >> (32 - ((n) * 8)))); Y = (((Y) << ((n) * 8)) ^ ((T) >> (32 - ((n) * 8))));
#define Q_ADD(X, Y, Z) { \
	((uint8_t *)&(X))[0] = ((uint8_t *)&(Y))[0] + ((uint8_t *)&(Z))[0]; \
	((uint8_t *)&(X))[1] = ((uint8_t *)&(Y))[1] + ((uint8_t *)&(Z))[1]; \
	((uint8_t *)&(X))[2] = ((uint8_t *)&(Y))[2] + ((uint8_t *)&(Z))[2]; \
	((uint8_t *)&(X))[3] = ((uint8_t *)&(Y))[3] + ((uint8_t *)&(Z))[3]; \
}
#define ROUND_ENC(X, Y, n) {	\
	T = (((uint32_t)F0[((uint8_t *)&(Y))[3]]) << 24) ^ (((uint32_t)F1[((uint8_t *)&(Y))[2]]) << 16) ^ (((uint32_t)F0[((uint8_t *)&(Y))[1]]) << 8) ^ (((uint32_t)F1[((uint8_t *)&(Y))[0]])); \
	((uint8_t *)&(T))[0] ^= ((uint8_t *)&(hight_rk->sk[n]))[0]; \
	((uint8_t *)&(T))[1] += ((uint8_t *)&(hight_rk->sk[n]))[1]; \
	((uint8_t *)&(T))[2] ^= ((uint8_t *)&(hight_rk->sk[n]))[2]; \
	((uint8_t *)&(T))[3] += ((uint8_t *)&(hight_rk->sk[n]))[3]; \
	((uint8_t *)&(X))[0] += ((uint8_t *)&(T))[0]; \
	((uint8_t *)&(X))[1] ^= ((uint8_t *)&(T))[1]; \
	((uint8_t *)&(X))[2] += ((uint8_t *)&(T))[2]; \
	((uint8_t *)&(X))[3] ^= ((uint8_t *)&(T))[3]; \
	X = (X << 8) ^ (X >> 24); \
}
#define ROUND_DEC(X, Y, n) {	\
	T = (((uint32_t)F0[((uint8_t *)&(Y))[3]]) << 24) ^ (((uint32_t)F1[((uint8_t *)&(Y))[2]]) << 16) ^ (((uint32_t)F0[((uint8_t *)&(Y))[1]]) << 8) ^ (((uint32_t)F1[((uint8_t *)&(Y))[0]])); \
	((uint8_t *)&(T))[0] ^= ((uint8_t *)&(hight_rk->sk[n]))[0]; \
	((uint8_t *)&(T))[1] += ((uint8_t *)&(hight_rk->sk[n]))[1]; \
	((uint8_t *)&(T))[2] ^= ((uint8_t *)&(hight_rk->sk[n]))[2]; \
	((uint8_t *)&(T))[3] += ((uint8_t *)&(hight_rk->sk[n]))[3]; \
	((uint8_t *)&(X))[0] -= ((uint8_t *)&(T))[0]; \
	((uint8_t *)&(X))[1] ^= ((uint8_t *)&(T))[1]; \
	((uint8_t *)&(X))[2] -= ((uint8_t *)&(T))[2]; \
	((uint8_t *)&(X))[3] ^= ((uint8_t *)&(T))[3]; \
	Y = (Y >> 8) ^ (Y << 24);	\
}
#define _F0(cur) \
_mm_and_si128(_mm_set1_epi16(0x00ff),_mm_xor_si128(_mm_xor_si128(_mm_xor_si128(_mm_slli_epi16(cur, 1), _mm_srli_epi16(cur, 7)),_mm_xor_si128(_mm_slli_epi16(cur, 2), _mm_srli_epi16(cur, 6))) ,_mm_xor_si128(_mm_slli_epi16(cur, 7), _mm_srli_epi16(cur, 1))))
#define _F1(cur) \
_mm_and_si128(_mm_set1_epi16(0x00ff),_mm_xor_si128(_mm_xor_si128(_mm_xor_si128(_mm_slli_epi16(cur, 3), _mm_srli_epi16(cur, 5)),_mm_xor_si128(_mm_slli_epi16(cur, 4), _mm_srli_epi16(cur, 4))) ,_mm_xor_si128(_mm_slli_epi16(cur, 6), _mm_srli_epi16(cur, 2))))

#define ROUND_F0(prv, cur, rk) \
prv = _mm_xor_si128(prv,_mm_add_epi8(_F0(cur),_mm_set1_epi16(rk)));
#define ROUND_F1(prv, cur, rk) \
prv = _mm_add_epi8(prv,_mm_xor_si128(_F1(cur),_mm_set1_epi16(rk)));

#define RROUND_F0(prv, cur, rk) \
prv = _mm_xor_si128(prv,_mm_add_epi8(_F0(cur),_mm_set1_epi16(rk)));
#define RROUND_F1(prv, cur, rk) \
prv = _mm_sub_epi8(prv,_mm_xor_si128(_F1(cur),_mm_set1_epi16(rk)));

int hight_keyexpansion(uint32_t hight_sk[32], const uint8_t key[16]);
int hight_keyschedule_enc(HIGHT_RK *hight_rk, const uint8_t key[16]);
int hight_keyschedule_dec(HIGHT_RK *hight_rk, const uint8_t key[16]);
int hight_enc_block(uint32_t data[2], const HIGHT_RK *hight_rk);
int hight_dec_block(uint32_t data[2], const HIGHT_RK *hight_rk);
/*
	hight_ecrypt, hight_decrypt, hight_setkey - Functions for MFC connecting
*/
int hight_setkey(uint8_t* key, int keyLen, int encType, HIGHT_RK *hight_rk);
int hight_encrypt(uint8_t *in, uint8_t *out, uint8_t *key);
int hight_encrypt_4(uint8_t *in, uint8_t *out, HIGHT_RK *key);
int hight_decrypt(uint8_t *in, uint8_t *out, uint8_t *key);
int hight_decrypt_4(uint8_t *in, uint8_t *out, HIGHT_RK *key);

void hight_ecb_encrypt(uint8_t* in, uint8_t* out, void* key,int enc, int inLen, int keyLen, char* inPath, char *outPath);
void hight_cbc_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* iv,int enc, int inLen, int keyLen, char* inPath, char *outPath);
void hight_cfb_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* iv,int enc, int inLen, int keyLen, char* inPath, char *outPath);
void hight_ofb_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* iv,int enc, int inLen, int keyLen, char* inPath, char *outPath);
void hight_ctr_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* ctr,int enc, int inLen, int keyLen, char* inPath, char *outPath);

#endif // !_HIGHT_H_
