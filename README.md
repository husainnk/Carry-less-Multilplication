


1) Binutils Patch

```
cd ~/rocket/chipyard-husainnk/toolchains/riscv-tools/riscv-gnu-toolchain/riscv-binutils
git apply <git-repo>/riscv-binutils_clmul_support.patch
```

Build the toolchain
```
cd chipyard-<USERNAME>
./scripts/build-toolchains.sh riscv-tools
```


2) Rocket Core Patch

```
cd /home/nkhusain/rocket/chipyard-husainnk/generators/rocket-chip/
git apply  <git-repo>/generators_rocket-chip--carry-less-in-scie.patch
```

3) Compile RISC-V Application
```
source ~/rocket/chipyard-husainnk/env.sh
riscv64-unknown-elf-gcc  -specs=htif_nano.specs clmul.c -o clmul.riscv

```

4) Run with Verilator

```
cd  ~/rocket/chipyard-husainnk/sims/verilator
make CONFIG=ECE5504RocketConfig -j64 run-binary BINARY=/home/nkhusain/rocket/chipyard-husainnk/clmul.riscv
```

