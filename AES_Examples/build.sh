
make clean

test_select=CONFIG_GCM_BASE size_select=CONFIG_SIZE_128 target=base_128_hw  hw_accel=CONFIG_HW_CLMUL make  ARCH=risc-v ; make clean
test_select=CONFIG_GCM_BASE size_select=CONFIG_SIZE_192 target=base_192_hw  hw_accel=CONFIG_HW_CLMUL make  ARCH=risc-v ; make clean
test_select=CONFIG_GCM_BASE size_select=CONFIG_SIZE_256 target=base_256_hw  hw_accel=CONFIG_HW_CLMUL make  ARCH=risc-v ; make clean

test_select=CONFIG_GCM_KAR  size_select=CONFIG_SIZE_128 target=kar_128_hw   hw_accel=CONFIG_HW_CLMUL make  ARCH=risc-v ; make clean
test_select=CONFIG_GCM_KAR  size_select=CONFIG_SIZE_192 target=kar_192_hw   hw_accel=CONFIG_HW_CLMUL make  ARCH=risc-v ; make clean
test_select=CONFIG_GCM_KAR  size_select=CONFIG_SIZE_256 target=kar_256_hw   hw_accel=CONFIG_HW_CLMUL make  ARCH=risc-v ; make clean

test_select=CONFIG_GCM_BASE size_select=CONFIG_SIZE_128 target=base_128_sw  hw_accel=NCONFIG_HW_CLMUL make  ARCH=risc-v ; make clean 
test_select=CONFIG_GCM_BASE size_select=CONFIG_SIZE_192 target=base_192_sw  hw_accel=NCONFIG_HW_CLMUL make  ARCH=risc-v ; make clean
test_select=CONFIG_GCM_BASE size_select=CONFIG_SIZE_256 target=base_256_sw  hw_accel=NCONFIG_HW_CLMUL make  ARCH=risc-v ; make clean

test_select=CONFIG_GCM_KAR  size_select=CONFIG_SIZE_128 target=kar_128_sw   hw_accel=NCONFIG_HW_CLMUL make  ARCH=risc-v ; make clean
test_select=CONFIG_GCM_KAR  size_select=CONFIG_SIZE_192 target=kar_192_sw   hw_accel=NCONFIG_HW_CLMUL make  ARCH=risc-v ; make clean
test_select=CONFIG_GCM_KAR  size_select=CONFIG_SIZE_256 target=kar_256_sw   hw_accel=NCONFIG_HW_CLMUL make  ARCH=risc-v ; make clean


