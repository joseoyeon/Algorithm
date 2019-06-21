#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

int main(void)
{
	FILE *ansP;
	unsigned int data1[4] = { 0xDAC1A3A4, 0x1305DC93, 0x45086119, 0xD66A3A39 };
	unsigned int data2[4] = { 0xD94B0DCB, 0x81896E34, 0xC649CEF6, 0x5DBDD571 };
	unsigned int ans_1[5] = { 0, }, ans_2[4] = { 0, }, ans_3[8] = { 0, };
	int i,j; 
   int carry_1=0;
   unsigned int a, b, c, d;
   unsigned int bd, ad, cb, ca;
   unsigned int carry[8] = { 0, };
   unsigned int front1, back1, front2, back2;
   unsigned int sum;
   unsigned int sum2;

	/* + */
  for (int i = 3; i >=0; i--){
      ans_1[i+1] += data1[i] + data2[i];
      if( (ans_1[i+1] < data1[i]) || (ans_1[i+1] < data2[i]) )
         ans_1[i] += 1;
   }

	/* - */
	for(i=3; i>=0; i--){
		if(data1[i] > data2[i]) {
			ans_2[i] = data1[i] - data2[i] - carry_1;
			carry_1 =0;
			}
		else {
			ans_2[i] = (0XFFFFFFFF - data2[i] + data1[i] + 1 - carry_1);
			carry_1 = 1;
			}
	}


	/* * */

   for (int i = 3; i >=0; i--)
   {
      for (int j = 3; j >=0; j--)
      {
         a = data1[i] / 0x00010000;
         b = data1[i] % 0x00010000;
         c = data2[j] / 0x00010000;
         d = data2[j] % 0x00010000;

         bd = b * d;
         ad = a * d;
         cb = c * b;
         ca = c * a;

         front1 = ad / 0x00010000;
         back1 = (ad % 0x00010000)<<16;
         front2 = cb / 0x00010000;
         back2 = (cb % 0x00010000)<<16;

         //I+J 자리
         sum = bd + back1;
         if( (bd > sum || back1 > sum) )
         {
            carry[i+j] += 1;
         }

         sum2 = sum + back2;

         if( (sum > sum2 || back2 > sum2))
         {
            carry[i + j] += 1;
         }

         sum = sum2 + ans_3[i + j + 1];

         if( (sum2 > sum || ans_3[i + j+1] > sum) )
         {
            carry[i + j] += 1;
         }
         
         ans_3[i + j + 1] = sum;


         //I+J+1 자리
         sum = ca + front1;
         if( (ca > sum || front1 > sum))
         {
            carry[i + j - 1] += 1;
         }
         sum2 = sum + front2;
         if( (sum > sum2 || front2 > sum2))
         {
            carry[i + j - 1] += 1;
         }
         sum = sum2 + ans_3[i + j];
         if( (sum2 > sum || ans_3[i + j] > sum) )
         {
            carry[i + j -1] += 1;
         }
            ans_3[i + j] = sum;
         

      }
   }
   
   
   
   for (int i = 7; i >=0; i--)
   {
      unsigned int sum = ans_3[i] + carry[i];
      if (sum < ans_3[i] || sum < carry[i])
      {
         carry[i-1] += 1;
      }
      ans_3[i] = sum;
   }
   
   


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