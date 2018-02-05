
#define TEST_COM_BASE ((volatile int*)(0xF00FFF00))

int var1 = 32;
int var2 = 0;
int var3 = 0;
int main() {
	TEST_COM_BASE[0] = var1 + var2 + var3;
	var1 += 1;
}


void irqCallback(int irq){

}

int miaou(){
	return 2;
}


