#	Makefile
#	2020-01-22	Markku-Juhani O. Saarinen <mjos@pqshield.com>
#   Copyright (c) 2020, PQShield Ltd.  All rights reserved.

#	export all variables to sub-makefiles
export				

BIN		= xtest


$(info arch=$(ARCH) )


ifeq ($(ARCH), risc-v)
CC             = riscv64-unknown-elf-gcc 
CFLAGS          = -g -specs=htif_nano.specs  -D${test_select} -D${size_select} -D${hw_accel}
BIN            = xtest_riscv_${target}
else
CC             = gcc
BIN            = xtest_x86_${target}

CFLAGS = -g -D${test_select} -D${size_select}
endif
 
CSRC	= $(wildcard *.c)
OBJS	= $(CSRC:.c=.o)
#CFLAGS	= -Wall -Wextra -Wshadow -fsanitize=address,undefined -O2 -g
#CFLAGS	= -Wall -march=native -O3
LIBS    +=

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(LIBS)

%.o:	%.[cS]
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS) $(BIN) *~ 
	cd hdl && $(MAKE) clean

