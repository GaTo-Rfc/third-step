#include <stdio.h>
#include <math.h>

#define SIZE 20 // クラス人数（配列サイズ）

// プロトタイプ宣言
int calc_ttl(int *);               // 合計計算
float calc_avg(int *);             // 平均計算
void calc_dev_val(int *, float *); // 偏差計算
float calc_dist(float *);          // 分散計算
float calc_std_dev(float *);       // 標準偏差計算
void swap(int *, int *);           // スワップ（バブルソート用）
void bubble_sort(int *);           // バブルソート（降順）
void print(int *);                 // 結果出力

int main(int argc, char const *argv[])
{
  // テストの得点の配列
  int science[SIZE] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};  // 科学
  int english[SIZE] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84}; // 英語

  // 結果出力
  print(science);
  print(english);

  return 0;
}

// 合計計算
int calc_ttl(int *points)
{
  int ttl = 0;

  // for文を用いてttlにデータをすべて足し合わせ
  for (size_t i = 0; i < SIZE; i++)
  {
    ttl += points[i];
  }

  return ttl;
}

// 平均計算
float calc_avg(int *points)
{
  // calc_ttlで足し合わせた値をデータ数で割る
  return calc_ttl(points) / (float)SIZE;
}

// 偏差計算
void calc_dev_val(int *points, float *dev_vals)
{
  // 平均を取得
  float avg = calc_avg(points);

  // 各データの偏差値を求めてdev_valsの対応する場所へ格納
  for (size_t i = 0; i < SIZE; i++)
  {
    dev_vals[i] = points[i] - avg;
  }
}

// 分散計算
float calc_dist(float *dev_vals)
{
  float dist = 0;

  // for文を用いてdistに偏差値の2乗を全て足し合わせ
  for (size_t i = 0; i < SIZE; i++)
  {
    dist += pow(dev_vals[i], 2);
  }

  // distをデータ数で割る
  return dist / SIZE;
}

// 標準偏差計算
float calc_std_dev(float *dev_vals)
{
  // 分散の平方根
  return sqrt(calc_dist(dev_vals));
}

// スワップ（バブルソート用）
void swap(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

// バブルソート（降順）
void bubble_sort(int *points)
{
  // 計算量O(n^2)
  for (size_t i = SIZE - 1; i > 0; i--)
  {
    for (size_t j = 0; j < i; j++)
    {
      // 左の値が右の値よりも小さければswapを実行
      if (points[j] < points[j + 1])
      {
        swap(&points[j], &points[j + 1]);
      }
    }
  }
}

// 結果出力
void print(int *points)
{
  float dev_vals[20];

  // 全得点出力
  printf("得点：");
  for (size_t i = 0; i < SIZE; i++)
  {
    printf("%d, ", points[i]);
  }
  printf("\n");

  printf("合計：%d\n", calc_ttl(points));    // 合計出力
  printf("平均：%.2lf\n", calc_avg(points)); // 平均出力

  // 全偏差値出力
  printf("偏差値：");
  calc_dev_val(points, dev_vals);
  for (size_t i = 0; i < SIZE; i++)
  {
    printf("%.2lf, ", dev_vals[i] + 50.0);
  }
  printf("\n");

  printf("分散：%.2lf\n", calc_dist(dev_vals));        // 分散出力
  printf("標準偏差：%.2lf\n", calc_std_dev(dev_vals)); // 標準偏差出力

  // バブルソートを実行
  bubble_sort(points);

  // 並び替え後の全得点出力
  printf("並び替え後の得点：");
  for (size_t i = 0; i < SIZE; i++)
  {
    printf("%d, ", points[i]);
  }
  printf("\n\n");
}