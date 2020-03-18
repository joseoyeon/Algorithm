#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <chrono>

#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 10495
#define COLUMN_NUM 2
#define IP_Length 16
#define D 0.99
#define ITERATION 100

using namespace std;

map<string, float> nodes;
map<string, vector<pair<string, float>>> outbinds;
map<string, vector<pair<string, float>>> inbinds;

struct comp
{
   bool operator()(pair<string, float> a, pair<string, float> b) { return a.second < b.second; };
};

void read_data(char(*quiz)[IP_Length], const char* fileDir);
void ready_page_rank();
void page_rank();

int main()
{
   char fileDir[128] = "./data.csv";
   char data[DATA_SIZE*COLUMN_NUM][IP_Length];
   clock_t start, end;
   
   time(NULL);
   read_data(data, fileDir); // CSV data file read
   // printf("%s -> %s\n",data[1*COLUMN_NUM+0],data[1*COLUMN_NUM+1]);//언제나 행+열

 auto prevTime = std::chrono::high_resolution_clock::now();
   ready_page_rank();

   int count = 100;
   while (count--)
   {
      page_rank();
   }
     int qCount = 10;
      priority_queue<pair<string, float>, vector<pair<string, float>>, comp> pQueue2;

      for (auto it = nodes.begin(); it != nodes.end(); it++)
      {
         pQueue2.push(make_pair(it->first, it->second));
      }

      while (qCount--)
      {
         string A = pQueue2.top().first;

          cout << A << endl;

         pQueue2.pop();
      }

   auto curTime = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double, std::milli> ms = curTime - prevTime;
  
   cout << static_cast<float>(ms.count())/1000 <<"(s)" <<endl;
   system("pause");

   return 0;
}

void ready_page_rank()
{
   //step 1: 초기 가중치 설정
   for (auto it = nodes.begin(); it != nodes.end(); it++)
   {
      it->second = 1 / nodes.size();
   }

}

void page_rank()
{
   //step 2: node로 outbinds 가중치 분산
   for (auto it = nodes.begin(); it != nodes.end(); it++)
   {
      string A = it->first;

      auto out = outbinds.find(A); 
      if (out == outbinds.end())
         continue;

      //A->B
      for (int i = 0; i < out->second.size(); i++)
      {   
         string B = out->second[i].first;
         
         //out A  second (B, 가중치값) = Node(A) / Node(A)에서 나가는 간선의 수
         float weight = it->second / out->second.size();
         
         out->second[i].second = weight;
         
         //B를 찾아서 inbinds 값 갱신 B<-A
         auto in = inbinds.find(B);
         if (in == inbinds.end())
            continue;

         for (int j = 0; j < in->second.size(); j++)
         {
            if (in->second[j].first == A)
            {
               in->second[j].second = weight;
            }
         }


      }
   }

   //step 3: A<-B 인 간선들의 가중치를 더해서 A를 바꾼다.
   for (auto it = nodes.begin(); it != nodes.end(); it++)
   {
      string A = it->first;
      auto in = inbinds.find(A);
      if (in == inbinds.end())
         continue;

      float sum = 0;
      for (int i = 0; i < in->second.size(); i++)
      {
         sum += in->second[i].second;
      }

      it->second = (1 - D) / nodes.size() +D*sum;
   }


}

void read_data(char(*quiz)[IP_Length], const char* fileDir)
{
   FILE* fp;
   char buffer[DATA_SIZE*COLUMN_NUM];
   char* ptr;
   int i = 0, j = 0, p = 0;

   fp = fopen(fileDir, "r");

   if (fp == NULL)
   {
      puts("data file open failed!!");
      return;
   }

   for (i = 0; i < DATA_SIZE; i++)
   {
      fgets(buffer, DATA_SIZE * COLUMN_NUM, fp);
      ptr = strtok(buffer, ", \n");
      j = 0;

      while (ptr != NULL)
      {
         for (p = 0; p < IP_Length; p++)
            quiz[i*COLUMN_NUM + j][p] = ptr[p];
         ptr = strtok(NULL, ", \n");
         j++;
      }

      string A = quiz[i*COLUMN_NUM];
      string B = quiz[i*COLUMN_NUM + 1];

      nodes.insert(make_pair(A, 0));
      nodes.insert(make_pair(B, 0));

      auto out = outbinds.find(A);

      if (out == outbinds.end())
      {
         vector<pair<string, float>> a;
         a.push_back(make_pair(B, 0)); // 가중치
         outbinds.insert(make_pair(A, a)); // Key A  vector B
      }
      else
      {
         out->second.push_back(make_pair(B,0));
      }

      auto in = inbinds.find(B);

      if (in == inbinds.end())
      {
         vector<pair<string, float>> b;
         b.push_back(make_pair(A, 0)); 
         inbinds.insert(make_pair(B, b));
      }
      else
      {
         in->second.push_back(make_pair(A, 0));
      }
      // printf("%d, %s -> %s\n", i, quiz[i*COLUMN_NUM + 0], quiz[i*COLUMN_NUM + 1]);//언제나 행+열
   }
   //  printf("send\n");

   fclose(fp);
}