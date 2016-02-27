#include "cpu/exec/template-start.h"

#define instr shld

#if DATA_BYTE == 2 || DATA_BYTE == 4
static void do_execute () {
	DATA_TYPE in = op_dest->val;
	DATA_TYPE out = op_src2->val;
	uint8_t count = op_src->val;
	count &= 0x1f;
	while(count != 0) {
		out <<= 1;
		out |= (in>>((DATA_BYTE<<3)-1)) & 1;
		in <<= 1;
		count --;
	}

	OPERAND_W(op_src2, out);

	print_asm("shld" str(SUFFIX) " %s,%s,%s", op_src->str, op_dest->str, op_src2->str);
}

make_instr_helper(si_rm2r)
#endif



#include "cpu/exec/template-end.h"
