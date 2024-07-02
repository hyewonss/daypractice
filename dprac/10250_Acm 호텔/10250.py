t = int(input())
for i in range(t):
    h,w,n = map(int, input().split())
    if (n%h == 0):
        room = int(n/h)
        floor = h
    else:
        room = int(n/h+1)
        floor = n%h
    
    if (room < 10):
        print(str(floor)+'0'+str(room))
    else:
        print(str(floor)+str(room))