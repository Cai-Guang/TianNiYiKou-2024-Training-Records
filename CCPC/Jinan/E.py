
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
        ans = min(ans, (D + X - 1) // X * A)
        cnt = D // X


        #ABABABABABABABCCC
        # AAAAAAAA use B, C to fill the rest
        if cnt * X + cnt * Y < D:
            ans = min(ans, A * cnt + B * cnt * Y + (D - cnt * X + cnt * Y) * C)
        else:
            ans = min(ans, A * cnt + B * (D - cnt * X))

        #AAAAAAABCCCCCC
        if cnt * X + Y >= D:
            ans = min(ans, A * cnt + )

        cnt = D // (X + Y)
        if cnt > 0:
            ans = min(ans, cnt * A + cnt * B * Y + (D - cnt * (X + Y)) * C)

        #ABABABAb

        if cnt * (X + Y) + X >= D:
            ans = min(ans, cnt * (A + B * Y) + A)
        else:
            ans = min(ans, cnt * (A + B * Y) + A + (D - (X + Y) * cnt - X) * B)
        print(ans)




if __name__ == "__main__":
    main()