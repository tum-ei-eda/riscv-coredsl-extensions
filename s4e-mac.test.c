// Basic test of assembly and layout of sample S4E MAC instruction extensions

// RUN: %clang --target=riscv32 -march=rv32ixs4emac -c -o %t.o %s
// RUN: llvm-objdump --disassembler-options=numeric -d %t.o | FileCheck %s

int main() {
  // Non-ISAX canary instruction, to flag an unwanted case of endian/width/compression/whatever
  // CHECK: b3 01 52 00 add x3, x4, x5
  asm("add x3, x4, x5");

  // CHECK: 0b 00 00 00 reset_acc
  asm("reset_acc");

  // CHECK: 0b 03 00 02 get_acc_lo x6
  asm("get_acc_lo x6");

  // CHECK: 8b 0c 00 04 get_acc_hi x25
  asm("get_acc_hi x25");

  // CHECK: 0b 90 1a 01 macu_32 x21, x17
  asm("macu_32 x21, x17");

  // CHECK: 0b 90 1a 03 macs_32 x21, x17
  asm("macs_32 x21, x17");

  // CHECK: 0b a0 1a 01 macu_64 x21, x17
  asm("macu_64 x21, x17");

  // CHECK: 0b a0 1a 03 macs_64 x21, x17
  asm("macs_64 x21, x17");

  return 42;
}
