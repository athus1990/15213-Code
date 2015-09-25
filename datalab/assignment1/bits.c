/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	//XOR=NOT(NOT(X NAND Y) AND NOT(Y NAND X))
  	int var1=~(x & (~y)); // NOT(X NAND Y)
	int var2=~((~x) & y); // NOT(Y NAND X)
	return ~(var1 & var2); //NOT(V1 AND V2) 
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	//WE NEED 0x80000000
  	return 0x80<<24;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
	//We need to find Umax and check for corner cases
	int u=x+x+1;//Umax=2*Tmax+1
	int c=!(x+1);//A checker to check for -1 as it also gives the same
	u=~u;//1111..>0000..
        u=u|c;
	return !u;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	//Create a Mask 0xAAAAAAAA 
	int y=0xAA;//create a mask
        int z=(y<<8)+y;//0xAAAA
	int q=(z<<16)+z;//0xAAAAAAAA
 	return !((x&q)^q);//Any number XOR with itsef will be 0
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	//Complement the Unsigned number and add 1
	return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	//If the number lies between the given range of max and least value
	//chck the sign and return the value

  	int ub=x+(~0x30+1);//x-0x30
  	int c1=!(ub>>31); //check the sign
	
	int lb=0x39+(~x+1);//0x39-x
	int c2=!(lb>>31);//check the sign
	
	return c1 & c2;//Has to be witin the max AND min value
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	//check if x is TRUE OR FALSE 
	int c=!(x);//will be 0x01 OR 0x00
	c=(c<<31)>>31;//now all bits are 0 or all bits are 1
	return ((y&~c)+(z&c));//eg:0000+1111=1111
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	//idea is to check the sign of x-y<=0
 	int c=(0x80<<24);
	int v,vs,xs,ys,zs;
	v=x+(~y+1);// calculates x-y
	vs=!(v&c);//is now 00(neg),01(pos).
        xs=!(x&c);//is now 00(neg),01(pos).
        ys=!(y&c);//is now 00(neg),01(pos).
		
	//Depending on sign xs ys and vs decide
	//if xs is neg and ys is pos then true
	//if vs is neg then false
	//and so on
	zs=xs^ys;//Just so that I reduce number of ops
	return (!!(zs & ys))+((!(zs | vs))|(!v));	

}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	//Negate the value and find the sign bit
	int y=~x+1;
	int m=(0x80<<24);
     	return (((x&m)|(y&m))>>31)+1; 
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
 
	//log2(x)+2
	int a16=0,a8=0,a4=0,a2=0,a1=0,count=0,c1=0,c2=0;
	x=x^(x>>31);//Make the number positive as it does not matter

	//Corner cases
	c1=!x; //what to do if x=0
	c2=((!!x)<<31)>>31; //what to do if x=-1

	//idea is to calculate log2(x)+2
	//split the number by 2^4/2^3/2^2/2/1
	
	a16=(!!(x>>16))<<4; //shift16 bits and div 
	count=a16; //increment count
	
	a8=count+((!!(x>>(8+count)))<<3);//shift 8 and div
	count=a8; //increment count
	
	a4=count+((!!(x>>(4+count)))<<2);//shift 4 and div
	count=a4; //increment count
	
	a2=count+((!!(x>>(2+count)))<<1);//shift by 2 and div
	count=a2;//increment count
	
	a1=count+(!!(x>>(1+count)));//final bit
	count=a1;//count
	
	count=count+2;//log2(n)+2

	return c1|(count & c2);//return 0/1/value

}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */


unsigned float_twice (unsigned uf){
 
  	int e,f,s;
      	e= ((uf>>23) & 0xFF);//extracted the exponent
      	f= uf & 0x007FFFFF;//extracted the mantisa
       	s= uf & (0x80<<24);//extracted the sign
	
	//Corner cases
	if (e==255 || (e == 0 && f == 0)) return uf;  //Deal with NAN and INF
	
	if (e) {
			if(e==0xFE) return s|((e+1)<<23)|0; // if e=11111110 and we add 1 it becomes INF/NAN. So we want to clear f bits
			else return s|((e+1)<<23)|f; //simple 2^E*2=2^(E+1)
	} else return s |( e << 23) |(f<<1);//If none of the cases go thro e=0 and it is a denorm 
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {

	//Initialisation of variables
  	unsigned int c=0,dum; //the number of bits,dummy value 
  	unsigned int f,e; //frac,e
	unsigned s=x & 0x80000000;//sign bit
	dum=x; 

	// Deal with corner cases when x=0 or Tmax
	if(x==0)return 0;
        if(x==0x80000000) return 0xCF000000;


	if(x<0)dum=-x; //make the dummy always postvite so we don't get confused in loop

    	while (!(dum & 0x80000000)) //Keep running until u hit the first bit  
    	{  
                dum<<=1;  
                c++; //Gives the 32-number of bits      
    	}
	
	dum=dum<<1; //Extra MSB bit
	c++;  //Extra MSB bit
 	
	f=dum>>9; // shift the frac bits by 32-23 positions
	e=(159-c)<<23; //127+(32-number of bits)<<23
	
    	if ((dum & 0x01ff)>0x0100 || (dum & 0x03ff)==0x0300 ) //when to roundup or roundeven 
        {
		 return s+e+f+1;//Add one to roundup
	}
    	else  
	{	 return s+e+f ; //Don't add
	}	
}

/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	//Initialisation of variables
	unsigned int dum; //the number of bits,dummy value
	unsigned int f,e,E,s; //frac,e,Exponent	 

	e = (uf >> 23) & 0xFF;//exp
        f = uf & 0x007FFFFF;//frac
	s=uf & 0x80000000;//sign bit
	E=e-127;//EXPONENT	 

	if (e == 0xFF) return 0x80000000u;//return for INF
	if (e < 127)  return 0x0;//denorm
	if (E>= 31)  return 0x80000000u;//overflow
	if (E> 22)   dum = f << (E - 23);//f*2^(-(E-23))
	else  dum = f >> (23 - E);//f*2^(23-E)

	dum=dum+(1<< E);//add 1 for the norm
	if (s) dum = -dum;//if negative negate
	return dum;
  
}
