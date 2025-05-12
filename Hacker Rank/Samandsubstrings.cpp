#include <bits/stdc++.h>

const int mod = 1000000007;

using namespace std;

// Complete the substrings function below.
long substrings(string s) {

    long n = s.length(); 
    long sod[n]; 

    sod[0] = s[0]-'0'; 
    long res = sod[0]; 
  
    for(long i=1; i<n; i++) 
    { 
        sod[i] = ((i+1) * (s[i]-'0') + 10 * sod[i-1])%mod; 
  
        
        res = (res+sod[i])%mod; 
    } 
  
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}


