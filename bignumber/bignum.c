
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

int main(void)
{
	FILE *ansP;
	unsigned int data1[4] = { 0xDAC1A3A4, 0x1305DC93, 0x45086119, 0xD66A3A39 };
	unsigned int data2[4] = { 0xD94B0DCB, 0x81896E34, 0xC649CEF6, 0x5DBDD571 };
	int carry =0x0;
	unsigned int ans_1[5] = { 0, }, ans_2[4] = { 0, }, ans_3[8] = { 0, };
	unsigned long long int d1 = 0XDAC1A3A41305, d2=0xD94B0DCB8189;
	int i= 0; 
printf("%llX", d1-d2);
	/* + */
	for(int i=3; i>=0; i--){
		ans_1[i+1] += data1[i] + data2[i];
		if(data1[i] > ans_1[i+1]) {ans_1[i]+= 1;} //carry
	}
	
	carry = 0;	

	/* - */
	for(int i=3; i>=0; i--){
		if(data1[i] > data2[i]) {
			ans_2[i] = data1[i] - data2[i] - carry;
			carry =0;
			}
		else {
			ans_2[i] = (0XFFFFFFFF - data2[i] + data1[i] + 1 - carry);
			carry = 1;
			}
	}

	// for (int i=0; i<4;i++){
	// 	printf("%08X\n", ans_2[i]);
	// }


	/* * */
		
// 3 * 3 뒤 
		ans_3[7] += (data1[3] & 0x0000ffff)*(data2[3] & 0x0000ffff);
		ans_3[7] += ((data1[3] >>16)*(data2[3] & 0x0000ffff))<<16;
		ans_3[7] += ((data1[3] & 0x0000ffff)*(data2[3] >>16))<<16; // 뒤

//3*3 앞 /  2 * 3 앞 뒤, 3 * 2 뒤
		ans_3[6] += ((data1[3] >> 16) * (data2[3] & 0x0000ffff)) >> 16; 
		ans_3[6] += ((data1[3] & 0x0000ffff)*(data2[3] >> 16)) >>16;
		ans_3[6] += ((data1[3] >> 16)*(data2[3] >> 16)); //앞

		ans_3[6] += ((data1[2] & 0x0000ffff)*(data2[3] & 0x0000ffff));
		ans_3[6] += ((data1[2] >>16)*(data2[3] & 0x0000ffff))<<16;
		ans_3[6] += ((data1[2] & 0x0000ffff)*(data2[3] >> 16))<<16; //앞

		ans_3[6] += ((data1[2] >> 16) * (data2[3] & 0x0000ffff)) >> 16; 
		ans_3[6] += ((data1[2] & 0x0000ffff)*(data2[3] >> 16)) >>16;
		ans_3[6] += ((data1[2] >> 16)*(data2[3] >> 16)); //뒤

		ans_3[6] += ((data1[3] >> 16) * (data2[2] & 0x0000ffff)) >> 16; 
		ans_3[6] += ((data1[3] & 0x0000ffff)*(data2[2] >> 16)) >>16;
		ans_3[6] += ((data1[3] >> 16)*(data2[2] >> 16)); //뒤

// 2*3 앞 / 1 * 3 앞 뒤, 
		ans_3[5] += ((data1[2] >> 16) * (data2[3] & 0x0000ffff)) >> 16; 
		ans_3[5] += ((data1[2] & 0x0000ffff)*(data2[3] >> 16)) >>16;
		ans_3[5] += ((data1[2] >> 16)*(data2[3] >> 16)); //앞

		ans_3[5] += ((data1[1] & 0x0000ffff)*(data2[3] & 0x0000ffff));
		ans_3[5] += ((data1[1] >>16)*(data2[3] & 0x0000ffff))<<16;
		ans_3[5] += ((data1[1] & 0x0000ffff)*(data2[3] >> 16))<<16; // 뒤
		
		ans_3[5] += ((data1[3] >> 16) * (data2[2] & 0x0000ffff)) >> 16; 
		ans_3[5] += ((data1[3] & 0x0000ffff)*(data2[2] >> 16)) >>16;
		ans_3[5] += ((data1[3] >> 16)*(data2[2] >> 16));  //앞

		ans_3[5] += ((data1[2] & 0x0000ffff)*(data2[2] & 0x0000ffff));
		ans_3[5] += ((data1[2] >>16)*(data2[2] & 0x0000ffff))<<16;
		ans_3[5] += ((data1[2] & 0x0000ffff)*(data2[2] >> 16))<<16; // 뒤

		ans_3[5] += ((data1[3] & 0x0000ffff)*(data2[1] & 0x0000ffff));
		ans_3[5] += ((data1[3] >>16)*(data2[1] & 0x0000ffff))<<16;
		ans_3[5] += ((data1[3] & 0x0000ffff)*(data2[1] >> 16))<<16; //뒤

//0 * 3
		ans_3[4] += ((data1[1] >> 16) * (data2[3] & 0x0000ffff)) >> 16; 
		ans_3[4] += ((data1[1] & 0x0000ffff)*(data2[3] >> 16)) >>16;
		ans_3[4] += ((data1[1] >> 16)*(data2[3] >> 16)); //앞

		ans_3[4] += ((data1[0] & 0x0000ffff)*(data2[3] & 0x0000ffff));
		ans_3[4] += ((data1[0] >>16)*(data2[3] & 0x0000ffff))<<16;
		ans_3[4] += ((data1[0] & 0x0000ffff)*(data2[3] >> 16))<<16; //뒤

		ans_3[4] += ((data1[2] >> 16) * (data2[2] & 0x0000ffff)) >> 16; 
		ans_3[4] += ((data1[2] & 0x0000ffff)*(data2[2] >> 16)) >>16;
		ans_3[4] += ((data1[2] >> 16)*(data2[2] >> 16)); //앞

		ans_3[4] += ((data1[1] & 0x0000ffff)*(data2[2] & 0x0000ffff));
		ans_3[4] += ((data1[1] >>16)*(data2[2] & 0x0000ffff))<<16;
		ans_3[4] += ((data1[1] & 0x0000ffff)*(data2[2] >> 16))<<16; //뒤

		ans_3[4] += ((data1[3] >> 16) * (data2[1] & 0x0000ffff)) >> 16; 
		ans_3[4] += ((data1[3] & 0x0000ffff)*(data2[1] >> 16)) >>16;
		ans_3[4] += ((data1[3] >> 16)*(data2[1] >> 16)); //앞

		ans_3[4] += ((data1[2] & 0x0000ffff)*(data2[1] & 0x0000ffff));
		ans_3[4] += ((data1[2] >>16)*(data2[1] & 0x0000ffff))<<16;
		ans_3[4] += ((data1[2] & 0x0000ffff)*(data2[1] >> 16))<<16; //뒤

		ans_3[4] += ((data1[3] & 0x0000ffff)*(data2[0] & 0x0000ffff));
		ans_3[4] += ((data1[3] >>16)*(data2[0] & 0x0000ffff))<<16;
		ans_3[4] += ((data1[3] & 0x0000ffff)*(data2[0] >> 16))<<16; //뒤


//3*2dd
		ans_3[3] += ((data1[0] >> 16) * (data2[3] & 0x0000ffff)) >> 16; 
		ans_3[3] += ((data1[0] & 0x0000ffff)*(data2[3] >> 16)) >>16;
		ans_3[3] += ((data1[0] >> 16)*(data2[3] >> 16)); //앞

		ans_3[3] += ((data1[1] >> 16) * (data2[2] & 0x0000ffff)) >> 16; 
		ans_3[3] += ((data1[1] & 0x0000ffff)*(data2[2] >> 16)) >>16;
		ans_3[3] += ((data1[1] >> 16)*(data2[2] >> 16)); //앞

		ans_3[3] += ((data1[0] & 0x0000ffff)*(data2[2] & 0x0000ffff));
		ans_3[3] += ((data1[0] >>16)*(data2[2] & 0x0000ffff))<<16;
		ans_3[3] += ((data1[0] & 0x0000ffff)*(data2[2] >> 16))<<16; // 뒤

		ans_3[3] += ((data1[2] >> 16) * (data2[1] & 0x0000ffff)) >> 16; 
		ans_3[3] += ((data1[2] & 0x0000ffff)*(data2[1] >> 16)) >>16;
		ans_3[3] += ((data1[2] >> 16)*(data2[1] >> 16)); //앞

		ans_3[3] += ((data1[1] & 0x0000ffff)*(data2[1] & 0x0000ffff));
		ans_3[3] += ((data1[1] >>16)*(data2[1] & 0x0000ffff))<<16;
		ans_3[3] += ((data1[1] & 0x0000ffff)*(data2[1] >> 16))<<16; // 뒤

		ans_3[3] += ((data1[3] >> 16) * (data2[0] & 0x0000ffff)) >> 16; 
		ans_3[3] += ((data1[3] & 0x0000ffff)*(data2[0] >> 16)) >>16;
		ans_3[3] += ((data1[3] >> 16)*(data2[0] >> 16)); //앞

		ans_3[3] += ((data1[3] & 0x0000ffff)*(data2[1] & 0x0000ffff));
		ans_3[3] += ((data1[3] >>16)*(data2[1] & 0x0000ffff))<<16;
		ans_3[3] += ((data1[3] & 0x0000ffff)*(data2[1] >> 16))<<16; // 뒤

//
		ans_3[2] += ((data1[0] >> 16) * (data2[2] & 0x0000ffff)) >> 16; 
		ans_3[2] += ((data1[0] & 0x0000ffff)*(data2[2] >> 16)) >>16;
		ans_3[2] += ((data1[0] >> 16)*(data2[2] >> 16)); //앞

		ans_3[2] += ((data1[1] >> 16) * (data2[1] & 0x0000ffff)) >> 16; 
		ans_3[2] += ((data1[1] & 0x0000ffff)*(data2[1] >> 16)) >>16;
		ans_3[2] += ((data1[1] >> 16)*(data2[1] >> 16)); //앞

		ans_3[2] += ((data1[3] >> 16) * (data2[1] & 0x0000ffff)) >> 16; 
		ans_3[2] += ((data1[3] & 0x0000ffff)*(data2[1] >> 16)) >>16;
		ans_3[2] += ((data1[3] >> 16)*(data2[1] >> 16)); //앞

		ans_3[2] += ((data1[0] & 0x0000ffff)*(data2[1] & 0x0000ffff));
		ans_3[2] += ((data1[0] >>16)*(data2[1] & 0x0000ffff))<<16;
		ans_3[2] += ((data1[0] & 0x0000ffff)*(data2[1] >> 16))<<16; // 뒤

		ans_3[2] += ((data1[3] & 0x0000ffff)*(data2[2] & 0x0000ffff));
		ans_3[2] += ((data1[3] >>16)*(data2[2] & 0x0000ffff))<<16;
		ans_3[2] += ((data1[3] & 0x0000ffff)*(data2[2] >> 16))<<16; // 뒤

//
		ans_3[1] += ((data1[0] >> 16) * (data2[1] & 0x0000ffff)) >> 16; 
		ans_3[1] += ((data1[0] & 0x0000ffff)*(data2[1] >> 16)) >>16;
		ans_3[1] += ((data1[0] >> 16)*(data2[1] >> 16)); //앞

		ans_3[1] += ((data1[3] >> 16) * (data2[2] & 0x0000ffff)) >> 16; 
		ans_3[1] += ((data1[3] & 0x0000ffff)*(data2[2] >> 16)) >>16;
		ans_3[1] += ((data1[3] >> 16)*(data2[2] >> 16)); //앞
		
		ans_3[1] += ((data1[3] & 0x0000ffff)*(data2[3] & 0x0000ffff));
		ans_3[1] += ((data1[3] >>16)*(data2[3] & 0x0000ffff))<<16;
		ans_3[1] += ((data1[3] & 0x0000ffff)*(data2[3] >> 16))<<16; // 뒤

//
		ans_3[0] += ((data1[3] >> 16) * (data2[3] & 0x0000ffff)) >> 16; 
		ans_3[0] += ((data1[3] & 0x0000ffff)*(data2[3] >> 16)) >>16;
		ans_3[0] += ((data1[3] >> 16)*(data2[3] >> 16)); //앞


	ansP = fopen("./ans.csv", "w");

	for (i = 0; i < 5; i++)
		fprintf(ansP, "%08X", ans_1[i]);
	
	fputs("\n", ansP);
	
	for (i = 0; i < 4; i++)
		fprintf(ansP, "%08X", ans_2[i]);

	fputs("\n", ansP);

	for (i = 0; i < 8; i++)
		fprintf(ansP, "%08X", ans_3[i]);

	fclose(ansP);
	system("anscheck.exe");

	return 0;
}
