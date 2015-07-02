/**
 *	TCE - The Tiny Computer Emulator
 *	(It's just a 16 bit architecture emulator)
 *	Written by Joe Dolan
 *	Modeled after the Intel 8086's internals
 *
 *	I made this as a teaching tool for students and hobbyists to 
 *	Learn how computer architecture works with a fairly simple computer
 */

//Basic types in TCE 
typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
typedef signed int i32;


//The status register, a special register outlined for special cases
//You can read more about the status register 
typedef union SRegister {
	u8 lowBit;			// 0-8 [0, 0, 0, 0, O, D, I, T]
	u8 highBit;			// 8-f [S, Z, 0, A, 0, P, 0, C]
};

//Registers are all just 16 bit numbers stored that we manipulate. Nothing scary here, I swear
enum Register: u16 {
	//Main Registers
	AX,			// Primary 
	BX,			// Base 
	CX,			// Counter
	DX,			// Other
	
	//Index Registers
	SI,			// Source Index
	DI,			// Destination Index
	BP,			// Base Pointer
	SP,			// Stack Pointer

	//Program Counter
	IP,			// Instruction pointer

	//Segment Register
	CS,			// Code Segment
	DS,			// Data Segment
	ES,			// Extra Segment
	SS			// Stack Segment
};


//We'll give this puppy 10K of memory. 
u16 memory[0x10000], registers[12] = {};

enum opCodes { MOV, ADD, SUB, MUL, DIV, SHL, SHR, AND, OR, XOR, IFE, IFN, IFG, IFL };



struct CPU
{
	//Execute the next operation
	void exOp(opCodes o, u16 a, u16 b)
	{
		switch (o)
		{
		case MOV:
			registers[a] = registers[b];
			break;
		case ADD:
			registers[a] += registers[b];
			break;
		case SUB:
			registers[a] -= registers[b];
			break;
		case MUL:
			registers[a] *= registers[b];
			break;
		case DIV:
			registers[a] /= registers[b];
			break;
		case SHL:
			registers[a] <<= b;
			break;
		case SHR:
			registers[a] >>= b;
			break;
		case AND:
			registers[a] &= registers[b];
			break;
		case OR:
			registers[a] |= registers[b];
			break;
		case XOR:
			registers[a] ^= registers[b];
			break;
		default:
			break;
		}
	}
};

int main(int argc, char* argv[])
{
	return 0;
}