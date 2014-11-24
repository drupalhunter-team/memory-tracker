typedef struct {
  char first[32];
  char last[32];
  int  age;
} PersonType;

typedef struct {
  PersonType basicInfo;
  char       stuNumber[12];
  float      gpa;
} StudentType;

typedef struct{
  PersonType basicInfo;
  int age;
}SupermanType;

typedef struct{
  PersonType basicInfo;
  float age;
}SpiderType;
  

