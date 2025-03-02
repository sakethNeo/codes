const int mod = 1e9 + 7;
void insert(vi &dp, int x){
    for(int i = 1000;i >= x; --i)
        dp[i] = (dp[i] + dp[i-x]) % mod;
}
void remove(vi &dp, int x){
    for(int i = x; i <= 1000; ++i)
        dp[i] = (dp[i] - dp[i-x] + mod) % mod;
}
int solve(){
    int n, s;
    cin >> n >> s;
    int a[n];
    inputarr(a, n);
    vector<int> dp(1001,0);
    dp[0] = 1;
    int r = 0;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        while(r < n && (dp[s] == 0)){
            insert(dp, a[r]);
            r++;
        }
        if(dp[s])
            ans = min(ans, r - i);
        remove(dp, a[i]);
    }
    if(ans == 1e9)
        ans = -1;
    cout << ans << endl;
 
    return 0;
}