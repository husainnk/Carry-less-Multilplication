

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "hpm.h"



uint64_t  HW_CLMUL(uint64_t op_a,uint64_t op_b)
{

	uint64_t result=0;
	asm volatile("clmul %0, %1,%2\n":"=r"(result):"r"(op_a),"r"(op_b):);
	printf("CLMUL:(h/w) 0x%"PRIx64 "\n",result);

	result=0;
	asm volatile("clmulh %0, %1,%2\n":"=r"(result):"r"(op_a),"r"(op_b):);
	printf("CLMUL-H:(h/w) 0x%"PRIx64 "\n",result);

	result=0;
	asm volatile("clmulbig %0, %1,%2\n":"=r"(result):"r"(op_a),"r"(op_b):);
	printf("CLMUL-64:(h/w) 0x%"PRIx64 "\n",result);

	result=0;
	asm volatile("clmulbigh %0, %1,%2\n":"=r"(result):"r"(op_a),"r"(op_b):);
	printf("CLMUL-64-H:(h/w) 0x%"PRIx64 "\n",result);

	return result ;
}

uint64_t  SW_CLMUL(uint64_t op_a,uint64_t op_b)
{
	uint64_t result = 0;
	for( size_t i = 0; i < 32; ++i )
	{
		if( (op_a >> i) & 1 )
		{
			result ^= (op_b) << i;
		}
	}	
	printf("CLMUL:(s/w) 0x%"PRIx64 "\n",result);
	return result ;
}

int main(void)
{
	
	hpm_init();

	uint64_t ret ;
	for(int i=0; i< 1 ; i++)
	{
		uint64_t op_a = 0xbf4d931e ;
		uint64_t op_b = 0x9b9c9322 ;
		ret = HW_CLMUL(op_a,op_b);
		ret = SW_CLMUL(op_a,op_b);
	}
	hpm_print();
	return 0;
}
