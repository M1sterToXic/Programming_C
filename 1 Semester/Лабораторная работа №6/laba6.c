// int a = 0xBAADF00D
//(a >> 24) << 8 = ?

//0x0000BA00

unsignet int a = 0x00C0FFEE;
unsignet char c;
c = (a & 0x000000FF); //тоже что и (a & 0xFF)
printf("a = %x\n", c); // c == 0xEE

c = ((a >>8) & 0x000000FF);
printf("a = %x\n",c ); // c == 0x00FF



// 5 >> i
// 00000000
// 00000001 & ==
// 00000000

// 00000000
// 00000001 | ==
// 00000001

int main(){
    


}