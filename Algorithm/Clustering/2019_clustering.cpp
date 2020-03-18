#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>

class Iris
{
public:
   Iris() : calyx_length(0.0f), calyx_width(0.0f), petal_length(0.0f), petal_width(0.0f){};
   Iris(float cl,float cw, float pl, float pw) : calyx_length(cl),calyx_width(cw),petal_length(pl),petal_width(pw) {}
   
   float calyx_length, calyx_width;
   float petal_length, petal_width;
   
   // 거리 구하기
   float LengthSQ(const Iris& iris) 
   { 
      return powf(iris.calyx_length - calyx_length, 2) + powf(iris.calyx_width - calyx_width, 2) + powf(iris.petal_length - petal_length, 2) + powf(iris.petal_width - petal_width, 2); 
   }


   const Iris& operator+=(const Iris& rhs)
   {
      calyx_length += rhs.calyx_length;
      calyx_width += rhs.calyx_width;
      petal_length += rhs.petal_length;
      petal_width += rhs.petal_width;

      return *this;
   }

   const Iris& operator/(const float& value)
   {
      calyx_length /= value;
      calyx_width /= value;
      petal_length /= value;
      petal_width /= value;

      return *this;
   }

   bool operator==(const Iris& rhs)
   {
      return (rhs.calyx_length == calyx_length &&
         rhs.calyx_width == calyx_width &&
         rhs.petal_length == petal_length &&
         rhs.petal_width == petal_width);
   }

   bool operator!=(const Iris& rhs)
   {
      return !(*this == rhs);
   }
   
   void Print()
   {
      printf("%0.1f %0.1f %0.1f %0.1f\n", calyx_length, calyx_width, petal_length, petal_width);
   }
};

enum class ClusterType : unsigned int
{
   A, B, C
};

void MoveToCenter();
void ClassifyDatas();


std::vector<std::pair<Iris, ClusterType>> irises; // Cluster A : True , B false
Iris ClusterA, ClusterB, ClusterC;

//Step1
int NumElement[3] = { 0, };

int main()
{
   FILE* fp;
   srand(time(NULL));

   fp = fopen("iris.csv", "r");

   if (fp == nullptr)
   {
      printf("file doesn't exist");
      return 0;
   }

   while (!feof(fp))
   {
      Iris a;

      fscanf(fp, "%f,%f,%f,%f", &a.calyx_length,&a.calyx_width,&a.petal_length,&a.petal_width);

      // 랜덤하게 배정
      ClusterType type = static_cast<ClusterType>(rand()%3);
      NumElement[static_cast<int>(type)]++;
      irises.push_back(std::make_pair(a,type));
   }

   MoveToCenter();

   Iris prevCluster[3];
   while (!((prevCluster[0] == ClusterA) && (prevCluster[1] == ClusterB) && (prevCluster[2] == ClusterC)))
   {
      prevCluster[0] = ClusterA;
      prevCluster[1] = ClusterB;
      prevCluster[2] = ClusterC;
      ClassifyDatas();
      MoveToCenter();

   }

   ClusterA.Print();
   ClusterB.Print();
   ClusterC.Print();



   system("pause");
   return 0;
}

//Step1 모든 데이터들에 대해, 각 데이터와 각 클러스터의 중심점과의 거리들을 모두 구한 후, 해당 데이터와 가장 가까운 클러스터에 해당 데이터 배정
void ClassifyDatas()
{
   NumElement[0] = 0;
   NumElement[1] = 0;
   NumElement[2] = 0;

   auto GetMinCluster = [](const std::pair<ClusterType,float>& a, const std::pair<ClusterType,float>& b)->std::pair<ClusterType,float>
   {
      return a.second < b.second ? a : b;
   };

   for (auto& iris : irises)
   {
      std::pair<ClusterType, float> distance[3];
      
      distance[0] = std::make_pair(ClusterType::A,iris.first.LengthSQ(ClusterA));
      distance[1] = std::make_pair(ClusterType::B,iris.first.LengthSQ(ClusterB));
      distance[2] = std::make_pair(ClusterType::C,iris.first.LengthSQ(ClusterC));

      auto min = GetMinCluster(distance[0], GetMinCluster(distance[1], distance[2]));

      //배정
      NumElement[static_cast<int>(min.first)]++;
      iris.second = min.first;
   }
}

//Step2 각 클러스터들의 중심점을 해당 클러스터들에 배정된 데이터들의 평균 값 지점으로 이동
void MoveToCenter()
{
   Iris temp[3];
   for (auto& iris : irises)
   {
      temp[static_cast<int>(iris.second)] += iris.first;
   }

   ClusterA = temp[0] / NumElement[0];
   ClusterB = temp[1] / NumElement[1];
   ClusterC = temp[2] / NumElement[2];
}