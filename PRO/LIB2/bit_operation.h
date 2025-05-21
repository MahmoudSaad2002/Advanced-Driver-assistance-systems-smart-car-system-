#ifndef bit_operation
#define bit_operation
 
#define set_bit(reg,bit) reg|=(1<<bit)
#define clear_bit(reg,bit) reg&=(~(1<<bit))
#define toggle_bit(reg,bit) reg^=(1<<bit)
#define read_bit(reg,bit) (reg>>bit)&1
#define clear_bin(reg,bit) reg&=(~(1<<bit))
#define set_bin(reg,bit) reg|=(1<<bit)
#define set_port(reg)    reg=0xff
#define clear_port(reg)  reg=0x00

#endif
