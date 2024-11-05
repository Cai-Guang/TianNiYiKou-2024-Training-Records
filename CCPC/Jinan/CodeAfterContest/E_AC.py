def main():
    for T in range(0, int(input())):
        A, B, C, X, Y, D = map(int, input().split(" "))

        #ABCCCCCCCCCCC
        ans = 0
        if D < X:
            ans = A
        elif D < X + Y:
            ans = A + B * (D - X)
        else:
            ans = A + B * Y + (D - X - Y) * C

        # AAAAAAAAAA

        cntA = (D + X - 1) // X
        ans = min(ans, cntA * A)

        # #ABABABABABABABCCC

        cntAB = D // (X + Y)
        restAB = D - cntAB * (X + Y)
        if cntAB >= 1:
            ans = min(ans, cntAB * (A + Y * B) + restAB * C)

        # AAAAAAAA use B, C to fill the rest

        cntA = D // X
        restA = D - cntA * X
        if restA <= Y * cntA:
            ans = min(ans, cntA * A + restA * B)

        # # #AAAAAAABCCCCCC

        if cntA > 0 and restA > Y:
            ans = min(ans, cntA * A + B * Y + (restA - Y) * C)


        #ABABABAb
        if X < restAB:
            ans = min(ans, cntAB * (A + B * Y) + (restAB - X) * B + A)
        else :
            ans = min(ans, cntAB * (A + B * Y) + A)

        rest = restAB - X
        if rest < 0 and cntAB * Y + rest > 0:
            ans = min(ans, cntAB * (A + B * Y) + A + B * rest)


        print(ans)



if __name__ == "__main__":
    main()