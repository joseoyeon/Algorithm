#include "hight.h"
#include <immintrin.h>

static uint32_t DELTA[32] =
{
	0x1b366d5a, 0x4103060d, 0x4c183060, 0x2c593366,
	0x4a152b56, 0x1c397265, 0x7973674e, 0x376f5e3c,
	0x0b162d5b, 0x50214205, 0x552a5428, 0x7d7a756a,
	0x172f5f3e, 0x2952254b, 0x62450a14, 0x766c5831,
	0x470e1d3b, 0x7c787163, 0x1f3f7f7e, 0x6143070f,
	0x6e5c3870, 0x1e3d7b77, 0x6953274f, 0x264d1a34,
	0x12244913, 0x01020409, 0x08102040, 0x48112244,
	0x0c193264, 0x68512346, 0x2e5d3a74, 0x5a356b57
};

static uint8_t F0[256] = {
	0x00,0x86,0x0D,0x8B,0x1A,0x9C,0x17,0x91,	0x34,0xB2,0x39,0xBF,0x2E,0xA8,0x23,0xA5,
	0x68,0xEE,0x65,0xE3,0x72,0xF4,0x7F,0xF9,	0x5C,0xDA,0x51,0xD7,0x46,0xC0,0x4B,0xCD,
	0xD0,0x56,0xDD,0x5B,0xCA,0x4C,0xC7,0x41,	0xE4,0x62,0xE9,0x6F,0xFE,0x78,0xF3,0x75,
	0xB8,0x3E,0xB5,0x33,0xA2,0x24,0xAF,0x29,	0x8C,0x0A,0x81,0x07,0x96,0x10,0x9B,0x1D,
	0xA1,0x27,0xAC,0x2A,0xBB,0x3D,0xB6,0x30,	0x95,0x13,0x98,0x1E,0x8F,0x09,0x82,0x04,
	0xC9,0x4F,0xC4,0x42,0xD3,0x55,0xDE,0x58,	0xFD,0x7B,0xF0,0x76,0xE7,0x61,0xEA,0x6C,
	0x71,0xF7,0x7C,0xFA,0x6B,0xED,0x66,0xE0,	0x45,0xC3,0x48,0xCE,0x5F,0xD9,0x52,0xD4,
	0x19,0x9F,0x14,0x92,0x03,0x85,0x0E,0x88,	0x2D,0xAB,0x20,0xA6,0x37,0xB1,0x3A,0xBC,
	0x43,0xC5,0x4E,0xC8,0x59,0xDF,0x54,0xD2,	0x77,0xF1,0x7A,0xFC,0x6D,0xEB,0x60,0xE6,
	0x2B,0xAD,0x26,0xA0,0x31,0xB7,0x3C,0xBA,	0x1F,0x99,0x12,0x94,0x05,0x83,0x08,0x8E,
	0x93,0x15,0x9E,0x18,0x89,0x0F,0x84,0x02,	0xA7,0x21,0xAA,0x2C,0xBD,0x3B,0xB0,0x36,
	0xFB,0x7D,0xF6,0x70,0xE1,0x67,0xEC,0x6A,	0xCF,0x49,0xC2,0x44,0xD5,0x53,0xD8,0x5E,
	0xE2,0x64,0xEF,0x69,0xF8,0x7E,0xF5,0x73,	0xD6,0x50,0xDB,0x5D,0xCC,0x4A,0xC1,0x47,
	0x8A,0x0C,0x87,0x01,0x90,0x16,0x9D,0x1B,	0xBE,0x38,0xB3,0x35,0xA4,0x22,0xA9,0x2F,
	0x32,0xB4,0x3F,0xB9,0x28,0xAE,0x25,0xA3,	0x06,0x80,0x0B,0x8D,0x1C,0x9A,0x11,0x97,
	0x5A,0xDC,0x57,0xD1,0x40,0xC6,0x4D,0xCB,	0x6E,0xE8,0x63,0xE5,0x74,0xF2,0x79,0xFF };

static uint8_t F1[256] = {
	0x00,0x58,0xB0,0xE8,0x61,0x39,0xD1,0x89,	0xC2,0x9A,0x72,0x2A,0xA3,0xFB,0x13,0x4B,
	0x85,0xDD,0x35,0x6D,0xE4,0xBC,0x54,0x0C,	0x47,0x1F,0xF7,0xAF,0x26,0x7E,0x96,0xCE,
	0x0B,0x53,0xBB,0xE3,0x6A,0x32,0xDA,0x82,	0xC9,0x91,0x79,0x21,0xA8,0xF0,0x18,0x40,
	0x8E,0xD6,0x3E,0x66,0xEF,0xB7,0x5F,0x07,	0x4C,0x14,0xFC,0xA4,0x2D,0x75,0x9D,0xC5,
	0x16,0x4E,0xA6,0xFE,0x77,0x2F,0xC7,0x9F,	0xD4,0x8C,0x64,0x3C,0xB5,0xED,0x05,0x5D,
	0x93,0xCB,0x23,0x7B,0xF2,0xAA,0x42,0x1A,	0x51,0x09,0xE1,0xB9,0x30,0x68,0x80,0xD8,
	0x1D,0x45,0xAD,0xF5,0x7C,0x24,0xCC,0x94,	0xDF,0x87,0x6F,0x37,0xBE,0xE6,0x0E,0x56,
	0x98,0xC0,0x28,0x70,0xF9,0xA1,0x49,0x11,	0x5A,0x02,0xEA,0xB2,0x3B,0x63,0x8B,0xD3,
	0x2C,0x74,0x9C,0xC4,0x4D,0x15,0xFD,0xA5,	0xEE,0xB6,0x5E,0x06,0x8F,0xD7,0x3F,0x67,
	0xA9,0xF1,0x19,0x41,0xC8,0x90,0x78,0x20,	0x6B,0x33,0xDB,0x83,0x0A,0x52,0xBA,0xE2,
	0x27,0x7F,0x97,0xCF,0x46,0x1E,0xF6,0xAE,	0xE5,0xBD,0x55,0x0D,0x84,0xDC,0x34,0x6C,
	0xA2,0xFA,0x12,0x4A,0xC3,0x9B,0x73,0x2B,	0x60,0x38,0xD0,0x88,0x01,0x59,0xB1,0xE9,
	0x3A,0x62,0x8A,0xD2,0x5B,0x03,0xEB,0xB3,	0xF8,0xA0,0x48,0x10,0x99,0xC1,0x29,0x71,
	0xBF,0xE7,0x0F,0x57,0xDE,0x86,0x6E,0x36,	0x7D,0x25,0xCD,0x95,0x1C,0x44,0xAC,0xF4,
	0x31,0x69,0x81,0xD9,0x50,0x08,0xE0,0xB8,	0xF3,0xAB,0x43,0x1B,0x92,0xCA,0x22,0x7A,
	0xB4,0xEC,0x04,0x5C,0xD5,0x8D,0x65,0x3D,	0x76,0x2E,0xC6,0x9E,0x17,0x4F,0xA7,0xFF };

int hight_keyexpansion(uint32_t hight_sk[32], const uint8_t key[16])
{
	int i = 0;
	uint32_t T = 0, N = 0, M = 0, X = 0, Y = 0;

	// Covert 8bit to 32bit;
	memcpy(&N, key, 4);
	memcpy(&M, key + 4, 4);
	memcpy(&X, key + 8, 4);
	memcpy(&Y, key + 12, 4);

	if (chk_endian())
	{
		ltob(N);
		ltob(M);
		ltob(X);
		ltob(Y);
	}

	for (i = 0; i < 8; i++)
	{
		Q_ADD(hight_sk[(4 * i)], Y, DELTA[(4 * i)]);
		Q_ADD(hight_sk[(4 * i) + 1], X, DELTA[(4 * i) + 1]);
		Q_ADD(hight_sk[(4 * i) + 2], M, DELTA[(4 * i) + 2]);
		Q_ADD(hight_sk[(4 * i) + 3], N, DELTA[(4 * i) + 3]);

		B_ROL(X, Y, 1);
		B_ROL(N, M, 1);
	}

	T = 0; N = 0; M = 0; X = 0; Y = 0;

	return 0;
}
int hight_keyschedule_enc(HIGHT_RK *hight_rk, const uint8_t key[16])
{
	int32_t ret = -1, i;
	uint32_t sk[32] = { 0, };

	//Set the encryption Sub-key
	hight_keyexpansion(sk, key);
	for (i = 0; i < 32; i++)
	{
		hight_rk->sk[i] = sk[i];
	}

	//Set the encryption Whitening-key
	memcpy(&hight_rk->wk[0], key, 4);
	memcpy(&hight_rk->wk[1], key + 12, 4);

	if (chk_endian())
	{
		ltob(hight_rk->wk[0]);
		ltob(hight_rk->wk[1]);
	}

	return 0;
}
int hight_keyschedule_dec(HIGHT_RK *hight_rk, const uint8_t key[16])
{
	int32_t ret = -1, i;
	uint32_t sk[32] = { 0, };

	//Set the decryption Sub-key
	hight_keyexpansion(sk, key);
	for (i = 0; i < 32; i++)
	{
		//ltob(sk[31 - i]);
		hight_rk->sk[i] = sk[31 - i];
	}

	//Set the decryption Whitening-key
	memcpy(&hight_rk->wk[0], key, 4);
	memcpy(&hight_rk->wk[1], key + 12, 4);

	if (chk_endian())
	{
		ltob(hight_rk->wk[0]);
		ltob(hight_rk->wk[1]);
	}
	
	return 0;
}

int hight_enc_block(uint32_t data[2], const HIGHT_RK *hight_rk)
{
	int32_t ret = -1, i = 0;
	uint32_t T = 0, X = 0, Y = 0, M = 0;

	// Initial Permutation
	X = ((data[0] & 0xFF000000)) ^ ((data[0] & 0x0000FF00) << 8) ^
		((data[1] & 0xFF000000) >> 16) ^ ((data[1] & 0x0000FF00) >> 8);
	Y = ((data[0] & 0x00FF0000) << 8) ^ ((data[0] & 0x000000FF) << 16) ^
		((data[1] & 0x00FF0000) >> 8) ^ ((data[1] & 0x000000FF)) ^ (hight_rk->wk[0] & 0xFF00FF00);
	((uint8_t *)&(Y))[0] += ((uint8_t *)&(hight_rk->wk[0]))[0];
	((uint8_t *)&(Y))[2] += ((uint8_t *)&(hight_rk->wk[0]))[2];

	// Process
	for (i = 0; i < 15; i++)
	{
		ROUND_ENC(X, Y, (2 * i));
		ROUND_ENC(Y, X, (2 * i) + 1);
	}
	ROUND_ENC(X, Y, 30);
	T = (((uint32_t)F0[((uint8_t *)&(X))[3]]) << 24) ^ (((uint32_t)F1[((uint8_t *)&(X))[2]]) << 16) ^ (((uint32_t)F0[((uint8_t *)&(X))[1]]) << 8) ^ (((uint32_t)F1[((uint8_t *)&(X))[0]]));
	((uint8_t *)&(T))[0] ^= ((uint8_t *)&(hight_rk->sk[31]))[0];
	((uint8_t *)&(T))[1] += ((uint8_t *)&(hight_rk->sk[31]))[1];
	((uint8_t *)&(T))[2] ^= ((uint8_t *)&(hight_rk->sk[31]))[2];
	((uint8_t *)&(T))[3] += ((uint8_t *)&(hight_rk->sk[31]))[3];
	((uint8_t *)&(Y))[0] += ((uint8_t *)&(T))[0];
	((uint8_t *)&(Y))[1] ^= ((uint8_t *)&(T))[1];
	((uint8_t *)&(Y))[2] += ((uint8_t *)&(T))[2];
	((uint8_t *)&(Y))[3] ^= ((uint8_t *)&(T))[3];

	// Final Permutation
	((uint8_t *)&(X))[0] += ((uint8_t *)&(hight_rk->wk[1]))[0];
	((uint8_t *)&(X))[1] ^= ((uint8_t *)&(hight_rk->wk[1]))[1];
	((uint8_t *)&(X))[2] += ((uint8_t *)&(hight_rk->wk[1]))[2];
	((uint8_t *)&(X))[3] ^= ((uint8_t *)&(hight_rk->wk[1]))[3];

	data[0] = (Y & 0xFF000000) ^ ((Y & 0x00FF0000) >> 8) ^ ((X & 0xFF000000) >> 8) ^ ((X & 0x00FF0000) >> 16);
	data[1] = ((Y & 0x0000FF00) << 16) ^ ((Y & 0x000000FF) << 8) ^ ((X & 0x0000FF00) << 8) ^ ((X & 0x000000FF));

	ret = 0;
	return ret;
}
int hight_dec_block(uint32_t data[2], const HIGHT_RK *hight_rk)
{
	int32_t ret = -1, i = 0;
	uint32_t T = 0, X = 0, Y = 0, M = 0;


	// Initial Permutation
	X = ((data[0] & 0xFF000000)) ^ ((data[0] & 0x0000FF00) << 8) ^
		((data[1] & 0xFF000000) >> 16) ^ ((data[1] & 0x0000FF00) >> 8);
	Y = ((data[0] & 0x00FF0000) << 8) ^ ((data[0] & 0x000000FF) << 16) ^
		((data[1] & 0x00FF0000) >> 8) ^ ((data[1] & 0x000000FF)) ^ (hight_rk->wk[1] & 0xFF00FF00);
	((uint8_t *)&(Y))[0] -= ((uint8_t *)&(hight_rk->wk[1]))[0];
	((uint8_t *)&(Y))[2] -= ((uint8_t *)&(hight_rk->wk[1]))[2];

	// Process
	for (i = 0; i < 15; i++)
	{
		ROUND_DEC(X, Y, (2 * i));
		ROUND_DEC(Y, X, (2 * i) + 1);
	}
	ROUND_DEC(X, Y, 30);
	T = (((uint32_t)F0[((uint8_t *)&(X))[3]]) << 24) ^ (((uint32_t)F1[((uint8_t *)&(X))[2]]) << 16) ^ (((uint32_t)F0[((uint8_t *)&(X))[1]]) << 8) ^ (((uint32_t)F1[((uint8_t *)&(X))[0]]));
	((uint8_t *)&(T))[0] ^= ((uint8_t *)&(hight_rk->sk[31]))[0];
	((uint8_t *)&(T))[1] += ((uint8_t *)&(hight_rk->sk[31]))[1];
	((uint8_t *)&(T))[2] ^= ((uint8_t *)&(hight_rk->sk[31]))[2];
	((uint8_t *)&(T))[3] += ((uint8_t *)&(hight_rk->sk[31]))[3];
	((uint8_t *)&(Y))[0] -= ((uint8_t *)&(T))[0];
	((uint8_t *)&(Y))[1] ^= ((uint8_t *)&(T))[1];
	((uint8_t *)&(Y))[2] -= ((uint8_t *)&(T))[2];
	((uint8_t *)&(Y))[3] ^= ((uint8_t *)&(T))[3];


	// Final Permutation
	((uint8_t *)&(X))[0] -= ((uint8_t *)&(hight_rk->wk[0]))[0];
	((uint8_t *)&(X))[1] ^= ((uint8_t *)&(hight_rk->wk[0]))[1];
	((uint8_t *)&(X))[2] -= ((uint8_t *)&(hight_rk->wk[0]))[2];
	((uint8_t *)&(X))[3] ^= ((uint8_t *)&(hight_rk->wk[0]))[3];

	data[0] = (Y & 0xFF000000) ^ ((Y & 0x00FF0000) >> 8) ^ ((X & 0xFF000000) >> 8) ^ ((X & 0x00FF0000) >> 16);
	data[1] = ((Y & 0x0000FF00) << 16) ^ ((Y & 0x000000FF) << 8) ^ ((X & 0x0000FF00) << 8) ^ ((X & 0x000000FF));

	ret = 0;
	return ret;
}

/*
	hight_ecrypt, hight_decrypt, hight_setkey - Functions for MFC connecting
*/
int hight_encrypt(uint8_t *in, uint8_t *out, uint8_t *key)
{
	uint32_t in32[2] = { 0 };
	CHtoIH(in32, in, 2);
	hight_enc_block(in32, key);
	IHtoCH(out, in32, 2);
	return 1;
}

int hight_decrypt(uint8_t *in, uint8_t *out, uint8_t *key)
{
	uint32_t in32[2] = { 0 };
	CHtoIH(in32, in, 2);
	hight_dec_block(in32, key);
	IHtoCH(out, in32, 2);
	return 1;
}

int hight_encrypt_4(uint8_t *in, uint8_t *out, HIGHT_RK *key)
{
	__m128i t, x0, x1, x2, x3, x4, x5, x6, x7;
	int i;
	uint8_t *pkey = (uint8_t*)key;

	x7 = _mm_setr_epi16(*((uint8_t *)in), *((uint8_t *)in + 0x08), *((uint8_t *)in + 0x10), *((uint8_t *)in + 0x18),
		*((uint8_t *)in + 0x20), *((uint8_t *)in + 0x28), *((uint8_t *)in + 0x30), *((uint8_t *)in + 0x38));
	x6 = _mm_setr_epi16(*((uint8_t *)in + 0x01), *((uint8_t *)in + 0x09), *((uint8_t *)in + 0x11), *((uint8_t *)in + 0x19),
		*((uint8_t *)in + 0x21), *((uint8_t *)in + 0x29), *((uint8_t *)in + 0x31), *((uint8_t *)in + 0x39));
	x5 = _mm_setr_epi16(*((uint8_t *)in + 0x02), *((uint8_t *)in + 0x0a), *((uint8_t *)in + 0x12), *((uint8_t *)in + 0x1a),
		*((uint8_t *)in + 0x22), *((uint8_t *)in + 0x2a), *((uint8_t *)in + 0x32), *((uint8_t *)in + 0x3a));
	x4 = _mm_setr_epi16(*((uint8_t *)in + 0x03), *((uint8_t *)in + 0x0b), *((uint8_t *)in + 0x13), *((uint8_t *)in + 0x1b),
		*((uint8_t *)in + 0x23), *((uint8_t *)in + 0x2b), *((uint8_t *)in + 0x33), *((uint8_t *)in + 0x3b));
	x3 = _mm_setr_epi16(*((uint8_t *)in + 0x04), *((uint8_t *)in + 0x0c), *((uint8_t *)in + 0x14), *((uint8_t *)in + 0x1c),
		*((uint8_t *)in + 0x24), *((uint8_t *)in + 0x2c), *((uint8_t *)in + 0x34), *((uint8_t *)in + 0x3c));
	x2 = _mm_setr_epi16(*((uint8_t *)in + 0x05), *((uint8_t *)in + 0x0d), *((uint8_t *)in + 0x15), *((uint8_t *)in + 0x1d),
		*((uint8_t *)in + 0x25), *((uint8_t *)in + 0x2d), *((uint8_t *)in + 0x35), *((uint8_t *)in + 0x3d));
	x1 = _mm_setr_epi16(*((uint8_t *)in + 0x06), *((uint8_t *)in + 0x0e), *((uint8_t *)in + 0x16), *((uint8_t *)in + 0x1e),
		*((uint8_t *)in + 0x26), *((uint8_t *)in + 0x2e), *((uint8_t *)in + 0x36), *((uint8_t *)in + 0x3e));
	x0 = _mm_setr_epi16(*((uint8_t *)in + 0x07), *((uint8_t *)in + 0x0f), *((uint8_t *)in + 0x17), *((uint8_t *)in + 0x1f),
		*((uint8_t *)in + 0x27), *((uint8_t *)in + 0x2f), *((uint8_t *)in + 0x37), *((uint8_t *)in + 0x3f));

	t = _mm_set1_epi16(*(pkey + 131));
	x6 = _mm_xor_si128(t, x6);
	t = _mm_set1_epi16(*(pkey + 130));
	x4 = _mm_add_epi8(t, x4);
	t = _mm_set1_epi16(*(pkey + 129));
	x2 = _mm_xor_si128(t, x2);
	t = _mm_set1_epi16(*(pkey + 128));
	x0 = _mm_add_epi8(t, x0);

	for (i = 0; i < 120; i += 32)
	{
		ROUND_F0(x7, x6, *(pkey + i + 3));
		ROUND_F1(x5, x4, *(pkey + i + 2));
		ROUND_F0(x3, x2, *(pkey + i + 1));
		ROUND_F1(x1, x0, *(pkey + i + 0));

		ROUND_F0(x6, x5, *(pkey + i + 7));
		ROUND_F1(x4, x3, *(pkey + i + 6));
		ROUND_F0(x2, x1, *(pkey + i + 5));
		ROUND_F1(x0, x7, *(pkey + i + 4));

		ROUND_F0(x5, x4, *(pkey + i + 11));
		ROUND_F1(x3, x2, *(pkey + i + 10));
		ROUND_F0(x1, x0, *(pkey + i + 9));
		ROUND_F1(x7, x6, *(pkey + i + 8));

		ROUND_F0(x4, x3, *(pkey + i + 15));
		ROUND_F1(x2, x1, *(pkey + i + 14));
		ROUND_F0(x0, x7, *(pkey + i + 13));
		ROUND_F1(x6, x5, *(pkey + i + 12));

		ROUND_F0(x3, x2, *(pkey + i + 19));
		ROUND_F1(x1, x0, *(pkey + i + 18));
		ROUND_F0(x7, x6, *(pkey + i + 17));
		ROUND_F1(x5, x4, *(pkey + i + 16));

		ROUND_F0(x2, x1, *(pkey + i + 23));
		ROUND_F1(x0, x7, *(pkey + i + 22));
		ROUND_F0(x6, x5, *(pkey + i + 21));
		ROUND_F1(x4, x3, *(pkey + i + 20));

		ROUND_F0(x1, x0, *(pkey + i + 27));
		ROUND_F1(x7, x6, *(pkey + i + 26));
		ROUND_F0(x5, x4, *(pkey + i + 25));
		ROUND_F1(x3, x2, *(pkey + i + 24));

		ROUND_F0(x0, x7, *(pkey + i + 31));
		ROUND_F1(x6, x5, *(pkey + i + 30));
		ROUND_F0(x4, x3, *(pkey + i + 29));
		ROUND_F1(x2, x1, *(pkey + i + 28));
	}
	t = _mm_set1_epi16(*(pkey + 135));
	x7 = _mm_xor_si128(t, x7);
	t = _mm_set1_epi16(*(pkey + 134));
	x5 = _mm_add_epi8(t, x5);
	t = _mm_set1_epi16(*(pkey + 133));
	x3 = _mm_xor_si128(t, x3);
	t = _mm_set1_epi16(*(pkey + 132));
	x1 = _mm_add_epi8(t, x1);


	*((uint8_t *)out) = _mm_extract_epi8(x0, 0);
	*((uint8_t *)out + 0x08) = _mm_extract_epi8(x0, 2);
	*((uint8_t *)out + 0x10) = _mm_extract_epi8(x0, 4);
	*((uint8_t *)out + 0x18) = _mm_extract_epi8(x0, 6);
	*((uint8_t *)out + 0x20) = _mm_extract_epi8(x0, 8);
	*((uint8_t *)out + 0x28) = _mm_extract_epi8(x0, 10);
	*((uint8_t *)out + 0x30) = _mm_extract_epi8(x0, 12);
	*((uint8_t *)out + 0x38) = _mm_extract_epi8(x0, 14);

	*((uint8_t *)out + 0x01) = _mm_extract_epi8(x7, 0);
	*((uint8_t *)out + 0x09) = _mm_extract_epi8(x7, 2);
	*((uint8_t *)out + 0x11) = _mm_extract_epi8(x7, 4);
	*((uint8_t *)out + 0x19) = _mm_extract_epi8(x7, 6);
	*((uint8_t *)out + 0x21) = _mm_extract_epi8(x7, 8);
	*((uint8_t *)out + 0x29) = _mm_extract_epi8(x7, 10);
	*((uint8_t *)out + 0x31) = _mm_extract_epi8(x7, 12);
	*((uint8_t *)out + 0x39) = _mm_extract_epi8(x7, 14);

	*((uint8_t *)out + 0x02) = _mm_extract_epi8(x6, 0);
	*((uint8_t *)out + 0x0a) = _mm_extract_epi8(x6, 2);
	*((uint8_t *)out + 0x12) = _mm_extract_epi8(x6, 4);
	*((uint8_t *)out + 0x1a) = _mm_extract_epi8(x6, 6);
	*((uint8_t *)out + 0x22) = _mm_extract_epi8(x6, 8);
	*((uint8_t *)out + 0x2a) = _mm_extract_epi8(x6, 10);
	*((uint8_t *)out + 0x32) = _mm_extract_epi8(x6, 12);
	*((uint8_t *)out + 0x3a) = _mm_extract_epi8(x6, 14);

	*((uint8_t *)out + 0x03) = _mm_extract_epi8(x5, 0);
	*((uint8_t *)out + 0x0b) = _mm_extract_epi8(x5, 2);
	*((uint8_t *)out + 0x13) = _mm_extract_epi8(x5, 4);
	*((uint8_t *)out + 0x1b) = _mm_extract_epi8(x5, 6);
	*((uint8_t *)out + 0x23) = _mm_extract_epi8(x5, 8);
	*((uint8_t *)out + 0x2b) = _mm_extract_epi8(x5, 10);
	*((uint8_t *)out + 0x33) = _mm_extract_epi8(x5, 12);
	*((uint8_t *)out + 0x3b) = _mm_extract_epi8(x5, 14);

	*((uint8_t *)out + 0x04) = _mm_extract_epi8(x4, 0);
	*((uint8_t *)out + 0x0c) = _mm_extract_epi8(x4, 2);
	*((uint8_t *)out + 0x14) = _mm_extract_epi8(x4, 4);
	*((uint8_t *)out + 0x1c) = _mm_extract_epi8(x4, 6);
	*((uint8_t *)out + 0x24) = _mm_extract_epi8(x4, 8);
	*((uint8_t *)out + 0x2c) = _mm_extract_epi8(x4, 10);
	*((uint8_t *)out + 0x34) = _mm_extract_epi8(x4, 12);
	*((uint8_t *)out + 0x3c) = _mm_extract_epi8(x4, 14);

	*((uint8_t *)out + 0x05) = _mm_extract_epi8(x3, 0);
	*((uint8_t *)out + 0x0d) = _mm_extract_epi8(x3, 2);
	*((uint8_t *)out + 0x15) = _mm_extract_epi8(x3, 4);
	*((uint8_t *)out + 0x1d) = _mm_extract_epi8(x3, 6);
	*((uint8_t *)out + 0x25) = _mm_extract_epi8(x3, 8);
	*((uint8_t *)out + 0x2d) = _mm_extract_epi8(x3, 10);
	*((uint8_t *)out + 0x35) = _mm_extract_epi8(x3, 12);
	*((uint8_t *)out + 0x3d) = _mm_extract_epi8(x3, 14);

	*((uint8_t *)out + 0x06) = _mm_extract_epi8(x2, 0);
	*((uint8_t *)out + 0x0e) = _mm_extract_epi8(x2, 2);
	*((uint8_t *)out + 0x16) = _mm_extract_epi8(x2, 4);
	*((uint8_t *)out + 0x1e) = _mm_extract_epi8(x2, 6);
	*((uint8_t *)out + 0x26) = _mm_extract_epi8(x2, 8);
	*((uint8_t *)out + 0x2e) = _mm_extract_epi8(x2, 10);
	*((uint8_t *)out + 0x36) = _mm_extract_epi8(x2, 12);
	*((uint8_t *)out + 0x3e) = _mm_extract_epi8(x2, 14);

	*((uint8_t *)out + 0x07) = _mm_extract_epi8(x1, 0);
	*((uint8_t *)out + 0x0f) = _mm_extract_epi8(x1, 2);
	*((uint8_t *)out + 0x17) = _mm_extract_epi8(x1, 4);
	*((uint8_t *)out + 0x1f) = _mm_extract_epi8(x1, 6);
	*((uint8_t *)out + 0x27) = _mm_extract_epi8(x1, 8);
	*((uint8_t *)out + 0x2f) = _mm_extract_epi8(x1, 10);
	*((uint8_t *)out + 0x37) = _mm_extract_epi8(x1, 12);
	*((uint8_t *)out + 0x3f) = _mm_extract_epi8(x1, 14);

	return 1;
}

int hight_decrypt_4(uint8_t *in, uint8_t *out, HIGHT_RK *key)
{
	__m128i t, x0, x1, x2, x3, x4, x5, x6, x7;
	int i;
	uint8_t *pkey = (uint8_t*)key;

	x7 = _mm_setr_epi16(*((uint8_t *)in), *((uint8_t *)in + 0x08), *((uint8_t *)in + 0x10), *((uint8_t *)in + 0x18),
		*((uint8_t *)in + 0x20), *((uint8_t *)in + 0x28), *((uint8_t *)in + 0x30), *((uint8_t *)in + 0x38));
	x6 = _mm_setr_epi16(*((uint8_t *)in + 0x01), *((uint8_t *)in + 0x09), *((uint8_t *)in + 0x11), *((uint8_t *)in + 0x19),
		*((uint8_t *)in + 0x21), *((uint8_t *)in + 0x29), *((uint8_t *)in + 0x31), *((uint8_t *)in + 0x39));
	x5 = _mm_setr_epi16(*((uint8_t *)in + 0x02), *((uint8_t *)in + 0x0a), *((uint8_t *)in + 0x12), *((uint8_t *)in + 0x1a),
		*((uint8_t *)in + 0x22), *((uint8_t *)in + 0x2a), *((uint8_t *)in + 0x32), *((uint8_t *)in + 0x3a));
	x4 = _mm_setr_epi16(*((uint8_t *)in + 0x03), *((uint8_t *)in + 0x0b), *((uint8_t *)in + 0x13), *((uint8_t *)in + 0x1b),
		*((uint8_t *)in + 0x23), *((uint8_t *)in + 0x2b), *((uint8_t *)in + 0x33), *((uint8_t *)in + 0x3b));
	x3 = _mm_setr_epi16(*((uint8_t *)in + 0x04), *((uint8_t *)in + 0x0c), *((uint8_t *)in + 0x14), *((uint8_t *)in + 0x1c),
		*((uint8_t *)in + 0x24), *((uint8_t *)in + 0x2c), *((uint8_t *)in + 0x34), *((uint8_t *)in + 0x3c));
	x2 = _mm_setr_epi16(*((uint8_t *)in + 0x05), *((uint8_t *)in + 0x0d), *((uint8_t *)in + 0x15), *((uint8_t *)in + 0x1d),
		*((uint8_t *)in + 0x25), *((uint8_t *)in + 0x2d), *((uint8_t *)in + 0x35), *((uint8_t *)in + 0x3d));
	x1 = _mm_setr_epi16(*((uint8_t *)in + 0x06), *((uint8_t *)in + 0x0e), *((uint8_t *)in + 0x16), *((uint8_t *)in + 0x1e),
		*((uint8_t *)in + 0x26), *((uint8_t *)in + 0x2e), *((uint8_t *)in + 0x36), *((uint8_t *)in + 0x3e));
	x0 = _mm_setr_epi16(*((uint8_t *)in + 0x07), *((uint8_t *)in + 0x0f), *((uint8_t *)in + 0x17), *((uint8_t *)in + 0x1f),
		*((uint8_t *)in + 0x27), *((uint8_t *)in + 0x2f), *((uint8_t *)in + 0x37), *((uint8_t *)in + 0x3f));


	t = _mm_set1_epi16(*(pkey + 135));
	x6 = _mm_xor_si128(t, x6);
	t = _mm_set1_epi16(*(pkey + 134));
	x4 = _mm_sub_epi8(x4, t);
	t = _mm_set1_epi16(*(pkey + 133));
	x2 = _mm_xor_si128(t, x2);
	t = _mm_set1_epi16(*(pkey + 132));
	x0 = _mm_sub_epi8(x0, t);

	for (i = 0; i < 120; i += 32)
	{
		RROUND_F0(x7, x6, *(pkey + i + 3));
		RROUND_F1(x5, x4, *(pkey + i + 2));
		RROUND_F0(x3, x2, *(pkey + i + 1));
		RROUND_F1(x1, x0, *(pkey + i + 0));

		RROUND_F0(x0, x7, *(pkey + i + 7));
		RROUND_F1(x6, x5, *(pkey + i + 6));
		RROUND_F0(x4, x3, *(pkey + i + 5));
		RROUND_F1(x2, x1, *(pkey + i + 4));

		RROUND_F0(x1, x0, *(pkey + i + 11));
		RROUND_F1(x7, x6, *(pkey + i + 10));
		RROUND_F0(x5, x4, *(pkey + i + 9));
		RROUND_F1(x3, x2, *(pkey + i + 8));

		RROUND_F0(x2, x1, *(pkey + i + 15));
		RROUND_F1(x0, x7, *(pkey + i + 14));
		RROUND_F0(x6, x5, *(pkey + i + 13));
		RROUND_F1(x4, x3, *(pkey + i + 12));

		RROUND_F0(x3, x2, *(pkey + i + 19));
		RROUND_F1(x1, x0, *(pkey + i + 18));
		RROUND_F0(x7, x6, *(pkey + i + 17));
		RROUND_F1(x5, x4, *(pkey + i + 16));

		RROUND_F0(x4, x3, *(pkey + i + 23));
		RROUND_F1(x2, x1, *(pkey + i + 22));
		RROUND_F0(x0, x7, *(pkey + i + 21));
		RROUND_F1(x6, x5, *(pkey + i + 20));

		RROUND_F0(x5, x4, *(pkey + i + 27));
		RROUND_F1(x3, x2, *(pkey + i + 26));
		RROUND_F0(x1, x0, *(pkey + i + 25));
		RROUND_F1(x7, x6, *(pkey + i + 24));

		RROUND_F0(x6, x5, *(pkey + i + 31));
		RROUND_F1(x4, x3, *(pkey + i + 30));
		RROUND_F0(x2, x1, *(pkey + i + 29));
		RROUND_F1(x0, x7, *(pkey + i + 28));
	}

	t = _mm_set1_epi16(*(pkey + 131));
	x5 = _mm_xor_si128(t, x5);
	t = _mm_set1_epi16(*(pkey + 130));
	x3 = _mm_sub_epi8(x3, t);
	t = _mm_set1_epi16(*(pkey + 129));
	x1 = _mm_xor_si128(t, x1);
	t = _mm_set1_epi16(*(pkey + 128));
	x7 = _mm_sub_epi8(x7, t);

	*((uint8_t *)out) = _mm_extract_epi8(x6, 0);
	*((uint8_t *)out + 0x08) = _mm_extract_epi8(x6, 2);
	*((uint8_t *)out + 0x10) = _mm_extract_epi8(x6, 4);
	*((uint8_t *)out + 0x18) = _mm_extract_epi8(x6, 6);
	*((uint8_t *)out + 0x20) = _mm_extract_epi8(x6, 8);
	*((uint8_t *)out + 0x28) = _mm_extract_epi8(x6, 10);
	*((uint8_t *)out + 0x30) = _mm_extract_epi8(x6, 12);
	*((uint8_t *)out + 0x38) = _mm_extract_epi8(x6, 14);

	*((uint8_t *)out + 0x01) = _mm_extract_epi8(x5, 0);
	*((uint8_t *)out + 0x09) = _mm_extract_epi8(x5, 2);
	*((uint8_t *)out + 0x11) = _mm_extract_epi8(x5, 4);
	*((uint8_t *)out + 0x19) = _mm_extract_epi8(x5, 6);
	*((uint8_t *)out + 0x21) = _mm_extract_epi8(x5, 8);
	*((uint8_t *)out + 0x29) = _mm_extract_epi8(x5, 10);
	*((uint8_t *)out + 0x31) = _mm_extract_epi8(x5, 12);
	*((uint8_t *)out + 0x39) = _mm_extract_epi8(x5, 14);

	*((uint8_t *)out + 0x02) = _mm_extract_epi8(x4, 0);
	*((uint8_t *)out + 0x0a) = _mm_extract_epi8(x4, 2);
	*((uint8_t *)out + 0x12) = _mm_extract_epi8(x4, 4);
	*((uint8_t *)out + 0x1a) = _mm_extract_epi8(x4, 6);
	*((uint8_t *)out + 0x22) = _mm_extract_epi8(x4, 8);
	*((uint8_t *)out + 0x2a) = _mm_extract_epi8(x4, 10);
	*((uint8_t *)out + 0x32) = _mm_extract_epi8(x4, 12);
	*((uint8_t *)out + 0x3a) = _mm_extract_epi8(x4, 14);

	*((uint8_t *)out + 0x03) = _mm_extract_epi8(x3, 0);
	*((uint8_t *)out + 0x0b) = _mm_extract_epi8(x3, 2);
	*((uint8_t *)out + 0x13) = _mm_extract_epi8(x3, 4);
	*((uint8_t *)out + 0x1b) = _mm_extract_epi8(x3, 6);
	*((uint8_t *)out + 0x23) = _mm_extract_epi8(x3, 8);
	*((uint8_t *)out + 0x2b) = _mm_extract_epi8(x3, 10);
	*((uint8_t *)out + 0x33) = _mm_extract_epi8(x3, 12);
	*((uint8_t *)out + 0x3b) = _mm_extract_epi8(x3, 14);

	*((uint8_t *)out + 0x04) = _mm_extract_epi8(x2, 0);
	*((uint8_t *)out + 0x0c) = _mm_extract_epi8(x2, 2);
	*((uint8_t *)out + 0x14) = _mm_extract_epi8(x2, 4);
	*((uint8_t *)out + 0x1c) = _mm_extract_epi8(x2, 6);
	*((uint8_t *)out + 0x24) = _mm_extract_epi8(x2, 8);
	*((uint8_t *)out + 0x2c) = _mm_extract_epi8(x2, 10);
	*((uint8_t *)out + 0x34) = _mm_extract_epi8(x2, 12);
	*((uint8_t *)out + 0x3c) = _mm_extract_epi8(x2, 14);

	*((uint8_t *)out + 0x05) = _mm_extract_epi8(x1, 0);
	*((uint8_t *)out + 0x0d) = _mm_extract_epi8(x1, 2);
	*((uint8_t *)out + 0x15) = _mm_extract_epi8(x1, 4);
	*((uint8_t *)out + 0x1d) = _mm_extract_epi8(x1, 6);
	*((uint8_t *)out + 0x25) = _mm_extract_epi8(x1, 8);
	*((uint8_t *)out + 0x2d) = _mm_extract_epi8(x1, 10);
	*((uint8_t *)out + 0x35) = _mm_extract_epi8(x1, 12);
	*((uint8_t *)out + 0x3d) = _mm_extract_epi8(x1, 14);

	*((uint8_t *)out + 0x06) = _mm_extract_epi8(x0, 0);
	*((uint8_t *)out + 0x0e) = _mm_extract_epi8(x0, 2);
	*((uint8_t *)out + 0x16) = _mm_extract_epi8(x0, 4);
	*((uint8_t *)out + 0x1e) = _mm_extract_epi8(x0, 6);
	*((uint8_t *)out + 0x26) = _mm_extract_epi8(x0, 8);
	*((uint8_t *)out + 0x2e) = _mm_extract_epi8(x0, 10);
	*((uint8_t *)out + 0x36) = _mm_extract_epi8(x0, 12);
	*((uint8_t *)out + 0x3e) = _mm_extract_epi8(x0, 14);

	*((uint8_t *)out + 0x07) = _mm_extract_epi8(x7, 0);
	*((uint8_t *)out + 0x0f) = _mm_extract_epi8(x7, 2);
	*((uint8_t *)out + 0x17) = _mm_extract_epi8(x7, 4);
	*((uint8_t *)out + 0x1f) = _mm_extract_epi8(x7, 6);
	*((uint8_t *)out + 0x27) = _mm_extract_epi8(x7, 8);
	*((uint8_t *)out + 0x2f) = _mm_extract_epi8(x7, 10);
	*((uint8_t *)out + 0x37) = _mm_extract_epi8(x7, 12);
	*((uint8_t *)out + 0x3f) = _mm_extract_epi8(x7, 14);
	return 1;
}

int hight_setkey(uint8_t* key, int keyLen, int encType, HIGHT_RK *hight_rk)
{
	if (encType)
		hight_keyschedule_dec(hight_rk, key);
	else
		hight_keyschedule_enc(hight_rk, key);

	return 0;
}


void hight_ecb_encrypt(uint8_t* in, uint8_t* out, void* key,int enc, int inLen, int keyLen, char* inPath, char *outPath)
{
    HIGHT_RK hight_rk;
    hight_setkey(key, keyLen, enc, &hight_rk);

    if(inPath)
    {
        if(enc)
            CRYPTO_ECB_FILE_Encrypt(inPath, outPath, &hight_rk, hight_decrypt,hight_decrypt_4, HIGHT_BLOCK_SIZE, HIGHT_BLOCK_SIZE);
        else
            CRYPTO_ECB_FILE_Encrypt(inPath, outPath, &hight_rk, hight_encrypt,hight_encrypt_4, HIGHT_BLOCK_SIZE, HIGHT_BLOCK_SIZE);
    }
    else
    {
        if(enc)
            CRYPTO_ECB_Encrypt(in, out, &hight_rk, hight_decrypt, inLen, HIGHT_BLOCK_SIZE);
        else
            CRYPTO_ECB_Encrypt(in, out, &hight_rk, hight_encrypt, inLen, HIGHT_BLOCK_SIZE);
    }
}

void hight_cbc_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* iv,int enc, int inLen, int keyLen, char* inPath, char *outPath)
{
    HIGHT_RK hight_rk;
    hight_setkey(key, keyLen, enc, &hight_rk);
    if(enc)
        CRYPTO_CBC_Decrypt(in, out, &hight_rk, iv, hight_decrypt, inLen, HIGHT_BLOCK_SIZE);
    else
        CRYPTO_CBC_Encrypt(in, out, &hight_rk, iv, hight_encrypt, inLen, HIGHT_BLOCK_SIZE);
}

void hight_cfb_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* iv,int enc, int inLen, int keyLen, char* inPath, char *outPath)
{
    HIGHT_RK hight_rk;
    hight_setkey(key, keyLen, enc, &hight_rk);
    if (enc)
        CRYPTO_CFB_Decrypt(in, out, &hight_rk, iv, hight_encrypt, inLen, HIGHT_BLOCK_SIZE);
    else
        CRYPTO_CFB_Encrypt(in, out, &hight_rk, iv, hight_encrypt, inLen, HIGHT_BLOCK_SIZE);
}

void hight_ofb_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* iv,int enc, int inLen, int keyLen, char* inPath, char *outPath)
{
    HIGHT_RK hight_rk;
    hight_setkey(key, keyLen, ENCRYPT, &hight_rk);
    CRYPTO_OFB_Encrypt(in, out, &hight_rk, iv, hight_encrypt, inLen, HIGHT_BLOCK_SIZE);
}

void hight_ctr_encrypt(uint8_t* in, uint8_t* out, void* key, uint8_t* ctr,int enc, int inLen, int keyLen, char* inPath, char *outPath)
{
    HIGHT_RK hight_rk;
    hight_setkey(key, keyLen, ENCRYPT, &hight_rk);

    if(inPath)
        CRYPTO_CTR_FILE_Encrypt(inPath, outPath, &hight_rk, ctr, hight_encrypt, hight_encrypt_4, HIGHT_BLOCK_SIZE, HIGHT_BLOCK_SIZE);
    else
        CRYPTO_CTR_Encrypt(in, out, &hight_rk, ctr, hight_encrypt, inLen, HIGHT_BLOCK_SIZE);
}
