ans = 321
for i in range(322):
    s = str(i)
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            ans -= 1

print(ans)
