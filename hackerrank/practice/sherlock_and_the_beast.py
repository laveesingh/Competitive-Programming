for _ in range(input()):
    n  = input()
    count1 = n
    count2 = 0
    while count1 >= 0:
        if count1 % 3 == 0:
            break
        else:
            count2 += 5
            count1 -= 5

    if count1 < 0:
        print "-1"

    else:
        print count1*'5'+count2*'3'