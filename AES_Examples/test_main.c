//  test_main.c
//  2020-01-23  Markku-Juhani O. Saarinen <mjos@pqshield.com>
//  Copyright (c) 2020, PQShield Ltd. All rights reserved.

//  Minimal unit tests for AES-128/192/256 (FIPS 197) and SM4 (GM/T 0002-2012).

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "aes_wrap.h"
#include "saes32.h"
#include "aes_saes32.h"
#include "aes_saes64.h"
#include "aes_otf_saes64.h"

#include "gcm_wrap.h"
#include "gcm_gfmul.h"

#include "hpm.h"
//  unit tests

int test_aes();								//  aes_test.c
int test_sm4();								//  sm4_test.c
int test_gcm();								//  gcm_test.c

void setup(){

	aes128_enc_key = aes128_enc_key_saes32;	//  set encryption key
	aes192_enc_key = aes192_enc_key_saes32;
	aes256_enc_key = aes256_enc_key_saes32;

	aes128_enc_ecb = aes128_enc_ecb_saes32;	//  encrypt a block
	aes192_enc_ecb = aes192_enc_ecb_saes32;
	aes256_enc_ecb = aes256_enc_ecb_saes32;

	aes128_dec_key = aes128_dec_key_saes32;	//  set decryption key
	aes192_dec_key = aes192_dec_key_saes32;
	aes256_dec_key = aes256_dec_key_saes32;

	aes128_dec_ecb = aes128_dec_ecb_saes32;	//  decrypt a block
	aes192_dec_ecb = aes192_dec_ecb_saes32;
	aes256_dec_ecb = aes256_dec_ecb_saes32;

	aes128_enc_ecb = aes128_enc_otf_saes64;
	aes192_enc_ecb = aes192_enc_otf_saes64;
	aes256_enc_ecb = aes256_enc_otf_saes64;

	aes128_enc_key = aes128_enc_key_saes64;	//  set encryption key
	aes192_enc_key = aes192_enc_key_saes64;
	aes256_enc_key = aes256_enc_key_saes64;

	aes128_enc_ecb = aes128_enc_ecb_saes64;	//  encrypt a block
	aes192_enc_ecb = aes192_enc_ecb_saes64;
	aes256_enc_ecb = aes256_enc_ecb_saes64;

	aes128_dec_key = aes128_dec_key_saes64;	//  set decryption key
	aes192_dec_key = aes192_dec_key_saes64;
	aes256_dec_key = aes256_dec_key_saes64;

	aes128_dec_ecb = aes128_dec_ecb_saes64;	//  decrypt a block
	aes192_dec_ecb = aes192_dec_ecb_saes64;
	aes256_dec_ecb = aes256_dec_ecb_saes64;

}


int main(int argc, char **argv)
{
	int fail = 0;

	setup();


	hpm_init();
#ifdef CONFIG_GCM_BASE
	printf("[INFO] === GCM using rv32_ghash_mul() ===\n");
	ghash_rev = rv32_ghash_rev;
	ghash_mul = rv32_ghash_mul;
	fail += test_gcm();
#endif

#ifdef CONFIG_GCM_KAR
	printf("[INFO] === GCM using rv32_ghash_mul_kar() ===\n");
	ghash_rev = rv32_ghash_rev;
	ghash_mul = rv32_ghash_mul_kar;
	fail += test_gcm();
#endif
	hpm_print();


	if (fail == 0) {
		printf("[PASS] all tests passed.\n");
	} else {
		printf("[FAIL] %d test(s) failed.\n", fail);
	}

	return fail;
}
