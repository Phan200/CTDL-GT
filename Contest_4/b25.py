a=[1,1]
for i in range(2,93):
    a.append(a[i-2]+a[i-1])
t=int (input())
def find_ith(t,i):
    if t==1:
        return 'A'
    if t==2:
        return 'B'
    if i<=a[t-2]:
        return find_ith(t-2,i)
    return find_ith(t-1,i-a[t-2])
while t>0 :
    #nhap n la xau thu n can dung
    #i la vi tri can tim ky tu
    n,i=map(int, input().split())
    print(find_ith(n,i-1))
    t=t-1

