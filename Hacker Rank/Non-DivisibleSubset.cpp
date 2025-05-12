//Giorgi Kldiashvili

#include <bits/stdc++.h>

using namespace std;

int a[1020], n, k, x, answer;

int main()
{
  scanf("%d%d", &n, &k);

  for(int i=0;i<n;++i)
  {
    scanf("%d", &x);
    a[x % k]++;
  }

  for(int i=1;i<k;++i)
  {
    if(i >= k - i)
      break;

    answer += max(a[i], a[k - i]);
  }

  if(a[0] != 0)
    answer++;

  if(a[k / 2] != 0 && k % 2 == 0)
    answer++;

  cout<<answer<<endl;
}