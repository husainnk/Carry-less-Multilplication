

#include <stdio.h>
#include <stdint.h>
#include "hpm.h"


#define HW_CLMUL 1

uint64_t  HW_CLMUL(uint32_t op_a,uint32_t op_b)
{

	uint64_t result;
	asm volatile("clmul %0, %1,%2\n":"=r"(result):"r"(op_a),"r"(op_b):);

	printf("CLMUL:(h/w) 0x%x\n",result);
	return result ;
}

uint64_t  SW_CLMUL(uint32_t op_a,uint32_t op_b)
{
	uint64_t result = 0;
	for( size_t i = 0; i < 16; ++i )
	{
		if( (op_a >> i) & 1 )
		{
			result ^= (op_b) << i;
		}
	}	
	printf("CLMUL:(s/w) 0x%x\n",result);

	return result ;
}

int main(void)
{
	
	hpm_init();

	uint64_t ret ;
	for(int i=0; i< 1000 ; i++)
#ifdef HWCLMUL
		ret = HW_CLMUL(0xffabdfdf,0xffabefef);
#else
		ret = SW_CLMUL(0xAD,0x10);
#endif
	hpm_print();
	return 0;
}
