#include<stdio.h>
#include <string.h>

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define KEY_LEN 256 // 키 길이 BIT 단위
#define ROL(x,i) (((x) << (i)) | ((x) >> (32-(i))))
#define ROR(x,i) (((x) >> (i)) | ((x) << (32-(i))))

void LEA_enc_KeySchedule(uint8_t* K, uint32_t* RK, uint8_t Round);
void LEA_dec_KeySchedule(uint8_t* K, uint32_t* RK, uint8_t Round);
void LEA_Encrypt(uint32_t *X, uint32_t *RK, uint8_t Round);
void LEA_Decrypt(uint32_t *X, uint32_t *RK, uint8_t Round);

int key_len; // BYTE 단위의 키 길이

int main() {
    uint8_t K[32] = {0x0f, 0x1e, 0x2d, 0x3c, 0x4b, 0x5a, 0x69, 0x78, 0x87, 0x96, 0xa5, 0xb4, 0xc3, 0xd2, 0xe1, 0xf0,
                    0xf0, 0xe1, 0xd2, 0xc3, 0xb4, 0xa5, 0x96, 0x87, 0x78, 0x69, 0x5a, 0x4b, 0x3c, 0x2d, 0x1e, 0x0f};
    // uint8_t P[16]=  {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f}; // 128
    // uint8_t P[16]=  {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f}; // 192
    uint8_t P[16]=  {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f}; //256
    uint32_t X[4] = {0,};
    uint32_t D[4] = {0,};
    uint32_t RK[192] = {0,};
    uint8_t i=0, k=0;
    uint8_t round=0;

/*#############평문은 항상 16으로 고정#########*/
    memcpy(X, P, 16);

    /*############## key_len 체크################# */
    if(KEY_LEN == 128) {memcpy(RK, K, 16); key_len = 16; round = 24;} // 128/32
    else if(KEY_LEN == 192){memcpy(RK, K, 24); key_len = 24; round = 28;}
    else if(KEY_LEN == 256){memcpy(RK, K, 32); key_len = 32; round = 32;}
    else{printf("error! key_len check, 128, 192, 256.");}

    /*############## TEST ################# */
    printf("\nPlainText : ");
    for (i=0; i<16; i++) printf("%02x ", P[i]);
    printf("\nKey : ");
    for (i=0; i<key_len; i++) printf("%02x ", K[i]);    

    LEA_enc_KeySchedule(K, RK, round);
    LEA_Encrypt(X, RK, round);

    printf("\nEncrypt : ");
    memcpy(P, X, 16);
    for (i=0; i<16; i++) printf("%02x ", P[i]);
    // for (i=0; i<4; i++) printf("%08x ", X[i]);

    LEA_dec_KeySchedule(K, RK, round);
    LEA_Decrypt(X, RK, round);

    printf("\nDecrypt : ");
    memcpy(P, X, 16);
    for (i=0; i<16; i++) printf("%02x ", P[i]);
    // for (i=0; i<4; i++) printf("%08x ", X[i]);

    // system("pause");
    return 0;
}

void LEA_Encrypt(uint32_t * X, uint32_t *RK, uint8_t Round){
    uint32_t X_[4]; 
    uint32_t i,j=0,q; //q 는 출력을 위한 변수

    for(i=0; i<Round; i++)
    {
        
        /*################출력####################*/
    // printf("\n%d, text : ",i );
    // for (q=0; q<4; q++) printf("%08x ", X[q]);
    //     printf("\n\n");
    // if(i != 25) {printf("\n%d, key : ",i +1);
    // for (q=j; q<j+6; q++){ printf("%08x ", RK[q]);}}
        /*####################################*/

        X_[0] = ROL((X[0]^RK[j+0]) + (X[1]^RK[j+1]),9);
        X_[1] = ROR((X[1]^RK[j+2]) + (X[2]^RK[j+3]),5);
        X_[2] = ROR((X[2]^RK[j+4]) + (X[3]^RK[j+5]),3);
        X_[3] = X[0];
        j += 6;
    memcpy(X, X_, 16);
    }
}

/*
Feistel 구조인데 왜 암복호화가 따로 정의 되어 있는지 모르겠다.
ROR 부분과 +/-를 다르게 한 것 뿐 구조는 암호화 과정과 동일하다.
*/

void LEA_Decrypt(uint32_t * X, uint32_t *RK, uint8_t Round){
    uint32_t X_[4]; 
    uint32_t i,j=0,q;

    for(i=0; i<Round; i++)
    {
        /*################출력####################*/
    // printf("\n%d, text : ",i );
    // for (q=0; q<4; q++) printf("%08x ", X[q]);
    //     printf("\n\n");
    // if(i != 25) {printf("\n%d, key : ",i +1);
    // for (q=j; q<j+6; q++){ printf("%08x ", RK[q]);}}
        /*####################################*/

        X_[0] = X[3];

        X_[1] = ROR(X[0], 9);
        X_[1] = (X_[1] - (X[3]^RK[j++])) ^ RK[j++];

        X_[2] = ROL(X[1], 5);
        X_[2] = (X_[2] - (X_[1]^RK[j++])) ^ RK[j++];

        X_[3] = ROL(X[2], 3);
        X_[3] = (X_[3] - (X_[2]^RK[j++])) ^ RK[j++] ;
  
    memcpy(X, X_, 16);
    }
}

const uint32_t C[8] = {0xc3efe9db, 0x44626b02, 0x79e27c8a, 0x78df30ec, 0x715ea49e, 0xc785da0a, 0xe04ef22a, 0xe5c40957};

void LEA_enc_KeySchedule(uint8_t* K, uint32_t* RK, uint8_t Round){
    uint32_t T[8];
    uint32_t i=0,j=0,q;

    memcpy(T, K, key_len);

    switch (Round){
    case 24:
        for(i=0; i<24; i++)
        {
            T[0] = (T[0]+ROL(C[i % 4], i));
            T[0]  = ROL(T[0] ,1);

            T[1] = (T[1] + ROL(C[i % 4], i+1));
            T[1]  = ROL(T[1], 3);

            T[2] = (T[2] + ROL(C[i % 4], i+2));
            T[2]  = ROL(T[2] ,6);

            T[3] = (T[3] + ROL(C[i % 4], i+3));
            T[3]  = ROL(T[3] ,11);

            RK[j] = T[0];
            RK[j+1] = T[1];
            RK[j+2] = T[2];
            RK[j+3] = T[1];
            RK[j+4] = T[3];
            RK[j+5] = T[1];
            j+=6;
        }
        break;
    case 28: 
        for(i=0; i<28; i++)
            {
                T[0] = (T[0]+ROL(C[i % 6], i));
                T[0]  = ROL(T[0] ,1);

                T[1] = (T[1] + ROL(C[i % 6], i+1));
                T[1]  = ROL(T[1], 3);

                T[2] = (T[2] + ROL(C[i % 6], i+2));
                T[2]  = ROL(T[2] ,6);

                T[3] = (T[3] + ROL(C[i % 6], i+3));
                T[3]  = ROL(T[3] ,11);

                T[4] = (T[4] + ROL(C[i % 6], i+4));
                T[4]  = ROL(T[4] ,13);

                T[5] = (T[5] + ROL(C[i % 6], i+5));
                T[5]  = ROL(T[5] ,17);

                RK[j] = T[0];
                RK[j+1] = T[1];
                RK[j+2] = T[2];
                RK[j+3] = T[3];
                RK[j+4] = T[4];
                RK[j+5] = T[5];
                j+=6;
            }
            break;
    case 32:   
        for(i=0; i<32; i++) 
            { q = 6*i;
                T[q % 8] = (T[q % 8]+ROL(C[i % 8], i));
                T[q % 8]  = ROL(T[q % 8] ,1);

                T[(q+1) % 8] = (T[(q+1) % 8] + ROL(C[i % 8], i+1));
                T[(q+1) % 8]  = ROL(T[(q+1) % 8], 3);

                T[(q+2) % 8] = (T[(q+2) % 8] + ROL(C[i % 8], i+2));
                T[(q+2) % 8]  = ROL(T[(q+2) % 8] ,6);

                T[(q+3) % 8] = (T[(q+3) % 8] + ROL(C[i % 8], i+3));
                T[(q+3) % 8]  = ROL(T[(q+3) % 8] ,11);

                T[(q+4) % 8] = (T[(q+4) % 8] + ROL(C[i % 8], i+4));
                T[(q+4) % 8]  = ROL(T[(q+4) % 8] ,13);

                T[(q+5) % 8] = (T[(q+5) % 8] + ROL(C[i % 8], i+5));
                T[(q+5) % 8]  = ROL(T[(q+5) % 8] ,17);

                RK[j] = T[q % 8];
                RK[j+1] = T[(q+1) % 8];
                RK[j+2] = T[(q+2) % 8];
                RK[j+3] = T[(q+3) % 8];
                RK[j+4] = T[(q+4) % 8];
                RK[j+5] = T[(q+5) % 8];
                j+=6;
            }
            break;
    default:
        break;
    }

        /*################출력####################*/
    /*키 출력*/
    // for (q=0; q<192; q++) {
    //     if(q%6 == 0) printf("\n");
    //     printf("%08x ", RK[q]);}
    // printf("\n\nend key\n\n");
            /*####################################*/
}

void LEA_dec_KeySchedule(uint8_t* K, uint32_t* RK, uint8_t Round){
    uint32_t T[8];
    uint32_t i=0,j,q;
    
    memcpy(T, K, key_len);
    
    switch (Round){
    case 24:
        j=138;
        for(i=0; i<24; i++)
        {
            T[0] = (T[0]+ROL(C[i % 4], i));
            T[0]  = ROL(T[0] ,1);

            T[1] = (T[1] + ROL(C[i % 4], i+1));
            T[1]  = ROL(T[1], 3);

            T[2] = (T[2] + ROL(C[i % 4], i+2));
            T[2]  = ROL(T[2] ,6);

            T[3] = (T[3] + ROL(C[i % 4], i+3));
            T[3]  = ROL(T[3] ,11);

            RK[j] = T[0];
            RK[j+1] = T[1];
            RK[j+2] = T[2];
            RK[j+3] = T[1];
            RK[j+4] = T[3];
            RK[j+5] = T[1];
            j-=6;
        }
        break;
    case 28: 
        j =162;
        for(i=0; i<28; i++)
            {
                T[0] = (T[0]+ROL(C[i % 6], i));
                T[0]  = ROL(T[0] ,1);

                T[1] = (T[1] + ROL(C[i % 6], i+1));
                T[1]  = ROL(T[1], 3);

                T[2] = (T[2] + ROL(C[i % 6], i+2));
                T[2]  = ROL(T[2] ,6);

                T[3] = (T[3] + ROL(C[i % 6], i+3));
                T[3]  = ROL(T[3] ,11);

                T[4] = (T[4] + ROL(C[i % 6], i+4));
                T[4]  = ROL(T[4] ,13);

                T[5] = (T[5] + ROL(C[i % 6], i+5));
                T[5]  = ROL(T[5] ,17);

                RK[j] = T[0];
                RK[j+1] = T[1];
                RK[j+2] = T[2];
                RK[j+3] = T[3];
                RK[j+4] = T[4];
                RK[j+5] = T[5];
                j-=6;
            }
            break;
    case 32:   
        j=186;
        for(i=0; i<32; i++) 
            { q= 6*i;
                T[q % 8] = (T[q % 8]+ROL(C[i % 8], i));
                T[q % 8]  = ROL(T[q % 8] ,1);

                T[(q+1) % 8] = (T[(q+1) % 8] + ROL(C[i % 8], i+1));
                T[(q+1) % 8]  = ROL(T[(q+1) % 8], 3);

                T[(q+2) % 8] = (T[(q+2) % 8] + ROL(C[i % 8], i+2));
                T[(q+2) % 8]  = ROL(T[(q+2) % 8] ,6);

                T[(q+3) % 8] = (T[(q+3) % 8] + ROL(C[i % 8], i+3));
                T[(q+3) % 8]  = ROL(T[(q+3) % 8] ,11);

                T[(q+4) % 8] = (T[(q+4) % 8] + ROL(C[i % 8], i+4));
                T[(q+4) % 8]  = ROL(T[(q+4) % 8] ,13);

                T[(q+5) % 8] = (T[(q+5) % 8] + ROL(C[i % 8], i+5));
                T[(q+5) % 8]  = ROL(T[(q+5) % 8] ,17);

                RK[j] = T[q % 8];
                RK[j+1] = T[(q+1) % 8];
                RK[j+2] = T[(q+2) % 8];
                RK[j+3] = T[(q+3) % 8];
                RK[j+4] = T[(q+4) % 8];
                RK[j+5] = T[(q+5) % 8];
                j-=6;
            }
            break;
    default:
        break;
    }

        /*################출력####################*/
    /*키 출력*/
    // for (q=0; q<192; q++) {
    //     if(q%6 == 0) printf("\n");
    //     printf("%08x ", RK[q]);}
    // printf("\n\nend key\n\n");
        /*####################################*/
}