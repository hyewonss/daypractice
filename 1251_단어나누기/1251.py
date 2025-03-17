word = input()
n = len(word)
ans = "z" * n #비교해야 해서 가장 큰 문자열로 세팅

for i in range(1, n-1): #맨 앞은 적어도 한글자 있게 하고 i-> 2-4
    for j in range(i+1, n): #j-> 2-5, i가 4가 되면 j는 마지막 한글자가 됨
        s1 = word[:i][::-1]
        s2 = word[i:j][::-1]
        s3 = word[j:][::-1]
        result = s1+s2+s3
        ans = min(ans, result)

print(ans)