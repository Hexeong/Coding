T = int(input())

while T > 0 :
    s = input()
    n = int(input())
    inp = input().split(',')
    inp[0] = inp[0][1:]
    inp[-1] = inp[-1][:-1]
    reversing = False

    if inp[0] == '' : inp = []

    re = ""
    for c in s:
        if c == 'R':
            reversing = not reversing
        elif c == 'D':
            if len(inp) != 0:
                if not reversing:
                    inp = inp[1:]
                else :
                    inp = inp[:-1]
            else:
                re = "error"
                break
    
    if len(re) != 0:
        print(re)
    else:
        if len(inp) == 0 :
            print("[]")
            continue
        if reversing :
            inp.reverse()
        print("[%s"%(inp[0]), end="")
        for i in inp[1:] :
            print(",%s"%(i), end="")
        print("]")
    
    T-=1