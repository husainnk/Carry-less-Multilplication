
## Project Report 

[Project_Report_Carry_Less_Multiplication](Project_Report_Carry_Less_Multiplication.pdf)

## Contents of this project

1) Patch 

	generators_rocket-chip--carry-less-in-scie.patch [ Changes in Rocket Core for CLMUL Support ]

	riscv-binutils_clmul_support.patch [ Compiler Changes ]

2) clmul.c  - Test file that executes clmul instruction on two operands. Contains both H/W and S/W implementation.

3) AES_Examples - AES examples that uses new clmul instruction 

	build.sh  - Run this script to compile AES test programs. Both H/W and S/W implementations will be created seperately. 



## Build Instructions

1) Binutils Patch

```
cd ~/rocket/chipyard-<USERNAME>/toolchains/riscv-tools/riscv-gnu-toolchain/riscv-binutils
git apply <THIS_SRC>/patches/riscv-binutils_clmul_support.patch
```

Build the toolchain
```
cd chipyard-<USERNAME>
./scripts/build-toolchains.sh riscv-tools
```


2) Rocket Core Patch

```
cd ~/rocket/chipyard-<USERNAME>/generators/rocket-chip/
git apply  <THIS_SRC>/patches/generators_rocket-chip--carry-less-in-scie.patch
```

3) Compile RISC-V Application
```
source ~/rocket/chipyard-<USERNAME>/env.sh
riscv64-unknown-elf-gcc  -specs=htif_nano.specs clmul.c -o clmul.riscv

```

4) Run with Verilator

```
cd  ~/rocket/chipyard-<USERNAME>/sims/verilator
make CONFIG=ECE5504RocketConfig -j64 run-binary BINARY=~/rocket/chipyard-husainnk/clmul.riscv
```


5) Compile AES Instructions

```
cd <THIS_SRC>/AES_Examples;

./build.sh

# Following programs will be generated

xtest_riscv_base_128_hw
xtest_riscv_base_128_sw
xtest_riscv_base_192_hw
xtest_riscv_base_192_sw
xtest_riscv_base_256_hw
xtest_riscv_base_256_sw
xtest_riscv_kar_128_hw
xtest_riscv_kar_128_sw
xtest_riscv_kar_192_hw
xtest_riscv_kar_192_sw
xtest_riscv_kar_256_hw
xtest_riscv_kar_256_sw

# Run each of them with verilator

cd  ~/rocket/chipyard-<USERNAME>/sims/verilator
make CONFIG=ECE5504RocketConfig -j64 run-binary BINARY=<THIS_SRC>/AES_Examples/<PROGRAM_NAME>

```


